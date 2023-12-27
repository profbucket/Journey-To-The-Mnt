#pragma once
#include "Profession.h"

class Binarion : public Profession {
    public:
        Binarion() = delete;
        Binarion(std::shared_ptr<Major> major, std::string name) : Profession(major, name) { 
            m_HPmod = major->getStartHP() - 40;
            m_ACmod = major->getAC() -2;
            m_HBmod = major->getHitBonus() + 10;
            m_initMod = major->getInitiative() + 0;
            maxHP = m_HPmod;

            abilityTypes[0] = Profession::attacking_single;
            abilityTypes[1] = Profession::attacking_front;
            abilityTypes[2] = Profession::attacking_single;
            abilityTypes[3] = Profession::selfParty;
            
        }
        void printActions() override;
        std::string getProfessionID() override;
        
        private: 
            bool abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) override; //bitTwist - does significant damage.
            bool abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) override; // binaryshift - does splash damage to front row
            bool abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) override; //codeflux - can put opponent in a daze.
            bool abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) override; //healingpulse - can heal allies.
};