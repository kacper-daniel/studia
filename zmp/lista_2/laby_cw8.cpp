#include <iostream>
#include <vector>
using namespace std;

vector<int> subset;

void subsets(int tab[], int size, int index){
    if(size == index){
        cout << "{ ";
        for(int i = 0; i < subset.size(); i++){
            cout << subset[i] << " ";
        }
        cout << "} ";
    }
    else {
        subset.push_back(tab[index]);
        subsets(tab, size, index+1);
        subset.pop_back();
        subsets(tab, size, index+1);
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
    subsets(tab, size, 0);
    return 0;
}