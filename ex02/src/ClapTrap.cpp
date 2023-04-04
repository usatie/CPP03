#include "ClapTrap.hpp"

#include <iostream>

// Hit points (10), represent the health of the ClapTrap
// Energy points (10)
// Attack damage (0)
ClapTrap::ClapTrap()
    : _name(""),
      _hitPoints(_defaultHitPoints),
      _energyPoints(_defaultEnergyPoints),
      _attackDamage(_defaultAttackDamage) {
  std::cout << "[ ClapTrap Default constructor called ]" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
      _hitPoints(_defaultHitPoints),
      _energyPoints(_defaultEnergyPoints),
      _attackDamage(_defaultAttackDamage) {
  std::cout << "[ ClapTrap constructor called ]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
    : _name(c._name),
      _hitPoints(c._hitPoints),
      _energyPoints(c._energyPoints),
      _attackDamage(c._attackDamage) {
  std::cout << "[ ClapTrap Copy constructor called ]" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
  std::cout << "[ ClapTrap Copy assignment operator called ]" << std::endl;
  if (this == &rhs) {
    return *this;
  }
  _name = rhs._name;
  _hitPoints = rhs._hitPoints;
  _energyPoints = rhs._energyPoints;
  _attackDamage = rhs._attackDamage;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "[ ClapTrap destructor is called ]" << std::endl;
}

bool ClapTrap::canMove() const {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _name << " has no hit points." << std::endl;
    return false;
  }
  if (_energyPoints <= 0) {
    std::cout << "ClapTrap " << _name << " has no energy points." << std::endl;
    return false;
  }
  return true;
}

// Member functions
// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void ClapTrap::attack(const std::string& target) {
  if (!canMove()) {
    return;
  }
  _energyPoints--;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage! Now HP is " << _hitPoints << "."
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!canMove()) {
    return;
  }
  std::cout << "ClapTrap " << _name << " is repaired and gets " << amount
            << " hit points back! Now HP is " << _hitPoints << "." << std::endl;
  _energyPoints--;
  _hitPoints += amount;
}
