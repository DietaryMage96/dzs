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
	void getTime(int &h, int &m) {
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
	string Books[];
public:
	Library(string books[]) {
		size = sizeof(books);
		for (int i = 0; i < sizeof(books); i++) {
			Books[i] = books[i];
		}
	}
	int  getBookCount() const {
		return size;
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

	string books[5] = { "Book1","Book2","Book3","Book4","Book5" };
	const Library(books, 5);
}
