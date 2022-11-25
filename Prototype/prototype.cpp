#include <iostream>
#include <string>


class Clonable {
    virtual Clonable* clone() = 0;
};

class Object: Clonable {
    private:
        int a;
        int b;
    
    public:
    Object(int a, int b): a(a), b(b) {}

    void method() {
        std::cout << "(a: " << a << ", b: " << b << ")\n";
    }
    Object* clone() override {
        return new Object(a, b);
    }
};


int main() {
    auto obj = new Object(1, 2);
    obj->method();

    auto clone = obj->clone();

    clone->method();

    return 0;
}