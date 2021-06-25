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
void displayRecipientFile();
bool Recipient_Login();
void recipient_screen();
void checkVal(Registration_Recipient recipient);

void searchDonorInfo_BloodGroup(char search[]);
void searchDonorInfo_BloodGroup_Location(char blood[], char location[]);

bool Donor_Login();
void donor_screen();
inline void procedure_to_donate();
inline void donation_benefits();
void create_booking();
void update_donor_information();


streamsize current_donor_position = 0;
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
			bool account_found = false;
			int attempts = 0;
			cout << "\nLogin" << endl << endl;
			while (account_found == false && attempts < 3)
			{
				account_found = Donor_Login();
				attempts++;
			}
			if (account_found) {
				donor_screen();
			}
			cout << endl;
		}
		else if (choice == 2)
		{
			bool account_found2 = false;
			int attempts2 = 0;
			cout << "\nLogin" << endl << endl;
			while (account_found2 == false && attempts2 < 3)
			{
				account_found2 = Recipient_Login();
				attempts2++;
			}
			if (account_found2) {
				recipient_screen();
			}
			cout << endl;
		}
		else if (choice == 3)
		{
			//register donor.
			Register_Donor();
			cout << endl << endl;
			displayDonorFile(); // remove later
		}
		else if (choice == 4)
		{
			Register_Recipient();
			cout << endl << endl;
			displayRecipientFile(); // remove later
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
void displayRecipientFile()
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	bool tempVal;
	RecipientFile.open("recipient.dat", ios::in | ios::binary);
	if (!RecipientFile)
	{
		cout << "File not found";
	}
	RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
	while (!RecipientFile.eof())
	{
		cout << "Name : " << recipient.FirstName << " " << recipient.MiddleName << " " << recipient.LastName << endl;
		cout << "Date Of Birth : " << recipient.DOB << endl;
		cout << "Nationalty : " << recipient.Nationalty << endl;
		cout << "Ethnicity : " << recipient.Ethnicity << endl;
		cout << "Gender : " << recipient.Gender << endl;
		cout << "City : " << recipient.City << endl;
		cout << "Contact Number : " << recipient.ContactNumber << endl;
		cout << "Email : " << recipient.Email << endl;
		cout << "Address : " << recipient.Address << endl;
		cout << "Conditions : " << recipient.Conditions << endl;
		cout << "Blood Group : " << recipient.BloodGroup << endl;
		cout << "Hospital : " << recipient.Hospital_Name << endl;
		checkVal(recipient);
		cout << endl;
		//cout << "Username : " << recipient.Username << endl;
		//cout << "Password : " << recipient.Password << endl;
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
	}
	RecipientFile.close();
}

bool Recipient_Login()
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	char username[20];
	char password[20];
	bool found_flag = false;
	RecipientFile.open("recipient.dat", ios::in | ios::binary);
	if (!RecipientFile)
	{
		cout << "File not found";
	}
	else {
		cout << "Username : ";
		cin.getline(username, 20);
		cout << "Password : ";
		cin.getline(password, 20);
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		while (!RecipientFile.eof())
		{
			if (strcmp(username, recipient.Username) == 0 && strcmp(password, recipient.Password) == 0) {
				cout << "\nWelcome back " << recipient.Username << "!\n";
				found_flag = true;
			}
			RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		}
		//if the account is not found 
		if (found_flag == false) {
			cout << "\nAccount not found.. Exiting\n";
		}
	}
	RecipientFile.close();
	return found_flag;
}

