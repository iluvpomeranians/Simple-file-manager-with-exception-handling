//David Martinez
//29556869
//Assignment #3
//November 30th, 2021
//COEN 244 - Stuart Thiel

#include <string>
#include <iostream>
using namespace std;

#ifndef NEWASS3_TA_H
#define NEWASS3_TA_H


class TA {

private:
    string year_hired;
    string dept;
    string student_id;
    string status;
    string working_hours;
    string age;
    string whole_entry;
    string space;

public:
    TA(string whole_entry);
    TA (string year_hired, string dept, string student_id, string status, string working_hours, string age);

    void chop_Whole_entry();
    string getYear_hired() ;
    string getDept() ;
    string getStudent_id() ;
    string getStatus() ;
    string getWorking_hours() ;
    string getAge() ;
    string getWhole_entry() ;
    string concatenate_columns();

};


#endif //NEWASS3_TA_H
