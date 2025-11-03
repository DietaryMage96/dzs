#include <iostream>
using namespace std;

class Clock {
private:
	int hours;
	int minutes;
public:
	void setTime(int h, int m) {
		this->hours = h;
		this->minutes = m;
	}
	void getTime(int &h, int &m) const {
		h = this->hours;
		m = this->minutes;
	}
	void showTime() {
		cout << "Time: " << this->hours << ":" << this->minutes << endl;
	}
};

class TV {
private:
	int volume;
public:
	void setVolume(int v) {
		this->volume = v;
	}
	int getVolume() const{
		return volume;
	}
	void showVolume() {
		cout << "Volume: " << this->volume << endl;
	}
};

class Library {
private:
	int size;
	string* Books;
public:
	Library(string books[], int si) {
		size = si;
		Books = new string[size];
		for (int i = 0; i < si; i++) {
			Books[i] = books[i];
		}
	}
	int  getBookCount() const {
		return size;
	}
	~Library() {
		delete[] Books;
	}
};

class Cart {
private:
	int size;
	string* goods;
public:
	Cart(string gods[], int s) {
		size = s;
		goods = new string[size];
		for (int i = 0; i < size; i++) {
			goods[i] = gods[i];
		}
	}
	int getCount() const {
		return size;
	}
	~Cart() {
		delete[] goods;
	}
};

class Movie {
private:
	double rating;
	string name;
public:
	Movie(string n, double r) : name(n), rating(r) {};
	string getName() const {
		return name;
	}
	double getRating() const {
		return rating;
	}
};

class ATM {
private:
	double balance;
public:
	ATM(double b) : balance(b) {};
	double getBalance() const {
		return balance;
	}
	bool withdrawal(double sum) {
		if (sum <= balance) {
			balance -= sum;
			return true;
		}
		else {
			return false;
		}
	}
};

class Zoo {
private:
	int size;
	string* animals;
public:
	Zoo(string anmls[], int s) {
		size = s;
		animals = new string[size];
		for (int i = 0; i < size; i++) {
			animals[i] = anmls[i];
		}
	}
	int getAnimalCount() const {
		return size;
	}
	~Zoo() {
		delete[] animals;
	}
};
int main()
{
	/*Clock clock;
	clock.setTime(10, 20);
	clock.showTime();
	Clock clock1;
	int h,m;
	clock.getTime(h, m);
	clock1.setTime(h, m);
	clock1.showTime();*/

	/*TV tv;
	tv.setVolume(10);
	tv.showVolume();
	TV tv1;
	tv1.setVolume(tv.getVolume());
	tv1.showVolume();*/

	/*string books[5] = { "Book1","Book2","Book3","Book4","Book5" };
	Library lib(books,5);
	cout << "Size: " << lib.getBookCount();*/

	/*string goods[6] = { "Apple", "Bread","Tea","Milk","Eggs", "Meat"};
	Cart cart(goods, 6);
	cout << "Count: " << cart.getCount();*/

	/*Movie movie("Joker", 8.3);
	cout << "Name: " << movie.getName() << " Rating: " << movie.getRating() << endl;*/

	/*ATM user1(2134.3);
	cout << "Check balance: " << user1.getBalance() << endl;
	if (user1.withdrawal(100)) {
		cout << "Withdrawn: 100" << endl;
	}
	else {
		cout << "Not enough balance" << endl;
	}
	cout << "Check balance after withdrawal: " << user1.getBalance() << endl;*/

	string animals[4] = { "Lion", "Elephant", "Giraffe", "Monkey" };
	Zoo zoo(animals, 4);
	cout << "Animals in the zoo: " << zoo.getAnimalCount();
}
