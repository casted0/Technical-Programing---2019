#ifndef MYFILE_H
#define MYFILE_H
#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

class Poly {
private:
   vector<double> coeffs;
public:
   void prune();
   void set_coeffs(const vector<double>& coeff_list);
   vector<double> get_coeffs() const;
   Poly derivative() const;
   double operator()(const double x) const;
};

Poly operator+(const Poly& left, const Poly& right);
Poly operator-(const Poly& left, const Poly& right);
Poly operator*(const Poly& left, const Poly& right);
Poly operator/(const Poly& dividee, const Poly& divisor);
Poly operator%(const Poly& dividee, const Poly& divisor);
ostream& operator<<(ostream& os, const Poly& poly);

#endif