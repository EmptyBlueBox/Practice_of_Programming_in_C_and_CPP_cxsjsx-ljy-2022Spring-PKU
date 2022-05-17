#include <iostream>
#include <algorithm>
using namespace std;

struct info {
	info(char c) {
		name = c;
	}
	char name;
	int weight = 10;
};
bool cmp(info a, info b) {
	return a.weight <= b.weight;
}
int main() {
	info a[4] = { 'z','q','s','l' };
	for (a[0].weight=10; a[0].weight <= 50; a[0].weight += 10) {
		for (a[1].weight=10; a[1].weight <= 50; a[1].weight += 10) { //多重循环不要省略写for (; a[1].weight <= 50; a[1].weight += 10)
			for (a[2].weight=10; a[2].weight <= 50; a[2].weight += 10) {
				for (a[3].weight=10; a[3].weight <= 50; a[3].weight += 10) {
					if (a[0].weight + a[1].weight == a[2].weight + a[3].weight && a[0].weight + a[3].weight > a[1].weight + a[2].weight && a[0].weight + a[2].weight < a[1].weight) {
						sort(a, a + 4, cmp);
						for (int i = 0; i < 4; i++)
							cout << a[i].name << ' ' << a[i].weight << endl;
						return 0;
					}
				}
			}
		}
	}
}