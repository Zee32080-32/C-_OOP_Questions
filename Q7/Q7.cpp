#include <iostream>
#include <iomanip>      // std::setw
#include <sstream>      // std::ostringstream
#include <string>
#include <map>
#include <utility>      // std::pair


using namespace std;
/* Turn a token to a string - tokens cannot contain spaces or other characters that are not valid for a variable name. */
#define X(token) #token
string null = X(NULL);

string department_names[] =
{

   X(Sales)

   , X(Engineering)

   , X(Clerical)

   , X(Marketing)

};



string employee_names[] =
{

   X(Rafferty)

   , X(Jones)

   , X(Heisenberg)

   , X(Robinson)

   , X(Smith)

   , X(Williams)

};



/* Table department: columns = DepartmentID, DepartmentName */

map<int, string*> department = { {31, department_names + 0}

                                 ,{33, department_names + 1}

                                 ,{34, department_names + 2}

                                 ,{35, department_names + 3} };

/* Table employee: columns = LastName, DepartmentID */

map<string*, int> employee = { {employee_names + 0, 31}

                               ,{employee_names + 1, 33}

                               ,{employee_names + 2, 33}

                               ,{employee_names + 3, 34}

                               ,{employee_names + 4, 34}

                               ,{employee_names + 5,  0} };



string get_null_or_X(int x)
{

    ostringstream os;  os << setw(15);

    if (0 == x) os << null;

    else        os << x;

    return os.str();

}

string get_null_or_X(const string* x)
{

    ostringstream os;  os << setw(15);

    if (nullptr == x) os << null;

    else              os << *x;

    return os.str();

}

string get_null_or_X(const char* x)
{
    ostringstream os;
    os << setw(15) << x;
    return os.str();

}



void print_dep()
{
    cout << get_null_or_X(X(DepartmentID)) << get_null_or_X(X(DepartmentName)) << endl;

    for (const auto& dep : department) {
        int departmentID = dep.first;
        string* departmentName = dep.second;
        cout << setw(14) << departmentID << " " << *departmentName << endl;
    }

}



void print_emp()
{
    cout << get_null_or_X(X(LastName)) << get_null_or_X(X(DepartmentID)) << endl;

    for (const auto& emp : employee) {
        string* lastName = emp.first;
        int departmentID = emp.second;
        cout << setw(14) << *lastName << setw(14) << get_null_or_X(departmentID) << endl;
    }

}



void print_inner_join()
{

    /* YOUR CODE HERE */

    cout << get_null_or_X(X(LastName)) << get_null_or_X(X(DepartmentID)) << get_null_or_X(X(DepartmentName)) << endl;

    for (const auto& emp : employee)
    {
        string* lastName = emp.first;
        int departmentID = emp.second;

        // Find the department name based on the department ID in the department map
        auto departmentIt = department.find(departmentID);
        if (departmentIt != department.end()) {
            string* departmentName = departmentIt->second;
            cout << setw(15) << *lastName << setw(15) << departmentID << setw(15) << *departmentName << endl;
        }
    }
}



int main() {

    print_dep();
    print_emp();
    print_inner_join();

    return 0;

}
