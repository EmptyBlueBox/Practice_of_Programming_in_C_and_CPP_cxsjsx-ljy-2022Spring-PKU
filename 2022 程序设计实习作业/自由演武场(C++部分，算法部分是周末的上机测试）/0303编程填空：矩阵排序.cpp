#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Mat {
		int h,w;
	public:
		Mat(int height,int width):h(height),w(width)
// 在此处补充你的代码
		{
			c=h*w;
			a=new int*[h];
			for(int i=0; i<h; i++) {
				a[i]=new int[w];
			}
			totalcnt++;
			no=totalcnt;
		}
		static int totalcnt;
		int c=0,s=0,no=0;
		int** a;
		bool operator<(Mat a) {
			if(c!=a.c)
				return c<a.c;
			else
				return no>a.no;
		}
		friend istream& operator>>(istream& is,Mat& m) {//变量要写引用否则读不进来
			for(int i=0; i<m.h; i++) {
				for(int j=0; j<m.w; j++) {
					is>>m.a[i][j];
					m.s+=m.a[i][j];
				}
			}
			return is;
		}
		friend ostream&operator<<(ostream& os,Mat m) {
			for(int i=0; i<m.h; i++) {
				for(int j=0; j<m.w; j++)
					os<<m.a[i][j]<<' ';
				os<<endl;
			}
			return os;
		}
};
int Mat::totalcnt=0;//初始化static也要写类型名：int
bool comparator_1(Mat a,Mat b) {
	if(a.s!=b.s)
		return a.s<b.s;
	else
		return a.no>b.no;
}
struct comparator_2 {
	bool operator()(Mat a,Mat b) {
		return a.no<b.no;
	}
};
// 在此处补充你的代码
int main() {
	vector<Mat> m;
	m.push_back(Mat(2,2));
	m.push_back(Mat(3,4));
	m.push_back(Mat(2,2));
	cin >> m[0] >> m[1] >> m[2];
	sort(m.begin(),m.end());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_1);
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	cout<<"*************"<<endl;
	sort(m.begin(),m.end(),comparator_2());
	cout<< m[0] << endl << m[1] << endl << m[2] <<endl;
	return 0;
}