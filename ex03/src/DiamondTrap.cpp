#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() {
  std::cout << "[ DiamondTrap Default constructor called ]" << std::endl;
  _name = "";
  ClapTrap::_name = "_clap_name";
  _hitPoints = FragTrap::_defaultHitPoints;
  _energyPoints = ScavTrap::_defaultEnergyPoints;
  _attackDamage = FragTrap::_defaultAttackDamage;
}

DiamondTrap::DiamondTrap(const std::string& name) {
  std::cout << "[ ScavTrap constructor called ]" << std::endl;
  _name = name;
  ClapTrap::_name = name + "_clap_name";
  _hitPoints = FragTrap::_defaultHitPoints;
  _energyPoints = ScavTrap::_defaultEnergyPoints;
  _attackDamage = FragTrap::_defaultAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d) {
  std::cout << "[ DiamondTrap Copy constructor called ]" << std::endl;
  DiamondTrap::operator=(d);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d) {
  std::cout << "[ DiamondTrap Copy assignment operator called ]" << std::endl;
  if (this != &d) {
    ClapTrap::_name = d.ClapTrap::_name;
    _name = d._name;
    _hitPoints = d._hitPoints;
    _energyPoints = d._energyPoints;
    _attackDamage = d._attackDamage;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "[ DiamondTrap destructor is called ]" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap's name is " << _name << std::endl;
  std::cout << "ClapTrap's name is " << ClapTrap::_name << std::endl;
}
