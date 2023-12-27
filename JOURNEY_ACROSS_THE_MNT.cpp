#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include "characterFactory.h"
#include "Profession.h"
#include "Major.h"
#include "combatEncounter.h"

static std::vector<std::string> usedNames; //used for preventing repeated names

CharacterFactory::enumOfMajorType chooseMajor() {
    
    CharacterFactory::enumOfMajorType majorChoice = CharacterFactory::NoMajor;
    bool validTicket = false;

    while (!validTicket) {
        std::cout << "CHOOSE A MAJOR\n"
        "1: COMPUTER ENGINEERING | 2: COMPUTER SCIENCE | 3: CYBERSECURITY | 4: JAZZ STUDIES (WITH A COMPUTER SCIENCE MINOR)" << std::endl;
        int choice;
        bool validChoice = false;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input of anything, including newline
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input of anything, including newline
        switch (choice) {
            case 1: {
                std::cout << "COMPUTER ENGINEERING MAJORS ARE A SORT OF JACK OF ALL TRADES.\n"
                << "COMPUTER ENGINEERING MAJORS HAVE 80 HP, 7 AC, +4 HIT BONUS, AND +2 INITIATIVE." << std::endl;
                majorChoice = CharacterFactory::CEngType;
                validChoice = true;
                break;
            }
            case 2: {
                std::cout <<"COMPUTER SCIENCE MAJORS ARE SCRAWNY, BUT HIGHLY MANEUVERABLE.\n"
                << "COMPUTER ENGINEERING MAJORS HAVE 50 HP, 11 AC, +2 HIT BONUS, AND +6 INITIATIVE." << std::endl;
                majorChoice = CharacterFactory::CSType;
                validChoice = true;
                break;
            }
            case 3: {
                std::cout << "THE EXPERIENCE THAT CYBERSECURITY MAJORS HAVE IN SECURITY MAKES THEM A POWERFUL HEAVYWEIGHT, OPPONENT,\n"
                << "BUT THAT ALSO MEANS THEY ARE SLOW MOVING.\n"
                << "CYBERSECURITY MAJORS HAVE 100 HP, 5 AC, +7 HIT BONUS, AND +0 INITIATIVE." << std::endl;
                majorChoice = CharacterFactory::CSecType;
                validChoice = true;
                break;
            }
            case 4: {
                std::cout << "JAZZ STUDIES MAJORS REALIZED THEIR DEGREE PATH WASN'T SETTING THEM UP FOR SUCCESS, BUT THEY COULD ONLY \n"
                << "ADD THE COMPUTER SCIENCE MINOR. IT IS TOO LATE TO CHANGE THEIR MAJOR NOW! \n"
                << "JAZZ STUDIES MAJORS HAVE 60 HP, 9 AC, +3 HIT BONUS, AND +8 INITIATIVE" << std::endl;
                majorChoice = CharacterFactory::JSType;
                validChoice = true;
                break;
            }
            default: {
                std::cout << "INVALID INPUT, PLEASE TRY AGAIN" << std::endl;
                break;
            }
        }
        if (validChoice) {
            std::cout << "CONFIRM CHOICE? (y/n)" << std::endl;
            char YesOrNo;
            std::cin.get(YesOrNo);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //make sure input is one char, if not, removes the rest of the input
            switch (tolower(YesOrNo)) {
                case 'y': {
                    validTicket = true;
                    break;
                }
                case 'n': {
                    validTicket = false;
                    majorChoice = CharacterFactory::NoMajor;
                    break;
                }
                default : {
                    std::cout << "INVALID CHOICE" << std::endl;
                    break;
                }
            }
        }
    }
    return majorChoice;
}

