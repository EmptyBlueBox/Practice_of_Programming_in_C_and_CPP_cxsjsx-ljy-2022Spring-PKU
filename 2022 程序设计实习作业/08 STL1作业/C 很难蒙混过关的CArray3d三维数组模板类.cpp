#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{
	// 在此处补充你的代码
public:
	int x, y, z;
	T* p3;
	class CArray2D
	{
	public:
		T* p2;//某一层的起始指针,要基于p3指针！！！
		int col;
		CArray2D(T* p20, int y0) :p2(p20), col(y0) {};
		T* operator[](int r)
		{
			return p2 + r * col;
		}
		operator T*()
		{
			return p2;	
		}
	};
	CArray3D(int z0, int x0, int y0) :x(x0), y(y0), z(z0)
	{
		p3 = new T[x * y * z];//new在构造函数内部
	}
	CArray2D operator [](int layer)
	{
		return CArray2D(p3 + layer * x * y, y);
	}
	~CArray3D() { delete[]p3; }
	// 在此处补充你的代码
};

CArray3D<int> a(3, 4, 5);
CArray3D<double> b(3, 2, 2);
void PrintA()
{
	for (int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 5; ++k)
				cout << a[i][j][k] << ",";
			cout << endl;
		}
	}
}
void PrintB()
{
	for (int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k)
				cout << b[i][j][k] << ",";
			cout << endl;
		}
	}
}

int main()
{

	int No = 0;
	for (int i = 0; i < 3; ++i) {
		a[i];
		for (int j = 0; j < 4; ++j) {
			a[j][i];
			for (int k = 0; k < 5; ++k)
				a[i][j][k] = No++;
			a[j][i][i];
		}
	}
	PrintA();
	memset(a[1], -1, 20 * sizeof(int));
	memset(a[1], -1, 20 * sizeof(int));
	PrintA();
	memset(a[1][1], 0, 5 * sizeof(int));
	PrintA();

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				b[i][j][k] = 10.0 / (i + j + k + 1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;

	return 0;
}
