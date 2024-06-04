/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:59:45 by achabrer          #+#    #+#             */
/*   Updated: 2024/06/04 11:59:25 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
    private:
        std::vector<int> _input1;
        std::deque<int> _input2;

    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& src);
        ~PmergeMe(void);

        PmergeMe& operator=(const PmergeMe& rhs);

        void readArgs(char** argv, int argc);
        void compute(void);
        double timeExecution(std::string t_container);

        // MERGE SORT
        void mergeSortVec(std::vector<int>& vec);
        void mergeVec(std::vector<int>& left, std::vector<int>& right,
                      std::vector<int>& origin);

        void mergeSortDeq(std::deque<int>& queue);
        void mergeDeq(std::deque<int>& left, std::deque<int>& right,
                      std::deque<int>& origin);
};

std::ostream& operator<<(std::ostream& ofs, const std::vector<int>& rhs);

bool is_number(const std::string &str);

#endif
