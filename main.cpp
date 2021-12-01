#include <iostream>
#include "TA.h"
#include <fstream>
#include <string>
#include <vector>
#include <regex>

TA* readTAFromFile(std::string TAInput);
void addTA(std::vector<TA*> &TAVector);

int main() {
    int ctr;
    const std::regex menu1("^[1-3]{1}$"), menu2("^[1-4]{1}$");
    auto getSIDPtr = &TA::getStudentID, getWoHoPtr = &TA::getWorking_Hours; // function pointers are created for the member getters to make the lambdas shorter
    auto getStatPtr = &TA::getStatus, getDeptPtr = &TA::getDept;
    std::string TAInput, line;
    std::vector<TA*> TAVector;

    std::ifstream TAin;
    TAin.open("TA_File.txt");
    if (TAin.is_open()){
        std::getline(TAin, TAInput);  // take the TA counter from the file, this isn't important for the code
        while (std::getline(TAin, TAInput)){ // take new TA from the file
            if (TAInput.find("Alum") == std::string::npos) { // check if it's an Alum TA, exclude if it is
                TAInput += " ";
                TAVector.push_back(readTAFromFile(TAInput)); // pass the TA information to readTAFromFile to create a new TA, and add it to the vector
            }
        }
    }
    else {
        std::cout << "The file is broken!";
    }
    TAin.close();

    int choice = 0, temp = 0;

    do {
        std::cout << "File updated. What would you like to do next?\n1. Add new TA\n2. Sort existing TA's\n3. Quit" << std::endl; // menu
        CHOICE:do {
            std::cin >> choice;
            std::string choiceCheck = std::to_string(choice);
            if (!std::regex_match(choiceCheck, menu1)){ // check if menu input is correct
                std::cout << "\nIncorrect input! Please enter a number between 1 and 3.\n";
            }
        } while (choice <= 0 || choice >= 4);

        switch (choice){
            case 1:{
                addTA(TAVector);
                break;
            }
            case 2:{
                int choice2, order;
                std::cout << "What would you like to sort the TA's by?\n1. Student ID's\n2. Departments\n3. Status\n4. Working Hours" << std::endl;
                INP1:std::cin >> choice2;
                std::string choice2check = std::to_string(choice2);
                if (!std::regex_match(choice2check, menu2)){
                    std::cout << "Incorrect category input. Please enter an integer between 1 and 4." << std::endl;
                    goto INP1;
                }
                std::cout << "How would you like to sort them?\n1.Ascending\n2.Descending" << std::endl;
                INP2:std::cin >> order;
                if (order != 1 && order != 2){
                    std::cout << "Incorrect sort input. Please enter 1 or 2" << std::endl;
                    goto INP2;
                }

                switch (choice2){
                    case 1: {
                        sort(TAVector.begin(), TAVector.end(), [&getSIDPtr, choice2](auto& lhs, auto& rhs) {
                            if (choice2 == 1){
                                return (lhs->*getSIDPtr)() < (rhs->*getSIDPtr)();
                            }
                            else if (choice2 ==2){
                                return (lhs->*getSIDPtr)() > (rhs->*getSIDPtr)();
                            }
                        });
                        break;
                    }
                    case 2:{
                        sort(TAVector.begin(), TAVector.end(), [&getDeptPtr, choice2](auto& lhs, auto& rhs) {
                            if (choice2 == 1){
                                return (lhs->*getDeptPtr)() > (rhs->*getDeptPtr)();
                            }
                            else if (choice2 ==2){
                                return (lhs->*getDeptPtr)() < (rhs->*getDeptPtr)();
                            }
                        });
                        break;
                    }
                    case 3:{
                        sort(TAVector.begin(), TAVector.end(), [&getStatPtr, choice2](auto& lhs, auto& rhs) {
                            if (choice2 == 1){
                                return (lhs->*getStatPtr)() > (rhs->*getStatPtr)();
                            }
                            else if (choice2 ==2){
                                return (lhs->*getStatPtr)() < (rhs->*getStatPtr)();
                            }
                        });
                        break;
                    }
                    case 4:{
                        sort(TAVector.begin(), TAVector.end(), [&getWoHoPtr, choice2](auto& lhs, auto& rhs) {
                            if (choice2 == 1){
                                return (lhs->*getWoHoPtr)() < (rhs->*getWoHoPtr)();
                            }
                            else if (choice2 ==2){
                                return (lhs->*getWoHoPtr)() > (rhs->*getWoHoPtr)();
                            }
                        });
                        break;
                    }
                    default:{
                        std::cout << "You have entered an incorrect input. The system will sort by the Student ID number.";
                    }
                }
                break;
            }
            case 3:{
                temp++;
                break;
            }
            default:{
                std::cout << "You somehow managed to enter an incorrect menu input and got through the check. Sending you back to the menu input, please enter a number between 1 and 3";
                goto CHOICE;

            }
        }

    } while(temp == 0);

    std::ofstream TAWrite;
    ctr = TAVector.size() - 1;
    TAWrite.open("TA_File.txt");
    TAWrite << TAVector.size();
    TAWrite << "\n";
    for (int j = 0; j <= ctr; j++){
        TAWrite << TAVector[j]->getStudentID() << " " << TAVector[j]->getDept() << " " << TAVector[j]->getStatus() << " " << TAVector[j]->getWorking_Hours() << "\n";
    }
    TAWrite.close();

    return 0;
}

