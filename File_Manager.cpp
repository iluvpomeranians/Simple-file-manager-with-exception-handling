//David Martinez
//29556869
//Assignment #3
//November 30th, 2021
//COEN 244 - Stuart Thiel

#include "File_Manager.h"

using namespace std;

//File_Manager Constructor which assigns pointer to current TA vector for a particular instance
File_Manager::File_Manager(){
    pointer = &this->overwrite  ;
}


//Part A: Writes default file of 6 students, reads it and then reprints the file without ALUMS
void File_Manager::write_default_file() {
    ofstream myfile1 ("TAs.txt");
    if (myfile1.is_open())
    {
        myfile1 << "2019 BIS 66339134 Alum 9 39\n";
        myfile1 << "2021 BCEE 98774074 Alum 7 29.\n";
        myfile1 << "2019 CSSE 73284174 Alum 15 24\n";
        myfile1 << "2016 MIAE 41075564 UGrad 7 22\n";
        myfile1 << "2017 ECE 12494364 Grad 13 33\n";
        myfile1 << "2021 BIS 41998554 Alum 10 32\n";
        myfile1.close();
    }
    else cout << "Unable to open file";

}

void File_Manager::read_default_file() {

    string line;
    ifstream myfile ("TAs.txt");
    int count = 0;

    if (myfile.is_open()) {
        cout<< "\n|| PART A: REMOVE ALUMS & UPDATE EXISITNG TEXT FILE ||\n";
        cout<< "*************************\n";
        cout<< "* Initial Student File: *\n";
        cout<< "*************************\n\n";
        cout << "# of Student Files = 6"<<endl;
        while (getline(myfile, line)) {
            cout<< line << endl;
            count++;
        }

        myfile.close();

    } else
        cout << "Unable to open file";

}

void File_Manager::rewrite_update(){

    //Open TAs.txt
         string line;
         ifstream myfile ("TAs.txt");
         int count = 0;

    //Scan for "Alum" and Exclude them
         if (myfile.is_open()) {
         while (getline(myfile, line)) {
            if (line.find("Alum") != std::string::npos)
                //ADD LINE THAT CHECKS ENTIRE LINE AS WELL TO AVOID DUPLICATES
                continue;
            else {
    //Push non-alums into TA vector
                File_Manager::pointer->push_back(TA(line));
                count++;
            }
        }

         myfile.close();



    //Write contents of vector to same text file
           ofstream myfile1("TAs.txt");
             if (myfile1.is_open()) {

                 //Start by overwriting the TAs.txt file with first value
                 int i = 0;
                 myfile1 << File_Manager::overwrite[i].getWhole_entry() << "\n";
                 i++;
                 myfile1.close();

                 //Then, we append to this text file up until the end of the vector
                 while (i < pointer->size()) {

                     myfile1.open("TAs.txt", std::fstream::app);
                     myfile1 << File_Manager::overwrite[i].getWhole_entry() << "\n";
                     myfile1.close();
                     i++;
                 }

             } else { cout << "Unable to open file"; }



    //Reprint contents of text file to the screen
        cout<< "**********************************\n";
        cout<< "* Updated file for current TA's: *\n";
        cout<< "**********************************\n\n";
        cout << "# of Student Files = " << count << endl;
             string line;
             ifstream myfile ("TAs.txt");

             if (myfile.is_open()) {

                 while (getline(myfile, line)) {
                     cout<< line << endl;
                 }

                 myfile.close();
             } else
                 cout << "Unable to open file";
    } else
        cout << "Unable to open file";

}//Read default Text file, Rewrite TA Vector without Alums, Prints updated list


//Part B: Add TA by verifying each User Input column entry

