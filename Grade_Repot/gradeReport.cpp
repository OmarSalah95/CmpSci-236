#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Course{
    public:
        Course(string, int, char);
        string getCourseCode();
        string printReport();

    protected:
        string courseCode;
        int gpv;
        char letterGrade;
        int credits;

};

Course::Course(string code, int credit, char grade){
    courseCode = code;
    letterGrade = grade;
    credits = credit;
    switch(grade){
        case 'A':
            gpv = 4;
            break;
        case 'B':
            gpv = 3;
            break;
        case 'C':
            gpv = 2;
            break;
        case 'D':
            gpv = 1;
            break;
        default:
            gpv = 0;
            break;
    }
};


string Course::getCourseCode(){
    return courseCode;
};

string Course::printReport(){
    return courseCode + " "  + to_string(credits) + " "  +  letterGrade + " " + to_string(gpv);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Student{
    public:
        Student(string, int);
        string getName();
        string getID();
        void printReportCard();
        void addClasses(vector <Course>);
        void listClasses();
        vector<Course> classes;

    protected:
        string fullName;
        int id;

};

Student::Student( string name, int studentID){
    fullName = name;
    id = studentID;
};

string Student::getName(){
    return fullName;
};

string Student::getID(){
    return to_string(id);
};

void Student::addClasses(vector <Course> courses){
    classes.insert(classes.end(), courses.begin(), courses.end());
};

void Student::listClasses(){
    for( int i = 0; i < classes.size(); i++)
        cout << classes[i].printReport() << endl;
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


class IOStreamHandler{
    public:
        IOStreamHandler();
        void openStreams();
        void cleanUp();
        void seedGradeFile();
        string readFromFile();
        void writeToFile(Student);
    private:
        ofstream outFile;
        ifstream inFile;
};

IOStreamHandler::IOStreamHandler(){

};

void IOStreamHandler::openStreams(){
    char outFilename[11] = "grades.dat";
    outFile.open(outFilename);
    if (outFile.fail()) {
        cout << "Failed to open the output file" << endl;
        exit(1);
    };

    char inFilename[11] = "grades.dat";
    inFile.open(inFilename);
    if (inFile.fail()) {
        cout << "Failed to open the input file" <<endl;
        exit(1);
    };
}


string IOStreamHandler::readFromFile(){
    string line;
    string full;
    while(getline(inFile, line)){
        // cout << line << endl;
        full += line + "\n";
    };
    
    return full;
};

void IOStreamHandler::writeToFile(Student student){
    outFile << "Student Name: " + student.getName() + "\nStudent ID: " + student.getID() << endl;
    for (int i = 0; i < student.classes.size(); i++){
        outFile << student.classes[i].printReport() << endl;
    }; 
    
};

void IOStreamHandler::seedGradeFile(){
    Student s1 = Student("Bokow, R.", 233021);
    Student s2 = Student("Fallin, D.", 2574063);
    Student s3 = Student("Kingsley, M.", 2663628);
    Course NS201 = Course("NS201", 3, 'A');
    Course MG342 = Course("MG342", 3, 'A');
    Course FA302 = Course("FA302", 1, 'A');
    Course MK106 = Course("MK106", 3, 'C');
    Course MA208 = Course("MA208", 3, 'B');
    Course CM201 = Course("CM201", 3, 'C');
    Course CP101 = Course("CP101", 2, 'B');
    Course QA140 = Course("QA140", 3, 'A');
    Course CM245 = Course("CM245", 3, 'B');
    Course EQ521 = Course("EQ521", 3, 'A');
    Course MK341 = Course("MK341", 3, 'A');
    

    s1.addClasses({NS201, MG342, FA302});
    s2.addClasses({MK106, MA208, CM201, CP101});
    s3.addClasses({QA140, CM245, EQ521, MK341, CP101});


    IOStreamHandler::writeToFile(s1);
    IOStreamHandler::writeToFile(s2);
    IOStreamHandler::writeToFile(s3);
};

void IOStreamHandler::cleanUp(){
    inFile.close();
    outFile.close();
};

int main() {
    IOStreamHandler iostream = IOStreamHandler();

    iostream.openStreams();
    iostream.seedGradeFile();

    
    cout << iostream.readFromFile();
    
    iostream.cleanUp();
    return 0;
};
