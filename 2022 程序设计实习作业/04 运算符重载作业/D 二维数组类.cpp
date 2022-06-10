#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
    // 在此处补充你的代码

    int** a, x, y;
public:
    Array2() {};
    Array2(int x0, int y0)
    {
        x = x0, y = y0;
        a = new int* [x];//包含每一行首元素地址的指针数组
        for (int i = 0; i < x; i++)
            a[i] = new int[y];
    }
    int& operator()(int i, int j)//重载括号，返回(i,j)元
    {
        return a[i][j];
    }
    int*& operator[](int i)//返回第i行的头指针
    {
        return a[i];
    }
    Array2& operator=(Array2& m)
    {
        //if (a == m.a)
        //    return *this;
        //if (a)//delete二维数组
        //{
        //    for (int i = 0; i < x; i++)
        //        delete[]a[i];
        //    delete[]a;
        //}
        //if (!m.a)
        //    a = NULL;
        //else
        //{
        //    x = m.x, y = m.y;
        //    a = new int* [x];
        //    for (int i = 0; i < x; i++)
        //    {
        //        a[i] = new int[y];
        //        memcpy(a[i], m.a[i], sizeof(int) * y);
        //    }
        //}
        x = m.x, y = m.y;
        a = new int* [x];
        for (int i = 0; i < x; i++)
        {
            a[i] = new int[y];
            memcpy(a[i], m.a[i], sizeof(int) * y);
        }
        return *this;
    }
    // 在此处补充你的代码
};

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
