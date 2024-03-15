/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:38:58 by achabrer          #+#    #+#             */
/*   Updated: 2024/02/26 13:49:38 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm ::ShrubberyCreationForm(const std::string& target)
    : AForm("shrubbery", 145, 137), _target(target)
{
    LOG("Shrubbery constructor called");
}

ShrubberyCreationForm ::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src)
{
    LOG("Shrubbery copy constructor called");
    *this = src;
}

ShrubberyCreationForm ::~ShrubberyCreationForm(void)
{
    LOG("Shrubbery destructor called");
}

ShrubberyCreationForm&
ShrubberyCreationForm ::operator=(const ShrubberyCreationForm& rhs)
{

    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

void ShrubberyCreationForm ::execute(void) const
{
    std::ofstream ofs;

    ofs.open(_target + "_shrubbery", std::ios::out | std::ios::trunc);
    if (!ofs.is_open())
        throw std::runtime_error("Fail to open the file " + _target +
                                 "_shrubbery");
    ofs << "            .        +          .      .          ." << std::endl;
    ofs << "     .            _        .                    ." << std::endl;
    ofs << "  ,              /;-._,-.____        ,-----.__" << std::endl;
    ofs << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
    ofs << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
    ofs << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
    ofs << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ."
        << std::endl;
    ofs << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
    ofs << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
    ofs << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7"
        << std::endl;
    ofs << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/"
        << std::endl;
    ofs << "              \\:  `  X` _| _,\\/\'   .-'" << std::endl;
    ofs << ".               \":._:`\\____  /:'  /      .           ."
        << std::endl;
    ofs << "                    \\::.  :\\/:'  /              +" << std::endl;
    ofs << "   .                 `\\.  /:'  }      ." << std::endl;
    ofs << "           .           ):_(:;   \\           ." << std::endl;
    ofs << "                      /:. _/ ,  |" << std::endl;
    ofs << "                   . (|::.     ,`                  ." << std::endl;
    ofs << "     .                |::.    \\{" << std::endl;
    ofs << "                      |::.\\" << "  \\ `." << std::endl;
    ofs << "                      |:::(\\    |" << std::endl;
    ofs << "              O       |:::/{ }  |                  (o" << std::endl;
    ofs << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`"
        << std::endl;
    ofs << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~"
        << std::endl;
    ofs << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~" << std::endl;
    ofs.close();
}