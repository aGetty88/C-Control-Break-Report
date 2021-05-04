/*
    cBreak.cpp
    CIS 250
    2020-1-23

    Control Break Report
*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::string;
using std::cout;
using std::setw;
using std::setfill;
using std::setprecision;
using std::fixed;
using std::showpoint;

int main(int argc, char* argv[]) {

    ifstream infile;
    ofstream outfile;

    infile.open("cb1data.txt");
    if ( !infile) {
        cerr << "Error: Input file failed to open\n";
        return 1;
    }
    outfile.open("cbreport.txt");
    if ( !outfile) {
        cerr << "Error: Output file failed to open\n";
        return 1;
    }

    string dept, empID;
    string prevDept, prevID = "$$$";
    int month, day, year;
    int recno = 0; 
    double hours;
    double deptHours, empHours, totHours = 0.0;

    outfile << "Daily hours worked by Department by Employee\n\n";
    outfile << "Dept" << setw(6) << "EmpID" << setw(9) << "Date" << setw(12) << "Hours\n\n";

    infile >> dept;
    while(infile) {
        infile >> empID >> month >> day >> year >> hours;
        recno = recno + 1;

        if(dept != prevDept && recno > 1) {
            outfile << "Employee total        " << setw(7) << empHours << "\n\n";
            deptHours += empHours;
            empHours = 0;
            outfile << "Department total      " << setw(7) << deptHours << "\n\n";
            totHours += deptHours;
            deptHours = 0;
        } else if (empID != prevID && recno > 1) {
            outfile << "Employee total        " << setw(7) << empHours <<"\n\n";
            deptHours += empHours;
            empHours = 0;
        }

        outfile << setw(3) << setfill(' ') << dept;
        outfile << setw(7) << empID;
        outfile << setw(4) << setfill(' ') << month << "/";
        outfile << setw(2) << setfill('0') << day<< "/";
        outfile << year << " ";
        outfile << setw(6) << setfill(' ') << setprecision(2) << fixed << hours << "\n";
        empHours += hours;
        prevID = empID;
        prevDept = dept;
        infile >> dept;
    }
    
    infile.close();

    outfile << "Employee total        " << setw(7) << empHours << "\n\n";
    deptHours += empHours;
    empHours = 0;
    
    outfile << "Department total      " << setw(7) << deptHours << "\n\n";
    totHours += deptHours;
    deptHours = 0;
    
    outfile << "Total hours worked    " << setw(7) << totHours << "\n";
    outfile << "\n" << recno << " records processed";

    outfile.close();
    return(0);
}
