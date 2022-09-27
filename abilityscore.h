#ifndef ABILITYSCORE_H
#define ABILITYSCORE_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


class Abilityscore {
private:
   
public:
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
    int armor_class = 0;
    ability_summary ability_summary;
    std::vector<int> init_scores;
    std::vector<std::string> skills{ "STR", "DEX", "CON", "INT", "WIS", "CHA" };
    Abilityscore() {};
    int diceRoll_d6T();
    //void returnRolls(int array[4]);

    void return_rolls(std::vector<int>& vector);
    //int sortRolls(int array[4]);
    int sortnsum_rolls(std::vector<int>& vector);

    //int totalRolls(int array[4]);
    //int total_rolls(std::vector<int> vector);
    int ability_score();
    int ability_modifier(int x);
    void sextuple_score();
    void assign_score();
    int ac_assign();
    int StrengthScore();
    int DexterityScore();
    int ConstitutionScore();
    int IntelligenceScore();
    int WisdomScore();
    int CharismaScore();
    int ScoreSelectorPartB(int score_container[6]);
    int scoreSelectorPartA(int score_container[6]);
    //int AbilityModifier(int x);

    friend class Species;
};
#endif ABILITYSCORE_H