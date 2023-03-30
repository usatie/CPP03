#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
  std::cout << "[ ScavTrap Default constructor called ]" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "[ ScavTrap constructor called ]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
    : ClapTrap(s._name, s._hitPoints, s._energyPoints, s._attackDamage) {
  std::cout << "[ ScavTrap Copy constructor called ]" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s) {
  std::cout << "[ ScavTrap Copy assignment operator called ]" << std::endl;
  _name = s._name;
  _hitPoints = s._hitPoints;
  _energyPoints = s._energyPoints;
  _attackDamage = s._attackDamage;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "[ ScavTrap destructor is called ]" << std::endl;
}

// Member functions
void ScavTrap::attack(const std::string& target) {
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    return;
  }
  _energyPoints--;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  std::cout << "ScavTrap " << _name << " takes " << amount
            << " points of damage! Now HP is " << _hitPoints << "."
            << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (_energyPoints <= 0 || _hitPoints <= 0) {
    return;
  }
  std::cout << "ScavTrap " << _name << " is repaired and gets " << amount
            << " hit points back! Now HP is " << _hitPoints << "." << std::endl;
  _energyPoints--;
  _hitPoints += amount;
}

// display a message informing that ScavTrap is now in Gate keeper mode.
void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!"
            << std::endl;
}
