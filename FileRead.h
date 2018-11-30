#include <iostream>


class FileRead
{
public:
  FileRead();
  ~FileRead();

  int getNumValues(std::string);
  void readThrough();

  void printBubbleSort(double*);
  void quickSort(double*, int, int);
  int partition(double*, int, int);
  void printQuickSort();
  void printInsertionSort(double*);
  void printSelectionSort(double*);
  void printAlgorithms();

private:
  double* doubleList;
  double* bubbleList;
  double* quickList;
  double* insertionList;
  double* selectionList;
  std::string file;
  int numValues;
};
