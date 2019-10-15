namespace bmalgo {

template<typename T>
void swap(T &t1, T &t2)
{
  T temp(t1);
  t1 = t2;
  t2 = temp;
}

template<typename It>
void iterSwap(It first, It second)
{
  swap(*first, *second);
}

template<typename It>
size_t distance(It first, It last)
{
  size_t res = 0;
  while (first++ != last) {
    res++;
  }
  return res;
}

template<typename It>
It next(It it)
{
  return ++it;
}

template<typename It>
void bubbleSort(It first, It last)
{
  bool stop = false;
  while (!stop) {
    stop = true;
    It nextIt;
    for (auto it = first; (nextIt = next(it)) != last; ++it) {
      if (*it > *(nextIt)) {
        stop = false;
        iterSwap(it, nextIt);
      }
    }
  }
}


}
