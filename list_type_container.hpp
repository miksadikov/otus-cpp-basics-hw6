#include <stdexcept>

template <typename T>
struct Node {
  Node();
  T m_Value;
  Node<T>* m_Prev;
  Node<T>* m_Next;
};

template <typename T>
Node<T>::Node() {
  m_Prev = nullptr;
  m_Next = nullptr;
}

template <typename T>
class ListTypeContainer {
 private:
  Node<T>* m_Head;
  Node<T>* m_Tail;
  size_t m_Size;

 public:
  ListTypeContainer();
  ~ListTypeContainer();

  // Add an element to the end of container
  void push_back(const T& val);

  // Remove an element from the container
  void remove(std::size_t position);

  // Remove last element from the container
  void pop_back();

  // Get the size of the container
  size_t size() const;

  // Insert the element into the container
  void insert(std::size_t position, const T& val);

  // Access by index
  T operator[](std::size_t position);

  // Displaying all elements of the container
  void print_all();
};

template <typename T>
ListTypeContainer<T>::ListTypeContainer()
    : m_Head(nullptr), m_Tail(nullptr), m_Size(0) {}

template <typename T>
ListTypeContainer<T>::~ListTypeContainer() {
  while (nullptr != m_Head) {
    pop_back();
  }
}

template <typename T>
void ListTypeContainer<T>::push_back(const T& val) {
  Node<T>* node = new Node<T>;
  node->m_Value = val;
  if (m_Size > 0) {
    m_Tail->m_Next = node;
    node->m_Prev = m_Tail;
    m_Tail = node;
  } else {
    m_Head = m_Tail = node;
  }
  m_Size++;
}

template <typename T>
void ListTypeContainer<T>::pop_back() {
  if (m_Size > 0) {
    m_Size--;
    Node<T>* delNode = m_Tail;
    m_Tail = m_Tail->m_Prev;
    if (nullptr == m_Tail) {
      m_Head = nullptr;
      if (delNode != nullptr) {
        delete delNode;
      }
      return;
    }
    m_Tail->m_Next = nullptr;
    if (delNode != nullptr) {
      delete delNode;
    }
  } else {
    std::cout << "pop_back() error: container is empty" << std::endl;
  }
}

template <typename T>
void ListTypeContainer<T>::remove(std::size_t position) {
  if (position < 0) {
    std::cout << "remove() error: invalid position" << std::endl;
    return;
  }
  if (nullptr == m_Head) {
    std::cout << "remove() error: empty container" << std::endl;
    return;
  }
  if (0 == position) {
    // remove head
    m_Head = m_Head->m_Next;
    if (nullptr != m_Head) {
      m_Head->m_Prev = nullptr;
    } else {
      // when container empty after delete
      m_Tail = nullptr;
    }
  } else {
    Node<T>* temp = m_Head;
    int n = 0;
    // find deleted node position
    while (nullptr != temp && n < position) {
      temp = temp->m_Next;
      n++;
    }
    if (nullptr == temp) {
      // position are greater than length of linked list
      std::cout << "remove() error: deleted node position are not found"
                << std::endl;
    } else {
      temp->m_Prev->m_Next = temp->m_Next;
      if (nullptr != temp->m_Next) {
        // when deleted intermediate nodes
        temp->m_Next->m_Prev = temp->m_Prev;
      } else {
        // when delete last node
        m_Tail = temp->m_Prev;
      }
      delete temp;
    }
  }
  m_Size--;
}

template <typename T>
void ListTypeContainer<T>::insert(std::size_t position, const T& val) {
  Node<T>* node = new Node<T>;
  node->m_Value = val;
  node->m_Next = nullptr;
  node->m_Prev = nullptr;
  if (position < 0) {
    std::cout << "insert() error: invalid position" << std::endl;
  } else if (0 == position) {
    node->m_Next = m_Head;
    m_Head->m_Prev = node;
    m_Head = node;
    m_Size++;
  } else {
    Node<T>* temp = m_Head;
    for (int i = 0; i < position - 1; i++) {
      if (nullptr != temp) {
        temp = temp->m_Next;
      }
    }
    if (nullptr != temp) {
      node->m_Next = temp->m_Next;
      node->m_Prev = temp;
      temp->m_Next = node;
      if (nullptr != node->m_Next) {
        node->m_Next->m_Prev = node;
      }
      m_Size++;
    } else {
      std::cout << "insert() error: the previous node is null" << std::endl;
    }
  }
}

template <typename T>
void ListTypeContainer<T>::print_all() {
  if (nullptr == m_Head) {
    std::cout << "print() warning: empty container" << std::endl;
  } else {
    Node<T>* temp = m_Head;
    std::cout << "container elements are:" << std::endl;
    while (nullptr != temp) {
      std::cout << "  " << temp->m_Value;
      temp = temp->m_Next;
    }
    std::cout << std::endl;
  }
}

template <typename T>
T ListTypeContainer<T>::operator[](std::size_t position) {
  if (position < 1) {
    throw std::runtime_error("operator[] error: invalid position");
  }
  if (nullptr == m_Head) {
    throw std::runtime_error("operator[] error: empty container");
  }
  Node<T>* temp = m_Head;
  int n = 0;
  while (nullptr != temp && n < position) {
    temp = temp->m_Next;
    n++;
  }
  if (nullptr == temp) {
    throw std::runtime_error(
        "operator[] error: element position are not found");
  } else {
    return (temp->m_Next->m_Value);
  }
}

template <typename T>
size_t ListTypeContainer<T>::size() const {
  return m_Size;
}
