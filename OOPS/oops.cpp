#include<bits/stdc++.h>
using namespace std;
class Point{
    private:
    int x, y;
    public:
    Point():x(0), y(0){
        x = 0, y = 0;
    }
    Point(int x1, int y1): x(x1), y(y1){
    }
    void print(){
        cout << x << " " << y << endl;
    }
};
// copy constructor
class Test{
    int *ptr;
    public:
    Test(int x){
        ptr = new int(x);
    }
    Test(const Test &t){
        int val = *(t.ptr);
        ptr = new int(val);
    }    
    ~Test(){
        cout << "Destructor Called" << endl;
    }
};
// static member in C++
class Player{
    public:
    static int count;
    Player(){
        count++;
    }
    ~Player(){
        count--;
    }
    static int getCount(){return count;}
};
int Player::count = 0; // required for initializing static member.

// operator overloading

class Complex{
    public:
    int x, y;
    Complex(int a = 0, int b = 0) : x(a), y(b){}
    Complex operator+(const Complex &ob){
        Complex res;
        res.x = x + ob.x;
        res.y = y + ob.y;
        return res;
    } 
};

// Service Now
class SomeClass{
    public:
    int x;
    SomeClass(int xx) : x(xx){}
    SomeClass(const SomeClass&a) { x = a.x; x++;}
    void operator=(const SomeClass &a1) {x = a1.x; x--;}
};

// Friend Function
class Employee;
class Printer{
    public:
    void printEmp(const Employee &e);
};
class Employee{
    private:
    int id; 
    string name;
    public:
    friend void Printer::printEmp(const Employee &e); 
    // friend class Printer; // every function inside Printer class can access employee members.
    Employee(int i, string n):id(i), name(n){};
};
void Printer::printEmp(const Employee &e){
    cout << e.id << " " << e.name << endl;
}

int main(){
    Point p1, p2(10, 20);
    p1.print();
    p2.print();
    Point *p3 = new Point(2, 5);
    p3->print();
    Test t(10);
    Player pl1;
    cout << Player::count << endl;
    Player pl2;
    cout << Player::count << endl;
    cout << Player::getCount() << endl;
    Complex c1(5, 6), c2(10, 8);
    Complex c3 = c1 + c2;
    cout << c3.x << " " << c3.y << endl;
    SomeClass a(4);
    SomeClass b = a;
    cout << b.x << endl;
    Printer p;
    Employee e(101, "abc");
    p.printEmp(e);
    return 0;
}