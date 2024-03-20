#include <iostream>
using namespace std;

int main(){
    // dynamiczne alokowanie pamieci

    int* ptr;
    ptr = new int;

    int* arr_ptr;
    int x;
    arr_ptr = new int[x];

    // zwalnianie zaalokowanej pamieci

    delete ptr;
    delete [] arr_ptr;

    return 0;
}