#include <iostream>
using namespace std;

void cw_1(){
    int array[20] = {};
    int res_i = 0;
    for(int i = 0; i < 20; i++){
        array[i] = i+1;
        res_i += array[i] * array[i]; 
    }
    cout << res_i << "\n";
    int res_p = 0;
    int* end = array + 20;
    for (int* curr = array; curr != end; ++curr){
        int val = *curr;
        res_p += val * val;
    }
    cout << res_p << "\n";
}   

int nwd_rec(int a, int b){
    if (a == b){
        return a;
    } else if (a > b){
        return nwd_rec(a -= b, b);
    } else {
        return nwd_rec(a, b -= a);
    }
}

void swap_ref(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_ptr(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    cw_1();
    cout << nwd_rec(76, 38) << endl;
    int x = 20;
    int y = 10;
    swap_ref(x, y);
    cout << "zamiana przy uzyciu referencji - x: " << x << " y: " << y << endl;
    swap_ptr(&x, &y);
    cout << "zamiana przy uzyciu wskaznikow - x: " << x << " y: " << y << endl;

    return 0;
}