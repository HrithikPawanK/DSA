#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    string name;
    int age;
    int height;
    string address;
    virtual void display()=0;
};
class Student : public Person{
    public:
    int roll;
    int year;
    int branch;
    int section;
    void display(){
        cout << roll << " " << name << endl;
    }
};
class Teacher : public Person{
    public:
    int deptid;
    string deptname;
    int salary;
    void display(){
        cout << name << " " << deptid << endl;
    }
};
int main(){
    Teacher t;
    t.salary = 10;
    t.name = "hrithik";
    t.deptid = 101;
    t.height = 157;
    t.salary = 1000000;
    t.deptname = "cse";
    t.display();
    return 0;
}
