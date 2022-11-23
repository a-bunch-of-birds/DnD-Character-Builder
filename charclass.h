#ifndef CHARCLASS_H
#define CHARCLASS_H
#include "abilityscore.h"
#include "species.h"

/*
0 == NONE
1 == Barbarian
2 == Bard
3 == Cleric
4 == Druid
5 == Fighter
6 == Monk
7 == Paladin
8 == Ranger
9 == Rogue
10 == Sorcerer
11 == Warlock
12 == Wizard

*/


class Charclass
{
private:
public:
	struct class_summary
	{
		int clss = 0;
		int hit_dice = 6;
		int hd_count = 1;
		int hit_points = 0;
		int exp = 0;
		int level = 1;
		int prof_bonus;
		std::vector<std::string> proficiencies{" "};
		bool lvlup_abscore = false;
		int spell_save_dc = 0;
		int spell_attk_mod = 0;
	};
	class_summary csumm;
	Charclass();
	~Charclass() {};
	void level_hd_hp(Abilityscore object);
	int hd_lvl_calc();
	void exp_lvlup(bool trigger);
	void prof_incr();
	int ab_upscore();
	void barbarian(Abilityscore object);
	void bard(Abilityscore object);
	void cleric(Abilityscore object);
	void druid(Abilityscore object);
	void fighter(Abilityscore object);
	void monk(Abilityscore object);
	void paladin(Abilityscore object);
	void ranger(Abilityscore object);
	void rogue(Abilityscore object);
	void sorcerer(Abilityscore object);
	void warlock(Abilityscore object);
	void wizard(Abilityscore object);


};

#endif CHARCLASS_H
