#include "Dataweaver.h"
#include <iostream>
#include <random>

void Dataweaver::printActions() {
    std::cout << "1: QUICK ATTACK - SLASH YOUR ENEMIES WITH A MELEE ATTACK. YOUR QUICKNESS ALLOWS YOU ATTACK THE BACK ROW AS WELL.\n"
    << "2: DATA CORRUPTION: MELEE ATTACK. IF SUCCESSFUL, WILL CORRUPT AN ENEMY, POISONING THEM\n"
    << "3: DATA TRANSFER: TEMPORARILY BOOST YOUR AC.\n"
    << "4: DECRYPT: LOWERS AN ENEMY'S AC." << std::endl;
}

std::string Dataweaver::getProfessionID(){return "DATAWEAVER";}

bool Dataweaver::abilitySlot1(std::shared_ptr<Profession> iCharacter, bool testMode) { //quick attack.
    if (!testMode) {
        std::cout << m_Name << " TRIES QUICK ATTACK" << std::endl;
        
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
        iCharacter->changeHP(-50); //testing purposes
        return true;
    }
}

bool Dataweaver::abilitySlot2(std::shared_ptr<Profession> iCharacter, bool testMode) { //datacourruption - poisons an opponent
    if (!testMode) {
        if (successfulAction(iCharacter)) {
            iCharacter->setPoisonStatus(true);
            std::cout << "THE ATTACK HITS " << iCharacter->getName() << "\n"
            << iCharacter->getName() << " HAS BEEN CORRUPTED!" << std::endl;
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

bool Dataweaver::abilitySlot3(std::shared_ptr<Profession> iCharacter, bool testMode) { //datatransfer - profession unique attack, basically mind reading and can boost a party member's AC up significantly for one turn
    if (!testMode) {
        std::cout << m_Name << " ATTEMPTS A DATA TRANSFER" << std::endl;
        
        int shieldPoints = (rand()%6);
        iCharacter->changeAC(shieldPoints);

        std::cout << m_Name << " HAS OBTAINED KNOWLEDGE ABOUT THE NEXT TURN.\n"
        << iCharacter->getName() <<"'S AC HAS GONE UP " << shieldPoints << " POINTS" << std::endl;
        std::cout<<std::endl;
    return true;
    }
    else {//testing
        iCharacter->changeAC(10);
        return true;
    }

}

bool Dataweaver::abilitySlot4(std::shared_ptr<Profession> iCharacter, bool testMode) { //decrypt - LOWERS ENEMY AC
    if (!testMode) {
        std::cout << m_Name << " TRIES DECRYPT" << std::endl;
        
        if (successfulAction(iCharacter)) {
            int shieldDamage = (rand()%6);
            iCharacter->changeAC(-shieldDamage);
            std::cout << "DECRYPTION SUCCESSUL." << iCharacter->getName() << "'S AC WENT DOWN BY " << shieldDamage << " POINTS" <<std::endl;
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
        iCharacter->changeAC(-10);
        return true;
    }
}