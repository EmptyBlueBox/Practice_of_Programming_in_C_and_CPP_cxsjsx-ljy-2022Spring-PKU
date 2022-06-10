#include <iostream>
#include <set>//要找最小的元素不能用queue 
#include <queue>
using namespace std;
typedef pair<int, int> p;//first是质因数
class cmpMax
{
public:
	bool operator()(p a, p b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
	}
};
class cmpMin
{
public:
	bool operator()(p a, p b)
	{
		if (a.first == b.first)
			return a.second > b.second;
		else
			return a.first > b.first;
	}
};
//bool isPrime(int n)
//{
//	for (int i = 2; i * i <= n; i++)
//		if (!(n % i))
//			return false;
//	return true;
//}
int Factor(int n)
{
	int ans = 0, n0 = n;
	int i;
	for (i = 2; i <= n; i++)
		if (!(n % i) && i != n0)
		{
			ans++;
			while (!(n % i))
				n /= i;
		}
	return ans;
}
int main()
{
	int cnt, n;
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmpMax> M;
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmpMin> m;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> n;
			M.push({ Factor(n),n });
			//cout << n << ":" << Factor(n) << " ";
			m.push({ Factor(n),n });
		}
		cout << M.top().second << " " << m.top().second << endl;
		M.pop(), m.pop();
	}
}
