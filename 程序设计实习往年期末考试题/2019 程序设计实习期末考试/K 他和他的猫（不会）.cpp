#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int l,r,n,m,p,x,y,a[N],d[N],q[N],g[N],s[N],f[105][N];
signed main() {
	int T;
	cin>>T;
	while(T--) {
		for(int i=2; i<=n; i++) {
			scanf("%lld",&x);
			d[i]=d[i-1]+x;
		}
		for(int i=1; i<=m; i++) {
			scanf("%lld%lld",&x,&y);
			a[i]=y-d[x];
		}
		sort(a+1,a+m+1);
		for(int i=1; i<=m; i++)s[i]=s[i-1]+a[i];
		memset(f,0x3f,sizeof(f));
		f[0][0]=0;
		for(int i=1; i<=p; i++) { //枚举定值i
			for(int j=1; j<=m; j++)g[j]=f[i-1][j]+s[j]; //y轴
			l=r=1;
			q[1]=0;
			for(int j=1; j<=m; j++) {
				while(l<r&&(g[q[l+1]]-g[q[l]])<=a[j]*(q[l+1]-q[l]))l++;
				f[i][j]=min(f[i-1][j],g[q[l]]+a[j]*j-s[j]-a[j]*q[l]);
				if(g[j]>=0x3f3f3f3f3f3f3f3fll)continue;
				while(l<r&&(g[q[r]]-g[q[r-1]])*(j-q[r])>=
				        (g[j]-g[q[r]])*(q[r]-q[r-1]))r--;
				q[++r]=j;
			}
		}
		cout<<f[p][m]<<endl;
	}
}