#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

multiset<int> s;
int a[5000 + 5];

int main() {
	int n, T, k;
	scanf("%d", &T);
	while (T--) {
		s.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%d", a + i);
			s.insert(a[i]);
		}
		bool flag = false;
		scanf("%d", &k);
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				int target = k - a[i] - a[j], min_count = 1;
// 在此处补充你的代码
				if(target==a[i])
					min_count++;
				if(target==a[j])
					min_count++;
				if(s.find(target)!=s.end()&&s.count(target)>=min_count)
					flag=true;
// 在此处补充你的代码
			}
			if (flag) break;
		}
		puts(flag? "Yes": "No");
	}
}