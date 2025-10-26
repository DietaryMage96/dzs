// https://fs3.itstep.org/api/v1/files/BHb1de_pweiiUeAP04U_WvQmHqFwa0H8?inline=true
// 2 завдання
#include <iostream>
using namespace std;

class parcel {
public:
    int id;
    double weight;
    parcel(int i, double w) : id(i), weight(w) {}
};

class document : public parcel {
public:
    int pages;
    document(int i, double w, int p) : parcel(i, w), pages(p) {}
};

class tech : public parcel {
public:
    int cost; 
    tech(int i, double w, int c) : parcel(i, w), cost(c) {}
};

class courier {
public:
    string name;
    class backpack {
    public:
        string place[3];
        backpack(string item1, string item2, string item3){
            place[0] = item1;
            place[1] = item2;
            place[2] = item3;
        }
        backpack(string items[3]) {
            place[0] = items[0];
            place[1] = items[1];
            place[2] = items[2];
        }
        void show() {
            cout << "Backpack sections: ";
            for (int i = 0; i < 3; i++) cout << place[i] << " ";
            cout << endl;
        }
    };

    backpack b;
    parcel* cparcel = nullptr;
    void connect(parcel* p) {
        cparcel = p;
    }
    courier(string n, string items[3]) : name(n), b(items) {};
    courier(string n, string item1, string item2, string item3) : name(n), b(item1, item2, item3) {};

    void info() {
        cout << "Courier: " << name << endl;
        b.show();
        if (cparcel != nullptr) {
            cout << "Connected parcel ID: " << cparcel->id << ", weight: " << cparcel->weight << endl;
        }
        else
            cout << "No parcel connected.\n";
        cout << endl;
    }
};
int main()
{
    document d1(1, 2.5, 12);
    tech t1(2, 5.8, 2000);

    courier c1("John", "smthg1", "smthg2", "smthg3");
    courier c2("Alex", "small", "bigger", "biggerthenother");

    c1.connect(&d1);
    c2.connect(&t1);

    c1.info();
    c2.info();
}