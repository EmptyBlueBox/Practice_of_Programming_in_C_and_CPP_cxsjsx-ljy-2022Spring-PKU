#include <iostream>
using namespace std;

int main() {
	for (int a = 2; a <= 100; a++)
		for (int b = a; b <= 100; b++)
			for (int c = 2; c <= 100; c++)//都小于100，c不是小于等于100根号2
				if (a * a + b * b == c * c)
					printf("%d*%d + %d*%d = %d*%d\n", a, a, b, b, c, c);
}