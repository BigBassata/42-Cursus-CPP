/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:56:05 by licohen           #+#    #+#             */
/*   Updated: 2025/07/15 16:16:41 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Include guards ( gardes d'inclusion ). Ces lignes protegent contre l inclusion multiple 
    du meme header. */
#ifndef FIXED_HPP
# define FIXED_HPP

/*  Headers de la bib stand C++. <cstdlib : version c++ de stdlib.h, contient EXIT_SUCCES, 
    malloc, free etc. <iostream> pour std::cout, endl, et flux d entree et de sortie. */
# include <cstdlib>
# include <iostream>

/*  Declaration de la classe. En C++, une classe est un type defini par l utilisateur qui encapsule
    des donnees (attributs) et des fonctions (methodes) qui operent sur ces donnees. */
class Fixed {

/*  Section privee: int _numberValue -> Encapsulation et representation interne. Cet entier stocke 
    la valeur en virgule fixe. Par exemple si l on veut representer 42.75 avec 8 bits frationnaires : 
    - 42.75 x 256 = 10944
    - Donc _numberValue = 10944
    static const int fractionalBitsNb -> 
        - static : cette variable appartient a la classe 
        pas a une instance particuliere. Toutes les instances deFixed partagent la meme valeur,\
        on ne peux pas l initiliser ici, on doit le faire dans le cpp.
        - const : Une fois init, cette valeur ne peut plus changer. Logique, car l on veut que 
        que toutes les instances utilisent le meme format de virugle fixe. 
        - fractionalBitsNb = 8 : On reserve 8 bits pour la partie fractionnaire. Avec un int de 32 bits 
        on a donc 24 bits pour la partie entiere. 
        Pourquoi 8 bits ? C est un bon compromis entre precision et simplicite. On obtient 256 subdivisions
        (2^8) entre chaque entier, soit une precision de 1/256 ~= 0.00039. */
	private:

	int					_numberValue;
	static const int	fractionalBitsNb;

    /*  Section public: Forme canonique de Coplien. Ces quatres declarations constituent la "rule of three"
        en c++. Chaque classe qui gere des ressources doit implementer ces trois fonctions (plus le destructeur)
        Analyse de chaque siganture : 
        - Fixed(void) : constructeur par defaut
            pas de parametre, appele quand on ecrit Fixed a; 
        - Fixed(const Fixed& other) : constructeur de copie
            prend une reference constante vers un autre Fixed, appele quand on ecrit Fixed b(a) ou Fixed b = a;
            const -> ne modifie pas l objet source, & on passe par reference pour eviter une copie inutile. 
        - Fixed& operator=(const Fixed& other) : operateur d affectation
            retourne une reference vers l objet courant, appele quand on ecrit a = b (ou a existe deja)
            Le retour par reference permet le chainage a = b = c; 
        - ~Fixed(void) : Destructeur
            appele automatiquement quand l objet est detruit
            Ici, pas de ressources dynamique, mais c est obligatoire pour la forme canonique.*/
 
	public:

	Fixed(void);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);
    
    /*  Fonctions d acces -> int getRawBits(void) const;void setRawBits(int const raw);
        Accesseurs (getters/setters) : 
        - getRawBits() : Retourne la valeur brute stockee, 
                    const a la fin car cette methode ne modifie pas l objet
        - setRawBits() : Modifie la valeur brute, int const raw, 
                    le parametre ne peut pas etre modifier dans la fonction.*/
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif