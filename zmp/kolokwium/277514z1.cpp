#include <iostream>

bool isPrime(int x){
    if(x < 2){
        return false;
    }
    int current = 2;
    while(current*current <= x){
        if (x % current == 0){
            return false;
        }
        current++;
    }
    return true;
}

void allTwins(int n){
    int current = 3;
    while(current + 2 <= n){
        if(isPrime(current) && isPrime(current+2)){
            std::cout << "(" << current << ", " << current+2 << ")" << std::endl;
        }
        current += 2;
    }
}

int main(){
    int n;
    std::cin >> n;

    allTwins(n);
}