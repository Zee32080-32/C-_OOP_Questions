#include <iostream>

using namespace std;      // File: q4.cc

class my_array_over {

    int len = 1;

    int* a = new int[1];

public:

    my_array_over() { a[0] = 0; }

    my_array_over(int ln, const int* o) : len(ln), a(new int[ln])

    {
        for (int n = 0; n < ln; ++n) a[n] = o[n];
    }

    ~my_array_over() { delete[] a; }

    int get_length() const { return len; } // Add this line

    void set(int index, int value) { a[index] = value; } // Add this line

    int operator[](int index) const { return a[index]; } // Add this line

};

void foo(const my_array_over& a2, int i) {

    if (i < a2.get_length())

        std::cout << a2[i] << std::endl;

}

int main() {

    int zero12[] = { 23, 1, 2 };

    my_array_over a1(3, zero12);

    a1.set(0, 13);

    foo(a1, 0); // should print 13

    return 0;

}