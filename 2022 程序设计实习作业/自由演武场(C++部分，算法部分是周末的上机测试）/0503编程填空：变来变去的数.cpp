#include <iostream>
using namespace std;

class myobject {
	public:
// 在此处补充你的代码
		static int counter;
		virtual void work() {
			switch(counter) {
				case 10:
					counter=6;
					break;
				case 6:
					counter=2;
					break;
				case 2:
					break;
				case 7:
					counter=3;
					break;
				case 3:
					break;
			}
			print_avaliable();
		}
		void print_avaliable() {
			cout<<counter<<' ';
		}
// 在此处补充你的代码
};

class producer : public myobject {
	public:
		virtual void work() {
			counter = counter + 5;
			print_avaliable();
		}
};
int myobject::counter = 0;

int main() {
	producer *pro = new producer();
	myobject *con = new myobject();
	pro->work();
	pro->work();
	cout << endl;
	con->work();
	con->work();
	con->work();
	cout << endl;
	pro->work();
	cout << endl;
	con->work();
	con->work();
	cout << endl;
}