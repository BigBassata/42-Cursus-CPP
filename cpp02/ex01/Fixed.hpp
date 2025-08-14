#ifndef FIXED_HPP
# define FIXED_HPP

# include <cstdlib>
# include <iostream>
# include <cmath>

class Fixed
{
    private:
        	int					_numberValue;
	        static const int	fractionalBitsNb;

    public:
        Fixed(void);
        Fixed(const int intValue);
        Fixed(const float fValue);
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);
        int     toInt(void) const;
        float   toFloat(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);

#endif