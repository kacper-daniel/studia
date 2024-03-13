#include <iostream>
#include <map>
using namespace std;
map<int,int> init;

int fib_rec(int n, map<int,int> cache = init){
    if (n <= 2){
        return 1; 
    }
    else if (cache.count(n)){
        return cache[n];
    }
    
    cache[n] = fib_rec(n-2, cache) + fib_rec(n-1, cache);
    return cache[n];
}

int main(){
    clock_t start, end;
    int x;
    cin >> x;
    start = clock();
    cout << fib_rec(x) << endl; // dla x = 40 obliczenia trwały u mnie 123 sekundy
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << time_taken;
    cout << " sec " << endl;
    return 0;
}