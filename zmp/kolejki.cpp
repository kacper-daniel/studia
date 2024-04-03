#include <iostream>
using namespace std;

struct fav_movie{
    string title;
    int year;
};

struct person{
    string name;
    int age;
    fav_movie f_movie;
};

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

struct Queue{
    Node* front;
    Node* back;

    Queue() : front(nullptr), back(nullptr) {}

    bool is_empty(){
        return (front == nullptr);
    }

    void enqueue(int val){
        Node* new_el = new Node(val);
        if (is_empty()){
            front = new_el;
            back = new_el;
        }
        else{
            back->next=new_el;
            back=new_el;
        }
    }

    int dequeue(){
        if(is_empty()){
            cerr << "kolejka jest pusta" << endl;
            return 1;
        }
        else{
            int val = front->data;
            Node* temp=front;
            front = front->next;
            delete temp;
            return val;
        }
    }
};

int main(){
    fav_movie movie;
    fav_movie* ptr=&movie;
    movie.title = "Super film";
    movie.year = 2000;
    cout << movie.title << " (" << movie.year << ")" << endl;
    cout << (*ptr).title << " (" << (*ptr).year << ")" << endl;
    cout << ptr->title << " (" << ptr->year << ")" << endl;

    person marcin;
    marcin.name="Marcin";
    marcin.age=35;
    marcin.f_movie=movie;
    cout << marcin.f_movie.title << endl;

    Queue kolejka;
    kolejka.enqueue(0);
    kolejka.enqueue(1);
    kolejka.enqueue(2);
    cout << kolejka.dequeue() << " " << kolejka.dequeue() << endl; 
    return 0;
}