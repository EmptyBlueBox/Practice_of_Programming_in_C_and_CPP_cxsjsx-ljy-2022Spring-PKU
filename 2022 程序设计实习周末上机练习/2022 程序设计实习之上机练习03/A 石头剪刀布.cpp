#include <iostream>
using namespace std;
int win(int a,int b) {
	if(a==b)
		return 0;
	else if(a==0&&b==2)return 1;
	else if(a==0&&b==5)return -1;
	else if(a==2&&b==0)return -1;
	else if(a==2&&b==5)return 1;
	else if(a==5&&b==0)return 1;
	else if(a==5&&b==2)return -1;
}
int main() {
	int n,la,lb,na[100],nb[100],awin=0;
	cin>>n>>la>>lb;
	for(int i=0; i<la; i++)
		cin>>na[i];
	for(int i=0; i<lb; i++)
		cin>>nb[i];
	for(int i=0; i<n; i++)
		awin+=win(na[i%la],nb[i%lb]);
	if(awin>0)
		cout<<"A"<<endl;
	else if(awin<0)
		cout<<"B"<<endl;
	else
		cout<<"draw"<<endl;
}