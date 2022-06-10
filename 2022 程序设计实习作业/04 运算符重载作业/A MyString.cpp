#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char* p;
public:
	MyString(const char* s) {
		if (s) {
			p = new char[strlen(s) + 1];
			strcpy(p, s);
		}
		else
			p = NULL;

	}
	~MyString() { if (p) delete[] p; }

	// 在此处补充你的代码

	MyString(const MyString& s)
	{
		if (!s.p)
			p = NULL;
		else
		{
			p = new char[strlen(s.p) + 1];
			strcpy(p, s.p);
		}
	}

	void Copy(const MyString& s)
	{
		p = new char[strlen(s.p) + 1];
		strcpy(p, s.p);
	}

	MyString& operator=(const char* s)//也可void
	{
		if(p)
			delete[]p;
		if (!s)
			p = NULL;
		else
		{
			p = new char[strlen(s) + 1];//new是方括号！！！
			strcpy(p, s);
		}
		return *this;
	}

	MyString& operator=(const MyString& s)
	{
		if (p == s.p)
			return *this;
		if (p)
			delete[]p;
		if (!s.p)
			p = NULL;
		else
		{
			p = new char[strlen(s.p) + 1];
			strcpy(p, s.p);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, MyString& a)//重载为全局函数的形式，否则参数过多
	{
		os << a.p;
		return os;
	}
	// 在此处补充你的代码
};
int main()
{
	char w1[200], w2[100];
	while (cin >> w1 >> w2) {
		MyString s1(w1), s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;

	}
}
