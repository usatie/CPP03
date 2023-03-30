#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  // Attack / no more energy
  {
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
    ClapTrap ct("Mike");

    ct.takeDamage(10);
    ct.beRepaired(5);
    ct.attack("foo");
  }
  std::cout << std::endl;
  // no hitpoint
  {
    ClapTrap ct("Rob");

    ct.takeDamage(15);
    ct.beRepaired(5);
    ct.attack("foo");
  }
  std::cout << std::endl;
  std::cout << "==================== ScavTrap ===================="
            << std::endl;
  // ScavTrap
  // Attack / no more energy
  {
    ScavTrap st("ScavJohn");

    for (int i = 1; i <= 51; i++) {
      std::cout << i << ": ";
      st.attack("foo");
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // be repaired / no more energy
  {
    ScavTrap st("ScavBob");

    for (int i = 1; i <= 51; i++) {
      std::cout << i << ": ";
      st.beRepaired(i);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  // no hitpoint
  {
    ScavTrap st("ScavMike");

    st.takeDamage(100);
    st.beRepaired(5);
    st.attack("foo");
  }
  std::cout << std::endl;
  // no hitpoint
  {
    ScavTrap st("ScavRob");

    st.takeDamage(150);
    st.beRepaired(5);
    st.attack("foo");
  }
  std::cout << std::endl;
  // gate
  {
    ScavTrap st("ScavTaro");

    st.guardGate();
  }
  std::cout << std::endl;
  std::cout << "==================== FragTrap ===================="
            << std::endl;
  // FragTrap
  // Attack / no more energy
  {
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
    FragTrap ft("FragMike");

    ft.takeDamage(100);
    ft.beRepaired(5);
    ft.attack("foo");
  }
  std::cout << std::endl;
  // no hitpoint
  {
    FragTrap ft("FragRob");

    ft.takeDamage(150);
    ft.beRepaired(5);
    ft.attack("foo");
  }
  std::cout << std::endl;
  // gate
  {
    FragTrap ft("FragTaro");

    ft.highFiveGuys();
  }
}