void File_Manager::add_new_TA(){

    cout<< "\n\n|| PART B: USER INPUT & UPDATE EXISITNG TEXT FILE ||\n";
    pointer->push_back(check_each_column_input());//Pushes the verified column inputs into the TA vector

    int i = 0;
    ofstream myfile1("TAs.txt");
    if (myfile1.is_open()) {
        //First, overwrite textfile with base element of vector

        myfile1 << File_Manager::overwrite[i].getWhole_entry() << "\n";
        i++;
        myfile1.close();

        //Then, Append all subsequent Vector entries to TAs.txt
        while (i < pointer->size()) {

            myfile1.open("TAs.txt", std::fstream::app);
            myfile1 << File_Manager::overwrite[i].getWhole_entry() << "\n";
            myfile1.close();
            i++;

        }
    } else { cout << "Unable to open file"; }

        //REPRINT UPDATED APPENDED FILE
        cout<< "\n**********************************\n";
        cout<< "* Updated file for current TA's: *\n";
        cout<< "**********************************\n\n";
        cout << "# of Student Files = " << i << endl;
        string line;
        ifstream myfile("TAs.txt");

        if (myfile.is_open()) {

            while (getline(myfile, line)) {
                cout << line << endl;
            }

            myfile.close();
        } else
            cout << "Unable to open file";
    }

