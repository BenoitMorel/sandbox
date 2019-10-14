#pragma once


namespace bmds {
 
/**
 *  Partial reimplementation of std::array
 */ 
template<typename T, size_t N>
class Array {
public:
  Array();
  Array(const Array &a);
  virtual ~Array();

  size_t size() const;
  const T operator[](size_t i) const;
  T& operator[](size_t i);

  typedef T* iterator;
  typedef const T* const_iterator;
  const_iterator begin() const;
  const_iterator end() const;
  iterator begin();
  iterator end();
private:
  T _buffer[N];
};


template<typename T, size_t N>
Array<T, N>::Array()
{
}

template<typename T, size_t N>
Array<T, N>::Array(const Array<T, N> &a)
{
  for (size_t i = 0; i < N; ++i) {
    _buffer[i] = a._buffer[i];
  }
}

template<typename T, size_t N>
Array<T, N>::~Array()
{
}


template<typename T, size_t N>
const T Array<T, N>::operator[](size_t i) const
{
  return _buffer[i];
}

template<typename T, size_t N>
T& Array<T, N>::operator[](size_t i)
{
  return _buffer[i];
}

template<typename T, size_t N>
size_t Array<T, N>::size() const
{
  return N;
}
  
template<typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::begin() const
{
  return _buffer;
}

template<typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::end() const
{
  return _buffer + N;
}
template<typename T, size_t N>
typename Array<T, N>::iterator Array<T, N>::begin()
{
  return _buffer;
}

template<typename T, size_t N>
typename Array<T, N>::iterator Array<T, N>::end()
{
  return _buffer + N;
}

} // namespace bmds
