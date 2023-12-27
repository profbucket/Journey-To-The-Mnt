#pragma once

class Major { //simple class, just initiates a character with specific values
    public:
        Major() = delete;
        Major(int maxHP, int armorClass, int hitBonus, int initiative) : m_startHP(maxHP), m_armorClass(armorClass),
        m_hitBonus(hitBonus), m_initiative(initiative) {}
        int getStartHP() const;
        int getAC() const;
        int getHitBonus() const;
        int getInitiative() const;

    protected:
        int m_startHP;
        int m_armorClass;
        int m_hitBonus;
        int m_initiative;
};