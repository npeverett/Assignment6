#include <iostream>


class FileRead
{
public:
  FileRead();
  ~FileRead();

  int getNumValues(std::string);
  void readThrough();
  void printAlgorithms();

  void printUnsorted();
  void printBubbleSort(double*);
  void quickSort(double*, int, int);
  void printQuickSort();
  void printInsertionSort();
  void printSelectionSort();
public:
  double* doubleList;
  double* bubbleList;
  double* quickList;
  double* insertionList;
  double* selectionlist;
  std::string file;
  int numValues;
};
