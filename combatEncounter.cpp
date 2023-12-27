#include "combatEncounter.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <functional>
#include <limits>


bool CombatEncounter::checkChoiceValidity(int lowerBound, int upperBound, int choice)
{
    if (choice > lowerBound && choice < upperBound) {
        return true;
    }
    else {
        std::cout << "INVALID CHOICE. PLEASE TRY AGAIN." <<std::endl;
        std::cin.clear(); //clearing error state and input stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return false;
}

bool CombatEncounter::checkCharacterStatus(int currentCharacter) {//returns false if character is unable to take a turn, true if able
    if (turnOrder[currentCharacter].m_char->dazeCheck()) {
        return false;
    }
    else if (turnOrder[currentCharacter].m_char->poisonCheck()) {}
    
    return true;
}

bool CombatEncounter::removeDownedCharacters() {
    for (int i = 0; i < turnOrder.size(); i++) {
        if (turnOrder[i].m_char->isDefeated()) {
            std::string m_charID = turnOrder[i].m_char->getName(); //getting index of downed character in their partymembers vector
        
            int downedCharacterIndex = -1; // Initialize to an invalid index

            for (int j = 0; j < turnOrder[i].m_party->getPartySize(); j++) {
                if (m_charID == turnOrder[i].m_party->getPartyMember(j)->getName()) {
                    downedCharacterIndex = j;
                    break; // If found, no need to continue the loop
                }
            }

            if (downedCharacterIndex != -1) {
                turnOrder[i].m_party->moveDownedCharacter(downedCharacterIndex); // Example function call to remove the party member
                // Remove from turnOrder vector
                turnOrder.erase(turnOrder.begin() + i);
                 // Adjust the index as the vector size has decreased
                return true;
            }
        }
    }
    return false;
}

void CombatEncounter::seeCharacterStats(int iCharacter) {
    auto character = turnOrder[iCharacter].m_char;
    std::cout << character->getName() << " STATS: " << character->getHP() << " HP, " << character->getAC() 
    << " AC, " << character->getHB() << " HB, " << character->getInit() << " INITIATIVE \n";
    if (character->getProfessionID() == "GENERATOR") {
        std::cout << " | ENERGY: " << character->getEnergy() <<"\n";
    }
    std::cout << std::endl;
}

void CombatEncounter::initializeEncounter() {

    m_playerParty->setPartyID("player"); //initializing party IDs
    m_enemyParty->setPartyID("enemy");
    
    std::vector<std::shared_ptr<Party>> partyVector = {m_playerParty, m_enemyParty};
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < partyVector[i]->getPartySize(); j++) {
            char_init_party entry(partyVector[i]->getPartyMember(j), partyVector[i]->getPartyMember(j)->getInit() + (rand()%21), partyVector[i]);
            
            turnOrder.push_back(entry);
        }
    }

    std::sort(turnOrder.begin(), turnOrder.end(), [](const char_init_party &a, const char_init_party &b) {
        return a.m_init > b.m_init;
    //lambda function to sort turnvector based on the second struct value: initiative, by descending order
    });
}

void CombatEncounter::endEncounter() {
    m_playerParty->resetPartySize();
    m_enemyParty->resetPartySize();
    
    std::cout << "=====================================================" << std::endl;
    for (int i = 0; i < m_playerParty->getPartySize(); i++) {
        auto character = m_playerParty->getPartyMember(i);
            
            std::cout << character->getName() << " POST ENCOUNTER STATS: " << character->getHP() << " HP, " << character->getAC() 
            << " AC, " << character->getHB() << " HB, " << character->getInit() << " INITIATIVE \n";
            if (character->getProfessionID() == "GENERATOR") {
                std::cout << " | ENERGY: " << character->getEnergy() <<"\n";
            }       
        std::cout << std::endl;
    }
    std::cout << "=====================================================" << std::endl;
}

CombatEncounter::moveType_abilityNum CombatEncounter::selectAbility(int currentCharacter) {
    int choice;
    bool validChoice = false;
    Profession::moveType selectedMoveType;
    
    std::cout << "IT IS " << turnOrder[currentCharacter].m_char->getName() << "'S TURN. SELECT ACTION TO TAKE" << std::endl;
    turnOrder[currentCharacter].m_char->printActions();

    while (!validChoice) {
        std::cin >> choice;
        if (checkChoiceValidity(0, 5, choice)) {
            validChoice = true;
        }
    }
    selectedMoveType = turnOrder[currentCharacter].m_char->getAbilityType(choice);

    moveType_abilityNum retVal(selectedMoveType, choice);
    return retVal;
}

