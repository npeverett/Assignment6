#include <iostream>
#include <fstream>
#include <ctime>
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


/*
 Method implementing the bubble sort algorithm with following steps
 1) Compare first two elements and exchange if out of order
 2) Move down one element and compare second and third. Exchange if necessary.
 3) Continue process until no exchanges made
*/
void FileRead::printBubbleSort(double* array)
{
  clock_t startTime = clock();
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
  clock_t endTime = clock();
  std::cout << "Start time: " << startTime << " ms" << std::endl;
  std::cout << "End time: " << endTime << " ms" << std::endl;
  std::cout << "Elapsed time: " << endTime - startTime << " ms" << std::endl;

  /*To see sorted list, uncomment code and recompile
  for (int w = 0; w < numValues; w++)
  {
    std::cout << bubbleList[w] << std::endl;
  }
  */
}

/*
  Method implementing the quick sort algorith with the following steps
  1) Pick the first element as the pivot
  2) All elements small than pivot are placed to left
  3) All elements larger than pivot are placed to right
  4) Repeat until no replacements needed
*/
void FileRead::quickSort(double* array, int low, int high)
{
  quickList = array;

  if (low < high)
  {
    int index = partition(quickList, low, high);

    quickSort(quickList, low, index - 1);
    quickSort(quickList, index + 1, high);
  }

}

int FileRead::partition(double* array, int low, int high)
{
  double pivot = quickList[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++)
  {
    if (quickList[j] <= pivot)
    {
      i++;
      double temp = quickList[i];
      quickList[i] = quickList[j];
      quickList[j] = temp;
    }
  }
  double temp = quickList[i + 1];
  quickList[i + 1] = quickList[high];
  quickList[high] = quickList[i + 1];

  return (i + 1);
}

//Print method must be separate due to recursion
void FileRead::printQuickSort()
{
  clock_t startTime = clock();
  int num = numValues/sizeof(doubleList[0]);
  quickSort(doubleList, 0, num-1);

  //PRINT SECTION
  std::cout << "QUICK SORT" << std::endl;
  std::cout << "===========" << std::endl;
  clock_t endTime = clock();
  std::cout << "Start time: " << startTime << " ms" << std::endl;
  std::cout << "End time: " << endTime << " ms" << std::endl;
  std::cout << "Elapsed time: " << endTime - startTime << " ms" << std::endl;

  /*To see sorted list, uncomment code and recompile
  for (int w = 0; w < numValues; w++)
  {
    std::cout << quickList[w] << std::endl;
  }
  */
}

/*
  Method implementing the insertion sort algorithm. The array is
  searched and unsorted items get moved and inserted into a 'sub-list'
  which sorts based on insertion to sublist, hence "insertion sort"
*/
void FileRead::printInsertionSort(double* array)
{
  clock_t startTime = clock();
  insertionList = array;

  //SORTING SECTION
  double key;
  int j;
  for (int i = 1; i < numValues; i++)
  {
    key = insertionList[i];
    j = i -1;
  }

  while (j >= 0 && insertionList[j] > key)
  {
    insertionList[j + 1] = insertionList[j];
    j -= 1;
  }
  insertionList[j + 1] = key;

  //PRINT SECTION
  std::cout << "INSERTION SORT" << std::endl;
  std::cout << "==============" << std::endl;
  clock_t endTime = clock();
  std::cout << "Start time: " << startTime << " ms" << std::endl;
  std::cout << "End time: " << endTime << " ms" << std::endl;
  std::cout << "Elapsed time: " << endTime - startTime << " ms" << std::endl;

  /*To see sorted list, uncomment code and recompile
  for (int w = 0; w < numValues; w++)
  {
    std::cout << insertionList[w] << std::endl;
  }
  */
}

/*
  Method implementing the selection sort algorithm. This algorithm
  finds the minimum element in the array and places it at the beginning.
  There exists two subarrays, sorted and unsorted, and every iteration
  the minimum element from the unsorted gets moved to the sorted.
*/
void FileRead::printSelectionSort(double* array)
{
  clock_t startTime = clock();
  selectionList = array;

  //SORTING SECTION
  int minimumIDX;
  for (int i = 0; i < numValues - 1; i++)
  {
    minimumIDX = i;
    for (int j = i+1; j < numValues; j++)
    {
      if (selectionList[j] < selectionList[minimumIDX])
      {
        minimumIDX = j;
      }
    }
    double temp = selectionList[minimumIDX];
    selectionList[minimumIDX] = selectionList[i];
    selectionList[i] = temp;
  }

  //PRINT SECTION
  std::cout << "SELECTION SORT" << std::endl;
  std::cout << "==============" << std::endl;
  clock_t endTime = clock();
  std::cout << "Start time: " << startTime << " ms" << std::endl;
  std::cout << "End time: " << endTime << " ms" << std::endl;
  std::cout << "Elapsed time: " << endTime - startTime << " ms" << std::endl;

  /*To see sorted list, uncomment code and recompile
  for (int w = 0; w < numValues; w++)
  {
    std::cout << selectionList[w] << std::endl;
  }
  */
}

void FileRead::printAlgorithms()
{
  std::cout << '\n' << std::endl;
  printBubbleSort(doubleList);
  std::cout << '\n' << std::endl;
  printQuickSort();
  std::cout << '\n' << std::endl;
  printInsertionSort(doubleList);
  std::cout << '\n' << std::endl;
  printSelectionSort(doubleList);
  std::cout << '\n' << std::endl;
}
