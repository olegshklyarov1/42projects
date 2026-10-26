#include <iostream>
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

static void testSubject(void)
{
	title("TEST 1 : subject main");
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();		// Meow
	j->makeSound();		// Woof
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

static void testWrong(void)
{
	title("TEST 2 : WrongAnimal / WrongCat base pointer");
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
}

static void testWrongDirect(void)
{
	title("TEST 3 : WrongCat uses directly");
	WrongCat wc;

	wc.makeSound();		// "Wrong Meow"
}

static void testStack(void)
{
	title("TEST 4 : object on the pile");
	Dog dog;
	Cat cat;

	std::cout << dog.getType() << " : ";
	dog.makeSound();
	std::cout << cat.getType() << " : ";
	cat.makeSound();
}

static void testReference(void)
{
	title("TEST 5 : reference polymorphisme");
	Dog dog;
	Cat cat;
	Animal &r1 = dog;
	Animal &r2 = cat;

	r1.makeSound();		// Woof
	r2.makeSound();		// Meow
}

static void testCopy(void)
{
	title("TEST 6 : copy constructors");
	Dog original;
	Dog copy(original);
	Dog assigned;

	assigned = original;
	std::cout << "original : " << original.getType() << std::endl;
	std::cout << "copy     : " << copy.getType() << std::endl;
	std::cout << "assigned : " << assigned.getType() << std::endl;
	copy.makeSound();
	assigned.makeSound();

	Cat c1;
	Cat c2(c1);
	Cat c3;

	c3 = c1;
	c1 = c1;
	std::cout << c2.getType() << " / " << c3.getType() << std::endl;
}

static void testArray(void)
{
	title("TEST 7 : Animal array");
	const int size = 6;
	Animal *animals[size];

	for (int k = 0; k < size; k++)
	{
		if (k % 2 == 0)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	std::cout << "--- sounds ---" << std::endl;
	for (int k = 0; k < size; k++)
	{
		std::cout << animals[k]->getType() << " : ";
		animals[k]->makeSound();
	}
	std::cout << "--- destruction ---" << std::endl;
	for (int k = 0; k < size; k++)
		delete animals[k];
}

int main(void)
{
	testSubject();
	testWrong();
	testWrongDirect();
	testStack();
	testReference();
	testCopy();
	testArray();
	return 0;
}