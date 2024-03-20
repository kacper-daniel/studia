#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "podaj startowa liczbe zapalek: ";
    cin >> n;
    int i = 1;
    while (n>0){
        int x;
        if (i%2 != 0){
            cout << "gracz 1: ";
        } else {
            cout << "gracz 2: ";
        }
        cin >> x;
        n -= x;
        i++;
    }
    cout << "przegrywa gracz " << (i%2)+1 << endl;
    return 0;
}