#include <iostream>

#include "consec_type_container.hpp"
#include "list_type_container.hpp"

int main() {
  std::cout << std::endl
            << "========== Consecuence-type container ========== " << std::endl;

  // создание объекта контейнера для хранения объектов типа int
  ConsecTypeContainer<int> ctcontainer;

  // добавление в контейнер десяти элементов (0, 1 ... 9)
  std::cout << "add 10 elements (0 - 9):" << std::endl;
  for (int i = 0; i < 10; i++) {
    ctcontainer.push_back(i);
  }

  // вывод содержимого контейнера на экран
  ctcontainer.print_all();

  // вывод размера контейнера на экран
  std::cout << "container size = " << ctcontainer.size() << std::endl;

  // удаление третьего (по счёту), пятого и седьмого элементов
  std::cout << "remove 3, 5, 7 elements:" << std::endl;
  ctcontainer.remove(3);
  ctcontainer.remove(4);
  ctcontainer.remove(5);

  // вывод содержимого контейнера на экран
  ctcontainer.print_all();

  // добавление элемента 10 в начало контейнера
  std::cout << "add 10 to the beginning:" << std::endl;
  ctcontainer.insert(0, 10);

  // вывод содержимого контейнера на экран
  ctcontainer.print_all();

  // добавление элемента 20 в середину контейнера
  std::cout << "add 20 in the middle:" << std::endl;
  ctcontainer.insert(4, 20);

  // вывод содержимого контейнера на экран
  ctcontainer.print_all();

  // добавление элемента 30 в конец контейнера
  std::cout << "add 30 to the end:" << std::endl;
  ctcontainer.push_back(30);

  // вывод содержимого контейнера на экран
  ctcontainer.print_all();

  std::cout << std::endl
            << "============== List-type container ============= " << std::endl;

  // создание объекта контейнера для хранения объектов типа int
  ListTypeContainer<int> ltcontainer;

  // добавление в контейнер десяти элементов (0, 1 ... 9)
  std::cout << "add 10 elements (0 - 9):" << std::endl;
  for (int i = 0; i < 10; i++) {
    ltcontainer.push_back(i);
  }

  // вывод содержимого контейнера на экран
  ltcontainer.print_all();

  // вывод размера контейнера на экран
  std::cout << "container size = " << ltcontainer.size() << std::endl;

  // удаление третьего (по счёту), пятого и седьмого элементов
  std::cout << "remove 3, 5, 7 elements:" << std::endl;
  ltcontainer.remove(3);
  ltcontainer.remove(4);
  ltcontainer.remove(5);

  // вывод содержимого контейнера на экран
  ltcontainer.print_all();

  // добавление элемента 10 в начало контейнера
  std::cout << "add 10 to the beginning:" << std::endl;
  ltcontainer.insert(0, 10);

  // вывод содержимого контейнера на экран
  ltcontainer.print_all();

  // добавление элемента 20 в середину контейнера
  std::cout << "add 20 in the middle:" << std::endl;
  ltcontainer.insert(4, 20);

  // вывод содержимого контейнера на экран
  ltcontainer.print_all();

  // добавление элемента 30 в конец контейнера
  std::cout << "add 30 to the end:" << std::endl;
  ltcontainer.push_back(30);

  // вывод содержимого контейнера на экран
  ltcontainer.print_all();

  return (0);
}