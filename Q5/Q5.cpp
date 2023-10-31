#include <iostream>

using namespace std;        // File: q5.cc

class my_array_over2 
{
    int len = 1;
    int* a = new int[1];

public:

    my_array_over2() { a[0] = 0; }

    my_array_over2(int ln, const int* o) : len(ln), a(new int[ln])

    {
        for (int n = 0; n < ln; ++n) a[n] = o[n];
    }

    ~my_array_over2() { delete[] a; }

    int get_length() const { return len; }

    int get(int i) const {
        if (i >= 0 && i < len)
            return a[i];
        else
            throw std::out_of_range("Index out of range");
    }

    int set(int i, int v) {
        if (i >= 0 && i < len) {
            int tmp = a[i];
            a[i] = v;
            return tmp;
        }
        else
            throw std::out_of_range("Index out of range");
    }

    int operator[](int i) const {
        return get(i);
    }

    int& operator[](int i) {
        if (i >= 0 && i < len) {
            return a[i];
        }
        else
            throw std::out_of_range("Index out of range");
    }

};



void foo(const my_array_over2& a2, int i) 
{
    if (i < a2.get_length())
    {
        std::cout << a2[i] << std::endl;

    }
}



int main() {

    int zero12[] = { 13, 1, 2 };
    my_array_over2 a1(3, zero12);
    a1[0] = 14; /* EXTRA LINE!!! */
    foo(a1, 0); // should print 14

    return 0;

}