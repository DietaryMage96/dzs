#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//Task 1

//class Weight {
//private:
//     double kg;
//public:
//    Weight(double k) {
//        if (k >= 0) {
//            kg = k;
//        }
//        else {
//            kg = 0;
//        }
//    }
//    Weight operator-(const Weight& other) const {
//        double res = this->kg - other.kg;
//        if (res < 0) {
//            res = 0;
//        }
//        return Weight(res);
//    }
//    bool operator<(const Weight& other) const {
//        if (this->kg < other.kg) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//
//    bool operator==(const Weight& other) const {
//        if (this->kg == other.kg) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//    Weight operator+(double k) const {
//        return Weight(this->kg + k);
//    }
//    double getkg() {
//        return kg;
//    }
//
//};
//
//class Package {
//private:
//    double tara;
//public:
//    Package(double t = 0) {
//        if (t >= 0) {
//            tara = t;
//        }
//        else {
//            tara = 0;
//        }
//    }
//
//    double get() { 
//        return tara; 
//    }
//};
//
//Weight operator+(Weight w, Package p) {
//    return Weight(w.getkg() + p.get());
//}
//Weight operator+(double k, Weight w) {
//    return Weight(k + w.getkg());
//}
//void testsa() {
//    cout << fixed;
//
//    try {
//        Weight w1(-5);
//        cout << "w1 = " << w1.getkg() << " kg (expected 0)\n";
//    }
//    catch (...) {
//        cout << "Error: negative weight failed\n";
//    }
//
//    try {
//        Weight w2(15.5), w3(10);
//        Weight wsum = w2 - w3;
//        cout << "15.5 - 10 = " << wsum.getkg() << " kg (expected 5.5)\n";
//    }
//    catch (...) {
//        cout << "Error: subtraction failed\n";
//    }
//
//    try {
//        Weight w4(5), w5(5.0000000001);
//
//        if (w4 == w5) {
//            cout << "w4 == w5 ? true (expected true)\n";
//        }
//        else {
//            cout << "w4 == w5 ? false (expected true)\n";
//        }
//    }
//    catch (...) {
//        cout << "Error: equality failed\n";
//    }
//
//    try {
//        Weight w6(10);
//        Weight w7 = w6 + 3.5;
//        cout << "10 + 3.5 = " << w7.getkg() << " kg (expected 13.5)\n";
//    }
//    catch (...) {
//        cout << "Error: add double failed\n";
//    }
//
//    try {
//        Package p1(2.5);
//        Weight w8(5);
//        Weight gross = w8 + p1;
//        cout << "5 + package(2.5) = " << gross.getkg() << " kg (expected 7.5)\n";
//    }
//    catch (...) {
//        cout << "Error: add package failed\n";
//    }
//
//    try {
//        Weight w9(7);
//        Weight w10 = 3 + w9;
//        cout << "3 + 7 = " << w10.getkg() << " kg (expected 10)\n";
//    }
//    catch (...) {
//        cout << "Error: symmetry failed\n";
//    }
//
//    try {
//        Package p2(0);
//        Package p3(1000);
//        Weight w11(50);
//
//        Weight result1 = w11 + p2;
//        cout << "w11 + p2 = " << result1.getkg() << " kg (expected 50)\n";
//
//        Weight result2 = w11 + p3;
//        cout << "w11 + p3 = " << result2.getkg() << " kg (expected 1050)\n";
//    }
//    catch (...) {
//        cout << "Error: package extremes failed\n";
//    }
//}


//Task 2

//class Money {
//private:
//    int uah;
//    int kop;
//
//    void normalize() {
//        if (kop >= 100) {
//            uah += kop / 100;
//            kop %= 100;
//        }
//        else if (kop < 0) {
//            int borrow = (abs(kop) + 99) / 100;
//            uah -= borrow;
//            kop += borrow * 100;
//        }
//    }
//
//public:
//    Money(int u = 0, int k = 0) : uah(u), kop(k) {
//        normalize();
//    }
//
//    Money operator+(const Money& other) const {
//        return Money(uah + other.uah, kop + other.kop);
//    }
//
//    Money operator-(const Money& other) const {
//        return Money(uah - other.uah, kop - other.kop);
//    }
//
//    Money operator*(int a) const {
//        int total = (uah * 100 + kop) * a;
//        return Money(total / 100, total % 100);
//    }
//
//    int getUAH() const {
//        return uah; 
//    }
//    int getKop() const { 
//        return kop;
//    }
//
//    friend ostream& operator<<(ostream& os, const Money& m) {
//        os << m.uah << " UAH " << m.kop << " kop";
//        return os;
//    }
//};
//
//class ExchangeRate {
//private:
//    double rate;
//public:
//    ExchangeRate(double r) : rate(r) {}
//    double getRate() const {
//        return rate; 
//    }
//};
//
//double operator/(const Money& m, const ExchangeRate& ex) {
//    double total = m.getUAH() + m.getKop() / 100.0;
//    double usd = total / ex.getRate();
//    return round(usd * 100) / 100.0;
//}
//
//void testsb() {
//    Money m1(12, 150);
//    cout << m1 << " (13 UAH 50 kop)\n";
//
//    Money m2(5, 75);
//    Money sum = m1 + m2;
//    cout << sum << " (19 UAH 25 kop)\n";
//
//    Money diff = m1 - m2;
//    cout << diff << " (7 UAH 75 kop)\n";
//
//    Money scaled = m2 * 3;
//    cout << scaled << " (17 UAH 25 kop)\n";
//
//    ExchangeRate ex(36.5);
//    double usd = m1 / ex;
//    cout << "m1 in USD = " << usd << " USD (0.37)\n";
//}


