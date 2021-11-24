#include <iostream>
#include "TA.h"
#include <fstream>
#include <string>

int main() {
    std::string TAinput;
    int lineNum;

    std::ifstream TAin;
    TAin.open("TA_File.txt");
    std::getline(TAin, TAinput);
    lineNum = std::stoi(TAinput);
    for (int i = 0; i < lineNum; i++){

    }




    return 0;
}
