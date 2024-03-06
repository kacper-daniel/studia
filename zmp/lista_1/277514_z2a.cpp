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

int main(){
    int x;
    cin >> x;
    cout << euler(x);
    return 0;
}