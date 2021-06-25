#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//system("CLS"); - to remove 
const int Size = 31;

struct Registration_Recipient
{
	// Change to char later when starting code
	char FirstName[Size];
	char MiddleName[Size];
	char LastName[Size];
	char DOB[Size]; // Date Of Birth
	char Nationalty[Size];
	char Ethnicity[Size];
	char Gender;
	char City[Size];
	char ContactNumber[Size];
	char Email[Size];
	char Address[100];
	char Conditions[255];
	char Username[20];
	char Password[20];
	char BloodGroup[5];
	char Hospital_Name[100];
	bool Validation;
};

struct Registration_Donor
{
	// Change to char later when starting code
	char FirstName[Size];
	char MiddleName[Size];
	char LastName[Size];
	char DOB[Size]; // Date Of Birth
	char Nationalty[Size];
	char Ethnicity[Size];
	char Gender;
	char City[Size];
	char ContactNumber[Size];
	char Email[Size];
	char Address[100];
	char Conditions[255];
	char Username[20];
	char Password[20];
	char BloodGroup[5];
	char Hospital_Name[100];
	//char LastestDonatation[100];
};

struct Admin
{
	string Username;
	string Password;

	Admin()
	{
		// Administrator [Username & Password] are here
		Username = "Admin";
		Password = "Password";
	}
};


void main_menu();

void Register_Recipient();
void Register_Donor();
bool checkUsername(string fileName, char username[]);
bool getValidation(char validation);
void displayDonorFile();

int main()
{
	main_menu();

	return 0;
}

void main_menu()
{
	int choice;
	bool check = true;
	int donor_record_found = false;

	cout << "Welcome to ________ Blood Bank" << endl << endl;

	cout << "What we do here ..." << endl << endl;

	cout << "Contact Details" << endl;

	while (check != false)
	{
		cout << endl;
		cout << "1. Login Donor" << endl;
		cout << "2. Login Recipient" << endl;
		cout << "3. Register Donor" << endl;
		cout << "4. Register Recipient" << endl;
		cout << "5. Login Admin" << endl;
		cout << "6. Quit" << endl << endl;

		cout << "Option : ";

		cin >> choice;

		cin.ignore();
		cout << endl << endl;

		if (choice == 1)
		{
			//login donor
			cout << endl;
		}
		else if (choice == 2)
		{
			//login recipient
			cout << endl;
		}
		else if (choice == 3)
		{
			//register donor.
			Register_Donor();
			cout << endl << endl;
			displayDonorFile();
		}
		else if (choice == 4)
		{
			Register_Recipient();
			cout << endl << endl;

		}
		else if (choice == 5)
		{
			cout << "Admin Login";
		}
		else if (choice == 6)
		{
			cout << "Quit" << endl;
			check = false;
			break;
		}
		else
		{
			cout << "Wrong Input" << endl;
		}
	}
}