TA* readTAFromFile(std::string TAInput){
    int c = 0, idFile, woHoFile;
    std::string temp, deptFile, statusFile;
    while (TAInput[c] != ' '){ // read the ID until the first space
        temp += TAInput[c];
        c++;
    }
    idFile = stoi(temp); // the ID and work hours are input as strings but stored as ints, they are converted here
    temp = "";
    c++;
    while (TAInput[c] != ' '){ // read the department until the next space
        deptFile += TAInput[c];
        c++;
    }
    c++;
    while (TAInput[c] != ' '){ // read the status until the next space
        statusFile += TAInput[c];
        c++;
    }
    c++;
    while (TAInput[c] != ' '){ // read the work hours until the next space (when the line is over)
        temp += TAInput[c];
        c++;
    }
    woHoFile = stoi(temp);
    TA* newTA = new TA(idFile, deptFile, statusFile, woHoFile); // new TA is created and returned to the main to add to the vector
    return newTA;
}

void addTA(std::vector<TA*> &TAVector){
    const std::regex integer ("^[0-9]*$"), dept ("^[A-Z]{3,4}$"), stat ("^[a-zA-Z]{4,5}$"); // create regex's
    int idInput, workHourInput, ctr = TAVector.size() - 1;
    std::string deptInput, statusInput, idInCheck, whInCheck;
    bool newID = false, validIDIn = false, validDeptIn = false, validStatIn = false, validWHIn = false;

    std::cout << "Enter the Student ID number of the TA:\n";
    LOOP:do{ // takes in student id input, checks if it's a correct input, then checks if it already exists in the file.
        do{
            std::cin >> idInput;
            idInCheck = std::to_string(idInput);
            if (!std::regex_match(idInCheck, integer)){// check if it's purely made up of integers 0-9, no size limit
                std::cout << "Incorrect input! Please only enter integers for the student ID." << std::endl;
            }
            else{
                validIDIn = true;
            }
        } while(!validIDIn);

        for (int i = 0; i <= ctr; i++){
            if (idInput == TAVector[i]->getStudentID()){ // look through vector, check if any student id's match the input
                std::cout << "\nYou have entered a Student ID number that is already in the file. Please enter a different Student ID number." << std::endl;
                goto LOOP; // if there are any matches, go back to the start of the original do/while loop
            }
            newID = true;
        }
    } while(!newID);

    std::cout << "\nEnter the department of the TA:\n";
    do{ // check the validity of the department input
        std::cin >> deptInput;
        if (!std::regex_match(deptInput, dept)){// check if it's a string of 3-4 capital letters
            /*note: if a user enters a letter in the ID input, the message below could be thrown as extra things remain in the input stream*/
            std::cout << "Incorrect input! Please only enter the 3-4 letter abbreviation of the department in all caps (ex: 'ECE' or 'MIAE')." << std::endl;
        }
        else{
            validDeptIn = true;
        }
    } while(!validDeptIn);

    std::cout << "\nEnter the status of the TA:\n";
    do{ // check the validity of the status input
        std::cin >> statusInput;
        if (!std::regex_match(statusInput, stat)){// check if it's a string of 4-5 letters
            std::cout << "Incorrect input! Please only enter the 3-4 letter abbreviation of the department in all caps (ex: 'ECE' or 'MIAE')." << std::endl;
        }
        else{
            validStatIn = true;
        }
    } while(!validStatIn);

    std::cout << "\nEnter the working hours of the TA\n";
    do{ // check the validity of the work hour input
        std::cin >> workHourInput;
        whInCheck = std::to_string(workHourInput);
        if (!std::regex_match(whInCheck, integer)){// check if it's purely made up of integers 0-9, no size limit
            std::cout << "Incorrect input! Please only enter integers for the work hours." << std::endl;
        }
        else{
            validWHIn = true;
        }
    } while(!validWHIn);

    TAVector.push_back(new TA(idInput, deptInput, statusInput, workHourInput)); // new TA is added to the vector
}
