/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:29:17 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:10:38 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	title("Both types");
	{
		ClapTrap clap("Clap");
		ScavTrap scav("Scav");
		clap.attack("X");          // 0 degats
		scav.attack("X");          // 20 degats
	}

	title("Destructors");
	return 0;
}