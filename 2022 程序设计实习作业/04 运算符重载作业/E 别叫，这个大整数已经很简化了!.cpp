#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
	// 在此处补充你的代码
	char a[203] = { 0 };
public:
	CHugeInt()
	{
		memset(a, 0, sizeof(a));
	}
	CHugeInt(const char s[])
	{
		strcpy(a, s);
	}
	CHugeInt(const int& n)
	{
		if (n == 0)
		{
			a[0] = '0';
			return;
		}
		int tmp = n, d = 0;
		while (tmp > 0)
			d++, tmp /= 10;
		tmp = n;
		for (int i = 0; i < d; i++)
		{
			a[d - i - 1] = tmp % 10 + '0';
			tmp /= 10;
		}
	}
	friend ostream& operator<<(ostream& os, const CHugeInt& m)
	{
		int len = strlen(m.a);
		for (int i = 0; i <= len - 1; i++)
			os << m.a[i];
		return os;
	}
	CHugeInt operator+(const CHugeInt& b)//通过构造函数将int转换为CHugeInt
		//为什么没有const报错？;为什么不能用&
	{
		CHugeInt ans;
		if (a[0] == '0' && b.a[0] == '0')
		{
			ans.a[0] = '0';
			return ans;
		}
		int tmp[210] = { 0 };
		int len1 = strlen(a), len2 = strlen(b.a);//用int做高精
		for (int i = 0; i < len1; i++)
			tmp[i] = a[len1 - i - 1] - '0';
		for (int i = 0; i < len2; i++)
			tmp[i] += b.a[len2 - i - 1] - '0';
		for (int i = 0; i <= 105; i++)
		{
			tmp[i + 1] += tmp[i] / 10;
			tmp[i] %= 10;
		}
		int flag = 0;
		for (int i = 205; i >= 0; i--)
		{
			if (tmp[i] == 0 && flag==0)
				continue;
			else
			{
				flag = 1;
				ans.a[i] = tmp[i] + '0';
			}
		}
		rev(ans.a);
		return ans;
		//if (len1 >= len2)
		//{
		//	for (int i = 0; i < len1; i++)
		//		ans.a[i] = a[len1 - i - 1];
		//	for (int i = 0; i < len2; i++)
		//		ans.a[i] += b.a[len2 - i - 1] - '0';
		//}
		//else
		//{
		//	for (int i = 0; i < len1; i++)
		//		ans.a[i] = a[len1 - i - 1] - '0';
		//	for (int i = 0; i < len2; i++)
		//		ans.a[i] += b.a[len2 - i - 1];
		//}

		//for (int i = 0; i < max(len1, len2) - 1; i++)
		//{
		//	ans.a[i + 1] += (ans.a[i] - '0') / 10;
		//	ans.a[i] = '0' + (ans.a[i] - '0') % 10;
		//}
		//if (ans.a[max(len1, len2) - 1] - '0' > 9)
		//{
		//	ans.a[max(len1, len2) - 1] = '0' + (ans.a[max(len1, len2) - 1] - '0') % 10;
		//	ans.a[max(len1, len2)] = '1';
		//}
		//rev(ans.a);
		//return ans;
	}
	CHugeInt operator+(int& n)
	{
		return *this + CHugeInt(n);
	}
	friend CHugeInt operator+(int& n, CHugeInt& m)
	{
		return m + n;
	}
	void operator+=(int n)
	{
		*this = *this + n;
	}
	CHugeInt operator++()
	{
		*this = *this + 1;
		return *this;
	}
	CHugeInt operator++(int k)
	{
		CHugeInt tmp = *this;
		*this = *this + 1;
		return tmp;
	}
	void rev(char str[])
	{
		int len = strlen(str);
		for (int i = 0, j = len - 1; i <= j; i++, j--)
		{
			char tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
		}
	}
	// 在此处补充你的代码
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
