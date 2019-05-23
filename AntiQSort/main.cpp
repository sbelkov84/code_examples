#include <vector>
#include <iostream>
#include <fstream>
//---------------------------------------------------------------------------
// Решена задача нахождения вектора, который, при быстрой сортировке с опорным элементом
// в середине вектора, сортировался бы максимально долго
//---------------------------------------------------------------------------

bool AntiQSort(std::vector<int>* Vec)
{
  int LastIndex = Vec->size() - 1;
  // если в векторе меньше трёх элементов, то выходим
  if (LastIndex < 2)
      return false;
  // использую индексы, как в обычном массиве для нахождения индекса середины вектора
  for (int i = 2; i <= LastIndex; i++)
  {
    int Mid = i / 2;
    int Tmp = Vec->at(i);
    Vec->at(i) = Vec->at(Mid);
    Vec->at(Mid) = Tmp;
  }
  //---
  return true;
}
//---------------------------------------------------------------------------

int main(int argc, char* argv[])
{
  int VecSize = 0;
  std::cout << "Please enter vector size: ";
  std::cin >> VecSize;

  //InputFile >> VecSize;
  std::vector<int> Vec;
  for (int i = 0; i < VecSize; i++)
  {
    Vec.push_back(i + 1);
  }

  if (!AntiQSort(&Vec))
  {
      std::cout << "Input vector is too little\n";
      system("pause");
      return 1;
  }

  std::ofstream OutputFile;
  OutputFile.open("..\\output.txt");
  if (!OutputFile.is_open())
  {
      std::cout << "Cannot open output file\n";
      system("pause");
      return 1;
  }

  for (int i = 0; i < VecSize; i++)
  {
    OutputFile << Vec[i] << ' ';
  }

  OutputFile.close();
  system("pause");
  return 0;
}
//---------------------------------------------------------------------------
