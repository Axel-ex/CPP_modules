/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:25:50 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/15 13:31:24 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL__H
#define __HARL__H

#include <iostream>

class Harl
{
    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif