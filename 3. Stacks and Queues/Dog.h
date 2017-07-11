#include "Animal.h"
#ifndef DOG_H
#define DOG_H

class Dog: public Animal{
public: 
	Dog();
	int getTime() const;
private:
	int age;
};

Dog::Dog() { 
	age = Animal::time++;
}

int Dog::getTime() const{
	return age;
}
 
#endif