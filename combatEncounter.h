#pragma once

#include "Major.h"
#include "Profession.h"
#include "party.h"
#include <vector>

/**
 * @brief Handles combat encounters
 * Contains all methods needed to initialize and end encounters, and modify party stats
 */
class CombatEncounter {
    public: 
        CombatEncounter() = delete;
        CombatEncounter(std::shared_ptr<Party> playerParty, std::shared_ptr<Party> enemyParty) : m_playerParty(playerParty), m_enemyParty(enemyParty) {};

        bool encounter(); //returns false if player party loses, true if they win
        void endEncounter(); //output final match stats.

    private:
        struct char_init_party { //struct designed to hold a character, their initiative, and their party.
            std::shared_ptr<Profession> m_char;
            int m_init;
            std::shared_ptr<Party> m_party;

            char_init_party(std::shared_ptr<Profession> character, int init, std::shared_ptr<Party> party)
            : m_char(character), m_init(init), m_party(party) {}
        };

        
        struct moveType_abilityNum { //struct designed to be able to return a movetype and an abilityselection
            Profession::moveType selectedMoveType;
            int abilitySelection;

            moveType_abilityNum(Profession::moveType moveType, int selection) : selectedMoveType(moveType), abilitySelection(selection) {};

        };

        std::shared_ptr<Party> m_playerParty;
        std::shared_ptr<Party> m_enemyParty;

        std::vector<char_init_party> turnOrder;

        bool checkChoiceValidity(int lowerBound, int upperBound, int choice); //helper function
        bool checkCharacterStatus(int currentCharacter); //returns false if character is unable to take a turn, true if able
        bool removeDownedCharacters(); //helper function for encounter
        void seeCharacterStats(int iCharacter);


        CombatEncounter::moveType_abilityNum selectAbility(int currentCharacter); //helper function for taketurn
        bool selectTarget(bool enemy, Profession::moveType selectedMoveType, int chosenAbility, int currentCharacter); //helper function for taketurn()

        void initializeEncounter(); //helper function for encounter()
        int takeTurn(int currentCharacter); //helper function for encounter(), returns either currentCharacter or an increment of it

};