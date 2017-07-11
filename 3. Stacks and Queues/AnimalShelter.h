#include "Cat.h"
#include "Dog.h"
#include "Queue.h"
#ifndef ANIMALSHELTER_H
#define ANIMALSHELTER_H

class AnimalShelter {
public:
	void newDog();
	void newCat();

	void Adopt();
	void AdoptDog();
	void AdoptCat();
private:
	Queue Qdog;
	Queue Qcat;
};

#endif

//StackNode not a template
void AnimalShelter::newDog() {
	Dog newDog = new Dog();
	Qdog.push(newDog);
}

void AnimalShelter::newCat() {
	Cat newCat = new Cat();
	Qcat.push(newCat);
}

void AnimalShelter::Adopt() {
	if(Qdog.isEmpty() && Qcat.isEmpty()) {
		//if dog and cat queue are both empty
		cout << "No Animal to Adopt" << endl;
	} else {
		if(!Qdog.isEmpty() && !Qcat.isEmpty()) {
			// if dog and cat are not empty
			if(Qdog.peek().getTime() >= Qcat.peek().getTime()) {
				Qdog.pop();
				cout << "Dog Adopted" << endl;
			} else {
				Qcat.pop();
				cout << "Cat Adopted" << endl;
			}
		} else if(Qdog.isEmpty()) {
			//if dog is empty, then cat pop
			Qcat.pop();
			cout << "Cat Adopted" << endl;
		} else {
			Qdog.pop();
			out << "Dog Adopted" << endl;
		}
	}
}

void AnimalShelter::AdoptDog() {
	if(Qdog.isEmpty()) {
		cout << "Cannot Adopt Dog because there is no dog" << endl;
	} else {
		Qdog.pop();
		cout << "Dog Adopted" << endl;
	}
}	

void AnimalShelter::AdoptCat() {
	if(Qcat.isEmpty()) {
		cout << "Cannot Adopt Cat because there is no cat" << endl;
	} else {
		Qcat.pop();
		cout << "Cat Adopted" << endl;
	}
}

