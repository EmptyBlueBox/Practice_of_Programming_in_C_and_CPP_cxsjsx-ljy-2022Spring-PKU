#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
//ID都是指第几个战士,即战士编号
int City_Num, Arrow_Force, Lion_Fear, Max_Time;
string Warrior_Type_To_Name[5] = { "dragon","ninja","iceman","lion","wolf" };//Warrior_Type=0,1,2,3,4
string Weapon_Type_To_Name[3] = { "sword","bomb","arrow" };
int Warrior_Cost[5] = { 0 };
int Warrior_Force[5] = { 0 };
string City_Flag[30] = { "NULL" };
int City_RedAndBlue_Win_Continuously[2][30] = { {0} };
int City_HP[30] = { 0 };
int BHQ_Has_Red = 0;
int RHQ_Has_Blue = 0;
bool All_End = false;
int RB_Making_Order_To_Type[2][5] = { {2,3,4,1,0},{3,0,1,2,4} };
void Print_Time(int t) {
	printf("%03d:%02d ", t / 60, t % 60);
	return;
}
class City {
		int No;
	public:
		City(int n) :No(n) {};
};
//抢武器要改Weapon_Force;Iceman走路不改变Weapon_Force!!!
class Weapon {
	public:
		int Weapon_Type;
		int Weapon_Force;
		int Arrow_Status = 3;//剩余使用次数
		double Blunt_Proportion = 1;
		Weapon(int tmp_Weapon_Type, int tmp_Warrior_Type) :Weapon_Type(tmp_Weapon_Type) {
			switch (tmp_Weapon_Type) {
				case 0:
					Weapon_Force = int(Warrior_Force[tmp_Warrior_Type] * 2 / 10);
					break;
				case 1:
					Weapon_Force = 0x7f7f7f7f;
					break;
				case 2:
					Weapon_Force = Arrow_Force;
					break;
			}
		}
		void Sword_Get_Blunt() {
			if (Weapon_Type == 0)
				Weapon_Force = int(Weapon_Force * 8 / 10), Blunt_Proportion *= 0.8;
		}
		bool Weapon_Is_Useless() {
			return (Arrow_Status == 0) || (Weapon_Force == 0);
		}
		void Print_Info() {
			switch (Weapon_Type) {
				case 0:
					printf("sword(%d)", Weapon_Force);
					break;
				case 1:
					printf("bomb");
					break;
				case 2:
					printf("arrow(%d)", Arrow_Status);
					break;
			}
		}
};
class Warrior {
		int Type, ID;
	public:
		int Iceman_Force = Warrior_Force[2];
		int HP, Location = 0;
		bool Come_From_Former = false;
		vector<Weapon> weapon;
		Warrior(int tmp_Type, int tmp_ID, int tmp_HP) :Type(tmp_Type), ID(tmp_ID), HP(tmp_HP) {};
		int Get_Sword() {
			for (int i = 0; i < weapon.size(); i++)
				if (weapon[i].Weapon_Type == 0)
					return i;
			return -1;
		}
		int Get_Bomb() {
			for (int i = 0; i < weapon.size(); i++)
				if (weapon[i].Weapon_Type == 1)
					return i;
			return -1;
		}
		int Get_Arrow() {
			for (int i = 0; i < weapon.size(); i++)
				if (weapon[i].Weapon_Type == 2)
					return i;
			return -1;
		}
		int Get_Type() {
			return Type;
		}
		int Get_ID() {
			return ID;
		}
		virtual void Print_Morale(int T) {};
		virtual void Print_Loyalty(int T) {};
		virtual bool Run_Away(int T, string col) {
			return false;
		};
		virtual void Iceman_March_Influence() {};
		friend void Red_Shot(Warrior* red, Warrior* blue, int T) { //红打蓝
			if (red->Location == blue->Location - 1) {
				for (int i = 0; i < red->weapon.size(); i++) {
					if (red->weapon[i].Weapon_Type == 2) {
						red->weapon[i].Arrow_Status--;//发射！
						blue->Hurted(red->weapon[i].Weapon_Force);
						if (red->weapon[i].Weapon_Is_Useless())//用了立刻判断是否耐久掉没了
							red->weapon.erase(red->weapon.begin() + i);
						if (blue->HP <= 0) {
							Print_Time(T);
							printf("red %s %d shot and killed blue %s %d\n", Warrior_Type_To_Name[red->Get_Type()].c_str(), red->Get_ID(), Warrior_Type_To_Name[blue->Get_Type()].c_str(), blue->Get_ID());
							return;
						}
						Print_Time(T);
						printf("red %s %d shot\n", Warrior_Type_To_Name[red->Get_Type()].c_str(), red->Get_ID());
					}
				}
			}
		}
		friend void Blue_Shot(Warrior* red, Warrior* blue, int T) { //蓝打红
			if (red->Location == blue->Location - 1) {
				for (int i = 0; i < blue->weapon.size(); i++) {
					if (blue->weapon[i].Weapon_Type == 2) {
						blue->weapon[i].Arrow_Status--;//发射！
						red->Hurted(blue->weapon[i].Weapon_Force);
						if (blue->weapon[i].Weapon_Is_Useless())//用了立刻判断是否耐久掉没了
							blue->weapon.erase(blue->weapon.begin() + i);
						if (red->HP <= 0) {
							Print_Time(T);
							printf("blue %s %d shot and killed red %s %d\n", Warrior_Type_To_Name[blue->Get_Type()].c_str(), blue->Get_ID(), Warrior_Type_To_Name[red->Get_Type()].c_str(), red->Get_ID());
							return;
						}
						Print_Time(T);
						printf("blue %s %d shot\n", Warrior_Type_To_Name[blue->Get_Type()].c_str(), blue->Get_ID());
					}
				}
			}
		}
		bool Use_Bomb(Warrior enemy, int City, int T) {
			for (int i = 0; i < weapon.size(); i++) {
				if (weapon[i].Weapon_Type == 1) {

				}
			}
		}
		int My_Force() {
			if (Type != 2)
				return Warrior_Force[Type];
			else
				return Iceman_Force;
		}
		virtual void Hurted(int Force) {
			HP -= Force;
		}
		virtual void Attack(Warrior* p, int City, string My_Col, string Enemy_Col, int T, bool COUT) {
			if (p->HP <= 0)
				return;
			if (COUT) {
				Print_Time(T);
				printf("%s %s %d attacked %s %s %d in city %d with %d elements and force %d\n", My_Col.c_str(), Warrior_Type_To_Name[Type].c_str(), ID, Enemy_Col.c_str(), Warrior_Type_To_Name[p->Get_Type()].c_str(), p->Get_ID(), City, HP, My_Force());
			}
			int tmp = Get_Sword();
			if (tmp != -1) {
				p->Hurted(My_Force() + weapon[tmp].Weapon_Force);
				if (tmp != -1) { //如果有剑用完立刻变钝并判断是否丢弃
					weapon[tmp].Sword_Get_Blunt();
					if (weapon[tmp].Weapon_Is_Useless())
						weapon.erase(weapon.begin() + tmp);
				}
			} else
				p->Hurted(My_Force());
			if (p->HP <= 0) {
				if (COUT) {
					Print_Time(T);
					printf("%s %s %d was killed in city %d\n", Enemy_Col.c_str(), Warrior_Type_To_Name[p->Get_Type()].c_str(), p->Get_ID(), City);
				}
				return;
			}
			p->Fight_Back(this, City, Enemy_Col, My_Col, T, COUT);
			if (HP <= 0) {
				if (COUT) {
					Print_Time(T);
					printf("%s %s %d was killed in city %d\n", My_Col.c_str(), Warrior_Type_To_Name[Type].c_str(), ID, City);
				}
				return;
			}
		}
		virtual void Fight_Back(Warrior* p, int City, string My_Col, string Enemy_Col, int T, bool COUT) {
			if (Type == 1)
				return;
			int tmp = Get_Sword();
			if (tmp != -1)
				p->Hurted(int(My_Force() / 2) + weapon[tmp].Weapon_Force);
			else
				p->Hurted(int(My_Force() / 2));
			if (COUT) {
				Print_Time(T);
				printf("%s %s %d fought back against %s %s %d in city %d\n", My_Col.c_str(), Warrior_Type_To_Name[Type].c_str(), ID, Enemy_Col.c_str(), Warrior_Type_To_Name[p->Get_Type()].c_str(), p->Get_ID(), City);
			}
			if (tmp != -1) {
				weapon[tmp].Sword_Get_Blunt();
				if (weapon[tmp].Weapon_Is_Useless())
					weapon.erase(weapon.begin() + tmp);
			}
		}
		//欢呼、获取生命元（但是并不改变实际的HQ_HP）、升旗、忠诚度或被夺取生命元、缴获武器；并且这些均只管自己方的
		void After_War(Warrior* p, int City, int Attack_First, int My_Win_Status, string My_Col, string Enemy_Col, int T, int& tmp_HQ_HP_Plus, int My_Pre_HP) {
			if (My_Win_Status == 1)
				this->Dragon_Happy();
			else
				this->Dragon_Sad();
			if (My_Win_Status != -1 && Attack_First == 1)
				this->Dragon_Yell(T, My_Col, City);

			if (My_Win_Status == 1) {
				tmp_HQ_HP_Plus += City_HP[City];
				Print_Time(T);
				printf("%s %s %d earned %d elements for his headquarter\n", My_Col.c_str(), Warrior_Type_To_Name[Type].c_str(), ID, City_HP[City]);
				City_HP[City] = 0;
			}

			if (My_Win_Status == 1 && City_Flag[City] != My_Col) { //防止已经是自己的旗子还要插自己的旗子
				City_RedAndBlue_Win_Continuously[My_Col == "blue"][City]++;
				if (City_RedAndBlue_Win_Continuously[My_Col == "blue"][City] == 2) {
					City_Flag[City] = My_Col;
					City_RedAndBlue_Win_Continuously[My_Col == "blue"][City] = 0;
					Print_Time(T);
					printf("%s flag raised in city %d\n", My_Col.c_str(), City);
				}
			} else
				City_RedAndBlue_Win_Continuously[My_Col == "blue"][City] = 0;

			if (My_Win_Status != 1)
				Lion_Sad();
			if (My_Win_Status == -1)
				Lion_Be_Taken_HP(p, My_Pre_HP);

			if (My_Win_Status == 1)
				Wolf_Take_Weapon(p);
		}
		void Report_Weapon(int T, string col) {
			Print_Time(T);
			printf("%s %s %d has ", col.c_str(), Warrior_Type_To_Name[Type].c_str(), ID);
			if (weapon.empty()) {
				cout << "no weapon\n";
				return;
			}
			switch (weapon.size()) {
				case 1: {
					weapon[0].Print_Info(), cout << endl;
					break;
				}
				case 2: {
					if (weapon[0].Weapon_Type > weapon[1].Weapon_Type)
						weapon[0].Print_Info(), cout << ',', weapon[1].Print_Info(), cout << endl;
					else
						weapon[1].Print_Info(), cout << ',', weapon[0].Print_Info(), cout << endl;
					break;
				}
				case 3: {
					for(int i=2; i>=0; i--)
						for(int j=0; j<3; j++)
							if (weapon[j].Weapon_Type == i) {
								weapon[j].Print_Info();
								if (i != 0)
									cout << ',';
								else
									cout << endl;
							}
					break;
				}
			}
			return;
		}
		virtual void Dragon_Yell(int T, string col, int City) {};
		virtual void Dragon_Happy() {};
		virtual void Dragon_Sad() {};
		virtual void Lion_Sad() {};
		virtual void Lion_Be_Taken_HP(Warrior* p, int My_Pre_HP) {};
		virtual void Wolf_Take_Weapon(Warrior* p) {};
};
class Dragon :public Warrior {
		double Dragon_Morale;
	public:
		Dragon(int tmp_ID, int tmp_Left_HP) :Warrior(0, tmp_ID, Warrior_Cost[0]) {
			weapon.push_back(Weapon(tmp_ID % 3, 0));
			if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0)
				weapon.clear();
			Dragon_Morale = tmp_Left_HP * 1.0 / Warrior_Cost[0];
		}
		virtual void Print_Morale(int T) {
			printf("Its morale is %.2lf\n", Dragon_Morale);
		}
		virtual void Dragon_Happy() {
			Dragon_Morale += 0.2;
		}
		virtual void Dragon_Sad() {
			Dragon_Morale -= 0.2;
		}
		virtual void Dragon_Yell(int T, string col, int City) {
			if (Dragon_Morale > 0.8) {
				Print_Time(T);
				printf("%s dragon %d yelled in city %d\n", col.c_str(), Get_ID(), City);
			}
		}
};
class Ninja :public Warrior {
	public:
		Ninja(int tmp_ID, int tmp_Left_HP) :Warrior(1, tmp_ID, Warrior_Cost[1]) {
			weapon.push_back(Weapon(tmp_ID % 3, 1));
			if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0)
				weapon.clear();
			weapon.push_back(Weapon((tmp_ID + 1) % 3, 1));
			if(weapon.size()==2)
				if (weapon[1].Weapon_Type == 0 && weapon[1].Weapon_Force == 0)
					weapon.erase(weapon.begin() + 1);
			if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0)
				weapon.erase(weapon.begin());
		}
};
class Iceman :public Warrior {
		bool One_Pace = false;
	public:
		Iceman(int tmp_ID, int tmp_Left_HP) :Warrior(2, tmp_ID, Warrior_Cost[2]) {
			weapon.push_back(Weapon(tmp_ID % 3, 2));
			if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0)
				weapon.clear();
		}
		virtual void Iceman_March_Influence() {
			if (One_Pace) {
				One_Pace = false;
				HP -= 9;
				if (HP <= 0)
					HP = 1;
				Iceman_Force += 20;
			} else
				One_Pace = true;
		}
};
class Lion :public Warrior {
	public:
		int Loyalty;
		Lion(int tmp_ID, int tmp_Left_HP) :Warrior(3, tmp_ID, Warrior_Cost[3]) {
			Loyalty = tmp_Left_HP;
		}
		virtual void Print_Loyalty(int T) {
			printf("Its loyalty is %d\n", Loyalty);
		}
		virtual bool Run_Away(int T, string col) {
			if (Loyalty <= 0) {
				Print_Time(T), printf("%s lion %d ran away\n", col.c_str(), Get_ID());
				return true;
			}
			return false;
		}
		virtual void Lion_Sad() {
			Loyalty -= Lion_Fear;
		}
		virtual void Lion_Be_Taken_HP(Warrior* p, int My_Pre_HP) {
			p->HP += My_Pre_HP;
		}
};
class Wolf :public Warrior {
	public:
		Wolf(int tmp_ID, int tmp_Left_HP) :Warrior(4, tmp_ID, Warrior_Cost[4]) {};
		virtual void Wolf_Take_Weapon(Warrior* p) {
			if (Get_Sword() == -1)
				if (p->Get_Sword() != -1)
					weapon.push_back(p->weapon[p->Get_Sword()]);
			if (Get_Bomb() == -1)
				if (p->Get_Bomb() != -1)
					weapon.push_back(p->weapon[p->Get_Bomb()]);
			if (Get_Arrow() == -1)
				if (p->Get_Arrow() != -1)
					weapon.push_back(p->weapon[p->Get_Arrow()]);
		}
};
class HQ {
	private:
		int Making_Order_To_Type[5];
		int Total_Warrior[6] = { 0 };//Type=0,1,2,3,4,ID
		int What_Is_Next = 0;
		bool Is_Stopped = false;
		string col;
	public:
		int HQ_Hp;
		vector<Warrior*> warrior;//保证指向的还是原始的warrior类型
		HQ(int Hp, int* Sq, string col_) {
			HQ_Hp = Hp;
			for (int i = 0; i <= 4; i++)
				Making_Order_To_Type[i] = Sq[i];
			col = col_;
		}
		void Make_Warrior(int T) { //肯定能制造战士
			if (HQ_Hp >= Warrior_Cost[Making_Order_To_Type[What_Is_Next]]) {
				int tmp_type = Making_Order_To_Type[What_Is_Next];
				Total_Warrior[tmp_type]++;
				Total_Warrior[5]++;
				HQ_Hp -= Warrior_Cost[tmp_type];
				Print_Time(T);
				printf("%s %s %d born\n", col.c_str(), Warrior_Type_To_Name[tmp_type].c_str(), Total_Warrior[5]);
				switch (tmp_type) {
					case 0: {
						warrior.push_back(new Dragon(Total_Warrior[5], HQ_Hp));
						break;
					}
					case 1: {
						warrior.push_back(new Ninja(Total_Warrior[5], HQ_Hp));
						break;
					}
					case 2: {
						warrior.push_back(new Iceman(Total_Warrior[5], HQ_Hp));
						break;
					}
					case 3: {
						warrior.push_back(new Lion(Total_Warrior[5], HQ_Hp));
						break;
					}
					case 4: {
						warrior.push_back(new Wolf(Total_Warrior[5], HQ_Hp));
						break;
					}
				}
				if (col == "blue")
					warrior.back()->Location = City_Num + 1;
				warrior.back()->Print_Morale(T);//特判龙和狮子要多写一行
				warrior.back()->Print_Loyalty(T);//
				What_Is_Next++;
				What_Is_Next %= 5;
			}
		}
		void Order_Warrior_March(int T, int pos) { //pos是目的地
			if (col == "red") {
				for (int i = 0; i < warrior.size(); i++) {
					if (warrior[i]->Location == pos - 1) {
						if (warrior[i]->Come_From_Former == false) { //防止不停前进
							warrior[i]->Location++;
							warrior[i]->Come_From_Former = true;
							warrior[i]->Iceman_March_Influence();
							Print_Time(T);
							if (pos == City_Num + 1) {
								printf("red %s %d reached blue headquarter with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), warrior[i]->HP, warrior[i]->My_Force());
								BHQ_Has_Red++;
								if (BHQ_Has_Red == 2) {
									Print_Time(T);
									cout << "blue headquarter was taken\n";
									All_End = true;
								}
								return;
							}
							printf("red %s %d marched to city %d with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), pos, warrior[i]->HP, warrior[i]->My_Force());
						}
					}
				}
			} else {
				for (int i = 0; i < warrior.size(); i++) {
					if (warrior[i]->Location == pos + 1) {
						warrior[i]->Location--;
						warrior[i]->Iceman_March_Influence();
						Print_Time(T);
						if (pos == 0) {
							printf("blue %s %d reached red headquarter with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), warrior[i]->HP, warrior[i]->My_Force());
							RHQ_Has_Blue++;
							if (RHQ_Has_Blue == 2) {
								Print_Time(T);
								cout << "red headquarter was taken\n";
								All_End = true;
							}
							return;
						}
						printf("blue %s %d marched to city %d with %d elements and force %d\n", Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), pos, warrior[i]->HP, warrior[i]->My_Force());
					}
				}
			}
		}
		void Procure_HP(int n, int i, int T, string col) {
			if (n == 0)
				return;
			HQ_Hp += n;
			Print_Time(T);
			printf("%s %s %d earned %d elements for his headquarter\n", col.c_str(), Warrior_Type_To_Name[warrior[i]->Get_Type()].c_str(), warrior[i]->Get_ID(), n);

		}
		void Report_HP(int T) {
			Print_Time(T);
			printf("%d elements in %s headquarter\n", HQ_Hp, col.c_str());
			return;
		}
};
void We_Shall_Play_a_Game() {
	BHQ_Has_Red = 0;
	RHQ_Has_Blue = 0;
	All_End = false;
	memset(City_RedAndBlue_Win_Continuously, 0, sizeof(City_RedAndBlue_Win_Continuously));
	for (int i = 0; i < 30; i++)
		City_Flag[i] = "NULL";
	memset(City_HP, 0, sizeof(City_HP));
	int HQ_Hp;
	cin >> HQ_Hp >> City_Num >> Arrow_Force >> Lion_Fear >> Max_Time;
	for (int j = 0; j <= 4; j++)
		cin >> Warrior_Cost[j];
	for (int j = 0; j <= 4; j++)
		cin >> Warrior_Force[j];
	HQ RHQ(HQ_Hp, RB_Making_Order_To_Type[0], "red");
	HQ BHQ(HQ_Hp, RB_Making_Order_To_Type[1], "blue");
	for (int T = 0; T <= Max_Time; T++) {
		int MO = T % 60;
		switch (MO) {
			//互相关系嵌套二重循环，只是要求地理顺序则平行
			case 0: {
				RHQ.Make_Warrior(T);
				BHQ.Make_Warrior(T);
				break;
			}
			case 5: {
				for (int i = 0; i <= City_Num + 1; i++) {
					for (int j = 0; j < RHQ.warrior.size(); j++) {
						if (i == City_Num + 1)
							continue;
						if (RHQ.warrior[j]->Location == i)
							if (RHQ.warrior[j]->Run_Away(T, "red"))
								RHQ.warrior.erase(RHQ.warrior.begin() + j);//可以break稍微省时间
					}
					for (int j = 0; j < BHQ.warrior.size(); j++) {
						if (i == 0)
							continue;
						if (BHQ.warrior[j]->Location == i)
							if (BHQ.warrior[j]->Run_Away(T, "blue"))
								BHQ.warrior.erase(BHQ.warrior.begin() + j);
					}
				}
				break;
			}
			case 10: {
				for (int i = 0; i <= City_Num + 1; i++) {
					RHQ.Order_Warrior_March(T, i);
					BHQ.Order_Warrior_March(T, i);
				}
				for (int i = 0; i < RHQ.warrior.size(); i++)
					RHQ.warrior[i]->Come_From_Former = false;
				if (All_End)
					return;
				break;
			}
			case 20: {//产出生命元
				for (int i = 1; i <= City_Num; i++)
					City_HP[i] += 10;
				break;
			}
			case 30: {
				for (int i = 1; i <= City_Num; i++) {
					for (int i = 1; i <= City_Num; i++) {
						for (int j = 0; j < RHQ.warrior.size(); j++) {
							if (RHQ.warrior[j]->Location == i) {
								for (int k = 0; k < BHQ.warrior.size(); k++)
									if (BHQ.warrior[k]->Location == i)
										goto next_City;
								RHQ.Procure_HP(City_HP[i], j, T, "red");
								City_HP[i] = 0;
								goto next_City;
							}
						}
						for (int j = 0; j < BHQ.warrior.size(); j++) {
							if (BHQ.warrior[j]->Location == i) {
								for (int k = 0; k < RHQ.warrior.size(); k++)
									if (RHQ.warrior[k]->Location == i)
										goto next_City;
								BHQ.Procure_HP(City_HP[i], j, T, "blue");
								City_HP[i] = 0;
								goto next_City;
							}
						}
next_City:
						;
					}
				}
				break;
			}
			case 35: {
				for (int i = 1; i <= City_Num; i++) {
					for (int j = 0; j < RHQ.warrior.size(); j++)
						if (RHQ.warrior[j]->Location == i)
							for (int k = 0; k < BHQ.warrior.size(); k++)
								Red_Shot(RHQ.warrior[j], BHQ.warrior[k], T);
					for (int j = 0; j < BHQ.warrior.size(); j++)
						if (BHQ.warrior[j]->Location == i)
							for (int k = 0; k < RHQ.warrior.size(); k++)
								Blue_Shot(RHQ.warrior[k], BHQ.warrior[j], T);
				}
				//要是删了就不能进入赢
				//for (int j = 0; j < RHQ.warrior.size(); j++)
				//	if (RHQ.warrior[j]->HP <= 0)
				//		RHQ.warrior.erase(RHQ.warrior.begin() + j), j = min((int)RHQ.warrior.size() - 1, j);
				//for (int j = 0; j < BHQ.warrior.size(); j++)
				//	if (BHQ.warrior[j]->HP <= 0)
				//		BHQ.warrior.erase(BHQ.warrior.begin() + j), j = min((int)BHQ.warrior.size() - 1, j);
				break;
			}
			case 38: {
				//先判断是否有一方被射死,若都活着则看谁输，如果输的那方有炸弹则删除两个warrior
				for (int i = 1; i <= City_Num; i++) {
					for (int j = 0; j < RHQ.warrior.size(); j++) {
						for (int k = 0; k < BHQ.warrior.size(); k++) {
							if (RHQ.warrior[j]->Location == i && RHQ.warrior[j]->Location == BHQ.warrior[k]->Location) {
								Warrior tmpr = *RHQ.warrior[j], tmpb = *BHQ.warrior[k];
								if (RHQ.warrior[j]->HP > 0 && BHQ.warrior[k]->HP > 0) {
									if (City_Flag[i] == "red" || (City_Flag[i] == "NULL" && (i & 1)))
										tmpr.Attack(&tmpb, i, "red", "blue", T, false);
									else if (City_Flag[i] == "blue" || (City_Flag[i] == "NULL" && !(i & 1)))
										tmpb.Attack(&tmpr, i, "blue", "red", T, false);
									if ((tmpr.HP > 0 && tmpb.HP <= 0) && (tmpb.Get_Bomb() != -1)) { //b用炸弹
										RHQ.warrior.erase(RHQ.warrior.begin() + j), BHQ.warrior.erase(BHQ.warrior.begin() + k);
										j = min((int)RHQ.warrior.size() - 1, j);
										k = min((int)BHQ.warrior.size() - 1, k);
										Print_Time(T);
										printf("blue %s %d used a bomb and killed red %s %d\n", Warrior_Type_To_Name[tmpb.Get_Type()].c_str(), tmpb.Get_ID(), Warrior_Type_To_Name[tmpr.Get_Type()].c_str(), tmpr.Get_ID());
									} else if ((tmpr.HP <= 0 && tmpb.HP > 0) && (tmpr.Get_Bomb() != -1)) {
										RHQ.warrior.erase(RHQ.warrior.begin() + j), BHQ.warrior.erase(BHQ.warrior.begin() + k);
										j = min((int)RHQ.warrior.size() - 1, j);
										k = min((int)BHQ.warrior.size() - 1, k);
										Print_Time(T);
										printf("red %s %d used a bomb and killed blue %s %d\n", Warrior_Type_To_Name[tmpr.Get_Type()].c_str(), tmpr.Get_ID(), Warrior_Type_To_Name[tmpb.Get_Type()].c_str(), tmpb.Get_ID());
									}
									j = min((int)RHQ.warrior.size() - 1, j);
									j = max(0, j);
									k = min((int)BHQ.warrior.size() - 1, k);
									k = max(0, k);
									if (RHQ.warrior.size() == 0)
										break;
								}
							}
						}
					}
				}
				break;
			}
			case 40: {
				int tmp_RHQ_HP_Plus = 0, tmp_BHQ_HP_Plus = 0;
				bool Red_Win[30] = { false }, Blue_Win[30] = { false };
				for (int i = 1; i <= City_Num; i++) {
					for (int j = 0; j < RHQ.warrior.size(); j++) {
						for (int k = 0; k < BHQ.warrior.size(); k++) {
							if (RHQ.warrior[j]->Location == i && RHQ.warrior[j]->Location == BHQ.warrior[k]->Location) {
								int Win_Status = 0;//1是red赢
								int Attack_First = 0;//1是red先attack
								int tmp_RHP = RHQ.warrior[j]->HP, tmp_BHP = BHQ.warrior[k]->HP;
								tmp_RHP = max(0, tmp_RHP), tmp_BHP = max(0, tmp_BHP);//防止已经被射死的Lion用负PH影响活着的
								if (RHQ.warrior[j]->HP <= 0 && BHQ.warrior[k]->HP <= 0) { //被同时射死,但也算发生了一场战斗，特殊地，不改变旗帜，没有任何影响
									RHQ.warrior.erase(RHQ.warrior.begin() + j);
									BHQ.warrior.erase(BHQ.warrior.begin() + k);
									break;
								} else if (RHQ.warrior[j]->HP <= 0 && BHQ.warrior[k]->HP > 0) //blue射死red
									Win_Status = -1;
								else if (RHQ.warrior[j]->HP > 0 && BHQ.warrior[k]->HP <= 0)//red射死blue
									Win_Status = 1;
								else if (City_Flag[i] == "red" || (City_Flag[i] == "NULL" && (i & 1)))
									RHQ.warrior[j]->Attack(BHQ.warrior[k], i, "red", "blue", T, true);
								else if (City_Flag[i] == "blue" || (City_Flag[i] == "NULL" && !(i & 1)))
									BHQ.warrior[k]->Attack(RHQ.warrior[j], i, "blue", "red", T, true);

								if (City_Flag[i] == "red" || (City_Flag[i] == "NULL" && (i & 1)))//无论什么时候都应该为了龙yell判断应该是谁先attack
									Attack_First = 1;
								else
									Attack_First = -1;

								if (RHQ.warrior[j]->HP > 0 && BHQ.warrior[k]->HP <= 0)
									Win_Status = 1, Red_Win[i] = true;
								else if (RHQ.warrior[j]->HP <= 0 && BHQ.warrior[k]->HP > 0)
									Win_Status = -1, Blue_Win[i] = true;
								RHQ.warrior[j]->After_War(BHQ.warrior[k], i, Attack_First, Win_Status, "red", "blue", T, tmp_RHQ_HP_Plus, tmp_RHP);
								BHQ.warrior[k]->After_War(RHQ.warrior[j], i, -Attack_First, -Win_Status, "blue", "red", T, tmp_BHQ_HP_Plus, tmp_BHP);
								if (RHQ.warrior[j]->HP <= 0 && BHQ.warrior[k]->HP > 0)//red死
									RHQ.warrior.erase(RHQ.warrior.begin() + j);
								else if (RHQ.warrior[j]->HP > 0 && BHQ.warrior[k]->HP <= 0)//blue死
									BHQ.warrior.erase(BHQ.warrior.begin() + k);
								j = min((int)RHQ.warrior.size() - 1, j);
								j = max(0, j);
								k = min((int)BHQ.warrior.size() - 1, k);
								k = max(0, k);
								if (RHQ.warrior.size() == 0)
									break;
							}
						}
					}
				}
				for (int i = 1; i <= City_Num && RHQ.HQ_Hp >= 8; i++) {
					if (Red_Win[i]) {
						for (int j = 0; j < RHQ.warrior.size(); j++)
							if (RHQ.warrior[j]->Location == i)
								RHQ.warrior[j]->HP += 8, RHQ.HQ_Hp -= 8;
					}
				}
				for (int i = City_Num; i >= 1 && BHQ.HQ_Hp >= 8; i--) {
					if (Blue_Win[i]) {
						for (int j = 0; j < BHQ.warrior.size(); j++)
							if (BHQ.warrior[j]->Location == i)
								BHQ.warrior[j]->HP += 8, BHQ.HQ_Hp -= 8;
					}
				}
				RHQ.HQ_Hp += tmp_RHQ_HP_Plus;
				BHQ.HQ_Hp += tmp_BHQ_HP_Plus;
				for (int j = 0; j < RHQ.warrior.size(); j++)
					if (RHQ.warrior[j]->HP <= 0)
						RHQ.warrior.erase(RHQ.warrior.begin() + j), j = min((int)RHQ.warrior.size() - 1, j);
				for (int j = 0; j < BHQ.warrior.size(); j++)
					if (BHQ.warrior[j]->HP <= 0)
						BHQ.warrior.erase(BHQ.warrior.begin() + j), j = min((int)BHQ.warrior.size() - 1, j);
				break;
			}
			case 50: {
				RHQ.Report_HP(T);
				BHQ.Report_HP(T);
				break;
			}
			case 55: {
				for (int i = 1; i <= City_Num + 1; i++)
					for (int j = 0; j < RHQ.warrior.size(); j++)
						if (RHQ.warrior[j]->Location == i)
							RHQ.warrior[j]->Report_Weapon(T, "red");
				for (int i = 0; i <= City_Num; i++)
					for (int j = 0; j < BHQ.warrior.size(); j++)
						if (BHQ.warrior[j]->Location == i)
							BHQ.warrior[j]->Report_Weapon(T, "blue");
				break;
			}
		}
	}
	return;
}
int main() {
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cout << "Case " << i << ":" << endl;
		We_Shall_Play_a_Game();
	}
	return 0;
}