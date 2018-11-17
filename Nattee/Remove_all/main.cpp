#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "student.h"
//#pragma once



int main() {
  CP::list<int> l;
  int n,k;
  std::cout << "n: ";
  std::cin >> n;
  std::cout << "k: "; 
  std::cin >> k;
  while (n > 0) {
    int x;
    std::cin >> x;
    l.push_back(x);
    n--;
  }
  l.remove_all(k);
  l.print();
}

