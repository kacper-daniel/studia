#include <iostream>
using namespace std;

int main(){
    int array[999] = {};
    for(int i = 0; i <= 999; i++){
        int x;
        cin >> x;
        array[i] = x;
    }
    int y;
    cin >> y;
    bool found = false;
    int i = 0;
    while(!found && i <= 999){
        if (array[i] == y){
            cout << "TAK" << endl;
            found = true;
        }
        i++;
    }
    if (!found){
        cout << "NIE" << endl;
    }
    return 0;
}