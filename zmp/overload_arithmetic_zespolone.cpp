#include <iostream>

using namespace std;

class Zespolone {
  protected:
    float re, im;
  public:
    Zespolone(){};
    Zespolone(float x) : re(x) {};
    Zespolone(float x, float y) : re(x), im(y) {};
    Zespolone operator - (){
      return Zespolone(-re,-im);
    }
    Zespolone operator + (const Zespolone &z){
      return Zespolone(re+z.re,im+z.im);
    }
    void show(){
      cout << re << "+" << im << "i\n";
    }
    Zespolone operator * (const Zespolone &z){
      return Zespolone(re*z.re-im*z.im,re*z.im+im*z.re);
    }
};

int main(){
  Zespolone z(1,2), w(7,5);
  (-z).show();
  (z+w).show();
  (z*w).show();
  return 0;
}