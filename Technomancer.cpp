#include "Technomancer.h"
#include <iostream>
#include <random>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

void Technomancer::printActions() {
    std::cout << "1: SHOCK PUNCH - MELEE ATTACK THAT CAN DO SPLASH DAMAGE\n" 
    << "2: HIJACK - CAN TAKE CONTROL OF AN ENEMY IF SUCCESSFUL, BUT DIFFICULT TO PULL OFF AND REQUIRES ENEMY TO BE IN MELEE RANGE\n"
    << "3: SYSTEM LOCK - CAN DAZE AN ENEMY FROM AFAR.\n"
    << "4: OVERHEAT - IF SUCESSFUL, WILL CAUSE AN ENEMY PROGRAM TO OVERHEAT, MAKING THEM TAKE DAMAGE EACH TURN." <<std::endl;
}

std::string Technomancer::getProfessionID(){return "TECHNOMANCER";}

bool Technomancer::abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) { //shock punch
    if (!testMode) {
        std::cout << "ELECTRICITY SHOOTS FROM " << m_Name << "'S HAND" << std::endl;
        
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

    else {//testing
        iCharacter->changeHP(-50);
        return true;
    }
}

bool Technomancer::abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) { //hijack
    if (!testMode) {
        std::cout << m_Name << " TRIES HIJACK" << std::endl;  
        if (successfulAction(iCharacter)) {
            iCharacter->setPoisonStatus(true);
            std::cout << "THE ATTACK HITS " << iCharacter->getName() << "\n"
            << iCharacter->getName() << " HAS BEEN HIJACKED AND CORRUPTED!" << std::endl;
            std::cout << std::endl;
            return true;
        }
        else {
            std::cout << "THE ATTACK MISSES" << std::endl;
        }
        std::cout << std::endl;
        return false;
    }
    else {//testing
        iCharacter->setPoisonStatus(true);
        return true;
    }
}

bool Technomancer::abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) { //system lock
    if (!testMode) {
        std::cout << m_Name << " TRIES SYSTEM LOCK" << std::endl;
        
        if (successfulAction(iCharacter)) {
            iCharacter->setDazedStatus(true);
            std::cout << "SYSTEM LOCK SUCCESSFUL. " << iCharacter->getName() << " HAS BEEN DAZED." << std::endl;
            std::cout << std::endl;
            return true;
        }
        else {
            std::cout << "THE ATTACK MISSES" << std::endl;
        }
        std::cout << std::endl;
        return false;
    }
    else {//testing
        iCharacter->setDazedStatus(true);
        return true;
    }
}

bool Technomancer::abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) { //overheat
    std::cout << m_Name << " TRIES OVERHEAT. THE AIR GETS HOT..." << std::endl;
    if (!testMode) {
        if (successfulAction(iCharacter)) {
            int damage = (rand()%9) + m_HBmod;
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
    else {//testing
        iCharacter->changeHP(-50);
        return true;
    }
}