void recipient_screen()
{
	bool flag = true;
	while (flag != false)
	{
		int choice;
		cout << "Recipient Menu" << endl;
		cout << "---------------" << endl << endl;
		cout << "1. Search Donors Info by Blood group" << endl;
		cout << "2. Search Donors Info by Blood group & Location" << endl;
		cout << "3. Gather Donors contact details (By given Full Name)" << endl;
		cout << "4. Your Blood details" << endl;
		cout << "5. Back" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			// search for blood group
			char A_pos[] = { "A+" };
			char A_neg[] = { "A-" };
			char B_pos[] = { "B+" };
			char B_neg[] = { "B-" };
			char O_pos[] = { "O+" };
			char O_neg[] = { "O-" };
			char AB_pos[] = { "AB+" };
			char AB_neg[] = { "AB-" };
			char inputBlood[100];
			cout << "Here are all the Blood group options (or type 'back' to go back to the menu)" << endl;
			cout << "[A+] [A-]" << endl;
			cout << "[B+] [B-]" << endl;
			cout << "[O+] [O-]" << endl;
			cout << "[AB+] [AB-]" << endl << endl;
			cin.ignore();
			cout << "Blood Group : ";
			cin.getline(inputBlood, 100);
			cout << endl;
			while ((strcmp(A_pos, inputBlood) != 0) && (strcmp(A_neg, inputBlood) != 0) &&
				(strcmp(B_pos, inputBlood) != 0) && (strcmp(B_neg, inputBlood) != 0) &&
				(strcmp(O_pos, inputBlood) != 0) && (strcmp(O_neg, inputBlood) != 0) &&
				(strcmp(AB_pos, inputBlood) != 0) && (strcmp(AB_neg, inputBlood) != 0))
			{
				cout << "\nPlease enter the correct Blood group (or type 'back' to go back to the menu)" << endl;
				cout << "[A+] [A-]" << endl;
				cout << "[B+] [B-]" << endl;
				cout << "[O+] [O-]" << endl;
				cout << "[AB+] [AB-]" << endl << endl;
				cout << "Blood Group : ";
				cin.getline(inputBlood, 100);
				cout << endl;
			}
			searchDonorInfo_BloodGroup(inputBlood);
			cout << "\nPress any key to conintue ...";
			cin.get();
			cout << endl;
			break;
		}
		case 2:
		{
			// search for blood group and location
			char A_pos[] = { "A+" };
			char A_neg[] = { "A-" };
			char B_pos[] = { "B+" };
			char B_neg[] = { "B-" };
			char O_pos[] = { "O+" };
			char O_neg[] = { "O-" };
			char AB_pos[] = { "AB+" };
			char AB_neg[] = { "AB-" };
			char inputBlood[100];
			char location[100];
			cout << "Here are all the Blood group options (or type 'back' to go back to the menu)" << endl;
			cout << "[A+] [A-]" << endl;
			cout << "[B+] [B-]" << endl;
			cout << "[O+] [O-]" << endl;
			cout << "[AB+] [AB-]" << endl << endl;
			cin.ignore();
			cout << "Blood Group : ";
			cin.getline(inputBlood, 100);
			cout << endl;
			while ((strcmp(A_pos, inputBlood) != 0) && (strcmp(A_neg, inputBlood) != 0) &&
				(strcmp(B_pos, inputBlood) != 0) && (strcmp(B_neg, inputBlood) != 0) &&
				(strcmp(O_pos, inputBlood) != 0) && (strcmp(O_neg, inputBlood) != 0) &&
				(strcmp(AB_pos, inputBlood) != 0) && (strcmp(AB_neg, inputBlood) != 0))
			{
				cout << "\nPlease enter the correct Blood group (or type 'back' to go back to the menu)" << endl;
				cout << "[A+] [A-]" << endl;
				cout << "[B+] [B-]" << endl;
				cout << "[O+] [O-]" << endl;
				cout << "[AB+] [AB-]" << endl << endl;
				cout << "Blood Group : ";
				cin.getline(inputBlood, 100);
				cout << endl;
			}
			cout << "Please enter the hospital name : ";
			cin.getline(location, 100);
			cout << endl;
			searchDonorInfo_BloodGroup_Location(inputBlood, location);
			cout << "\nPress any key to conintue ...";
			cin.get();
			cout << endl;
			break;
		}
		case 3:
		{
			// Get Donors Details - (By giving Full name) - (Not Middle name)
			// donor contact details for recipient
			cout << "Donor contacts" << endl;
			break;
		}
		case 4:
		{
			// (Your Details)
			cout << endl;
			displayRecipientFile();
			cout << endl;
			break;
		}
		case 5:
		{
			// Back - back main menu
			return;
		}
		default:
		{
		}
		}
	}
}

