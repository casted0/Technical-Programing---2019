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
  for(vector<int>::size_type i = 0; i < coeff_list.size(); i++){
    coeffs[i] = coeff_list[i];
  }
}

vector<double> Poly::get_coeffs() const {
  return this->coeffs;
}

Poly Poly::derivative() const {

  vector<double> coeffs = this->coeffs;
  vector<double> der_coeffs;
  Poly der;
  int size = coeffs.size();

  for(vector<int>::size_type i = 0; i < size; i++){
    
    der_coeffs[i] == coeffs[i] * i;

  }

  der.set_coeffs(der_coeffs);

  return der;

}

double Poly::operator()(double x) const {
  vector<double> coeffs = this->coeffs;
  int size = coeffs.size();
  double res = 0.0;
  for(vector<int>::size_type i; i < size ; i++){
    res += (coeffs.at(i) * x);
  }
  return res;
}


Poly operator+(const Poly& left, const Poly& right){
  vector<double> coeffs;
  Poly res;
  int sL = left.get_coeffs().size();
  int sR = right.get_coeffs().size();
  int size = (sL >= sR) ? sR : sL;
  for(vector<int>::size_type i; i < size ; i++){
    coeffs[i] = left.get_coeffs()[i] + right.get_coeffs()[i];
  }
  res.set_coeffs(coeffs);
  return res;
}

Poly operator-(const Poly& left, const Poly& right){
  vector<double> coeffs;
  Poly res;
  int sL = left.get_coeffs().size();
  int sR = right.get_coeffs().size();
  int size = (sL >= sR) ? sR : sL;
  for(vector<int>::size_type i; i < size; i++){
    coeffs[i] = left.get_coeffs()[i] - right.get_coeffs()[i];
  }
  res.set_coeffs(coeffs);
  return res;
}

Poly operator*(const Poly& left, const Poly& right){
  vector<double> coeffs;
  Poly res;
  for(vector<int>::size_type i; i < left.get_coeffs().size(); i++){
    coeffs[i] = left.get_coeffs()[i] * right.get_coeffs()[i];
  }
  res.set_coeffs(coeffs);
  return res;
}

Poly operator/(const Poly& dividee, const Poly& divisor){
  vector<double> coeffs;
  Poly res;
  for(vector<int>::size_type i; i < dividee.get_coeffs().size(); i++){
    coeffs[i] = dividee.get_coeffs()[i] / divisor.get_coeffs()[i];
  }
  res.set_coeffs(coeffs);
  return res;
}

Poly operator%(const Poly& dividee, const Poly& divisor){
  vector<double> coeffs;
  Poly res;
  for(vector<int>::size_type i; i < dividee.get_coeffs().size(); i++){
    coeffs[i] = dividee.get_coeffs()[i] + divisor.get_coeffs()[i];
  }
  res.set_coeffs(coeffs);
  return res;
}

ostream& operator<<(ostream& os, const Poly& poly) {
  vector<double> coeffs = poly.get_coeffs();
  int size = coeffs.size();
  string str = "";
  string x = "x";
  for(vector<int>::size_type i = 0; i < size-1; i++){
    str = str + to_string(coeffs[i]) + "^" + to_string(i);
  } 
  str = str + to_string(coeffs[size]);
  os << str;
  return os;
}

