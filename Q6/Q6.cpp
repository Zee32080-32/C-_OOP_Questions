#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;        // File: q6.cc

class m2dvector 
{
    vector<int> vi = { 0, 0 };

public:

    m2dvector(vector<int> some_vi) : vi(some_vi) { if (some_vi.size() > 2) throw std::exception(); }
    const vector<int>& get_data() const { return vi; }
};

// Overloaded output operator
ostream& operator<<(ostream& os, const m2dvector& vec) {
    os << "<" << vec.get_data()[0] << " " << vec.get_data()[1] << ">";
    return os;
}

// Overloaded input operator
istream& operator>>(istream& is, m2dvector& vec) {
    char c;
    int num1, num2;
    is >> c >> num1 >> num2 >> c;
    vec = m2dvector({ num1, num2 });
    return is;
}


int main() 
{
    vector<int> vi = { 11, 12, 13, 14, 15 };
    m2dvector z1({ vi[0], vi[1] });
    m2dvector z2({ vi[3], vi[4] });
    cout << z1 << endl; /* should print: <11 12> */
    cout << z2 << endl; /* should print: <14 15> */
    string s1 = "<11 12>    <13 14>a";
    istringstream iss(s1);
    iss >> z2 >> z1;
    cout << z1 << endl; /* should print: <13 14> */
    cout << z2 << endl; /* should print: <11 12> */
    char c;

    iss >> c; cout << c << endl; /* should print ‘a’ – the char after the 2nd m2dvector above. */
    ostringstream oss;
    oss << z2;
    string so = oss.str();

    for (char c : so)
        if (c == '\n') { cerr << "Output has a newline\n"; return 0; }
    cerr << "Output does not have a newline\n";
    return 0;

}