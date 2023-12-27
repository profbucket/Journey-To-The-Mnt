#include "Profession.h"
#include <iostream>
#include <cstdlib>
#include <random>

std::shared_ptr<Major> Profession::getMajor()const{return m_Major;}

std::string Profession::getName() const{return m_Name;}

void Profession::changeHP(int input)
{
    m_HPmod += input;

    if (m_HPmod > maxHP) {
        std::cout << "FULL HEALTH REACHED" << std::endl;
        m_HPmod = maxHP;
        return;
    }
    if (m_HPmod < 0) {
        m_HPmod = 0;
    }
}

void Profession::changeAC(int input)
{
    m_ACmod += input;

    if (m_ACmod > 12) {
        m_ACmod = 12;
        std::cout << "MAX POSSIBLE AC REACHED" << std::endl;
        return;
    }

    if (m_ACmod > maxAC) {
        std::cout << "MAX AC REACHED" << std::endl;
        m_ACmod = maxAC;
        return;
    }
    if (m_ACmod < 0) {
        m_ACmod = 0;
    }
}

void Profession::changeHB(int input){m_HBmod += input;}

void Profession::setPoisonStatus(bool input){poisoned = input;}

void Profession::setDazedStatus(bool input){dazed = input;}

bool Profession::isDefeated()
{
    if (m_HPmod <= 0) {
        defeated = true;
        return true;
    }
    else {
    return false;
    }
}

bool Profession::poisonCheck()
{
    if (poisoned == true) {
        if ((rand()%21) + m_ACmod > 18) {
            poisoned = false;
            std::cout << m_Name << " IS NO LONGER CORRUPTED.\n" << std::endl;
            return false; 
        }
        else {
            int damage = rand()%9;
            this->changeHP(-damage);
            std::cout << m_Name << " TAKES " << damage << " CORRUPTION DAMAGE\n" << std::endl;
        }
    }
    return false;
}

bool Profession::dazeCheck()
{
    if (dazed == true) {
        if ((rand()%21) + m_ACmod > 18 ) {
            dazed = false;
            std::cout << m_Name << " IS NO LONGER DAZED.\n" << std::endl;
            return false;
        }
        else {
            std::cout << m_Name << " IS DAZED.\n" << std::endl;
            return true;
        }
    }
    return false;
}

int Profession::getHP() const{return m_HPmod;}

int Profession::getAC() const{return m_ACmod;}

int Profession::getHB() const{return m_HBmod;}

int Profession::getEnergy() const{return energy;}

int Profession::getInit() const{return m_initMod;}

Profession::moveType Profession::getAbilityType(int index)
{
    return abilityTypes[index - 1];
}

bool Profession::successfulAction(std::shared_ptr<Profession> iCharacter)
{
    
    if ((rand()%21) > iCharacter->getAC()) { //if roll is higher than defender's armor class, attack is successful
        return true;
    }
    return false;
}

bool Profession::selectAction(int i, std::shared_ptr<Profession> iCharacter, bool testMode){
   
    switch (i) {
        case 1: {
            return this->abilitySlot1(iCharacter, testMode);
        }
        case 2: {
            return this->abilitySlot2(iCharacter, testMode);
        }
        case 3: {
            return this->abilitySlot3(iCharacter, testMode);
        }
        case 4: {
            return this->abilitySlot4(iCharacter, testMode);
        }
        default: {
            return false;
        }
    }
}

