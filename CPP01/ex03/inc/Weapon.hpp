#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    private:
    std::string type;

    public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType();
    void setType(const std::string& newType);
};

#endif