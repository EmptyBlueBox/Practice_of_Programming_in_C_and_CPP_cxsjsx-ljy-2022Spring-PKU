#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D {
// 在此处补充你的代码
	public:
		int x,y,z;
		T* p3;
		CArray3D(int _z,int _x,int _y):x(_x),y(_y),z(_z) {
			p3=new T[x*y*z];
		}
		class CArray2D {//内部类和外部类没有继承或friend关系
			public:
				T* p2;
				int x,y;
				CArray2D(T*p3,int _x,int _y,int layer):x(_x),y(_y) {
					p2=p3+layer*x*y;
				}
				T* operator[](int tmp_x) {
					return p2+tmp_x*y;
				}
				operator T*() {
					return p2;
				}
		};
		CArray2D operator[](int layer) {
			return CArray2D(p3,x,y,layer);
		}
// 在此处补充你的代码
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA() {
	for(int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 5; ++k)
				cout << a[i][j][k] << "," ;
			cout << endl;
		}
	}
}
void PrintB() {
	for(int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k)
				cout << b[i][j][k] << "," ;
			cout << endl;
		}
	}
}

int main() {

	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];
		}
	}
	PrintA();
	memset(a[1],-1,20*sizeof(int));
	memset(a[1],-1,20*sizeof(int));
	PrintA();
	memset(a[1][1],0,5*sizeof(int));
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;

	return 0;
}