#ifndef CHARCLASS_H
#define CHARCLASS_H
#include "abilityscore.h"
#include "species.h"

class Charclass
{
private:
public:
	struct class_summary
	{
		int hit_dice = 6;
		int hd_count = 1;
		int hit_points = 0;
		int exp = 0;
		int level = 1;
		int prof_bonus;
		std::vector<std::string> proficiencies{" "};
		bool lvlup_abscore = false;
	};
	class_summary csumm;
	Charclass();
	~Charclass() {};
	void level_hd_hp();
	int hd_lvl_calc();
	void exp_lvlup(bool trigger);
	void barbarian(Abilityscore& object);
	void bard(Abilityscore &object);
	void cleric(Abilityscore& object);
	void druid(Abilityscore& object);
	void fighter(Abilityscore& object);
	void monk(Abilityscore& object);
	void paladin(Abilityscore& object);
	void ranger(Abilityscore& object);
	void rogue(Abilityscore& object);
	void sorcerer(Abilityscore& object);
	void warlock(Abilityscore& object);
	void wizard(Abilityscore& object);


};

#endif CHARCLASS_H