//Task 3

//class Vec2 {
//private:
//    double x, y;
//
//public:
//    Vec2();
//
//    Vec2(double x_, double y_) : x(x_), y(y_) {}
//
//    Vec2 operator+(const Vec2& other) const {
//        return Vec2(x + other.x, y + other.y);
//    }
//    Vec2 operator-(const Vec2& other) const {
//        return Vec2(x - other.x, y - other.y);
//    }
//    Vec2 operator-() const {
//        return Vec2(-x, -y);
//    }
//    Vec2 operator*(double s) const {
//        return Vec2(x * s, y * s);
//    }
//    bool operator==(const Vec2& other) const {
//        return (x == other.x && y == other.y);
//    }
//    double getX() const { 
//        return x; 
//    }
//    double getY() const {
//        return y;
//    }
//
//    void show() const {
//        cout << "(" << x << ", " << y << ")";
//    }
//    double length() const {
//        return sqrt(x * x + y * y);
//    }
//    double dot(const Vec2& other) const {
//        return x * other.x + y * other.y;
//    }
//};
//
//class Mat2 {
//private:
//    double angle;
//public:
//    Mat2(double a_deg) {
//        angle = a_deg * 3.14 / 180.0;
//    }
//
//    Vec2 operator*(const Vec2& v) const {
//        double nx = v.getX() * cos(angle) - v.getY() * sin(angle);
//        double ny = v.getX() * sin(angle) + v.getY() * cos(angle);
//        return Vec2(nx, ny);
//    }
//};
//void testc() {
//    Vec2 v1(1, 0);
//    Vec2 v2(0, 1);
//
//    cout << "Original: ";
//    v1.show(); cout << " ³ "; v2.show(); cout << endl;
//
//    Mat2 rot(90);
//
//    Vec2 r1 = rot * v1;
//    Vec2 r2 = rot * v2;
//
//    cout << "Rotate: ";
//    r1.show(); cout << " ³ "; r2.show(); cout << endl;
//
//    cout << "Lenght: " << r1.length() << ", " << r2.length() << endl;
//    cout << "dobutok: " << r1.dot(r2) << endl;
//}

//Task 4

//class Monomial {
//private:
//    double k;
//    int pow;
//public:
//    Monomial(double k_, int pow_) : k(k_), pow(pow_) {}
//
//    double getK() const {
//        return k; 
//    }
//    int getPow() const {
//        return pow; 
//    }
//};
//
//class Poly {
//private:
//    vector<double> c;
//
//    void normalize() {
//        while (!c.empty() && c.back() == 0) {
//            c.pop_back();
//        }
//    }
//
//public:
//    Poly() {}
//    Poly(const vector<double>& c) : c(c) { normalize(); }
//
//    double operator[](int p) const {
//        if (p < 0 || p >= int(c.size())) {
//            return 0;
//        }
//        return c[p];
//    }
//
//    Poly operator+(const Poly& other) const {
//        vector<double> res(max(c.size(), other.c.size()), 0.0);
//        for (size_t i = 0; i < res.size(); i++) {
//            double a;
//            if (i < c.size()) {
//                a = c[i];
//            }
//            else {
//                a = 0;
//            }
//            double b;
//            if (i < other.c.size()) {
//                b = other.c[i];
//            }
//            else {
//                b = 0;
//            }
//            res[i] = a + b;
//        }
//        return Poly(res);
//    }
//
//    Poly operator-(const Poly& other) const {
//        vector<double> res(max(c.size(), other.c.size()), 0.0);
//        for (size_t i = 0; i < res.size(); i++) {
//            double a;
//            if (i < c.size()) {
//                a = c[i]; 
//            }
//            else {
//                a = 0;
//            }
//            double b;
//            if (i < other.c.size()) {
//                b = other.c[i];
//            }
//            else {
//                b = 0;
//            }
//            res[i] = a - b;
//        }
//        return Poly(res);
//    }
//
//    Poly operator*(double k) const {
//        vector<double> res = c;
//        for (size_t i = 0; i < res.size(); i++) {
//            res[i] *= k;
//        }
//        return Poly(res);
//    }
//
//    Poly operator*(const Monomial& m) const {
//        vector<double> res(c.size() + m.getPow(), 0.0);
//        for (size_t i = 0; i < c.size(); i++) {
//            res[i + m.getPow()] = c[i] * m.getK();
//        }
//        return Poly(res);
//    }
//
//    bool operator==(const Poly& other) const {
//        Poly a = *this, b = other;
//        a.normalize();
//        b.normalize();
//        if (a.c.size() != b.c.size()) {
//            return false;
//        }
//        for (size_t i = 0; i < a.c.size(); i++) {
//            if (a.c[i] != b.c[i]) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    void show() const {
//        if (c.empty()) {
//            cout << "0";
//            return;
//        }
//        for (int i = int(c.size()) - 1; i >= 0; i--) {
//            if (c[i] == 0) {
//                continue;
//            }
//            if (i != int(c.size()) - 1 && c[i] > 0) {
//                cout << " + ";
//            }
//            if (i == 0) {
//                cout << c[i];
//            }
//            else if (i == 1) {
//                cout << c[i] << "x";
//            }
//            else {
//                cout << c[i] << "x^" << i;
//            }
//        }
//    }
//
//    bool isZero() const {
//        return c.empty();
//    }
//};
//
//void testsd() {
//    Poly zero1({ 0, 0, 0 });
//    Poly zero2({});
//
//    if (zero1 == zero2) {
//        cout << "zero1 == zero2" << endl;
//    }
//    else {
//        cout << "zero1 != zero2" << endl;
//    }
//
//    if (zero1.isZero()) {
//        cout << "zero1 zero" << endl;
//    }
//    else {
//        cout << "zero1 not zero" << endl;
//    }
//
//    if (zero2.isZero()) {
//        cout << "zero2 zero" << endl;
//    }
//    else {
//        cout << "zero2 not zero" << endl;
//    }
//}


