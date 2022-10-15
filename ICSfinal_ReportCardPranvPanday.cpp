#include<iostream>
#include<fstream>
#include<iomanip>

//ICS FINAL PROJECT
// PRANAV PANDAY
// ICS 4U1-01
using namespace std;
//The purpose of this code is to accurately keep track of the students grades and perform tasks to,
// accurately keep track of the students records.
class inforOfStudent
{
	int rollno;  // variable for roll number
	char name[50]; // variable for name
	int p_marks, c_marks, m_marks, e_marks, cs_marks; // variable marks for physics,chem, math, english, computer science
	double avg;  // variables for overall average
	char grade;
	void calculate();	//function to calculate grade
public:
	void getdata();		//function to accept data from user
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
	int retrollno() const;
}; //class ends here


void inforOfStudent::calculate()
{
	avg=(p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
	if(avg>=80) //if avg 80+ prints A
		grade='A';
	else if(avg>=70) //if avg 70+ prints B
		grade='B';
	else if(avg>=60) //if avg 60+ prints C
		grade='C';
	else if (avg >= 50)//if avg 50+ prints D
		grade='D';
	else  // else statement for below 50 - its a F! :(
		grade='F';
}


void inforOfStudent::getdata() //using pointers for inforOFStudent functions to use the getData function (CONCEPT OF POINTERS - CHAP 5 )
{
	cout<<"\nEnter The roll number of student: "; // asking for roll number
	cin>>rollno; // storing roll number
	cout<<"\nEnter The Name of student: "; // asking for the name of the student
	cin.ignore(); // calling the ignore function
	cin.getline(name,50); //storing  the name
	cout<<"\nEnter The marks in physics out of 100 : "; // asking for physics mark
	cin>>p_marks;//storing the phyiscs mark
	cout<<"\nEnter The marks in chemistry out of 100 : "; // asking for chem mark
	cin>>c_marks; // storing the chem mark
	cout<<"\nEnter The marks in maths out of 100 : "; // asking for the math mark
	cin>>m_marks; // storing the math mark
	cout<<"\nEnter The marks in english out of 100 : "; // asking for the english mark
	cin>>e_marks; // storing the english mark
	cout<<"\nEnter The marks in computer science out of 100 : "; // asking for the ics mark
	cin>>cs_marks; // storing the ics mark
	calculate(); // using object 1 to help use the caluclate function - to calculate overall average
}


void inforOfStudent::showdata() const
{
	cout<<"\nRoll number of student : "<<rollno; // showing roll number
	cout<<"\nName of student : "<<name; // showing student name
	cout<<"\nMarks in Physics : "<<p_marks; // showing phyiscs mark
	cout<<"\nMarks in Chemistry : "<<c_marks; // showing chem mark
	cout<<"\nMarks in Maths : "<<m_marks; // showing the math mark
	cout<<"\nMarks in English : "<<e_marks; // showing the english mark
	cout<<"\nMarks in Computer Science :"<<cs_marks; // showing the ics mark
	cout<<"\nPercentage of student is  :"<<avg; // showing the overall percentage of the student
	cout<<"\nGrade of student is :"<<grade; // final grade of the student
}


void inforOfStudent::show_tabular() const  // concept from chapter 5 pointers - student function using the show_tabular to display
{
	cout<<"ROLL NUMBER: "<<rollno<<endl;
	cout<<"NAME: "<<name<<endl;
    cout<<"PHYSICS: "<<p_marks<<endl;
	cout<<"CHEMISTRY: "<<c_marks<<endl;
	cout<<"MATH: "<<m_marks<<endl;
	cout<<"ENGLISH: "<<e_marks<<endl;
	cout<<"ICS: "<<cs_marks<<endl;
	cout<<"-----------------------"<<endl;
	cout<<"OVERALL AVERAGE: "<<avg<<endl;
	cout<<"LETTER GRADE: "<<grade<<endl;
	cout <<"******************************"<<endl;
}

int  inforOfStudent::retrollno() const
{
	return rollno; // returning the roll number
}



void write_student();	//write the record in binary file
void display_all();	//read all records from binary file
void display_sp(int);	//accept rollno and read record from binary file
void modify_student(int);	//accept rollno and update record of binary file
void delete_student(int);	//accept rollno and delete selected records from binary file
void class_result();	//display all records in tabular format from binary file
void result();		//display result menu
void intro();		//display welcome screen
void entry_menu();	//display entry menu on screen

struct Calculate : public inforOfStudent // the struct calculate is INHERITAINING the class student- making it public
// using the calculate function from the class
{
	public:
	Calculate()
	{
		int rollno; // getting the neccessary variables to get the overall average
	char name[50];// name
	int p_marks, c_marks, m_marks, e_marks, cs_marks; // marks for each subject
	double avg; // overall average
	char grade; // variable for letter grade
	}
	~Calculate()
	{
		//Clearing variables by assigning a value of 0
		int rollno = 0;
		char name[50] = {0};
		int p_marks, c_marks, m_marks, e_marks, cs_marks = 0;
		double avg = 0;
	}
} ;

class variables : public inforOfStudent //CONCEPT OF INHERITANCE - class variables inheriting the student class
{
	public:
		variables() //constructor
		{
			int rollno;
			char name[50];
			int p_marks, c_marks, m_marks, e_marks, cs_marks;
			double avg;
			char grade;
			void calculate();	//function to calculate grade
		}
};

int main() // main menu
{

	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	intro();
	do // using concept of EXCEPTIONS to catch the invalid input
	{
		try { // prints the following
		cout<<"\nMAIN MENU";
		cout<<"\n01. ENTRY/EDIT MENU";
		cout<<"\n02. RESULT MENU";
		cout<<"\n03. EXIT";
		cout<<"\nPlease Select Your Option (1-3) ";
		cin>>ch;
		switch(ch) // checking the validation of input
		{
			case '1': entry_menu();
				break; // break the case checking if  ch=1, if not go to next
			case '2': result();
				break;// break the case checking if  ch=1, if not go to next
			case '3':
				break;
			default :cout<<"\a"; throw 0;
		}
	} catch (...) // catch (. . .) if there is the error
	{
		cout <<"Error" <<endl; //printing the error
	}
    }while(ch!='3'); // while loop to keep going if ch!= 3

	return 0;
}

void write_student()//function to write in file
{
	inforOfStudent st; //object of class student
	ofstream outFile; //variable outFile to input data into a file
	outFile.open("student.dat",ios::binary|ios::app); //open file
	st.getdata(); //calling getdata from class student
	outFile.write(reinterpret_cast<char *> (&st), sizeof(inforOfStudent)); //casting the pointer to be written as a char
	outFile.close(); //close file
    	cout<<"\n\nStudent record Has Been Created ";
	cin.ignore(); //ignores whitespace characters
}

void display_all() //	function to read all records from file
{
	inforOfStudent st; //object of class student
	ifstream inFile; //inFile variable to load from file
	inFile.open("student.dat",ios::binary); //open file
	if(!inFile) //if file not found
	{
		cout<<"File could not be open !! Press any Key..."; // errro msg
		cin.ignore();
		cin.get(); // reads the line
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(inforOfStudent))) //go through file and display the data normally by converting the binary file into normal characters
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close(); //close a file
	cin.ignore();
	cin.get();
}

