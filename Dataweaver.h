#pragma once
#include "Profession.h"

/**
 * @brief Dataweaver profession class
 * Contains overriden methods and character builder mods
 * 
 */
class Dataweaver : public Profession { //basically a rogue with some cool attacks
    public:
        Dataweaver() = delete;
        Dataweaver(std::shared_ptr<Major> major, std::string name) : Profession(major, name) {
            m_HPmod = major->getStartHP() -10;
            m_ACmod = major->getAC() + 3;
            m_HBmod = major->getHitBonus() + 2;
            m_initMod = major->getInitiative() + 5;
            maxHP = m_HPmod;

            abilityTypes[0] = Profession::attacking_any;
            abilityTypes[1] = Profession::attacking_single;
            abilityTypes[2] = Profession::self;
            abilityTypes[3] = Profession::attacking_any;
        }

        void printActions() override;
        std::string getProfessionID() override;

        private:
            bool abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) override; //quickattack - basic quick melee attack
            bool abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) override; //datacourruption - poisons an opponent
            bool abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) override; //datatransfer - profession unique attack, basically mind reading and can boost a party member's AC up significantly for one turn.
            bool abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) override;

};