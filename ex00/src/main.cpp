#include <iostream>

#include "ClapTrap.hpp"

#define RESET "\033[m"
#define G "\e[0;32m"
#define B "\033[1m"
#define R "\e[0;31m"
#define GREEN(s) (std::cout << G << s << RESET << std::endl)
#define BOLD(s) (std::cout << B << s << RESET << std::endl)
#define RED(s) (std::cout << R << s << RESET << std::endl)

int main(void) {
  // Orthodox Canonical Form
  {
    GREEN("Orthodox Canonical Form");
    BOLD("Default Initialization");
    ClapTrap a;  // Default Initialization (Default constructor)
    BOLD("Direct Initialization");
    ClapTrap b("B");  // Direct Initialization (Constructor)
    BOLD("Direct Initialization");
    ClapTrap c(b);  // Direct Initialization (Copy constructor)
    BOLD("Copy Initialization");
    ClapTrap d = c;  // Copy Initialization (Copy constructor)
    BOLD("Copy Assignment");
    a = d;  // (copy assignment operator)
  }
  // Attack / no more energy
  {
    GREEN("Attack / no more energy");
    ClapTrap ct("John");

    for (int i = 1; i <= 11; i++) {
      std::cout << i << ": ";
      ct.attack("foo");
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // be repaired / no more energy
  {
    GREEN("beRepaired / no more energy");
    ClapTrap ct("Bob");

    for (int i = 1; i <= 11; i++) {
      std::cout << i << ": ";
      ct.beRepaired(i);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // no hitpoint
  {
    GREEN("no hitpoint1");
    ClapTrap ct("Mike");

    ct.takeDamage(10);
    ct.beRepaired(5);
    ct.attack("foo");
  }
  std::cout << std::endl;
  // no hitpoint
  {
    GREEN("no hitpoint2");
    ClapTrap ct("Rob");

    ct.takeDamage(15);
    ct.beRepaired(5);
    ct.attack("foo");
  }
}
