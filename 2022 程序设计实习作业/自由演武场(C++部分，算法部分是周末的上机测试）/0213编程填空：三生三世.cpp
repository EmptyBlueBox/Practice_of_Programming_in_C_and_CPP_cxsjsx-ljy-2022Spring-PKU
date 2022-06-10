#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;

class TV_Drama {
	public:
		char name[100];
		int actor;
		int story;
		int acting_skill;
// 在此处补充你的代码
		TV_Drama(char* p,int a,int b,int c):actor(a),story(b),acting_skill(c) {
			int len=strlen(p);
			for(int i=0; i<len; i++)
				name[i]=p[i];
			name[len]='\0';
		}
		bool operator<(TV_Drama& a) {
			return actor>a.actor;
		}
};
bool comparator_1(TV_Drama a,TV_Drama b) {
	return a.story>b.story;
}
class comparator_2 {
	public:
		bool operator()(TV_Drama a,TV_Drama b) {
			return a.acting_skill>b.acting_skill;
		}
};
void Printer(TV_Drama a) {
	cout<<a.name<<';';
}
// 在此处补充你的代码
int main() {
	list<TV_Drama> lst;
	int n;

	cin>>n;
	char  _name[100];
	int _actor, _story, _acting_skill;
	for (int i=0; i<n; i++) {
		cin.ignore();
		cin.getline(_name,100);
		cin>>_actor>>_story>>_acting_skill;
		lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
	}

	lst.sort();
	for_each(lst.begin(), lst.end(), Printer);
	cout<<endl;

	lst.sort(comparator_1);
	for_each(lst.begin(), lst.end(), Printer);
	cout<<endl;

	lst.sort(comparator_2());
	for_each(lst.begin(), lst.end(), Printer);
	cout<<endl;

	return 0;
}