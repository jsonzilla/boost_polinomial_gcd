
#include<stdlib.h>

#include <vector>

#include "poly.h"

using namespace std;

const vector<double> GCD(vector<double>& p, vector<double>& q) {
  vector<double> remainder;

  while (1) {
    remainder = Poly::Division(p, q);
    if (remainder.size() == 0) {
      break;
    }
    else {
      p = q;
      q = remainder;
    }
  }
  return q;
}

int main() {
  cout << "GDC\n";
  vector<double> p = { 2,1,1 };// Poly::get_data();
  vector<double> q = { 1,2,3 }; // Poly::get_data();
  cout << "Polynomial1:";
  Poly::display(p);
  cout << "Polynomial2:";
  Poly::display(p);
  Poly::display(GCD(p, q));
  return 0;
}