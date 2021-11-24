#include <iostream>
#include "TA.h"
#include <fstream>
#include <string>
#include <vector>


int main() {
    std::string TAinput;
    int lineNum;
    std::vector<std::string> fileHold;

    std::ifstream TAin("TA_File.txt");
    std::ofstream TAwrite("TA_File.txt", std::ofstream::trunc);
    TAin.open("TA_File.txt");
    std::getline(TAin, TAinput);
    lineNum = std::stoi(TAinput);
    for (int i = 0; i < lineNum; i++){
        std::getline(TAin, TAinput);
        if (!TAinput.find("Alum")){
            fileHold.push_back(TAinput);
        }
    }
    TAin.close();
    TAwrite.open("TA_File.txt");


    return 0;
}
