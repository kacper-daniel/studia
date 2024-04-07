#include<iostream>
using namespace std;

int binary_search(int n, int array[], int size){
    int lo = 0;
    int hi = size - 1;
    int mid = (lo + hi) / 2;
    while(lo <= hi){
        if (n == array[mid]){
            return mid;
        } else if (n < array[mid]){
            hi = mid - 1;
        } else if (n > array[mid]){
            lo = mid + 1;
        }
        mid = (lo + hi) / 2;
    }
    return -1;
}

void pivot(int tab[], int size, int p){
    int p_idx = binary_search(p, tab, size);
    int* smaller_tab = new int[size];
    int* greater_tab = new int[size];
    if(p_idx >= 0){
        int j = 0;
        int k = 0;
        for(int i=0; i<size; i++){
            if(tab[i]<p){
                smaller_tab[j] = tab[i];
                j++;
            }
            else if(tab[i]>p){
                greater_tab[k] = tab[i];
                k++;
            }
        }
        for(int i=0; i<size; i++){
            if(i<j){
                tab[i] = smaller_tab[i];
            }
            else if(i == j){
                tab[i] = p;
            }
            else{
                tab[i] = greater_tab[i - j - 1];
            }
        }
    }
    for(int i = 0; i < size; i++){
        cout << tab[i] << " ";
    }
}

int main(){
    int size;
    int* tab;
    cout << "podaj wielkosc tablicy: ";
    cin >> size;
    tab = new int[size];
    cout << "podaj elementy tablicy: " << endl;
    for(int i = 0; i < size; i++){
        cin >> tab[i];
    }

    pivot(tab, size, 5);
    return 0;
}