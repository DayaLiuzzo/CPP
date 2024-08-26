#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string ideas[100];
    // Class members go here
public:
    Brain(); // Default constructor
    Brain(const Brain &other); // Copy constructor
    Brain &operator=(const Brain &other); // Copy assignment operator
    ~Brain(); // Destructor
    //getters and setters
    std::string getIdea(int index) const;
    void setIdea(int index, std::string& idea);
};

#endif // BRAIN_HPP