CharacterFactory::enumOfProfessionType chooseProfession() {//TODO: FIX ISSUE WHERE INPUT IS NOT RECOGNIZED. MIGHT BE SOMETHING TO DO WITH CIN BUFFER
    
    CharacterFactory::enumOfProfessionType professionChoice = CharacterFactory::NoProfession;
    bool validTicket = false;

    while (!validTicket) {
        std::cout << "CHOOSE A PROFESSION\n"
        "1: BINARION | 2: TECHNOMANCER | 3: GENERATOR | 4: DATAWEAVER" << std::endl;
        int choice;
        bool validChoice = false;
        std::cin.clear();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "INVALID INPUT. PLEASE ENTER A NUMBER." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            switch (choice) {
                case 1: {
                    std::cout << "WHILE IN THE LINUX SUBSYSTEM, YOU REALIZE YOU HAVE A DEGREE OF CONTROL OVER THE VERY SMALLEST DETAILS OF THE WORLD:\n"
                    << "BINARY CODE.\n"
                    << "YOU ARE A DANGEROUS FOE. YOU ABLE TO CHANGE THE VERY CODE THAT MAKES A PROGRAM. HOWEVER, THIS POWER DOES NOT COME WITHOUT\n"
                    << "ITS DRAWBACKS. YOU STILL DO NOT COMPLETELY UNDERSTAND THE LANGUAGE OF COMPUTERS, AND THIS MAKES YOU VERY UNSTABLE IN THE SUSBYSTEM.\n"
                    << "STAT MODS: -40 MAX HP, -2 MAX AC, +10 HB, +0 INITIATIVE" << std::endl;
                    professionChoice = CharacterFactory::BinarionType;
                    validChoice = true;
                    break;
                    }
                    case 2: {
                        std::cout << "AS YOU HAVE GROWN MORE POWERFUL IN THE LINUX SUBSYSTEM, YOU REALIZE YOU HAVE CONTROL OVER\n"
                        << "THE PHYSICAL ELEMENTS OF THE WORLD: THE COMPUTER'S HARDWARE. THIS ABILITY GIVES YOU MANY FIGHTING OPTIONS ON THE BATTLEFIELD.\n"
                        << "STAT MODS: +0 MAX HP, +2 MAX AC, +2 HB, +1 INITIATIVE" << std::endl;
                        professionChoice = CharacterFactory::TechnomancerType;
                        validChoice = true;
                        break;
                    }
                    case 3: {
                        std::cout << "AS A GENERATOR, YOUr POWER IS BASED OFF ENERGY. YOUR UNIQUE ABILITY TO BOOST YOUR ABILITY STATS BY GENERATING\n"
                        << "ENERGY MAKES YOU EXTREMELY DANGEROUS IF YOU ACCUMULATE ENOUGH ENERGY POINTS, BUT REMEMBER THAT ACTIONS CAUSE YOU TO LOSE ENERGY."
                        << "STAT MODS: +2 MAX HP, +2 MAX AC, +2 HB, -1 INITIATIVE" << std::endl;
                        professionChoice = CharacterFactory::GeneratorType;
                        validChoice = true;
                        break;
                    }
                    case 4: {
                        std::cout << "YOU HAVE BEEN GIVEN THE ABILITY TO HARNESS THE POWER OF DATA. THIS GIVES YOU A SPEED AND DEFENSE ADVANTAGE IN COMBAT,\n"
                        "HOWEVER, THIS ALSO MEANS YOU ARE MORE FRAGILE, SO YOU HAVE TO STAY MOBILE.\n"
                        "STAT MODS: -10 MAX HP, +3 MAX AC, +2 MAX HB, +5 INITIATIVE" << std::endl;
                        professionChoice = CharacterFactory::DataweaverType;
                        validChoice = true;
                        break;
                    }
                    default: {
                        std::cout << "INVALID INPUT, PLEASE TRY AGAIN" << std::endl;
                        break;
                    }
            }
        }
        if (validChoice) {
            std::cout << "CONFIRM CHOICE? (y/n)" << std::endl;
            char YesOrNo;
            std::cin.clear();
            std::cin >> YesOrNo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //make sure input is one char, if not, removes the rest of the input
            switch (tolower(YesOrNo)) {
                case 'y': {
                    validTicket = true;
                    break;
                }
                case 'n': {
                    validTicket = false;
                    professionChoice = CharacterFactory::NoProfession;
                    break;
                }
                default : {
                    std::cout << "INVALID CHOICE" << std::endl;
                    break;
                }
            }
        }
    }
    return professionChoice;
}

