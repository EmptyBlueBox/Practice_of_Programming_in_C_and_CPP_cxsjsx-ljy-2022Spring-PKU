#include <iostream>
using namespace std;
class Hero {
public:
    // 在此处补充你的代码
    void attack() { cout << "Hero::attack()" << endl; }
    virtual void defense() { cout << "Hero::defense()" << endl; }
    // 在此处补充你的代码
};
class Priest : public Hero {
public:
    virtual void attack() { cout << "Priest::attack()" << endl; }
    virtual void defense() { cout << "Priest::defense()" << endl; }
};

int main() {
    Priest anduin;
    Hero h;
    h.defense();
    Hero* player = &anduin;
    player->attack();
    player->defense();
    anduin.attack();
    anduin.defense();
    return 0;
}