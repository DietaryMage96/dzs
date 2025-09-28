#include <iostream>
#include <string>
using namespace std;
    

class Array {
private:
    int* Data;
    size_t Size;
public:
    Array(int* data, size_t size) {
        this->Size = size;
        this->Data = new int[size];
        for (size_t i = 0; i < size; i++) {
            this->Data[i] = data[i];
        }
    }
    void Copy(int* otherdata, size_t othersize) {
        this->Size = othersize;
        for (int i = 0; i <= othersize + 1; i++) {
            this->Data[i] = otherdata[i];
        }
    }
    void Print() {
        for (size_t i = 0; i < this->Size; i++) {
            cout << this->Data[i] << " ";
        }
        cout << endl;
    }
    ~Array(){
        delete[] this->Data;
    }
};

class Buffer {
private:
    char* buf;
public:
    Buffer(char* buf, size_t size) {
        this->buf = new char[size];
        for (size_t i = 0; i < size; i++) {
            this->buf[i] = buf[i];
        }
    }
    void Copy(char* otherdata, size_t othersize) {
        for (int i = 0; i <= othersize + 1; i++) {
            this->buf[i] = otherdata[i];
        }
    }
    void Print() {
        cout << this->buf << endl;
    }
    ~Buffer() {
        delete[] this->buf;
    }
};

class BadString {
private:
    char* data;
public:
    BadString(char* data) {
        this->data = data;
    }

    ~BadString(){
        delete[] data;
    }
};

class CopyTest {
private:
    int* data;
    size_t size;
public:
    CopyTest(int* arr, size_t n) {
        size = n;
        data = new int[n];
        for (size_t i = 0; i < n; i++) {
            data[i] = arr[i];
        }
    }
    CopyTest(const CopyTest& other) {
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    void Print() {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]: " << this->data[i] << endl;
        }
        cout << endl;
    }
    ~CopyTest() {
        delete[] data;
    }
};

class Book {
private:
    string title;
public:
    Book(string t){
        cout << "Constructor" << endl;
        title = t;
    }

    Book(const Book& other){
        cout << "Copy" << endl;
        title = other.title;
    }

    void Print() const {
        cout << "Method print" << endl;
        cout << "Book: " << title << endl;
    }
};
void printBook(Book b) {
    cout << "Book in the function: " << endl;
    b.Print();
}

class Book1 {
public:
    string title;

    Book1(string t) {
        title = t;
        cout << "Constructor: " << title << endl;
    }

    Book1(const Book1& other) {
        title = other.title;
        cout << "Copy Constructor: " << title << endl;
    }

    Book1(Book1&& other) noexcept {
        title = move(other.title);
        cout << "Move Constructor: " << title << endl;
    }

    ~Book1() {
        cout << "Destructor: " << title << endl;
    }

    void print() {
        cout << "Book title: " << title << endl;
    }
};
Book1 createBook() {
    Book1 b("Something");
    return b;
}
int main()
{

    //Task 1(9)
    /*int data[] = { 1, 2, 3, 4, 5 };
    size_t n = 5;

    Array arr(data, n);
    arr.Print();

    int otherdata[] = { 10, 20, 30 };
    arr.Copy(otherdata, 3);
    arr.Print();*/

    //Task 2(10)
    /*char databuf[] = {"Hello"};
    Buffer buf(databuf, sizeof(databuf));
    buf.Print();

    char databuf1[] = { "Hi" };

    buf.Copy(databuf1,sizeof(databuf1));
    buf.Print();*/

    //Task 3(11)
   /* char text[] = "Hello";
    BadString b1(text);
    BadString b2 = b1;*/
    //Помилка виникає тому що видалення пам'яті відбувається двічі

    //Task 4(12)
    /*int* p = new int[1];
    int* b = p;
    delete[] p;
    delete[] b;*/
    //Помилка, при такому копіюванні вони мають однакову адресу і при видаленні одного об'єкта ломається інший

    //Task 5(13)
    /*const int N = 3;
    int data[N] = { 1,1,2 };
    CopyTest* a = new CopyTest(data, N);
    CopyTest b = *a;
    cout << "a:" << endl;
    a->Print();
    cout << "b:" << endl;
    b.Print();
    delete a;
    cout << "b after delete a:" << endl;
    b.Print();*/

    //Task 6(14)
    /*Book a1("Some text"); 
    printBook(a1);    */           
    //Через те що в функцію йде копія витрачається зайва пам'ять, щоб цього не було треба використовувати const і &

    //Task 7(15)
    /*Book1 myBook = createBook();
    myBook.print();*/
}