void checkVal(Registration_Recipient recipient)
{
	if (recipient.Validation == 1)
	{
		cout << "Validation : True" << endl;
	}
	else
	{
		cout << "Validation : False" << endl;
	}
}
void donor_screen() {
	int donor_menu_input;

	while (1) {
		cout << "\nDonor Menu : \n";
		cout << "\n1. Procedure to donate blood";
		cout << "\n2. Create a Booking";
		cout << "\n3. Benefits of blood donation";
		cout << "\n4. Manage donor information";
		cout << "\n5. Back\n";
		cout << "Please enter option : ";
		cin >> donor_menu_input;
		switch (donor_menu_input)
		{
		case 1:
			procedure_to_donate();
			break;
		case 2:
			//Booking function.
			break;
		case 3:
			//Benefits of blood donation 
			donation_benefits();
			break;
		case 4:
			//Update the donor information.
			update_donor_information();
			displayDonorFile();
			//Also edit booking informations. / switch case menu for both options.
			break;
		case 5:
			//create_booking();
			return;
		default:
			cout << "\nPlease enter a valid option..\n";
			break;
		}
	}
}
bool Donor_Login()
{

	fstream DonorFile;
	Registration_Donor donor;
	char username[20];
	char password[20];
	bool found_flag = false;

	DonorFile.open("donor.dat", ios::in | ios::binary);

	if (!DonorFile)
	{
		//currently printing 3 times as function called 3, just use argument value as fix lol
		cout << "Donor File not found! ";
	}
	else {

		cout << "\nLogin" << endl << endl;
		cout << "Username : ";
		cin.getline(username, 20);
		cout << "Password : ";
		cin.getline(password, 20);
		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));

		while (!DonorFile.eof())
		{
			if (strcmp(username, donor.Username) == 0 && strcmp(password, donor.Password) == 0) {
				cout << "Welcome back " << donor.Username << "!\n";
				found_flag = true;
				current_donor_position = DonorFile.tellg() / sizeof(donor) - 1;
			}
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}
		//if the account is not found 
		if (found_flag == false) {
			cout << "Account not found.. Exiting\n";
		}
	}


	DonorFile.close();
	return found_flag;
}

