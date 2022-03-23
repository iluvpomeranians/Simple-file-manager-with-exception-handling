//David Martinez
//29556869
//Assignment #3
//November 30th, 2021
//COEN 244 - Stuart Thiel

#include "TA.h"
#include <vector>
#include <sstream>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;
using std::stringstream;



TA::TA(string whole_entry) {

    this->whole_entry = whole_entry;
    chop_Whole_entry();

}


TA::TA(string year_hired, string dept, string student_id, string status, string working_hours, string age) {
    this->year_hired = year_hired;
    this->dept = dept;
    this->student_id = student_id;
    this->status = status;
    this->working_hours = working_hours;
    this->age = age;
    this->space = " ";
}

string TA::getYear_hired()  {
    return this->year_hired;
}

string TA::getDept()  {
    return this->dept;
}

string TA::getStudent_id()  {
    return this->student_id;
}

string TA::getStatus() {
    return this->status;
}

string TA::getWorking_hours()  {
    return this->working_hours;
}

string TA::getAge()  {
    return this->age;
}

string TA::getWhole_entry()  {
    return this->whole_entry;
}

string TA::concatenate_columns() {

    this->whole_entry = this->year_hired + this->space + this->dept + this->space + this->student_id
            + this->space + this->status + this->space + this->working_hours + this->space
            + this->age;
    return this->whole_entry;
}

void TA::chop_Whole_entry() {

    char space_char = ' ';
    stringstream sstream(getWhole_entry());
    vector<string> chop;
    string column;
    while (std::getline(sstream, column, space_char )){
        chop.push_back(column);
    }

    year_hired = chop[0];
    dept = chop[1];
    student_id = chop[2];
    status = chop[3];
    working_hours = chop[4];
    age = chop[5];



}