//Task 5


/*
class Duration {
private:
    int64_t sec;

public:
    Duration(int64_t s) : sec(s) {}

    int64_t getSec() const {
        return sec;
    }

    Duration operator+(const Duration& other) const {
        return Duration(sec + other.sec);
    }

    Duration operator-(const Duration& other) const {
        return Duration(sec - other.sec);
    }

    Duration operator*(int k) const {
        return Duration(sec * k);
    }

    bool operator<(const Duration& other) const {
        return sec < other.sec;
    }

    bool operator==(const Duration& other) const {
        return sec == other.sec;
    }
};

class Timestamp {
private:
    int64_t unixTime;

public:
    Timestamp(int64_t t) : unixTime(t) {}

    int64_t getTime() const {
        return unixTime;
    }

    Timestamp operator+(const Duration& d) const {
        return Timestamp(unixTime + d.getSec());
    }

    void show() const {
        cout << "Timestamp: " << unixTime;
    }
};
void testse() {
    int64_t max64 = 9223372036854775807;
    int64_t min64 = -9223372036854775807;

    Duration dMax(max64);
    Duration d1(10);

    Duration sum = dMax + d1;
    if (sum.getSec() < dMax.getSec()) {
        cout << "Error: Duration + Duration" << endl;
    }
    else {
        cout << "Duration + Duration = " << sum.getSec() << endl;
    }

    Timestamp tMax(max64);
    Timestamp tNew = tMax + Duration(10);

    if (tNew.getTime() < tMax.getTime()) {
        cout << "Error: Timestamp + Duration" << endl;
    }
    else {
        cout << "Timestamp + Duration = ";
        tNew.show();
        cout << endl;
    }
}
*/



//Task 6

//class Celsius {
//private:
//    double temp;
//public:
//    explicit Celsius(double t) : temp(t) {}
//
//    Celsius operator+(double d) const {
//        return Celsius(temp + d);
//    }
//
//    Celsius& operator++() {
//        temp += 1;
//        return *this;
//    }
//
//    Celsius& operator--() {
//        temp -= 1;
//        return *this;
//    }
//
//    bool operator<(const Celsius& other) const {
//        return temp < other.temp;
//    }
//
//    bool operator==(const Celsius& other) const {
//        return temp == other.temp;
//    }
//
//    explicit operator double() const {
//        return temp;
//    }
//
//    double getTemp() const {
//        return temp;
//    }
//};
//
//class Fahrenheit {
//private:
//    double temp;
//public:
//    explicit Fahrenheit(double t) : temp(t) {}
//
//    double getTemp() const {
//        return temp;
//    }
//};
//
//bool operator==(const Celsius& c, const Fahrenheit& f) {
//    double f_as_c = (f.getTemp() - 32) * 5 / 9;
//    return c.getTemp() == f_as_c;
//}
//
//bool operator==(const Fahrenheit& f, const Celsius& c) {
//    return c == f;
//}
//
//void testsf() {
//    Celsius c(-40);
//    Fahrenheit f(-40);
//
//    if (c == f) {
//        cout << "-40C == -40F" << endl;
//    }
//    else {
//        cout << "-40C != -40F" << endl;
//    }
//}


//Task 7

