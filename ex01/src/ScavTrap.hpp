#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  static const int InitialHP = 100;
  static const int InitialEP = 50;
  static const int InitialAD = 20;
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
