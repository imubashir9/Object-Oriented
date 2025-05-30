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
        admissionDate(admissionDate), section(section), qualification(qualification){}

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
        bool isMale = stoi(item);
    
        getline(iss, item, ',');
        string address = item;

        getline(iss, item, ',');
        string birthDate = item;

        getline(iss, item, ',');
        string admissionDate = item;

        getline(iss, item, ',');
        char section = item[0];

        getline(iss, item, ',');
        string qualification = item;

        students.emplace_back(id, name, fatherName, isMale, address, birthDate, admissionDate, section, qualification);
    }

    file.close();
    return students;
}


class Course {
public:
    int id;
    string program;
    string semester;
    string courseCode;
    int marks;
    string department;

    Course(int id, const string& program, const string& semester, const string& courseCode,
        int marks, const string& department)
        : id(id), program(program), semester(semester), courseCode(courseCode), marks(marks), department(department)
    {
    }
};

vector<Course> 
importData1(const string& filename)
{
    ifstream file(filename);
    string line;
    vector<Course> courses;

    while (getline(file, line))
    {
        istringstream iss(line);
        string item1;

        getline(iss, item1, ',');
        int id = stoi(item1);

        getline(iss, item1, ',');
        string program = item1;

        getline(iss, item1, ',');
        string semester = item1;

        getline(iss, item1, ',');
        string courseCode = item1;

        getline(iss, item1, ',');
        int marks = 0;
        try {
            marks = stoi(item1);
        }
        catch (const exception& e) {
            // Handle the exception here
            cerr << "Exception caught: " << e.what() << endl;
        }
       
        getline(iss, item1, ',');
        string department = item1;

        courses.emplace_back(id, program, semester, courseCode, marks, department);
    }

    file.close();
    return courses;
}


int main()
{
    string filename0 = "Lhr_Student_94.txt";
    string filename = "P_Student_94.txt";

    vector<Student>
    students1 = importData(filename0);

    vector<Student>
    students = importData(filename);

    // Display the imported data
    for (const auto& student : students1)
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
    for (const auto& student : students1)
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
        
        
        
    string filename1 = "Lhr_Detail_94.txt";
    string filename2 = "P_Detail_94.txt";

    vector<Course> 
    courses1 = importData1(filename1);

    vector<Course>
    courses2 = importData1(filename2);

    // Display the imported data from file1.txt
    for (const auto& course : courses1)
    {
        cout << "ID: " << course.id << endl;
        cout << "Program: " << course.program << endl;
        cout << "Semester: " << course.semester << endl;
        cout << "Course Code: " << course.courseCode << endl;
        cout << "Marks: " << course.marks << endl;
        cout << "Department: " << course.department << endl;
        cout << endl;
    }

    // Display the imported data from file2.txt
    for (const auto& course : courses2)
    {
        cout << "ID: " << course.id << endl;
        cout << "Program: " << course.program << endl;
        cout << "Semester: " << course.semester << endl;
        cout << "Course Code: " << course.courseCode << endl;
        cout << "Marks: " << course.marks << endl;
        cout << "Department: " << course.department << endl;
        cout << endl;
    }

    return 0;
}
