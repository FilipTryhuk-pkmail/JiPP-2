//
// Created by anon on 1/10/22.
//
#include <iostream>

template <typename T>
class Test {
private:
    T* sample_ptr;

public:
    Test() {
        sample_ptr = new int;
    };

    ~Test() {
        delete sample_ptr;
        sample_ptr = nullptr;
    };
    Test(const Test &) = delete;
    Test& operator=(const Test &) = delete;
    //Test operator=(const Test t) = delete;
};

class Test2 {
private:
    //T* sample_ptr;
public:
    unsigned int *iterator;
    Test2() {
        iterator = new unsigned int;
        *iterator = 1;
        };
    Test2(const Test2 &t) {
        this->iterator = t.iterator;
        (*iterator)++;
    }
    ~Test2() {
        (*iterator)--;
        if(*iterator < 1) {
            delete iterator;
            iterator = nullptr;
        }
    }
};

int main() {
    //Test t = Test();
    //Test t2 = t;
    Test2 *t3 = new Test2();
    Test2 *t4 = t3;
    std::cout << " " << t3->iterator << " " << t4->iterator << std::endl;
    //delete t3;
    return 0;
}