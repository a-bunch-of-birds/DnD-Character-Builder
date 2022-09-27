#include "species.h"
#include "abilityscore.h"

void Species::default_dwarf(Abilityscore &object)
{
	object.ability_summary.con += 2;  //CON score +2
	object.ability_summary.conabm = object.ability_modifier(object.ability_summary.con); //ensure to live update the ability modifiers
}

void Species::hill_dwarf(Abilityscore &object)
{
	//default_dwarf(object);
	object.ability_summary.wis += 1;  //WIS score +1
	object.ability_summary.wisabm = object.ability_modifier(object.ability_summary.wis); //ensure to live update the ability modifiers
}

void Species::mountain_dwarf(Abilityscore &object)
{
	//default_dwarf(object);
	object.ability_summary.str += 2; //STR score +2
	object.ability_summary.strabm = object.ability_modifier(object.ability_summary.str); //ensure to live update the ability modifiers
}

void Species::default_elf(Abilityscore &object)
{
	object.ability_summary.dex += 2;
	object.ability_summary.dexabm = object.ability_modifier(object.ability_summary.dex);
}

void Species::high_elf(Abilityscore &object)
{ 
	object.ability_summary.intl += 1;
	object.ability_summary.intlabm = object.ability_modifier(object.ability_summary.intl);
}

void Species::wood_elf(Abilityscore &object)
{
	object.ability_summary.wis += 1;
	object.ability_summary.wisabm = object.ability_modifier(object.ability_summary.wis);
}

void Species::dark_elf(Abilityscore &object)
{
	object.ability_summary.cha += 1;
	object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);
}

void Species::default_halfling(Abilityscore& object)
{
	object.ability_summary.dex += 2;
	object.ability_summary.dexabm = object.ability_modifier(object.ability_summary.dex);
}

void Species::lightfoot_halfling(Abilityscore& object)
{
	object.ability_summary.cha += 1;
	object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);
}

void Species::stout_halfling(Abilityscore& object)
{
	object.ability_summary.con += 1;
	object.ability_summary.conabm = object.ability_modifier(object.ability_summary.con);
}

void Species::human(Abilityscore& object)
{
	object.ability_summary.str += 1;
	object.ability_summary.dex += 1;
	object.ability_summary.con += 1;
	object.ability_summary.intl += 1;
	object.ability_summary.wis += 1;
	object.ability_summary.cha += 1;

	object.ability_summary.strabm = object.ability_modifier(object.ability_summary.str);
	object.ability_summary.dexabm = object.ability_modifier(object.ability_summary.dex);
	object.ability_summary.conabm = object.ability_modifier(object.ability_summary.con);
	object.ability_summary.intlabm = object.ability_modifier(object.ability_summary.intl);
	object.ability_summary.wisabm = object.ability_modifier(object.ability_summary.wis);
	object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);
}

void Species::dragonborn(Abilityscore& object)
{
	object.ability_summary.str += 2;
	object.ability_summary.cha += 1;

	object.ability_summary.strabm = object.ability_modifier(object.ability_summary.str);
	object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);

}

void Species::default_gnome(Abilityscore& object)
{
	object.ability_summary.intl += 2;

	object.ability_summary.intlabm = object.ability_modifier(object.ability_summary.intl);
}

void Species::forest_gnome(Abilityscore& object)
{
	object.ability_summary.dex += 1;

	object.ability_summary.dexabm = object.ability_modifier(object.ability_summary.dex);
}

void Species::rock_gnome(Abilityscore& object)
{
	object.ability_summary.con += 1;

	object.ability_summary.conabm = object.ability_modifier(object.ability_summary.con);
}

void Species::default_halfelf(Abilityscore& object)
{
	object.ability_summary.cha += 2;

	object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);
}
	

void Species::halfelf_plustwo(Abilityscore& object, char a, char b)
{
	switch (a)
	{

	case 's':
	{
		object.ability_summary.str += 1;
		object.ability_summary.strabm = object.ability_modifier(object.ability_summary.str);
		break;
	}
	case 'd':
	{
		object.ability_summary.dex += 1;
		object.ability_summary.dexabm = object.ability_modifier(object.ability_summary.dex);
		break;
	}
	case 'c':
	{
		object.ability_summary.con += 1;
		object.ability_summary.conabm = object.ability_modifier(object.ability_summary.con);
		break;
	}
	case 'i':
	{
		object.ability_summary.intl += 1;

		object.ability_summary.intlabm = object.ability_modifier(object.ability_summary.intl);
		break;
	}
	case 'w':
	{
		object.ability_summary.wis += 1;

		object.ability_summary.wisabm = object.ability_modifier(object.ability_summary.wis);
		break;
	}
	case 'a':
	{
		object.ability_summary.cha += 1;

		object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);
		break;
	}
	default:
	{
		std::cout << "there is a problem with your 'char a' switch statement" << std::endl;
		break;
	}
	
	}

	switch (b)
	{

	case 's':
	{
		object.ability_summary.str += 1;
		object.ability_summary.strabm = object.ability_modifier(object.ability_summary.str);
		break;
	}
	case 'd':
	{
		object.ability_summary.dex += 1;
		object.ability_summary.dexabm = object.ability_modifier(object.ability_summary.dex);
		break;
	}
	case 'c':
	{
		object.ability_summary.con += 1;
		object.ability_summary.conabm = object.ability_modifier(object.ability_summary.con);
		break;
	}
	case 'i':
	{
		object.ability_summary.intl += 1;

		object.ability_summary.intlabm = object.ability_modifier(object.ability_summary.intl);
		break;
	}
	case 'w':
	{
		object.ability_summary.wis += 1;

		object.ability_summary.wisabm = object.ability_modifier(object.ability_summary.wis);
		break;
	}
	case 'a':
	{
		object.ability_summary.cha += 1;

		object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);
		break;
	}
	default:
	{
		std::cout << "there is a problem with your 'char b' switch statement" << std::endl;
		break;
	}

	}

}

void Species::halforc(Abilityscore& object)
{
	object.ability_summary.str += 2;
	object.ability_summary.con += 2;

	object.ability_summary.strabm = object.ability_modifier(object.ability_summary.str);
	object.ability_summary.conabm = object.ability_modifier(object.ability_summary.con);
}

void Species::tiefling(Abilityscore& object)
{
	object.ability_summary.intl += 1;
	object.ability_summary.cha += 2;

	object.ability_summary.intlabm = object.ability_modifier(object.ability_summary.intl);
	object.ability_summary.chaabm = object.ability_modifier(object.ability_summary.cha);
}