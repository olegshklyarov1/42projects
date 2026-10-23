#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

static void title(const std::string &str)
{
	std::cout << std::endl << "===== " << str << " =====" << std::endl;
}

int main()
{
	title("Constructors");
	ClapTrap a;
	ClapTrap b("Bob");
	ClapTrap c(b);       // copie
	ClapTrap d("Dave");
	d = b;               // assignation

	title("Simple Attack");
	b.attack("Target");
	std::cout << "Energy Bob: " << b.getEnergyPoints() << std::endl;

	title("Damage and Reparations");
	b.takeDamage(4);
	std::cout << "HP Bob: " << b.getHitPoints() << std::endl;
	b.beRepaired(3);
	std::cout << "HP Bob: " << b.getHitPoints() << std::endl;
	std::cout << "Energy Bob: " << b.getEnergyPoints() << std::endl;

	title("No Energy");
	ClapTrap e("Eve");
	for (int i = 0; i < 12; i++)
		e.attack("Dummy");
	e.beRepaired(5);     // doit echouer : plus d'energie
	std::cout << "Energy Eve: " << e.getEnergyPoints() << std::endl;

	title("Death");
	ClapTrap f("Frank");
	f.takeDamage(5);
	f.takeDamage(100);   // overkill -> HP a 0
	std::cout << "HP Frank: " << f.getHitPoints() << std::endl;
	f.takeDamage(1);     // deja mort
	f.attack("Someone"); // doit echouer
	f.beRepaired(10);    // doit echouer

	title("0 Damage");
	ClapTrap g("Gary");
	g.takeDamage(0);
	g.beRepaired(0);

	title("ScavTrap chaining");
	{
		ScavTrap scav("Scav");
		scav.attack("Target");
		scav.guardGate();
		scav.takeDamage(30);       // methode heritee
		scav.beRepaired(10);       // methode heritee
		std::cout << "HP: " << scav.getHitPoints() << " / Energy: " << scav.getEnergyPoints() << std::endl;
	}

	title("ScavTrap copy / assignment");
	{
		ScavTrap s1("Orig");
		ScavTrap s2(s1);
		ScavTrap s3;
		s3 = s1;
		s3.guardGate();            // doit afficher "Orig"
	}

	title("ScavTrap energy exhaustion");
	{
		ScavTrap tired("Tired");
		for (int i = 0; i < 52; i++)
			tired.attack("Dummy"); // 50 reussies, 2 refus
		std::cout << "Energy: " << tired.getEnergyPoints() << std::endl;
	}

	title("FragTrap chaining");
	{
		FragTrap frag("Frag");
		frag.attack("Target");     // herite de ClapTrap : 30 degats
		frag.highFivesGuys();
		frag.takeDamage(40);
		frag.beRepaired(10);
		std::cout << "HP: " << frag.getHitPoints() << " / Energy: " << frag.getEnergyPoints() << std::endl;
	}

	title("FragTrap copy / assignment");
	{
		FragTrap f1("Orig");
		FragTrap f2(f1);
		FragTrap f3;
		f3 = f1;
		f3.highFivesGuys();        // doit afficher "Orig"
	}

	title("All three types");
	{
		ClapTrap clap("Clap");
		ScavTrap scav("Scav");
		FragTrap frag("Frag");
		clap.attack("X");          // 0 degats
		scav.attack("X");          // 20 degats
		frag.attack("X");          // 30 degats
	}

	title("Virtual destructor");
	{
		ClapTrap *p = new FragTrap("Ptr");
		delete p;                  // Frag puis Clap destructor
	}

	title("Destructors");
	return 0;
}