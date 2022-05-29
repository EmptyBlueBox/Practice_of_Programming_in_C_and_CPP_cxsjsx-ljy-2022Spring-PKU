#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

//利用C函数直接转换
//strtol是自带的；itoa在stdlib.h
int main() {
	string x;
	int base1, base2;
	cout << "请输入要转换的数与其转换前后的进制数" << endl;
	while (cin >> x >> base1 >> base2) {
		int Ten = strtol(x.c_str(), NULL, base1);//转换为十进制！！！
		char ans[101];//itoa把答案放进char数组
		itoa(Ten, ans, base2);//转换为base2进制！！！
		for (int i = 0; i < 101; i++)
			if (ans[i] >= 'a' && ans[i] <= 'f')
				ans[i] = ans[i] - 'a' + 'A';//转换为大写
		cout << ans << endl << "请输入要转换的数与其转换前后的进制数" << endl;
	}
}

//将小于十进制的数转换为十进制
/*
int convert(int x, int base) { //将base进制下的x转换为10进制
	int ans = 0;
	for (auto c : to_string(x))//从高位到低位
		ans = ans * base + c - '0';//每经过一位就乘base，再加这一位（相当于这一位是个位）
	return ans;
}
int main() {
	cout << "请输入要转换为十进制的数与其进制数（进制数小于10）" << endl;
	int x, base;
	while (cin >> x >> base)
		cout << convert(x, base) << endl << "请输入要转换为十进制的数与其进制数" << endl;
}
*/