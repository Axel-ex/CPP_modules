/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:27:33 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/19 17:00:53 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP__H
#define FRAGTRAP__H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& trap);
        ~FragTrap(void);

        FragTrap& operator=(const FragTrap& trap);

        void highFiveGuys(void);
};

std::ostream& operator<<(std::ostream& ofs, const FragTrap& rhs);

#endif