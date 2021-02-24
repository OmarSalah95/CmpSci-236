#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Student{
    public:
        Student(string, int);
        string getName();
        string getID();
        void printReportCard();
        

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

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
    return courseCode + " "  + to_string(credits) + " "  +  letterGrade + " " + to_string(gpv);
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
    // while(!inFile.eof()){
    //     string temp;
    //     inFile >> temp;
    //     line += " " + temp;
    // }
    inFile >> line;
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
    iostream.writeToFile(omar, cmpsci);
    cout << iostream.readFromFile();


    iostream.cleanUp();
    return 0;
};




using namespace std;