#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>


class Character
{
private:
	struct ability_summary
	{
		int str = 0;
		int dex = 0;
		int con = 0;
		int intl = 0;
		int wis = 0;
		int cha = 0;
		int strabm = 0;
		int dexabm = 0;
		int conabm = 0;
		int intlabm = 0;
		int wisabm = 0;
		int chaabm = 0;
	};
	ability_summary ability_summary;

	struct species_summary
	{
		std::string species = "";
		int age = 0;
		std::string alignment = "";
		std::string size = "";
		int speed = 0;
		bool darkvision = false;
		std::vector<std::string> tools{};
		std::vector<std::string> languages{};
	};
	species_summary species_summary;

	struct class_summary
	{
		int clss = 0;
		int hit_dice = 6;
		int hd_count = 1;
		int hit_points = 0;
		int exp = 0;
		int level = 1;
		int prof_bonus;
		std::vector<std::string> proficiencies{ " " };
		bool lvlup_abscore = false;
		int spell_save_dc = 0;
		int spell_attk_mod = 0;
	};
	class_summary csumm;
	
	/*
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
	int strengthmod;
	int dexteritymod;
	int constitutionmod;
	int intelligencemod;
	int wisdommod;
	int charismamod;
	
	int proficiencybonus;
	int age;
	std::string alignment;
	std::string size;
	std::string speed;
	std::vector<std::string> languages;
	*/

public:
	Character() {};
	~Character() {};
	virtual void commit_change() const = 0;

};

#endif CHARACTER_H