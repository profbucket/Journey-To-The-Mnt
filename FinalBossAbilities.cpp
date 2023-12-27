#include "FinalBossAbilities.h"
#include <iostream>

void finalBoss_profession::printActions(){return;}

std::string finalBoss_profession::getProfessionID() {return "OLEKAS";}

bool finalBoss_profession::abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) {
    if (!testMode) {
        std::cout << "PROFESSOR OLEKAS TRIES KERNEL OVERLOAD.\n ...THE GROUND SHAKES BENEATH YOUR FEET." << std::endl;
        
        if (successfulAction(iCharacter)) {

            int damage = (rand()%11) + m_HBmod;
            iCharacter->changeHP(-(damage));

            std::cout << "THE ATTACK HITS " << iCharacter->getName() << " FOR " << damage << " DAMAGE" << std::endl;
            if (damage >= 20) {
                std::cout << "CRITICAL HIT!" << std::endl;
            }    
            if (iCharacter->isDefeated()) {
                std::cout << iCharacter->getName() << " HAS BEEN DOWNED!" << std::endl;
            }
            std::cout << std::endl;
            return true;
        }
        else {
            std::cout << "THE ATTACK MISSES" << std::endl;
        }
        std::cout << std::endl;
        return false;
    }
    else {
        iCharacter->changeHP(-50);
        return true;
    }
}

bool finalBoss_profession::abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode){
    if (!testMode) {
        std::cout << "PROFESSOR OLEKAS TRIES SEGMENTATION FAULT" << std::endl;
        
        if (successfulAction(iCharacter)) {
            iCharacter->setPoisonStatus(true);
            iCharacter->setDazedStatus(true);
            int shieldDamage = (rand()%6);
            iCharacter->changeAC(-shieldDamage);
            std::cout << "ATTACK SUCCESSFUL" << iCharacter->getName() << "'S AC WENT DOWN BY " << shieldDamage << " POINTS.\n"
            << iCharacter->getName() << " HAS BECOME DAZED AND CORRUPTED!" <<std::endl;
            std::cout << std::endl;
            return true;
        }
        else {
            std::cout << "THE ATTACK MISSES" << std::endl;
        }
        std::cout << std::endl;
        return false;
    }
    else {
        iCharacter->setPoisonStatus(true);
        iCharacter->setDazedStatus(true);
        iCharacter->changeAC(-6);
        return true;
    }
}

bool finalBoss_profession::abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode){
    if (!testMode) {
        std::cout << "PROFESSOR OLEKAS PERFORMS REFACTOR." << std::endl;
        
        int healingPoints = (rand()%16);
        iCharacter->changeHP(healingPoints);

        std::cout << iCharacter->getName() << " IS HEALED FOR " << healingPoints << " POINTS" << std::endl;
        std::cout << std::endl;
        return true;

        return true;
    }
    else {
        iCharacter->changeHP(10);
        return true;
    }
}

bool finalBoss_profession::abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode){      
    if (!testMode) {
        std::cout << "PROFESSOR OLEKAS TRIES BINARY STORM SURGE" << std::endl;
        
        if (successfulAction(iCharacter)) {
            int damage = (rand()%21) + m_HBmod;
            iCharacter->changeHP(-(damage));

            std::cout << "THE ATTACK HITS " << iCharacter->getName() << " FOR " << damage << " DAMAGE" << std::endl;
            if (damage >= 20) {
                std::cout << "CRITICAL HIT!" << std::endl;
            }    
            if (iCharacter->isDefeated()) {
                std::cout << iCharacter->getName() << " HAS BEEN DOWNED!" << std::endl;
            }
            std::cout << std::endl;
            return true;
        }
        else {
            std::cout << "THE ATTACK MISSES" << std::endl;
        }
        std::cout << std::endl;
        return false;
    }

    else {
        iCharacter->changeHP(-50);
        return true;
    }
}