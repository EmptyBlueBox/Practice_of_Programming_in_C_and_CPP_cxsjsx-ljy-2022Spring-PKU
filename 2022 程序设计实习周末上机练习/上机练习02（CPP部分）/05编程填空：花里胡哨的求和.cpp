#include<iostream>
#include<vector>
using namespace std;
class A {
		// 在此处补充你的代码
	public:
		static int presum;
		int n;
		A(int _n) :n(_n) {
			n += presum, presum = n;
		}
		void output() {
			cout << n << endl;
		}
		// 在此处补充你的代码
};
int A::presum=0;
int main() {
	int n;
	cin>>n;
	vector<A*> p;
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
		p.push_back(new A(x));
	}
	for(int i=0; i<n; i++) {
		p[i]->output();
	}
	return 0;
}