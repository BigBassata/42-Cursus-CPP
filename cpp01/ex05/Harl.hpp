/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:41:11 by licohen           #+#    #+#             */
/*   Updated: 2025/07/02 17:49:24 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <fstream>
#include <string>

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain(std::string level);

    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif