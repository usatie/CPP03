#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
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

void test_claptrap() {
  // print test title
  printTitle("ClapTrap test");
  // test orthodox canonical form
  {
    printTitle("test orthodox canonical form");
    ClapTrap ct("John");
    ClapTrap ct2(ct);
    ClapTrap ct3 = ct2;

    ct3 = ct;
  }
  // test attack
  {
    printTitle("test attack");
    ClapTrap ct("John");

    ct.attack("foo");
  }
  // test takeDamage
  {
    printTitle("test takeDamage");
    ClapTrap ct("John");

    ct.takeDamage(5);
  }
  // test beRepaired
  {
    printTitle("test beRepaired");
    ClapTrap ct("John");

    ct.beRepaired(5);
  }
  // test no hitpoint
  {
    printTitle("test no hitpoint");
    ClapTrap ct("John");

    ct.takeDamage(10);
    ct.beRepaired(5);
    ct.attack("foo");
  }
  // test no energy point
  {
    printTitle("test no energy point");
    ClapTrap ct("John");

    for (int i = 1; i <= 11; i++) {
      std::cout << i << ": ";
      ct.attack("foo");
    }
    std::cout << std::endl;
  }
}

void test_scavtrap() {
  // print test title
  printTitle("ScavTrap test");
  // test orthodox canonical form
  {
    printTitle("test orthodox canonical form");
    ScavTrap st("John");
    ScavTrap st2(st);
    ScavTrap st3 = st2;

    st3 = st;
  }
  // test attack
  {
    printTitle("test attack");
    ScavTrap st("John");

    st.attack("foo");
  }
  // test takeDamage
  {
    printTitle("test takeDamage");
    ScavTrap st("John");

    st.takeDamage(5);
  }
  // test beRepaired
  {
    printTitle("test beRepaired");
    ScavTrap st("John");

    st.beRepaired(5);
  }
  // test no hitpoint
  {
    printTitle("test no hitpoint");
    ScavTrap st("John");

    st.takeDamage(100);
    st.beRepaired(5);
    st.attack("foo");
  }
  // test no energy point
  {
    printTitle("test no energy point");
    ScavTrap st("John");

    for (int i = 1; i <= 51; i++) {
      std::cout << i << ": ";
      st.attack("foo");
    }
    std::cout << std::endl;
  }
  // test guardGate
  {
    printTitle("test guardGate");
    ScavTrap st("John");

    st.guardGate();
    st.takeDamage(100);
    st.guardGate();
  }
}

int main(void) {
  test_claptrap();
  test_scavtrap();
}
