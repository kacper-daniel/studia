// Kacper Daniel
#include <iostream>

int main(){
    int a = 30;
    int b = 30;
    std::cout << std::to_string(a) << " " << std::to_string(b) << std::endl;

    // cwiczenie 2
    int x = 20;
    int y = 5;
    int z = 3;
    std::cout << 2*x*y << std::endl;
    std::cout << 2*x + y << std::endl;
    std::cout << 2+x*y << std::endl;
    std::cout << 2+x/y*z << std::endl;
    std::cout << 2+x*y/z << std::endl;

    // cwiczenie 3 
    int p = 5;
    int r, s;
    r = s = p;
    std::cout << r << std::endl;
    // operator przypisania jest prawostronnie łączny

    // cwiczenie 4
    std::cout << "cwiczenie 4" << std::endl;
    int m, n;
    std::cin >> m;
    std::cin >> n;
    std::cout << 3*(m+n) << std::endl;

    // zapisz za pomoca operatorow bitowych i "+" wyrazenie x-y
    std::cout << ~y << std::endl;
    std::cout << x + ~y + 1 << std::endl; 

    return 0;
}