#include <iostream>
#include <fstream>
#include "FileRead.h"

//Class Constructor
FileRead::FileRead()
{
 numValues = 0;
}

//Class Destructor
FileRead::~FileRead()
{
  delete[] doubleList;
}

/*Method to get the number of values (doubles for this assignment)
in the file, most necessary for dynamic size allocation of array
in next method.
*/
int FileRead::getNumValues(std::string filename)
{
  file = filename;
  std::string line;
  std::ifstream fin;

  fin.open(file);
  if (fin.is_open() && fin.good())
  {
    fin >> numValues;
  }

  else
  {
    std::cout << "Unable to open given file. Please try again with existing file." << std::endl;
    exit(0);
  }

  return numValues;
}

/*Method that reads through double values in file and stores
in dynamically allocated array */
void FileRead::readThrough()
{
  std::string line;
  std::ifstream fin;
  fin.open(file);

  if (fin.is_open() && fin.good())
  {
    doubleList = new double[numValues];

    for (int i = 0; i < numValues; i++)
    {
      double d;
      fin >> d;
      doubleList[i] = d;
    }
  }

  else
  {
    std::cout << "Unable to open given file. Please try again with existing file." << std::endl;
    exit(0);
  }
}

//Method printing unsorted list of doubles
void FileRead::printUnsorted()
{
  std::cout << "UNSORTED" << std::endl;
  std::cout << "========" << std::endl;
  for (int i = 0; i < numValues; ++i)
  {
    /* Skip the first variable in list because it only denotes
    number of doubles present in file */
    if (i != 0)
    {
      std::cout << doubleList [i] <<  std::endl;
      continue;
    }
  }
}

/*
 Method implementing the bubble sort algorithm with following steps
 1) Compare first two elements and exchange if out of order
 2) Move down one element and compare second and third. Exchange if necessary.
 3) Continue process until no exchanges made
*/
void FileRead::printBubbleSort(double* array)
{
  bubbleList = array;

  //SORTING SECTION
  bool swapped = true;
  int j = 0;

  while (swapped)
  {
    swapped = false;
    j++;
    for (int i = 0; i < numValues - j; ++i)
    {
      if (doubleList[i] > doubleList[i + 1])
      {
        int temp = doubleList[i];
        doubleList[i] = doubleList[i + 1];
        doubleList[i + 1] = temp;
        swapped = true;
      }
    }
  }

  //PRINT SECTION
  std::cout << "BUBBLE SORT" << std::endl;
  std::cout << "===========" << std::endl;
  for (int i = 0; i < numValues; ++i)
  {
    std::cout << doubleList[i] << std::endl;
  }

}

/*
  Method implementing the quick sort algorith with the following steps
  1) Pick the first element as the pivot
  2) All elements small than pivot are placed to left
  3) All elements larger than pivot are placed to right
  4) Repeat until no replacements needed
*/
void FileRead::quickSort(double* array, int left, int right)
{
  quickList = array;

  //SORTING SECTION
  int i = left;
  int j = right;
  double pivot = quickList[0];

  while (i <= j)
  {
    while (quickList[i] < pivot)
    {
      i++;
    }
    while (quickList[j] > pivot)
    {
      j--;
    }
    if (i <= j)
    {
      double temp = quickList[i];
      quickList[i] = quickList[j];
      quickList[j] = temp;
      i++;
      j--;
    }
  }
  if (left < j)
  {
    quickSort(quickList, left, j);
  }
  if (i < right)
  {
    quickSort(quickList, i, right);
  }
}

//Print method must be separate due to recursion
void FileRead::printQuickSort()
{
  quickSort(doubleList, 0, numValues/8);

  //PRINT SECTION
  std::cout << "QUICK SORT" << std::endl;
  std::cout << "===========" << std::endl;
  for (int i = 0; i < numValues; i++)
  {
    std::cout << quickList[i] << std::endl;
  }
}

void FileRead::printInsertionSort()
{

}

void FileRead::printAlgorithms()
{
  printUnsorted();
  std::cout << '\n' << std::endl;
  printBubbleSort(doubleList);
  std::cout << '\n' << std::endl;
  printQuickSort();
}
