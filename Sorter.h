#ifndef SORTER_H
#define SORTER_H

#include "IComparable.h"

class Sorter
{
public:
  static void bubbleSort(IComparable** pItems, unsigned itemCount);
  static void quickSort(IComparable ** pItems, unsigned itemCount);
  // Other sorting algorithms can be implemented here...

};

#endif /* SORTER_H */