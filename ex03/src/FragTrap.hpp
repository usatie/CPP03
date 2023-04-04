#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 private:
  bool canMove() const;

 protected:
  static const int _defaultHitPoints = 100;
  static const int _defaultEnergyPoints = 100;
  static const int _defaultAttackDamage = 30;

 public:
  FragTrap();
  explicit FragTrap(const std::string& name);
  FragTrap(const FragTrap& f);
  FragTrap& operator=(const FragTrap& f);
  ~FragTrap();
  // member functions
  void highFiveGuys();
};

#endif