void display_sp(int n)//function to read specific record from file
{
	inforOfStudent st; //object of class student
	ifstream inFile;
	inFile.open("student.dat",ios::binary); //open file
	if(!inFile) //if file not found
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(inforOfStudent))) //while loop that reads through the file
	{
		if(st.retrollno()==n) //if roll number matches
		{
	  		 st.showdata(); //show data
			 flag=true;
		}
	}
	inFile.close(); //close file
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

void modify_student(int n) //function to modify record of file
{
	bool found=false;
	inforOfStudent st; //st object to locate something from the class of student - learnt in chapter 5
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out); //opens file
	if(!File) //if not in file
	{
		cout<<"File could not be open !! Press any Key..."; //error message
		cin.ignore();
		cin.get();
		return;
	}
    	while(!File.eof() && found==false) //goes through the file
	{

		File.read(reinterpret_cast<char *> (&st), sizeof(inforOfStudent));
		if(st.retrollno()==n) //checks to match roll number
		{
			st.showdata();
			cout<<"\nPlease Enter The New Details of student"<<endl; // asking user for new details of the student
			st.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(st)); //storing the data at that location into pos
		    	File.seekp(pos,ios::cur); //checking for pos in file
		    	File.write(reinterpret_cast<char *> (&st), sizeof(inforOfStudent)) ; //write that into the file
		    	cout<<"\n Record Updated";
		    	found=true; //terminate loop
		}
	}
	File.close(); //close file
	if(found==false)
		cout<<"\n Record Not Found "; // eroor message
	cin.ignore();
	cin.get();
}
void delete_student(int n)//function to delete record of file
{
	inforOfStudent st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary); //open file
	if(!inFile) //if file not found
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out); //open temp.dat file
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(inforOfStudent))) //while loop that reads through file
	{
		if(st.retrollno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(inforOfStudent)); //writes in the rolln umber into the file
		}
	}
	outFile.close(); //close file
	inFile.close(); //close second file
	remove("student.dat"); //remove the student.dat file
	rename("Temp.dat","student.dat"); //renaming files
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}
void class_result()//function to display all students grade report
{
	inforOfStudent st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary); //open file
	if(!inFile) //if not in file
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
//display results
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(inforOfStudent))) //read through file
	{
		st.show_tabular(); //show data as file is read
	}
	cin.ignore();
	cin.get();
	inFile.close(); //close file
}