inline void procedure_to_donate() {
	cout << "\nProcedure to donate blood:\n\n";
	cout << "\t1. Check with your G.P to make sure you are eligible as a donor\n";
	cout << "\t2. Register as a donor with this system.\n";
	cout << "\t3. Log into the donor menu.\n";
	cout << "\t4. Select the booking option 2 in the donor menu.\n";
	cout << "\t5. Enter the booking details. Hospital name, date etc\n";
	cout << "\t6. Select an available timeslot at the hospital.\n";
	cout << "\t7. The system will tell you if this is available\n";
	cout << "\t8. Come into the selected hospital and bring your ID, something to pass time and a smile!!\n";
	cout << "\n\tRemember you're saving a life today!!\n";

	cout << "\n\tTips:\n";
	cout << "\t\tEat within a few hours before donation and almost immediately afterwards.\n";
	cout << "\t\tKeep yourself hydrated to avoid light headedness.\n";
	cout << "\t\tMake sure to rest adequately.\n";
	cout << "\t\tMake sure you are in good health. E.g: Have recovered from any colds / flu's.\n";

	cout << "\n\tOnce you have arrived:\n\n";
	cout << "\t1. Check in at the blood donation office.\n";
	cout << "\t2. Read two mandatory leaflets and complete a Donor Health Questionnaire.\n";
	cout << "\t3. Once completed donors sign a declaration that to the best of their knowledge the health\n";
	cout << "\tinformation given is correct and give consent to the testing for blood groups\n";
	cout << "\tand evidence of some infections in the blood that they donate.\n";
	cout << "\t4. Once you have completed your questionnaire, you will have a confidential interview with a NZBS nurse\n";
	cout << "\tor donor technician\n";
	cout << "\t5. They will also check your haemoglobin level using a finger prick test.\n\n";
	cout << "\t6. Once you've completed your interview successfully, you will be taken to one of our donation\n";
	cout << "\tchairs and seated comfortably.\n";
	cout << "\t7. Your arm will be cleaned at the venepuncture site (on the inside of the elbow)\n";
	cout << "\t8. A sterile , single-use needle will be inserted. There may be a moment of discomfort as \n";
	cout << "\tthe needle goes in - sorry, this is the only way to get the blood out! \n";
	cout << "\tThe time you spend in the donation chair will differ depending on the type of donation you are giving. \n\n";

	cout << "\tA blood donation can take up to 60 minutes (includes registration, donation and recovery).\n";
	cout << "\tThe blood is collected in a sterile bag, and time on the bed can take about 5 to 10 minutes..\n";
	cout << "\t9. A unit of blood (around 470 ml) will be collected. The needle is then removed and a bandage is applied.\n\n";
	cout << "\tA plasma donation can take up to 90 minutes (includes registration, donation and recovery). The process of\n";
	cout << "\tdonating plasma is longer because blood is taken and separated into plasma and red blood cells by a special\n";
	cout << "\tapheresis machine.  The red blood cells are returned to your body and the plasma is collected in a \n";
	cout << "\tsterile bag. The time on the bed can take about 45 to 60 minutes. For your safety, a new needle and \n";
	cout << "\tcollection bag is used for each blood donation.Needlesand bags are never reused. \n\n";

	cout << "\t10. After donating blood, you will be asked to rest on the chair for around 5 to 10 minutes. When you're \n";
	cout << "\tready, you will be invited to have refreshments in the recovery area. We like to keep an eye on\n";
	cout << "\tyou for another 10-15 minutes to make sure that you feel OK before leaving.\n";
}
inline void donation_benefits() {
	cout << "\nBenefits of donating Blood: \n";
	cout << "\n\tThe gift of blood can only be given from one person to another, and there is no substitute. \n";
	cout << "\tRegular weekly donations ensure blood and plasma are available for those in need.\n";
	cout << "\tHowever, the need for blood and plasma is constant, so we're looking for more lifesavers.\n ";
	cout << "\tBy putting aside a small part of your day you can make a life-changing difference, \n ";
	cout << "\tyou can become a lifesaver too!\n\n";
	cout << "Reasons to donate: \n";
	cout << "\n\t1. One blood donation can save up to 3 lives.\n";
	cout << "\t2. Make a difference in your community by helping others.\n";
	cout << "\t3. Pay it forward. One day whanau, friends or even you may need it.\n";
	cout << "\t4. Join an extraordinary group of lifesavers.\n";
	cout << "\t5. Donating regularly ensures that a safe and plentiful supply of blood is available \n";
	cout << "\twhenever and wherever it is needed.\n";
	cout << "\t6.Less than 3% of people in New Zealand are blood donors.\n";
	cout << "\t7.Whether you choose to give blood, plasma or platelets, your donation will save and \n";
	cout << "\timprove the lives of people across New Zealand.\n";
}

void searchDonorInfo_BloodGroup(char search[])
{
	fstream DonorFile;
	Registration_Donor donor;
	int i = 1;
	DonorFile.open("donor.dat", ios::in | ios::out | ios::binary);
	if (!DonorFile)
	{
		cout << "File not found!";
	}
	else
	{
		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		while (!DonorFile.eof())
		{
			if (strcmp(search, donor.BloodGroup) == 0)
			{
				cout << "\nDonor Form [" << i << "] " << endl;
				cout << "----------------" << endl;
				cout << "Name : " << donor.FirstName << " " << donor.LastName << endl;
				cout << "Gender : " << donor.Gender << endl;
				cout << "Blood Group : [" << donor.BloodGroup << "]" << endl;
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				cout << "Conditions : " << donor.Conditions << endl;
				cout << "-----------------------------------------------------------------------------------------------------------" << endl;
				if (DonorFile.eof())
				{
					break;
				}
				else
				{
					cout << "Press any key to for next form ...";
					cin.get();
				}
			}
			i++;
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}
	}
	DonorFile.close();
}

