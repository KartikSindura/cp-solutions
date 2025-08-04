#include <cstring>
#include <iostream>
using namespace std;

class Person {
  char *name;

public:
  Person(const char *n) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
  }

  // Shallow copy (default copy constructor)
  // Deep Copy: Uncomment the one below
  Person(const Person &other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
  }

  void setName(const char *newName) { strcpy(name, newName); }

  void print() { cout << "Name: " << name << endl; }

  ~Person() { delete[] name; }
};

int main() {
  Person p1("Alice");
  Person p2(p1); // Shallow copy here

  p2.setName("Bob");

  p1.print(); // ❗️ Unexpected output: Name: Bob
  p2.print(); // Name: Bob

  return 0;
}
