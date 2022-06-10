#include <iostream>
using namespace std;
class Hero {
	public:
// 在此处补充你的代码
		void virtual defense() { //virtual虚函数，多态，指向的哪种类型就使用哪种类型的指针
			cout << "Hero::defense()" << endl;
		}
		void attack() {
			cout << "Hero::attack()" << endl;
		}
		// 在此处补充你的代码
};
class Priest: public Hero {
	public:
		virtual void attack() {
			cout << "Priest::attack()" << endl;
		}
		virtual void defense() {
			cout << "Priest::defense()" << endl;
		}
};

int main() {
	Priest anduin;
	Hero h;
	h.defense();
	Hero *player = &anduin;
	player->attack();
	player->defense();
	anduin.attack();
	anduin.defense();
	return 0;
}