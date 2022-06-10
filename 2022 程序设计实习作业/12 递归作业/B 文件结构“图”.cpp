#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int cnt = 0;
bool Data_Structure(int level, string catalog) {//处理一层，即 (目录, ']']
	string tmp;
	vector<string> file;
	char next;

	if(level==0)
		printf("DATA SET %d:\n", ++cnt);
	for (int i = 0; i < level; i++)
		cout << "|     ";
	cout << catalog << endl;

	while (true) {
		//接下来是所有可能的情况
		next = cin.peek();
		if (next == 'f') {
			cin >> tmp;
			cin.get();
			file.push_back(tmp);
		} else if (next == 'd') {
			cin >> tmp;
			cin.get();
			Data_Structure(level + 1, tmp);
		}
		//不能返回true，万一后面是#就应该返回false了
		//不能直接返回，还要输出file
		else if (next == '*') {
			cin.get(), cin.get();//拿走*与换行符
			break;
		} else if (next == ']') {
			cin.get(), cin.get();
			break;
		}
	}

	sort(file.begin(), file.end());
	for (int i = 0; i < file.size(); i++) {
		for (int j = 0; j < level; j++)
			cout << "|     ";
		cout << file[i] << endl;
	}
	
	//一层结束了不能返回true，万一后面是#就应该返回false，所有输入结束了
	if (cin.peek() == '#')
		return false;
	else
		return true;
}
int main() {
	int notend = true;
	while (notend) {
		notend = Data_Structure(0, "ROOT");
		cout << endl;
	}
}