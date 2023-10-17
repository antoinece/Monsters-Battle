#pragma once
#include <string>

enum Action
{
	Attack,
	Parry,
	Heal,
};
enum Race
{
	orc,
	goblin,
	troll,
};
std::string raceString(Race race);
struct Monstre
{
	int HpMax;
	int HP;
	int AD;
	int DP;
	int S;
	int defTurn;
	Race race;
	std::string toString()
	{
		return raceString(race);
	}
};
extern Monstre orc1;
extern Monstre goblin1;
extern Monstre troll1;
void statsShow(Monstre monstre);
bool isMonsterDead(Monstre& monstre);
void attack(Monstre& monstre, Monstre& monstre2);
void parry(Monstre& monstre);
void stopParry(Monstre& monstre);
void heal(Monstre& monstre);
int randAction(Monstre& monstre);
void rules();
void fight(Monstre& monstre, Monstre& monstre2);
Monstre chooseMonsters();
void chooseMonsters(Monstre& monstre1, Monstre& monstre2);
bool Replay();
