// main.cpp
#include <iostream>

class Person {
public:
    Person(std::string name, int age);
    void displayInfo();

private:
    std::string name;
    int age;
};

class Student : public Person {
public:
    Student(std::string name, int age, int studentId);
    void displayStudentInfo();

private:
    int studentId;
};

Person::Person(std::string name, int age) : name(name), age(age) {}

void Person::displayInfo() {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

Student::Student(std::string name, int age, int studentId) : Person(name, age), studentId(studentId) {}

void Student::displayStudentInfo() {
    displayInfo(); // 부모 클래스의 함수 호출
    std::cout << "Student ID: " << studentId << std::endl;
}

int main() {
    // Person 객체 생성
    Person person("John Doe", 25);
    person.displayInfo();

    // Student 객체 생성
    Student student("Alice Smith", 20, 12345);
    student.displayStudentInfo();

    return 0;
}
