#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: ClapTrap {
private:
public:
	FragTrap() ;
	FragTrap( const std::string & name ) ;
	FragTrap(const FragTrap& f) ;
	FragTrap& operator =(const FragTrap& f) ;
	~FragTrap() ;
	// member functions
	void	attack(const std::string& target) ;
	void	takeDamage(unsigned int amount) ;
	void	beRepaired(unsigned int amount) ;
	void	highFiveGuys() ;
} ;

#endif
