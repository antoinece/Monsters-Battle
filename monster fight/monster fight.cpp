// monster fight.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "combat.h"

int main()
{
	rules();
	do {
		statsShow(orc1);
		statsShow(goblin1);
		statsShow(troll1);
		Monstre monstre, monstre2;
		chooseMonsters(monstre, monstre2);
		if (monstre.S > monstre2.S) {
			fight(monstre, monstre2);
		}else
		{
			fight(monstre2, monstre);
		}
	} while (Replay());
}