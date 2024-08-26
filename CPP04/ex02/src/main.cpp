#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const int	arraySize = 4;
	Animal		*animals[arraySize];
    

	for (int i = 0; i < arraySize / 2; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = arraySize / 2; i < arraySize; ++i)
	{
		animals[i] = new Cat();
	}
    std::cout << "---------------------" << std::endl;
	for (int i = 0; i < arraySize; ++i)
	{
		Dog* dog = dynamic_cast<Dog *>(animals[i]);
		if (dog)
		{
			dog->setBrainIdea(0, "Pee on the couch");
			std::cout << "Dog's idea: " << dog->getBrainIdea(0) << std::endl;
		}
        Cat* cat = dynamic_cast<Cat*>(animals[i]);
        if (cat) {
        cat->setBrainIdea(0, "Eat the mice");
        std::cout << "Cat's idea: " << cat->getBrainIdea(0) << std::endl;
    }
	}

    std::cout << "---------------------" << std::endl;
    std::cout << "Deep copy of Dog" << std::endl;

    Dog* dog = dynamic_cast<Dog *>(animals[0]);
    Dog* deep_dog = dog;
    std::cout << "Dog's idea: " << dog->getBrainIdea(0) << std::endl;
    std ::cout << "Deep Dog's idea: " << deep_dog->getBrainIdea(0) << std::endl;
    deep_dog->setBrainIdea(0, "Pee on the mattress");
    std::cout << "Dog's idea: " << dog->getBrainIdea(0) << std::endl;
    std::cout << "Deep Dog's idea: " << deep_dog->getBrainIdea(0) << std::endl;


    std::cout << "---------------------" << std::endl;
    std::cout << "Deep copy of Cat" << std::endl;

    Cat* cat = dynamic_cast<Cat *>(animals[3]);
    Cat* deep_Cat = cat;
    std::cout << "Cat's idea: " << cat->getBrainIdea(0) << std::endl;
    std ::cout << "Deep Cat's idea: " << deep_Cat->getBrainIdea(0) << std::endl;
    deep_Cat->setBrainIdea(0, "Eat the dogs food");
    std::cout << "Cat's idea: " << cat->getBrainIdea(0) << std::endl;
    std::cout << "Deep Cat's idea: " << deep_Cat->getBrainIdea(0) << std::endl;
    std::cout << "---------------------" << std::endl;

    // Animal idea_of_animal;
    //Animal* pointer_idea_of_animal;


    for (int i = 0; i < arraySize; ++i)
    {
        delete animals[i];
    }


	return (0);
}
