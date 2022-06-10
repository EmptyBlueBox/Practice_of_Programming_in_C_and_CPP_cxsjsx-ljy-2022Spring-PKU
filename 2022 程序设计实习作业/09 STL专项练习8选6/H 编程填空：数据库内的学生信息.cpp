#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
// 在此处补充你的代码
template<class T1,class T2, class cmp = greater<T1>>//如何让模板也默认？在最开始default
class MyMultimap
{
public:
	typedef typename multimap<T1, T2, cmp>::iterator iterator;//在模板中写迭代器时，最好在前面加上 typename关键字，否则可能会编译错
	multimap<T1, T2, cmp>a;//含template的构造函数？已经实例化了，就1不用在构造函数中写T1、T2了
	MyMultimap() { a.clear(); }
	void insert(pair<T1, T2> p1) { a.insert(p1); }
	iterator find(T1 key) { return a.find(key); }
	iterator begin() { return a.begin(); }
	iterator end() { return a.end(); }
	//multiest不能以pairs[key]形式访问元素
	void Set(T1 key, T2 info)
	{
		iterator x = a.equal_range(key).first;
		iterator y = a.equal_range(key).second;
		while (x != y)
		{
			x->second = info;
			x++;
		}
	}
	void Set(T2 info, T1 key) 
	{
		iterator x = a.equal_range(key).first;
		iterator y = a.equal_range(key).second;
		while (x != y)
		{
			x->second = info;
			x++;
		}
	}
	void clear() { a.clear(); }
	//friend ostream& operator<<(ostream& os, pair<T1, T2> p)//为什么不能写在class MyMultimap内部？
	//{
	//	os << "(" << p.first << "," << p.second << ")";
	//	return os;
	//}
};
template<class T1,class T2>
ostream& operator<<(ostream& os, pair<T1, T2> p)//为什么不能写在class MyMultimap内部？
{
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
// 在此处补充你的代码
struct Student
{
	string name;
	int score;
};
template <class T>
void Print(T first, T last) {
	for (; first != last; ++first)
		cout << *first << ",";
	cout << endl;
}
int main()
{

	Student s[] = { {"Tom",80},{"Jack",70},
					{"Jone",90},{"Tom",70},{"Alice",100} };

	MyMultimap<string, int> mp;
	for (int i = 0; i < 5; ++i)
		mp.insert(make_pair(s[i].name, s[i].score));
	Print(mp.begin(), mp.end()); //按姓名从大到小输出

	mp.Set("Tom", 78); //把所有名为"Tom"的学生的成绩都设置为78
	Print(mp.begin(), mp.end());



	MyMultimap<int, string, less<int> > mp2;
	for (int i = 0; i < 5; ++i)
		mp2.insert(make_pair(s[i].score, s[i].name));

	Print(mp2.begin(), mp2.end()); //按成绩从小到大输出
	mp2.Set(70, "Error");          //把所有成绩为70的学生，名字都改为"Error"
	Print(mp2.begin(), mp2.end());
	cout << "******" << endl;

	mp.clear();

	string name;
	string cmd;
	int score;
	while (cin >> cmd) {
		if (cmd == "A") {
			cin >> name >> score;
			if (mp.find(name) != mp.end()) {
				cout << "erroe" << endl;
			}
			mp.insert(make_pair(name, score));
		}
		else if (cmd == "Q") {
			cin >> name;
			MyMultimap<string, int>::iterator p = mp.find(name);
			if (p != mp.end()) {
				cout << p->second << endl;
			}
			else {
				cout << "Not Found" << endl;
			}
		}
	}
	return 0;
}
