#include "Preset.hpp"

#include "impl/Alliance/AllianceSpaceShipFactory.hpp"
#include "impl/Empire/EmpireSpaceShipFactory.hpp"
#include "Tools.hpp"

#include "json/parse.h"

#include <fstream>
#include <optional>

namespace StarWarsTestTask {

bool isCorrectPercent(float percent) noexcept {
  return not ((cmpFloat(percent, 0) < 0) || (cmpFloat(percent, 1) > 0));
}

template <class JsonCharacteristicT>
float getFloatFromJson(
  const JsonCharacteristicT& characteristic
  , const std::string& characteristicName
) noexcept(not USE_ASSERT_AS_THROW) {
  const auto* characteristicPtr = std::get_if<double>(&characteristic);
  ASSERT(characteristicPtr != nullptr, characteristicName + " must have numeric type");
  ASSERT(cmpDbl(*characteristicPtr, 0) >= 0, characteristicName + " must be positive");
  return static_cast<float>(*characteristicPtr);
}

template <class JsonCharacteristicT>
std::size_t getSizeTFromJson(
  const JsonCharacteristicT& characteristic
  , const std::string& characteristicName
) noexcept(not USE_ASSERT_AS_THROW) {
  const auto* characteristicPtr = std::get_if<double>(&characteristic);
  ASSERT(characteristicPtr != nullptr, characteristicName + " must have numeric type");
  ASSERT(
    cmpDbl(*characteristicPtr, std::round(*characteristicPtr)) == 0
    , characteristicName + " must be integer"
  );
  ASSERT(std::round(*characteristicPtr) >= 0, characteristicName + " must be positive");
  return *characteristicPtr;
}

template <class JsonValueT, class JsonCharacteristicT>
SpaceShipCharacteristics getSpaceShipCharacteristics(
  const JsonCharacteristicT& jsonCharacteristics
  , const std::string& spaceShipType
) noexcept(not USE_ASSERT_AS_THROW) {
  const auto* spaceShipCharacteristics =
    std::get_if<typename JsonValueT::object_type>(&jsonCharacteristics);
  ASSERT(spaceShipCharacteristics != nullptr, spaceShipType + " field must be like map");
  ASSERT(
    spaceShipCharacteristics->size() == 5, spaceShipType + " field size must be equal 5"
  );

  std::optional<std::size_t> countInArmy;
  std::optional<std::size_t> damage;
  std::optional<float> accuracy;
  std::optional<std::size_t> startHP;
  std::optional<float> dodging;

  for (const auto& [characteristicName, spaceShipCharacteristic]
  : *spaceShipCharacteristics) {
    if (characteristicName == "countInArmy") {
      ASSERT(not countInArmy.has_value(), "Key countInArmy must be unique");
      countInArmy.emplace(getSizeTFromJson(spaceShipCharacteristic, characteristicName));
    } else if (characteristicName == "damage") {
      ASSERT(not damage.has_value(), "Key damage must be unique");
      damage.emplace(getSizeTFromJson(spaceShipCharacteristic, characteristicName));
    } else if (characteristicName == "accuracy") {
      ASSERT(not accuracy.has_value(), "Key accuracy must be unique");
      accuracy.emplace(getFloatFromJson(spaceShipCharacteristic, characteristicName));
    } else if (characteristicName == "startHP") {
      ASSERT(not startHP.has_value(), "Key startHP must be unique");
      startHP.emplace(getSizeTFromJson(spaceShipCharacteristic, characteristicName));
    } else if (characteristicName == "dodging") {
      ASSERT(not dodging.has_value(), "Key dodging must be unique");
      dodging.emplace(getFloatFromJson(spaceShipCharacteristic, characteristicName));
    } else {
      ASSERT(false, characteristicName + " this is incorrect key for characteristicName");
    }
  }

  ASSERT(countInArmy.has_value(), "countInArmy must be setted");
  ASSERT(damage.has_value(), "damage must be setted");
  ASSERT(accuracy.has_value(), "accuracy must be setted");
  ASSERT(isCorrectPercent(accuracy.value()), "(0 <= accuracy <= 1) must be equal true");
  ASSERT(startHP.has_value(), "startHP must be setted");
  ASSERT(dodging.has_value(), "dodgtng must be setted");
  ASSERT(isCorrectPercent(dodging.value()), "(0 <= dodging <= 1) must be equal true");
  return {
    countInArmy.value()
    , damage.value()
    , accuracy.value()
    , startHP.value()
    , dodging.value()
  };
}

template <class JsonValueT, class RootPtrT>
Preset::ArmyCharacteristicsT getArmyCharacteristics(
  const RootPtrT rootPtr
  , const std::string& armyName
) noexcept(not USE_ASSERT_AS_THROW) {
  using namespace std::string_literals;

  const auto jsonArmyCharacteristicsIt = rootPtr->find(armyName);
  ASSERT(jsonArmyCharacteristicsIt != rootPtr->end(), "Root must contain "s + armyName);
  const auto* jsonArmyCharacteristics = 
    std::get_if<typename JsonValueT::object_type>(&jsonArmyCharacteristicsIt->second);
  ASSERT(jsonArmyCharacteristics != nullptr, armyName + " field must be like map");
  ASSERT(jsonArmyCharacteristics->size() == 5, armyName + " field size must be equal 5");

  Preset::ArmyCharacteristicsT armyCharacteristics{};
  for (const auto& [spaceShipType, jsonSpaceShipCharacteristics]: *jsonArmyCharacteristics) {
    const bool isCorrectSpaceShipType = std::find(
        Preset::allSpaceShipTypes.begin(), Preset::allSpaceShipTypes.end()
        , spaceShipType
      ) != Preset::allSpaceShipTypes.end();
    ASSERT(isCorrectSpaceShipType, "SpaceShipType must be from Preset::allSpaceShipTypes");

    armyCharacteristics.emplace(std::make_pair(
      spaceShipType, getSpaceShipCharacteristics<JsonValueT>(
        jsonSpaceShipCharacteristics, spaceShipType
      )
    ));
  }
  return armyCharacteristics;
}

Preset::Preset(
  const std::filesystem::path& pathToSettingsFile, WritterI* const writter
) noexcept(not USE_ASSERT_AS_THROW) : writter(writter) {
  using JsonValueT = json::value<char>;

  std::fstream fs{pathToSettingsFile, std::ios_base::in};
  ASSERT(fs.is_open(), "File not found");

  JsonValueT jsonObj;
  fs >> jsonObj >>std::ws;
  const auto* root = std::get_if<JsonValueT::object_type>(&jsonObj);
  ASSERT(root != nullptr, "Root in json must be like map");
  ASSERT(root->size() == 2, "Root size must be equal 2");

  allianceCharacteristics = getArmyCharacteristics<JsonValueT>(root, "Alliance");
  empireCharacteristics = getArmyCharacteristics<JsonValueT>(root, "Empire");
}

Army Preset::getAllianceArmy() const noexcept {
  auto factory = std::make_unique<AllianceSpaceShipFactory>(writter);
  return getArmy(&Preset::allianceCharacteristics, std::move(factory));
}

Army Preset::getEmpireArmy() const noexcept {
  auto factory = std::make_unique<EmpireSpaceShipFactory>(writter);
  return getArmy(&Preset::empireCharacteristics, std::move(factory));
}

Army Preset::getArmy(
  decltype(&Preset::empireCharacteristics) characteristicsField
  , std::unique_ptr<AbstractSpaceShipFactory>&& factory
) const noexcept(
  noexcept(std::declval<AbstractSpaceShipFactory>().createSpaceShipByTypename(
    std::declval<std::string>(), std::declval<SpaceShipCharacteristics>()
  ))
) {
  const auto& characteristics = this->*characteristicsField;
  Army army{factory->getArmyName()};
  for(const auto& [spaceShipTypename, characteristic] : characteristics) {
    const auto countInArmy = characteristic.getCountInArmy();
    for (std::size_t i = 0; i < countInArmy; ++i) {
      army.emplace(factory->createSpaceShipByTypename(
        spaceShipTypename, characteristic
      ));
    }
  }
  return army;
}

}  // namespace StarWarsTestTask
