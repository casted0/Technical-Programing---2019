#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

class Poly {
private:
   vector<double> coeffs;
   void prune();
public:
   void set_coeffs(const vector<double>& coeff_list);
   vector<double> get_coeffs() const;
   Poly derivative() const;
   double operator()(const double x) const;
};

Poly operator+(const Poly& left, const Poly& right) const;
Poly operator-(const Poly& left, const Poly& right) const;
Poly operator*(const Poly& left, const Poly& right) const;
Poly operator/(const Poly& dividee, const Poly& divisor) const;
Poly operator%(const Poly& dividee, const Poly& divisor) const;
ostream& operator<<(ostream& os, const Poly& poly);
