#include <iostream>
#include <vector>
using namespace std;
int d,n,m,tmp;
vector<int> stone;
bool ok(int ans) {
	int cnt=0;
	for(int i=0; i<=n+1; i++) {
		for(int j=i+1; j<=n+1; j++) {
			if(stone[j]-stone[i]<ans)
				cnt++;
			else {
				i=j-1;//贪心？
				break;
			}
			if(j==n+1) {
				i=n+1;
				break;
			}
		}
	}
	return cnt<=m;
}
int main() {
	cin>>d>>n>>m;
	stone.resize(n+2);//可以这样使用vector可变长的特性
	stone[0]=0,stone[n+1]=d;
	for(int i=1; i<=n; i++)
		cin>>stone[i];
//1.l与r初始化为不可能取到的值，防止所有的都是蓝色
//2.程序保证ans不会越界，ans最大比r初始化小1，ans最小比l初始化大1
//3.更新指针不要写ans+-1
//4.这个程序保证不会死循环
	int l=0,r=d+1,ans;//ans是最短跳跃距离,现要让其最大
	while(l+1!=r) {
		ans=(l+r)/2;
		if(ok(ans))
			l=ans;//更新指针不要写ans+-1
		else
			r=ans;
	}
	cout<<l;
}