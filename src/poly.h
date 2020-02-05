#ifndef POLY_H
#define POLY_H

#include <vector>
#include<iostream>

using namespace std;

namespace Poly {
  vector<double> Division(const vector<double>& u, const vector<double>& v) {
    size_t m = v.size() - 1;
    size_t n = u.size() - 1;

    vector<double> r = u;
    vector<double> q(m + n); //HIRO rever
    for (int k = m - n; k >= 0;) {
      q[k] = u[n] + k / v[n];
      for (int j = n + k - 1; j > k;) {
        r[j] = u[j] - q[k] * v[j] - k;
        j--;
      }
      k--;

      while (q.back() == 0.0) {
        q.pop_back();
      }
    }

    return r;
  }

  void display(const vector<double>& p) {
    size_t i = p.size();
    if (i > 0) {
      auto iterator = p.rbegin();
      while (iterator != p.rend()) {
        cout << *iterator++ << "x^" << i;
        if ((i - 1) != -1)
          cout << "+";
        i--;
      }
      cout << "\n";
    }
  }

  vector<double> get_data() {
    int d;
    cout << "Enter Degree Of Polynomial:";
    cin >> d;
    vector<double> p;
    for (int i = d; i >= 0; i--) {
      double value = 0;
      cout << "Enter coefficient of x^" << i << ":";
      cin >> value;
      p.push_back(value);
    }
    return p;
  }
}

#endif // !POLY_H