#include <iostream>
using namespace std;

// cwiczenie 5
int k_th_bit(int n, int k){
    while(n > 0 && k > 0){
        n /= 2;
        k -= 1;
    }   
    return n % 2;
}

int main(){
    cout << k_th_bit(4, 1) << endl;
    return 0;
}