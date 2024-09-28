#include <iostream>

template <class T>
class CVector {
    T* ptr;
    int tam;
    int ini;

public:
    CVector() : ptr(nullptr), tam(0), ini(-1) {}

    void resize(int t) {
        T* temp = new T[t];
        for (int i = 0; i < tam; i++) {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;

        tam = t; // 1 - 2 - 3
    };

    void push_back(T v) {
        resize(tam + 1);

        ini++; // 0 - 1 - 2                  --->   ini = 2
        ptr[ini] = v; // 0 - 1 - 2
        //ptr[tam-1] = v;
    };

    void push_front(T v) {
        resize(tam + 1); // 4
        for (int i = tam - 2; i >= 0; i--) { // i = 2, 1 = 1, i = 0
            //i = ini
            ptr[i + 1] = ptr[i]; // 1 = 0 , 2 = 1
            //[10,20,30]      
            //[10,10,20,30]      
        }
        ptr[0] = v;         //[xx,10,20,30]
        ini++; // ini = 3

    };

    void pop_back() {
        resize(tam - 1);
        ini--;
    };

    void pop_front() {
        T* temp = new T[ini];
        for (int i = 0; i < ini; i++) {
            temp[i] = ptr[i];
        }
        delete[] ptr;
        ptr = temp;
        ini--;
        tam--;

    };

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < tam; i++) {
            std::cout << ptr[i] << "  ";
        }
        std::cout << "]" << std::endl;
    };

};


int main() {
    CVector<int> Vector;

    Vector.push_back(11);
    Vector.print();
    Vector.push_back(10);
    Vector.print();
    Vector.push_front(100);
    Vector.print();
    Vector.push_front(400);
    Vector.print();
    Vector.push_back(8);
    Vector.print();
    Vector.push_front(300);
    Vector.print();
    Vector.push_back(2);
    Vector.print();
    Vector.push_front(200);
    Vector.print();

    std::cout << std::endl;

    Vector.pop_back();
    Vector.print();
    Vector.pop_back();
    Vector.print();
}