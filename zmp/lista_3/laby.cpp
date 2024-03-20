#include <iostream>
using namespace std;

int array_max(int array[], int size){
    if (size > 0){
        int max = array[0];
        for (int i = 0; i < size; i++){
            if(array[i] > max){
                max = array[i];
            }
        }
        return max;
    } 
    return 0;
}

int array_min(int array[], int size){
    if (size > 0){
        int min = array[0];
        for (int i = 0; i < size; i++){
            if(array[i] < min){
                min = array[i];
            }
        }
        return min;
    } 
    return 0;
}

int silnia(int k){
    int x = 1;
    for (int i = 1; i <= k; i++){
        x*= i;
    }
    return x;
}

double cw_2(int n){
    double res = 2.0;
    int factorial = 1;
    for(int i = 2; i <= n; i++){
        factorial *= i;
        res += 1/factorial;
    }
    return res;
}

int main(){
    int* array;
    int size;
    cin >> size;
    array = new int[size];
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }

    cout << "max: " << array_max(array, size) << endl;
    cout << "min: " << array_min(array, size) << endl;

    cout << cw_2(10) << endl;

    return 0;
}