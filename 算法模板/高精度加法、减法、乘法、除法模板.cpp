#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 10088;
//高精度加法，无负数，不能与vector结合（不知道为什么）
string Big_Integer_Add(string a, string b) { //正常无多余0的输入
	string ans;
	int na[N] = { 0 }, nb[N] = { 0 }, la = a.length(), lb = b.length(), lm = max(la, lb);
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());//把大整数的个位放在前面
	for (int i = 0; i < la; i++) na[i] = a[i] - '0';//将string变成数组
	for (int i = 0; i < lb; i++) nb[i] = b[i] - '0';
	for (int i = 0; i < lm; i++) na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;//加法并处理进位
	if (na[lm]) lm++;//如果最高位也进位了就将总长度加一
	for (int i = 0; i < lm; i++) ans += na[i] + '0';//将数组变成string
	reverse(ans.begin(), ans.end());//把大整数的个位放到后面
	return ans;
}
//高精度减法，无负数，可以小减大
string Big_Integer_Sub(string a, string b) { //正常无多余0的输入
	bool is_Negative = false;
	if (a == b) return "0";//a==b特判
	else if (a.length() < b.length() || (a.length() == b.length() && a < b)) swap(a, b), is_Negative = true;//a<b就交换并标记答案为负数

	string ans;
	int na[N] = { 0 }, nb[N] = { 0 }, la = a.length(), lb = b.length(), lm = max(la, lb);
	reverse(a.begin(), a.end()), reverse(b.begin(), b.end());//把大整数的个位放在前面
	for (int i = 0; i < la; i++) na[i] = a[i] - '0';//将string变成数组
	for (int i = 0; i < lb; i++) nb[i] = b[i] - '0';
	for (int i = 0; i < lm; i++) {
		na[i] -= nb[i];//减法
		if (na[i] < 0)//借位
			na[i] += 10, na[i + 1]--;
	}
	while (!na[lm - 1]) lm--;//只要最高位是0就将总长度减一
	for (int i = 0; i < lm; i++) ans += na[i] + '0';//将数组变成string
	if (is_Negative) ans += '-';//负数加一个负号
	reverse(ans.begin(), ans.end());//把大整数的个位放到后面
	return ans;
}
//高精度乘法，高精度乘高精度
string Big_Integer_Mul(string a, string b) { //高精度a乘高精度b，复杂度o(n^2)
	string s;
	int na[N] = { 0 }, nb[N] = { 0 }, nc[N] = { 0 }, la = a.size(), lb = b.size();//na存储被乘数，nb存储乘数，nc存储积,数组从下标1开始
	for (int i = la - 1; i >= 0; i--) na[la - i] = a[i] - '0';//将string变成数组
	for (int i = lb - 1; i >= 0; i--) nb[lb - i] = b[i] - '0';
	for (int i = 1; i <= la; i++)
		for (int j = 1; j <= lb; j++)
			nc[i + j - 1] += na[i] * nb[j];//a的第i位乘以b的第j位为积的第i+j-1位（先不考虑进位）
	for (int i = 1; i <= la + lb; i++)
		nc[i + 1] += nc[i] / 10, nc[i] %= 10;//统一处理进位
	if (nc[la + lb]) s += nc[la + lb] + '0';//判断第i+j位上的数字是不是0
	for (int i = la + lb - 1; i >= 1; i--)
		s += nc[i] + '0';//将整形数组转成字符串
	return s;
}
//高精度乘法，高精度乘低精度(int)
string Big_Integer_Mul(string a, int b) { //高精度a乘单精度b，复杂度o(n)
	string ans;
	int na[N] = { 0 }, la = a.size(), w = 0;
	for (int i = la - 1; i >= 0; i--) na[la - i - 1] = a[i] - '0';
	for (int i = 0; i < la; i++) na[i] = na[i] * b + w, w = na[i] / 10, na[i] = na[i] % 10;
	while (w) na[la++] = w % 10, w /= 10;
	la--;
	while (la >= 0) ans += na[la--] + '0';
	return ans;
}
//高精度除法，高精度除以高精度，div的第三个参数是选择返回商(nn=1)还是余数(nn=2)
int sub(int* a, int* b, int La, int Lb) {
	if (La < Lb) return -1;//如果a小于b，则返回-1
	if (La == Lb) {
		for (int i = La - 1; i >= 0; i--)
			if (a[i] > b[i]) break;
			else if (a[i] < b[i]) return -1;//如果a小于b，则返回-1

	}
	for (int i = 0; i < La; i++) { //高精度减法
		a[i] -= b[i];
		if (a[i] < 0) a[i] += 10, a[i + 1]--;
	}
	for (int i = La - 1; i >= 0; i--)
		if (a[i]) return i + 1;//返回差的位数
	return 0;//返回差的位数

}
string Big_Integer_Div(string n1, string n2, int nn) {
	string s, v;//s存商,v存余数
	int a[N], b[N], r[N], La = n1.size(), Lb = n2.size(), i, tp = La;//a，b是整形数组表示被除数，除数，tp保存被除数的长度
	fill(a, a + N, 0);
	fill(b, b + N, 0);
	fill(r, r + N, 0);//数组元素都置为0
	for (i = La - 1; i >= 0; i--) a[La - 1 - i] = n1[i] - '0';
	for (i = Lb - 1; i >= 0; i--) b[Lb - 1 - i] = n2[i] - '0';
	if (La < Lb || (La == Lb && n1 < n2)) {
		//cout<<0<<endl;
		return n1;
	}//如果a<b,则商为0，余数为被除数
	int t = La - Lb;//除被数和除数的位数之差
	for (int i = La - 1; i >= 0; i--)//将除数扩大10^t倍
		if (i >= t) b[i] = b[i - t];
		else b[i] = 0;
	Lb = La;
	for (int j = 0; j <= t; j++) {
		int temp;
		while ((temp = sub(a, b + j, La, Lb - j)) >= 0) { //如果被除数比除数大继续减
			La = temp;
			r[t - j]++;
		}
	}
	for (i = 0; i < N - 10; i++) r[i + 1] += r[i] / 10, r[i] %= 10;//统一处理进位
	while (!r[i]) i--;//将整形数组表示的商转化成字符串表示的
	while (i >= 0) s += r[i--] + '0';
	i = tp;
	while (!a[i]) i--;//将整形数组表示的余数转化成字符串表示的
	while (i >= 0) v += a[i--] + '0';
	if (v.empty()) v = "0";
	if (nn == 1) return s;
	if (nn == 2) return v;
}
//高精度除法，高精度除以单精度，nn是选择返回商(nn=1)还是余数(nn=2)
string Big_Integer_Div(string a, int b, int nn) { //高精度a除以单精度b
	string r, ans;
	int d = 0;
	if (a == "0") return a;//特判
	for (int i = 0; i < a.size(); i++) {
		r += (d * 10 + a[i] - '0') / b + '0';//求出商
		d = (d * 10 + (a[i] - '0')) % b;//求出余数
	}
	int p = 0;
	for (int i = 0; i < r.size(); i++)
		if (r[i] != '0') {
			p = i;
			break;
		}
	if (nn == 1)
		return r.substr(p);
	else if (nn == 2)
		return to_string(d);
}

int main() {
	string a, b;
	while (cin >> a >> b) {
		cout << "a=" << a << ' ' << "b=" << b << endl;
		cout << "a+b=" << Big_Integer_Add(a, b) << endl;
		cout << "a-b=" << Big_Integer_Sub(a, b) << endl;
		cout << "a*b=" << Big_Integer_Mul(a, b) << endl;
		cout << "a/b=" << Big_Integer_Div(a, b, 1) << "..." << Big_Integer_Div(a, b, 2) << endl;
		cout << endl;
	}
}
