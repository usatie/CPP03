#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
 private:
 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& s);
  ScavTrap& operator=(const ScavTrap& s);
  ~ScavTrap();
  // member functions
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void guardGate();
};
#endif
