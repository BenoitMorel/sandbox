#include <iostream>
#include <cassert>
#include "array.hxx"
#include <array>
#include <numeric>

void test_array()
{
  const unsigned int size = 49;
  bmds::Array<unsigned int, size> array1;
  assert(array1.size() == size);
  for (unsigned i = 0; i < array1.size(); ++i) {
    array1[i] = i;
  }
  for (unsigned int i = 0; i < array1.size(); ++i) {
    assert(array1[i] == i);
  }
  unsigned int sum = std::accumulate(array1.begin(), array1.end(), 0);
  for (auto v: array1) {
    sum -= v;
  }
  assert(sum == 0);
}

int main(int argc, char**argv)
{
  test_array();
  std::cout << "All tests passed successfully" << std::endl;
  return 0;
}
