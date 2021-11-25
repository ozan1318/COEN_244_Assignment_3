#ifndef UNTITLED1_TA_H
#define UNTITLED1_TA_H
#include <string>

class TA {
private:
    int Student_ID;
    std::string Dept;
    std::string Status;
    int Working_Hours;
public:
    int getStudentID();
    void setStudentID(int input);
    std::string getDept();
    void setDept(std::string input);
    std::string getStatus();
    void setStatus(std::string input);
    int getWorking_Hours();
    void setWorking_Hours(int input);
};


#endif //UNTITLED1_TA_H
