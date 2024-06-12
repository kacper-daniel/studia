#include <iostream>
// #include <string>
using std::string;

class Konto{
    protected:
        string imie;
        string nazwisko;
        double stan_konta;

    public:
        explicit Konto(string imie = "", string nazwisko= "", double stan_konta = 0){
            imie = imie;
            nazwisko = nazwisko;
            stan_konta = stan_konta;
        }

        virtual void wplata(double kwota){
            stan_konta += kwota;
        }

        virtual void wyplata(double kwota){
            stan_konta -= kwota;
        }

        virtual void sprawdzenieStanuKonta(){
            std::cout << stan_konta << std::endl;
        }
};

class Premium : public Konto{
    private:
        int bonus;

    public: 
        Premium(string imie = "", string nazwisko= "", double stan_konta = 0){
            imie = imie;
            nazwisko = nazwisko;
            stan_konta = stan_konta;
            bonus = 0;
        }

        virtual void wplata(double kwota){
            stan_konta += kwota;
            bonus++;
        }

        virtual void wyplata(double kwota){
            stan_konta -= kwota;
            bonus++;
        }

        virtual void sprawdzenieStanuKonta(){
            std::cout << "Szanowny" << imie << " " << nazwisko << "! Twoj balans to " << stan_konta << " i bonus to " << bonus << std::endl;
        }
};

class Sub_Premium : public Konto{
    public:
        using Konto::Konto;
        virtual void sprawdzenieStanuKonta(){
            std::cout << "Czesc " << imie << " " << nazwisko << "! Twoj balans to " << stan_konta << std::endl;
        }
};

int main(){
    string s1, s2;
    double w1, w2, w3;

    std::cin >> s1;
    std::cin >> s2;
    std::cin >> w1;
    std::cin >> w2;
    std::cin >> w3;

    Premium premium(s1, s2);
    Sub_Premium sub_premium(s1, s2);

    premium.wplata(w1);
    premium.wplata(w2);
    premium.wyplata(w3);

    sub_premium.wplata(w1);
    sub_premium.wplata(w2);
    sub_premium.wyplata(w3);

    premium.sprawdzenieStanuKonta();
    sub_premium.sprawdzenieStanuKonta();

    return 0;
}