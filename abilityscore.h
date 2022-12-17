#ifndef ABILITYSCORE_H
#define ABILITYSCORE_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


class Abilityscore {
private:
    const int min_roll = 1;
    const int max_roll = 6;
    std::vector<int> roll_results;
    std::vector<int> init_scores;
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
    int armor_class = 0;
public:
    /*
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
    */
    //int armor_class = 0;
    //ability_summary ability_summary;
    //std::vector<int> init_scores;
    std::vector<std::string> skills{ "STR", "DEX", "CON", "INT", "WIS", "CHA" };
    Abilityscore() {};
    ~Abilityscore() {};
    int diceRoll_d6T();
    //void returnRolls(int array[4]);

    //void return_rolls(std::vector<int>& vector);
    void return_rolls();
    //int sortRolls(int array[4]);
    //int sortnsum_rolls(std::vector<int>& vector);
    int sortnsum_rolls();
    //int totalRolls(int array[4]);
    //int total_rolls(std::vector<int> vector);
    int ability_score();
    int ability_modifier(int x);
    void sextuple_score();
    void assign_score();
    int ac_assign();

    std::vector<int>& fetch_init_scores();
    void resort_init_scores();
    void clear_init_scores();
    void commit_scores();
    void commit_lvl();

    int StrengthScore();
    int DexterityScore();
    int ConstitutionScore();
    int IntelligenceScore();
    int WisdomScore();
    int CharismaScore();

    void SetStr(int str);
    void SetDex(int dex);
    void SetCon(int con);
    void SetIntl(int intl);
    void SetWis(int wis);
    void SetCha(int cha);

    void pushback_init(int var);
    void clr_init();


    int StrAbm();
    int DexAbm();
    int ConAbm();
    int IntAbm();
    int WisAbm();
    int ChaAbm();

    int ArmorClass();


    int ScoreSelectorPartB(int score_container[6]);
    int scoreSelectorPartA(int score_container[6]);
    //int AbilityModifier(int x);

    friend class Species;
};
#endif ABILITYSCORE_H