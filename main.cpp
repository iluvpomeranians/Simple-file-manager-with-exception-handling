//David Martinez
//29556869
//Assignment #3
//November 30th, 2021
//COEN 244 - Stuart Thiel

#include "File_Manager.h"



int main () {

//PART A//
//***************************//
File_Manager newfile;
newfile.write_default_file();
newfile.read_default_file();
cout<<"\n";
newfile.rewrite_update();
cout<<"\n";


//PART B//
//***************************//
    int choice;
    do {
    cout << "***********************\n";
    cout << "***      Menu       ***\n";
    cout << "***********************\n\n";
    cout << "ADD NEW TA: press 1\n";
    cout << "SORT BY COLUMN: press 2\n";
    cout << "QUIT MENU: press any other key\n";
    cin >> choice;
    switch (choice) {
        case 1:
            newfile.add_new_TA();
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << '\n';
            break;
//PART C//
//***************************//
        case 2:
        {
                bool column = false;
                bool direction = false;
                int pick;
                char asc_or_dsc;
                do {
                    try {
                        if (!column) {
                        cout<< "Please enter in the column # you would like to sort (starting from left '1' to right '6'):\n";
                        if ((!(cin >> pick)) || (pick < 1) || (pick > 6)) {
                            throw CurrentExceptions("Column number must be between 1 to 6 inclusive!\n\n");
                        }
                    }column = true;

                        if(!direction) {
                            cout<< "Please type letter 'A' for ascending and 'D' for descending (lowercase also works!):\n";
                            if ((!(cin>>asc_or_dsc)) || (!(asc_or_dsc == 'a' || asc_or_dsc == 'A' || asc_or_dsc == 'D' || asc_or_dsc == 'd'))) {
                                throw CurrentExceptions("Must be only 'A' or 'D' (or lowercase)!\n\n");
                            }
                        }direction = true;
                        break;
                    }catch (CurrentExceptions c){
                        cout << "Invalid Entry:" << c.getError_Message();
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                }while(true);
                newfile.sort(pick, asc_or_dsc);
                newfile.simple_write();
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << '\n';
        }
            break;
        //case 3: newfile.rewrite_update();
            cout << '\n';
            break;
        default:
            cout << "Exiting Menu! Goodbye!\n";
    }
}while((choice == 1) || (choice ==2));



    return 0;
}

