#include <iostream>
using namespace std;

void trajektoria(int n){
    int len = 0;
    while (n > 1){
        len += 1;
        cout << n << " ";
        if (n%2 == 0){
            n /= 2;
        } else {
            n = 3*n + 1;
        }
    }
    cout << 1 << ", " << len+1;
}

int main(){
    int x;
    cin >> x;
    trajektoria(x);
    return 0;
}