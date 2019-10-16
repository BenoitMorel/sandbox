#pragma once

#include <cstddef>

namespace bmds {
  
template<typename T>
class Vector {
public:
  Vector(size_t size = 0);
  Vector(const Vector<T> &vector);
  Vector(size_t size, const T &value);
  virtual ~Vector();
    
  Vector& operator=(const Vector& vector);
  const T operator[](size_t i) const;
  T& operator[](size_t i);
  size_t size() const;
  
  typedef T* iterator;
  typedef const T* const_iterator;
  const_iterator begin() const;
  const_iterator end() const;
  iterator begin();
  iterator end();

  void resize(size_t size);

  void push_back(const T&t);
  void pop_back();
  void clear();
  T &back();
private:
  T *_buffer;
  size_t _size;
  size_t _capacity;
  void _reallocate(size_t capacity);
};

template<typename T>
Vector<T>::Vector(size_t size):
  _buffer(nullptr),
  _size(0),
  _capacity(0)
{
  resize(size);
}

template<typename T>
Vector<T>::Vector(const Vector<T> &vector):
  _buffer(nullptr),
  _size(0),
  _capacity(0)
{
  resize(vector.size());
  for (size_t i = 0; i < vector.size(); ++i) {
    (*this)[i] = vector[i];
  }
}

template<typename T>
Vector<T>::Vector(size_t size, const T &value):
  _buffer(nullptr),
  _size(0),
  _capacity(0)
{
  resize(size);
  for (auto &v: *this) {
    v = value;
  }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector)
{
  resize(vector.size());
  for (size_t i = 0; i < vector.size(); ++i) {
    (*this)[i] = vector[i];
  }
  return *this;
}

template<typename T>
Vector<T>::~Vector()
{
  delete[] _buffer;
}

template<typename T>
size_t Vector<T>::size() const
{
  return _size;
} 

template<typename T>
const T Vector<T>::operator[](size_t i) const
{
  return _buffer[i];
}

template<typename T>
T& Vector<T>::operator[](size_t i)
{
  return _buffer[i];
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const
{
  return _buffer;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
  return _buffer + size();
}
template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
  return _buffer;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
  return _buffer + size();
}

template<typename T>
void Vector<T>::push_back(const T&t)
{
  if (size() >= _capacity) {
    _reallocate((size() + 1) * 2);
  }
  (*this)[size()] = t;
  _size++;
}

template<typename T>
void Vector<T>::pop_back()
{
  _size--;
  if (size() * 2 < _capacity) {
    _reallocate(_capacity);
  }
}

template<typename T>
void Vector<T>::clear()
{
  delete[] _buffer;
  _buffer = nullptr;
  _size = 0;
  _capacity = 0;
}

template<typename T>
T &Vector<T>::back()
{
  return _buffer[size() - 1];
}

template<typename T>
void Vector<T>::resize(size_t newSize)
{
  if (size() != newSize) {
    _reallocate(newSize);
    _size = newSize;
  }
}

template<typename T>
void Vector<T>::_reallocate(size_t newCapacity)
{
  if (0 == newCapacity) {
    delete[] _buffer;
    _buffer = nullptr;
    return;
  }
  auto savedBuffer = _buffer;
  _buffer = new T[newCapacity];
  auto minSize = newCapacity < size() ? newCapacity : size();
  for (size_t i = 0; i < minSize; ++i) {
    _buffer[i] = savedBuffer[i];
  }
  _capacity = newCapacity;
  delete[] savedBuffer;
}


} // namespace bmds
