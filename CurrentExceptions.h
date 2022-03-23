//David Martinez
//29556869
//Assignment #3
//November 30th, 2021
//COEN 244 - Stuart Thiel

#include <exception>
#include <string>
using namespace std;

#ifndef NEWASS3_CURRENTEXCEPTIONS_H
#define NEWASS3_CURRENTEXCEPTIONS_H


class CurrentExceptions : public exception {

private:
    std::string error_message;

public:
    explicit CurrentExceptions(const string& error_message) : error_message(error_message){}
    string getError_Message() const {
        return(error_message);
    }

};


#endif //NEWASS3_CURRENTEXCEPTIONS_H
