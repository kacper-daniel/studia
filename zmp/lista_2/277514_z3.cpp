#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]){
    string a = argv[1];
    string b = argv[2];

    if (a.length() != b.length()){
        return false;
    }

    map<char, int> map_a;
    map<char, int> map_b;

    for(int i = 0; i < a.length(); i++){
        map_a[a[i]] += 1;
        map_b[b[i]] += 1;
    }

    bool is_good = true;
    for(auto i : map_a){
        if (i.second != map_b[i.first]){
            cout << "NIE" << endl;
            is_good = false;
            break;
        }
    }

    if (is_good){
        cout << "TAK" << endl;
    }

    return 0;
}