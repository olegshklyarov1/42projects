/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:29:17 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 14:55:50 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

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

	title("Destructors");
	return 0;
}