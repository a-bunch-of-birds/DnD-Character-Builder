#include "abilityscore.h"
#include "charclass.h"

Charclass::Charclass()
{
	csumm.hit_dice = 6;
	csumm.hd_count = 1;
	csumm.hit_points = 0;
	csumm.exp = 0;
	csumm.level = 1;
	csumm.prof_bonus = 2;
	csumm.proficiencies = { " " };
}

int Charclass::hd_lvl_calc()
{
	int min = 1;
	int max = csumm.hit_dice;
	int result = 0;
	result = rand() % max + min;
	return result;
}

void Charclass::level_hd_hp()
{
	
}

void Charclass::exp_lvlup(bool trigger)
{
	if (csumm.exp == 0 || csumm.level == 1)
	{
		csumm.exp = 0;
		csumm.level = 1;
		csumm.prof_bonus = 2;
	}
	else if (csumm.exp == 300 || csumm.level == 2)
	{
		csumm.level = 2;
		csumm.exp = 300;
	}
	else if (csumm.exp == 900 || csumm.level == 3)
	{
		csumm.level = 3;
		csumm.exp = 900;
	}
	else if (csumm.exp == 2700 || csumm.level == 4)
	{
		csumm.level = 4;
		csumm.exp = 2700;
	}
	else if (csumm.exp == 6500 || csumm.level == 5)
	{
		csumm.level = 5;
		csumm.exp = 6500;
		csumm.prof_bonus = 3;
	}
	else if (csumm.exp == 14000 || csumm.level == 6)
	{
		csumm.level = 6;
		csumm.exp = 14000;
	}
	else {}
}

void Charclass::barbarian(Abilityscore &object)
{
	csumm.hit_dice = 12;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.hit_points = object.ability_summary.conabm + 12;
	}
	//remember to later account for ability score increases to CON at lvls 4, 8, 12, 16, && 19
	else if (csumm.level > 1 && csumm.level < 4)
	{
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
	}
	else if (csumm.level == 4)
	{
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
	}
	else if (csumm.level == 8)
	{
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
	}
	else if (csumm.level == 12)
	{
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
	}
	else if (csumm.level == 16)
	{
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
	}
	else if (csumm.level == 19)
	{
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
	}
	else {}

}