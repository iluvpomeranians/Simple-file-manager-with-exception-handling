//David Martinez
//29556869
//Assignment #3
//November 30th, 2021
//COEN 244 - Stuart Thiel

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "CurrentExceptions.h"
#include "TA.h"
#include <algorithm>
#include <sstream>
#include <ctype.h>

using namespace std;

#ifndef NEWASS3_FILE_MANAGER_H
#define NEWASS3_FILE_MANAGER_H


class File_Manager {

private:
    vector<TA> overwrite;
    vector<TA>* pointer;

public:
    File_Manager();
    void write_default_file();
    void rewrite_update();
    void simple_write();
    void read_default_file();
    void add_new_TA();
    TA check_each_column_input();
    void sort(int column, char direction);


};


#endif //NEWASS3_FILE_MANAGER_H