//class Color {
//    int r;
//    int g;
//    int b;
//public:
//    Color(int rr = 0, int gg = 0, int bb = 0) {
//        if (rr < 0)
//            rr = 0;
//        if (rr > 255)
//            rr = 255;
//        if (gg < 0) 
//            gg = 0;
//        if (gg > 255)
//            gg = 255;
//        if (bb < 0) 
//            bb = 0;
//        if (bb > 255) 
//            bb = 255;
//        r = rr;
//        g = gg;
//        b = bb;
//    }
//
//    int getR() const { 
//        return r; 
//    }
//    int getG() const { 
//        return g; 
//    }
//    int getB() const { 
//        return b; 
//    }
//
//    Color operator+(const Color& o) const {
//        int nr = r + o.getR();
//        int ng = g + o.getG();
//        int nb = b + o.getB();
//        if (nr > 255) nr = 255;
//        if (ng > 255) ng = 255;
//        if (nb > 255) nb = 255;
//        return Color(nr, ng, nb);
//    }
//
//    Color operator*(double brightness) const {
//        if (brightness < 0.0) {
//            brightness = 0.0;
//        }
//        int nr = int(round(r * brightness));
//        int ng = int(round(g * brightness));
//        int nb = int(round(b * brightness));
//        if (nr > 255) nr = 255;
//        if (ng > 255) ng = 255;
//        if (nb > 255) nb = 255;
//        return Color(nr, ng, nb);
//    }
//
//    bool operator==(const Color& o) const {
//        if (r == o.getR() && g == o.getG() && b == o.getB()) {
//            return true;
//        }
//        return false;
//    }
//
//    void print() const {
//        cout << "Color(";
//        cout << r << "," << g << "," << b;
//        cout << ")";
//    }
//};
//
//class Alpha {
//    double a;
//public:
//    Alpha(double aa = 1.0) {
//        if (aa < 0) {
//            aa = 0;
//        }
//        if (aa > 1) {
//            aa = 1;
//        }
//        a = aa;
//    }
//    double get() const {
//        return a;
//    }
//};
//
//Color operator*(const Color& c, const Alpha& al) {
//    double a = al.get();
//    int nr = int(round(c.getR() * a));
//    int ng = int(round(c.getG() * a));
//    int nb = int(round(c.getB() * a));
//    if (nr < 0) 
//        nr = 0;
//    if (nr > 255) 
//        nr = 255;
//    if (ng < 0) 
//        ng = 0;
//    if (ng > 255)
//        ng = 255;
//    if (nb < 0) 
//        nb = 0;
//    if (nb > 255) 
//        nb = 255;
//    return Color(nr, ng, nb);
//}
//
//void testsg() {
//    Color c1(200, 100, 50);
//    Color c2(100, 200, 220);
//
//    Color sum = c1 + c2;
//    cout << "sum = ";
//    sum.print();
//    cout << endl;
//
//    Color bright = c1 * 2.0;
//    cout << "bright = ";
//    bright.print();
//    cout << endl;
//
//    Color dark = c1 * -1.0;
//    cout << "dark = ";
//    dark.print();
//    cout << endl;
//
//    Alpha a1(1.5);
//    Color p1 = c1 * a1;
//    cout << "c1 * a1= ";
//    p1.print();
//    cout << endl;
//
//    Alpha a2(-0.5);
//    Color p2 = c1 * a2;
//    cout << "c1 * a2= ";
//    p2.print();
//    cout << endl;
//
//    Color out(-10, 300, 500);
//    cout << "constructor test ";
//    out.print();
//    cout << endl;
//}


//Task 8

//class FileSize {
//    long long bytes;
//public:
//    FileSize(long long b = 0) {
//        if (b < 0)
//            b = 0;
//
//        bytes = b;
//    }
//    long long get() const { return bytes; }
//
//    FileSize operator+(const FileSize& o) const {
//        return FileSize(bytes + o.bytes);
//    }
//    FileSize operator-(const FileSize& o) const {
//        long long r = bytes - o.bytes;
//        if (r < 0) r = 0;
//        return FileSize(r);
//    }
//
//    bool operator>(const FileSize& o) const {
//        return bytes > o.bytes;
//    }
//    bool operator==(const FileSize& o) const {
//        return bytes == o.bytes;
//    }
//
//    FileSize operator*(double factor) const {
//        long long r = long long(bytes * factor);
//        if (r < 0) 
//            r = 0;
//        return FileSize(r);
//    }
//
//    FileSize operator>>(int n) const {
//        if (n < 0) 
//            return *this;
//        return FileSize(bytes >> n);
//    }
//
//    void print() const {
//        cout << "FileSize(" << bytes << " bytes)";
//    }
//};
//
//class KiB {
//    long long kb;
//public:
//    KiB(long long k = 0) : kb(k) {}
//    long long get() const { 
//        return kb; 
//    }
//};
//
//FileSize operator+(const FileSize& f, const KiB& k) {
//    return FileSize(f.get() + k.get() * 1024);
//}
//
//void testsh() {
//    FileSize f1(5000000000);
//    FileSize f2(7000000000);
//
//    FileSize sum = f1 + f2;
//    cout << "sum = " << sum.get() << " bytes (12000000000)";
//    cout << endl;
//
//    FileSize diff = f2 - f1;
//    cout << "diff = " << diff.get() << " bytes (2000000000)";
//    cout << endl;
//
//    KiB k1(1048576);
//    FileSize total = f1 + k1;
//    cout << "f1 + k1 = " << total.get() << " bytes (6073741824)\n";
//    cout << endl;
//
//    FileSize half = f2 * 0.5;
//    cout << "half of f2 = " << half.get() << " bytes (3500000000)\n";
//    cout << endl;
//}

//Task 9


//const double p = 3.14;
//class Degrees;
//
//class Angle {
//    double rad;
//public:
//    Angle(double r = 0) : rad(r) {}
//    double get() const { 
//        return rad; 
//    }
//
//    Angle operator+(const Angle& o) const {
//        return Angle(rad + o.rad);
//    }
//    Angle operator-(const Angle& o) const {
//        return Angle(rad - o.rad);
//    }
//    Angle operator*(int n) const {
//        return Angle(rad * n);
//    }
//    Angle operator+() const {
//        return Angle(rad);
//    }
//    Angle operator-() const {
//        return Angle(-rad);
//    }
//};
//
//class Degrees {
//    double deg;
//public:
//    Degrees(double d) : deg(d) {}
//    double get() const { return deg; }
//};
//double norm360(double x) {
//    while (x >= 360) {
//        x = x - 360;
//    }
//    while (x < 0) {
//        x = x + 360;
//    }
//    return x;
//}
//bool operator==(const Angle& a, const Degrees& d) {
//    double a_deg = a.get() * 180 / p;
//    a_deg = norm360(a_deg);
//    double deg2 = norm360(d.get());
//    return a_deg == deg2;
//}
//void testsi() {
//    Angle a1(p);
//    Degrees d1(180);
//    Degrees d2(540);
//    Degrees d3(-180);
//    Degrees d4(900);
//
//    cout << boolalpha << "a1 == d1: " << (a1 == d1) << " (true)" << endl;
//    cout << boolalpha << "a1 == d2: " << (a1 == d2) << " (true)" << endl;
//    cout << boolalpha << "a1 == d3: " << (a1 == d3) << " (true)" << endl;
//    cout << boolalpha << "a1 == d4: " << (a1 == d4) << " (false)" << endl;
//}

