#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
//ID都是指第几个战士,即战士编号
string Warrior_Type_To_Name[5] = { "dragon","ninja","iceman","lion","wolf" };//Type=0,1,2,3,4
string Weapon_Type_To_Name[3] = { "sword","bomb","arrow" };
int Warrior_Cost[5] = { 0 }, MIN_COST = 0x7f7f7f7f;
int RB_Making_Order_To_Type[2][5] = { {2,3,4,1,0},{3,0,1,2,4} };
class Warrior
{
	int Type, ID, HP;
public:
	Warrior(int tmp_Type, int tmp_ID, int tmp_HP) :Type(tmp_Type), ID(tmp_ID), HP(tmp_HP) {};
	int Get_Warrior_Type() { return Type; }
};
class Warrior_Dragon :public Warrior
{
	int Dragon_Weapon_Type;
	double Dragon_Morale;
public:
	Warrior_Dragon(int tmp_ID, int tmp_Left_HP) :Warrior(0, tmp_ID, Warrior_Cost[0])
	{
		Dragon_Weapon_Type = tmp_ID % 3;
		Dragon_Morale = tmp_Left_HP * 1.0 / Warrior_Cost[0];
	}
	void Print_Dragon_Info()
	{
		cout << "It has a " << Weapon_Type_To_Name[Dragon_Weapon_Type] << ",and it's morale is " << fixed << setprecision(2) << Dragon_Morale << endl;
		return;
	}
};
class Warrior_Ninja :public Warrior
{
	int Ninja_Weapon_Type_1, Ninja_Weapon_Type_2;
public:
	Warrior_Ninja(int tmp_ID, int tmp_Left_HP) :Warrior(1, tmp_ID, Warrior_Cost[1])
	{
		Ninja_Weapon_Type_1 = tmp_ID % 3;
		Ninja_Weapon_Type_2 = (tmp_ID + 1) % 3;
	}
	void Print_Ninja_Info()
	{
		cout << "It has a " << Weapon_Type_To_Name[Ninja_Weapon_Type_1] << " and a " << Weapon_Type_To_Name[Ninja_Weapon_Type_2] << endl;
		return;
	}
};
class Warrior_Iceman :public Warrior
{
	int Iceman_Weapon_Type;
public:
	Warrior_Iceman(int tmp_ID, int tmp_Left_HP) :Warrior(2, tmp_ID, Warrior_Cost[2])
	{
		Iceman_Weapon_Type = tmp_ID % 3;
	}
	void Print_Iceman_Info()
	{
		cout << "It has a " << Weapon_Type_To_Name[Iceman_Weapon_Type] << endl;
		return;
	}
};
class Warrior_Lion :public Warrior
{
	int Loyalty;
public:
	Warrior_Lion(int tmp_ID, int tmp_Left_HP) :Warrior(3, tmp_ID, Warrior_Cost[3])
	{
		Loyalty = tmp_Left_HP;
	}
	void Print_Lion_Info()
	{
		cout << "It's loyalty is " << Loyalty << endl;
		return;
	}
};
class Warrior_Wolf :public Warrior
{
public:
	Warrior_Wolf(int tmp_ID, int tmp_Left_HP) :Warrior(4, tmp_ID, Warrior_Cost[4])
	{
	}
};
class HQ 
{
private:
	int HQ_Hp, Making_Order_To_Type[5];
	int Total_Warrior[6] = { 0 };//Type=0,1,2,3,4,ID
	vector<Warrior_Dragon> dragon;
	vector<Warrior_Ninja> ninja;
	vector<Warrior_Iceman> iceman;
	vector<Warrior_Lion> lion;
	vector<Warrior_Wolf> wolf;
	int What_Is_Next = 0;
	bool Is_Stopped = false;
	string col;
public:
	HQ(int Hp, int* Sq, string col_)
	{
		HQ_Hp = Hp;
		for (int i = 0; i <= 4; i++)
			Making_Order_To_Type[i] = Sq[i];
		col = col_;
	}
	void Make_Warrior(int T)//肯定能制造战士
	{
		for (int i = What_Is_Next; i <= What_Is_Next + 4; i++)
		{
			int Generate_Now = i % 5;//该产生顺位第Generate_Now的战士
			if (HQ_Hp >= Warrior_Cost[Making_Order_To_Type[Generate_Now]])
			{
				int tmp_type = Making_Order_To_Type[Generate_Now];
				Total_Warrior[tmp_type]++;
				Total_Warrior[5]++;
				HQ_Hp -= Warrior_Cost[tmp_type];
				printf("%03d ", T);
				cout << col << " " << Warrior_Type_To_Name[tmp_type] << " " << Total_Warrior[5] << " " << "born with strength" << " " << Warrior_Cost[tmp_type];
				cout << "," << Total_Warrior[tmp_type] << " " << Warrior_Type_To_Name[tmp_type] << " in " << col << " headquarter" << endl;
				//make a warrior
				switch (tmp_type)
				{
				case 0:
				{
					dragon.push_back(Warrior_Dragon(Total_Warrior[5], HQ_Hp));
					dragon.back().Print_Dragon_Info();
					break;
				}
				case 1:
				{
					ninja.push_back(Warrior_Ninja(Total_Warrior[5], HQ_Hp));
					ninja.back().Print_Ninja_Info();
					break;
				}
				case 2:
				{
					iceman.push_back(Warrior_Iceman(Total_Warrior[5], HQ_Hp));
					iceman.back().Print_Iceman_Info();
					break;
				}
				case 3:
				{
					lion.push_back(Warrior_Lion(Total_Warrior[5], HQ_Hp));
					lion.back().Print_Lion_Info();
					break;
				}
				case 4:
				{
					wolf.push_back(Warrior_Wolf(Total_Warrior[5], HQ_Hp));
					break;
				}
				}
				//
				What_Is_Next = Generate_Now + 1;
				break;
			}
		}
	}
	bool Stopped(int T)
	{
		if (Is_Stopped)
			return true;
		if (HQ_Hp < MIN_COST)
		{
			if (!Is_Stopped)
			{
				printf("%03d ", T);
				cout << col << " headquarter stops making warriors" << endl;
				Is_Stopped = true;
			}
			return true;
		}
		else
			return false;
	}
};

int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++)
	{
		int HQ_Hp;
		cin >> HQ_Hp;
		MIN_COST = 0x7f7f7f7f;
		for (int j = 0; j <= 4; j++)
			cin >> Warrior_Cost[j], MIN_COST = min(MIN_COST, Warrior_Cost[j]);
		cout << "Case:" << i << endl;
		HQ RHQ(HQ_Hp, RB_Making_Order_To_Type[0], "red");
		HQ BHQ(HQ_Hp, RB_Making_Order_To_Type[1], "blue");
		int T = 0;
		while ((!RHQ.Stopped(T)) || (!BHQ.Stopped(T)))
		{
			if (!RHQ.Stopped(T))
				RHQ.Make_Warrior(T);
			if (!BHQ.Stopped(T))
				BHQ.Make_Warrior(T);
			T++;
		}
	}
	return 0;
}
