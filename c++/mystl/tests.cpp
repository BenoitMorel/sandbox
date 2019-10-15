#include "datastructures/array.hxx"
#include "datastructures/vector.hxx"
#include "algorithms/sort.hxx"

#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>

void test_array()
{
  const unsigned int size = 49;
  bmds::Array<unsigned int, size> array1;
  assert(array1.size() == size);
  for (unsigned i = 0; i < array1.size(); ++i) {
    array1[i] = i;
  }
  bmds::Array<unsigned int, size> array2(array1);
  for (unsigned int i = 0; i < array1.size(); ++i) {
    assert(array1[i] == i);
    assert(array2[i] == array1[i]);
  }
  unsigned int sum = std::accumulate(array1.begin(), array1.end(), 0);
  assert (sum == size * (size - 1) / 2);
  for (auto v: array1) {
    sum -= v;
  }
  assert(sum == 0);
}

void test_vector()
{
  unsigned int size1 = 131;
  unsigned int defaultValue1 = 42;
  bmds::Vector<unsigned int> v1(size1, defaultValue1);
  unsigned int sum = 0;
  for (auto value: v1) {
    sum += value;
  }
  assert(sum == size1 * defaultValue1);
  v1.clear();
  size1 *= 2;
  for (size_t i = 0; i < size1; ++i) {
    v1.push_back(i * 2);
  }
  for (size_t i = 0; i < size1; ++i) {
    assert(v1[i] == i * 2);
  }
  for (size_t i = 0; i < size1 - 1; ++i) {
    v1.pop_back();
  }
  assert(v1.size() == 1);
}

void test_bubble_sort()
{
  srand(42);
  size_t size = 1000;
  bmds::Vector<unsigned int> v(size);
  for (auto &value: v) {
    value = rand();
  }
  bmalgo::bubbleSort(v.begin(), v.end());    
  assert(std::is_sorted(v.begin(), v.end()));
}

void test_quick_sort()
{
  srand(42);
  size_t size = 100000;
  bmds::Vector<unsigned int> v(size);
  for (auto &value: v) {
    value = rand();
  }
  bmalgo::quickSort(v.begin(), v.end());    
  assert(std::is_sorted(v.begin(), v.end()));
}

int main(int argc, char**argv)
{
  test_array();
  test_vector();
  test_bubble_sort();
  test_quick_sort();
  std::cout << "All tests passed successfully" << std::endl;
  return 0;
}
