// https://fs3.itstep.org/api/v1/files/BHb1de_pweiiUeAP04U_WvQmHqFwa0H8?inline=true
// 4 Á‡‚‰‡ÌÌˇ
#include <iostream>
using namespace std;

class book {
public:
    string title;
    string author;
    int year;
    book(string t, string a, int year) : title(t), author(a), year(year) {};
    virtual void info() {
        cout << "Title: " << title <<endl;
        cout << "Author: " << author <<endl;
        cout << "Year: " << year <<endl;
    }
};

class printed : public book{
public:
    int pages;
    printed(string t, string a, int y, int p) : book(t, a, y) {
        pages = p;
    };
    void info() override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Pages: " << pages << endl;
    }
};


class electronic : public book{
public:
    double size;
    electronic(string t, string a, int y, double s) : book(t, a, y) {
        size = s;
    };
    void info() override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Size: " << size << endl;
    }
};

class library {
public:
    book* catalog[100];
    int size=0;
    void add(book* b) {
        if (size < 100) {
            catalog[size] = b;
            size++;
        }
        else {
            cout << "Catalog is full! :(";
        }
    }
    void searcht(string t) {
        for (int i = 0; i < size; i++) {
            if (catalog[i]->title == t) {
                cout << "Found!" << endl;
                catalog[i]->info();
            }
        }
    }
};

class reader {
public:
    string name;
    book* borrowed[5];
    int size=0;
    reader(string n) : name(n) {};
    void borrowb(book* b) {
        if (size < 5) {
            borrowed[size] = b;
            size++;
        }
        else {
            cout << "Return the books you borrowed!";
        }
    }
    void returnb(book* b) {
        for (int i = 0; i < size; i++) {
            if (borrowed[i]->title == b->title) {
                for (int j = i; j < size - 1; j++) {
                    borrowed[j] = borrowed[j + 1];
                }
                size--;
                break;
            }
        }
    }
    void show() {
        for (int i = 0; i < size; i++) {
            borrowed[i]->info();
        }
    }
};
int main()
{
    reader Bob("Bob");
    book HP("Harry Potter and the Philosopherís Stone", "J.K. Rowling", 1997);
    book HP1("Harry Potter and the Chamber of Secrets", "J.K. Rowling", 1998);
    Bob.borrowb(&HP);
    Bob.borrowb(&HP1);
    Bob.show();
    cout << endl;
    Bob.returnb(&HP);
    Bob.show();

    cout << endl;
    cout << "Lb";
    library lib;

    printed p1("Harry Potter and the Philosopherís Stone", "J.K. Rowling", 1997, 223);
    printed p2("Harry Potter and the Chamber of Secrets", "J.K. Rowling", 1998, 251);
    electronic e1("Digital Fortress", "Dan Brown", 1998, 1.5);

    lib.add(&p1);
    lib.add(&p2);
    lib.add(&e1);

    cout << endl;
    lib.searcht("Harry Potter and the Philosopherís Stone");
    lib.searcht("The Da Vinci Code");
}