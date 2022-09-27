#ifndef SPECIES_H
#define SPECIES_H

#include <iostream>
#include <vector>
#include <string>
#include "abilityscore.h"

class Species
{
private:
	//waiting on setting attributes to private until I know how I want to access it from ImGui
public:
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
	Species() {};
	~Species() {};
	void default_dwarf(Abilityscore &object);
	void hill_dwarf(Abilityscore &object);
	void mountain_dwarf(Abilityscore &object);
	void default_elf(Abilityscore& object);
	void high_elf(Abilityscore& object);
	void wood_elf(Abilityscore& object);
	void dark_elf(Abilityscore& object);
	void default_halfling(Abilityscore& object);
	void lightfoot_halfling(Abilityscore& object);
	void stout_halfling(Abilityscore& object);
	void human(Abilityscore& object);
	void dragonborn(Abilityscore& object);
	void default_gnome(Abilityscore& object);
	void forest_gnome(Abilityscore& object);
	void rock_gnome(Abilityscore& object);
	void default_halfelf(Abilityscore& object);
	void halfelf_plustwo(Abilityscore& object, char a, char b);
	void halforc(Abilityscore& object);
	void tiefling(Abilityscore& object);
};

#endif SPECIES_H