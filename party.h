#pragma once

#include <memory>
#include <vector>
#include <string>

/**
 * @brief Keeps track of parties
 * Includes methods for modifying party size, ID, and handling defeated characters
 */
class Profession; //fwd declaration

class Party {
    public:
        Party() = delete;
        Party(const std::shared_ptr<Profession> & character1);
        Party(const std::shared_ptr<Profession> &character1, const std::shared_ptr<Profession> &character2,
        const std::shared_ptr<Profession> &character3, const std::shared_ptr<Profession> &character4);

        int getPartySize() const;

        std::shared_ptr<Profession> getPartyMember(int i) const; //index starts at 0
        
        std::string getpartyID() const; 

        void setPartyID(std::string ID); //party id lets us know if it is an enemy party or a player party.

        bool moveDownedCharacter(int i);

        void resetPartySize();

        bool swapCharacters(int charNum1, int charNum2); //works based on indices

    private:
        std::vector<std::shared_ptr<Profession>> partyMembers; //0 and 1 are front row and 2 and 3 are back row
        std::string partyID;
        int partySize;
};