TA File_Manager::check_each_column_input() {

        //Verify all columns, convert ints to strings, pushback a new TA object with user input information
        string year, department, id, status, hours, age;
        int year_int, id_int, hours_int, age_int;
        cout<< "***********************************************";
        cout<< "\n* To add a new TA, Please Enter The Following *\n";
        cout<< "***********************************************\n\n";
        bool year_check = false;
        bool ID_check = false;
        bool Hour_check = false;
        bool Age_check = false;
        bool Status_check = false;
        bool Dept_check = false;

        do{

            try{
                if(!year_check){
                    cout << "Year Hired(4 numbers, between 1975 to 2021):\n";

                    if((!(cin >> year_int)) || ((2021 < year_int) || (year_int < 1975))){
                        throw CurrentExceptions("Only numerical years after year 1975 and before year 2022!\n");
                    }
                }year_check = true;

                if(!Dept_check){
                    cout << "Department(min 3 letter, max 4 letter acronym):\n";
                    if((!(cin >> department)) || (3 > department.length()) || (department.length() > 4)){

                        throw CurrentExceptions("Dept must be minimum 3/maximum 4 letters\n");
                    }
                }
                //Here we convert all letters to uppercase, so that the sort compare function can work properly
                std::for_each(department.begin(), department.end(), [](char & c){c = ::toupper(c);});
                Dept_check = true;

                if(!ID_check){
                    cout << "Student ID(New ID numbers only - 8 numbers):\n";
                    cout << "[Pre-existing ID numbers]\n";
                    for(int j = 0; j < pointer->size(); j++){
                        cout<<  stoi(overwrite[j].getStudent_id()) << endl;
                    }

                    if((!(cin >> id_int)) || ((9999999 >= id_int) || (id_int > 99999999))){
                        throw CurrentExceptions("Number must be 8 numbers only please!\n\n");
                    }
                    for(int j = 0; j < pointer->size(); j++){
                        if(id_int == stoi(overwrite[j].getStudent_id())){
                            throw CurrentExceptions("This student ID already exists!\n\n");
                        }
                    }
                }ID_check=true;

                if(!Status_check) {
                    cout << "Status(UGrad or Grad only):\n";
                    if((!(cin >> status)) || ((status != "Grad") && (status != "UGrad"))){
                        throw CurrentExceptions("Status must be: Grad or UGrad:\n\n");
                    }
                } Status_check = true;

                if(!Hour_check){
                    cout << "Working Hours(2 numbers max, 99 hour max):\n";
                    if((!(cin >> hours_int)) || (0 >= hours_int) || (hours_int >= 100)){
                        throw CurrentExceptions("Work hours must be a number between 1 and 100\n\n");
                    }
                }Hour_check = true;

                if(!Age_check){
                    cout << "Age(2 numbers max,18 min age/99 max age):\n";
                    if((!(cin >> age_int)) || (18 > age_int) || (age_int >= 100)){
                        throw CurrentExceptions("Age must be a number between 18 and 100\n\n");
                    }
                }Age_check = true;





                //Convert all Int types to string//
                year = to_string(year_int);
                id = to_string(id_int);
                hours = to_string(hours_int);
                age = to_string(age_int);

                //Creates the new TA object with User Input& Push back Vector


                return TA(TA(year,department,id,status,hours,age).concatenate_columns());




            }catch(CurrentExceptions &c){
                cout << "Invalid Entry:" << c.getError_Message();
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }while(true);



    }


//Part C: Sorts the current vector TA by column and direction (Ascending or Descending)

void File_Manager::sort(int column, char direction) {

    cout<< "\n\n|| PART C: SORT EXISITNG TEXT FILE ||\n";

            if (column == 1 && (direction == 'a' || direction == 'A')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) {
                              return stoi(first.getYear_hired()) < stoi(second.getYear_hired());
                          });

            }

            if (column == 1 && (direction == 'd' || direction == 'D')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) {
                              return stoi(first.getYear_hired()) > stoi(second.getYear_hired());
                          });

            }

            if (column == 2 && (direction == 'a' || direction == 'A')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) { return first.getDept().compare(second.getDept()) < 0; });

            }

            if (column == 2 && (direction == 'd' || direction == 'D')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) { return first.getDept().compare(second.getDept()) > 0; });
            }

            if (column == 3 && (direction == 'a' || direction == 'A')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) {
                              return stoi(first.getStudent_id()) < stoi(second.getStudent_id());
                          });
            }

            if (column == 3 && (direction == 'd' || direction == 'D')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) {
                              return stoi(first.getStudent_id()) > stoi(second.getStudent_id());
                          });
            }

            if (column == 4 && (direction == 'a' || direction == 'A')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) { return first.getStatus().compare(second.getStatus()) < 0; });
            }

            if (column == 4 && (direction == 'd' || direction == 'D')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) { return first.getStatus().compare(second.getStatus()) > 0; });
            }

            if (column == 5 && (direction == 'a' || direction == 'A')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) {
                              return stoi(first.getWorking_hours()) < stoi(second.getWorking_hours());
                          });
            }

            if (column == 5 && (direction == 'd' || direction == 'D')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) {
                              return stoi(first.getWorking_hours()) > stoi(second.getWorking_hours());
                          });
            }

            if (column == 6 && (direction == 'a' || direction == 'A')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) { return stoi(first.getAge()) < stoi(second.getAge()); });
            }

            if (column == 6 && (direction == 'd' || direction == 'D')) {
                std::sort(overwrite.begin(), overwrite.end(),
                          [](TA first, TA second) { return stoi(first.getAge()) > stoi(second.getAge()); });
            }


        }

void File_Manager::simple_write() {
    //Write contents of vector to same text file
    int i = 0;
    ofstream myfile1("TAs.txt");
    if (myfile1.is_open()) {

        //Start by overwriting the TAs.txt file with first value

        myfile1 << File_Manager::overwrite[i].getWhole_entry() << "\n";
        i++;
        myfile1.close();

        //Then, we append to this text file up until the end of the vector
        while(i < pointer->size()) {

            myfile1.open("TAs.txt", std::fstream::app);
            myfile1 << File_Manager::overwrite[i].getWhole_entry() << "\n";
            myfile1.close();
            i++;
        }

    }

    else cout << "Unable to open file";



    //Reprint contents of text file to the screen
    cout<< "**********************************\n";
    cout<< "* Updated file for current TA's: *\n";
    cout<< "**********************************\n\n";
    cout << "# of Student Files = " << i << endl;
    string line;
    ifstream myfile ("TAs.txt");

    if (myfile.is_open()) {

        while (getline(myfile, line)) {
            cout<< line << endl;
        }

        myfile.close();
    } else
        cout << "Unable to open file";

}//Writes current TA Vector to Text file, Prints updated list






















