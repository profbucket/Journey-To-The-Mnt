#pragma once
#include "Profession.h"

/**
 * @brief Technomancer profession class
 * Contains overriden methods and character builder mods
 */
class Technomancer : public Profession { //Class that can control computer hardware
    public:
        Technomancer() = delete;
        Technomancer(std::shared_ptr<Major> major, std::string name) : Profession(major, name) {
            m_HPmod = major->getStartHP() + 0;
            m_ACmod = major->getAC() + 2;
            m_HBmod = major->getHitBonus() + 2;
            m_initMod = major->getInitiative() + 1;
            maxHP = m_HPmod;

            abilityTypes[0] = Profession::attacking_front;
            abilityTypes[1] = Profession::attacking_single;
            abilityTypes[2] = Profession::attacking_single;
            abilityTypes[3] = Profession::attacking_all;
        }
        void printActions() override;
        std::string getProfessionID() override;
        
        private:
            bool abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) override; //shockPunch - melee attack that does splash damage
            bool abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) override; //hijack - poisons an enemy
            bool abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) override; //systemLock - can daze an enemy
            bool abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) override; //overheat - attacking_all
};