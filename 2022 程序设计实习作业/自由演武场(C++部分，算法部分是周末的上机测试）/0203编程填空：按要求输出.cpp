#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
int  a[10] = { 0, 6, 7, 3, 9, 5, 8, 6, 4, 9 };
int  b[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
int main(int argc, char** argv) {
	// 在此处补充你的代码
	map<int, int> c;
	map<int, int>::iterator it;
	// 在此处补充你的代码
	for (int i = 0; i < 10; i++)
		c[a[i]] = b[i];
	for (it = c.begin(); it != c.end(); it++)
		cout << it->second << " ";
	return 0;
}