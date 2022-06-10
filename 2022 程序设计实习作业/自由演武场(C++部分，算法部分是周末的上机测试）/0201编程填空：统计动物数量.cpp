#include <iostream>
using namespace std;
// 在此处补充你的代码
class Animal {
	public:
		static int number;
		Animal() {
			number++;
		}
		virtual ~Animal() {
			number--;
		}
};
class Dog :public Animal {
	public:
		static int number;
		Dog() {
			number++;
		}
		~Dog() {
			number--;
		}
};
class Cat :public Animal {
	public:
		static int number;
		Cat() {
			number++;
		}
		~Cat() {
			number--;
		}
};
int Animal::number = 0;
int Cat::number = 0;
int Dog::number = 0;
// 在此处补充你的代码
void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}