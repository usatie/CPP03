#include <iomanip>
#include <iostream>

#include "ClapTrap.hpp"
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

void test_fragtrap() {
  std::cout << "==================== FragTrap ===================="
            << std::endl;
  printTitle("FragTrap");
  // FragTrap
  // Attack / no more energy
  {
    printTitle("Attack / no more energy");
    FragTrap ft("FragJohn");

    for (int i = 1; i <= 101; i++) {
      std::cout << i << ": ";
      ft.attack("foo");
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // be repaired / no more energy
  {
    printTitle("be repaired / no more energy");
    FragTrap ft("FragBob");

    for (int i = 1; i <= 101; i++) {
      std::cout << i << ": ";
      ft.beRepaired(i);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // no hitpoint
  {
    printTitle("no hitpoint");
    FragTrap ft("FragMike");

    ft.takeDamage(100);
    ft.beRepaired(5);
    ft.attack("foo");
  }
  std::cout << std::endl;
  // no hitpoint
  {
    printTitle("no hitpoint");
    FragTrap ft("FragRob");

    ft.takeDamage(150);
    ft.beRepaired(5);
    ft.attack("foo");
  }
  std::cout << std::endl;
  // high five guys
  {
    printTitle("high five guys");
    FragTrap ft("FragTaro");

    ft.highFiveGuys();
    ft.takeDamage(150);
    ft.highFiveGuys();
  }
}

int main(void) { test_fragtrap(); }
