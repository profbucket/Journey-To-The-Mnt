#include "Major.h"
#include <iostream>

int  Major::getStartHP()const
{
    return m_startHP;
}

int  Major::getAC()const
{
    return m_armorClass;
}

int  Major::getHitBonus()const
{
    return m_hitBonus;
}

int  Major::getInitiative()const
{
    return m_initiative;
}
