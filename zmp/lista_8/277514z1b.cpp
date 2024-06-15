#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <iterator>
#include <string>

class Multiset {
public:
    std::multiset<int> elements;

    void add(int element) {
        elements.insert(element);
    }

    void display() const {
        for (int element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    bool isSubsetSumZero() const {
        std::vector<int> vec(elements.begin(), elements.end());
        std::unordered_map<std::string, bool> memo;
        return isSubsetSumZeroRec(vec, vec.size(), 0, memo);
    }

private:
    bool isSubsetSumZeroRec(const std::vector<int>& elements, int n, int sum, std::unordered_map<std::string, bool>& memo) const {
        std::string key = std::to_string(n) + "_" + std::to_string(sum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        if (sum == 0) {
            return true;
        }

        if (n == 0) {
            return false;
        }

        bool exclude = isSubsetSumZeroRec(elements, n - 1, sum, memo);
        bool include = isSubsetSumZeroRec(elements, n - 1, sum - elements[n - 1], memo);

        memo[key] = include || exclude;
        return memo[key];
    }
};

int main() {
    Multiset multiset;

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        multiset.add(temp);
    }

    if (multiset.isSubsetSumZero()) {
        std::cout << "Istnieje podzbiór o sumie zero." << std::endl;
    } else {
        std::cout << "Nie istnieje podzbiór o sumie zero." << std::endl;
    }

    return 0;
}
