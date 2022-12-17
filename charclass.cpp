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

void Charclass::level_hd_hp(Abilityscore object)
{
	int hp_passoff = 0;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();

	for (int i = 2; i <= csumm.level; i++)
	{
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
	}
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


void Charclass::prof_incr()
{
	int lvl_stor = csumm.level;
	if (lvl_stor < 5)
	{
		csumm.prof_bonus = 2;
	}
	else if (lvl_stor > 4 && lvl_stor < 9)
	{
		csumm.prof_bonus = 3;
	}
	else if (lvl_stor > 8 && lvl_stor < 13)
	{
		csumm.prof_bonus = 4;
	}
	else if (lvl_stor > 12 && lvl_stor < 17)
	{
		csumm.prof_bonus = 5;
	}
	else if (lvl_stor > 16)
	{
		csumm.prof_bonus = 6;
	}
}

int Charclass::ab_upscore()
{
	int score_incr = 0; //score increment will collect how many ability points you can choose from to increase.  imgui will take care of denominations
	int lvl_stor = csumm.level;
	int clss_type = csumm.clss;
	//<><><><><><><>

	if (clss_type == 0)
	{
		std::cout << "WARNING: CLASS NOT CHOSEN" << std::endl;	
	}
	//fighter ability score increment
	else if (clss_type == 5)
	{
		for (int i = 1; i <= lvl_stor; i++)
		{
			if (i == 4 || i == 6 || i == 8 || i == 12 || i == 14 || i == 16 || i == 19)
			{
				score_incr += 2;
			}
			else {}
		}
	}
	//rogue ability score increment
	else if (clss_type == 9)
	{
		for (int i = 1; i <= lvl_stor; i++)
		{
			if (i == 4 || i == 8 || i == 10 || i == 12 || i == 16 || i == 19)
			{
				score_incr += 2;
			}
			else {}
		}
	}
	//if (clss_type == 1 || clss_type == 2 || clss_type == 3 || clss_type == 4 || clss_type == 6 || clss_type == 7 || clss_type == 8 || clss_type == 10 || clss_type == 11 || clss_type == 12)
	else 
	{
		for (int i = 1; i <= lvl_stor; i++)
		{
			if (i == 4 || i == 8 || i == 12 || i == 16 || i == 19)
			{
				score_incr += 2;
			}
			else {}
		}
	}

	return score_incr;

}

void Charclass::barbarian(Abilityscore object)
{
	csumm.hit_dice = 12;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 12;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 1; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::bard(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	int con_mod = object.ConAbm();
	//int con_mod = object.ability_summary.conabm;
	csumm.hit_points = con_mod + 8;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 2; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::cleric(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 8;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 3; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::druid(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 8;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 4; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::fighter(Abilityscore object)
{
	csumm.hit_dice = 10;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 10;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 5; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::monk(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 8;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 6; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::paladin(Abilityscore object)
{
	csumm.hit_dice = 10;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 10;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 7; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::ranger(Abilityscore object)
{
	csumm.hit_dice = 10;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 10;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 8; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::rogue(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 8;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 9; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::sorcerer(Abilityscore object)
{
	csumm.hit_dice = 6;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 6;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 10; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::warlock(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 8;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 11; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

void Charclass::wizard(Abilityscore object)
{
	csumm.hit_dice = 6;
	csumm.hd_count = 1;
	//int con_mod = object.ability_summary.conabm;
	int con_mod = object.ConAbm();
	csumm.hit_points = con_mod + 6;
	csumm.prof_bonus = 2;
	csumm.level = 1;
	csumm.exp = 0;
	csumm.clss = 12; //integer denotation of class in the csumm struct.  see charclass.h note at the top
}

/*
void Charclass::barbarian(Abilityscore object)
{
	csumm.hit_dice = 12;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.hit_points = con_mod + 12;
		csumm.prof_bonus = 2;
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
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
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
		csumm.prof_bonus = 3;
	}
	else if (csumm.level == 8)
	{
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
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
		csumm.prof_bonus = 4;
	}
	else if (csumm.level == 12)
	{
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
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
		csumm.prof_bonus = 5;
	}
	else if (csumm.level == 16)
	{
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
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
		csumm.prof_bonus = 6;
	}
	else if (csumm.level == 19)
	{
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
	}
	else {}

}

void Charclass::bard(Abilityscore object) //we don't need to pass by ref here cause we don't need to change anything in the Abilityscores class
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int cha_mod = object.ability_summary.chaabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2; //for the bard class, we need to immediately apply a prof_bonus to the struct so we can calculate spell save dc and attack mod below
		csumm.hit_points = con_mod + 12;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	//remember to later account for ability score increases to CON at lvls 4, 8, 12, 16, && 19
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else {}

}

void Charclass::cleric(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int wis_mod = object.ability_summary.wisabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2;
		csumm.hit_points = con_mod + 8;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++) //this ain't gonna work bro; hilariously high hit point calculations || or not.  unless we can load save files, this won't be an issue
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 20)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
	
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else {}

}

void Charclass::druid(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int wis_mod = object.ability_summary.wisabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2;
		csumm.hit_points = con_mod + 8;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++) //this ain't gonna work bro; hilariously high hit point calculations || or not.  unless we can load save files, this won't be an issue
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 20)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;

		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else {}
}

void Charclass::fighter(Abilityscore object)
{
	csumm.hit_dice = 10;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int wis_mod = object.ability_summary.wisabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2;
		csumm.hit_points = con_mod + 10;
		//the following will apply when we get to Eldritch Knight; needs to account for intelligence mods, not wisdom mods
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++) //this ain't gonna work bro; hilariously high hit point calculations || or not.  unless we can load save files, this won't be an issue
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 20)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;

		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else {}
}

void Charclass::monk(Abilityscore object)
{
	csumm.hit_dice = 10;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int cha_mod = object.ability_summary.chaabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2;
		csumm.hit_points = con_mod + 8;
		//the following will apply when we get to Eldritch Knight; needs to account for intelligence mods, not wisdom mods
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++) //this ain't gonna work bro; hilariously high hit point calculations || or not.  unless we can load save files, this won't be an issue
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 20)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;

		//csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		//csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else {}
}

void Charclass::paladin(Abilityscore object)
{
	csumm.hit_dice = 10;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int cha_mod = object.ability_summary.chaabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2;
		csumm.hit_points = con_mod + 10;
		
	}
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++) //this ain't gonna work bro; hilariously high hit point calculations || or not.  unless we can load save files, this won't be an issue
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else if (csumm.level == 20)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;

		csumm.spell_save_dc = (csumm.prof_bonus + cha_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + cha_mod;
	}
	else {}
}

void Charclass::ranger(Abilityscore object)
{
	csumm.hit_dice = 10;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int wis_mod = object.ability_summary.wisabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2;
		csumm.hit_points = con_mod + 10;

	}
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++) //this ain't gonna work bro; hilariously high hit point calculations || or not.  unless we can load save files, this won't be an issue
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else if (csumm.level == 20)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;

		csumm.spell_save_dc = (csumm.prof_bonus + wis_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + wis_mod;
	}
	else {}
}

void Charclass::rogue(Abilityscore object)
{
	csumm.hit_dice = 8;
	csumm.hd_count = 1;
	int hp_passoff = 0;
	int con_mod = object.ability_summary.conabm;
	int intl_mod = object.ability_summary.intlabm;
	//int prof_bonus = csumm.prof_bonus;
	int level_storage = 0;
	level_storage = csumm.level;
	if (csumm.level == 1)
	{
		csumm.prof_bonus = 2;
		csumm.hit_points = con_mod + 10;

	}
	else if (csumm.level > 1 && csumm.level < 4)
	{
		csumm.prof_bonus = 2;
		for (int i = 0; i < csumm.level; i++) //this ain't gonna work bro; hilariously high hit point calculations || or not.  unless we can load save files, this won't be an issue
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level == 4)
	{
		csumm.prof_bonus = 2;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to false as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level > 4 && csumm.level < 8)
	{
		csumm.prof_bonus = 3;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level == 8)
	{
		csumm.prof_bonus = 3;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level > 8 && csumm.level < 12)
	{
		csumm.prof_bonus = 4;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level == 12)
	{
		csumm.prof_bonus = 4;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level > 12 && csumm.level < 16)
	{
		csumm.prof_bonus = 5;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level == 16)
	{
		csumm.prof_bonus = 5;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level > 16 && csumm.level < 19)
	{
		csumm.prof_bonus = 6;
		for (int i = 0; i < csumm.level; i++)
		{
			hp_passoff = hd_lvl_calc();
			csumm.hit_points += hp_passoff;
			csumm.hit_points += con_mod;
		}
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level == 19)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;
		//this is a trigger, but we should return it to FALSE as soon as we complete the ability score improvement
		csumm.lvlup_abscore = true;
		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else if (csumm.level == 20)
	{
		csumm.prof_bonus = 6;
		hp_passoff = hd_lvl_calc();
		csumm.hit_points += hp_passoff;
		csumm.hit_points += con_mod;

		csumm.spell_save_dc = (csumm.prof_bonus + intl_mod) + 8;
		csumm.spell_attk_mod = csumm.prof_bonus + intl_mod;
	}
	else {}
}
*/
