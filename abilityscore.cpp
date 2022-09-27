#include "abilityscore.h"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstdlib>

/*
TO DO:
- fix iterator issues with the vector.erase() for the skills list (low priority with GUI implementation)
*/
int Abilityscore::diceRoll_d6T()
{
    int min = 1;
    int max = 6;
    int result = 0;
    result = rand() % max + min;
    return result;
}

void Abilityscore::return_rolls(std::vector<int>& vector)
{
    int y = 0;
    for (int i = 0; i < 4; i++)
    {
        y = diceRoll_d6T();
        vector.push_back(y);
    }
}

int Abilityscore::sortnsum_rolls(std::vector<int>& vector)
{
    int minRoll = 6;
    int y = minRoll;
    int roll_sum = 0;
   
    for (auto i : vector)
    {
        if (i < y)
        {
            y = i;
        }
        else
        {        }
    }
    
    for (auto j : vector)
    {
        roll_sum += j;
    }

    roll_sum -= y;
    
    return roll_sum;
}

int Abilityscore::ability_score()
{
    std::vector<int> results;
    int score;
    return_rolls(results);
    score = sortnsum_rolls(results);
    return score;
}

int Abilityscore::ability_modifier(int x) {
    int y = 0;
    if (x < 2) {
        y = -5;
    }
    else if (x < 4) {
        y = -4;
    }
    else if (x < 6) {
        y = -3;
    }
    else if (x < 8) {
        y = -2;
    }
    else if (x < 10) {
        y = -1;
    }
    else if (x < 12) {
        y = 0;
    }
    else if (x < 14) {
        y = 1;
    }
    else if (x < 16) {
        y = 2;
    }
    else if (x < 18) {
       y = 3;
    }
    else if (x < 20) {
       y = 4;
    }
    else {
        std::cout << "error" << std::endl;
    }
    return y;
}

void Abilityscore::sextuple_score()
{
    int x = 0;
    for (int i = 0; i < 6; i++)
    {
        x = ability_score();
        init_scores.push_back(x);
    }
}

