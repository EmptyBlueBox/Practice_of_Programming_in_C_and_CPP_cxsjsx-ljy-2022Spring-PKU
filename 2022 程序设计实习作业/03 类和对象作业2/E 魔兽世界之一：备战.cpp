#include <iostream>
using namespace std;
string ID_To_Name[5] = { "dragon","ninja","iceman","lion","wolf" };//id=0,1,2,3,4
int Warrior_Cost[5] = { 0 }, MIN_COST = 0x7f7f7f7f;
int RB_Order_To_ID[2][5] = { {2,3,4,1,0},{3,0,1,2,4} };
class HQ{
private:
	int HQ_Hp, Order_To_ID[5];
	int Total_Warrior[5] = { 0 };//id=0,1,2,3,4,5
	int What_Is_Next = 0;//参数
	bool Is_Stopped = false;
	string col;
public:
	HQ(int Hp, int* Sq, string col_)
	{
		HQ_Hp = Hp;
		for (int i = 0; i <= 4; i++)
			Order_To_ID[i] = Sq[i];
		col = col_;
	}
	void Make_Warrior(int T)
	{
		for (int i = What_Is_Next; i <= What_Is_Next + 4; i++)
		{
			int tmp = i % 5;
			if (HQ_Hp >= Warrior_Cost[Order_To_ID[tmp]])
			{
				Total_Warrior[Order_To_ID[tmp]]++;
				HQ_Hp -= Warrior_Cost[Order_To_ID[tmp]];
				printf("%03d ", T);
				cout << col << " " << ID_To_Name[Order_To_ID[tmp]] << " " << T + 1<< " " << "born with strength" << " " << Warrior_Cost[Order_To_ID[tmp]];
				cout << "," << Total_Warrior[Order_To_ID[tmp]] << " " << ID_To_Name[Order_To_ID[tmp]] << " in " << col << " headquarter" << endl;
				What_Is_Next = i + 1;
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
		HQ RHQ(HQ_Hp, RB_Order_To_ID[0], "red");
		HQ BHQ(HQ_Hp, RB_Order_To_ID[1], "blue");
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
