#include "poly.h"

int main(void) {
  Poly p1, p2;

  vector<double> cv1={-4, 0, -2, 0, 1}, cv2={-2, 1};

  p1.set_coeffs(cv1);
  p2.set_coeffs(cv2);

  cout << "p1: " << p1 << "\n" << "p2: " <<p2 << "\n" << "p1/p2: " << p1/p2 << "\n" << "p1%p2: " << p1%p2 << "\n";
  cout << "p1*p2 " << p1*p2 << "\n" << "p1+p2: " << p1+p2 << "\n" << "p1-p2: " << p1-p2 << "\n";
  cout << "p1(2.4): " << p1(2.4) << "\n" << "d/dx[p1(x)]: " << p1.derivative() << "\n";
}
