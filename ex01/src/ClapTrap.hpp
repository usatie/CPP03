#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
 private:
  void init(int h, int e, int a);

 protected:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
  bool canMove() const;

 public:
  ClapTrap();
  explicit ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& c);
  ClapTrap& operator=(const ClapTrap& rhs);
  virtual ~ClapTrap();
  // member functions
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
