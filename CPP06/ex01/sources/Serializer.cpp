/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:21:32 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/27 15:25:01 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

uintptr_t Serializer ::serialize(t_data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

t_data *Serializer ::deserialize(uintptr_t ptr)
{
    return (reinterpret_cast<t_data *>(ptr));
}