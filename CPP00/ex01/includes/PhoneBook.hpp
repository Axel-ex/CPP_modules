/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:58:37 by achabrer          #+#    #+#             */
/*   Updated: 2024/04/03 14:39:07 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

#define RED "\033[38;5;196m"
#define YELLOW "\033[38;5;226m"
#define RESET "\033[0m"
#define CLEAR "\033[2J\033[H"

#define MAX_CONTACTS 8
#define TITLE "\t\t-->WELCOME TO YOUR PHONEBOOK!<--\n"
#define ADD_TITLE "\t\t-->ADD<--\n"
#define SEARCH_TITLE "\t\t-->SEARCH<--\n"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void add(void);
        void search(void);

        static void printMenu(void);
        static void printError(std::string msg);

    private:
        Contact _contacts[MAX_CONTACTS];
        int _id;
        void _display(void) const;
};

#endif
