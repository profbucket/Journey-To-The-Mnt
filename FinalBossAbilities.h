#pragma once
#include "Profession.h"

/**
 * @brief Secret final boss profession
 * Contains overriden methods and character builder mods
 */
class finalBoss_profession : public Profession {//FINAL BOSS
    public:
        finalBoss_profession(std::shared_ptr<Major> major, std::string name) : Profession(major, name) {
            m_HPmod = major->getStartHP();
            m_ACmod = major->getAC();
            m_HBmod = major->getHitBonus();
            m_initMod = major->getInitiative();
            maxHP = m_HPmod;

            abilityTypes[0] = Profession::attacking_all;
            abilityTypes[1] = Profession::attacking_single;
            abilityTypes[2] = Profession::self;
            abilityTypes[3] = Profession::attacking_front;
        }

        void printActions() override;
        std::string getProfessionID() override;

        private:
            bool abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) override; //KERNEL OVERLOAD - ATTACKS THE ENTIRE PARTY
            bool abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) override; //SEGMENTATION FAULT - CORRUPTS AN ENEMY
            bool abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) override; //REFACTOR - INCREASES HEALTH
            bool abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) override; //BINARY SURGE - ATTACKS FRONT ROW
};