#include <iostream>
#include "TA.h"
#include <fstream>
#include <string>
#include <vector>

TA* readTAFromFile(std::string TAinput);

int main() {
    int ctr;
    std::string TAinput, line;
    std::vector<TA*> TAVector;

    std::ifstream TAin;
    TAin.open("TA_File.txt");
    if (TAin.is_open()){
        std::getline(TAin, TAinput);
        while (std::getline(TAin, TAinput)){
            if (TAinput.find("Alum") == std::string::npos) {
                TAinput += " ";
                TAVector.push_back(readTAFromFile(TAinput));
            }
        }
    }
    else {
        std::cout << "The file is broken!";
    }
    TAin.close();

    std::ofstream TAwrite;
    ctr = TAVector.size() - 1;
    TAwrite.open("TA_File.txt");
    TAwrite << TAVector.size();
    TAwrite << "\n";
    for (int j = 0; j <= ctr; j++){

        TAwrite << "\n";
    }
    TAwrite.close();

    return 0;
}

TA* readTAFromFile(std::string TAinput){
    int c = 0, idFile, woHoFile;
    std::string temp, deptFile, statusFile;
    while (TAinput[c] != ' '){
        temp += TAinput[c];
        c++;
    }
    idFile = stoi(temp);
    temp = "";
    c++;
    while (TAinput[c] != ' '){
        deptFile += TAinput[c];
        c++;
    }
    c++;
    while (TAinput[c] != ' '){
        statusFile += TAinput[c];
        c++;
    }
    c++;
    while (TAinput[c] != ' '){
        temp += TAinput[c];
        c++;
    }
    woHoFile = stoi(temp);
    TA* newTA = new TA(idFile, deptFile, statusFile, woHoFile);
    return newTA;
}
