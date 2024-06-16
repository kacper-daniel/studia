#include <iostream>
#include <map>

template <typename T> class Multiset{
    private:
        std::map<T, int> pairs;

    public:
        void add(T value, int count = 1){
            pairs[value] += count;
        }

        void remove(T value, int count = 1){
            auto it = pairs.find(value);
            if(it != pairs.end()){
                it->second -= count;
                if(it->second <= 0){
                    pairs.erase(it);
                }
            }
        }

        bool operator==(const Multiset<T>& other) {
            return pairs == other.pairs;
        }

        bool operator!=(const Multiset<T>& other){
            return !(pairs == other.pairs);
        }

        bool isSubset(const Multiset<T>& other){
            for(auto const& [key, val] : pairs){
                auto it = other.pairs.find(key);
                if (it == other.pairs.end() || it->second < pairs[key]){
                    return false;
                }
            }
            return true;
        }

        Multiset<T> operator+(const Multiset<T>& other){
            Multiset result = *this;
            for (auto pair : other.pairs){
                result.add(pair.first, pair.second);
            }
            return result;
        }

        Multiset<T> operator*(const Multiset<T>& other){
            Multiset<T> result;
            for (auto pair : pairs){
                auto it = other.pairs.find(pair.first);
                if(it != other.pairs.end()){
                    result.add(pair.first, std::min(pair.second, it->second));
                }
            }
            return result;
        }

        Multiset<T> operator-(const Multiset<T>& other){
            Multiset<T> result = *this;
            for(auto pair : other.pairs){
                result.remove(pair.first, pair.second);
            }
            return result;
        }

        void print(){
            for(auto const& [key, val] : pairs){
                std::cout << "(" << key << ", " << val << ") ";
            }
        }
};

int main() {
    Multiset<int> multiset1;
    Multiset<int> multiset2;

    int n, k;
    std::cin >> n;
    std::cin >> k;

    for(int i = 0; i < n; i++){
        int temp;
        std::cin>>temp;
        multiset1.add(temp);
    }

    for(int i = 0; i < k; i++){
        int temp;
        std::cin>>temp;
        multiset2.add(temp);
    }

    std::cout << "M1: " << std::endl;
    multiset1.print();

    std::cout << "\nM2: " << std::endl;
    multiset2.print();

    Multiset<int> unionMultiset = multiset1 + multiset2;
    Multiset<int> intersectionMultiset = multiset1 * multiset2;
    Multiset<int> differenceMultiset = multiset1 - multiset2;

    std::cout << "\nM1 + M2: " << std::endl;
    unionMultiset.print();

    std::cout << "\nM1 && M2:" << std::endl;
    intersectionMultiset.print();

    std::cout << "\nM1 \\ M2: " << std::endl;
    differenceMultiset.print();

    std::cout << "\nM1 < M2: " << multiset1.isSubset(multiset2) << std::endl;

    return 0;
}
