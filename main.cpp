#include <iostream>
#include "TA.h"
#include <fstream>
#include <string>
#include <vector>


int main() {
    int ctr;
    std::string TAinput, line, substrAlum = "Alum";
    std::vector<std::string> fileHold;

    std::ifstream TAin;
    TAin.open("TA_File.txt");

    if (TAin.is_open()){
        std::getline(TAin, TAinput);
        while (std::getline(TAin, TAinput)){
            if (TAinput.find(substrAlum) == std::string::npos){
                fileHold.push_back(TAinput);
            }
        }
    }
    else {
        std::cout << "The file is broken!";
    }
    TAin.close();

    std::ofstream TAwrite;
    ctr = fileHold.size() - 1;
    TAwrite.open("TA_File.txt");
    TAwrite << fileHold.size();
    TAwrite << "\n";
    for (int j = 0; j <= ctr; j++){
        TAwrite << fileHold[j];
        TAwrite << "\n";
    }
    TAwrite.close();

    return 0;
}
