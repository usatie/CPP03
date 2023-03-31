#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"

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

void printBold(std::string const& str) {
  std::cout << BOLD << str << RESET << std::endl;
}

int main(void) {
  // Orthodox Canonical Form
  printTitle("Orthodox Canonical Form");
  {
    printBold("Default Initialization");
    ClapTrap a;  // Default Initialization (Default constructor)
    printBold("Direct Initialization");
    ClapTrap b("B");  // Direct Initialization (Constructor)
    printBold("Direct Initialization");
    ClapTrap c(b);  // Direct Initialization (Copy constructor)
    printBold("Copy Initialization");
    ClapTrap d = c;  // Copy Initialization (Copy constructor)
    printBold("Copy Assignment");
    a = d;  // (copy assignment operator)
    printBold("Destructor");
  }
  // Attack / no more energy
  {
    printTitle("Attack / no more energy");
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
    printTitle("beRepaired / no more energy");
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
    printTitle("no hitpoint");
    ClapTrap ct("Mike");

    ct.takeDamage(10);
    ct.beRepaired(5);
    ct.attack("foo");
  }
  std::cout << std::endl;
  // no hitpoint
  {
    printTitle("no hitpoint2");
    ClapTrap ct("Rob");

    ct.takeDamage(15);
    ct.beRepaired(5);
    ct.attack("foo");
  }
}
