#pragma once

#include "Major.h"
#include <memory>
#include <string>

/**
 * @brief Profession parent class
 * Contains getters and setters for class, moveType enum, and character stats
 */
class Profession {
    public:
        Profession() = delete;
        Profession(std::shared_ptr<Major> major, std::string name) 
        : m_HPmod(0), m_ACmod(0), m_HBmod(0), m_initMod(0), m_Major(major), m_Name(name){};

        //this enum helps combatEncounter decide which potential characters are candidates for a certain action
        enum moveType {attacking_single, attacking_front, attacking_all, attacking_any, selfParty, self}; 

        std::shared_ptr<Major>getMajor() const;
        std::string getName() const;
        void changeHP(int input); //input is ADDED to current stat, does NOT change stat to input.
        void changeAC(int input);
        void changeHB(int input);

        void setPoisonStatus(bool input);
        void setDazedStatus(bool input);

        bool isDefeated();
        bool poisonCheck();
        bool dazeCheck();

        int getHP() const; int getAC() const; int getHB() const; int getInit() const; int getACBuff() const; int getEnergy() const;
        
        moveType getAbilityType(int index); //i starts from 1

        bool successfulAction(std::shared_ptr<Profession>);

        virtual void printActions() = 0; //prints the moves the character with the profession can make
        virtual std::string getProfessionID() = 0;

        bool selectAction(int i, std::shared_ptr<Profession> iCharacter, bool testMode); //boolean output to see if selectedAction is successful or not

    protected:
        std::shared_ptr<Major> m_Major;
        std::string m_Name;
        
        int m_HPmod, m_ACmod, m_HBmod, m_initMod; //final stats after profession-based modifications
        int maxHP, maxAC; //maximum hp/ac the player may have


        bool defeated = false;
        bool poisoned = false;
        bool dazed = false;

        int energy = 0;

        moveType abilityTypes[4];

        virtual bool abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) = 0;
        virtual bool abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) = 0;
        virtual bool abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) = 0;
        virtual bool abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) = 0;
};