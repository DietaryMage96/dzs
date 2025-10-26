// https://fs3.itstep.org/api/v1/files/BHb1de_pweiiUeAP04U_WvQmHqFwa0H8?inline=true
// 1 завдання
#include <iostream>
#include <string>
using namespace std;

class human {
private:
	string name;
	int age;
	string ticket;
public:
	human(string n, int a) : name(n), age(a) {
		char start = name[0];
		string end = to_string(age);
		ticket = start + end;
	}
	virtual double discount() {
		return 0;
	}
	string tn() {
		return ticket;
	}
};

class pupil : public human {
public:
	pupil(string n, int a) : human(n,a) {};
	double discount() override{
		return 0.5;
	}
};

class pensioner : public human {
public:
	pensioner(string n, int a) : human(n, a) {};
	double discount() override {
		return 0.3;
	}
};

class visitor {
public:
	double price = 100;
	human* hman;
	visitor(human* h) : hman(h) {};
	double fnlpric() {
		return price * (1 - hman->discount());
	}
	string tv() {
		return hman->tn();
	}
};


int main()
{
	pupil a("Josh", 13);
	pensioner b("Donald", 60);
	human c("Julia", 28);

	visitor v1(&a);
	cout << "Visitor 1 ticket price: " << v1.fnlpric() << " and ticket number: " << v1.tv() << endl;
	visitor v2(&b);
	cout << "Visitor 2 ticket price: " << v2.fnlpric() << " and ticket number: " << v2.tv() << endl;
	visitor v3(&c);
	cout << "Visitor 3 ticket price: " << v3.fnlpric() << " and ticket number: " << v3.tv() << endl;
}