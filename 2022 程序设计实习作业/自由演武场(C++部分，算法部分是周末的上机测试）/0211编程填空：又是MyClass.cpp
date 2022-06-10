#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
// 在此处补充你的代码
template<class T>
class CMyClass {
	public:
		int len;
		T* p;
		CMyClass(T* _p,int _len):p(_p),len(_len) {}
		T operator[](int i) {
			return p[i];
		}
};
// 在此处补充你的代码
int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while ( t -- ) {
		int m;
		scanf("%d",&m);
		for (int i = 0; i < m; ++i)
			scanf("%d",a+i);
		char s[100];
		scanf("%s",s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}