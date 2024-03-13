#include <iostream>
using namespace std;

int fib_loop(int n){
    if(n < 1){
        return 0;
    } else if (n == 1 || n == 2){
        return 1;
    }
    int chars[n] = {};
    chars[0] = 0;
    chars[1] = 1;
    chars[2] = 1;
    int res = 0;
    for(int i = 3; i<= n; i++){
        res = chars[i-2] + chars[i-1];
        chars[i] = res;
    }
    return res;
}

int main(){
    int x;
    cin >> x;
    cout << fib_loop(x) << endl;
}