//Task 10


//class Probability {
//    double p;
//public:
//    Probability(double val = 0) {
//        if (val < 0) {
//            p = 0;
//        }
//        else if (val > 1) {
//            p = 1;
//        }
//        else {
//            p = val;
//        }
//    }
//
//    double get() const {
//        return p;
//    }
//
//    Probability operator*(const Probability& other) const {
//        return Probability(p * other.p);
//    }
//
//    Probability operator+(const Probability& other) const {
//        return Probability(p + other.p);
//    }
//
//    Probability& operator+=(const Probability& other) {
//        p = p + other.p;
//        if (p > 1) {
//            p = 1;
//        }
//        if (p < 0) {
//            p = 0;
//        }
//        return *this;
//    }
//
//    friend ostream& operator<<(ostream& out, const Probability& pr);
//};
//
//class Odds {
//    double a;
//    double b;
//public:
//    Odds(double x, double y) {
//        a = x;
//        b = y;
//    }
//
//    double get() const {
//        return a / (a + b);
//    }
//};
//
//bool operator==(const Probability& p, const Odds& o) {
//    double smthg = o.get();
//    return p.get() == smthg;
//}
//
//ostream& operator<<(ostream& out, const Probability& pr) {
//    out << pr.get() * 100 << "%";
//    return out;
//}
//
//void testsj() {
//    cout << boolalpha;
//
//    Probability p0(0);
//    Probability p1(1);
//
//    cout << "p0 = " << p0 << " (0%)" << endl;
//    cout << "p1 = " << p1 << " (100%)" << endl;
//
//    Probability mult1 = p0 * p1;
//    cout << "p0 * p1 = " << mult1 << " (0%)" << endl;
//
//    Probability mult2 = p1 * p1;
//    cout << "p1 * p1 = " << mult2 << " (100%)" << endl;
//
//    Probability add1 = p0 + p1;
//    cout << "p0 + p1 = " << add1 << " (100%)" << endl;
//
//    Probability add2 = p1 + p1;
//    cout << "p1 + p1 = " << add2 << " (100%)" << endl;
//
//    Probability x(0.8);
//    Probability y(0.5);
//    x += y;
//    cout << "0.8 += 0.5 => " << x << " (100%)" << endl;
//
//    Odds o1(1, 1);
//    Odds o2(0, 1); 
//    Odds o3(1, 0); 
//
//    cout << "p0 == o2: " << (p0 == o2) << " (true)" << endl;
//    cout << "p1 == o3: " << (p1 == o3) << " (true)" << endl;
//    cout << "p1 == o1: " << (p1 == o1) << " (false)" << endl;
//}


//Task 11


//int nsd(int a, int b) {
//    if (b == 0) {
//        return a;
//    }
//    return nsd(b, a % b);
//}
//
//class Rational {
//    int n;
//    int d;
//public:
//    void simplify() {
//        int g = nsd(abs(n), abs(d));
//        n /= g;
//        d /= g;
//        if (d < 0) {
//            n = -n;
//            d = -d;
//        }
//    }
//
//    Rational(int x = 0, int y = 1) {
//        if (y == 0) {
//            y = 1;
//        }
//        n = x;
//        d = y;
//        simplify();
//    }
//
//    int getN() const { 
//        return n; 
//    }
//    int getD() const {
//        return d; 
//    }
//
//    Rational operator+(const Rational& r) const {
//        int x = n * r.d + r.n * d;
//        int y = d * r.d;
//        return Rational(x, y);
//    }
//
//    Rational operator*(const Rational& r) const {
//        int x = n * r.n;
//        int y = d * r.d;
//        return Rational(x, y);
//    }
//
//    bool operator==(const Rational& r) const {
//        return n * r.d == r.n * d;
//    }
//
//    bool operator<(const Rational& r) const {
//        return n * r.d < r.n * d;
//    }
//
//    Rational operator+(int val) const {
//        return Rational(n + val * d, d);
//    }
//
//    explicit operator double() const {
//        return (double)n / d;
//    }
//
//    void print() const {
//        cout << n << "/" << d;
//    }
//};
//
//class Mixed {
//    int w;
//    Rational f;
//public:
//    Mixed(int x = 0, const Rational& r = Rational()) {
//        w = x;
//        f = r;
//    }
//
//    Mixed operator+(const Rational& r) const {
//        Rational s = f + r;
//        int add = s.getN() / s.getD();
//        int newW = w + add;
//        int newN = s.getN() % s.getD();
//        return Mixed(newW, Rational(newN, s.getD()));
//    }
//
//    void print() const {
//        cout << w << " + ";
//        f.print();
//    }
//};
//
//void testsk() {
//    Rational a(3, 4), b(-2, 3), c(0, 5);
//    cout << "3/4 + -2/3 = "; (a + b).print(); cout << " (expected 1/12)\n";
//    cout << "3/4 * -2/3 = "; (a * b).print(); cout << " (expected -1/2)\n";
//    cout << "0 + 3/4 = "; (c + a).print(); cout << " (expected 3/4)\n";
//
//    Mixed m(2, Rational(3, 4));
//    Mixed n = m + Rational(5, 4);
//    cout << "2+3/4 + 5/4 = "; n.print(); cout << " (expected 4+0/1)\n";
//}


