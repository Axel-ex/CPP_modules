/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:58:37 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 10:36:54 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

# define MAX_CONTACTS 	8
# define ADD_TITLE		"\t\t-->ADD<--\n"
# define SEARCH_TITLE 	"\t\t-->SEARCH<--\n"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);

		static void	printMenu(void);
		static void	printError(std::string msg);


	private:
		Contact _contacts[MAX_CONTACTS];
		int		_id;
		void	_display(void)	const;
};

#endif