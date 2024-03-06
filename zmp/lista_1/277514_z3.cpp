#include <iostream>
using namespace std;

int zeros(int n){
    int res = 0;
    for(int i = 5; n / i >= 1; i *= 5){
        res += n / i;
    }
    return res;
}

int main(){
    int x;
    cin >> x;
    cout << zeros(x);
    return 0;
}