//Task 12

//class Point {
//    double x;
//public:
//    Point(double xx) : x(xx) {}
//    double get() const { return x; }
//};
//
//class Interval {
//    double l, r;
//public:
//    Interval(double ll = 0, double rr = 0) {
//        if (ll <= rr) { l = ll; r = rr; }
//        else { l = rr; r = ll; }
//    }
//
//    Interval operator+(double shift) const {
//        return Interval(l + shift, r + shift);
//    }
//
//    Interval operator&(const Interval& o) const {
//        double nl = l > o.l ? l : o.l;
//        double nr = r < o.r ? r : o.r;
//        if (nl > nr)
//            return Interval(0, 0);
//        return Interval(nl, nr);
//    }
//
//    Interval operator|(const Interval& o) const {
//        double nl = l < o.l ? l : o.l;
//        double nr = r > o.r ? r : o.r;
//        return Interval(nl, nr);
//    }
//
//    bool operator==(const Interval& o) const {
//        return l == o.l && r == o.r;
//    }
//
//    void print() const {
//        cout << "[" << l << "," << r << "]";
//    }
//
//    friend ostream& operator<<(ostream& out, const Interval& i) {
//        if (i.l <= i.r) {
//            out << "true";
//        }
//        else {
//            out << "false";
//        }
//        return out;
//    }
//
//    bool contains(const Point& p) const {
//        return p.get() >= l && p.get() <= r;
//    }
//};
//
//void testsl() {
//    Interval empty(5, 3);
//    Interval point(4, 4);
//    Interval zero(0, 0);
//
//    cout << "empty = ";
//    empty.print();
//    cout << endl;
//
//    cout << "point = ";
//    point.print();
//    cout << endl;
//
//    cout << "zero = ";
//    zero.print();
//    cout << endl;
//
//    cout << "point & empty = ";
//    (point & empty).print();
//    cout << endl;
//
//    cout << "point == zero: ";
//    if (point == zero) {
//        cout << "true";
//    }
//    else {
//        cout << "false";
//    }
//    cout << endl;
//}

//Task 13


//class Vec3 {
//    double x, y, z;
//public:
//    Vec3(double a = 0, double b = 0, double c = 0) {
//        x = a; y = b; z = c;
//    }
//
//    double getX() const {
//        return x; 
//    }
//    double getY() const { 
//        return y;
//    }
//    double getZ() const {
//        return z; 
//    }
//
//    Vec3 operator+(const Vec3& v) const {
//        return Vec3(x + v.x, y + v.y, z + v.z);
//    }
//
//    Vec3 operator-(const Vec3& v) const {
//        return Vec3(x - v.x, y - v.y, z - v.z);
//    }
//
//    Vec3 operator*(double s) const {
//        return Vec3(x * s, y * s, z * s);
//    }
//
//    bool operator==(const Vec3& v) const {
//        double eps = 1e-6;
//        if (fabs(x - v.x) > eps) return false;
//        if (fabs(y - v.y) > eps) return false;
//        if (fabs(z - v.z) > eps) return false;
//        return true;
//    }
//
//    double& operator[](int i) {
//        if (i == 0) 
//            return x;
//        else if (i == 1) 
//            return y;
//        else 
//            return z;
//    }
//};
//
//class Plane {
//    Vec3 n;
//    double d;
//public:
//    Plane(const Vec3& normal, double dist) {
//        n = normal;
//        d = dist;
//    }
//
//    double operator*(const Vec3& v) const {
//        return n.getX() * v.getX() + n.getY() * v.getY() + n.getZ() * v.getZ() - d;
//    }
//};
//void testsm() {
//    Vec3 n(0, 0, 1);
//    Plane p(n, 0);
//
//    Vec3 v1(1, 2, 0);
//    Vec3 v2(0, 0, 1);
//
//    cout << "v1 orthogonal to plane? ";
//    if (fabs(p * v1) < 1e-6) {
//        cout << "true\n";
//    }
//    else {
//        cout << "false\n";
//    }
//
//    cout << "v2 orthogonal to plane? ";
//    if (fabs(p * v2) < 1e-6) {
//        cout << "true\n";
//    }
//    else {
//        cout << "false\n";
//    }
//}


//Task 14


