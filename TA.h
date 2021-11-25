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

    TA(int id, std::string dept, std::string stat, int woHo){
        Student_ID = id;
        Dept = dept;
        Status = stat;
        Working_Hours = woHo;
    }
};


#endif //UNTITLED1_TA_H
