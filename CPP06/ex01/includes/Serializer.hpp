/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:11:07 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/27 15:27:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct s_data
{
        int x;
        std::string str;
} t_data;

class Serializer
{
    public:
        static uintptr_t serialize(t_data *ptr);
        static t_data *deserialize(uintptr_t raw);
};

#endif