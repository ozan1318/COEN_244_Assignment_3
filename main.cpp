#include <iostream>
#include "TA.h"
#include <fstream>
#include <string>
#include <vector>


int main() {
    std::string TAinput = "1", line;
    std::vector<std::string> fileHold;

    std::ifstream TAin("TA_File.txt");
    TAin.open("TA_File.txt");

    if (TAin.is_open())
    {
        while ( getline (TAin,line) )
        {
            std::cout << line << '\n';
        }
        TAin.close();
    }

    else std::cout << "Unable to open file";

    if (TAin.is_open()){
        std::getline(TAin, TAinput);
        while (std::getline(TAin, TAinput)){
            std::cout << TAinput;
            if (!TAinput.find("Alum")){
                fileHold.push_back(TAinput);
            }
        }
    }
    else {
        std::cout << "bwoah";
    }
    TAin.close();

    std::ofstream TAwrite("TA_File.txt");

    for (int j = 0; j <= (fileHold.size() - 1); j++){
        std::cout << fileHold[j];
    }

    TAwrite.open("TA_File.txt");
    TAwrite << fileHold.size();
    TAwrite << "\n";
    for (int j = 0; j <= (fileHold.size() - 1); j++){
        TAwrite << fileHold[j];
        TAwrite << "\n";
    }
    TAwrite.close();

    return 0;
}
