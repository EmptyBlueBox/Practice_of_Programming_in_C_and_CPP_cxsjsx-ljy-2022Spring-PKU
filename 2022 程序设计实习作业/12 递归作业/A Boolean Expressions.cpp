#include <iostream>
using namespace std;
//一个表达式是由许多VF()通过&|在一起的
bool expression_value();
bool factor_value();
int main() {
	int cnt = 1;
	while (cin.peek() != EOF) {
		cout << "Expression " << cnt << ": ";
		cnt++;
		if (expression_value())
			cout << "V" << endl;
		else
			cout << "F" << endl;
		cin.get();
	}
}
bool expression_value() {
	bool result = factor_value();
	while (true) {
		char next = cin.peek();
		if (next == '&') {
			cin.get();
			bool next_value = factor_value();
			result &= next_value;
		} else if (next == '|') {
			cin.get();
			bool next_value = factor_value();
			result |= next_value;
		} else if (next == ' ')
			cin.get();
		else
			break;
	}
	return result;

//不能这么做，因为因子的结合是从左往右的，这样写是从右往左，有区别
//就好像加减法不能从右往左算一样
//	bool ans1 = factor_value();
//	char next = cin.peek();
//	while (next == ' ') {
//		cin.get();
//		next = cin.peek();
//	}
//	if (next == '&') {
//		cin.get();
//		return ans1 & expression_value();
//	} else if (next == '|') {
//		cin.get();
//		return ans1 | expression_value();
//	} else
//		return ans1;

}
bool factor_value() {
	char next = cin.peek();
	while (next == ' ') {
		cin.get();
		next = cin.peek();
	}
	if (next == '!') {
		cin.get();
		return !factor_value();
	} else if (next == 'V') {
		cin.get();
		return true;
	} else if (next == 'F') {
		cin.get();
		return false;
	} else if (next == '(') {
		cin.get();
		bool result = expression_value();
		cin.get();
		return result;
	}
}