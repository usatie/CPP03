#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 private:
  std::string _name;

 public:
  DiamondTrap();
  explicit DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& d);
  DiamondTrap& operator=(const DiamondTrap& d);
  ~DiamondTrap();
  void attack(const std::string& target);
  void whoAmI();
};

#endif