void searchDonorInfo_BloodGroup_Location(char blood[], char location[])
{
	fstream DonorFile;
	Registration_Donor donor;
	int i = 1;
	DonorFile.open("donor.dat", ios::in | ios::out | ios::binary);
	if (!DonorFile)
	{
		cout << "File not found!";
	}
	else
	{
		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		while (!DonorFile.eof())
		{
			if (location != donor.Hospital_Name)
			{
				cout << "Location not found!...\n" << endl;
				return;
			}
			else
			{
				if (strcmp(blood, donor.BloodGroup) == 0 && strcmp(location, donor.Hospital_Name) == 0)
				{
					cout << "Donor Form [" << i << "] " << endl;
					cout << "----------------" << endl;
					cout << "Name : " << donor.FirstName << " " << donor.LastName << endl;
					cout << "Gender : " << donor.Gender << endl;
					cout << "Hospital : [" << donor.Hospital_Name << "]" << endl;
					cout << "Blood Group : [" << donor.BloodGroup << "]" << endl;
					cout << "-----------------------------------------------------------------------------------------------------------" << endl;
					cout << "Conditions : " << donor.Conditions << endl;
					cout << "-----------------------------------------------------------------------------------------------------------" << endl << endl;
					i++;
				}
			}
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}
	}
	DonorFile.close();
}

void update_donor_information() {

	fstream DonorFile;
	Registration_Donor edit_donor;
	DonorFile.open("donor.dat", ios::in | ios::out | ios::binary);

	if (!DonorFile)
	{
		cout << "Donor File not found! ";
	}

	int edit_donor_choice;

	while (1) {
		cout << "\nManage donor information menu : \n";
		cout << "\n1. Update contact details : ";
		cout << "\n2. Update health status : ";
		cout << "\n3. Change your current booking : ";
		cout << "\n4. Back\n";
		cout << "Please enter option : ";
		cin >> edit_donor_choice;
		DonorFile.seekg(current_donor_position * sizeof(edit_donor), ios::beg);
		DonorFile.read(reinterpret_cast<char*>(&edit_donor), sizeof(edit_donor));
		cin.ignore();
		switch (edit_donor_choice)
		{
		case 1:
			char temp5;

			cout << "\nFirst Name:";
			cin.getline(edit_donor.FirstName, Size);
			cout << "\nMiddle Name:";
			cin.getline(edit_donor.MiddleName, Size);
			cout << "\nLast Name:";
			cin.getline(edit_donor.LastName, Size);
			cout << "\nDate of birth:";
			cin.getline(edit_donor.DOB, Size);

			cout << "\nGender (M/F/X - Other): ";
			cin >> temp5;
			while (temp5 != 'M' && temp5 != 'F' && temp5 != 'X' && temp5 != 'm' && temp5 != 'f' && temp5 != 'x')
			{
				system("CLS"); // clear screen
				cout << "\nPlease try again" << endl;
				cout << "Gender (M/F/X - Other): ";
				cin >> temp5;
			}
			edit_donor.Gender = temp5;
			cin.ignore();

			cout << "\nNationality:";
			cin.getline(edit_donor.Nationalty, Size);
			cout << "\nEthnicity:";
			cin.getline(edit_donor.Ethnicity, Size);
			cout << "\nCity:";
			cin.getline(edit_donor.City, Size);
			cout << "\nAddress:";
			cin.getline(edit_donor.Address, Size);
			cout << "\nContact Number:";
			cin.getline(edit_donor.ContactNumber, Size);
			cout << "\nEmail:";
			cin.getline(edit_donor.Email, Size);
			break;
		case 2:
			cout << "\nealth Conditions:";
			cin.getline(edit_donor.Conditions, Size);
			break;
		case 3:
			cout << "\nChange current booking: ";
			break;
		case 4:
			return;
		default:
			cout << "\nPlease enter a valid option..\n";
			break;
		}
		DonorFile.seekp(current_donor_position * sizeof(edit_donor), ios::beg);
		DonorFile.write(reinterpret_cast<char*>(&edit_donor), sizeof(edit_donor));
	}

	DonorFile.close();
}
void create_booking() {
	/*
			###########################################################
		   createBooking()
		   displayBooking()
		   editBooking()

		   weekly display
		   Do a starting date for a week.
		   and an ending date.
		   Make Booking struct., store this in .dat file.
		   hospital..
		   State assumptions..

		   Name : Example
		   DOB : 00/00/0000
		   Condition : None
		   Date : 00/00/0000
		   Time : 00:00(AM / PM)

								 Time Available
								---------------
		  -----------------------------------------------------------------
		  |(Not Available)|  (Available)  |(Not Available)|(Not Available)|
		  |    9:00AM    |    10:00AM     |     11:00AM    |     12:00PM |
		  -----------------------------------------------------------------
		  |(Not Available)|  (Available)  |  (Available)  |(Not Available)|
		  |    1:00PM     |    2:00PM     |    3:00PM     |    4:00PM      |
		  -----------------------------------------------------------------
		  Booking_screen()
	*			Booking for the donation must access the donor’s full name, dob, recent health
				condition, date, time, and
		*/
		//please enter the starting date of the week 
		//you would like to donate blood in. E.g : 1/1/2021
		//please enter the ending date of the week
		//you would like to donate blood in. E.g : 7/1/2021
		//get current hospital name. + other details.
		//Then display current bookings for this hospital. During this week.
		//Please enter a day in which you would like to visit.
		// Please enter the time of donation.
		//Here is your current booking..

		//Farhan said I could preset values for unavailable bookings and then could just use donor.bookingtime etc.
		//donor.bookingyear, month, day. , donor.bookingtime

}


