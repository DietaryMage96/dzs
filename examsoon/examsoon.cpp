//https://fs3.itstep.org/api/v1/files/ue9VHauxkw2CddqBhZBbXh5LJXUwKrhb?inline=true (13-30 включно)

#include <iostream>
#include <vector>
using namespace std;

//class Computer {
//public:
//	class Keyboard {
//	public:
//		int size;
//		Keyboard(int s) : size(s) {};
//		void info() {
//			cout << size << endl;
//		}
//	}; 
//	class Monitor {
//	public:
//		string resolution;
//		Monitor(string r) : resolution(r) {};
//		void info() {
//			cout << resolution << endl;
//		}
//	};
//	
//	Keyboard keyboard;
//	Monitor monitor;
//	Computer(int s, string r) : keyboard(s), monitor(r) {};
//	void info() {
//		keyboard.info();
//		monitor.info();
//	}
//};

//class House {
//public:
//	class Room {
//	public:
//		int size;
//		Room() : size(0) {};
//		Room(int s) : size(s) {};
//		void info() {
//			cout << size << endl;
//		}
//	};
//
//	Room room[3];
//	House(int s[3]){
//		for (int i = 0; i < 3; i++) {
//			room[i] = Room(s[i]);
//		}
//	};
//	void showRooms() {
//		for (int i = 0; i < 3; i++) {
//			room[i].info();
//		}
//	}
//};

//class Human {
//public:
//    class Heart {
//    public:
//        bool heart;
//        Heart(bool h) : heart(h) {}
//        void info() {
//            cout << heart << endl;
//        }
//    };
//
//    Heart human;
//    Human(bool h) : human(h) {}
//
//    void isAlive() {
//        if (human.heart) {
//            cout << "Alive! :)";
//        }
//        else {
//            cout << "Not alive :(";
//        }
//    }
//};

//class Human {
//public:
//	string name;
//	Human(string n) : name(n) {};
//};
//class Student : public Human{
//public:
//	Student(string n) : Human(n) {};
//	void Study() {
//		cout << "Studing";
//	}
//};

//class Human {
//public:
//	string name;
//	Human(string n) : name(n) {};
//};
//class Teacher : public Human {
//public:
//	Teacher(string n) : Human(n) {};
//	void Teach() {
//		cout << "Teaching";
//	}
//};

//class Animal {
//public:
//	string name;
//	Animal(string n) : name(n) {};
//};
//class Cat : public Animal {
//public:
//	Cat(string n) : Animal(n) {};
//
//	void Meow() {
//		cout << "Meow" << endl;
//	}
//};

//class Human {
//public:
//	string name;
//	Human(string n) : name(n) {};
//};
//
//class Policeman : public Human {
//public:
//	Policeman(string n) : Human(n) {};
//
//	void arrest() {
//		cout << "Arresting" << endl;
//	}
//};

//class Human {
//public:
//	string name;
//	Human(string n) : name(n) {
//		cout << "Human constructor" << endl;	
//	};
//};
//
//class Student : public Human {
//public:
//	Student(string n) : Human(n) {
//		cout << "Student constructor" << endl;
//	};
//};

//class A {
//public:
//	A() {};
//	~A(){ 
//		cout << "A destructor" << endl;
//	}
//};
//
//class B : public A {
//public:
//	B() {};
//	~B() {
//		cout << "B destructor" << endl;
//	}
//};

//class Human {
//protected:
//	string name;
//public:
//	Human(string n) : name(n) {};
//};
//
//class Student : public Human {
//public:
//	Student(string n) : Human(n) {};
//	void info() {
//		cout << name << endl;
//	}
//};

//class Base {
//public:
//    string smthg;
//    Base(string s) : smthg(s) {}
//
//    void show() {
//        cout << "Base: " << smthg << endl;
//    }
//};
//class NotBase : public Base {
//public:
//    NotBase(string s) : Base(s) {}
//    void info() {
//        cout << "NotBase: " << smthg << endl;
//    }
//};
//class NotBase1 : protected Base {
//public:
//    NotBase1(string s) : Base(s) {}
//    void info() {
//        cout << "NotBase1: " << smthg << endl;
//    }
//};
//class NotBase2 : private Base {
//public:
//    NotBase2(string s) : Base(s) {}
//    void info() {
//        cout << "NotBase2: " << smthg << endl;
//    }
//};