void Abilityscore::assign_score()
{
    int switchbutton = 0;
    //int x = 0;

    //std::cout << "Rolled scores: ";
   // for (int i = 0; i < 6; i++)
   // {
   //     x = ability_score();
  //      init_scores.push_back(x);
        //std::cout << init_scores[i] << ", ";
   // }

    std::cout << "Please select a score to assign to a skill" << std::endl;

    std::cout << "______________________________________________________________________________________________________" << std::endl;
    std::cout << std::endl;
    
    while (!init_scores.empty())
    {
        std::cout << "Select Ability to assign a score value to: " << std::endl;
        std::cout << std::endl;
        for (auto j : skills)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
        int trash = 1;
        int selector;
        int skillspos;
        std::cout << "Enter selection here: ";
        std::cin >> switchbutton;
        switch (switchbutton) {
        case 1:
            if (ability_summary.str != 0)
            {
                std::cout << "Value already assigned to Strength ability! Please select another ability to assign a score" << std::endl;
                break;
            }
            std::cout << "STRENGTH" << std::endl;
            std::cout << "select which score to assign to the STRENGTH ability" << std::endl;

            for (auto k : init_scores)
            {
                std::cout << trash << " - " << k << ", ";
                trash++;
            }
            //int selector;
            std::cin >> selector;
            //if (selector > 0 && selector < 7)
            if (selector <= init_scores.size())
            {
                selector = selector--;
                ability_summary.str = init_scores.at(selector);
                init_scores.erase(init_scores.begin() + selector);
                skillspos = switchbutton - 1;
                //skills.erase(skills.begin() + skillspos);
            }
            else
            {
                std::cout << "please enter a valid selection option as an integer" << std::endl;
            }

            break;
        case 2:
            if (ability_summary.dex != 0)
            {
                std::cout << "Value already assigned to Dexterity ability! Please select another ability to assign a score" << std::endl;
                break;
            }
            std::cout << "DEXTERITY" << std::endl;
            std::cout << "select which score to assign to the DEXTERITY ability" << std::endl;

            for (auto m : init_scores)
            {
                std::cout << trash << " - " << m << ", ";
                trash++;
            }

            std::cin >> selector;
            //if (selector > 0 && selector < 7)
            if (selector <= init_scores.size())
            {
                selector = selector--;
                ability_summary.dex = init_scores.at(selector);
                init_scores.erase(init_scores.begin() + selector);
                skillspos = switchbutton - 1;
                //skills.erase(skills.begin() + skillspos);
            }
            else
            {
                std::cout << "please enter a valid selection option as an integer" << std::endl;
            }

            break;
        case 3:
            if (ability_summary.con != 0)
            {
                std::cout << "Value already assigned to Constitution ability! Please select another ability to assign a score" << std::endl;
                break;
            }
            std::cout << "CONSTITUTION" << std::endl;
            std::cout << "select which score to assign to the CONSTITUTION ability" << std::endl;

            for (auto n : init_scores)
            {
                std::cout << trash << " - " << n << ", ";
                trash++;
            }

            std::cin >> selector;
            //if (selector > 0 && selector < 7)
            if (selector <= init_scores.size())
            {
                selector = selector--;
                ability_summary.con = init_scores.at(selector);
                init_scores.erase(init_scores.begin() + selector);
                skillspos = switchbutton - 1;
                //skills.erase(skills.begin() + skillspos);
            }
            else
            {
                std::cout << "please enter a valid selection option as an integer" << std::endl;
            }
            break;
        case 4:
            if (ability_summary.intl != 0)
            {
                std::cout << "Value already assigned to Intelligence ability! Please select another ability to assign a score" << std::endl;
                break;
            }
            std::cout << "INTELLIGENCE" << std::endl;
            std::cout << "select which score to assign to the INTELLIGENCE ability" << std::endl;

            for (auto o : init_scores)
            {
                std::cout << trash << " - " << o << ", ";
                trash++;
            }

            std::cin >> selector;
            //if (selector > 0 && selector < 7)
            if (selector <= init_scores.size())
            {
                selector = selector--;
                ability_summary.intl = init_scores.at(selector);
                init_scores.erase(init_scores.begin() + selector);
                skillspos = switchbutton - 1;
                //skills.erase(skills.begin() + skillspos);
            }
            else
            {
                std::cout << "please enter a valid selection option as an integer" << std::endl;
            }
            break;
        case 5:
            if (ability_summary.wis != 0)
            {
                std::cout << "Value already assigned to Wisdom ability! Please select another ability to assign a score" << std::endl;
                break;
            }
            std::cout << "WISDOM" << std::endl;
            std::cout << "select which score to assign to the WISDOM ability" << std::endl;

            for (auto p : init_scores)
            {
                std::cout << trash << " - " << p << ", ";
                trash++;
            }

            std::cin >> selector;
            //if (selector > 0 && selector < 7)
            if (selector <= init_scores.size())
            {
                selector = selector--;
                ability_summary.wis = init_scores.at(selector);
                init_scores.erase(init_scores.begin() + selector);
                skillspos = switchbutton - 1;
                //skills.erase(skills.begin() + skillspos);
            }
            else
            {
                std::cout << "please enter a valid selection option as an integer" << std::endl;
            }
            break;
        case 6:
            if (ability_summary.cha != 0)
            {
                std::cout << "Value already assigned to Charisma ability! Please select another ability to assign a score" << std::endl;
                break;
            }
            std::cout << "CHARISMA" << std::endl;
            std::cout << "select which score to assign to the CHARISMA ability" << std::endl;

            for (auto q : init_scores)
            {
                std::cout << trash << " - " << q << ", ";
                trash++;
            }

            std::cin >> selector;
            //if (selector > 0 && selector < 7)
            if (selector <= init_scores.size())
            {
                selector = selector--;
                ability_summary.cha = init_scores.at(selector);
                init_scores.erase(init_scores.begin() + selector);
                skillspos = switchbutton - 1;
                //skills.erase(skills.begin() + skillspos);
            }
            else
            {
                std::cout << "please enter a valid selection option as an integer" << std::endl;
            }
            break;
        default:
            std::cout << "invalid input, please try again" << std::endl;

            break;
        }
    }

    std::cout << "Now for your Ability Modifiers!" << std::endl;
    std::cout << std::endl;
    std::cout << "Current ability scores: " << std::endl;
    std::cout << ability_summary.str << " " << ability_summary.dex << " " << ability_summary.con << " ";
    std::cout << ability_summary.intl << " " << ability_summary.wis << " " << ability_summary.cha << std::endl;
    ability_summary.strabm = ability_modifier(ability_summary.str);
    ability_summary.dexabm = ability_modifier(ability_summary.dex);
    ability_summary.conabm = ability_modifier(ability_summary.con);
    ability_summary.intlabm = ability_modifier(ability_summary.intl);
    ability_summary.wisabm = ability_modifier(ability_summary.wis);
    ability_summary.chaabm = ability_modifier(ability_summary.cha);
    std::cout << std::endl;
    std::cout << "Ability modifiers for each score: " << std::endl;
    std::cout << "Strength ABM: " << ability_summary.strabm << std::endl;
    std::cout << "Dexterity ABM: " << ability_summary.dexabm << std::endl;
    std::cout << "Constitution ABM: " << ability_summary.conabm << std::endl;
    std::cout << "Intelligence ABM: " << ability_summary.intlabm << std::endl;
    std::cout << "Wisdom ABM: " << ability_summary.wisabm << std::endl;
    std::cout << "Charisma ABM: " << ability_summary.chaabm << std::endl;

   
}

int Abilityscore::ac_assign()
{
    int abm_passoff = ability_summary.dexabm;
    return armor_class = abm_passoff + 10;
}


int Abilityscore::StrengthScore() {
    
    return ability_summary.str;
}

int Abilityscore::DexterityScore() {
    
    return ability_summary.dex;

}

int Abilityscore::ConstitutionScore() {
    
    return ability_summary.con;

}

int Abilityscore::IntelligenceScore() {
    
    return ability_summary.intl;
    
}

int Abilityscore::WisdomScore() {
  
    return ability_summary.wis;
    
}

int Abilityscore::CharismaScore() {
    
    return ability_summary.cha;
    
}