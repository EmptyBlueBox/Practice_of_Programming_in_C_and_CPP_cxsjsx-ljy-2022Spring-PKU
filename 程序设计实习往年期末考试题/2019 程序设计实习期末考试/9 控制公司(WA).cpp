#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[102][102];
int cnt[102];
int m;
bool f[102];
bool own[102];
void EMILY(int x) {
	if(f[x]==true)
		return ;
	f[x]=true;
	for(int i=m; i; i--) {
		cnt[i]+=a[x][i];
		if(cnt[i]>50) {
			own[i]=true;
			EMILY(i);
		}
	}
}
int main() {
	int i,j,k,u,v,w,n;
	for(scanf("%d",&n); n; n--) {
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		m=max(u,max(m,v));
	}
	for(i=1; i<=m; i++) {
		memset(f,false,sizeof(f));
		memset(own,false,sizeof(own));
		memset(cnt,0,sizeof(cnt));
		EMILY(i);
		for(j=1; j<=m; j++)
			if(own[j]==true&&i!=j)
				printf("%d %d\n",i,j);
	}
	return 0;
}
//WA
/*
#include <iostream>
using namespace std;

int n, p[101][101] = { {0} }, fa, son, h;
bool ctrl[101][101] = { {0} }, vis[101][101] = { {0} }, exist[101] = { 0 };
bool f(int x, int y) {
	if (vis[x][y]) return ctrl[x][y];
	vis[x][y] = true;
	int cnt = 0;
	for (int i = 1; i <= 100 && cnt <= 50; i++)
		if (exist[i] && (i != y) && p[i][y] && f(x, i))
			cnt += p[i][y];
	if (cnt > 50) {
		ctrl[x][y] =  true;
		return true;
	}
	return false;
}
int main() {
	cin >> n;
	for (int i = 1; i <= 100; i++)
		ctrl[i][i] = vis[i][i] = true;
	for (int i = 1; i <= n; i++) {
		cin >> fa >> son >> h, p[fa][son] = h, exist[fa] = exist[son] = true;
		if (h > 50) ctrl[fa][son] = vis[fa][son] = true;
	}
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (exist[i] && exist[j] && i != j && f(i, j))
				cout << i << ' ' << j << endl;
}
*/