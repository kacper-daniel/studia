#include <iostream>
#include <string>

class Zwierz {
    private:
        std::string imie, rasa;
    public:
        Zwierz(std::string imie="", std::string rasa =""){
            imie = imie;
            rasa = rasa;
        }

        friend std::istream& operator>>(std::istream& cin, Zwierz& z){
            cin >> z.imie >> z.rasa;
            return cin;
        }

        friend std::ostream& operator<<(std::ostream& cout, Zwierz& z){
            cout << "imie: " << z.imie << ", rasa: " << z.rasa;
            z.sound();
            return cout;
        }

        virtual void sound(){
            std::cout << " dzwiek: " << std::endl;
        };
};

class Kot : public Zwierz {
    public:
        virtual void sound(){
            std::cout << " dzwiek: miau" << std::endl;
        }
};

class Pies : public Zwierz {
    public:
        virtual void sound(){
            std::cout << " dzwiek: hau" << std::endl;
        }
};

int main(){
    Kot kot;
    std::cin >> kot;

    Pies pies;
    std::cin >> pies;

    std::cout << kot;
    std::cout << pies;

    return 0;
}