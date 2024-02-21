/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:41:25 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 10:36:03 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

# define CLEAR "\033[2J\033[H"

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		
		void		display() 		const;
		std::string	getFirstName()	const;
		std::string	getLastName()	const;
		std::string	getNickname()	const;

		static 		std::string	formatField(std::string field);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