//class Vec2 {
//public:
//    double x, y;
//    Vec2(double xx = 0, double yy = 0) : x(xx), y(yy) {}
//};
//
//class ScalarWrapper {
//public:
//    double val;
//    ScalarWrapper(double v) : val(v) {}
//};
//
//class Mat2 {
//    double m[2][2];
//public:
//    Mat2(double a = 0, double b = 0, double c = 0, double d = 0) {
//        m[0][0] = a; m[0][1] = b;
//        m[1][0] = c; m[1][1] = d;
//    }
//
//    Mat2 operator+(const Mat2& o) const {
//        return Mat2(m[0][0] + o.m[0][0], m[0][1] + o.m[0][1],
//            m[1][0] + o.m[1][0], m[1][1] + o.m[1][1]);
//    }
//
//    Mat2 operator*(const Mat2& o) const {
//        return Mat2(m[0][0] * o.m[0][0] + m[0][1] * o.m[1][0],
//            m[0][0] * o.m[0][1] + m[0][1] * o.m[1][1],
//            m[1][0] * o.m[0][0] + m[1][1] * o.m[1][0],
//            m[1][0] * o.m[0][1] + m[1][1] * o.m[1][1]);
//    }
//
//    Mat2 operator*(const ScalarWrapper& s) const {
//        return Mat2(m[0][0] * s.val, m[0][1] * s.val,
//            m[1][0] * s.val, m[1][1] * s.val);
//    }
//
//    Mat2 operator*(double s) const {
//        return Mat2(m[0][0] * s, m[0][1] * s, m[1][0] * s, m[1][1] * s);
//    }
//
//    Vec2 operator()(const Vec2& v) const {
//        return Vec2(m[0][0] * v.x + m[0][1] * v.y,
//            m[1][0] * v.x + m[1][1] * v.y);
//    }
//
//    bool operator==(const Mat2& o) const {
//        return m[0][0] == o.m[0][0] && m[0][1] == o.m[0][1] &&
//            m[1][0] == o.m[1][0] && m[1][1] == o.m[1][1];
//    }
//};
//
//void testsn() {
//    Mat2 zero;
//    Mat2 id(1, 0, 0, 1);
//
//    cout << "zero + zero == zero? ";
//    if (zero + zero == zero) {
//        cout << "true\n";
//    }
//    else {
//        cout << "false\n";
//    }
//
//    cout << "id + zero == id? ";
//    if (id + zero == id) {
//        cout << "true\n";
//    }
//    else {
//        cout << "false\n";
//    }
//
//    cout << "id * id == id? ";
//    if (id * id == id) {
//        cout << "true\n";
//    }
//    else {
//        cout << "false\n";
//    }
//
//    cout << "zero * id == zero? ";
//    if (zero * id == zero) {
//        cout << "true\n";
//    }
//    else {
//        cout << "false\n";
//    }
//}


//Task 15


//class AsciiBuffer {
//    string s;
//public:
//    AsciiBuffer(const string& str = "") : s(str) {}
//
//    AsciiBuffer operator+(const AsciiBuffer& o) const {
//        return AsciiBuffer(s + o.s);
//    }
//
//    AsciiBuffer operator+(char c) const {
//        return AsciiBuffer(s + c);
//    }
//
//    char& operator[](size_t i) {
//        return s[i];
//    }
//
//    char operator[](size_t i) const {
//        return s[i];
//    }
//
//    bool operator==(const AsciiBuffer& o) const {
//        return s == o.s;
//    }
//
//    void print() const {
//        cout << s;
//    }
//
//    string get() const {
//        return s; 
//    }
//};
//
//class Utf8String {
//    string t;
//public:
//    Utf8String(const string& str) : t(str) {}
//    string get() const {
//        return t; 
//    }
//};
//
//AsciiBuffer operator+(const AsciiBuffer& a, const Utf8String& u) {
//    string out = a.get();
//    for (char c : u.get()) {
//        if ((unsigned char)c < 128)
//            out += c;
//        else
//            out += '?';
//    }
//    return AsciiBuffer(out);
//}
//
//void testso() {
//    AsciiBuffer a1("Hello");
//    Utf8String u1("World");
//    Utf8String u2("Ïðèâ³ò");
//
//    AsciiBuffer res1 = a1 + u1;
//    AsciiBuffer res2 = a1 + u2;
//
//    cout << "a1 + u1 = ";
//    res1.print();
//    cout << endl;
//
//    cout << "a1 + u2 = ";
//    res2.print();
//    cout << endl;
//}


//Task 16


//class Pixel {
//    int r, g, b;
//public:
//    Pixel(int rr = 0, int gg = 0, int bb = 0) {
//        if (rr < 0) rr = 0; if (rr > 255) rr = 255;
//        if (gg < 0) gg = 0; if (gg > 255) gg = 255;
//        if (bb < 0) bb = 0; if (bb > 255) bb = 255;
//        r = rr; g = gg; b = bb;
//    }
//
//    Pixel operator+(const Pixel& o) const {
//        int nr = r + o.r; if (nr > 255) nr = 255;
//        int ng = g + o.g; if (ng > 255) ng = 255;
//        int nb = b + o.b; if (nb > 255) nb = 255;
//        return Pixel(nr, ng, nb);
//    }
//
//    Pixel operator*(double f) const {
//        int nr = int(r * f); if (nr > 255) nr = 255; if (nr < 0) nr = 0;
//        int ng = int(g * f); if (ng > 255) ng = 255; if (ng < 0) ng = 0;
//        int nb = int(b * f); if (nb > 255) nb = 255; if (nb < 0) nb = 0;
//        return Pixel(nr, ng, nb);
//    }
//
//    bool operator==(const Pixel& o) const {
//        return r == o.r && g == o.g && b == o.b;
//    }
//
//    void print() const {
//        cout << "rgb(" << r << "," << g << "," << b << ")";
//    }
//};
//void testsp() {
//    Pixel p1(0, 0, 0);
//    Pixel p2(255, 255, 255);
//
//    Pixel sum = p1 + p2;
//    cout << "0+255 = ";
//    sum.print();
//    cout << endl;
//
//    Pixel over = p2 + p2;
//    cout << "255+255 = "; 
//    over.print(); 
//    cout << endl;
//
//    Pixel bright = p2 * 1.5;
//    cout << "255*1.5 = ";
//    bright.print();
//    cout << endl;
//
//    Pixel dark = p1 * 0.5;
//    cout << "0*0.5 = ";
//    dark.print(); 
//    cout << endl;
//}


