#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  static const int _defaultHitPoints = 100;
  static const int _defaultEnergyPoints = 50;
  static const int _defaultAttackDamage = 20;
  bool canMove() const;

 public:
  ScavTrap();
  explicit ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& s);
  ScavTrap& operator=(const ScavTrap& rhs);
  ~ScavTrap();
  // member functions
  void attack(const std::string& target);
  void guardGate();
};
#endif
