#include <iostream>
using namespace std;

int nwd(int a, int b){
    while (a != b){
        if (a>b){
            a -=b;
        } else {
            b -= a;
        }
    }
    return a;
}

int euler(int n){
    int res = 0;
    for(int k = 1; k <= n; k++){
        if (nwd(k, n) == 1){
            res += 1;
        }
    }    
    return res;
}

int podpunkt_b(int n){
    int res = 0;
    for(int d = 1; d <= n; d++){
        if (n%d == 0){
            res += euler(d);
        }
    }
    return res;
}

int main(){
    int x;
    cin >> x;
    cout << podpunkt_b(x);
    return 0;
}