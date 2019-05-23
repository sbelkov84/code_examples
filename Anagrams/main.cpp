#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
//---------------------------------------------------------------------------
// Решена задача поиска анаграмм в векторе строк
//---------------------------------------------------------------------------

using TInputVector = std::vector<std::string>;
using TResultMap = std::map<std::string, std::vector<std::string>>;
//---------------------------------------------------------------------------

void FindAnagrams(const TInputVector& InVec, TResultMap& Result)
{
    for (auto It = InVec.begin(); It != InVec.end(); ++It)
    {
        std::string Current = *It;
        std::sort(Current.begin(), Current.end());
        Result[Current].push_back(*It);
    }
}
//---------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    TInputVector InVec = {"сон", "нос", "рост", "трос", "сорт", "торт"};
    TResultMap ResMap;
    FindAnagrams(InVec, ResMap);

    std::ofstream OutputFile;
    OutputFile.open("..\\output.txt");
    if (!OutputFile.is_open())
    {
        std::cout << "Cannot open output file\n";
        system("pause");
        return 1;
    }

    for (auto ItMap = ResMap.begin(); ItMap != ResMap.end(); ++ItMap)
    {
        for (auto ItVec = ItMap->second.begin(); ItVec != ItMap->second.end(); ++ItVec)
        {
            OutputFile << *ItVec << ' ';
        }
        OutputFile << '\n';
    }
    OutputFile.close();

    system("pause");
    return 0;
}
//---------------------------------------------------------------------------
