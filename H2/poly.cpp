#include "poly.h"

/*
Helper function to chop off extra zeros. Treat very small leading coeffs as zeros.
*/
void Poly::prune() {
   double max_coeff_value = 0.;
   for (int i=0;i<coeffs.size();i++)
     max_coeff_value = abs(coeffs[i])>max_coeff_value ? abs(coeffs[i]) : max_coeff_value;
   for (int i=coeffs.size()-1;i>=0;i--) {
      if (abs(coeffs[i])<1e-10*max_coeff_value) coeffs.pop_back();
      else break;
   }
}

void Poly::set_coeffs(const vector<double>& coeff_list) {
  ...add your own code...
}

vector<double> Poly::get_coeffs() const {
  ...add your own code...
}

Poly Poly::derivative() const {
  ...add your own code...
}

double Poly::operator()(double x) const {
  ...add your own code...
}


Poly operator+(const Poly& left, const Poly& right) const {
  ...add your own code...
}

Poly operator-(const Poly& left, const Poly& right) const {
  ...add your own code...
}

Poly operator*(const Poly& left, const Poly& right) const {
  ...add your own code...
}

Poly operator/(const Poly& dividee, const Poly& divisor) const {
  ...add your own code...
}

Poly operator%(const Poly& dividee, const Poly& divisor) const {
  ...add your own code...
}


ostream& operator<<(ostream& os, const Poly& poly) {
  ...add your own code...
   return os;
}

