#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
//ID都是指第几个战士,即战士编号
int City_Num, Lion_Fear, Max_Time;
string Warrior_Type_To_Name[5] = { "dragon","ninja","iceman","lion","wolf" };//Warrior_Type=0,1,2,3,4
string Weapon_Type_To_Name[3] = { "sword","bomb","arrow" };
int Warrior_Cost[5] = { 0 };
int Warrior_Force[5] = { 0 };
bool All_End = false;
int RB_Making_Order_To_Type[2][5] = { {2,3,4,1,0},{3,0,1,2,4} };
void Print_Time(int t)
{
	printf("%03d:%02d ", t / 60, t % 60);
	return;
}
class City
{
	int No;
public:
	City(int n) :No(n) {};
};
struct Weapon
{
	int Weapon_Type;
	int Arrow_Status;//剩余使用次数
	Weapon(int tmp_Weapon_Type, int x = 2) :Weapon_Type(tmp_Weapon_Type), Arrow_Status(x) {};
};
//夺取使用,没用过的在前
bool cmp1(Weapon a, Weapon b)
{
	if (a.Weapon_Type < b.Weapon_Type)
		return true;
	else if (a.Weapon_Type > b.Weapon_Type)
		return false;
	else
		return a.Arrow_Status > b.Arrow_Status;
}
//攻击使用，用过的再前
bool cmp2(Weapon a, Weapon b)
{
	if (a.Weapon_Type < b.Weapon_Type)
		return true;
	else if (a.Weapon_Type > b.Weapon_Type)
		return false;
	else
		return a.Arrow_Status < b.Arrow_Status;
}
bool Is_Sword(Weapon a)
{
	return a.Weapon_Type == 0;
}
bool Is_Bomb(Weapon a)
{
	return a.Weapon_Type == 1;
}
bool Is_Arrow(Weapon a)
{
	return a.Weapon_Type == 2;
}
class Warrior
{
	int Type, ID;
public:
	//需要修改的用public
	int HP, Location = 0;
	bool Come_From_Former = false;
	vector<Weapon> weapon;
	Warrior(int tmp_Type, int tmp_ID, int tmp_HP) :Type(tmp_Type), ID(tmp_ID), HP(tmp_HP) {};
	int Get_Type()
	{
		return Type;
	}
	int Get_ID()
	{
		return ID;
	}
	virtual bool Run_Away(int T, string col) { return false; };
	virtual void Attack(Warrior* p,int tmp_Weapon_Type, int& tmp_Arrow_Status) {};
	virtual void Hurted(int Force) {};
	void Report_Weapon(int T, string col)
	{
		Print_Time(T);
		printf("%s %s %d has %d sword %d bomb %d arrow and %d elements\n", col.c_str(), Warrior_Type_To_Name[Type].c_str(), ID, count_if(weapon.begin(), weapon.end(), Is_Sword), count_if(weapon.begin(), weapon.end(), Is_Bomb), count_if(weapon.begin(), weapon.end(), Is_Arrow), HP);
		return;
	}
	virtual int Force_Of_A_Weapon(int tmp_Weapon_Type) { return 0; };
	friend int Attack_End(Warrior* a, Warrior* b)//返回0即还在打，1死a，2死b，3死a、b，4平局
	{
		if (a->HP <= 0 && b->HP <= 0)//死一个或都死了
			return 3;
		else if (a->HP <= 0)
			return 1;
		else if (b->HP <= 0)
			return 2;
		else if (a->weapon.empty() && b->weapon.empty())//武器用完没死，平局
			return 4;
		else//存在bomb或arrow或者sword攻击力不为零则继续打
		{
			for (int i = 0; i < a->weapon.size(); i++)
				if (a->weapon[i].Weapon_Type != 0 || a->Force_Of_A_Weapon(a->weapon[i].Weapon_Type) != 0) 
					return 0;
			for (int i = 0; i < b->weapon.size(); i++)
				if (b->weapon[i].Weapon_Type != 0 || b->Force_Of_A_Weapon(b->weapon[i].Weapon_Type) != 0)
					return 0;
			return 4;
		}
	}
	friend int Mutual_Attack(Warrior* a, Warrior* b, int T, string a0, string b0, int City)
	{
		int i = 0, j = 0;
		while (!Attack_End(a, b))
		{
			if (a->weapon.size())
			{
				a->Attack(b, a->weapon[i].Weapon_Type, a->weapon[i].Arrow_Status);
				if (a->weapon[i].Arrow_Status == 0 || a->weapon[i].Weapon_Type == 1)
				{
					a->weapon.erase(a->weapon.begin() + i);
					i--;
				}
				i++;
				if (a->weapon.size())
					i %= a->weapon.size();
			}
			if (Attack_End(a, b))
				break;
			if (b->weapon.size())
			{
				b->Attack(a, b->weapon[j].Weapon_Type, b->weapon[j].Arrow_Status);
				if (b->weapon[j].Arrow_Status == 0 || b->weapon[j].Weapon_Type == 1)
				{
					b->weapon.erase(b->weapon.begin() + j);
					j--;
				}
				j++;
				if (b->weapon.size())
					j %= b->weapon.size();
			}
		}
		Print_Time(T);
		int tmp = Attack_End(a, b);
		switch (tmp)
		{
		case 1: {
			printf("%s %s %d killed %s %s %d in city %d remaining %d elements\n", b0.c_str(), Warrior_Type_To_Name[b->Get_Type()].c_str(),
				b->Get_ID(), a0.c_str(), Warrior_Type_To_Name[a->Get_Type()].c_str(), a->Get_ID(), City, b->HP);
			break;
		}
		case 2: {
			printf("%s %s %d killed %s %s %d in city %d remaining %d elements\n", a0.c_str(), Warrior_Type_To_Name[a->Get_Type()].c_str(),
				a->Get_ID(), b0.c_str(), Warrior_Type_To_Name[b->Get_Type()].c_str(), b->Get_ID(), City, a->HP);
			break;
		}
		case 3: {
			if (a0 == "red")
				printf("both red %s %d and blue %s %d died in city %d\n", Warrior_Type_To_Name[a->Get_Type()].c_str(), a->Get_ID(),
					Warrior_Type_To_Name[b->Get_Type()].c_str(), b->Get_ID(), City);
			else
				printf("both red %s %d and blue %s %d died in city %d\n", Warrior_Type_To_Name[b->Get_Type()].c_str(), b->Get_ID(),
					Warrior_Type_To_Name[a->Get_Type()].c_str(), a->Get_ID(), City);
			break;
		}
		case 4: {
			if (a0 == "red")
				printf("both red %s %d and blue %s %d were alive in city %d\n", Warrior_Type_To_Name[a->Get_Type()].c_str(), a->Get_ID(),
					Warrior_Type_To_Name[b->Get_Type()].c_str(), b->Get_ID(), City);
			else
				printf("both red %s %d and blue %s %d were alive in city %d\n", Warrior_Type_To_Name[b->Get_Type()].c_str(), b->Get_ID(),
					Warrior_Type_To_Name[a->Get_Type()].c_str(), a->Get_ID(), City);
			break;
		}
		}
		return tmp;
	}
	friend void Take_Trophy(Warrior* a, Warrior* b)
	{
		sort(b->weapon.begin(), b->weapon.end(), cmp1);
		while (a->weapon.size() <= 10 && b->weapon.size())
		{
			a->weapon.push_back(b->weapon[0]);
			b->weapon.erase(b->weapon.begin());
		}
	}	//a从b抢
	virtual void Yell(int T, string col, int City) {};
};
class Dragon :public Warrior
{
	double Dragon_Morale;
public:
	Dragon(int tmp_ID, int tmp_Left_HP) :Warrior(0, tmp_ID, Warrior_Cost[0])
	{
		weapon.push_back(Weapon(tmp_ID % 3));
		Dragon_Morale = tmp_Left_HP * 1.0 / Warrior_Cost[0];
	}
	virtual void Attack(Warrior* p, int tmp_Weapon_Type, int& tmp_Arrow_Status)
	{
		if (tmp_Weapon_Type == 0)
		{
			p->Hurted(int(Warrior_Force[0] * 2 / 10));
		}
		else if (tmp_Weapon_Type == 1)
		{
			p->Hurted(int(Warrior_Force[0] * 4 / 10));
			HP -= int(int(Warrior_Force[0] * 4 / 10) / 2);
		}
		else if (tmp_Weapon_Type == 2)
		{
			p->Hurted(int(Warrior_Force[0] * 3 / 10));
			tmp_Arrow_Status--;
		}
	}
	virtual void Hurted(int Force)
	{
		HP -= Force;
	}
	virtual int Force_Of_A_Weapon(int tmp_Weapon_Type)
	{
		if (tmp_Weapon_Type == 0)
		{
			return int(Warrior_Force[0] * 2 / 10);
		}
		else if (tmp_Weapon_Type == 1)
		{
			return int(Warrior_Force[0] * 4 / 10);
		}
		else if (tmp_Weapon_Type == 2)
		{
			return int(Warrior_Force[0] * 3 / 10);
		}
	}
	virtual void Yell(int T, string col, int City)
	{
		Print_Time(T);
		printf("%s dragon %d yelled in city %d\n", col.c_str(), Get_ID(), City);
	}
};
class Ninja :public Warrior
{
public:
	Ninja(int tmp_ID, int tmp_Left_HP) :Warrior(1, tmp_ID, Warrior_Cost[1])
	{
		weapon.push_back(Weapon(tmp_ID % 3));
		weapon.push_back(Weapon((tmp_ID + 1) % 3));
	}
	virtual void Attack(Warrior* p, int tmp_Weapon_Type, int& tmp_Arrow_Status)
	{
		if (tmp_Weapon_Type == 0)
		{
			p->Hurted(int(Warrior_Force[1] * 2 / 10));
		}
		else if (tmp_Weapon_Type == 1)
		{
			p->Hurted(int(Warrior_Force[1] * 4 / 10));
		}
		else if (tmp_Weapon_Type == 2)
		{
			p->Hurted(int(Warrior_Force[1] * 3 / 10));
			tmp_Arrow_Status--;
		}
	}
	virtual void Hurted(int Force)
	{
		HP -= Force;
	}
	virtual int Force_Of_A_Weapon(int tmp_Weapon_Type)
	{
		if (tmp_Weapon_Type == 0)
		{
			return int(Warrior_Force[1] * 2 / 10);
		}
		else if (tmp_Weapon_Type == 1)
		{
			return int(Warrior_Force[1] * 4 / 10);
		}
		else if (tmp_Weapon_Type == 2)
		{
			return int(Warrior_Force[1] * 3 / 10);
		}
	}
};
class Iceman :public Warrior
{
public:
	Iceman(int tmp_ID, int tmp_Left_HP) :Warrior(2, tmp_ID, Warrior_Cost[2])
	{
		weapon.push_back(Weapon(tmp_ID % 3));
	}
	virtual void Attack(Warrior* p, int tmp_Weapon_Type, int& tmp_Arrow_Status)
	{
		if (tmp_Weapon_Type == 0)
		{
			p->Hurted(int(Warrior_Force[2] * 2 / 10));
		}
		else if (tmp_Weapon_Type == 1)
		{
			p->Hurted(int(Warrior_Force[2] * 4 / 10));
			HP -= int(int(Warrior_Force[2] * 4 / 10) / 2);
		}
		else if (tmp_Weapon_Type == 2)
		{
			p->Hurted(int(Warrior_Force[2] * 3 / 10));
			tmp_Arrow_Status--;
		}
	}
	virtual void Hurted(int Force)
	{
		HP -= Force;
	}
	virtual int Force_Of_A_Weapon(int tmp_Weapon_Type)
	{
		if (tmp_Weapon_Type == 0)
		{
			return int(Warrior_Force[2] * 2 / 10);
		}
		else if (tmp_Weapon_Type == 1)
		{
			return int(Warrior_Force[2] * 4 / 10);
		}
		else if (tmp_Weapon_Type == 2)
		{
			return int(Warrior_Force[2] * 3 / 10);
		}
	}
};//如果HP=0是否还要输出前进？
class Lion :public Warrior
{
public:
	int Loyalty;
	Lion(int tmp_ID, int tmp_Left_HP) :Warrior(3, tmp_ID, Warrior_Cost[3])
	{
		Loyalty = tmp_Left_HP;
		weapon.push_back(Weapon(tmp_ID % 3));
	}
	virtual bool Run_Away(int T, string col)
	{
		if (Loyalty <= 0)
		{
			Print_Time(T), printf("%s lion %d ran away\n", col.c_str(), Get_ID());
			return true;
		}
		return false;
	}
	virtual void Attack(Warrior* p, int tmp_Weapon_Type, int& tmp_Arrow_Status)
	{
		if (tmp_Weapon_Type == 0)
		{
			p->Hurted(int(Warrior_Force[3] * 2 / 10));
		}
		else if (tmp_Weapon_Type == 1)
		{
			p->Hurted(int(Warrior_Force[3] * 4 / 10));
			HP -= int(int(Warrior_Force[3] * 4 / 10) / 2);
		}
		else if (tmp_Weapon_Type == 2)
		{
			p->Hurted(int(Warrior_Force[3] * 3 / 10));
			tmp_Arrow_Status--;
		}
	}
	virtual void Hurted(int Force)
	{
		HP -= Force;
	}
	virtual int Force_Of_A_Weapon(int tmp_Weapon_Type)
	{
		if (tmp_Weapon_Type == 0)
		{
			return int(Warrior_Force[3] * 2 / 10);
		}
		else if (tmp_Weapon_Type == 1)
		{
			return int(Warrior_Force[3] * 4 / 10);
		}
		else if (tmp_Weapon_Type == 2)
		{
			return int(Warrior_Force[3] * 3 / 10);
		}
	}
};
class Wolf :public Warrior
{
public:
	Wolf(int tmp_ID, int tmp_Left_HP) :Warrior(4, tmp_ID, Warrior_Cost[4]) {};
	void Grab_Weapon(Warrior* p, string Wolf_Col, string Another_Col, int T, int City)
	{
		sort(p->weapon.begin(), p->weapon.end(), cmp1);
		if (p->weapon.empty() || p->Get_Type() == 4)
			return;
		int Grab_Type = p->weapon[0].Weapon_Type;
		int cnt_Grab = 0;
		while (weapon.size()<=10 && !p->weapon.empty() && Grab_Type == p->weapon[0].Weapon_Type)
		{
			weapon.push_back(p->weapon[0]);
			p->weapon.erase(p->weapon.begin());
			cnt_Grab++;
		}
		Print_Time(T);
		printf("%s wolf %d took %d %s from %s %s %d in city %d\n", Wolf_Col.c_str(), Get_ID(), cnt_Grab, Weapon_Type_To_Name[Grab_Type].c_str(), Another_Col.c_str(), Warrior_Type_To_Name[p->Get_Type()].c_str(), p->Get_ID(), City);
		return;
	}
	virtual void Attack(Warrior* p, int tmp_Weapon_Type, int& tmp_Arrow_Status)
	{
		if (tmp_Weapon_Type == 0)
		{
			p->Hurted(int(Warrior_Force[4] * 2 / 10));
		}
		else if (tmp_Weapon_Type == 1)
		{
			p->Hurted(int(Warrior_Force[4] * 4 / 10));
			HP -= int(int(Warrior_Force[4] * 4 / 10) / 2);
		}
		else if (tmp_Weapon_Type == 2)
		{
			p->Hurted(int(Warrior_Force[4] * 3 / 10));
			tmp_Arrow_Status--;
		}
	}
	virtual void Hurted(int Force)
	{
		HP -= Force;
	}
	virtual int Force_Of_A_Weapon(int tmp_Weapon_Type)
	{
		if (tmp_Weapon_Type == 0)
		{
			return int(Warrior_Force[4] * 2 / 10);
		}
		else if (tmp_Weapon_Type == 1)
		{
			return int(Warrior_Force[4] * 4 / 10);
		}
		else if (tmp_Weapon_Type == 2)
		{
			return int(Warrior_Force[4] * 3 / 10);
		}
	}
};
class HQ
{
private:
	int HQ_Hp, Making_Order_To_Type[5];
	int Total_Warrior[6] = { 0 };//Type=0,1,2,3,4,ID
	int What_Is_Next = 0;
	bool Is_Stopped = false;
	string col;
public:
	vector<Warrior*> warrior;//保证指向的还是原始的warrior类型
	HQ(int Hp, int* Sq, string col_)
	{
		HQ_Hp = Hp;
		for (int i = 0; i <= 4; i++)
			Making_Order_To_Type[i] = Sq[i];
		col = col_;
	}
	void Make_Warrior(int T)//肯定能制造战士
	{
		int Generate_Now = What_Is_Next;//该产生顺位第Generate_Now的战士
		if (HQ_Hp >= Warrior_Cost[Making_Order_To_Type[Generate_Now]])
		{
			int tmp_type = Making_Order_To_Type[Generate_Now];
			Total_Warrior[tmp_type]++;
			Total_Warrior[5]++;
			HQ_Hp -= Warrior_Cost[tmp_type];
			Print_Time(T);
			cout << col << " " << Warrior_Type_To_Name[tmp_type] << " " << Total_Warrior[5] << " " << "born" << endl;
			switch (tmp_type)
			{
			case 0:
			{
				warrior.push_back(new Dragon(Total_Warrior[5], HQ_Hp));
				break;
			}
			case 1:
			{
				warrior.push_back(new Ninja(Total_Warrior[5], HQ_Hp));
				break;
			}
			case 2:
			{
				warrior.push_back(new Iceman(Total_Warrior[5], HQ_Hp));
				break;
			}
			case 3:
			{
				warrior.push_back(new Lion(Total_Warrior[5], HQ_Hp));
				break;
			}
			case 4:
			{
				warrior.push_back(new Wolf(Total_Warrior[5], HQ_Hp));
				break;
			}
			}
			if (col == "blue")
				warrior.back()->Location = City_Num + 1;
			//特判狮子要多写一行
			if (warrior.back()->Get_Type() == 3)
			{
				Lion* tmp_Lion = (Lion*)warrior.back();
				cout << "Its loyalty is " << tmp_Lion->Loyalty << endl;
			}
			//
			What_Is_Next = Generate_Now + 1;
			What_Is_Next %= 5;
		}
	}
	void Order_Warrior_March(int T, int pos)//pos是目的地 
	{
		if (col == "red")
		{
			for (int i = 0; i < warrior.size(); i++)
			{
				if (warrior[i]->Location == pos - 1)
				{
					if (warrior[i]->Come_From_Former == false)//防止不停前进
					{
						warrior[i]->Location++, warrior[i]->Come_From_Former = true;
						if (warrior[i]->Get_Type() == 2)
						{
							warrior[i]->HP -= (int)(warrior[i]->HP / 10);
						}
						else if (warrior[i]->Get_Type() == 3)
						{
							Lion* tmp_Lion = (Lion*)warrior[i];
							tmp_Lion->Loyalty -= Lion_Fear;
							//5分钟才跑
							/*if (tmp_Lion->Loyalty <= 0)
								tmp_Lion->Is_available = false;*/
						}
						Print_Time(T);
						if (pos == City_Num + 1)
						{
							printf("red %s %d reached blue headquarter with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), warrior[i]->HP, Warrior_Force[warrior[i]->Get_Type()]);
							Print_Time(T);
							cout << "blue headquarter was taken\n";
							All_End = true;
							return;
						}
						printf("red %s %d marched to city %d with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), pos, warrior[i]->HP, Warrior_Force[warrior[i]->Get_Type()]);
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < warrior.size(); i++)
			{
				if (warrior[i]->Location == pos + 1)
				{
					warrior[i]->Location--;
					if (warrior[i]->Get_Type() == 2)
					{
						warrior[i]->HP -= (int)(warrior[i]->HP / 10);
					}
					else if (warrior[i]->Get_Type() == 3)
					{
						Lion* tmp_Lion = (Lion*)warrior[i];
						tmp_Lion->Loyalty -= Lion_Fear;
					}					
					Print_Time(T);
					if (pos == 0)
					{
						printf("blue %s %d reached red headquarter with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), warrior[i]->HP, Warrior_Force[warrior[i]->Get_Type()]);
						Print_Time(T);
						cout << "red headquarter was taken\n";
						All_End = true;
						return;
					}
					printf("blue %s %d marched to city %d with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), pos, warrior[i]->HP, Warrior_Force[warrior[i]->Get_Type()]);
				}
			}
		}
	}
	void Report_HP(int T)
	{
		Print_Time(T);
		printf("%d elements in %s headquarter\n", HQ_Hp, col.c_str());
		return;
	}
};
void We_Shall_Play_a_Game()
{
	All_End = false;
	int HQ_Hp;
	cin >> HQ_Hp >> City_Num >> Lion_Fear >> Max_Time;
	for (int j = 0; j <= 4; j++)
		cin >> Warrior_Cost[j];
	for (int j = 0; j <= 4; j++)
		cin >> Warrior_Force[j];
	HQ RHQ(HQ_Hp, RB_Making_Order_To_Type[0], "red");
	HQ BHQ(HQ_Hp, RB_Making_Order_To_Type[1], "blue");

	for (int T = 0; T <= Max_Time; T++)
	{
		int MO = T % 60;
		switch (MO)
		{		//互相关系嵌套二重循环，只是要求地理顺序则平行
		case 0:{
			RHQ.Make_Warrior(T);
			BHQ.Make_Warrior(T);
			break;
		}
		case 5:{
			for (int i = 0; i <= City_Num + 1; i++)
			{
				for (int j = 0; j < RHQ.warrior.size(); j++)
				{
					if (i == City_Num + 1)
						continue;
					if (RHQ.warrior[j]->Location == i)
						if(RHQ.warrior[j]->Run_Away(T, "red"))
							RHQ.warrior.erase(RHQ.warrior.begin() + j);//可以break稍微省时间
				}
				for (int j = 0; j < BHQ.warrior.size(); j++)
				{
					if (i == 0)
						continue;
					if (BHQ.warrior[j]->Location == i)
						if(BHQ.warrior[j]->Run_Away(T, "blue"))
							BHQ.warrior.erase(BHQ.warrior.begin() + j);
				}
			}
		break;
		}
		case 10:{
			for (int i = 0; i <= City_Num + 1; i++)
			{
				RHQ.Order_Warrior_March(T, i);
				BHQ.Order_Warrior_March(T, i);
			}
			for (int i = 0; i < RHQ.warrior.size(); i++)
				RHQ.warrior[i]->Come_From_Former = false;
			if (All_End)
				return;
			break;
		}
		case 35:{
			for (int i = 1; i <= City_Num; i++)
			{
				for (int j = 0; j < RHQ.warrior.size(); j++)
				{
					for (int k = 0; k < BHQ.warrior.size(); k++)
					{
						if (RHQ.warrior[j]->Location == i && RHQ.warrior[j]->Location == BHQ.warrior[k]->Location)
						{
							if (RHQ.warrior[j]->Get_Type() == 4)
							{
								Wolf* tmp_Wolf = (Wolf*)RHQ.warrior[j];
								tmp_Wolf->Grab_Weapon(BHQ.warrior[k], "red", "blue", T, i);
							}
							else if (BHQ.warrior[k]->Get_Type() == 4)
							{
								Wolf* tmp_Wolf = (Wolf*)BHQ.warrior[k];
								tmp_Wolf->Grab_Weapon(RHQ.warrior[j], "blue", "red", T, i);
							}
						}
					}
				}
			}
			break;
		}
		case 40:{
			for (int i = 1; i <= City_Num; i++)
			{
				for (int j = 0; j < RHQ.warrior.size(); j++)
				{
					for (int k = 0; k < BHQ.warrior.size(); k++)
					{
						if (RHQ.warrior[j]->Location == i && RHQ.warrior[j]->Location == BHQ.warrior[k]->Location)
						{
							sort(RHQ.warrior[j]->weapon.begin(), RHQ.warrior[j]->weapon.end(), cmp2);
							sort(BHQ.warrior[k]->weapon.begin(), BHQ.warrior[k]->weapon.end(), cmp2);
							if (i & 1)//奇数城市
							{
								int tmp = Mutual_Attack(RHQ.warrior[j], BHQ.warrior[k], T, "red", "blue", i);
								switch (tmp)
								{
								case 1: {Take_Trophy(BHQ.warrior[k], RHQ.warrior[j]); RHQ.warrior.erase(RHQ.warrior.begin() + j); BHQ.warrior[k]->Yell(T, "blue", i); break; }
								case 2: {Take_Trophy(RHQ.warrior[j], BHQ.warrior[k]); BHQ.warrior.erase(BHQ.warrior.begin() + k); RHQ.warrior[j]->Yell(T, "red", i); break; }
								case 3: {RHQ.warrior.erase(RHQ.warrior.begin() + j), BHQ.warrior.erase(BHQ.warrior.begin() + k); break; }
								case 4: {RHQ.warrior[j]->Yell(T, "red", i); BHQ.warrior[k]->Yell(T, "blue", i); break; }
								}
							}
							else
							{
								int tmp = Mutual_Attack(BHQ.warrior[k], RHQ.warrior[j], T, "blue", "red", i);
								switch (tmp)
								{
								case 1: {Take_Trophy(RHQ.warrior[j], BHQ.warrior[k]); BHQ.warrior.erase(BHQ.warrior.begin() + k); RHQ.warrior[j]->Yell(T, "red", i); break; }
								case 2: {Take_Trophy(BHQ.warrior[k], RHQ.warrior[j]); RHQ.warrior.erase(RHQ.warrior.begin() + j); BHQ.warrior[k]->Yell(T, "blue", i); break; }
								case 3: {RHQ.warrior.erase(RHQ.warrior.begin() + j), BHQ.warrior.erase(BHQ.warrior.begin() + k); break; }
								case 4: {RHQ.warrior[j]->Yell(T, "red", i); BHQ.warrior[k]->Yell(T, "blue", i); break; }
								}
							}
						}
					}
				}
			}
			break;
		}
		case 50:{
			RHQ.Report_HP(T);
			BHQ.Report_HP(T);
			break;
		}
		case 55:{
			for (int i = 1; i <= City_Num; i++)
			{
				for (int j = 0; j < RHQ.warrior.size(); j++)
				{
					if (RHQ.warrior[j]->Location == i)
					{
						RHQ.warrior[j]->Report_Weapon(T, "red");
					}
				}
				for (int j = 0; j < BHQ.warrior.size(); j++)
				{
					if (BHQ.warrior[j]->Location == i)
					{
						BHQ.warrior[j]->Report_Weapon(T, "blue");
					}
				}
			}
			break;
		}
		}
	}
	return;
}
int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++)
	{
		cout << "Case " << i << ":" << endl;
		We_Shall_Play_a_Game();
	}
	return 0;
}
