#include <iostream>
#include <algorithm>
using namespace std;
struct info {
	info(char c) {
		name = c;
	}
	//按饭量大小输出是先输出饭量小的，应该是题目描述不清楚
	bool operator<(info a) {
		return eat < a.eat;
	}
	char name;
	int eat, sayright = 0;
} a[3] = { 'A','B','C' };
int main() {
	for (a[0].eat = 1; a[0].eat <= 3; a[0].eat++) {
		for (a[1].eat = 1; a[1].eat <= 3; a[1].eat++) {
			for (a[2].eat = 1; a[2].eat <= 3; a[2].eat++) {
				if (a[0].eat == a[1].eat || a[1].eat == a[2].eat || a[0].eat == a[2].eat)//保证不重复
					continue;
				a[0].sayright = (a[1].eat > a[0].eat) + (a[2].eat == a[0].eat);
				a[1].sayright = (a[0].eat > a[1].eat) + (a[0].eat > a[2].eat);
				a[2].sayright = (a[2].eat > a[1].eat) + (a[1].eat > a[0].eat);
				for (int i = 0; i < 3; i++)
					if (a[i].eat + a[i].sayright != 3)//保证逆序
						goto loop;//continue不能跳到上上层循环
				sort(a, a + 3);//sort完会导致循环再次从头开始，直接return 0
				for (int i = 0; i < 3; i++)
					cout << a[i].name;
				return 0;
				loop:;
			}
		}
	}
}