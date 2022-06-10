#include <iostream>
#include <string>
using namespace std;
string a[22];
int n;
int find();
int rfind();
string copy();
string add();
void insert();
void reset()
{
	string tmp, s;
	int n;
	cin >> tmp;
	if (tmp == "copy")
		s = copy();
	else if (tmp == "add")
		s = add();
	else
		s = tmp;
	cin >> tmp;
	if (tmp == "find")
		n = find();
	else if (tmp == "rfind")
		n = rfind();
	else
		n = atoi(tmp.c_str());
	a[n] = s;
}
void print()
{
	string tmp;
	int n;
	cin >> tmp;
	if (tmp == "find")
		n = find();
	else if (tmp == "rfind")
		n = rfind();
	else
		n = atoi(tmp.c_str());
	cout << a[n] << endl;
}
void printall()
{
	for (int i = 1; i <= n; i++)
		cout << a[i] << endl;
}
int find()
{
	string tmp, s;
	int n;
	cin >> tmp;
	if (tmp == "copy")
		s = copy();
	else if (tmp == "add")
		s = add();
	else
		s = tmp;
	cin >> tmp;
	if (tmp == "find")
		n = find();
	else if (tmp == "rfind")
		n = rfind();
	else
		n = atoi(tmp.c_str());
	return a[n].find(s);
}
int rfind()
{
	string tmp, s;
	int n;
	cin >> tmp;
	if (tmp == "copy")
		s = copy();
	else if (tmp == "add")
		s = add();
	else
		s = tmp;
	cin >> tmp;
	if (tmp == "find")
		n = find();
	else if (tmp == "rfind")
		n = rfind();
	else
		n = atoi(tmp.c_str());
	return a[n].rfind(s);
}
string copy()
{
	int n, x, l;
	string tmp;
	cin >> tmp;
	if (tmp == "find")
		n = find();
	else if (tmp == "rfind")
		n = rfind();
	else
		n = atoi(tmp.c_str());
	cin >> tmp;
	if (tmp == "find")
		x = find();
	else if (tmp == "rfind")
		x = rfind();
	else
		x = atoi(tmp.c_str());
	cin >> tmp;
	if (tmp == "find")
		l = find();
	else if (tmp == "rfind")
		l = rfind();
	else
		l = atoi(tmp.c_str());

	return(a[n].substr(x, l));
}
string add()
{
	string a, b, tmp;
	int n1, n2, ans;
	cin >> tmp;
	if (tmp == "copy")
		a = copy();
	else if (tmp == "add")
		a = add();
	else
		a = tmp;
	cin >> tmp;
	if (tmp == "copy")
		b = copy();
	else if (tmp == "add")
		b = add();
	else
		b = tmp;

	int l1 = a.length();
	int l2 = b.length();
	for (int i = 0; i < l1; i++)
		if (a[i] < '0' || a[i]>'9')
			goto flag;
	for (int i = 0; i < l2; i++)
		if (b[i] < '0' || b[i]>'9')
			goto flag;
	n1 = atoi(a.c_str());
	n2 = atoi(b.c_str());
	if (n1 > 99999 || n2 > 99999)
		goto flag;
	ans = n1 + n2;
	return to_string(ans);
	flag:
	return a + b;
}
void insert()
{
	string tmp, s;
	int n, x;
	cin >> tmp;
	if (tmp == "copy")
		s = copy();
	else if (tmp == "add")
		s = add();
	else
		s = tmp;
	cin >> tmp;
	if (tmp == "find")
		n = find();
	else if (tmp == "rfind")
		n = rfind();
	else
		n = atoi(tmp.c_str());
	cin >> tmp;
	if (tmp == "find")
		x = find();
	else if (tmp == "rfind")
		x = rfind();
	else
		x = atoi(tmp.c_str());
	a[n].insert(x, s);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	string cd;
	while (cin >> cd && cd != "over")
	{
		if (cd == "insert")
			insert();
		else if (cd == "reset")
			reset();
		else if (cd == "print")
			print();
		else if (cd == "printall")
			printall();
	}
}
