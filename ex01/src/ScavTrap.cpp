#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
  std::cout << "[ ScavTrap Default constructor called ]" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  std::cout << "[ ScavTrap constructor called ]" << std::endl;
  _hitPoints = _defaultHitPoints;
  _energyPoints = _defaultEnergyPoints;
  _attackDamage = _defaultAttackDamage;
}

ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s) {
  std::cout << "[ ScavTrap Copy constructor called ]" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
  std::cout << "[ ScavTrap Copy assignment operator called ]" << std::endl;
  ClapTrap::operator=(rhs);
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "[ ScavTrap destructor is called ]" << std::endl;
}

// Member functions
bool ScavTrap::canMove() const {
  if (_hitPoints <= 0) {
    std::cout << "ScavTrap " << _name << " has no hit points." << std::endl;
    return false;
  }
  if (_energyPoints <= 0) {
    std::cout << "ScavTrap " << _name << " has no energy points." << std::endl;
    return false;
  }
  return true;
}

void ScavTrap::attack(const std::string& target) {
  if (!canMove()) return;
  _energyPoints--;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

// display a message informing that ScavTrap is now in Gate keeper mode.
void ScavTrap::guardGate() {
  if (!canMove()) return;
  _energyPoints--;
  std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!"
            << std::endl;
}
