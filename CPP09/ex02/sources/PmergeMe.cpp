/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:08:42 by achabrer          #+#    #+#             */
/*   Updated: 2024/03/12 13:27:30 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <sstream>

PmergeMe ::PmergeMe(void) {}

PmergeMe ::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe ::~PmergeMe(void) {}

// OPERATOR OVERLOAD
PmergeMe& PmergeMe ::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        _input1 = rhs._input1;
        _input2 = rhs._input2;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& ofs, const std::vector<int>& rhs)
{
    size_t i = -1;

    std::cout << "  ";
    while (++i < rhs.size() && i < 4)
        std::cout << rhs[i] << " ";
    if (i == 4 && rhs.size() > 4)
        std::cout << "[...]" << std::endl;
    return (ofs);
}

// MEMBER FCTS
void PmergeMe ::readArgs(char** argv, int argc)
{
    int i = 0;
    int elem;
    std::string arg;

    while (++i < argc)
    {
        std::stringstream ss(argv[i]);
        while (ss.good())
        {
            ss >> arg;
            try
            {
                elem = std::stoi(arg);
                _input1.push_back(elem);
                _input2.push_back(elem);
            }
            catch (std::invalid_argument& e)
            {
                std::cout << "Invalid argument: " << e.what() << std::endl;
            }
            catch (std::out_of_range& e)
            {
                std::cout << "Out of range: " << e.what() << std::endl;
            }
        }
    }
}

void PmergeMe ::compute(void)
{
    std::chrono::high_resolution_clock::duration t_vec, t_deq;

    std::cout << "Before: " << _input1 << std::endl;
    t_vec = timeExecution("vector");
    t_deq = timeExecution("deque");
    std::cout << "After: " << _input1 << std::endl;

    std::cout << "Time to process a range of " << _input1.size()
              << " with std::vector " << " " << (t_vec).count() << " us"
              << std::endl;
    std::cout << "Time to process a range of " << _input2.size()
              << " with std::deque " << " " << (t_deq).count() << " us"
              << std::endl;
}

std::chrono::high_resolution_clock::duration
PmergeMe ::timeExecution(std::string t_container)
{
    std::chrono::high_resolution_clock::time_point start, end;

    start = std::chrono::high_resolution_clock::now();

    if (t_container == "vector")
        mergeSortVec(_input1);
    else if (t_container == "deque")
        mergeSortDeq(_input2);

    end = std::chrono::high_resolution_clock::now();
    return (std::chrono::duration_cast<std::chrono::microseconds>(end - start));
}

void PmergeMe ::mergeSortVec(std::vector<int>& vec)
{
    size_t size = vec.size();
    std::vector<int> left;
    std::vector<int> right;

    if (size == 1)
        return;

    for (size_t i = 0; i < size; i++)
    {
        if (i < (size / 2))
            left.push_back(vec[i]);
        else
            right.push_back(vec[i]);
    }
    mergeSortVec(left);
    mergeSortVec(right);
    mergeVec(left, right, vec);
}

void PmergeMe ::mergeVec(std::vector<int>& left, std::vector<int>& right,
                         std::vector<int>& origin)
{
    size_t l = 0;
    size_t r = 0;
    size_t o = 0;
    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
            origin[o++] = left[l++];
        else
            origin[o++] = right[r++];
    }
    while (l < left.size())
        origin[o++] = left[l++];
    while (r < right.size())
        origin[o++] = right[r++];
}

void PmergeMe ::mergeSortDeq(std::deque<int>& queue)
{
    size_t size = queue.size();
    std::deque<int> left;
    std::deque<int> right;

    if (size == 1)
        return;

    for (size_t i = 0; i < size; i++)
    {
        if (i < (size / 2))
            left.push_back(queue[i]);
        else
            right.push_back(queue[i]);
    }
    mergeSortDeq(left);
    mergeSortDeq(right);
    mergeDeq(left, right, queue);
}

void PmergeMe ::mergeDeq(std::deque<int>& left, std::deque<int>& right,
                         std::deque<int>& origin)
{
    size_t l = 0;
    size_t r = 0;
    size_t o = 0;

    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
            origin[o++] = left[l++];
        else
            origin[o++] = right[r++];
    }
    while (l < left.size())
        origin[o++] = left[l++];
    while (r < right.size())
        origin[o++] = right[r++];
}