//class Human {
//public:
//	void sayHello() {
//		cout << "Hello";
//	}
//};
//
//class Student : public Human {
//public:
//};

//class Human{
//public:
//	string name;
//	Human(string n) : name(n) {}
//};
//class Student : public Human {
//public:
//	Student(string n) : Human(n) {}
//	void print() const {
//		cout << name << endl;
//	}
//};
//class Teacher : public Human {
//public:
//	Teacher(string n) : Human(n) {}
//	void print() const {
//		cout << name << endl;
//	}
//};
//class University {
//public:
//	vector<Student> students;
//	vector<Teacher> teachers;
//
//	University(const vector<Student>& s, const vector<Teacher>& t) : students(s), teachers(t) {}
//
//	void print() const {
//		cout << "=== Students ===" << endl;
//		for (int i = 0; i < students.size(); i++) {
//			students[i].print();
//		}
//
//		cout << "\n=== Teachers ===" << endl;
//		for (int i = 0; i < teachers.size(); i++) {
//			teachers[i].print();
//		}
//	}
//};

//class Transport {
//public:
//	void drive() {
//		cout << "Driving";
//	}
//};
//
//class Car : public Transport {
//public:
//};

//class Employee {
//public:
//	void manage() {
//		cout << "Manage";
//	}
//};
//
//class Manager : public Employee {
//public:
//};

//class Animal {
//public:
//	string name;
//	Animal(string n) : name(n) {};
//	void info() {
//		cout << name << endl;
//	}
//};
//
//class Zoo{
//public:
//	vector<Animal> animals;
//	Zoo(const vector<Animal>& an) {
//		animals = an;
//	}
//	void print() {
//		for (int i = 0; i < animals.size(); i++) {
//			animals[i].info();
//		}
//	}
//};

//class Human {
//public:
//	string name;
//	Human(string n) : name(n) {}
//};
//class School {
//public:
//	class Classroom {
//	public:
//		string name;
//		Classroom(string n) : name(n) {}
//	};
//	class Teacher : public Human {
//	public:
//		Classroom classs;
//
//		Teacher(string n, Classroom c) : Human(n), classs(c) {};
//
//		void info() {
//			cout << name << " : " << classs.name << endl;
//		}
//	};
//};

int main()
{
	/*Computer c(12, "1920 x 1080");
	c.info();*/

	/*int a[3] = { 3, 4, 5 };
	House h(a);
	h.showRooms();*/

    /*Human Bib(true);
    Bib.isAlive();*/

	/*Student bib("Bib");
	bib.Study();*/

	/*Teacher bib("Bibcher");
	bib.Teach();*/

	/*Cat bib_cat("Bib`s cat");
	bib_cat.Meow();*/

	/*Policeman bib("Bib (in job)");
	bib.arrest();*/

	//Student bib("Bib (studies)");

	/*B* b = new B();
	delete b;*/

	/*Student bib("Bib");
	bib.info();*/


	/*{
		NotBase a("Public");
		a.show();
		a.info();

		NotBase1 b("Protected");
		// b.show(); // Не доступний
		b.info();

		NotBase2 c("Private");
		// c.show(); // Не доступний
		c.info();
	}*/

	/*Student bib;
	bib.sayHello();*/

	/*vector<Student> s = { Student("Bib"), Student("Bib_friend") };
	vector<Teacher> t = { Teacher("Bib_teacher"), Teacher("Bib_teacher1") };

	University u(s, t);
	u.print();*/

	/*Car car;
	car.drive();*/

	/*Manager manager;
	manager.manage();*/

	/*vector<Animal> a = { Animal("Lion"), Animal("Tiger"), Animal("Penguin") };
	Zoo zoo(a);
	zoo.print();*/

	/*School::Classroom classs("P41");
	School::Teacher teacher("Bibcher", classs);
	teacher.info();*/
}
