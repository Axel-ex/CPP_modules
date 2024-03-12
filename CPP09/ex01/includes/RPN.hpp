/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:59:10 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/04 10:50:55 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <forward_list>
#include <stack>

#define LOG_ERR(str)	std::cerr << str << std::endl

#define	INVALID_TYPE	"Error: invalid token type"

typedef enum t_type
{
	OPERAND,
	OPERATOR,
}	e_type;

typedef	struct t_token
{
	std::string	content;	
	e_type		type;
}	s_token;


class	RPN
{
	private:
		std::forward_list<s_token>	_token_list;
		std::string					_input;

	public:
		RPN( void );
		RPN( const std::string &input );
		RPN( const RPN &src );
		~RPN( void );

		RPN &operator=( const RPN &rhs );

		void	compute( void );
		void	lexer( void );
		void	executor( void );
		int		operate( std::stack<int> &tmp,const std::string &op);

		//helper
		void	getTokenType( s_token &token );
		void	printTokenList( void )	const;


		class	InvalidTokenException : public std::exception
		{
			private:
				std::string _err_msg;

			public:
				InvalidTokenException(std::string msg) : _err_msg(msg){};
				const char	*what( void ) const throw();
				~InvalidTokenException( void ) _NOEXCEPT{};
		};
};

#endif
