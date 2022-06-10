#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
		//
		int age,id;
		char c,name[100];
		double avgscore,s1,s2,s3,s4;
	public:
		void input() {
			cin.getline(name,20,',');
			cin>>age>>c>>id>>c;
			cin>>s1>>c>>s2>>c>>s3>>c>>s4;
		}

		void calculate() {
			avgscore=(s1+s2+s3+s4)/4;
		}
		void output() {
			cout<<name<<','<<age<<','<<id<<','<<avgscore;
		}
		//
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}