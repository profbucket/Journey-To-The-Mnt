#pragma once
#include "Profession.h"

/**
 * @brief Generator profession class
 * Contains overriden methods and character builder mods
 */
class Generator : public Profession { //generates energy to become more powerful
    public:
        Generator() = delete;
        Generator(std::shared_ptr<Major> major, std::string name) : Profession(major, name) {
            m_HPmod = major->getStartHP() + 2;
            m_ACmod = major->getAC() + 2;
            m_HBmod = major->getHitBonus() + 2;
            m_initMod = major->getInitiative() + -1;
            maxHP = m_HPmod;

            abilityTypes[0] = Profession::self;
            abilityTypes[1] = Profession::selfParty;
            abilityTypes[2] = Profession::attacking_front;
            abilityTypes[3] = Profession::selfParty;
        }

        void printActions() override;
        std::string getProfessionID() override;
        
        private:
            bool abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) override; //GENERATE ENERGY - BUFFS ALL ACTIONS
            bool abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) override; //Ordershield- shield a party member
            bool abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) override; // order attack
            bool abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) override; //orderheal - heal a party member    
};