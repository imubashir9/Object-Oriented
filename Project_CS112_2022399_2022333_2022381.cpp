#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    int id;
    string name;
    string fatherName;
    bool isMale;
    string address;
    string birthDate;
    string admissionDate;
    char section;
    string qualification;

    Student(int id, const std::string& name, const string& fatherName, int isMale, const string& address,
        const string& birthDate, const string& admissionDate, char section, const string& qualification)
        : id(id), name(name), fatherName(fatherName), isMale(isMale), address(address), birthDate(birthDate),
        admissionDate(admissionDate), section(section), qualification(qualification)
    {
    }
};

vector<Student> 
importData(const string& filename)
{
    ifstream file(filename);
    string line;
    vector<Student> students;

    while (getline(file, line))
    {
        istringstream iss(line);
        string item;

        getline(iss, item, ',');
        int id = stoi(item);

        getline(iss, item, ',');
        string name = item;
        
        getline(iss, item, ',');
        string fatherName = item;

        getline(iss, item, ',');
        int isMale = stoi(item);

        std::getline(iss, item, ',');
        std::string address = item;

        std::getline(iss, item, ',');
        std::string birthDate = item;

        std::getline(iss, item, ',');
        std::string admissionDate = item;

        std::getline(iss, item, ',');
        char section = item[0];

        std::getline(iss, item, ',');
        std::string qualification = item;

        students.emplace_back(id, name, fatherName, isMale, address, birthDate, admissionDate, section, qualification);
    }

    file.close();
    return students;
}

int main()
{
    string filename = "test.txt";
    vector<Student> 
    students = importData(filename);

    // Display the imported data
    for (const auto& student : students)
    {
        cout << "ID: " << student.id << "\n";
        cout << "Name: " << student.name << "\n";
        cout << "Father's Name: " << student.fatherName << "\n";
        cout << "Is Male: " << student.isMale << "\n";
        cout << "Address: " << student.address << "\n";
        cout << "Birth Date: " << student.birthDate << "\n";
        cout << "Admission Date: " << student.admissionDate << "\n";
        cout << "Section: " << student.section << "\n";
        cout << "Qualification: " << student.qualification << "\n";
        cout << "\n";
    }

    return 0;
}