/*
*GET RID OF CURRENT DONOR FUNCTION ETC...
* Remove the use of a global variable
*
* Then we have to make sure the variables follow same naming styles, i.e only _'s or camelCase.
* all initialsed structs.
* Most efficient ways possible.
* Little code reuse.
* Lots of github commits. commit in small funcitons.
* current problem : when dat file for donors doesn't exist. and register one user. Then enter incorrect data. Getline doesnt work.
* Should have a check that makes sure user name and password doesnt already exist in database!!
* type checking for switch cases and throw exceptions / handling.!! A+ !!. ROBUST

	/* Recipient_Menu()

		1. Donors Information by Blood Group
		"Get all donors contacts by the same blood group they have looked up"

		" User Input(Blood Group) : A+

			---Information Found---

		" Name: Example 1
		" Blood Group : A+
		" Location : Christchurch

		" Name : Example 2
		" Blood Group : A+
		" Location : Auckland "

		2. Donors by Blood Group and Location
		"All donors names by type of blood group and location"

		" User Input(Blood Group) : A+
		  User Input(Location) : Christhcurch


			---Information Found---

		" Name: Example 1
		" Blood Group : A+
		" Location : Christchurch

		" Name : Example 2
		" Blood Group : A+
		" Location : Chirstchurch

		3. Donors contacts (find by given full name)      */




		//************************************************************
				/* Admin_Menu()

					1. View Recipient and Donors information
						all_reports();

					" [Recipient]         |        [Donor]
										  |
						 Contact [1]      |      Contact [1]
					  Name : _______      |        Name : _______
					  Blood Group : __    |        Blood Group : __
					  Location : ______   |        Location : _______
					  ------------------------------------------------
						 Contact [2]      |      Contact [2]
					  Name : _______      |        Name : _______
					  Blood Group : __    |        Blood Group : __
					  Location : ______   |        Location : _______
					  ------------------------------------------------
						 Contact [3]      |      Contact [3]
					  Name : _______      |        Name : _______
					  Blood Group : __    |        Blood Group : __
					  Location : ______   |        Location : _______ "

					  We don't technically have match up donors and recipients, just have to show available donors.

					  2. Update donors blood test report

					  3. Donors report

					  4. Recipient report

					  5. Report by blood group

					  6. Report by location
				*/





