#include "ClapTrap.hpp"

#include <iostream>

// Hit points (10), represent the health of the ClapTrap
// Energy points (10)
// Attack damage (0)
void ClapTrap::init(int h = 10, int e = 10, int a = 0) {
  _hitPoints = h;
  _energyPoints = e;
  _attackDamage = a;
}

ClapTrap::ClapTrap() : _name("") {
  std::cout << "[ ClapTrap Default constructor called ]" << std::endl;
  init();
}

ClapTrap::ClapTrap(const std::string& name) : _name(name) {
  std::cout << "[ ClapTrap constructor called ]" << std::endl;
  init();
}

ClapTrap::ClapTrap(const ClapTrap& c) : _name(c._name) {
  std::cout << "[ ClapTrap Copy constructor called ]" << std::endl;
  init(c._hitPoints, c._energyPoints, c._attackDamage);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
  std::cout << "[ ClapTrap Copy assignment operator called ]" << std::endl;
  _name = rhs._name;
  init(rhs._hitPoints, rhs._energyPoints, rhs._attackDamage);
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
  if (!canMove()) {
    return;
  }
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
