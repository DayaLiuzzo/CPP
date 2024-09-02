#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
private:
public:
    virtual ~Base(); // Destructor
};

Base *generate(void);
void identify(Base &p);
void identify(Base *p);


#endif // BASE_HPP

