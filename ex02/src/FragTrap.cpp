#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
  std::cout << "[ FragTrap Default constructor called ]" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "[ FragTrap constructor called ]" << std::endl;
}

FragTrap::FragTrap(const FragTrap& f)
    : ClapTrap(f._name, f._hitPoints, f._energyPoints, f._attackDamage) {
  std::cout << "[ FragTrap Copy constructor called ]" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f) {
  std::cout << "[ FragTrap Copy assignment operator called ]" << std::endl;
  _name = f._name;
  _hitPoints = f._hitPoints;
  _energyPoints = f._energyPoints;
  _attackDamage = f._attackDamage;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "[ FragTrap destructor is called ]" << std::endl;
}

// Member functions
void FragTrap::attack(const std::string& target) {
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    return;
  }
  _energyPoints--;
  std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  std::cout << "FragTrap " << _name << " takes " << amount
            << " points of damage! Now HP is " << _hitPoints << "."
            << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    return;
  }
  std::cout << "FragTrap " << _name << " is repaired and gets " << amount
            << " hit points back! Now HP is " << _hitPoints << "." << std::endl;
  _energyPoints--;
  _hitPoints += amount;
}

// This member function displays a positive high fives request on the standard
// output.
void FragTrap::highFiveGuys() {
  std::cout << "FragTrap " << _name
            << " says \"Hey guys, who's up for some high fives? Let's "
               "celebrate our awesomeness!\""
            << std::endl;
}
