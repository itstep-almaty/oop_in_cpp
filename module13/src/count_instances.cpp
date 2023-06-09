#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        static int count; // статическая переменная
    private:
        double gpa;
        string name;
    

    public:
        double get_gpa() const{
            return this->gpa;
        }
        Student(string name, double gpa){
            count++;
            this->name = name;
            this->gpa = gpa;
            cout << name << "+" << endl;
        }

        Student(const Student& s){
            count++;
            this->name = s.name;
            this->gpa = s.gpa;
            cout << name << "+ copy" << endl;
        }

        ~Student(){
            cout << name << "-" << ", count = " << this->count << endl;
            count--;
        }
};

int Student::count = 0; // инициализация статической переменной

int main(){
    Student b("Bob",3.5);
    Student a("Alice",3.7);
    cout << Student::count << endl;
    cin.get();
}
