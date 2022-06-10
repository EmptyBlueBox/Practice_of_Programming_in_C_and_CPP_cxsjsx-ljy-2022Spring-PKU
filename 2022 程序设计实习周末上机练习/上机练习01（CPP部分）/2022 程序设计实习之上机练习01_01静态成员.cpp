#include <iostream>
#include <vector>
using namespace std;

class A {
		static int count;
	public:
		A() {
			count++;
		}
		static int theNumberOfA() {
			return count;
		}
};

int A::count = 0;

int main() {
	vector<A> v;

	for(int i = 0; i < 3; i++) {
		{
			A a;
			v.push_back(a);
		}
		cout << A::theNumberOfA() << endl;
	}

	return 0;
}