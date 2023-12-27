#include "party.h"

Party::Party(const std::shared_ptr<Profession> &character1)
{
    partyMembers.push_back(character1);

    partySize = 1;
}

Party::Party(const std::shared_ptr<Profession> &character1, const std::shared_ptr<Profession> &character2,
             const std::shared_ptr<Profession> &character3, const std::shared_ptr<Profession> &character4)
{
    partyMembers.push_back(character1);
    partyMembers.push_back(character2);
    partyMembers.push_back(character3);
    partyMembers.push_back(character4);

    partySize = 4;
}

int Party::getPartySize() const
{
    return partySize;
}

std::shared_ptr<Profession> Party::getPartyMember(int i) const
{
    return partyMembers[i];
}

std::string Party::getpartyID() const
{
    return partyID;
}

void Party::setPartyID(std::string ID)
{
    partyID = ID;
}

bool Party::moveDownedCharacter(int i)
{
    if (i < 0 || i >= this->getPartySize())
    return false;

    std::shared_ptr<Profession> temp = partyMembers[i]; 
    partyMembers.erase(partyMembers.begin() + i);
    //at most will only need to shift 3 elements so it shouldn't be that big of a deal.
    partyMembers.push_back(temp);//put downed party member in the back
    partySize--; //decrementing this value should make the downed party member inaccessible in combatEncounter 

    return true;
}

void Party::resetPartySize()
{
    partySize = partyMembers.size();

}

bool Party::swapCharacters(int charNum1, int charNum2)
{
    if (((charNum1 < 0 || charNum1 >= this->getPartySize()) || (charNum2 < 0 || charNum2 >= this->getPartySize())) 
    && charNum1 != charNum2) { //make sure charnums are in range and not the same
        return false;
    }

    std::shared_ptr<Profession> temp = partyMembers[charNum1];
    partyMembers[charNum1] = partyMembers[charNum2];
    partyMembers[charNum2] = temp;

    return true;
}