bool CombatEncounter::selectTarget(bool enemy, Profession::moveType selectedMoveType, int chosenAbility, int currentCharacter) {
    int choice;
    bool validTicket = false;

    if (selectedMoveType == Profession::attacking_single) {
        if (enemy) {
            return turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_playerParty->getPartyMember((rand()%m_playerParty->getPartySize())/2), false);
            //crazy line but basically the current character is calling whatever ability they decided to call on a random enemy party member
              //should only attack people in front row
        }
        else {
            std::cout << "CHOOSE OPPONENT TO ATTACK. "  << std::endl;
            for (int i = 0; i < m_enemyParty->getPartySize() && i < 2; i++) {
                std:: cout << i + 1 << ": " << m_enemyParty->getPartyMember(i)->getName() << std::endl;
            }
            while (!validTicket) { //loops until valid/available opponent is entered
                std::cin >> choice;
                if (checkChoiceValidity(0, m_enemyParty->getPartySize() + 1, choice)) {
                    validTicket = true;
                }
                else {
                    std::cout << "INVALID INPUT, ENTER VALID OPPONENT." << std::endl;
                }
            }
                return turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_enemyParty->getPartyMember(choice - 1), false);
        }
    }
    else if (selectedMoveType == Profession::attacking_front) {
        if (enemy) {
            for (int i = 0; i < m_playerParty->getPartySize() && i < 2; i++) {
                turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_playerParty->getPartyMember(i), false);
            }
            return true;
        }
        else {
            for (int i = 0; i < m_enemyParty->getPartySize() && i < 2; i++) {
                turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_enemyParty->getPartyMember(i), false);
            }
            return true;
        }
    }
    else if (selectedMoveType == Profession::attacking_all) {
        if (enemy) {
            for (int i = 0; i < m_playerParty->getPartySize(); i++) {
                turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_playerParty->getPartyMember(i), false);
            }
            return true;
        }
        else {
            for (int i = 0; i < m_enemyParty->getPartySize(); i++) {
                turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_enemyParty->getPartyMember(i), false);
            }
            return true;
        }
    }
    else if (selectedMoveType == Profession::attacking_any) {
        if (enemy) {
            return turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_playerParty->getPartyMember((rand()%m_playerParty->getPartySize())), false);
        }
        else {
            std::cout << "CHOOSE OPPONENT TO ATTACK. "  << std::endl;
            for (int i = 0; i < m_enemyParty->getPartySize(); i++) {
                std:: cout << i + 1 << ": " << m_enemyParty->getPartyMember(i)->getName() << std::endl;
            }
            while (!validTicket) { //loops until valid/available opponent is entered
                std::cin >> choice;
                if (checkChoiceValidity(0, m_enemyParty->getPartySize() + 1, choice)) {
                    validTicket = true;
                }
                else {
                    std::cout << "INVALID INPUT, ENTER VALID OPPONENT." << std::endl;
                }
            }
            return turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_enemyParty->getPartyMember(choice - 1), false);
        }
    }
    else if (selectedMoveType == Profession::selfParty) {
        if (enemy) {
            return turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_enemyParty->getPartyMember((rand()%m_enemyParty->getPartySize())), false);
        }
        else {
            std::cout << "SELECT AN ALLY. "  << std::endl;
            for (int i = 0; i < m_playerParty->getPartySize(); i++) {
                std:: cout << i + 1 << ": " << m_playerParty->getPartyMember(i)->getName() << std::endl;
            }
            while (!validTicket) { //loops until valid/available ally is entered
                std::cin >> choice;
                if (checkChoiceValidity(0, m_playerParty->getPartySize() + 1, choice)) {
                    validTicket = true;
                }
                else {
                    std::cout << "INVALID INPUT, ENTER VALID ALLY." << std::endl;
                }
            }
            return turnOrder[currentCharacter].m_char->selectAction(chosenAbility, m_playerParty->getPartyMember(choice - 1), false);
        }
    }
    else if (selectedMoveType == Profession::self) {
        return turnOrder[currentCharacter].m_char->selectAction(chosenAbility, turnOrder[currentCharacter].m_char, false);
    }
    return false;
}


int CombatEncounter::takeTurn(int currentCharacter)
{
    bool enemy = false;
    int choice;
    Profession::moveType selectedMoveType;
    int chosenAbility;

    if (removeDownedCharacters()) {
        return currentCharacter;
    }
    
    if (!checkCharacterStatus(currentCharacter)) {
        return currentCharacter + 1;
    }

    if (turnOrder[currentCharacter].m_party->getpartyID() == "enemy") {
        enemy = true;
    }
    else {
        seeCharacterStats(currentCharacter);
    }

    if (enemy) {
        chosenAbility = (rand()%4)+1;
        selectedMoveType = turnOrder[currentCharacter].m_char->getAbilityType(chosenAbility);
    }

    else {
        moveType_abilityNum entry = selectAbility(currentCharacter);
        selectedMoveType = entry.selectedMoveType;
        chosenAbility = entry.abilitySelection;
    }

    selectTarget(enemy, selectedMoveType, chosenAbility, currentCharacter); //need to create a while loop to loop until valid input is given

    return currentCharacter + 1;
}

bool CombatEncounter::encounter()
{
    initializeEncounter();

    int i = 0;

    while (m_playerParty->getPartySize() != 0 && m_enemyParty->getPartySize() != 0) {
        
        i = takeTurn(i);
        
        if (i >= (m_enemyParty->getPartySize() + m_playerParty->getPartySize())) {
            i = 0;
        }
    }
    if (m_playerParty->getPartySize() == 0) {
        return false;
    }
    else {
        return true;
    }
}


