#include "Animal.h"
#ifndef CAT_H
#define CAT_H

class Cat: public Animal {
public:
	Cat();
	int getTime() const;

private:
	int age;
};

Cat::Cat() {
	age = Animal::time++;
}

int Cat::getTime() const {
	return age;
}

#endif
