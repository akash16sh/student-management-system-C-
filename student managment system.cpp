#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int age;
    float marks;
};

void addStudent() {
    ofstream file("student_records.txt", ios::app);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    Student student;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter age: ";
    cin >> student.age;
    cout << "Enter marks: ";
    cin >> student.marks;

    file << student.name << "," << student.rollNumber << "," << student.age << "," << student.marks << endl;
    file.close();
    cout << "Student record added successfully." << endl;
}

void viewStudents() {
    ifstream file("student_records.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    cout << "Student Records:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchStudent() {
    ifstream file("student_records.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;

    string line;
    bool found = false;
    while (getline(file, line)) {
        Student student;
        size_t pos = line.find(',');
        student.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        student.rollNumber = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        student.age = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        student.marks = stof(line);

        if (student.rollNumber == rollNumber) {
            cout << "Name: " << student.name << endl;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Age: " << student.age << endl;
            cout << "Marks: " << student.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }

    file.close();
}

void deleteStudent() {
    ifstream inputFile("student_records.txt");
    if (!inputFile) {
        cout << "Error opening file." << endl;

