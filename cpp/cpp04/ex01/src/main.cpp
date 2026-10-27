#include <iostream>
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl << "===== " << s << " =====" << std::endl;
}

/* TEST 1 : main du sujet, avec delete via Animal* */
static void testSubject(void)
{
	title("TEST 1 : subject main");
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;	// ne doit pas leak
	delete i;
}

/* TEST 2 : tableau moitie Dog / moitie Cat, detruit via Animal* */
static void testArray(void)
{
	title("TEST 2 : Animal array (half Dog, half Cat)");
	const int size = 6;
	Animal *animals[size];

	for (int k = 0; k < size; k++)
	{
		if (k < size / 2)
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

/* TEST 3 : copie profonde de Dog (constructeur de copie) */
static void testDeepCopyDogCtor(void)
{
	title("TEST 3 : Dog deep copy (copy constructor)");
	Dog a;
	a.getBrain()->setIdea(0, "bone");
	{
		Dog b(a);
		a.getBrain()->setIdea(0, "ball");
		std::cout << "b idea 0 : " << b.getBrain()->getIdea(0) << " (expected: bone)" << std::endl;
		std::cout << "a idea 0 : " << a.getBrain()->getIdea(0) << " (expected: ball)" << std::endl;
		std::cout << "different brains : " << (a.getBrain() != b.getBrain())
			<< " (expected: 1)" << std::endl;
		std::cout << "different idea addresses : "
			<< (a.getBrain()->getIdeaAddress(0) != b.getBrain()->getIdeaAddress(0))
			<< " (expected: 1)" << std::endl;
	}	// b detruit ici, a doit rester valide
	std::cout << "a idea 0 after b destroyed : " << a.getBrain()->getIdea(0)
		<< " (expected: ball)" << std::endl;
}

/* TEST 4 : copie profonde de Dog (operator=) */
static void testDeepCopyDogAssign(void)
{
	title("TEST 4 : Dog deep copy (assignment operator)");
	Dog a;
	Dog c;

	a.getBrain()->setIdea(0, "ball");
	a.getBrain()->setIdea(99, "last idea");
	c = a;
	a.getBrain()->setIdea(0, "stick");
	std::cout << "c idea 0  : " << c.getBrain()->getIdea(0) << " (expected: ball)" << std::endl;
	std::cout << "c idea 99 : " << c.getBrain()->getIdea(99) << " (expected: last idea)" << std::endl;
	std::cout << "a idea 0  : " << a.getBrain()->getIdea(0) << " (expected: stick)" << std::endl;
	std::cout << "different brains : " << (a.getBrain() != c.getBrain())
		<< " (expected: 1)" << std::endl;
}

/* TEST 5 : copie profonde de Cat (constructeur + operator=) */
static void testDeepCopyCat(void)
{
	title("TEST 5 : Cat deep copy");
	Cat x;
	x.getBrain()->setIdea(0, "mouse");
	{
		Cat y(x);
		x.getBrain()->setIdea(0, "fish");
		std::cout << "y idea 0 : " << y.getBrain()->getIdea(0) << " (expected: mouse)" << std::endl;
		std::cout << "different brains : " << (x.getBrain() != y.getBrain())
			<< " (expected: 1)" << std::endl;
	}
	std::cout << "x idea 0 after y destroyed : " << x.getBrain()->getIdea(0)
		<< " (expected: fish)" << std::endl;

	Cat z;
	z = x;
	x.getBrain()->setIdea(0, "yarn");
	std::cout << "z idea 0 : " << z.getBrain()->getIdea(0) << " (expected: fish)" << std::endl;
}

/* TEST 6 : copie d'un objet du tableau, puis destruction de l'original */
static void testCopyFromArray(void)
{
	title("TEST 6 : copy of an object from the array");
	Animal *animals[2];

	animals[0] = new Dog();
	animals[1] = new Cat();
	static_cast<Dog *>(animals[0])->getBrain()->setIdea(0, "walk");
	static_cast<Cat *>(animals[1])->getBrain()->setIdea(0, "sleep");

	Dog dogCopy(*static_cast<Dog *>(animals[0]));
	Cat catCopy(*static_cast<Cat *>(animals[1]));

	delete animals[0];
	delete animals[1];

	std::cout << "dogCopy idea 0 : " << dogCopy.getBrain()->getIdea(0) << " (expected: walk)" << std::endl;
	std::cout << "catCopy idea 0 : " << catCopy.getBrain()->getIdea(0) << " (expected: sleep)" << std::endl;
}

/* TEST 7 : auto-affectation et limites de Brain */
static void testEdgeCases(void)
{
	title("TEST 7 : edge cases");
	Dog d;

	d.getBrain()->setIdea(0, "self");
	d = d;
	std::cout << "after self-assignment : " << d.getBrain()->getIdea(0) << " (expected: self)" << std::endl;

	d.getBrain()->setIdea(100, "out of range");		// message d'erreur attendu
	std::cout << d.getBrain()->getIdea(100) << std::endl;	// message d'erreur attendu
	std::cout << "NULL address for out of range : "
		<< (d.getBrain()->getIdeaAddress(100) == NULL) << " (expected: 1)" << std::endl;
}

int main(void)
{
	testSubject();
	testArray();
	testDeepCopyDogCtor();
	testDeepCopyDogAssign();
	testDeepCopyCat();
	testCopyFromArray();
	testEdgeCases();
	return 0;
}