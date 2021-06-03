#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// In the space below: create a class MilitaryTime that converts given 12 hour time to 24 hour time. It has two private string member fields: time12 & time24. It has one private member function convert().

// (2 pts) Create a constructor that accepts and assigns a string parameter time12. It then calls convert() function.

// (5 pts) Create the IO capability for this class by overloading << & >> operators. The >> operator should read time in 12 hour format and << should print time in 24 hour format.

// (7 pts) Add the Class Conversion capability for this class to convert to and from built-in type int. Use time24 value.

class MilitaryTime
{
	public:
		MilitaryTime();
		MilitaryTime(string civTime){ this-> time12 = civTime; this-> convert();};
        MilitaryTime(int time12);
		void setTime(string);
		friend ostream& operator<<(ostream&, const MilitaryTime&);
		friend istream& operator<<(istream&, const MilitaryTime&);
		operator int();
		

	private:
		string time12,
			time24;
		void convert();
};
MilitaryTime::MilitaryTime(){

}
void MilitaryTime::setTime(string time){
	this-> time12 = time;
	this-> convert();
}

MilitaryTime::operator int(){
	string temp = time24;
	temp.erase(remove(temp.begin(), temp.end(), ':'), temp.end());
	return stoi(temp);
}

MilitaryTime::MilitaryTime(int time)
{
    string s = to_string(time);

    switch (s.length())
    {
    case 1:
    case 2:
    {
        time12 = "12:" + (time > 59 || time < 0 ? "00" : s) + " AM";
        convert();
        break;
    }
    case 3:
    {
        s = "0" + s;
    }
    case 4:
    {
        int hour = stoi(s.substr(0, 2));
        int mins = stoi(s.substr(2, 2));

        if (hour < 0 || hour > 23 || mins > 59 || mins < 0)
        {
            time12 = "12:00 AM";
            convert();
            break;
        }

        if (time >= 1300)
        {
            time12 = to_string(hour - 12) + ":" + s.substr(2, 2);
        }
        else
        {
            time12 = s.substr(0, 2) + ":" + s.substr(2, 2);
        }

        time12 += (time >= 1200 ? " PM" : " AM");

        convert();
        break;
    }

    default:
    {
        time12 = "12:00 AM";
        convert();
        break;
    }
    }
}

void MilitaryTime::convert() {
	int s = time12.find(" ");

	if (s < 0)
	return;

	string t = time12.substr(0, s);
	string a = time12.substr(s + 1);

	if (a != "AM" && a != "am" && a != "PM" && a != "pm") return;

	int c = t.find(":");

	if (c < 0) return;

	string h = t.substr(0, c);
	string m = t.substr(c + 1);

	int hi, mi;

	try {
	hi = stoi(h);
	mi = stoi(m);
	}
	catch (exception& e) {
	return;
	}

	if (a == "PM" || a == "pm")
	hi = hi + 12;

	if (0 > hi || hi > 23) return;

	if (0 > mi || mi > 60) return;

	string phi = to_string(hi);
	if (hi < 10) phi = "0" + phi;

	string pmi = to_string(mi);
	if (mi < 10) pmi = "0" + pmi;


	time24 = phi + ":" + pmi;
}


ostream& operator<<(ostream& out, const MilitaryTime& m1) {

    out << m1.time24 << endl;

    return out;
}

istream& operator>>(istream& in, MilitaryTime& m1) {
	string tempTime;

    getline(in, tempTime);
	m1.setTime(tempTime);
    return in;
}



int main() {

MilitaryTime runTime("7:00 AM");
cout << "Test 1: " << runTime << endl;

MilitaryTime dinnerTime("8:30 PM");
cout << "Test 2: " << dinnerTime << endl;

MilitaryTime userTime;
cout << "Enter a time: ";
cin >> userTime;
cout << "Test 3: " << userTime << endl;

MilitaryTime intTime(2145);
cout << "Test 4: " << intTime << endl;

int t = int(userTime);
cout << "Test 5: " << t << endl;

}
