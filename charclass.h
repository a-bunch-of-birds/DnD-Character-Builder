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
	void exp_lvlup();
	void barbarian(Abilityscore& object);
	void bard();
	void cleric();
	void druid();
	void fighter();
	void monk();
	void paladin();
	void ranger();
	void rogue();
	void sorcerer();
	void warlock();
	void wizard();


};

#endif CHARCLASS_H
