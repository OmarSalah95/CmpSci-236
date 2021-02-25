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
            gpv = 4;
            break;
        case 'C':
            gpv = 4;
            break;
        case 'D':
            gpv = 4;
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
    return courseCode + " "  + to_string(credits) + " "  +  letterGrade + " " + to_string(gpv) + "\n";
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Student{
    public:
        Student(string, int);
        string getName();
        string getID();
        void printReportCard();
        void addClass(Course);
        void listClasses();

    protected:
        string fullName;
        int id;
        vector<Course> classes;

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

void Student::addClass(Course course){
    classes.push_back(course);
};

void Student::listClasses(){
    for( int i = 0; i < classes.size(); i++)
        cout << classes[i].printReport();
};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


class IOStreamHandler{
    public:
        IOStreamHandler();
        void openStreams();
        void cleanUp();
        void seedGradeFile();
        string readFromFile();
        void writeToFile(Student, Course);
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

void IOStreamHandler::seedGradeFile(){
    
};

string IOStreamHandler::readFromFile(){
    string line;
    while(!inFile.eof()){
        string temp;
        inFile >> temp;
        line += " " + temp;
    }
  
    return line;
};

void IOStreamHandler::writeToFile(Student student, Course course){
    outFile << student.getName() + " " + student.getID() + " " + course.printReport() << endl;
};

void IOStreamHandler::cleanUp(){
    inFile.close();
    outFile.close();
};

int main() {
    IOStreamHandler iostream = IOStreamHandler();

    iostream.openStreams();
    

    Student omar = Student("omar", 1234675);
    Course cmpsci = Course("CmpSci-236", 3, 'A');
    Course math = Course("Calc-212", 5, 'A');



    omar.addClass(cmpsci);
    omar.addClass(math);
    omar.listClasses();

    iostream.writeToFile(omar, cmpsci);
    cout << iostream.readFromFile();


    iostream.cleanUp();
    return 0;
};