//Task 17


//class Sample {
//    double value;
//    double t;
//public:
//    Sample(double v = 0, double time = 0) : value(v), t(time) {}
//
//    double getValue() const {
//        return value; 
//    }
//    double getTime() const { 
//        return t; 
//    }
//
//    double operator-(const Sample& s) const {
//        return value - s.value;
//    }
//
//    bool operator<(const Sample& s) const {
//        return t < s.t;
//    }
//
//    Sample operator+(double shift) const {
//        return Sample(value + shift, t);
//    }
//
//    bool operator==(const Sample& s) const {
//        return value == s.value && t == s.t;
//    }
//
//    void print() const {
//        cout << "(" << value << "," << t << ")";
//    }
//};
//
//class Window {
//    double width;
//public:
//    Window(double w) : width(w) {}
//
//    Sample operator+(const Sample& s) const {
//        return Sample(s.getValue() / 2, s.getTime());
//    }
//};
//void testsq() {
//    Sample s1(10, 0);
//    Sample s2(20, 0.5);
//    Sample s3(30, 2.0);
//
//    if (s1 < s2) {
//        cout << "s1 before s2\n";
//    }
//    else {
//        cout << "s1 not before s2\n";
//    }
//
//    if (s2 < s3) {
//        cout << "s2 before s3\n";
//    }
//    else {
//        cout << "s2 not before s3\n";
//    }
//}


//Task 18

//class Score {
//    double val;
//public:
//    Score(double v = 0) {
//        if (v < 0)
//            val = 0;
//        else if (v > 100)
//            val = 100;
//        else
//            val = v;
//    }
//
//    double get() const {
//        return val; 
//    }
//
//    Score operator+(const Score& s) const {
//        return Score((val + s.val) / 2.0);
//    }
//
//    Score operator/(const Score& s) const {
//        return Score((val + s.val) / 2.0);
//    }
//
//    bool operator>(const Score& s) const {
//        return val > s.val;
//    }
//
//    Score operator+(int x) const {
//        double res = val + x;
//        if (res > 100) 
//            res = 100;
//        if (res < 0)
//            res = 0;
//        return Score(res);
//    }
//
//    void print() const {
//        cout << int(val) << "/100";
//    }
//};
//
//class Weight {
//    double w;
//public:
//    Weight(double x = 1.0) {
//        if (x < 0) 
//            w = 0;
//        else if (x > 1) 
//            w = 1;
//        else 
//            w = x;
//    }
//    double get() const {
//        return w; 
//    }
//};
//
//Score operator*(const Score& s, const Weight& w) {
//    return Score(s.get() * w.get());
//}
//
//void testsr() {
//    Score s1(90);
//    s1 = s1 + 20;
//    cout << "s1 + 20 = ";
//    if (s1.get() > 100) {
//        cout << "overflow!\n";
//    }
//    else {
//        cout << s1.get() << "\n";
//    }
//
//    Score s2(5);
//    s2 = s2 + (-10);
//    cout << "s2 - 10 = ";
//    if (s2.get() < 0) {
//        cout << "underflow!\n";
//    }
//    else {
//        cout << s2.get() << "\n";
//    }
//}


//Task 19 (last :0)


//class Offset {
//    int dx, dy;
//public:
//    Offset(int x = 0, int y = 0) : dx(x), dy(y) {}
//    int getX() const { 
//        return dx; 
//    }
//    int getY() const {
//        return dy; 
//    }
//};
//
//class Cell {
//    int col, row;
//public:
//    Cell(int c = 0, int r = 0) : col(c), row(r) {}
//
//    bool operator==(const Cell& o) const {
//        return col == o.col && row == o.row;
//    }
//
//    bool operator<(const Cell& o) const {
//        if (col < o.col) 
//            return true;
//        if (col == o.col && row < o.row) 
//            return true;
//        return false;
//    }
//
//    Cell operator+(const Cell& o) const {
//        return Cell(col + o.col, row + o.row);
//    }
//
//    Cell operator+(const Offset& off) const {
//        return Cell(col + off.getX(), row + off.getY());
//    }
//
//    Cell operator+(int n) const {
//        return Cell(col + n, row);
//    }
//
//    int operator[](int i) const {
//        if (i == 0) 
//            return col;
//        return row;
//    }
//
//    void print() const {
//        cout << "(" << col << "," << row << ")";
//    }
//};
//
//void testss() {
//    Cell c(5, 5);
//    Offset o(-2, -3);
//
//    Cell a = c + o;
//    cout << "a = "; 
//    a.print();
//    cout << endl;
//
//    Cell b = c + (-3);
//    cout << "b = ";
//    b.print(); 
//    cout << endl;
//
//    Cell d = a + (-1);
//    cout << "d = ";
//    d.print(); 
//    cout << endl;
//}

int main()
{
    //Task 1
    //testsa();

    //Task 2
    //testsb();

    //Task 3
    //testc();

    //Task 4
    //testsd();

    //Task 5
    //testse();

    //Task 6
    //testsf();

    //Task 7
    //testsg();

    //Task 8
    //testsh();

    //Task 9
    //testsi();

    //Task 10
    //testsj();

    //Task 11
    //testsk();

    //Task 12
    //testsl();

    //Task 13
    //testsm();

    //Task 14
    //testsn();

    //Task 15
    //testso();

    //Task 16
    //testsp();

    //Task 17
    //testsq();

    //Task 18
    //testsr();

    //Task 19
    //testss();
}