#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage {
		// 在此处补充你的代码
	public:
		int h, w, cnt = 0;
		int** p;//二维数组
		IntegralImage(int a, int b) :h(a), w(b) {
			p = new int* [h];//先new n个数组名！！！
			for (int i = 0; i < h; i++)
				p[i] = new int[w];
		}
		void operator()(int* n) {
			int tmp = 0;//每一行前几个的和
			for (int i = 0; i < w; i++) {
				tmp += n[i];
				p[cnt][i] = 0;
				if (cnt != 0)
					p[cnt][i] += p[cnt - 1][i];
				p[cnt][i] += tmp;
			}
			cnt++;
		}
		int* operator[](int i) {
			return p[i];
		}
		// 在此处补充你的代码
};
int main() {
	int H, W;
	cin >> H >> W;
	int ** image = new int*[H];
	for(int i=0; i<H; ++i) {
		image[i]=new int[W];
	}
	for(int i=0; i<H; ++i)
		for(int j=0; j<W; ++j)
			cin >> image[i][j];
	IntegralImage it(H,W);
	for_each(image, image+H, it);
	for(int i=0; i<H; ++i) {
		for(int j=0; j<W; ++j)
			cout<<it[i][j]<<" ";
		cout<<endl;
	}

}