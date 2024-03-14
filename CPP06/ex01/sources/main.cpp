/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:16:39 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/28 09:59:36 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

void adressTest(void)
{
    t_data *original = new t_data;
    original->str = "hey guys";
    original->x = 42;

    t_data *tmp = original;

    tmp = Serializer::deserialize(Serializer::serialize(tmp));
    if (tmp == original)
        std::cout << "adresses are equal" << std::endl;
    else
        std::cout << "adresses are not equal" << std::endl;

    std::cout << "\n-----------\nOBJECT CONTENT" << std::endl;
    std::cout << "ORIGINAL:" << std::endl;
    std::cout << "\t" << original->str << std::endl;
    std::cout << "\t" << original->x << std::endl;

    std::cout << "TMP:" << std::endl;
    std::cout << "\t" << original->str << std::endl;
    std::cout << "\t" << original->x << std::endl;

    delete original;
}

void operationTest(void)
{
    t_data data1;
    t_data data2;

    uintptr_t tmp1;
    uintptr_t tmp2;

    data1.str = "abc";
    data2.str = "def";
    data1.x = 4;
    data2.x = 2;

    tmp1 = Serializer::serialize(&data1);
    tmp2 = Serializer::serialize(&data2);

    // adress are added. it serialize the adress into an int
    tmp1 += tmp2;
    // res here will have an invalid adress
    t_data *res = Serializer::deserialize(tmp1);
    (void)res;

    // dereferencing ---> ERROR
    //  std::cout << "result:" << std::endl << "\t" << res->str << std::endl;
    //  std::cout << "\t" << res->x  << std::endl;
}

int main(void)
{
    adressTest();
    operationTest();

    return (EXIT_SUCCESS);
}