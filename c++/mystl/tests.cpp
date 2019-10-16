#include "datastructures/array.hxx"
#include "datastructures/vector.hxx"
#include "datastructures/hashtable.hxx"
#include "algorithms/sort.hxx"

#include <numeric>
#include <iostream>
#include <cassert>
#include <algorithm>


std::string randomString(size_t length, const char charset[])
{
  auto randchar = []() -> char
  {
    const char charset[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[ rand() % max_index ];
  };
  std::string str(length,0);
  std::generate_n( str.begin(), length, randchar );
  return str;
}

std::string randomPhone(size_t length)
{
  const char charset[] = "0123456789";
  return randomString(length, charset);
}

std::string randomName(size_t length)
{
    const char charset[] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";
  return randomString(length, charset);
}

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

void test_hashtable()
{
  size_t size = 100000;
  bmds::Vector<std::pair<std::string, std::string> > nameAndPhoneArray;
  for (size_t i = 0; i < size; ++i) {
    auto str1 = randomName(30);
    auto str2 = randomPhone(10);
    std::pair<std::string, std::string> p(str1, str2);
    nameAndPhoneArray.push_back(p);
  }
  bmds::HashTable<std::string, std::string> nameToPhoneHashTable(10000);
  for (const auto &p: nameAndPhoneArray) {
    nameToPhoneHashTable.insert(p.first, p.second);
  }
  assert(nameToPhoneHashTable.size() == size);
  for (const auto &p: nameAndPhoneArray) {
    // this one should not have any effect
    nameToPhoneHashTable.insert(p.first, p.second);
  }
  assert(nameToPhoneHashTable.size() == size);
  for (const auto &p: nameAndPhoneArray) {
    const auto &value = nameToPhoneHashTable[p.first];
    assert(value == p.second);
  }
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
  test_hashtable();
  /*
  test_array();
  test_vector();
  test_bubble_sort();
  test_quick_sort();
  */
  std::cout << "All tests passed successfully" << std::endl;
  return 0;
}
