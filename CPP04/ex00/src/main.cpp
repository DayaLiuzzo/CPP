#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
const Animal* meta = new Animal();
const Animal* dog = new Dog();
const Animal* cat = new Cat();
std::cout << dog->getType() << " " << std::endl;
std::cout << cat->getType() << " " << std::endl;
cat->makeSound(); //will output the cat sound!
dog->makeSound();
meta->makeSound();

delete dog;
delete cat;
delete meta;

std::cout << "non pointers" << std::endl;
Animal meta2;
Dog dog2;
Cat cat2;
std::cout << dog2.getType() << " " << std::endl;
std::cout << cat2.getType() << " " << std::endl;
cat2.makeSound(); //will output the cat sound!
dog2.makeSound();
meta2.makeSound();

std::cout << "Wrong animals" << std::endl;
const WrongAnimal* wrongmeta = new WrongAnimal();
const WrongAnimal* wrongcat = new WrongCat();
std::cout << wrongcat->getType() << " " << std::endl;
wrongcat->makeSound(); //will output the cat sound!
wrongmeta->makeSound();

delete wrongcat;
delete wrongmeta;

Animal* meta3 = new Animal();
Animal* dog3 = new Dog();
Animal* cat3 = new Cat();
std::cout << dog3->getType() << " " << std::endl;
std::cout << cat3->getType() << " " << std::endl;
cat3->makeSound(); //will output the cat sound!
dog3->makeSound();
meta3->makeSound();

delete meta3;
delete dog3;
delete cat3;

return 0;
}