/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:11:56 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/04 22:47:22 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN ::RPN(void) {}

RPN ::RPN(const std::string &input) : _input(input) {}

RPN ::RPN(const RPN &src) { *this = src; }

RPN ::~RPN(void) {}

// OPERATOR OVERLOAD
RPN &RPN ::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        _input = rhs._input;
        _token_list = rhs._token_list;
    }
    return (*this);
}

// MEMBER FCT
void RPN ::compute(void)
{
    lexer();
    executor();
}

void RPN ::lexer(void)
{
    std::stringstream ss(_input);
    s_token token;

    std::string tokenString;
    while (std::getline(ss, tokenString, ' '))
    {
        token.content = tokenString;
        getTokenType(token);
        _token_list.push_front(token); // Push tokens to the back of the list
    }
    _token_list.reverse();
}

void RPN ::executor(void)
{
    std::forward_list<s_token>::const_iterator it;
    std::stack<int> tmp;

    for (it = _token_list.begin(); it != _token_list.end(); it++)
    {
        if (it->type == OPERAND)
        {
            tmp.push(std::stoi(it->content));
            continue;
        }
        tmp.push(operate(tmp, it->content));
    }
    std::cout << tmp.top() << std::endl;
}

int RPN ::operate(std::stack<int> &tmp, const std::string &op)
{
    int size = tmp.size();
    if (size < 2)
        throw std::runtime_error("Too few elements on the stack");

    int b = tmp.top();
    tmp.pop();
    int a = tmp.top();
    tmp.pop();

    if (op == "*")
        return (a * b);
    if (op == "/")
        return (a / b);
    if (op == "+")
        return (a + b);
    else
        return (a - b);
}

// HELPER
void RPN ::getTokenType(s_token &token)
{
    std::string cnt = token.content;

    if (cnt == "*" || cnt == "/" || cnt == "-" || cnt == "+")
        token.type = OPERATOR;
    else if (std::isdigit(token.content[0]) && token.content.size() == 1)
        token.type = OPERAND;
    else
        throw InvalidTokenException("Invalid token : " + token.content);
}

void RPN ::printTokenList(void) const
{
    std::forward_list<s_token>::const_iterator it;

    for (it = _token_list.begin(); it != _token_list.end(); it++)
        std::cout << it->content << " : " << it->type << std::endl;
}

const char *RPN ::InvalidTokenException ::what(void) const throw()
{
    return (_err_msg.c_str());
}