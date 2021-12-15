template <class T>
class ConsecTypeContainer {
 public:
  typedef T* iterator;

  ConsecTypeContainer();
  ~ConsecTypeContainer();

  ConsecTypeContainer<T>& operator=(const ConsecTypeContainer<T>&);

  // Get size and capacity of the container
  size_t capacity() const;
  size_t size() const;

  // Check for empty
  bool empty() const;

  // Iterators
  iterator begin();
  iterator end();

  // Add an element to the end of container
  void push_back(const T& val);

  // Insert an element into the container
  void insert(std::size_t position, const T& val);

  // Remove an element from the container
  void remove(std::size_t position);

  // Reserve and resize mem
  void reserve(size_t capacity);
  void resize(size_t size);

  // Access by index
  T& operator[](size_t index) const;

  // Displaying all elements of the container
  void print_all();

 private:
  size_t m_Size;
  size_t m_Capacity;
  T* m_Buffer;
};

template <class T>
ConsecTypeContainer<T>::ConsecTypeContainer() {
  m_Capacity = 0;
  m_Size = 0;
  m_Buffer = nullptr;
}

template <class T>
bool ConsecTypeContainer<T>::empty() const {
  return m_Size == 0;
}

template <class T>
typename ConsecTypeContainer<T>::iterator ConsecTypeContainer<T>::begin() {
  return m_Buffer;
}

template <class T>
typename ConsecTypeContainer<T>::iterator ConsecTypeContainer<T>::end() {
  return m_Buffer + m_Size;
}

template <class T>
void ConsecTypeContainer<T>::push_back(const T& val) {
  if (m_Size >= m_Capacity) {
    if (m_Capacity == 0)
      reserve(m_Capacity + 1);
    else
      reserve(m_Capacity * 2);
  }
  m_Buffer[m_Size++] = val;
}

template <class T>
void ConsecTypeContainer<T>::insert(std::size_t position, const T& val) {
  resize(m_Size + 1);

  typename ConsecTypeContainer<T>::iterator result = end();

  if (position < size()) {
    result = std::copy_backward(std::next(begin(), position), std::prev(end()),
                                end());
  } else {
    std::cout << "insert() error: invalid position" << std::endl;
  }

  auto it = std::prev(result);
  *it = val;
}

template <class T>
void ConsecTypeContainer<T>::remove(std::size_t position) {
  typename ConsecTypeContainer<T>::iterator start = &m_Buffer[position];

  for (auto it = start; it != (end() - 1); ++it) {
    *it = *(it + 1);
  }
  resize(m_Size - 1);
}

template <class T>
void ConsecTypeContainer<T>::reserve(size_t capacity) {
  T* newBuffer = new T[capacity];

  std::copy(m_Buffer, m_Buffer + m_Size, newBuffer);

  m_Capacity = capacity;
  delete[] m_Buffer;
  m_Buffer = newBuffer;
}

template <class T>
size_t ConsecTypeContainer<T>::size() const {
  return m_Size;
}

template <class T>
void ConsecTypeContainer<T>::resize(size_t size) {
  reserve(size);
  m_Size = size;
}

template <class T>
T& ConsecTypeContainer<T>::operator[](size_t index) const {
  return m_Buffer[index];
}

template <class T>
size_t ConsecTypeContainer<T>::capacity() const {
  return m_Capacity;
}

template <class T>
void ConsecTypeContainer<T>::print_all() {
  if (empty()) {
    std::cout << "print() warning: empty container" << std::endl;
  }
  std::cout << "container elements are:" << std::endl;
  for (typename ConsecTypeContainer<T>::iterator it = begin(); it != end();
       ++it) {
    std::cout << "  " << *it;
  }
  std::cout << std::endl;
}

template <class T>
ConsecTypeContainer<T>::~ConsecTypeContainer() {
  delete[] m_Buffer;
}