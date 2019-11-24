#include <iostream>
using namespace std;

template <typename T> void g(T val) {
    T t = val;
    cout << "&t: " << &t << endl;
    cout << "&val: " << &val << endl;
    val = 10; // ci: error
    t = 20;
}

int main() {
    int i = 100;
    const int ci = 200;
    g(i);
    g(ci);
    g(i*ci);
    g(42);
    cout << "i: " << i << endl;
    cout << "ci: " << ci << endl;
}
