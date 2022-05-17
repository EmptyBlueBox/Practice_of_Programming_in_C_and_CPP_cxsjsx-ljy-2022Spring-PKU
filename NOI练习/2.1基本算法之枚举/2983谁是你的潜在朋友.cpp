#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	vector<int> mybook, bookcnt;
	cin >> n >> m;
	mybook.resize(n, 0), bookcnt.resize(m, 0);
	for (auto& i : mybook)//要修改容器元素的值，auto后要写引用
		cin >> i, i--, bookcnt[i]++;//为了按区间循环，不能舍去0
	for (auto i : mybook) {
		if (bookcnt[i] == 1)
			cout << "BeiJu" << endl;
		else
			cout << bookcnt[i] - 1 << endl;
	}
}