void result()//function to display result menu
{
	try { //EXCEPTION concept from chapter 7 being used for users validation
	int ch;
	int rno;
	cout<<"\nRESULT MENU";
	cout<<"\n1. Class Result";
	cout<<"\n2. Student Report Card";
	cout<<"\n3. Back to Main Menu";
	cout<<"\nEnter Choice (1/2/3)? ";
	cin>>ch;

	if(ch == 1)
	{
	class_result();}
	else if (ch==2)
	{
		cout<<"\nEnter Roll Number Of Student : "; cin>>rno; // asking user for student roll number to locate their file
				display_sp(rno);
	}
	else if (ch==3)
	{
		cout <<"\a"<<endl;
	}
	else
		throw 0; //throw exception
	} catch (...)
	{
	cout << "Choice should be 1-3" << endl;//print error message
	}
}


// INTRO FUNCTION
void intro()
{
	cout<<"\nSTEM SECONDARY SCHOOL";
	cout<<"\nSTUDENT MARK RECORD SYSTEM ";
	cout<<"\nby-Pranav Panday";
	cout <<"\n---------------------------";
}

void entry_menu() //ENTRY / EDIT MENU FUNCTION
{
	char ch;
	int num;
	cout<<"\nENTRY MENU";
	cout<<"\n1.CREATE STUDENT RECORD"; // asking to creat student report card
	cout<<"\n2.DISPLAY ALL STUDENTS RECORDS"; // displaying the students records
	cout<<"\n3.SEARCH STUDENT RECORD";// search for a students record
	cout<<"\n4.MODIFY STUDENT RECORD"; // modify a specific students record
	cout<<"\n5.DELETE STUDENT RECORD"; // delete a student record
	cout<<"\n6.BACK TO MAIN MENU"; // back to main menu
	cout<<"\nPlease Enter Your Choice (1-6) "; // asking user for their input
	cin>>ch; // reading the user anser
	try { // exception to check user input validation, if not 1-6 error message is shown
	switch(ch)
	{
	case '1':	write_student(); break;
	case '2':	display_all(); break;
	case '3':	cout<<"\nPlease Enter The roll number "; cin>>num;
			display_sp(num); break;
	case '4':	cout<<"\nPlease Enter The roll number "; cin>>num;
			modify_student(num);break;
	case '5':	cout<<"\nPlease Enter The roll number "; cin>>num;
			delete_student(num);break;
	case '6':	break;
	default:	entry_menu(); throw 0; // throws exception
	}
	} catch (...)
	{
		cout << "Choice must be between 1-6" << endl;//error message
	}
}



