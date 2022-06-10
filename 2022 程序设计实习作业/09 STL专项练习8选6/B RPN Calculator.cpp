#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue> 
#include <math.h>
using namespace std;
stack<double> a;
priority_queue<double, vector<double>, greater<double>> m;//不是int要写出vector，默认的是vector<int>
int main()
{
	int n;
	double tmp = 0, x, y;
	string cd;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		m.push(tmp);
	}
	while (cin >> cd)
	{
		if (cd == "=")
		{
			printf("%e\n", a.top());
			m.pop();
			m.push(a.top());
			a.pop();
		}
		else if (cd == "+")
		{
			y = a.top();
			a.pop();
			x = a.top();
			a.pop();
			a.push(x + y);
		}
		else if (cd == "-")
		{
			y = a.top();
			a.pop();
			x = a.top();
			a.pop();
			a.push(x - y);
		}
		else if (cd == "*")
		{
			y = a.top();
			a.pop();
			x = a.top();
			a.pop();
			a.push(x * y);
		}
		else if (cd == "/")
		{
			y = a.top();
			a.pop();
			x = a.top();
			a.pop();
			a.push(x / y);
		}
		else if (cd == "^")
		{
			y = a.top();
			a.pop();
			x = a.top();
			a.pop();
			a.push(pow(x, y));
		}
		else
			a.push(atof(cd.c_str()));
	}
	cout << endl << scientific;//cout科学计数法用scientific
	int cnt = 1;
	while (!m.empty())
	{
		cout << m.top() << " ";
		m.pop();
		if (!(cnt % 10))
			cout<<endl;
		cnt++;
	}
}
