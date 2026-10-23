/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:45:59 by olshklya          #+#    #+#             */
/*   Updated: 2026/10/23 16:51:20 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
	public:
		Weapon(const std::string& type);
		~Weapon();

		const std::string& getType(void) const;
		void setType(const std::string& type);

	private:
		std::string _type;
};