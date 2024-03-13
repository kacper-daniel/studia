#include <iostream>
using namespace std;

/*
    Ile porównań wystarczy w tym przypadku?
        Przy liczbie n wielkości tablicy w najgorszym scenariuszu wystarczy logarytm o podstawie 2 z n porównań 
        (ze względu na złożoność obliczeniową wyszukiwania binarnego)
        Zatem w naszym przypadku gdy n = 1000 
        to wystarczy logarytm o podstawie 2 z 1000 porównań
        (czyli zaokrąglając w górę - bo chcemy liczbę całkowitą - będzie to chyba 10)
*/


bool binary_search(int n, int array[999]){
    int lo = 0;
    int hi = 999;
    int mid = (lo + hi) / 2;
    while(lo <= hi){
        if (n == array[mid]){
            return true;
        } else if (n < array[mid]){
            hi = mid - 1;
        } else if (n > array[mid]){
            lo = mid + 1;
        }
        mid = (lo + hi) / 2;
    }
    return false;
}

int main(){
    int array[999] = {};
    for(int i = 0; i <= 999; i++){
        int x;
        cin >> x;
        array[i] = x;
    }
    int y;
    cin >> y;
    if (binary_search(y, array)){
        cout << "TAK" << endl;
    } else {
        cout << "NIE" << endl;
    }
    return 0;
}