#include <iostream>

using namespace std;    // File: q2.cc

class person {

    int age;

public:

    person() : age() {}                //
    person(int a) : age(a) {}

    int  get_age() const;

    void set_age(int a);

};
void person::set_age(int a)
{
    age = a;
}

int person::get_age() const
{
    return this->age;
}

int main() {

    person p1;

    p1.set_age(25);

    cout << p1.get_age() << endl; // should print 25

    return 0;

}