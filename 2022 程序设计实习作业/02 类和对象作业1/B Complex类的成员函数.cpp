#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    //
    Complex() {};
    Complex(const char a[])
    {
        int j = 0;
        string b, c;
        while (a[j] != '+')
        {
            b += char(a[j]);
            j++;
        }
        j++;
        while (a[j] != 'i')
        {
            c += char(a[j]);
            j++;
        }
        r = atoi(b.c_str());
        i = atoi(c.c_str());
    }
    //
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}