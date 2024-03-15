/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:56:29 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/14 11:07:52 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

void clearScreen(void) { std::cout << "\033c"; }

void pressEnter(void)
{
    std::cout << "\nPress ENTER to continue...";
    std::cin.ignore(10000, '\n');
    clearScreen();
}

void printBanner(const std::string& msg)
{
    const int bannerWidth = 15;
    int padding = std::max(0, (bannerWidth - static_cast<int>(msg.size())) / 2);
    std::cout << "---->";
    std::cout << std::string(padding, ' ') << msg << std::string(padding, ' ');
    std::cout << "<----" << std::endl;
}

void subjectTest(void)
{
    printBanner("SUBJECT TEST");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    pressEnter();
}

void limitsMateriaSourceTest(void)
{
    printBanner("SOURCE LIMITS");
    pressEnter();

    MateriaSource* source = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    printBanner("ADD MATERIA");
    AMateria* mat;
    for (int i = 0; i < 7; i++)
    {
        mat = source->createMateria("ice");
        source->learnMateria(mat);
        std::cout << "trying to add materia " << i << " to the source"
                  << std::endl;
    }
    pressEnter();

    printBanner("DISPLAY THE SOURCE");
    std::cout << *source << std::endl;
    pressEnter();

    printBanner("DISPLAY THE FLOOR");
    Floor::displayList();
    pressEnter();

    printBanner("DESTRUCTION");
    delete source;
    pressEnter();
}

void deepCopyTestSource()
{
    printBanner("SRC DEEP COPY");
    pressEnter();

    MateriaSource* source = new MateriaSource();
    MateriaSource* source2 = new MateriaSource();
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());

    printBanner("BEFORE THE COPY");
    std::cout << *source2 << std::endl;
    pressEnter();

    printBanner("AFTER THE COPY");
    *source2 = *source;
    std::cout << *source2 << std::endl;
    pressEnter();

    delete source;
    delete source2;
}

void deepCopyTestSCharacter()
{
    printBanner("CHAR DEEP COPY");
    pressEnter();

    MateriaSource* source = new MateriaSource();
    Character* john = new Character("John");
    Character* jack = new Character("Jack");

    source->learnMateria(new Ice());
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        jack->equip(source->createMateria("ice"));
    }

    printBanner("BEFORE COPY");
    std::cout << *jack << std::endl;
    std::cout << *john << std::endl;
    pressEnter();

    printBanner("AFTER COPY");
    *john = *jack;
    std::cout << *jack << std::endl;
    std::cout << *john << std::endl;
    pressEnter();

    delete source;
    delete john;
    delete jack;
}

int main(void)
{
    clearScreen();
    subjectTest();
    limitsMateriaSourceTest();
    deepCopyTestSource();
    deepCopyTestSCharacter();

    return (EXIT_SUCCESS);
}
