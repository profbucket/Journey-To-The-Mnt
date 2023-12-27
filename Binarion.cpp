#include "Binarion.h"
#include <random>
#include <iostream>
/**
 * @brief Binarion profession class
 * Contains overriden methods and character builder mods
 */
void Binarion::printActions() {
    std::cout << "1: BIT TWIST - DOES REGULAR DAMAGE TO AN ENEMY. NO CHANCE OF HARMING USER.\n"
    << "2: BINARY SHIFT - DOES DAMAGE TO THE ENEMY'S FRONT ROW IF SUCCESSFUL.\n"
    << "3: CODE FLUX- IF SUCCESSFUL, WILL CONFUSE OPPONENT.\n"
    << "4: HEALING PULSE - HEAL A PARTY MEMBER." <<std::endl;
}

std::string Binarion::getProfessionID() {return "BINARION";}

bool Binarion::abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) { //bit Twist
    if (!testMode) {
        std::cout << m_Name << " TRIES BIT TWIST" << std::endl;
        
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

bool Binarion::abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) { //binary shift
    if (!testMode) {
        std::cout << m_Name << " TRIES BINARY SHIFT" << std::endl;
        
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

bool Binarion::abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) { //code flux
    if (!testMode) {
        std::cout << m_Name << " TRIES CODE FLUX" << std::endl;
        
        if (successfulAction(iCharacter)) {
            iCharacter->setDazedStatus(true);
            std::cout << "SUCCESS. " << iCharacter->getName() << " HAS BECOME DAZED." << std::endl;
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
        iCharacter->setDazedStatus(true);
        return true;
    }
}

bool Binarion::abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) { //healing pulse
    if (!testMode) {
        std::cout << m_Name << " PERFORMS HEALING PULSE" << std::endl;
        
        int healingPoints = (rand()%9);
        iCharacter->changeHP(healingPoints);

        std::cout << iCharacter->getName() << " IS HEALED FOR " << healingPoints << " POINTS" << std::endl;
        std::cout << std::endl;
        return true;
    }
    else {
        iCharacter->changeHP(10);
        return true;
    }
}