#pragma once

#include "vector.hxx"
#include <cstddef> // size_t
#include <functional> // std::hash
#include <iostream>

namespace bmds {

template <typename K, typename V, typename Hash = std::hash<K> >
class HashTable {
private:
  struct Cell {
    K k;
    V v;
    Cell() {}
    Cell (const K &key, const V &value) {
      k = key;
      v = value;
    }
  };
public:
  HashTable(size_t initialBucketsNumber = 1000);
  void insert(const K &key, const V &value);
  size_t size() const;
  size_t bucketsNumber() const;
  V & operator[](const K &key);
  void resize(size_t newBucketsNumber);
private:
  Vector<Vector<Cell> > _buckets; 
  unsigned int _size;
  bool _resizeNeeded() const;  
  Vector<Cell> &_getBucket(const K &key);
  Cell &_getOrCreateCell(const K &key);
};


template <typename K, typename V, typename Hash>
HashTable<K, V, Hash>::HashTable(size_t initialBucketsNumber):
  _buckets(initialBucketsNumber),
  _size(0)
{
}

template <typename K, typename V, typename Hash>
void HashTable<K, V, Hash>::insert(const K &key, const V &value)
{
  auto &cell = _getOrCreateCell(key);
  cell.v = value;
}


template <typename K, typename V, typename Hash>
size_t HashTable<K, V, Hash>::size() const
{
  return _size;
}


template <typename K, typename V, typename Hash>
size_t HashTable<K, V, Hash>::bucketsNumber() const 
{
  return _buckets.size();
}
  
template <typename K, typename V, typename Hash>
V & HashTable<K, V, Hash>::operator[](const K &key)
{
  return _getOrCreateCell(key).v;
}

template <typename K, typename V, typename Hash>
void HashTable<K, V, Hash>::resize(size_t newBucketsNumber)
{
  Vector<Vector<Cell> > backupBuckets(_buckets); // this should be a std::move
  _buckets.clear();
  _size = 0;
  _buckets.resize(newBucketsNumber);
  for (auto &bucket: backupBuckets) {
    for (auto &cell: bucket) {
      (*this)[cell.k] = cell.v;
    }
  }
}

template <typename K, typename V, typename Hash>
bool HashTable<K, V, Hash>::_resizeNeeded() const
{
  // arbitrary threshold here, a real implementation
  // would require some benchmarks
  return ((size() * 4) / 3) > bucketsNumber();
}


template <typename K, typename V, typename Hash>
typename HashTable<K, V, Hash>::Cell & HashTable<K, V, Hash>::_getOrCreateCell(const K &key)
{
  auto &bucket = _getBucket(key);
  for (auto &cell: bucket) {
    if (cell.k == key) {
      return cell; 
    }
  }
  bucket.push_back(Cell(key, V()));
  _size++;
  if (_resizeNeeded()) {
    resize(bucketsNumber() * 2);
    return _getOrCreateCell(key);
  } else {
    return bucket.back();
  }
}


template <typename K, typename V, typename Hash>
Vector<typename HashTable<K, V, Hash>::Cell > &HashTable<K, V, Hash>::_getBucket(const K &key)
{
  auto hash = Hash{}(key);
  return _buckets[hash % bucketsNumber()];
}



/*
template <typename K, typename V, typename Hash>
HashTable<K, V, Hash>::
*/

} // namespace
