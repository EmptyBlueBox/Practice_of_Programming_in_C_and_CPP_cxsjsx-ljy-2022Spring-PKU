#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x) {
	return pow(x,5)-15*pow(x,4)+85*pow(x,3)-225*pow(x,2)+274*x-121;
}
int main() {
	double eps=1e-7;
	double l=1.5,r=2.4,m=(l+r)/2;
	//cout<<f(1.5)<<' '<<f(2.4)<<endl; + -
	while(r-l>eps) {
		m=(l+r)/2;
		if(f(m)>0)
			l=m;
		else
			r=m;
	}
	cout<<fixed<<setprecision(6)<<m<<endl;
}