void Register_Recipient()
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	RecipientFile.open("recipient.dat", ios::out | ios::app | ios::binary);
	if (!RecipientFile)
	{
		cout << "File not found!";
	}
	char A_pos[] = { "A+" };
	char A_neg[] = { "A-" };
	char B_pos[] = { "B+" };
	char B_neg[] = { "B-" };
	char O_pos[] = { "O+" };
	char O_neg[] = { "O-" };
	char AB_pos[] = { "AB+" };
	char AB_neg[] = { "AB-" };
	char none1[] = { "None" };
	char none2[] = { "none" };
	char temp;
	cout << " Rigster Recipient" << endl;
	cout << "-------------------\n" << endl;
	cout << "First Name : ";
	cin >> recipient.FirstName;
	cout << "Middle Name : ";
	cin >> recipient.MiddleName;
	cout << "Last Name : ";
	cin >> recipient.LastName;
	cout << "Date Of Birth : ";
	cin >> recipient.DOB;
	cin.ignore();
	cout << "Nationality : ";
	cin.getline(recipient.Nationalty, Size);
	cout << "City : ";
	cin.getline(recipient.City, Size);
	cout << "Hospital : ";
	cin.getline(recipient.Hospital_Name, Size);
	cout << "Ethnicity : ";
	cin.getline(recipient.Ethnicity, Size);
	cout << "Gender (M/F/X - Other): ";
	cin >> temp;
	while (temp != 'M' && temp != 'F' && temp != 'X' && temp != 'm' && temp != 'f' && temp != 'x')
	{
		//system("CLS"); // clear screen
		cout << "\nPlease try again" << endl;
		cout << "Gender (M/F/X - Other): ";
		cin >> temp;
	}
	recipient.Gender = temp;
	cin.ignore();
	cout << "Any Health Conditions : ";
	cin.getline(recipient.Conditions, 255);
	cout << "Blood Group (If not sure type None) : ";
	cin >> recipient.BloodGroup;
	while ((strcmp(A_pos, recipient.BloodGroup) != 0) && (strcmp(A_neg, recipient.BloodGroup) != 0) &&
		(strcmp(B_pos, recipient.BloodGroup) != 0) && (strcmp(B_neg, recipient.BloodGroup) != 0) &&
		(strcmp(O_pos, recipient.BloodGroup) != 0) && (strcmp(O_neg, recipient.BloodGroup) != 0) &&
		(strcmp(AB_pos, recipient.BloodGroup) != 0) && (strcmp(AB_neg, recipient.BloodGroup) != 0) &&
		(strcmp(none1, recipient.BloodGroup) != 0) && (strcmp(none2, recipient.BloodGroup) != 0))
	{
		//system("CLS"); // clear screen
		cout << "\nPlease enter the correct Blood group (or if not sure type None)" << endl;
		cout << "[A+] [A-]" << endl;
		cout << "[B+] [B-]" << endl;
		cout << "[O+] [O-]" << endl;
		cout << "[AB+] [AB-]" << endl << endl;
		cout << "Blood Group : ";
		cin >> recipient.BloodGroup;
	}
	cin.ignore();
	cout << "Contact Number : ";
	cin.getline(recipient.ContactNumber, Size);
	cout << "Email : ";
	cin.getline(recipient.Email, Size);
	cout << "Address : ";
	cin.getline(recipient.Address, Size);
	//system("CLS");
	bool tempBoolUsername;
	bool check = false;
	int i;
	char tempusername[20];
	cout << "\n20 Characters Maximum" << endl;
	cout << "Username : ";
	cin >> tempusername;
	while (check != true)
	{
		for (i = 0; tempusername[i]; i++)
		{
		}
		if (i > 20)
		{
			//system("CLS"); // clear screen
			cout << "Only 20 Maximum characters" << endl;
			cout << "Username : ";
			cin >> tempusername;
		}
		else if (i < 20)
		{
			check = true;
			break;
		}
	}
	tempBoolUsername = checkUsername("recipient.dat", tempusername);
	while (tempBoolUsername == true)
	{
		bool check = false;
		int i;
		cout << "\nUsername Already exists! \n" << endl;
		cout << "\n20 Characters Maximum" << endl;
		cout << "Username : ";
		cin >> tempusername;
		while (check != false)
		{
			for (i = 0; tempusername[i]; i++)
			{
			}
			if (i > 20)
			{
				//system("CLS"); // clear screen
				cout << "Only 20 Maximum characters" << endl;
				cout << "Username : ";
				cin >> tempusername;
			}
			else if (i < 20)
			{
				check = true;
				break;
			}
		}
		tempBoolUsername = checkUsername("recipient.dat", tempusername);
	}
	check = false;
	for (int i = 0; i < 20; i++)
	{
		recipient.Username[i] = tempusername[i];
	}
	cout << "\n20 Characters Maximum" << endl;
	cout << "Password : ";
	cin >> recipient.Password;
	while (check != true)
	{
		for (i = 0; recipient.Password[i]; i++)
		{
		}
		if (i > 20)
		{
			//system("CLS"); // clear screen
			cout << "Only 20 Maximum characters" << endl;
			cout << "Password : ";
			cin >> recipient.Password;
		}
		else if (i < 20)
		{
			check = true;
			break;
		}
	}
	char valcheck;
	bool tempBool;
	cout << "\nAre you able to recieve Blood? (y/n) :";
	cin >> valcheck;
	while (valcheck != 'y' && valcheck != 'n')
	{
		cout << "\nOnly (y/n) : ";
		cin >> valcheck;
	}
	tempBool = getValidation(valcheck);
	recipient.Validation = tempBool;
	cout << endl;
	cin.ignore();
	RecipientFile.write(reinterpret_cast<char*>(&recipient), sizeof(recipient));
	RecipientFile.close();
}

