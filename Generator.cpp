#include "Generator.h"
#include <iostream>
#include <random>
void Generator::printActions() {
    std::cout << "1: GENERATE ENERGY - BOOST YOUR STATS BY 5 ENERGY POINTS.\n"
    << "2: ENERGY SHIELD - GENERATE A SHIELD FOR YOURSELF OR AN ALLY. -3 ENERGY POINTS\n"
    << "3: ENERGY ATTACK - ATTACK AN ENEMY FROM AFAR BY RELEASING ENERGY. -5 ENERGY POINTS\n"
    << "4: ENERGY HEAL - SEND A HEALING BEAM TO YOURSELF OR AN ALLY. -3 ENERGY POINTS" << std::endl;
}

std::string Generator::getProfessionID(){return "GENERATOR";}

bool Generator::abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) { //generate energy
    if (!testMode) {
        if (energy < 30) {
            energy += 5;
            if (energy >=30) { //if energy goes over 30, then cap it at 30.
                std::cout << "MAX ENERGY (30) ACQUIRED" << std::endl;
                energy = 30;
            return true;
            }
            else {
                std::cout << this->getName() << " HAS GENERATED " << energy << " ENERGY POINTS." << std::endl;
            return true;
            }
        }
        std::cout << "MAX ENERGY (30) ACQUIRED" << std::endl;
        return false;
    }
    else {//testing
        if (energy < 30) {
            energy += 5;
            if (energy >=30) { //if energy goes over 30, then cap it at 30.
                energy = 30;
            return true;
            }
        }
        return false;
    }
}

bool Generator::abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) { //order shield
    if (!testMode) {
        std::cout << m_Name << " GENERATES A SHIELD" << std::endl;
        
        int shieldPoints = (rand()%6 + (energy/2));
        iCharacter->changeAC(shieldPoints);

        energy -= 3;
        if (energy < 0) {energy = 0;}
        std::cout << iCharacter->getName() << "'S AC GOES UP " << shieldPoints << " POINTS\n" << std::endl;
        return true;
    }
    else {//testing
        iCharacter->changeAC(10);
        energy-= 3;
        if (energy < 0) {energy = 0;}
        return true;
    }

}

bool Generator::abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) { //order attack
    if (!testMode) {
    std::cout << m_Name << " SHOOTS A STREAM OF ENERGY FROM THEIR HANDS" << std::endl;
    
    if (successfulAction(iCharacter)) {
        int damage = (rand()%12) + m_HBmod + (energy/2);
        iCharacter->changeHP(-(damage));

        std::cout << "THE ATTACK HITS " << iCharacter->getName() << " FOR " << damage << " DAMAGE" << std::endl;
        if (damage >= 20) {
            std::cout << "CRITICAL HIT!" << std::endl;
        }    
        if (iCharacter->isDefeated()) {
            std::cout << iCharacter->getName() << " HAS BEEN DOWNED!" << std::endl;
        }
        energy -= 5;
        if (energy < 0) {energy = 0;}
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
        energy -= 5;
        if (energy < 0) {energy = 0;}
        return true;
    }
}

bool Generator::abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) { //order heal
    if (!testMode) {
        std::cout << m_Name << " RELEASES A HEALING ENERGY BEAM" << std::endl;
        
        int healingPoints = (rand()%7) + (energy/2);
        iCharacter->changeHP(healingPoints);

        std::cout << iCharacter->getName() << " IS HEALED FOR " << healingPoints << " POINTS" << std::endl;
        energy -= 3;
        if (energy < 0) {energy = 0;}
        std::cout << std::endl;
        return true;
    }
    else {//testing
        iCharacter->changeHP(10);
        energy -= 3;
        if (energy < 0) {energy = 0;}
        return true;
    }
}