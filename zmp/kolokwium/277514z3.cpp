#include <iostream>
#include <cmath>

template <typename T> class Polynomial{
    private:
        int deg;
        T* coefficients;

    public:
        Polynomial(int n = 0);

        void addCoeff(int index, T value){
            coefficients[index] = value;
        }

        T operator()(T value){
            T result;
            for(int i = 0; i < deg; i++){
                result += coefficients[i]*(pow(value, i));
            }
            return result;
        }

        void operator+(Polynomial<T> other){
            if(other.deg > deg){
                T* temp = new T[other.deg]; 
                for(int i = 0; i < other.deg; i++){
                    try {
                        temp[i] = coefficients[i] + other.coefficients[i];
                    }
                    catch () {
                        temp[i] = other.coefficients[i];
                    }
                }
                coefficients = temp;
            }
            else{
                T* temp = new T[deg];
                for(int i = 0; i < deg; i++){
                    try {
                        temp[i] = coefficients[i] + other.coefficients[i];
                    }
                    catch () {
                        temp[i] = coefficients[i];
                    }
                }
                coefficients = temp;
            }
        }

        void operator-(Polynomial<T> other){
            if(other.deg > deg){
                T* temp = new T[other.deg]; 
                for(int i = 0; i < other.deg; i++){
                    try {
                        temp[i] = coefficients[i] - other.coefficients[i];
                    }
                    catch () {
                        temp[i] = other.coefficients[i];
                    }
                }
                coefficients = temp;
            }
            else{
                T* temp = new T[deg];
                for(int i = 0; i < deg; i++){
                    try {
                        temp[i] = coefficients[i] - other.coefficients[i];
                    }
                    catch () {
                        temp[i] = coefficients[i];
                    }
                }
                coefficients = temp;
            }
        }

        Polynomial<T> derivative(){
            T* dx = new T[deg-1];
            for(int i = 1; i < deg; i++){
                dx[i-1] = coefficients[i]*i;
            }
            Polynomial<T> temp = Polynomial(deg-1);
            for(int i = 0; i < deg-1; i++){
                temp.addCoeff(i, dx[i]);
            }
        }

        void print(){
            for(int i = 0; i < deg; i++){
                std::cout << coefficients[i] << "x^" << i;
                if (i < deg -1 ){
                    std::cout << " + "; 
                }
            }
            std::cout << "\n";
        }

};

template <typename T> Polynomial<T>::Polynomial(int n){
    deg = n;
    coefficients = new T[n];
}

int main(){
    int n;
    std::cin >> n;
    Polynomial<double> poly_a(n);

    for(int i = 0; i < n; i++){
        double temp;
        std::cin >> temp;
        poly_a.addCoeff(i, temp);
    }

    int m;
    std::cin >> m;
    Polynomial<double> poly_b(m);

    for(int i = 0; i < m; i++){
        double temp;
        std::cin >> temp;
        poly_b.addCoeff(i, temp);
    }

    double x;
    std::cin >> x;

    poly_a.print();
    poly_b.print();

    poly_a + poly_b;
    poly_a.print()

    Polynomial poly_a_dx = poly_a.derivative();
    poly_a_dx.print();

    std::cout << "a(" << x << ") = " << poly_a(x) << std::endl; 

    return 0;
}