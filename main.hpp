#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

const int N = 5;
struct Student
{
    int id;
    string name;
    string major;
};

void makeStudent(Student *student);
void printStudent(Student *student);

void makeStudent(Student *student)
{
    ifstream ifs;

    string temp;
    int count = 0, index = 0;

    ifs.open("students.txt");

    
    while(ifs >> temp) {
        switch (count) {
            case 0:
                student[index].id = stoi(temp);
                ++count;
                break;
            case 1:
                student[index].name = temp;
                ++count;
                break;
            case 2:
                student[index].major = temp;
                count = 0;
                ++index;
                break;
        }
    }
}
void printStudent(Student *student)
{
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << student[i].id << " " << student[i].name << " " << student[i].major << endl;
    }
}