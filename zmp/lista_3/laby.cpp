#include <iostream>
using namespace std;
int cache[1000] = {};

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

int array_max_rec(int array[], int size, int index, int value){
    if (value < array[index]){
        value = array[index];
    }
    if (index > size - 1){
        return value;
    }
    return array_max_rec(array, size, index + 1, value);
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

int silnia_rec(int k){
    if(k == 1){
        return 1;
    }
    if(cache[k] != 0){
        return cache[k];
    }
    cache[k] = silnia_rec(k-1)*k;
    return cache[k];
}

double cw_2(int n){
    double res = 2.0;
    int factorial = 1;
    for(int i = 2; i <= n; i++){
        res += 1/(double)silnia_rec(i);
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
    cout << "max rec: " << array_max_rec(array, size, 1, array[0]) << endl;
    cout << "min: " << array_min(array, size) << endl;

    cout << cw_2(30) << endl;

    return 0;
}