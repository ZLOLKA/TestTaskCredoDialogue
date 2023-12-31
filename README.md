# Моделирование космического сражения

Необходимо спроектировать и реализовать консольное приложение,
 позволяющее моделировать космическое сражение.

В сражении участвуют корабли двух сторон:
 Повстанческий Альянс и Галактическая Империя.
 Характеристики техники представлены в таблицах ниже:

## Техника Альянса (Alliance)

| Тип | Прочность | Урон за выстрел | Вероятность попадания | Вероятность уклонения |
| - | - | - | - | - |
| Шаттл /Shuttle | 10 | 4 | 0.50 | 0.10 |
| Транспорт /Transport | 30 | 6 | 0.55 | 0.00 |
| Разведчик /Scout | 60 | 9 | 0.60 | 0.30 |
| Истребитель /Fighter | 40 | 15 | 0.75 | 0.30 |
| Бомбардировщик /Bomber | 20 | 20 | 0.95 | 0.20 |

## Техника Империи (Empire)

| Тип | Прочность | Урон за выстрел | Вероятность попадания | Вероятность уклонения |
| - | -| - | - | - |
| Шаттл /Shuttle | 8 | 5 | 0.70 | 0.10 |
| Транспорт /Transport | 25 | 9 | 0.80 | 0.05 |
| Разведчик /Scout | 50 | 14 | 0.80 | 0.20 |
| Истребитель /Fighter | 30 | 25 | 0.90 | 0.20 |
| Бомбардировщик /Bomber | 15 | 30 | 1.00 | 0.15 |

Каждая армия поочередно производит выстрел по вражеской технике. Выбор звездолета,
 который осуществляет выстрел и по которому осуществляется выстрел, производится
 случайным образом. Результат выстрела (попадание или промах) рассчитывается на
 основе вероятности попадания стреляющей техники и вероятности уклонения цели.
 Боевая единица считается уничтоженной, если уровень ее прочности снижается до 0.
 Уничтоженная техника не участвует в сражении. Побеждает та сторона, у которой
 остались боевые единицы.

Характеристики техники, а также количество каждой единицы техники, должны храниться
 в файле settings.json, который загружается программой перед началом симуляции.
 Количество звездолетов задать самостоятельно.

Результат симуляции поместить в выходной файл output.txt. В него необходимо
 записывать результат каждого выстрела. В конце файла поместить информацию о том,
 какая сторона победила и сколько какого вида техники у нее осталось.

Пример файла:

```
Аlliance: Shuttle-A1 shoots at Scout-E2. Result: 4 damage, 46 strength left.
Еmpire: Scout-E2 shoots at Fighter-A1. Result: miss, 40 strength left.
Аlliance: Scout-A1 shoots at Bomber-E2. Result: 9 damage, 6 strength left.
Еmpire: Bomber-E1 shoots at Transport-A1. Result: 30 damage, destroyed.

------------------------------------------------------------------------------------------

Alliance won.
Remaining spaceships:
Shuttle: 0
Transport: 0
Scout: 1
Fighter: 1
Bomber: 0
```

Для каждого хода через дефис от названия звездолета отображаем префикс армии
 (A – Alliance, E- Empier) и уникальный идентификатор техники (в пределах армии).

Для каждого типа техники создать свой класс. Вся техника из задания должна быть
 включена в единую иерархию классов. Для создания объектов классов необходимо
 использовать шаблон проектирования Абстрактная фабрика. Реализация на С++17.

Исходные коды необходимо прислать в виде архива zip. Проверка задания будет
 выполняться в MSVS2022, Windows 10.