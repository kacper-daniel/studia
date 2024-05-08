#include <iostream>

class Vector3d{
    public:
        double x;
        double y;
        double z;
        Vector3d(double a, double b, double c){
            x = a;
            y = b;
            z = c;
        }
        void print(){
            std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
        };
        Vector3d scalarMulti(double a, Vector3d v);
};

Vector3d add(Vector3d v, Vector3d w){
    return Vector3d(v.x + w.x, v.y + w.y, v.z + w.z);
}

Vector3d Vector3d::scalarMulti(double a, Vector3d v){
    return Vector3d(v.x*a, v.y*a, v.z*a);
}

double dotProduct(Vector3d v, Vector3d w){
    return v.x*w.x + v.y*w.y + v.z*w.z;
}

bool isParallel(Vector3d v, Vector3d w){
    if ((v.y*w.z - v.z*w.y == 0) && (v.z*w.x - v.x*w.z == 0) && (v.x*w.y - v.y*w.x == 0)){
        return true;
    }
    else{
        return false;
    }
}

bool isPerpendicular(Vector3d v, Vector3d w){
    if (dotProduct(v, w) == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    double v1, v2, v3, w1, w2, w3, a;
    std::cin >> v1;
    std::cin >> v2;
    std::cin >> v3;
    std::cin >> w1;
    std::cin >> w2;
    std::cin >> w3;
    std::cin >> a;
    Vector3d v(v1, v2, v3);
    Vector3d w(w1, w2, w3);

    std::cout << "av = ";
    v.scalarMulti(a, v).print();

    std::cout << "v + w = ";
    add(v, w).print();

    std::cout << "v ◦ w = " << dotProduct(v, w) << std::endl;

    if (isParallel(v, w) == false){
        std::cout << "v i w nie sa rownolegle" << std::endl; 
    }
    else{
        std::cout << "v i w sa rownolegle" << std::endl;
    }

    if(isPerpendicular(v, w) == false){
        std::cout << "v i w nie sa prostopadle" << std::endl;
    }
    else{
        std::cout << "v i w sa prostopadle" << std::endl;
    }
    
    return 0;
}