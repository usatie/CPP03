#include <iomanip>
#include <iostream>

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define RESET "\033[m"
#define GREEN "\e[0;32m"
#define RED "\e[0;31m"
#define BOLD "\033[1m"

// print title in green color surrounded by '='
void printTitle(std::string const& title) {
  // set color to green
  std::cout << GREEN << BOLD;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // print title at the center
  std::cout << std::setfill(' ') << std::setw(40 - title.length() / 2) << ""
            << title << std::endl;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

void test_diamondtrap() {
  printTitle("DiamondTrap");
  // FragTrap
  // Attack / no more energy
  {
    printTitle("Attack / no more energy");
    DiamondTrap dt("DiamondJohn");

    for (int i = 1; i <= 101; i++) {
      std::cout << i << ": ";
      dt.attack("foo");
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // be repaired / no more energy
  {
    printTitle("be repaired / no more energy");
    DiamondTrap dt("DiamondBob");

    for (int i = 1; i <= 101; i++) {
      std::cout << i << ": ";
      dt.beRepaired(i);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // no hitpoint
  {
    printTitle("no hitpoint");
    DiamondTrap dt("DiamondMike");

    dt.takeDamage(100);
    dt.beRepaired(5);
    dt.attack("foo");
  }
  std::cout << std::endl;
  // no hitpoint
  {
    printTitle("no hitpoint");
    DiamondTrap dt("DiamondRob");

    dt.takeDamage(150);
    dt.beRepaired(5);
    dt.attack("foo");
  }
  std::cout << std::endl;
  // guardGate
  {
    printTitle("guardGate");
    DiamondTrap dt("DiamondSteve");

    dt.guardGate();
  }
  // high five guys
  {
    printTitle("high five guys");
    DiamondTrap dt("DiamondTaro");

    dt.highFiveGuys();
    dt.takeDamage(150);
    dt.highFiveGuys();
  }
  std::cout << std::endl;
  // whoAmI
  {
    printTitle("whoAmI");
    DiamondTrap dt("DiamondJiro");
    DiamondTrap dt2;

    dt.whoAmI();
    dt2.whoAmI();
  }
}

int main(void) { test_diamondtrap(); }
