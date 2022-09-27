#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>


class Character
{
private:
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

public:
	Character();
	~Character();
	void get_ability_scores();
};

#endif CHARACTER_H