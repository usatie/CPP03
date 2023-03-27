#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	// Attack / no more energy
	{
		ClapTrap ct("John") ;

		for ( int i = 1; i <= 11; i++ ) {
			std::cout << i << ": " ;
			ct.attack("foo") ;
		}
		std::cout << std::endl ;
	}
	std::cout << std::endl ;
	// be repaired / no more energy
	{
		ClapTrap ct("Bob") ;

		for ( int i = 1; i <= 11; i++ ) {
			std::cout << i << ": " ;
			ct.beRepaired(i) ;
		}
		std::cout << std::endl ;
	}
	std::cout << std::endl ;
	// no hitpoint
	{
		ClapTrap ct("Mike") ;

		ct.takeDamage(10) ;
		ct.beRepaired(5) ;
		ct.attack("foo") ;
	}
	std::cout << std::endl ;
	// no hitpoint
	{
		ClapTrap ct("Rob") ;

		ct.takeDamage(15) ;
		ct.beRepaired(5) ;
		ct.attack("foo") ;
	}
}
