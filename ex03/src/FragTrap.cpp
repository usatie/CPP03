#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
  std::cout << "[ FragTrap Default constructor called ]" << std::endl;
  _hitPoints = _defaultHitPoints;
  _energyPoints = _defaultEnergyPoints;
  _attackDamage = _defaultAttackDamage;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  std::cout << "[ FragTrap constructor called ]" << std::endl;
  _hitPoints = _defaultHitPoints;
  _energyPoints = _defaultEnergyPoints;
  _attackDamage = _defaultAttackDamage;
}

FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f) {
  std::cout << "[ FragTrap Copy constructor called ]" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f) {
  std::cout << "[ FragTrap Copy assignment operator called ]" << std::endl;
  ClapTrap::operator=(f);
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "[ FragTrap destructor is called ]" << std::endl;
}

// Member functions
bool FragTrap::canMove() const {
  if (_hitPoints <= 0) {
    std::cout << "FragTrap " << _name << " has no hit points." << std::endl;
    return false;
  }
  if (_energyPoints <= 0) {
    std::cout << "FragTrap " << _name << " has no energy points." << std::endl;
    return false;
  }
  return true;
}
// This member function displays a positive high fives request on the standard
// output.
void FragTrap::highFiveGuys() {
  if (!canMove()) return;
  _energyPoints--;
  std::cout << "FragTrap " << _name
            << " says \"Hey guys, who's up for some high fives? Let's "
               "celebrate our awesomeness!\""
            << std::endl;
}
