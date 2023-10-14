#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include<fstream>
using namespace std;

void intro()
{
	cout << "\n\n\t            ";
	cout << "     C++ Project On Hotel Room Management System";
	cout << "\n\n\n\n\n\n\n\t\t\t\t####################################################";
	cout << "\n\t\t\t\t#\t\t MADE BY \t\t\t   #";
	cout << "\n\t\t\t\t#   SUJAN KHATIWODA ,UJJWAL DAHAL ,RACHAN PHUYAL   #";
	cout << "\n\t\t\t\t####################################################";
}

void head()
{
	cout << "\n\n\n\n\n\n\n\t\t\t\t####################################################";
	cout << "\n\t\t\t\t#               XYZ HOTEL PVT. LTD.                #";
	cout << "\n\t\t\t\t####################################################";
}

void ex_it(void)				 // function to exit
{
    system("cls");
    head();						 // call head function
    cout<<"\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)";
    getch();					 // holds screen
}
void time()
{
	int i = 0;
	long long j;
	cout << "	\n\n\n	Connecting to Server\n 	Syncing DaTa";
	while(i < 10)
	{
		for (j = 5; j > 4; j++)
		{
			if (j == 99999)
			{
				cout << ".";
				break;
			}
		}
		++i;
	}
}

bool isValidName(char *name)       //namevalid
{
	int i = 0;
	while (name[i] != '\0')
	{
		// if the character is not alpha or space
		if ((!isalpha(name[i])) && (name[i] != ' '))
		{
			cout<<"\tPlease Use Alphabets Only.\n";
			return false;
		}
		i++;
	}
	return true;
}
class hotel                  //class
{
private:
	int room_no;
	char name[30];
	char address[50];
	char phone[15];
    char date[15];
	long int id;
	int days;
	float fare;
public:
	void Loginscreen();                  //username & password.
	void main_menu();		           	 //to display the main menu
	long int checkSerial(long int);    	 // to check if the id number already exists
	void add();			              	 //to book a room
	void display(); 				 	 //to display the customer record
	void rooms();						 //to display allotted rooms
	void edit();						//to edit the customer record
	int check(int);	     				//to check room status
	void modify(int);					//to modify the record
	void delete_rec(int); 				 //to delete the record
	void about();
};
void hotel::main_menu()
{
	int choice;
	while(choice != 5)
	{
		system("cls");
		head();
		cout << "\n\n\n\t\t\t\t*************";
		cout << "\n\t\t\t\t* MAIN MENU *";
		cout << "\n\t\t\t\t*************";
		cout << "\n\n\n\t\t\t\t1.Book A Room";
		cout << "\n\t\t\t\t2.Customer Record";
		cout << "\n\t\t\t\t3.Rooms Allotted";
		cout << "\n\t\t\t\t4.Edit Record";
		cout << "\n\t\t\t\t5.About";
		cout << "\n\t\t\t\t6.Exit";
		cout << "\n\n\t\t\t\tEnter Your Choice: ";
		cin  >> choice;
		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
				display();
				break;
			case 3:
				rooms();
				break;
			case 4:
				edit();
				break;
			case 5:
				about();
				break;
			case 6:
			    ex_it();
				break;
			default:
			{
				cout << "\n\n\t\t\t\tWrong choice.....!!!";
				cout << "\n\t\t\t\tPress any key to continue....!!";
				getch();
			}
		}
	
	}
}
void hotel::Loginscreen()                           // login screen username & password.
{
	char username[20], password[20], user[] = "admin", pass[] = "8855";
	int e = 0, i;
	do
	{  system("cls");
        head();
    	cout<<"\n\n\n\t\t USERNAME: ";
        cin>>username;
    	cout<<"\n\t\t PASSWORD: ";
        for (i = 0; i < 20; i++)
        {
            password[i] = getch();
            if (password[i] == 13)
            {
                break;
            }
            else
            {
                cout<<"*";
            }
        }
        password[i] = '\0';
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
        {
            main_menu();
        }
        else
        {
            cout<<"\n\n";
            cout<<"\t\t You Enter wrong password Please login again.";
            e++;
            getch();
        }
    } while (e <= 1);
    if (e > 1)
    {
        cout<<"\n\t\t You have cross the limit. You cannot login. :(";
        getch();
        ex_it();
    }

    system("cls");
}
void hotel::add()                           //data add function
{
	char cont;
z:
	system("cls");
	head();
	int r, flag, valid;
	long int tid;
	ofstream fout("Record.txt", ios::app);
	cout << "\n\n Enter Customer Details";
	cout << "\n ----------------------";
	cout << "\n\n Room no <Only 20 rooms> :";
	fflush(stdin);
	cin >> r;
	flag = check(r);                                    // room check
	if(flag)
	{
	cout << "\n Sorry..!!!Room is already booked";
	getch();
	goto z;
    }
	else
	{
		room_no = r;
		fflush(stdin);

		do
        {
        	fflush(stdin);
            cout << " Name: ";
            fflush(stdin);
            gets(name);
        }
        while(!isValidName(name));               // valid name.


		fflush(stdin);
		cout << " Address: ";
		fflush(stdin);
		gets(address);
A:
		fflush(stdin);
		cout << " Id no: ";
		fflush(stdin);
		cin >> tid;
		if (checkSerial(tid))
		{
			cout << " \t\t(This Id number already exists.)\n";
			goto A;
		}
		else
		{
			id = tid;
		}
		do
		{
D:
			fflush(stdin);
			cout << " Phone no{98xxxxxxxx}:";
			fflush(stdin);
			cin >> phone;
			if (strlen(phone) != 10)
			{
				cout << "\nSorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)\n";
				goto D;
			}
			else
			{
				for (int b = 0; b < strlen(phone); b++)
				{
					if (!isalpha(phone[b]))
					{
						valid = 1;
					}
					else
					{
						valid = 0;
						break;
					}
				}
				if (!valid)
				{
					cout << "\n\t\t phone no. contain Invalid character :(  Enter again :)";
					goto D;
				}
			}
		}
		while (!valid);
		fflush(stdin);
		cout<< " Entry Date <DD/MM/YY> : ";
		fflush(stdin);
		gets(date);
		fflush(stdin);
		cout << " No of Days to Checkout: ";
		cin >> days;
		fare = days * 900;						//900 is currently set as the
		//default price per day
		fout.write((char*)this, sizeof(hotel));
    	//	cout << "\n Room is booked...!!!";
	}
      //	cout << "\n Press any key to continue.....!!";
    //	getch();
	fout.close();
	cout<<"\n\t\t Success:)";

    cout<<"\n\n\t\t----------------------------------------------------------------------------------";
    cout<<"\n\n\t\t Do you want to continue ? ( Press y/Y for yes)\n\t\t ";
	cin>>cont;
    system("cls");
    if (cont == 'y')
    {
        add();
    }
    else
    {
        main_menu();
    }
}
void hotel::display()                     //record display
{
	system("cls");
	head();
	ifstream fin("Record.txt", ios::in);
	if(!fin)
    {
        cout<<"File doesn't exist.\n";
        return;
    }
	int r, flag;
	cout << "\n Enter room no: ";
	cin >> r;
	system ("cls");
	while(fin.read((char*)this, sizeof(hotel)))
	{
		if(room_no == r)
		{
			head();
			cout << "\n Customer Details";
			cout << "\n ----------------";
			cout << "\n\n Room no: " << room_no;
			cout << "\n Name: " << name;
			cout << "\n Address: " << address;
			cout << "\n Id no. :" << id;
			cout << "\n Phone no: " << phone;
			cout << "\n Entry Date <DD/MM/YY> : "<<date;
			cout << "\n Days: " << days;
			cout << "\n Total Fare: " << fare;
			flag = 1;
		}
	}
	if(flag == 0)
		cout << "\n Sorry Room no. not found or vacant....!!";

    cout << "\n\n Press any key to continue....!!";
	getch();
	fin.close();
}
void hotel::rooms()                      //allotted room 
{
	system("cls");
	head();
	ifstream fin("Record.txt", ios::in);
	cout << "\n\n\t\t\t\t    List Of Rooms Allotted";
	cout << "\n\t\t\t    ----------------------";
		while(fin.read((char*)this, sizeof(hotel)))
	{
		
		cout << "\n Room no: " << room_no << "\n Name: " << name;
		cout << "\n Address: " << address << "\n Id no :" << id << "\n Phone: " << phone<< "\n Entry Date <DD/MM/YY> :"<<date;
		cout << "\n Days: " << days << "\n Total: " << fare;
		cout << "\n**********************************";
	}
	cout << "\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();
}
void hotel::edit()                           //delete and modify
{
	system("cls");
	head();
	int choice, r;
	cout << "\n EDIT MENU";
	cout << "\n ---------";
	cout << "\n\n 1.Modify Customer Record";
	cout << "\n 2.Delete Customer Record";
	cout << "\n\n\n Enter your choice: ";
	cin >> choice;
	system("cls");
	head();
	cout << "\n Enter room no: " ;
	cin >> r;
	system("cls");
	switch(choice)
	{
		case 1:
			modify(r);
			break;
		case 2:
			delete_rec(r);
			break;
		default:
			cout << "\n Wrong Choice.....!!";
	}
	cout << "\n Press any key to continue....!!!";
	getch();
}
int hotel::check(int r)               //room check function.
{
	int flag = 0;
	ifstream fin("Record.txt", ios::in);
	while(!fin.eof())
	{
		fin.read((char*)this, sizeof(hotel));
		if(room_no == r)
		{
			flag = 1;
			break;
		}
	}
	fin.close();
	return(flag);
}
void hotel::modify(int r)          //reccordd edit function.
{
	system("cls");
	head();
	long pos, flag = 0;
	fstream file("Record.txt", ios::in | ios::out | ios::binary);
	while(!file.eof())
	{
		pos = file.tellg();
		file.read((char*)this, sizeof(hotel));
		if(room_no == r)
		{
			cout << "\n Enter New Details";
			cout << "\n -----------------";
			fflush(stdin);
			cout << "\n Name: ";
			fflush(stdin);
			gets(name);
			fflush(stdin);
			cout << " Address: ";
			fflush(stdin);
			gets(address);
			cout << "Id no : ";
			fflush(stdin);
			cin >> id;
			cout << " Phone no: ";
			fflush(stdin);
			gets(phone);
			fflush(stdin);
			cout<< " Entry Date <DD/MM/YY> : ";
			fflush(stdin);
			gets(date);
			cout << " Days: ";
			cin >> days;
			fare = days * 900;
			file.seekg(pos);
			file.write((char*)this, sizeof(hotel));
			cout << "\n Record is modified....!!";
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		cout << "\n Sorry Room no. not found or vacant...!!";
	file.close();
}
void hotel::delete_rec(int r)                   //record delete function.
{
	system("cls");
	head();
	int flag = 0;
	char ch;
	ifstream fin("Record.txt", ios::in);
	ofstream fout("temp.txt", ios::out);
	while(fin.read((char*)this, sizeof(hotel)))
	{
		if(room_no == r)
		{
			cout << "\n Name: " << name;
			cout << "\n Address: " << address;
			cout << "\n Id no.: " << id;
			cout << "\n Phone No: " << phone;
			cout << "\n Entry Date <DD/MM/YY> :"<<date;
			cout << "\n Days: " << days;
			cout << "\n Total Fare: " << fare;
			cout << "\n\n Do you want to delete this record(y/n): ";
			cin >> ch;
			if(ch == 'n')
				fout.write((char*)this, sizeof(hotel));
			flag = 1;
			break;
		}
		else
			fout.write((char*)this, sizeof(hotel));
	}
	fin.close();
	fout.close();
	if(flag == 0)
		cout << "\n Sorry room no. not found or vacant...!!";
	else
	{
		remove("Record.txt");
		rename("temp.txt", "Record.txt");
	}
}
long hotel::checkSerial(long int serial)          // id check function
{
	ifstream fin("Record.txt", ios::in);
	int flag = 0;
	while(!fin.eof())
	{
		fin.read((char*)this, sizeof(hotel));
		if(id == serial)
		{
			flag = 1;
		}
	}
	fin.close();
	return flag;
}
void hotel::about()  
{
    system("cls");
    head();
    cout<<"\n\n\n";
    cout<<"\tThis Program is Design For Hotel Room Management system.\n\tWe Three Group of Students Designed it for the college project.\n\tAs you can see,we are newbies and our program is for keeping record of Hotel Room.\n ";
    cout<<"\n\tDesigned By:\n\tSujan Khatiwoda\n\tUjjwal Dahal\n\tRachan Phuyal\n";
    getch();
    main_menu();
}
// Main() Function Here =>
int main()
{

	hotel h;

	cout << "\n\n\n";
	intro();
	time();
	cout << "\n\n\n\t\t\tPress any key to continue....!!";
	getch();
	system("cls");
	head();
	h.Loginscreen();
	getch();
	return 0;
}


