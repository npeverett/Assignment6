#include "FileRead.h"
#include <iostream>

int main(int argc, char **argv)
{
  if (argv[1] == NULL)
  {
    std::cerr << "Pleast attach a file to run this program." << std::endl;
    exit(0);
  }

  FileRead fr;
  fr.getNumValues(argv[1]);
  fr.readThrough();
  fr.printAlgorithms();

  return 1;
}
