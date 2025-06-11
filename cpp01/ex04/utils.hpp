/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:10:53 by licohen           #+#    #+#             */
/*   Updated: 2025/06/11 16:48:13 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_HPP
#define UTILS_HPP


#include <iostream>
#include <fstream>
#include <string>

class Replace
{
    private:
        static std::string replaceAll(const std::string &content, const std::string &from, const std::string &to);
    public:
        static bool process(const std::string &filename, const std::string &from, const std::string &to);
};

#endif