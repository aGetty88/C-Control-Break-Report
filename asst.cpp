
/*
    asst.cpp
    Alan Getty
    CIS 250
    2020-01-14
    
    Creates a controll break report
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using std:: cout;
using std:: string;
using std:: cerr;
using std:: ifstream;
using std:: setw;
using std:: setprecision;
using std:: setfill;
using std:: fixed;
using std:: showpoint;

int main(int argc, char* argv[]) {
    string dept, empID;
    int month, day, year;
    double hours;
    
    ifstream infile("cb1data.txt");
    if ( !infile) {
        cerr << "Error: Input file failed to open\n";
        return 1;
    }

infile >> dept;
while (infile) {
    infile >> empID >> month >> day >> year >> hours;
    cout << setw(3) << dept << "  " << setw(5) << empID
        << "  " << setw(2) << setfill(' ') << month
        << "/" << setw (2) << setfill ('0') << day
        << "/" << setw(2) << year << " "
        << fixed << showpoint << setprecision(2)
        << setw(6) << hours << '\n';
    infile >> dept;
}

infile.close();
    return 0;
}

