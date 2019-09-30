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
    this->coeffs.push_back(coeff_list[i]);
  }
}

vector<double> Poly::get_coeffs() const {
  return this->coeffs;
}

Poly Poly::derivative() const {

  vector<double> coeffs = this->coeffs;
  vector<double> der_coeffs;
  Poly der;
  double temp = 0.0;

  for(vector<int>::size_type i = 0; i < coeffs.size(); i++){
    temp = coeffs.at(i) * i;
    der_coeffs.push_back(temp);
  }

  for(vector<int>::size_type i = 0; i < der_coeffs.size()-1; i++){
    der_coeffs[i] = der_coeffs[i+1];
  }

  der_coeffs.erase (der_coeffs.begin());
  der.set_coeffs(der_coeffs);
  der.prune();
  return der;
}

double Poly::operator()(double x) const {

  vector<double> coeffs = this->coeffs;
  int size = coeffs.size();
  double res = 0.0;
  for(vector<int>::size_type i = 0; i < size ; i++){
    res += (coeffs.at(i) * pow(x, i));
  }
  return res;
}


Poly operator+(const Poly& left, const Poly& right){

  vector<double> coeffs;
  Poly res;
  int sL = left.get_coeffs().size();
  int sR = right.get_coeffs().size();
  int sizeMax, sizeMin;
  if(sL > sR){

    sizeMax = sL;
    sizeMin = sR;

  }else{

    sizeMax = sR;
    sizeMin = sL;

  }

  for(vector<int>::size_type i = 0; i < sizeMax; i++){
    if(i < sizeMin){
      coeffs.push_back(left.get_coeffs().at(i) + right.get_coeffs().at(i));
    }else{
      if(sL == sizeMax){
        coeffs.push_back(left.get_coeffs().at(i));
      }else{
        coeffs.push_back(right.get_coeffs().at(i));
      }
    }
  }

  res.set_coeffs(coeffs);
  res.prune();
  return res;
}

Poly operator-(const Poly& left, const Poly& right){

  vector<double> coeffs;
  Poly res;
  int sL = left.get_coeffs().size();
  int sR = right.get_coeffs().size();
  int sizeMax, sizeMin;
  if(sL > sR){

    sizeMax = sL;
    sizeMin = sR;

  }else{

    sizeMax = sR;
    sizeMin = sL;

  }

  for(vector<int>::size_type i = 0; i < sizeMax; i++){
    if(i < sizeMin){
      coeffs.push_back(left.get_coeffs().at(i) - right.get_coeffs().at(i));
    }else{
      if(sL == sizeMax){
        coeffs.push_back(left.get_coeffs().at(i));
      }else{
        coeffs.push_back(right.get_coeffs().at(i));
      }
    }
  }

  res.set_coeffs(coeffs);
  res.prune();
  return res;
}

Poly operator*(const Poly& left, const Poly& right){

  vector<double> coeffs;
  Poly res;
  int new_size = (left.get_coeffs().size()) + (right.get_coeffs().size()) - 1;

  for (vector<int>::size_type i = 0; i < new_size; i++){

      coeffs.push_back(0.0);

  }

  for (vector<int>::size_type i = 0; i < left.get_coeffs().size(); i++){ 

    for (vector<int>::size_type j = 0; j < right.get_coeffs().size(); j++){

      coeffs[i+j] += left.get_coeffs().at(i) * right.get_coeffs().at(j);

    }

  } 

  res.set_coeffs(coeffs);
  return res;

}

Poly operator/(const Poly& dividee, const Poly& divisor){ // function n / d:

  vector<double> quotient; 
  vector<double> rest;
  double temp = 0.0;
  Poly aux;

  rest = dividee.get_coeffs(); // r ← n
  
  for(vector<int>::size_type i = 0; i < dividee.get_coeffs().size(); i++){ // q ← 0
    quotient.push_back(0);
  }

  // At each step n = d × q + r

  while((rest.size() != 0) && (rest.size() >= divisor.get_coeffs().size() ) ){
    temp = rest.at(rest.size()-1) / divisor.get_coeffs().at(divisor.get_coeffs().size()-1);     // Divide the leading terms
    quotient[quotient.size()-1] + temp;
    for(vector<int>::size_type i = 0; i < rest.size(); i++){
      rest[rest.size()-(1 + i)] - (temp * divisor.get_coeffs().at(divisor.get_coeffs().size()-1));
    }
    //rest = rest − temp * divisor;
  }

  aux.set_coeffs(rest);
  return aux;

}

Poly operator%(const Poly& dividee, const Poly& divisor){

  vector<double> quotient; 
  vector<double> rest;
  double temp = 0.0;
  Poly aux;

  rest = dividee.get_coeffs(); // r ← n
  
  for(vector<int>::size_type i = 0; i < dividee.get_coeffs().size(); i++){ // q ← 0
    quotient.push_back(0);
  }

  // At each step n = d × q + r

  while((rest.size() != 0) && (rest.size() >= divisor.get_coeffs().size() ) ){
    temp = rest.at(rest.size()-1) / divisor.get_coeffs().at(divisor.get_coeffs().size()-1);     // Divide the leading terms
    quotient[quotient.size()-1] + temp;
    for(vector<int>::size_type i = 0; i < rest.size(); i++){
      rest[rest.size()-(1 + i)] - (temp * divisor.get_coeffs().at(divisor.get_coeffs().size()-1));
    }
    //rest = rest − temp * divisor;
  }

  aux.set_coeffs(rest);
  return aux;
}

ostream& operator<<(ostream& os, const Poly& poly) {

  vector<double> coeffs = poly.get_coeffs();
  int size = coeffs.size();
  string str = " ";
  for(vector<int>::size_type i = size-1; i >= 1; i--){
    if(coeffs.at(i) == 0) continue;
    str = str + "(" + to_string(coeffs.at(i)) + "x^" + to_string(i) + ")";
    if(i != 1){
      str = str + " + ";
    }
  } 
  if(coeffs.at(0) != 0){
    str = str + " + " + to_string(coeffs.at(0));
  }
  os << str;
  return os;
}

