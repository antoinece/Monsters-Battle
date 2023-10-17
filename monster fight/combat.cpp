#include "combat.h"
#include <iostream>
#include <random>

Monstre orc1{ 90,90,7,5,4,0,orc };
Monstre goblin1{ 85, 85,8,2,10,0,goblin };
Monstre troll1{ 100,100,5,6,2,0,troll };
std::string raceString(Race race)
{
	switch (race) {
	case orc:
		return "orc";
	case goblin:
		return "goblin";
	case troll:
		return "troll";
	default:
		return "Unknown";
	}
}
void statsShow(Monstre monstre)
{
	std::cout << monstre.toString() << "\nHP : " << monstre.HP << "/" << monstre.HpMax << "\nAttack Damage : " << monstre.AD << "\nDefense Power : " << monstre.DP << "\nSpeed : " << monstre.S << "\n\n";
}
bool isMonsterDead(Monstre& monstre)
{
	if (monstre.HP < 1)
	{
		monstre.HP = 0;
		return true;
	}
	return false;
}
void attack(Monstre& monstre, Monstre& monstre2) {
	if (isMonsterDead(monstre) == false) {
		std::cout << monstre.toString() << " : attack\n\n";
		if (monstre.AD > monstre2.DP)
		{
			monstre2.HP = monstre2.HP - (monstre.AD - monstre2.DP);
		}
	}
}
void parry(Monstre& monstre)
{
	if (monstre.defTurn == -1)
	{
		std::cout << monstre.toString() << " : parry\n\n";
		monstre.DP = monstre.DP + 3;
		monstre.defTurn = 2;
	}
	else
	{
		std::cout << monstre.toString() << " : parry failed\n\n";
	}
}
void stopParry(Monstre& monstre)
{
	monstre.DP = monstre.DP - 3;
}
void heal(Monstre& monstre)
{
	std::cout << monstre.toString() << " : heal\n\n";
	if (isMonsterDead(monstre) == false) {
		monstre.HP = monstre.HP + (monstre.HP - monstre.HpMax) * 0.1;
	}
}
int randAction(Monstre& monstre)
{
	std::random_device rd;
	std::mt19937 e2(rd());
	do {
		std::uniform_int_distribution<int> rNomber(0, 10);
		if (rNomber(e2) <= 1)
		{
			heal(monstre);
			return Heal;
		}
		else if (rNomber(e2) >= 9)
		{
			parry(monstre);
			return Parry;
		}
		else
		{
			return Attack;
		}
	} while (true);
}
void rules()
{
	std::cout << "rules :\n- During one turn, you can either parry, attack, or heal\n- Parry increases your defense by 3 points for 2 turn\n- The heal restores 10% of your missing HP\n\ntype enter after reading the rules \n";
	std::cin.get();
	system("cls");
}
void fight(Monstre& monstre, Monstre& monstre2)
{
	int round = 0;
	do
	{
		system("cls");
		if (monstre.defTurn >= 0)
		{
			monstre.defTurn--;
		}
		if (monstre2.defTurn >= 0)
		{
			monstre2.defTurn--;
		}
		round++;
		std::cout << "\nround : " << round << "---------------------------------\n\n";
		if (randAction(monstre) == Attack)
		{
			attack(monstre, monstre2);
		}
		if (randAction(monstre2) == Attack)
		{
			attack(monstre2, monstre);
		}
		if (monstre.defTurn == 0) {
			stopParry(monstre);
		}
		if (monstre2.defTurn == 0) {
			stopParry(monstre2);
		}
		statsShow(monstre);
		statsShow(monstre2);
		std::cout << "\ntype enter to see the next round \n";
		std::cin.get();
	} while (!isMonsterDead(monstre) && !isMonsterDead(monstre2));
	system("cls");
	if (isMonsterDead(monstre))
	{
		std::cout << "\n" << monstre.toString() << " is dead\n\n";
	}
	if (isMonsterDead(monstre2))
	{
		std::cout << "\n" << monstre2.toString() << " is dead\n\n";
	}
	statsShow(monstre);
	statsShow(monstre2);
}
Monstre chooseMonsters()
{
	int choice;
	std::cout << "Choose a monsters (1 for the orc, 2 for the goblin, 3 for the troll): ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		return orc1;
	case 2:
		return goblin1;
	case 3:
		return troll1;
	default:
		std::cout << "invalid choice. Default monster orc will be used\n";
		return orc1;
	}
}
void chooseMonsters(Monstre &monstre, Monstre &monstre2)
{
	std::cout << "monster 1\n";
	monstre = chooseMonsters();
	std::cout << monstre.toString()<< "\n";

	std::cout << "\nmonster 2\n";
	monstre2 = chooseMonsters();
	std::cout << monstre.toString() << "\n";
}
bool Replay()
{
	char replay;
	std::cout << "Do you want to play again? (y/n)";
	std::cin >> replay;
	return replay == 'y';
}