bool getValidation(char validation)
{
	//fstream RecipientFile;
	Registration_Recipient recipient;
	if (validation == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkUsername(string fileName, char username[])
{
	fstream RecipientFile;
	fstream DonorFile;
	Registration_Recipient recipient;
	Registration_Donor donor;
	if (fileName == "recipient.dat")
	{
		RecipientFile.open("recipient.dat", ios::in | ios::binary);
		if (!RecipientFile)
		{
			return false;
		}
		else
		{
			RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
			while (!RecipientFile.eof())
			{
				if (strcmp(username, recipient.Username) == 0)
				{
					return true;
				}
				else
				{
					return false;
				}
				RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
			}
		}
		RecipientFile.close();
	}
	else if (fileName == "donor.dat")
	{
		DonorFile.open("donor.dat", ios::in | ios::binary);
		if (!DonorFile)
		{
		}
		else
		{
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			while (!DonorFile.eof())
			{
				if (strcmp(username, donor.Username) == 0)
				{
					return true;
				}
				else
				{
					return false;
				}
				DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			}
		}
		DonorFile.close();
	}
	else
	{
		return false;
	}
}
void Register_Donor()
{
	fstream DonorFile;
	Registration_Donor donor;
	DonorFile.open("donor.dat", ios::out | ios::app | ios::binary);
	if (!DonorFile)
	{
		cout << "File not found!";
	}
	char A_pos[] = { "A+" };
	char A_neg[] = { "A-" };
	char B_pos[] = { "B+" };
	char B_neg[] = { "B-" };
	char O_pos[] = { "O+" };
	char O_neg[] = { "O-" };
	char AB_pos[] = { "AB+" };
	char AB_neg[] = { "AB-" };
	char none1[] = { "None" };
	char none2[] = { "none" };
	char temp;
	cout << " Register Donor" << endl;
	cout << "-------------------\n" << endl;
	cout << "First Name : ";
	cin >> donor.FirstName;
	cout << "Middle Name : ";
	cin >> donor.MiddleName;
	cout << "Last Name : ";
	cin >> donor.LastName;
	cout << "Date Of Birth : ";
	cin >> donor.DOB;
	cin.ignore();
	cout << "Nationality : ";
	cin.getline(donor.Nationalty, Size);
	cout << "City : ";
	cin.getline(donor.City, Size);
	cout << "Hospital : ";
	cin.getline(donor.Hospital_Name, Size);
	cout << "Ethnicity : ";
	cin.getline(donor.Ethnicity, Size);
	cout << "Gender (M/F/X - Other): ";
	cin >> temp;
	while (temp != 'M' && temp != 'F' && temp != 'X' && temp != 'm' && temp != 'f' && temp != 'x')
	{
		//system("CLS"); // clear screen
		cout << "\nPlease try again" << endl;
		cout << "Gender (M/F/X - Other): ";
		cin >> temp;
	}
	donor.Gender = temp;
	cin.ignore();
	cout << "Any Health Conditions : ";
	cin.getline(donor.Conditions, 255);
	cout << "Blood Group (If not sure type None) : ";
	cin >> donor.BloodGroup;
	while ((strcmp(A_pos, donor.BloodGroup) != 0) && (strcmp(A_neg, donor.BloodGroup) != 0) &&
		(strcmp(B_pos, donor.BloodGroup) != 0) && (strcmp(B_neg, donor.BloodGroup) != 0) &&
		(strcmp(O_pos, donor.BloodGroup) != 0) && (strcmp(O_neg, donor.BloodGroup) != 0) &&
		(strcmp(AB_pos, donor.BloodGroup) != 0) && (strcmp(AB_neg, donor.BloodGroup) != 0) &&
		(strcmp(none1, donor.BloodGroup) != 0) && (strcmp(none2, donor.BloodGroup) != 0))
	{
		//system("CLS"); // clear screen
		cout << "\nPlease enter the correct Blood group (or if not sure type None)" << endl;
		cout << "[A+] [A-]" << endl;
		cout << "[B+] [B-]" << endl;
		cout << "[O+] [O-]" << endl;
		cout << "[AB+] [AB-]" << endl << endl;
		cout << "Blood Group : ";
		cin >> donor.BloodGroup;
	}
	//if ((strcmp(none1, donor.BloodGroup) == 0) || (strcmp(none2, donor.BloodGroup) == 0))
	//{
	//  randomBloodGroup(donor.BloodGroup);
	//}
	cin.ignore();
	cout << "Contact Number : ";
	cin.getline(donor.ContactNumber, Size);
	cout << "Email : ";
	cin.getline(donor.Email, Size);
	cout << "Address : ";
	cin.getline(donor.Address, Size);
	//system("CLS");
	bool tempBoolUsername;
	bool check = false;
	int i;
	char tempusername[20];
	cout << "\n20 Characters Maximum" << endl;
	cout << "Username : ";
	cin >> tempusername;
	while (check != true)
	{
		for (i = 0; tempusername[i]; i++)
		{
		}
		if (i > 20)
		{
			//system("CLS"); // clear screen
			cout << "Only 20 Maximum characters" << endl;
			cout << "Username : ";
			cin >> tempusername;
		}
		else if (i < 20)
		{
			check = true;
			break;
		}
	}
	tempBoolUsername = checkUsername("donor.dat", tempusername);
	while (tempBoolUsername == true)
	{
		bool check = false;
		int i;
		cout << "\nUsername Already exists! \n" << endl;
		cout << "\n20 Characters Maximum" << endl;
		cout << "Username : ";
		cin >> tempusername;
		while (check != false)
		{
			for (i = 0; tempusername[i]; i++)
			{
			}
			if (i > 20)
			{
				//system("CLS"); // clear screen
				cout << "Only 20 Maximum characters" << endl;
				cout << "Username : ";
				cin >> tempusername;
			}
			else if (i < 20)
			{
				check = true;
				break;
			}
		}
		tempBoolUsername = checkUsername("donor.dat", tempusername);
	}
	check = false;
	for (int i = 0; i < 20; i++)
	{
		donor.Username[i] = tempusername[i];
	}
	cout << "\n20 Characters Maximum" << endl;
	cout << "Password : ";
	cin >> donor.Password;
	while (check != true)
	{
		for (i = 0; donor.Password[i]; i++)
		{
		}
		if (i > 20)
		{
			//system("CLS"); // clear screen
			cout << "Only 20 Maximum characters" << endl;
			cout << "Password : ";
			cin >> donor.Password;
			cin.ignore();
		}
		else if (i < 20)
		{
			check = true;
			break;
		}
	}
	DonorFile.write(reinterpret_cast<char*>(&donor), sizeof(donor));
	DonorFile.close();
}

void displayDonorFile()
{
	fstream DonorFile;
	Registration_Donor donor;

	DonorFile.open("donor.dat", ios::in | ios::binary);

	if (!DonorFile)
	{
		cout << "File not found";
	}

	DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));

	while (!DonorFile.eof())
	{
		cout << "Name : " << donor.FirstName << " " << donor.MiddleName << " " << donor.LastName << endl;
		cout << "Date Of Birth : " << donor.DOB << endl;
		cout << "Nationalty : " << donor.Nationalty << endl;
		cout << "Ethnicity : " << donor.Ethnicity << endl;
		cout << "Gender : " << donor.Gender << endl;
		cout << "City : " << donor.City << endl;
		cout << "Contact Number : " << donor.ContactNumber << endl;
		cout << "Email : " << donor.Email << endl;
		cout << "Address : " << donor.Address << endl;
		cout << "Conditions : " << donor.Conditions << endl;
		cout << "Blood Group : " << donor.BloodGroup << endl;
		cout << "Hospital : " << donor.Hospital_Name << endl;
		cout << "Username : " << donor.Username << endl;
		cout << "Password : " << donor.Password << endl;

		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
	}

	DonorFile.close();
}