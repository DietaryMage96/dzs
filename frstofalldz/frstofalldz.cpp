#include <iostream>
using namespace std;

class Weight {
private:
     double kg;
public:
    Weight(double k) {
        if (k >= 0) {
            kg = k;
        }
        else {
            kg = 0;
        }
    }
    Weight operator-(const Weight& other) {
        double res = this->kg - other.kg;
        if (res < 0) {
            res = 0;
        }
        return Weight(res);
    }
    bool operator<(const Weight& other) {
        if (this->kg < other.kg) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator==(const Weight& other) {
        if (this->kg == other.kg) {
            return true;
        }
        else {
            return false;
        }
    }
    Weight operator+(double k) {
        return Weight(this->kg + k);
    }
    double getkg() {
        return kg;
    }

};

class Package {
private:
    double tara;
public:
    Package(double t = 0) {
        if (t >= 0) {
            tara = t;
        }
        else {
            tara = 0;
        }
    }

    double get() { 
        return tara; 
    }
};

Weight operator+(Weight w, Package p) {
    return Weight(w.getkg() + p.get());
}
Weight operator+(double k, Weight w) {
    return Weight(k + w.getkg());
}

void tests() {
    cout << fixed;

    try {
        Weight w1(-5);
        cout << "w1 = " << w1.getkg() << " kg (expected 0)\n";
    }
    catch (...) {
        cout << "Error: negative weight failed\n";
    }

    try {
        Weight w2(15.5), w3(10);
        Weight wsum = w2 - w3;
        cout << "15.5 - 10 = " << wsum.getkg() << " kg (expected 5.5)\n";
    }
    catch (...) {
        cout << "Error: subtraction failed\n";
    }

    try {
        Weight w4(5), w5(5.0000000001);

        if (w4 == w5) {
            cout << "w4 == w5 ? true (expected true)\n";
        }
        else {
            cout << "w4 == w5 ? false (expected true)\n";
        }
    }
    catch (...) {
        cout << "Error: equality failed\n";
    }

    try {
        Weight w6(10);
        Weight w7 = w6 + 3.5;
        cout << "10 + 3.5 = " << w7.getkg() << " kg (expected 13.5)\n";
    }
    catch (...) {
        cout << "Error: add double failed\n";
    }

    try {
        Package p1(2.5);
        Weight w8(5);
        Weight gross = w8 + p1;
        cout << "5 + package(2.5) = " << gross.getkg() << " kg (expected 7.5)\n";
    }
    catch (...) {
        cout << "Error: add package failed\n";
    }

    try {
        Weight w9(7);
        Weight w10 = 3 + w9;
        cout << "3 + 7 = " << w10.getkg() << " kg (expected 10)\n";
    }
    catch (...) {
        cout << "Error: symmetry failed\n";
    }

    try {
        Package p2(0);
        Package p3(1000);
        Weight w11(50);

        Weight result1 = w11 + p2;
        cout << "w11 + p2 = " << result1.getkg() << " kg (expected 50)\n";

        Weight result2 = w11 + p3;
        cout << "w11 + p3 = " << result2.getkg() << " kg (expected 1050)\n";
    }
    catch (...) {
        cout << "Error: package extremes failed\n";
    }
}
int main()
{
    tests();
}
// 2-20 (within)