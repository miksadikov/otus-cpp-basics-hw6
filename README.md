# OTUS C++ Basic курс

## Задание "Реализация контейнеров"

В задании требуется реализовать два контейнера динамического размера – последовательный и
спискового типа – и пользовательский код с демонстрацией возможностей этих контейнеров.

1. Последовательный контейнер
Отличительная черта такого контейнера – расположение элементов друг за другом подряд
(как и у обычного массива в стиле Си).

2. Контейнер спискового типа – не предоставляет гарантий расположения элементов друг за
другом в памяти. Связь между элементами осуществляется через указатели (указатель на
предыдущий элемент и/или указатель на следующий элемент).

## Инструкция по сборке

Требуется компилятор с поддержкой C++17

Для сборки проекта необходимo выполнить следующие команды
```
mkdir build && cd build
cmake ..
cmake --build .
```
