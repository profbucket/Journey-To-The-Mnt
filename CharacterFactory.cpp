#include "characterFactory.h"
#include "Major.h"
#include "Profession.h"
#include "CompEng.h"
#include "CompSci.h"
#include "Cybersecurity.h"
#include "JazzStudies.h"
#include "Binarion.h"
#include "Technomancer.h"
#include "Generator.h"
#include "Dataweaver.h"
#include "FinalBossStats.h"
#include "FinalBossAbilities.h"
#include <map>

CharacterFactory::CharacterFactory() {
    std::shared_ptr<Major> m_compEng = std::make_shared<CompEng>();
    std::shared_ptr<Major> m_compSci = std::make_shared<CompSci>();
    std::shared_ptr<Major> m_cSec = std::make_shared<Cybersecurity>();
    std::shared_ptr<Major> m_JS = std::make_shared<JazzStudies>();
    std::shared_ptr<Major> m_finalBoss = std::make_shared<finalBoss_major>();

    m_characterMap.insert(std::pair(CEngType, m_compEng)); //i dont really know how maps work in c++ but i know it's dictionary stuff.
    m_characterMap[CSType] = m_compSci; //just copying the code from the samplefleetattack he gave us
    m_characterMap[CSecType] = m_cSec;
    m_characterMap[JSType] = m_JS;
    m_characterMap[finalBoss_majorType] = m_finalBoss;
}

CharacterFactory::~CharacterFactory() {}

CharacterFactory & CharacterFactory::GetCharacterFactory() {
    static CharacterFactory cF;
    return cF;
} //creating the single instance of CharacterFactory

std::shared_ptr<Profession> CharacterFactory::CreateCharacter(enumOfMajorType majorType, enumOfProfessionType ProfessionType, std::string name) {

    std::shared_ptr<Profession> retVal = nullptr;

    if (ProfessionType == BinarionType) {
        retVal = std::make_shared<Binarion>(m_characterMap[majorType], name); //all i know is that this works to generate a character
    }
    else if (ProfessionType == TechnomancerType) {
        retVal = std::make_shared<Technomancer>(m_characterMap[majorType], name);
    } 
    else if (ProfessionType == GeneratorType) {
        retVal = std::make_shared<Generator>(m_characterMap[majorType], name);
    }   
    else if (ProfessionType == DataweaverType) {
        retVal = std::make_shared<Dataweaver>(m_characterMap[majorType], name);
    }
    else if (ProfessionType == finalBoss_professionType) {
        retVal = std::make_shared<finalBoss_profession>(m_characterMap[majorType], name);
    }
    return retVal;
}

