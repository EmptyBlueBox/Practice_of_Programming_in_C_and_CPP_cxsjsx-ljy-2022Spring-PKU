#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double ans() {
	string tmp;
	cin >> tmp;
	if (tmp == "+")
		return ans() + ans();
	else if (tmp == "-")
		return ans() - ans();
	else if (tmp == "*")
		return ans() * ans();
	else if (tmp == "/")
		return ans() / ans();
	else
		return atof(tmp.c_str());
}
int main() {
	cout << fixed << setprecision(6) << ans() << endl;
}