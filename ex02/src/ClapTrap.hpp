#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
 protected:
  ClapTrap(std::string n, int h, int e, int a);
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;

 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& x);
  ClapTrap& operator=(const ClapTrap& x);
  virtual ~ClapTrap();
  // member functions
  virtual void attack(const std::string& target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
};

#endif