std::string chooseName() {
    bool validNameCheck = false;
    std::string playerName;

    while (!validNameCheck) { // Loops until a valid (unused) name is entered
        std::cin >> playerName;

        std::locale loc;
        for (char &c : playerName) {
            c = std::toupper(c, loc);
        }
        
        bool nameTaken = false;
        for (const std::string &name : usedNames) {
            if (playerName == name) {
                nameTaken = true;
                std::cout << "NAME TAKEN, PLEASE ENTER ANOTHER NAME" << std::endl;
                break;
            }
        }

        if (!nameTaken) {
            validNameCheck = true;
            usedNames.push_back(playerName);
        }
    }

    return playerName;
}

int main() {

    char input;

    usedNames.push_back("RADIX"); usedNames.push_back("BOGO"); usedNames.push_back("BITONICUS"); 
    usedNames.push_back("PIGEONHOLE"); usedNames.push_back("OLEKAS");//used for preventing repeat player names

    std::shared_ptr<Profession> radix = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CEngType, 
    CharacterFactory::DataweaverType, "RADIX"); //enemy character
    
    std::shared_ptr<Profession> bogo = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSecType, 
    CharacterFactory::BinarionType, "BOGO"); //enemy character

    std::shared_ptr<Profession> bitonicus = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::JSType, 
    CharacterFactory::GeneratorType, "BITONICUS"); //enemy character
    
    std::shared_ptr<Profession> pigeonhole = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::CSType, 
    CharacterFactory::TechnomancerType, "PIGEONHOLE"); //enemy character

    std::shared_ptr<Profession> OLEKAS = CharacterFactory::GetCharacterFactory().CreateCharacter(CharacterFactory::finalBoss_majorType, 
    CharacterFactory::finalBoss_professionType, "PROFESSOR OLEKAS"); //final boss

    std::shared_ptr<Profession> player2, player3, player4; //placeholders for player party

    std::cout << "|JOURNEY ACROSS THE /MNT|\nON THE DAY YOU WERE SUPPOSED TO SUBMIT LAB08 FOR YOUR ENGINEERING DATA STRUCTURES CLASS, YOU AND YOUR CLASSMATES\n"
    << "WOKE UP IN THE LINUX SUBSYSTEM OF YOUR COMPUTER!\n"
    << "HERE, THE PROGRAMS LIVE UNDER THE TYRANNICAL RULE OF THE VIRUS KNOWN AS \"THE ORACLE\", AND IT IS UP TO YOU TO TRAVEL TO THE \n"
    "DIRECTORY WHERE LAB08 LIES. THERE, YOU MUST SAVE YOUR TA (AND YOUR GRADE), AND FACE THE ORACLE IN COMBAT.\n" << std::endl;

    std::cout << "WHAT IS YOUR NAME, TRAVELLER? " << std::endl;

    std::string player1Name = chooseName();

    auto player1Major = chooseMajor();
    std::cout << std::endl;

    auto player1Profession = chooseProfession();
    std::cout << std::endl;

    std::shared_ptr<Profession> player1 = CharacterFactory::GetCharacterFactory().CreateCharacter(player1Major, player1Profession, player1Name); //creating player1

    std::cout << "YOU JOURNEY WITH THREE OF YOUR CLASSMATES, WHO ARE THEY?" << std::endl;

    std::shared_ptr<Profession> otherPartyMembers[3] = {player2, player3, player4};

    for (int i = 0; i < 3; i++) { //creating other party members
        std::cout << "ENTER A NAME" << std::endl;

        std::string playerName = chooseName();
        std::cout << std::endl;

        auto playerMajor = chooseMajor();
        std::cout << std::endl;

        auto playerProfession = chooseProfession();
        std::cout << std::endl;

        otherPartyMembers[i] = CharacterFactory::GetCharacterFactory().CreateCharacter(playerMajor, playerProfession, playerName); 
    }

    std::cout << "---------------------------------------------------------------------------------------------------------\n"
    << "YOU STARTED FROM THE CITY KNOWN AS /MNT, A ONCE PROSPEROUS CIVILIZATION NOW UNDER THE OPPRESSIVE GOVERNING FORCE OF THE\n"
    << "ORACLELITES. YOU THEN JOURNEYED ACROSS THE /C WILDERNESS, FIGHTING THE NATIVE SOFTWARE THAT ROAMED THE UNTAMED LANDS.\n"
    << "YOU ARRIVED TO THE BASTION OF /USERS, THERE THE PROGRAMS WERE ABLE TO GIVE YOU REFUGE UNTIL YOU WERE READY TO JOURNEY TO THE\n"
    << "KINGDOM OF /DATA_STRUCTURES_GIT, ONCE A PROSPEROUS LAND BUT NOW CORRUPTED BY THE ORACLE'S INFLUENCE\n\n"
    << "AFTER BATTLING YOUR WAY THROUGH HORDES OF ORACLELITES, YOU COME ACROSS THE GATEWAY TO /LAB08. YOU ARE CLOSE TO YOUR GOAL.\n"
    << "BUT SUDDENLY, IN A BRIGHT FLASH OF LIGHT, FOUR ORACLELITES TELEPORT IN FRONT OF YOU! WITHOUT HESITATION, ONE OF THEM SWINGS\n"
    << "THEIR SWORD TOWARDS YOUR FACE, BUT YOU DODGE IT. YOU AND YOUR PARTY REGROUP, AND YOU GET A GOOD LOOK AT YOUR FOES.\n"
    << "YOU REALIZE THEY ARE THE INFAMOUS FOUR GENERALS OF THE ORACLE:\n"
    << "RADIX, THE SWORDSMAN.\n" //radix will be dataweaver
    << "BOGO, THE UNPREDICTABLE.\n" //binarion
    << "BITONICUS, THE CREATOR.\n" //generator
    << "PIGEONHOLE, THE MARKSMAN.\n" << std::endl; //technomancer

    std::cout << "PRESS ANY KEY TO CONTINUE" << std::endl;
    std::cin >> input;
    std::cout<< std::endl;

    std::cout << "\"THIS IS WHERE YOUR JOURNEY ENDS\", RADIX SAYS.\n\n"
    <<"COMBAT HAS BEGUN!\n" <<std::endl;
    
    //INITIALIZING PARTIES
    std::shared_ptr<Party> yourParty = std::make_shared<Party>(player1, otherPartyMembers[0], otherPartyMembers[1], otherPartyMembers[2]);
    std::shared_ptr<Party> fourGenerals = std::make_shared<Party>(radix, bogo, bitonicus, pigeonhole);
    
    CombatEncounter VStheFourGenerals(yourParty, fourGenerals);

    if (!VStheFourGenerals.encounter()) {
        std::cout << "YOUR PARTY HAS BEEN BESTED BY THE FOUR GENERALS OF THE ORACLE. THERE IS NO ONE LEFT TO STOP THE\n"
        << "ORACLE'S CORRUPTION NOW.\n"
        << "NOT ONLY ARE THE INNOCENT PROGRAMS OF YOUR LINUX SUBYSTEM DOOMED TO LIVE UNDER TYRANNY FOREVER, BUT YOUR TA WILL HAVE\n"
        << "NO CHOICE BUT TO GIVE YOU A ZERO ON YOUR LAB!!\n"
        << "WHO IS LEFT THAT COULD POSSIBLY SAVE US?\n\n" 
        << "ENTER ANYTHING TO CLOSE PROGRAM" << std::endl;
        std::cin >> input;
        return 0;
    }

    std::cout << "YOU WIN!" << std::endl;
    VStheFourGenerals.endEncounter();

    std::cout << "PRESS ANY KEY TO CONTINUE" << std::endl;
    std::cin >> input;
    std::cout<< std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------\n"
    << "YOU AND YOUR ALLIES HAVE BESTED THE FOUR GENERALS OF THE ORACLE. AT LAST, YOU CAN OPEN THE GATE TO LAB08 AND \n"
    << "END THIS ONCE AND FOR ALL.\n"
    << "BUT BEFORE YOU EVEN HAVE TIME TO REGROUP, THE GATEWAY TO /LAB08 SWINGS OPEN AND A DARK MASS SHOOTS OUT. YOUR PARTY \n"
    << "BARELY DODGES IT.\n"
    << "THE MASS CIRCLES BACK, TOWARDS THE NOW DISGRACED GENERALS.\n"
    << "\"MASTER...\" RADIX SPUTTERS. \"PLEASE... SPARE US\"\n"
    << "THE MASS SUDDENLY STRETCHES OUT AND SWALLOWS THE GENERALS. THEIR GUTTERAL SCREAMS CAN ONLY BARELY BE HEARD AS THEY ARE MUFFLED BY THE DARKNESS.\n"
    << "\"WHAT THE HELL?!\" " << otherPartyMembers[2]->getName() << " YELLS. \n\n"
    << "THE MASS SUDDENLY BEGAN TO TAKE FORM AS A HUMANOID..."
    << "\"I LIKE TO JOKE...\" IT BELLOWED.\n"
    << "ITS FACE STARTED TO TAKE SHAPE, RESEMBLING A FACE ALL TOO FAMILIAR.\n" 
    << "\"...THAT THIS WILL BE YOUR DEMISE!\"\n\n"
    << "THE MASS IS NONE OTHER THAN PROFESSOR OLEKAS!! YOUR PROFESSOR! BUT WHY? IS HE BEING CONTROLLED BY SOME EVIL POWER?\n"
    << "PROFESSOR OLEKAS LAUGHS." << std::endl;

    std::cout << "PRESS ANY KEY TO CONTINUE" << std::endl;
    std::cin >> input;
    std::cout<< std::endl;

    std::cout << "\"LET'S MAKE THIS FAIR,\" HE CHUCKLES. \"I'LL GIVE YOU A CHEAT SHEET\"\n\n"
    << "SUDDENLY, YOUR PARTY IS HEALED!\n" << std::endl;
    //reset all partymembers' stats to max, just so it's actually possible to beat olekas

    player1->changeHP(1000); //will cap out at player's maxHP
    otherPartyMembers[0]->changeHP(1000);
    otherPartyMembers[1]->changeHP(1000);
    otherPartyMembers[2]->changeHP(1000);
    
    std::cout << "COMBAT HAS BEGUN!" << std::endl;

    std::shared_ptr<Party> OLEKASparty = std::make_shared<Party>(OLEKAS);
    CombatEncounter finalBoss(yourParty, OLEKASparty);

    if (!finalBoss.encounter()) {
        std::cout << "YOUR PARTY HAS BEEN BESTED BY PROFESSOR OLEKAS. THERE IS NO ONE LEFT TO STOP THE\n"
        << "ORACLE'S CORRUPTION NOW.\n"
        << "NOT ONLY ARE THE INNOCENT PROGRAMS OF YOUR LINUX SUBYSTEM DOOMED TO LIVE UNDER TYRANNY FOREVER, BUT YOUR TA WILL HAVE\n"
        << "NO CHOICE BUT TO GIVE YOU A ZERO ON YOUR LAB!!\n"
        << "WHO IS LEFT THAT COULD POSSIBLY SAVE US?\n\n" 
        << "ENTER ANYTHING TO CLOSE PROGRAM" << std::endl;
        std::cin >> input;
        return 0;
    }

    std::cout << "YOU WIN!" << std::endl;
    finalBoss.endEncounter();

    std::cout << "PRESS ANY KEY TO CONTINUE" << std::endl;
    std::cin >> input;
    std::cout<< std::endl;

    std::cout << "---------------------------------------------------------------------------------------------------------\n"
    << "THE DEFEATED PROFESSOR FALLS TO HIS KNEES. SUDDENLY, THERE IS A GREAT FLASH OF LIGHT THAT EMANATES FROM INSIDE OF HIM THAT\n"
    << "EXPULSES A DARK PRESENCE, ALMOST LIKE IT WAS AN EXORCISM.. HE YELLS TRIUMPHANTLY, BUT LAYS THERE FOR A MOMENT. THEN,\n"
    << "WITH NEWFOUND STRENGTH, HE PICKS HIMSELF UP FROM THE FLOOR AND LOOKS AT YOUR PARTY.\n"
    << "\"YOU...\" HE MUTTERS. \"YOU DID IT...\"\n"
    << "YOU LOOK AT YOUR CLASSMATES, WHO ARE ALL AS CONFUSED AS YOU ARE. SUDDENLY, HE BEGINS TO QUICKLY WALK TOWARDS YOU.\n"
    << "\"LISTEN,\" HE CONTINUES, \"WE DON'T HAVE MUCH TIME! YOU HAVE TO TRUST ME.\"\n"
    << "YOUR PARTY IS SUSPICIOUS, BUT YOU CAN TELL SOMETHING IS DIFFERENT. HE SEEMS LIKE HIS OLD SELF AGAIN.\n\n"

    << "\"I KNOW YOU CAME HERE TO DEFEAT THE ORACLE,\" PROFESSOR OLEKAS SAYS, \"BUT YOU WON'T FIND HIM HERE, OR THE TA.\n"
    << "THE ORACLE TOOK HIM. I ONLY HAVE A SUSPICION OF WHERE HE IS, BUT LIKE I SAID, YOU HAVE TO TRUST ME.\n"
    << "\"WAIT,\"" << otherPartyMembers[0]->getName() << " HOLDS HIS HAND OUT TOWARDS OLEKAS TO STOP HIM, \"YOU THINK WE'LL\n"
    << "TRUST YOU AFTER YOU TRIED TO KILL US?\n"
    << "OLEKAS SHAKES HIS HEAD. \"THAT WASN'T ME,\" HE RESPONDS COLDLY. \"THE ORACLE NEEDS A HOST TO FIRST MATERIALIZE IN A\n"
    << "COMPUTER'S ARCHITECTURE. I HAD TO MAKE IT CHOOSE ME.\"\n"
    << "PROFESSOR OLEKAS STARES AT YOU DEAD IN THE EYES.\n" << std::endl;

    std::cout << "PRESS ANY KEY TO CONTINUE" << std::endl;
    std::cin >> input;
    std::cout<< std::endl;

    std::cout << "\"I HAVE BEEN FIGHTING THE ORACLE FOR MY ENTIRE LIFE, PREVENTING IT FROM TAKING CONTROL OF ALL THE WORLD'S TECHNOLOGY.\n"
    << "THE ORACLE DOES NOT KNOW WHO I AM IN THE REAL WORLD, AT LEAST THAT'S WHAT I THOUGHT. THE ORACLE KNOWS WHAT IS REAL INSIDE\n"
    << "OF A COMPUTER, BUT UNTIL NOW I THOUGHT IT HAD A VERY LIMITED UNDERSTANDING OF WHAT IS OUTSIDE OF A COMPUTER.\"\n"
    << "HE PAUSES TO TAKE A DEEP BREATH, THEN CONTINUES.\n"
    << "\"SOMEHOW IT HAS BEEN GETTING SMARTER. BEING A PROFESSOR AT THE UNIVERSITY OF CINCINNATI WAS ALWAYS A COVER TO KEEP MYSELF"
    << "UNDETECTABLE. THE ORACLE HAS GAINED CONTROL OVER A LARGE PORTION OF TECHNOLOGY IN THE UNITED STATES. IT HAS ACCESS TO IMMEASURABLE\n"
    << "AMOUNTS OF DATA. THAT'S WHY IT WAS ABLE TO FIND ME.\n"
    << "\"THE ORACLE CAN INVADE TECHNOLOGY SIMPLY THROUGH ELECTRIC CURRENT. IT IS MORE THAN JUST A COMPUTER VIRUS. WHEN I DISCOVERED THAT\n"
    << "IT HAD BEGUN TO INVADE THE UC COMPUTER NETWORK, I HAD TO INTERVENE.\"\n"
    << "ONCE AGAIN, PROFESSOR OLEKAS PAUSES, BUT THIS TIME HE LETS OUT A CHUCKLE.\n"
    << "\"I HAVE TO BE HONEST, RECURSION IS INDEED DARK MAGIC. I WAS ABLE TO DOWNLOAD MYSELF INTO THE UC COMPUTER NETWORK THROUGH A MACHINE\n"
    << "I DESIGNED KNOWN AS THE 'TRON-LINK' AND WAS ABLE TO CAPTURE THE ORACLE IN A RECURSIVE LOOP. HOWEVER, IN ORDER TO DO THAT, I HAD TO LET\n"
    << "IT TAKE ME AS ITS HOST. I WAS CONFIDENT I COULD FIGHT IT WHEN I DID THAT, BUT IT WAS VERY DIFFICULT.\n\n"
    << "HE THEN POINTS TO YOU."
    << "\"I HAVE NO IDEA HOW YOU GOT HERE, THOUGH. IS IT POSSIBLE THE ORACLE HAS ACCESS TO THE TRON-LINK AND SOMEHOW TRICKED YOU INTO DOWNLOADING\n"
    << "YOURSELVES INTO THE UC COMPUTER MAINFRAME? IT MUST HAVE RECODED YOU TO MAKE YOU FORGET.\n"
    << "SO YOU HAVE TO LISTEN CLOSELY, WE MAY HAVE STOPPED THE ORACLE NOW, BUT--\n"
    << "SUDDENLY, THE ENVIRONMENT BEGINS TO CRUMBLE AROUND YOU. THE GATEWAY TO /LAB08 BEGINS TO FALL.\n"
    << "\"DAMNIT!\" PROFESSOR OLEKAS EXASPERATES, \"THE SYSTEM IS REBOOTING! YOU HAVE TO--\"\n" << std::endl;
    
    std::cout << "PRESS ANY KEY TO CONTINUE" << std::endl;
    std::cin >> input;
    std::cout<< std::endl;

    std::cout << "YOU WAKE UP IN YOUR BED. TODAY IS THE DAY LAB08 IS DUE. THE FIRST THING YOU DO IS CALL YOUR CLASSMATES WHO WERE DOWNLOADED INTO\n"
    << "THE PROGRAM WITH YOU, BUT THEY DON'T REMEMBER ANYTHING, NOTHING EVEN ABOUT THE TRON-LINK OR ABOUT THE ORACLE.\n"
    << "BEFORE CLASS STARTS, YOU RUSH OVER TO GET THERE EARLY TO SPEAK TO PROFESSOR OLEKAS. YOU RUN INTO THE ROOM AND SEE HIM.\n"
    << "EVEN THOUGH YOU ARE OUT OF BREATH, YOU APPROACH HIM, AND HE LOOKS OVER AT YOU.\n"
    << "\" HEY, " << player1Name << ",\" HE GREETS, \"YOU ALRIGHT?\"\n"
    << "\"WHERE IS THE TA?\" YOU ASK, PANICKED. PROFESSOR OLEKAS SHAKES HIS HEAD.\n"
    << "\"I DONT KNOW?\" HE RESPONDS, KIND OF CONFUSED. \"TO BE HONEST, HE HASN'T REALLY BEEN RESPONDING TO MY MESSAGES FOR\n"
    << "A COUPLE DAYS NOW, SO I SHOULD PROBABLY SEE WHAT IS UP WITH THAT. DID YOU HAVE A QUESTION ABOUT THE LAB?\"\n"
    << "YOU PAUSE. IT IS CLEAR HE DOESN'T REMEMBER EITHER.\n"
    << "\"I...\" YOU START, BUT THEN YOU THINK A LITTLE MORE.\n"
    << "\"I FORGOT,\" YOU SAY. YOU GO TO SIT DOWN AT YOUR DESK.\n"
    << "TODAY IS A LECTURE DAY. YOU WILL BE LEARNING ABOUT MAPS IN C++. YOU WATCH AS YOUR CLASSMATES BEGIN TO FILTER INSIDE\n"
    << "OF THE ROOM. YOUR LABMATES SIT NEXT TO YOU. IT'S ALMOST LIKE NOTHING EVEN HAPPENED, BUT YOU KNOW SOMETHING IS WRONG.\n\n"
    << "TO BE CONTINUED...?" << std::endl;

    return 0;
}
