#include "TA.h"

int TA::getStudentID() {
    return Student_ID;
}

void TA::setStudentID(int input){
    Student_ID = input;
}

std::string TA::getDept(){
    return Dept;
}

void TA::setDept(std::string input){
    Dept = input;
}

std::string TA::getStatus(){
    return Status;
}

void TA::setStatus(std::string input){
    Status = input;
}

int TA::getWorking_Hours(){
    return Working_Hours;
}

void TA::setWorking_Hours(int input){
    Working_Hours = input;
}
