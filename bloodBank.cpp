//Michael Kemp and Bailey Crawford 2021 Yoobee Colleges.
/*
Then we have to make sure the variables follow same naming styles, i.e only _'s or camelCase.
Comment thoroughly
Best Practises, no empty for loops etc.
Type check with throw exception for switch case menus.
Make sure code entered doesnt exceed buffers.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

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
	char hasBooking[20];
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

struct donorBooking {
	char start_day[20];
	char start_month[20];
	char start_year[20];

	char booking_date_day[20];
	char booking_date_month[20];
	char booking_date_year[20];

	char booking_time[20];
	char booking_day_name[20];

	//REUSE of members because, nesting structs stored in .dat files causes problems..
	char FirstName[Size];
	char MiddleName[Size];
	char LastName[Size];
	char DOB[Size]; // Date Of Birth
	char Conditions[255];
	char Hospital_Name[100];
	char serial[100];
	char Username[20];
};

// Register Functions
void RegisterRecipient();
void RegisterDonor();

// Login Functions
bool DonorLogin();
bool RecipientLogin(char tempUsername[]);
bool AdminLogin();

// Display Function
void displayRecipientFile(char tempUsername[]);

// Validation Functions 
//-----------------------------------------------------
// Check Login (aren't the same) Function
bool checkUsername(string fileName, char username[]);

// Check array size isnt above array limit
bool checkValidArraySize(char arr[], int setSize);

// Check array if only Alphabet letters are inside
bool checkValidInput(char arr[]);

// Check array if only Numbers are inside
bool checkValidNumbers(char arr[]);

// Check string if only Alphabet letters are inside
bool checkValidStringInput(string str);

// Check string if only Numbers are inside
bool checkValidStringNumberInput(string str);

bool validationSwitchCase(int choice);
//-----------------------------------------------------

// Main Menu
void mainmenu();

// Donor Functions
void donorScreen();
inline void procedureToDonate();
inline void donationBenefits();
void updateDonorInformation();
void createBooking();
void displayBooking(char uname[Size]);
void updateDonorBookingStatus(string value);
void deleteBooking(string uname);

// Recipient Functions
void recipientScreen(char tempUsername[]);
void searchDonorInfoBloodGroup(char search[]);
void searchDonorInfoBloodGroupLocation(char blood[], char location[]);
void getDonorContacts();
bool getValidation(char validation);
void checkVal(Registration_Recipient recipient);

// Admin Functions
void adminScreen();
void displayRecipientForAdmin();
void displayDonorForAdmin();
void displayDonorReport();
void searchDonorBloodGroupReport(char blood[]);
void displayRecipientReport();
void searchRecipientBloodGroupReport(char blood[]);
void searchDonorLocationReport(char search[]);
void searchRecipientLocationReport(char search[]);
void updateDonorReport(char uname[]);

//Misc
void inline printline(int size, char symbol);

streamsize current_donor_position = 0;

int main()
{
	srand(time(NULL));
	mainmenu();

	return 0;
}

void mainmenu()
{
	fstream RecipientFile;
	fstream DonorFile;
	int choice;
	bool check = true;
	bool checkSwitchCase;
	int donor_record_found = false;


	cout << "Welcome to the New Zealand Blood Bank Administration Program." << endl;
	cout << "\nRegular weekly donations ensure blood and plasma are available for those in need.\n";
	cout << "The gift of blood can only be given from one person to another, and there is no substitute.\n";
	cout << "So it's nice to know New Zealand can rely on everyday heroes.\n";
	cout << "generosity to keep the flow of blood and plasma going.\n";
	cout << "However, the need for bloodand plasma is constant, so we're looking for more lifesavers.\n";
	cout << "By putting aside a small part of your day you can make a life-changing\n";
	cout << "difference, you can become a lifesaver too! \n\n";

	cout << "Main Menu:" << endl;

	while (check != false)
	{
		cout << endl;
		cout << "1. Login Donor" << endl;
		cout << "2. Login Recipient" << endl;
		cout << "3. Register Donor" << endl;
		cout << "4. Register Recipient" << endl;
		cout << "5. Login Admin" << endl;
		cout << "6. Quit" << endl << endl;

		cout << "Please enter option : ";

		cin >> choice;

		while (cin.fail())
		{
			cout << "\nPlease enter a valid option.." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << endl;
			cout << "1. Login Donor" << endl;
			cout << "2. Login Recipient" << endl;
			cout << "3. Register Donor" << endl;
			cout << "4. Register Recipient" << endl;
			cout << "5. Login Admin" << endl;
			cout << "6. Quit" << endl << endl;

			cout << "Please enter option : ";
			cin >> choice;
		}

		cin.ignore();
		cout << endl << endl;

		if (choice == 1)
		{
			bool account_found = false;
			int attempts = 0;


			cout << "\nDonor Login" << endl << endl;

			while (account_found == false && attempts < 3)
			{
				account_found = DonorLogin();
				attempts++;
			}
			if (account_found) {
				donorScreen();
			}
			cout << endl;
		}
		else if (choice == 2)
		{
			bool account_found2 = false;
			int attempts2 = 0;
			char tempUsername[20];
			cout << "\nRecipient Login" << endl << endl;

			while (account_found2 == false && attempts2 < 3)
			{

				account_found2 = RecipientLogin(tempUsername);
				attempts2++;
			}
			if (account_found2) {
				recipientScreen(tempUsername);
			}
			cout << endl;
		}
		else if (choice == 3)
		{
			RegisterDonor();
			cout << endl << endl;
		}
		else if (choice == 4)
		{
			RegisterRecipient();
			cout << endl << endl;
		}
		else if (choice == 5)
		{
			bool account_found3 = false;
			int attempts3 = 0;

			cout << "Admin Login" << endl << endl;

			while (account_found3 == false && attempts3 < 3)
			{
				account_found3 = AdminLogin();
				attempts3++;
			}
			if (account_found3)
			{
				adminScreen();
				cout << endl << endl;
			}
			cout << endl << endl;
		}
		else if (choice == 6)
		{
			cout << "Quit" << endl;
			check = false;
			break;
		}
		else
		{
			cout << "Please enter a valid option.." << endl;
		}
	}
}

//Register Functions.
void RegisterRecipient()
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	bool tempAlphabetValid;
	bool tempArraySize;
	bool tempNumberValid;

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
	char tempGender;
	char temp;

	cout << " Rigster Recipient" << endl;
	cout << "-------------------\n" << endl;

	// First Name -------------------------------------------------------------------------------------
	cout << "First Name : ";
	cin >> recipient.FirstName;

	tempAlphabetValid = checkValidInput(recipient.FirstName);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "First Name : ";
		cin >> recipient.FirstName;
		tempAlphabetValid = checkValidInput(recipient.FirstName);
	}

	tempArraySize = checkValidArraySize(recipient.FirstName, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "First Name : ";
		cin >> recipient.FirstName;
		tempAlphabetValid = checkValidInput(recipient.FirstName);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "First Name : ";
			cin >> recipient.FirstName;
			tempAlphabetValid = checkValidInput(recipient.FirstName);
		}

		tempArraySize = checkValidArraySize(recipient.FirstName, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Middle Name -----------------------------------------------------------------------------------
	cout << "Middle Name : ";
	cin >> recipient.MiddleName;

	tempAlphabetValid = checkValidInput(recipient.MiddleName);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Middle Name : ";
		cin >> recipient.MiddleName;
		tempAlphabetValid = checkValidInput(recipient.MiddleName);
	}

	tempArraySize = checkValidArraySize(recipient.MiddleName, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Middle Name : ";
		cin >> recipient.MiddleName;
		tempAlphabetValid = checkValidInput(recipient.MiddleName);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Middle Name : ";
			cin >> recipient.MiddleName;
			tempAlphabetValid = checkValidInput(recipient.MiddleName);
		}

		tempArraySize = checkValidArraySize(recipient.MiddleName, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Last Name -------------------------------------------------------------------------------------
	cout << "Last Name : ";
	cin >> recipient.LastName;

	tempAlphabetValid = checkValidInput(recipient.LastName);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Last Name : ";
		cin >> recipient.LastName;
		tempAlphabetValid = checkValidInput(recipient.LastName);
	}

	tempArraySize = checkValidArraySize(recipient.LastName, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Last Name : ";
		cin >> recipient.LastName;
		tempAlphabetValid = checkValidInput(recipient.LastName);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Last Name : ";
			cin >> recipient.LastName;
			tempAlphabetValid = checkValidInput(recipient.LastName);
		}

		tempArraySize = checkValidArraySize(recipient.LastName, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Date of Birth ---------------------------------------------------------------------------------
	cout << "Date Of Birth : ";
	cin >> recipient.DOB;
	tempArraySize = checkValidArraySize(recipient.DOB, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Date Of Birth : ";
		cin >> recipient.DOB;
		tempArraySize = checkValidArraySize(recipient.DOB, Size);
	}
	cin.ignore();
	// -----------------------------------------------------------------------------------------------


	// Nationality -----------------------------------------------------------------------------------
	cout << "Nationality : ";
	cin >> recipient.Nationalty;
	tempAlphabetValid = checkValidInput(recipient.Nationalty);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Nationalty : ";
		cin >> recipient.Nationalty;
		tempAlphabetValid = checkValidInput(recipient.Nationalty);
	}

	tempArraySize = checkValidArraySize(recipient.Nationalty, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Nationalty : ";
		cin >> recipient.Nationalty;
		tempAlphabetValid = checkValidInput(recipient.Nationalty);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Nationalty : ";
			cin >> recipient.Nationalty;
			tempAlphabetValid = checkValidInput(recipient.Nationalty);
		}

		tempArraySize = checkValidArraySize(recipient.Nationalty, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// City ------------------------------------------------------------------------------------------
	cout << "City : ";
	cin >> recipient.City;
	tempAlphabetValid = checkValidInput(recipient.City);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "City : ";
		cin >> recipient.City;
		tempAlphabetValid = checkValidInput(recipient.City);
	}

	tempArraySize = checkValidArraySize(recipient.City, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "City : ";
		cin >> recipient.City;
		tempAlphabetValid = checkValidInput(recipient.City);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "City : ";
			cin >> recipient.City;
			tempAlphabetValid = checkValidInput(recipient.City);
		}

		tempArraySize = checkValidArraySize(recipient.City, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Hospital --------------------------------------------------------------------------------------
	cout << "Hospital : ";
	cin >> recipient.Hospital_Name;
	tempAlphabetValid = checkValidInput(recipient.Hospital_Name);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Hospital : ";
		cin >> recipient.Hospital_Name;
		tempAlphabetValid = checkValidInput(recipient.Hospital_Name);
	}

	tempArraySize = checkValidArraySize(recipient.Hospital_Name, 100);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 100 characters limit." << endl;
		cout << "Hospital : ";
		cin >> recipient.Hospital_Name;
		tempAlphabetValid = checkValidInput(recipient.Hospital_Name);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Hospital : ";
			cin >> recipient.Hospital_Name;
			tempAlphabetValid = checkValidInput(recipient.Hospital_Name);
		}

		tempArraySize = checkValidArraySize(recipient.Hospital_Name, 100);
	}
	// -----------------------------------------------------------------------------------------------


	// Ethnicity -------------------------------------------------------------------------------------
	cout << "Ethnicity : ";
	cin >> recipient.Ethnicity;
	tempAlphabetValid = checkValidInput(recipient.Ethnicity);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Ethnicity : ";
		cin >> recipient.Ethnicity;
		tempAlphabetValid = checkValidInput(recipient.Ethnicity);
	}

	tempArraySize = checkValidArraySize(recipient.Ethnicity, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Ethnicity : ";
		cin >> recipient.Ethnicity;
		tempAlphabetValid = checkValidInput(recipient.Ethnicity);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Ethnicity : ";
			cin >> recipient.Ethnicity;
			tempAlphabetValid = checkValidInput(recipient.Ethnicity);
		}

		tempArraySize = checkValidArraySize(recipient.Ethnicity, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Gender ----------------------------------------------------------------------------------------
	cout << "Gender (M/F/X - Other): ";
	cin >> tempGender;

	while (tempGender != 'M' && tempGender != 'F' && tempGender != 'X' && tempGender != 'm' && tempGender != 'f' && tempGender != 'x')
	{
		cin.ignore(100, '\n');
		//system("CLS"); // clear screen

		cout << "\nPlease try again" << endl;
		cout << "Gender (M/F/X - Other): ";
		cin >> tempGender;
	}
	recipient.Gender = tempGender;
	// -----------------------------------------------------------------------------------------------


	// Conditions ------------------------------------------------------------------------------------
	cout << "Any Health Conditions : ";
	cin >> recipient.Conditions;
	tempAlphabetValid = checkValidInput(recipient.Conditions);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Any Health Conditions : ";
		cin >> recipient.Conditions;
		tempAlphabetValid = checkValidInput(recipient.Conditions);
	}

	tempArraySize = checkValidArraySize(recipient.Conditions, 255);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 255 characters limit." << endl;
		cout << "Any Health Conditions : ";
		cin >> recipient.Conditions;
		tempAlphabetValid = checkValidInput(recipient.Conditions);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Any Health Conditions : ";
			cin >> recipient.Conditions;
			tempAlphabetValid = checkValidInput(recipient.Conditions);
		}

		tempArraySize = checkValidArraySize(recipient.Conditions, 255);
	}
	// -----------------------------------------------------------------------------------------------


	// Blood Group -----------------------------------------------------------------------------------
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

	// -----------------------------------------------------------------------------------------------


	// Contact Number --------------------------------------------------------------------------------
	cout << "Contact Number : ";
	cin >> recipient.ContactNumber;
	tempNumberValid = checkValidNumbers(recipient.ContactNumber);
	while (tempNumberValid != true)
	{
		cout << "\nPlease try again with using number characters." << endl;
		cout << "Contact Number : ";
		cin >> recipient.ContactNumber;
		tempNumberValid = checkValidNumbers(recipient.ContactNumber);
	}

	tempArraySize = checkValidArraySize(recipient.ContactNumber, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Contact Number : ";
		cin >> recipient.ContactNumber;
		tempNumberValid = checkValidNumbers(recipient.ContactNumber);

		while (tempNumberValid != true)
		{
			cout << "\nPlease try again with using number characters." << endl;
			cout << "Contact Number : ";
			cin >> recipient.ContactNumber;
			tempNumberValid = checkValidNumbers(recipient.ContactNumber);
		}

		tempArraySize = checkValidArraySize(recipient.ContactNumber, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Email -----------------------------------------------------------------------------------------
	cout << "Email : ";
	cin >> recipient.Email;
	tempArraySize = checkValidArraySize(recipient.Email, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Email : ";
		cin >> recipient.Email;

		tempArraySize = checkValidArraySize(recipient.Email, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Address ---------------------------------------------------------------------------------------
	cout << "Address : ";
	cin >> recipient.Address;
	tempArraySize = checkValidArraySize(recipient.Address, 100);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 100 characters limit." << endl;
		cout << "Address : ";
		cin >> recipient.Address;

		tempArraySize = checkValidArraySize(recipient.Address, 100);
	}
	// -----------------------------------------------------------------------------------------------


	// Username --------------------------------------------------------------------------------------
	bool tempBoolUsername;
	bool check = false;
	int i;
	char tempusername[20];
	string fileName = "recipient.dat";

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


	tempBoolUsername = checkUsername(fileName, tempusername);

	while (tempBoolUsername != false)
	{

		bool check = false;
		int i;

		cout << "\nUsername Already exists! \n" << endl;

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

		tempBoolUsername = checkUsername(fileName, tempusername);
	}

	check = false;

	for (int i = 0; i < 20; i++)
	{
		recipient.Username[i] = tempusername[i];
	}
	// -----------------------------------------------------------------------------------------------


	// Password --------------------------------------------------------------------------------------
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
	// -----------------------------------------------------------------------------------------------


	// Validation Check ------------------------------------------------------------------------------
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
	// -----------------------------------------------------------------------------------------------

	cout << endl;
	cin.ignore();

	RecipientFile.write(reinterpret_cast<char*>(&recipient), sizeof(recipient));

	RecipientFile.close();
}
void RegisterDonor()
{
	fstream DonorFile;
	Registration_Donor donor;
	bool tempAlphabetValid;
	bool tempArraySize;
	bool tempNumberValid;

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
	char tempGender;

	cout << " Register Donor" << endl;
	cout << "-------------------\n" << endl;

	// First Name -------------------------------------------------------------------------------------
	cout << "First Name : ";
	cin >> donor.FirstName;

	tempAlphabetValid = checkValidInput(donor.FirstName);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "First Name : ";
		cin >> donor.FirstName;
		tempAlphabetValid = checkValidInput(donor.FirstName);
	}

	tempArraySize = checkValidArraySize(donor.FirstName, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "First Name : ";
		cin >> donor.FirstName;
		tempAlphabetValid = checkValidInput(donor.FirstName);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "First Name : ";
			cin >> donor.FirstName;
			tempAlphabetValid = checkValidInput(donor.FirstName);
		}

		tempArraySize = checkValidArraySize(donor.FirstName, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Middle Name -----------------------------------------------------------------------------------
	cout << "Middle Name : ";
	cin >> donor.MiddleName;

	tempAlphabetValid = checkValidInput(donor.MiddleName);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Middle Name : ";
		cin >> donor.MiddleName;
		tempAlphabetValid = checkValidInput(donor.MiddleName);
	}

	tempArraySize = checkValidArraySize(donor.MiddleName, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Middle Name : ";
		cin >> donor.MiddleName;
		tempAlphabetValid = checkValidInput(donor.MiddleName);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Middle Name : ";
			cin >> donor.MiddleName;
			tempAlphabetValid = checkValidInput(donor.MiddleName);
		}

		tempArraySize = checkValidArraySize(donor.MiddleName, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Last Name -------------------------------------------------------------------------------------
	cout << "Last Name : ";
	cin >> donor.LastName;

	tempAlphabetValid = checkValidInput(donor.LastName);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Last Name : ";
		cin >> donor.LastName;
		tempAlphabetValid = checkValidInput(donor.LastName);
	}

	tempArraySize = checkValidArraySize(donor.LastName, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Last Name : ";
		cin >> donor.LastName;
		tempAlphabetValid = checkValidInput(donor.LastName);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Last Name : ";
			cin >> donor.LastName;
			tempAlphabetValid = checkValidInput(donor.LastName);
		}

		tempArraySize = checkValidArraySize(donor.LastName, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Date of Birth ---------------------------------------------------------------------------------
	cout << "Date Of Birth : ";
	cin >> donor.DOB;
	tempArraySize = checkValidArraySize(donor.DOB, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Date Of Birth : ";
		cin >> donor.DOB;
		tempArraySize = checkValidArraySize(donor.DOB, Size);
	}
	cin.ignore();
	// -----------------------------------------------------------------------------------------------


	// Nationality -----------------------------------------------------------------------------------
	cout << "Nationality : ";
	cin >> donor.Nationalty;
	tempAlphabetValid = checkValidInput(donor.Nationalty);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Nationalty : ";
		cin >> donor.Nationalty;
		tempAlphabetValid = checkValidInput(donor.Nationalty);
	}

	tempArraySize = checkValidArraySize(donor.Nationalty, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Nationalty : ";
		cin >> donor.Nationalty;
		tempAlphabetValid = checkValidInput(donor.Nationalty);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Nationalty : ";
			cin >> donor.Nationalty;
			tempAlphabetValid = checkValidInput(donor.Nationalty);
		}

		tempArraySize = checkValidArraySize(donor.Nationalty, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// City ------------------------------------------------------------------------------------------
	cout << "City : ";
	cin >> donor.City;
	tempAlphabetValid = checkValidInput(donor.City);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "City : ";
		cin >> donor.City;
		tempAlphabetValid = checkValidInput(donor.City);
	}

	tempArraySize = checkValidArraySize(donor.City, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "City : ";
		cin >> donor.City;
		tempAlphabetValid = checkValidInput(donor.City);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "City : ";
			cin >> donor.City;
			tempAlphabetValid = checkValidInput(donor.City);
		}

		tempArraySize = checkValidArraySize(donor.City, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Hospital --------------------------------------------------------------------------------------
	cout << "Hospital : ";
	cin >> donor.Hospital_Name;
	tempAlphabetValid = checkValidInput(donor.Hospital_Name);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Hospital : ";
		cin >> donor.Hospital_Name;
		tempAlphabetValid = checkValidInput(donor.Hospital_Name);
	}

	tempArraySize = checkValidArraySize(donor.Hospital_Name, 100);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 100 characters limit." << endl;
		cout << "Hospital : ";
		cin >> donor.Hospital_Name;
		tempAlphabetValid = checkValidInput(donor.Hospital_Name);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Hospital : ";
			cin >> donor.Hospital_Name;
			tempAlphabetValid = checkValidInput(donor.Hospital_Name);
		}

		tempArraySize = checkValidArraySize(donor.Hospital_Name, 100);
	}
	// -----------------------------------------------------------------------------------------------


	// Ethnicity -------------------------------------------------------------------------------------
	cout << "Ethnicity : ";
	cin >> donor.Ethnicity;
	tempAlphabetValid = checkValidInput(donor.Ethnicity);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Ethnicity : ";
		cin >> donor.Ethnicity;
		tempAlphabetValid = checkValidInput(donor.Ethnicity);
	}

	tempArraySize = checkValidArraySize(donor.Ethnicity, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Ethnicity : ";
		cin >> donor.Ethnicity;
		tempAlphabetValid = checkValidInput(donor.Ethnicity);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Ethnicity : ";
			cin >> donor.Ethnicity;
			tempAlphabetValid = checkValidInput(donor.Ethnicity);
		}

		tempArraySize = checkValidArraySize(donor.Ethnicity, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Gender ----------------------------------------------------------------------------------------
	cout << "Gender (M/F/X - Other): ";
	cin >> tempGender;

	while (tempGender != 'M' && tempGender != 'F' && tempGender != 'X' && tempGender != 'm' && tempGender != 'f' && tempGender != 'x')
	{
		cin.ignore(100, '\n');
		//system("CLS"); // clear screen

		cout << "\nPlease try again" << endl;
		cout << "Gender (M/F/X - Other): ";
		cin >> tempGender;
	}
	donor.Gender = tempGender;
	// -----------------------------------------------------------------------------------------------


	// Conditions ------------------------------------------------------------------------------------
	cout << "Any Health Conditions : ";
	cin >> donor.Conditions;
	tempAlphabetValid = checkValidInput(donor.Conditions);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using alphabet characters." << endl;
		cout << "Any Health Conditions : ";
		cin >> donor.Conditions;
		tempAlphabetValid = checkValidInput(donor.Conditions);
	}

	tempArraySize = checkValidArraySize(donor.Conditions, 255);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Any Health Conditions : ";
		cin >> donor.Conditions;
		tempAlphabetValid = checkValidInput(donor.Conditions);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Any Health Conditions : ";
			cin >> donor.Conditions;
			tempAlphabetValid = checkValidInput(donor.Conditions);
		}

		tempArraySize = checkValidArraySize(donor.Conditions, 255);
	}
	// -----------------------------------------------------------------------------------------------


	// Blood Group -----------------------------------------------------------------------------------
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

	cin.ignore();

	// -----------------------------------------------------------------------------------------------


	// Contact Number --------------------------------------------------------------------------------
	cout << "Contact Number : ";
	cin >> donor.ContactNumber;
	tempAlphabetValid = checkValidNumbers(donor.ContactNumber);
	while (tempAlphabetValid != true)
	{
		cout << "\nPlease try again with using number characters." << endl;
		cout << "Contact Number : ";
		cin >> donor.ContactNumber;
		tempAlphabetValid = checkValidNumbers(donor.ContactNumber);
	}

	tempArraySize = checkValidArraySize(donor.ContactNumber, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Contact Number : ";
		cin >> donor.ContactNumber;
		tempAlphabetValid = checkValidNumbers(donor.ContactNumber);

		while (tempAlphabetValid != true)
		{
			cout << "\nPlease try again with using number characters." << endl;
			cout << "Contact Number : ";
			cin >> donor.ContactNumber;
			tempAlphabetValid = checkValidNumbers(donor.ContactNumber);
		}

		tempArraySize = checkValidArraySize(donor.ContactNumber, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Email -----------------------------------------------------------------------------------------
	cout << "Email : ";
	cin >> donor.Email;
	tempArraySize = checkValidArraySize(donor.Email, Size);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Email : ";
		cin >> donor.Email;

		tempArraySize = checkValidArraySize(donor.Email, Size);
	}
	// -----------------------------------------------------------------------------------------------


	// Address ---------------------------------------------------------------------------------------
	cout << "Address : ";
	cin >> donor.Address;
	tempArraySize = checkValidArraySize(donor.Address, 100);
	while (tempArraySize != true)
	{
		cout << "\nPlease try again with only 31 characters limit." << endl;
		cout << "Address : ";
		cin >> donor.Address;

		tempArraySize = checkValidArraySize(donor.Address, 100);
	}
	// -----------------------------------------------------------------------------------------------


	// Username --------------------------------------------------------------------------------------
	bool tempBoolUsername;
	bool check = false;
	int i;
	char tempusername[30];
	string fileName = "donor.dat";

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


	tempBoolUsername = checkUsername(fileName, tempusername);

	while (tempBoolUsername != false)
	{

		bool check = false;
		int i;

		cout << "\nUsername Already exists! \n" << endl;

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
				cout << "Only 20 Maximum characters" << endl;
				cout << "Username : ";
				cin >> tempusername;
				check = false;
			}
			else if (i < 20)
			{
				check = true;
				break;
			}
		}

		tempBoolUsername = checkUsername(fileName, tempusername);
	}

	check = false;

	for (int i = 0; i < 20; i++)
	{
		donor.Username[i] = tempusername[i];
	}
	// -----------------------------------------------------------------------------------------------


	// Password --------------------------------------------------------------------------------------
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
			cout << "Only 20 Maximum characters" << endl;
			cout << "Password : ";
			cin >> donor.Password;
		}
		else if (i < 20)
		{
			check = true;
			break;
		}
	}
	// -----------------------------------------------------------------------------------------------

	DonorFile.write(reinterpret_cast<char*>(&donor), sizeof(donor));

	DonorFile.close();
}

//Login Functions.
bool RecipientLogin(char tempUsername[])
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	char username[20];
	char password[20];
	string user, pass;
	bool found_flag = false;

	RecipientFile.open("recipient.dat", ios::in | ios::binary);

	if (!RecipientFile)
	{
		cout << "File not found";
	}
	else {
		//Buffer validation check.
		cout << "\nLogin" << endl << endl;
		cout << "Username : ";
		getline(cin, user);
		while (user.length() > 20) {
			cout << "\nPlease enter username less than 20 characters: ";
			getline(cin, user);
		}
		//Copy string into character array if correct.
		strcpy_s(username, user.c_str());

		cout << "Password : ";
		getline(cin, pass);
		while (pass.length() > 20) {
			cout << "\nPlease enter password less than 20 characters: ";
			getline(cin, pass);
		}
		//Copy string into character array if correct.
		strcpy_s(password, pass.c_str());
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));

		while (!RecipientFile.eof())
		{
			if (strcmp(username, recipient.Username) == 0 && strcmp(password, recipient.Password) == 0) {
				cout << "\nWelcome back " << recipient.Username << "!\n";

				for (int i = 0; i < 20; i++)
				{
					tempUsername[i] = *(recipient.Username + i);
				}

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
bool DonorLogin()
{

	fstream DonorFile;
	Registration_Donor donor;
	char username[20];
	char password[20];
	string user, pass;
	bool found_flag = false;

	DonorFile.open("donor.dat", ios::in | ios::binary);

	if (!DonorFile)
	{
		//currently printing 3 times as function called 3, just use argument value as fix lol
		cout << "Donor File not found! ";
	}
	else {
		//Buffer validation check.
		cout << "\nLogin" << endl << endl;
		cout << "Username : ";
		getline(cin, user);
		while (user.length() > 20) {
			cout << "\nPlease enter username less than 20 characters: ";
			getline(cin, user);
		}
		//Copy string into character array if correct.
		strcpy_s(username, user.c_str());

		cout << "Password : ";
		getline(cin, pass);
		while (pass.length() > 20) {
			cout << "\nPlease enter password less than 20 characters: ";
			getline(cin, pass);
		}
		//Copy string into character array if correct.
		strcpy_s(password, pass.c_str());
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
bool AdminLogin()
{
	Admin admin;

	string username;
	string password;
	bool found_flag = false;
	int tries = 0;

	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> password;
	cout << endl;

	if ((username != admin.Username) && (password != admin.Password))
	{
		cout << "\nAccount not found.. Exiting\n";
		found_flag = false;
		return found_flag;
	}
	else if ((username == admin.Username) && (password == admin.Password))
	{
		cout << "\nWelcome back " << admin.Username << "!\n";
		found_flag = true;
		return found_flag;
	}

	return found_flag;
}

//Check Logins aren't the same functions.
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

				RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
			}

		}

		RecipientFile.close();

		return false;
	}
	else
	{
		DonorFile.open("donor.dat", ios::in | ios::binary);

		if (!DonorFile)
		{
			return false;
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

				DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
			}

		}

		DonorFile.close();

		return false;
	}

	return false;

}

//Display Functions
void displayRecipientFile(char tempUsername[])
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	bool tempVal;

	RecipientFile.open("recipient.dat", ios::in | ios::binary);

	if (!RecipientFile)
	{
		cout << "File not found";
		return;
	}
	else
	{
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));

		while (!RecipientFile.eof())
		{
			if (strcmp(tempUsername, recipient.Username) == 0)
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

			}

			RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		}
	}
	RecipientFile.close();
}
void displayBooking(char username[Size]) {
	//Display a booking record based on donors' full name.
	fstream bookingFile;
	donorBooking book;
	bookingFile.open("booking.dat", ios::in | ios::out | ios::binary);


	if (!bookingFile)
	{
		cout << "Donor File not found! ";
		return;
	}


	bookingFile.read(reinterpret_cast<char*>(&book), sizeof(book));
	while (!bookingFile.eof()) {
		//display the booking based on the username of the donor.

		if (strcmp(username, book.Username) == 0) {

			cout << "Name : " << book.FirstName << " " << book.MiddleName << " " << book.LastName << "\n";
			cout << "DOB : " << book.DOB << "\n";
			cout << "Condition : " << book.Conditions << "\n";
			cout << "Booking Date " << book.booking_date_day << "/" << book.booking_date_month;
			cout << "/" << book.booking_date_year << endl;
			cout << "Booking Time :" << book.booking_time << "\n";
			cout << "Booking Location :" << book.Hospital_Name << "\n";
			//break;
		}
		bookingFile.read(reinterpret_cast<char*>(&book), sizeof(book));
	}
	bookingFile.close();
}

//Recipient Functions.
void recipientScreen(char tempUsername[])
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
		cout << "5. Back" << endl << endl;

		cout << "Please enter option : ";
		cin >> choice;

		while (cin.fail())
		{
			cout << "\nPlease enter a valid option.." << endl;
			cin.clear();
			cin.ignore(256, '\n');

			cout << "1. Search Donors Info by Blood group" << endl;
			cout << "2. Search Donors Info by Blood group & Location" << endl;
			cout << "3. Gather Donors contact details (By given Full Name)" << endl;
			cout << "4. Your Blood details" << endl;
			cout << "5. Back" << endl << endl;

			cout << "Please enter option : ";
			cin >> choice;
		}
		cout << endl;

		switch (choice)
		{
		case 1:
		{
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

			searchDonorInfoBloodGroup(inputBlood);

			cout << "Press any key to conintue ...";
			cin.get();
			cout << endl;

			break;
		}
		case 2:
		{
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
			bool tempAlphabetValid;
			bool tempArraySize;

			cout << "Here are all the Blood group options (or type 'back' to go back to the menu)" << endl;
			cout << "[A+] [A-]" << endl;
			cout << "[B+] [B-]" << endl;
			cout << "[O+] [O-]" << endl;
			cout << "[AB+] [AB-]" << endl << endl;

			cin.ignore();

			cout << "Blood Group : ";
			cin >> inputBlood;
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
				cin >> inputBlood;
				cout << endl;
			}

			cout << "Please enter the hospital name : ";
			cin >> location;

			// -------------------------------------------------------------------------
			tempAlphabetValid = checkValidInput(location);
			while (tempAlphabetValid != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "Hospital Name : ";
				cin >> location;
				tempAlphabetValid = checkValidInput(location);
			}

			tempArraySize = checkValidArraySize(location, 100);
			while (tempArraySize != true)
			{
				cout << "\nPlease try again with only 100 characters limit." << endl;
				cout << "Hospital : ";
				cin >> location;
				tempAlphabetValid = checkValidInput(location);

				while (tempAlphabetValid != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "Hospital : ";
					cin >> location;
					tempAlphabetValid = checkValidInput(location);
				}

				tempArraySize = checkValidArraySize(location, 100);
			}
			cout << endl;
			// -------------------------------------------------------------------------



			searchDonorInfoBloodGroupLocation(inputBlood, location);

			cout << "Press any key to conintue ...";
			cin.get();
			cin.ignore();
			cout << endl;
			break;
		}
		case 3:
		{
			// Get Donors Details - (By giving Full name) - (Not Middle name)
			getDonorContacts();
			break;
		}
		case 4:
		{
			// (Your Details)
			cout << endl;
			displayRecipientFile(tempUsername);
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
			cout << "Please enter a valid option.." << endl;
			break;
		}
		}
	}
}
void searchDonorInfoBloodGroup(char search[])
{
	fstream DonorFile;
	Registration_Donor donor;
	int i = 0;

	DonorFile.open("donor.dat", ios::in | ios::out | ios::binary);

	if (!DonorFile)
	{
		cout << "File not found!";
		return;
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
void searchDonorInfoBloodGroupLocation(char blood[], char location[])
{
	fstream DonorFile;
	Registration_Donor donor;
	int i = 0;

	DonorFile.open("donor.dat", ios::in | ios::binary);

	if (!DonorFile)
	{
		cout << "File not found!";
		return;
	}
	else
	{
		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		while (!DonorFile.eof())
		{
			if ((strcmp(location, donor.Hospital_Name) == 0) && (strcmp(blood, donor.BloodGroup) == 0))
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
			else
			{
				cout << "Location not found!...\n" << endl;
				return;
			}
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}
	}

	DonorFile.close();
}
void getDonorContacts()
{
	fstream DonorFile;
	Registration_Donor donor;

	bool found_user = false;
	bool checkValidLetter;
	bool checkValidSize;
	char firstName[Size];
	char lastName[Size];

	DonorFile.open("donor.dat", ios::in | ios::binary);

	if (!DonorFile)
	{
		cout << "File not found!";
		return;
	}
	else
	{
		// First Name Check --------------------------------------------
		cout << "Enter Donors First name : ";
		cin >> firstName;

		checkValidLetter = checkValidInput(firstName);
		while (checkValidLetter != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Enter Donors First name : ";
			cin >> firstName;

			checkValidLetter = checkValidInput(firstName);
		}

		checkValidSize = checkValidArraySize(firstName, Size);
		while (checkValidSize != true)
		{
			cout << "\nPlease try again with only 31 characters limit." << endl;
			cout << "Enter Donors First name : ";
			cin >> firstName;

			checkValidLetter = checkValidInput(firstName);
			while (checkValidLetter != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "Enter Donors First name : ";
				cin >> firstName;

				checkValidLetter = checkValidInput(firstName);
			}
			checkValidSize = checkValidArraySize(firstName, Size);
		}
		// -------------------------------------------------------------

		cout << endl;

		// Last Name Check ---------------------------------------------
		cout << "Enter Donors Last name : ";
		cin >> lastName;
		checkValidLetter = checkValidInput(lastName);
		while (checkValidLetter != true)
		{
			cout << "\nPlease try again with using alphabet characters." << endl;
			cout << "Enter Donors Last name : ";
			cin >> lastName;

			checkValidLetter = checkValidInput(lastName);
		}

		checkValidSize = checkValidArraySize(lastName, Size);
		while (checkValidSize != true)
		{
			cout << "\nPlease try again with only 31 characters limit." << endl;
			cout << "Enter Donors Last name : ";
			cin >> lastName;

			checkValidLetter = checkValidInput(lastName);
			while (checkValidLetter != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "Enter Donors Last name : ";
				cin >> lastName;

				checkValidLetter = checkValidInput(lastName);
			}
			checkValidSize = checkValidArraySize(lastName, Size);
		}
		// -------------------------------------------------------------

		cout << endl;

		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));

		while (!DonorFile.eof())
		{
			if (strcmp(firstName, donor.FirstName) == 0 && strcmp(lastName, donor.LastName) == 0)
			{
				cout << "Name : " << donor.FirstName << " " << donor.LastName << endl;
				cout << "Gender : " << donor.Gender << endl;
				cout << "Email : " << donor.Email << endl;
				cout << "Contact Number : " << donor.ContactNumber << endl;
				cout << "------------------------------------------------------" << endl << endl;
				found_user = true;
			}

			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}

	}
	if (found_user == false)
	{
		cout << "\nFirst & Last name not found in are System!\n" << endl;
	}
	DonorFile.close();
}
bool getValidation(char validation)
{
	if (validation == 'y')
	{
		return true;
	}
	else
	{
		return false;
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

//Donor Functions.
void donorScreen() {
	int donor_menu_input;

	while (1) {
		cout << "\nDonor Menu : \n";
		cout << "\n1. Procedure to donate blood";
		cout << "\n2. Create a Booking";
		cout << "\n3. Benefits of blood donation";
		cout << "\n4. Manage donor / booking information";
		cout << "\n5. Back\n" << endl;

		cout << "Please enter option : ";
		cin >> donor_menu_input;

		while (cin.fail())
		{
			cout << "\nPlease enter a valid option.." << endl;
			cin.clear();
			cin.ignore(256, '\n');

			cout << "\nDonor Menu : \n";
			cout << "\n1. Procedure to donate blood";
			cout << "\n2. Create a Booking";
			cout << "\n3. Benefits of blood donation";
			cout << "\n4. Manage donor / booking information";
			cout << "\n5. Back\n" << endl;

			cout << "Please enter option : ";
			cin >> donor_menu_input;
		}

		switch (donor_menu_input)
		{
		case 1:
			procedureToDonate();
			break;
		case 2:
			cin.ignore();
			createBooking();
			break;
		case 3:
			//Benefits of blood donation 
			donationBenefits();
			break;
		case 4:
			//Update the donor information.
			updateDonorInformation();
			//Also edit booking informations. / switch case menu for both options.
			break;
		case 5:
			return;
		default:
			cout << "\nPlease enter a valid option..\n";
			break;
		}
	}
}
inline void procedureToDonate() {
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
	cout << "\t   information given is correct and give consent to the testing for blood groups\n";
	cout << "\t   and evidence of some infections in the blood that they donate.\n";
	cout << "\t4. Once you have completed your questionnaire, you will have a confidential interview with a NZBS nurse\n";
	cout << "\t   or donor technician\n";
	cout << "\t5. They will also check your haemoglobin level using a finger prick test.\n\n";
	cout << "\t6. Once you've completed your interview successfully, you will be taken to one of our donation\n";
	cout << "\t   chairs and seated comfortably.\n";
	cout << "\t7. Your arm will be cleaned at the venepuncture site (on the inside of the elbow)\n";
	cout << "\t8. A sterile , single-use needle will be inserted. There may be a moment of discomfort as \n";
	cout << "\t   the needle goes in - sorry, this is the only way to get the blood out! \n";
	cout << "\t   The time you spend in the donation chair will differ depending on the type of donation you are giving. \n\n";

	cout << "\t   A blood donation can take up to 60 minutes (includes registration, donation and recovery).\n";
	cout << "\t   The blood is collected in a sterile bag, and time on the bed can take about 5 to 10 minutes..\n";
	cout << "\t9. A unit of blood (around 470 ml) will be collected. The needle is then removed and a bandage is applied.\n\n";
	cout << "\t   A plasma donation can take up to 90 minutes (includes registration, donation and recovery). The process of\n";
	cout << "\t   donating plasma is longer because blood is taken and separated into plasma and red blood cells by a special\n";
	cout << "\t   apheresis machine.  The red blood cells are returned to your body and the plasma is collected in a \n";
	cout << "\t   sterile bag. The time on the bed can take about 45 to 60 minutes. For your safety, a new needle and \n";
	cout << "\t   collection bag is used for each blood donation.Needlesand bags are never reused. \n\n";

	cout << "\t10. After donating blood, you will be asked to rest on the chair for around 5 to 10 minutes. When you're \n";
	cout << "\t    ready, you will be invited to have refreshments in the recovery area. We like to keep an eye on\n";
	cout << "\t    you for another 10-15 minutes to make sure that you feel OK before leaving.\n";
}
inline void donationBenefits() {
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
void createBooking() {
	donorBooking currentBooking;
	string donor_start_date, donor_end_date;
	int test_end_date;
	donor_start_date = "05-JUL-2021";
	string booking_day;
	bool valid_day = false;
	string booking_time;
	bool valid_time = false;

	//Read the currently logged in donor's records onto donor_for_booking
	fstream DonorFile;
	Registration_Donor donor_for_booking;
	DonorFile.open("donor.dat", ios::in | ios::out | ios::binary);

	if (!DonorFile)
	{
		cout << "Donor File not found! ";
		return;
	}

	DonorFile.seekg(current_donor_position * sizeof(donor_for_booking), ios::beg);
	DonorFile.read(reinterpret_cast<char*>(&donor_for_booking), sizeof(donor_for_booking));
	DonorFile.close();


	//If the current donor has already created a booking please prematurely exit.
	if (strcmp(donor_for_booking.hasBooking, "true") == 0)
	{
		cout << "\nThis Donor has already created a booking. Returning!\n";
		return;
	}



	//Get current donor details to store in booking record : Booking for the donation must access the donor’s full name, dob, recent health
	//condition, date, time... 
	strcpy_s(currentBooking.FirstName, donor_for_booking.FirstName);
	strcpy_s(currentBooking.MiddleName, donor_for_booking.MiddleName);
	strcpy_s(currentBooking.LastName, donor_for_booking.LastName);
	strcpy_s(currentBooking.DOB, donor_for_booking.DOB);
	strcpy_s(currentBooking.Conditions, donor_for_booking.Conditions);
	strcpy_s(currentBooking.Hospital_Name, donor_for_booking.Hospital_Name);
	strcpy_s(currentBooking.Username, donor_for_booking.Username);

	cout << "\nBooking Screen\n";
	cout << "Please enter the starting date of the week\n";
	cout << "you would like to donate blood in E.g: 01-FEB-2021: ";

	//Can change this date for the week shown. However make sure to delete .dat every time!!

	//Seperating the day, month, year from inputted dates to store in booking record.
	string start_day = donor_start_date.substr(0, 2);
	string start_month = donor_start_date.substr(3, 3);
	string start_year = donor_start_date.substr(7, 4);
	//Convert date strings into char array and store in record.
	sprintf_s(currentBooking.start_day, "%.20s", start_day.c_str());
	sprintf_s(currentBooking.start_month, "%.20s", start_month.c_str());
	sprintf_s(currentBooking.start_year, "%.20s", start_year.c_str());

	test_end_date = stoi(start_day);
	test_end_date += 6;

	//Initialise struct and display bookings available for this week. E.g use default values for every week and write in comments + report..
	cout << "\n\n\t\t\t\t\t\t" << currentBooking.Hospital_Name << "\n\n";
	cout << "Bookings available from " << donor_start_date << " to " << test_end_date << "/" << start_month << "/" << start_year << " : \n\n";


	//2D Array default Values.
	string test[7][8] = { {"Available", "Available", "Available", "Available", "Available", "Available", "Available", "Available"},
	  { "Available", "Available", "Available", "Available", "Available", "Available", "Available", "Available" },
	  { "Available", "Available", "Available", "Available", "Available", "Available", "Available", "Available" },
	  { "Available", "Available", "Available", "Available", "Available", "Available", "Available", "Available" },
	  { "Available", "Available", "Available", "Available", "Available", "Available", "Available", "Available" },
	  { "Available", "Available", "Available", "Available", "Available", "Available", "Available", "Available" },
	  { "Available", "Available", "Available", "Available", "Available", "Available", "Available", "Available" } };

	string days_of_week[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	string bookingTimes[8] = { "9am", "10am", "11am", "12pm", "1pm", "2pm", "3pm", "4pm" };

	//Open Booking file handle.
	fstream bookingsFileTest;
	donorBooking testBooking;
	bookingsFileTest.open("booking.dat", ios::in | ios::binary);

	if (!bookingsFileTest)
	{
		cout << "File not found";
	}

	else {
		//File already exists.
		bookingsFileTest.read(reinterpret_cast<char*>(&testBooking), sizeof(testBooking));

		while (!bookingsFileTest.eof())
		{
			/*
			*	check through the existing bookings to see if any exist.
			*		then update the 2d array accordingly.
			*/
			for (int i = 0; i < 7; i++)
			{
				if (strcmp(testBooking.booking_day_name, days_of_week[i].c_str()) == 0) {
					for (int j = 0; j < 8; j++)
					{
						if (strcmp(testBooking.booking_time, bookingTimes[j].c_str()) == 0) {
							//Make item unavailable in 2D array
							//Assuming One booking per donor.
							test[i][j] = "Not Available";
						}
					}
				}

			}

			bookingsFileTest.read(reinterpret_cast<char*>(&testBooking), sizeof(testBooking));
		}
	}
	bookingsFileTest.close();

	//Display available timeslots.
	for (int i = 0; i < 7; i++)
	{
		cout << setw(0) << days_of_week[i] << "\n\n";
		printline(120, '*');
		cout << endl;
		for (int j = 0; j < 8; j++)
		{
			cout << bookingTimes[j] << " " << test[i][j] << setw(10);
			//only display 5 booking slots per line.
			if (j % 4 == 0 && j > 0) {
				cout << setw(0) << endl;
			}
		}
		cout << setw(0) << endl << endl;
		printline(120, '*');
		cout << endl;
	}

	//cin.ignore();
	//Validating the user's inputted day of the week for their booking.
	while (valid_day == false) {
		cout << "Please enter the day of the week in which you would like to donate: ";

		getline(cin, booking_day);
		for (int i = 0; i < 7; i++)
		{
			if (booking_day == days_of_week[i]) {

				int test_booking_day;
				test_booking_day = stoi(start_day);
				test_booking_day += (i);
				string test_booking_day_str;
				test_booking_day_str = to_string(test_booking_day);

				//Storing the date of booking into booking structure as char array:
				sprintf_s(currentBooking.booking_date_day, "%.20s", test_booking_day_str.c_str());
				sprintf_s(currentBooking.booking_date_month, "%.20s", start_month.c_str());
				sprintf_s(currentBooking.booking_date_year, "%.20s", start_year.c_str());


				strcpy_s(currentBooking.booking_day_name, booking_day.c_str());


				//Test to see if the date for booking stores:
				cout << "\nThe date of booking is " << currentBooking.booking_date_day << "/" << currentBooking.booking_date_month;
				cout << "/" << currentBooking.booking_date_year << endl << endl;

				valid_day = true;
			}
		}
		if (valid_day == false)
			cout << "\nPlease enter a valid week day!!\n\n";
	}



	//Get user booking time and make sure its valid..
	while (valid_time == false) {
		cout << "Please enter an available booking slot:";
		getline(cin, booking_time);
		for (int i = 0; i < 7; i++) {
			//Check if the timeslot is available..
				//if booking day is correct. Check the availability of timeslot.
			if (booking_day.compare(days_of_week[i]) == 0) {
				for (int j = 0; j < 8; j++)
				{
					//Check if spot is taken..
					if (booking_time == bookingTimes[j]) {
						if (test[i][j] == "Not Available") {
							cout << "\nBooking slot is not available! Try again\n\n";

						}
						else {
							valid_time = true;
						}
					}

				}
			}
		}
	}
	//Give the Booking structure the value of the booking time.
	//sprintf_s(currentBooking.booking_time, "%.20s", booking_time.c_str());
	strcpy_s(currentBooking.booking_time, booking_time.c_str());

	//Store the Booking record into Binary File.
	fstream bookingFile;
	bookingFile.open("booking.dat", ios::out | ios::app | ios::binary);
	if (!bookingFile)
	{
		cout << "File not found!";
	}

	//Update the current donor's hasBooking status to true.
	updateDonorBookingStatus("true");

	bookingFile.write(reinterpret_cast<char*>(&currentBooking), sizeof(currentBooking));
	bookingFile.close();

}
void updateDonorBookingStatus(string value)
{
	//Update the status of the donor to true or false.
	//Allows us to make sure only booking per donor in createBooking()
	fstream DonorFile;
	Registration_Donor donor3;
	DonorFile.open("donor.dat", ios::in | ios::out | ios::binary);

	if (!DonorFile)
	{
		cout << "Donor File not found! ";
		return;
	}

	DonorFile.seekg(current_donor_position * sizeof(donor3), ios::beg);
	DonorFile.read(reinterpret_cast<char*>(&donor3), sizeof(donor3));
	//If donor has created a valid booking, update status.
	strcpy_s(donor3.hasBooking, value.c_str());
	DonorFile.seekp(current_donor_position * sizeof(donor3), ios::beg);
	DonorFile.write(reinterpret_cast<char*>(&donor3), sizeof(donor3));
	DonorFile.close();
}
void deleteBooking(string uname) {
	//Delete the booking based on the first name of the donor passed as argument.
	//instead of using serial, use the name as the comparison.
	donorBooking deleteBooking;
	//Create new file object and open file for writing
	fstream newfile;
	newfile.open("newbooking.dat", ios::out | ios::binary);

	// Create file object and open file
	fstream booking;
	booking.open("booking.dat", ios::in | ios::binary);
	if (!booking)
	{
		cout << "Error in opening the file . ";
		return;
	}
	else {
		booking.read(reinterpret_cast<char*>(&deleteBooking), sizeof(deleteBooking));
		while (!booking.eof())
		{
			if (uname != deleteBooking.Username)
			{
				newfile.write(reinterpret_cast<char*>(&deleteBooking), sizeof(deleteBooking));
			}
			booking.read(reinterpret_cast<char*>(&deleteBooking), sizeof(deleteBooking));
		}
	}
	booking.close();
	newfile.close();

	char oldname1[] = "booking.dat";
	char newname1[] = "oldbooking.dat";

	/*	Deletes the file if exists */
	if (rename(oldname1, newname1) != 0)
		perror("\nError renaming old file.\n");


	/*	Deletes the file if exists */
	if (remove(newname1) != 0)
		perror("\nOld File deletion failed.\n");

	char oldname2[] = "newbooking.dat";
	char newname2[] = "booking.dat";

	/*	Deletes the file if exists */
	if (rename(oldname2, newname2) != 0)
		perror("\nError renaming new file.\n");

	updateDonorBookingStatus("false");
}
void updateDonorInformation() {
	//Dynamically update the donor's booking with new data.
	string sFname, sMname, sLname, sDob, sNationality, sEthnicity, sCity, sAddress, sContactNumber, sEmail, sConditions;
	fstream DonorFile;
	Registration_Donor edit_donor;
	DonorFile.open("donor.dat", ios::in | ios::out | ios::binary);

	string temp8 = "true";
	char tab2[20];
	strcpy_s(tab2, temp8.c_str());

	string temp9 = "false";
	char tab3[20];
	strcpy_s(tab3, temp9.c_str());

	if (!DonorFile)
	{
		cout << "Donor File not found! ";
		return;
	}

	int edit_donor_choice;

	while (1) {
		cout << "\nManage donor information / Booking menu : \n";
		cout << "\n1. Update contact details and booking (If it exists.): ";
		cout << "\n2. Back\n" << endl;
		cout << "Please enter option : ";
		cin >> edit_donor_choice;

		while (cin.fail())
		{
			cout << "\nPlease enter a valid option.." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << endl;
			// --------------------------------
			// Menu Here....
			cout << "\n1. Update contact details and booking (If it exists.): ";
			cout << "\n2. Back\n" << endl;
			// --------------------------------

			cout << "Please enter option : ";
			cin >> edit_donor_choice;
		}
		DonorFile.seekg(current_donor_position * sizeof(edit_donor), ios::beg);
		DonorFile.read(reinterpret_cast<char*>(&edit_donor), sizeof(edit_donor));

		cin.ignore();
		switch (edit_donor_choice)
		{
		case 1:
			char temp5;
			bool tempValidationInput;

			//when user wants to update donor info but hasnt made booking catch this.
			if (strcmp(edit_donor.hasBooking, tab2) == 0) {
				deleteBooking(edit_donor.Username);
				strcpy_s(edit_donor.hasBooking, "false");
			}

			//if delete set statis to
			//strcpy_s(edit_donor.hasBooking, "false");

			// First name ---------------------------------------------------------------------------------
			cout << "\nFirst Name : ";
			getline(cin, sFname);
			tempValidationInput = checkValidStringInput(sFname);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\nFirst Name : ";
				getline(cin, sFname);

				tempValidationInput = checkValidStringInput(sFname);
			}

			while (sFname.length() > Size)
			{
				cout << "\nPlease enter a first name less than " << Size << " characters : ";
				getline(cin, sFname);

				tempValidationInput = checkValidStringInput(sFname);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\nFirst Name : ";
					getline(cin, sFname);

					tempValidationInput = checkValidStringInput(sFname);
				}
			}

			strcpy_s(edit_donor.FirstName, sFname.c_str());

			// --------------------------------------------------------------------------------------------


			// Middle name --------------------------------------------------------------------------------
			cout << "\nMiddle Name : ";
			getline(cin, sMname);
			tempValidationInput = checkValidStringInput(sMname);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\Middle Name : ";
				getline(cin, sMname);

				tempValidationInput = checkValidStringInput(sMname);
			}

			while (sMname.length() > Size)
			{
				cout << "\nPlease enter a Middle name less than " << Size << " characters : ";
				getline(cin, sMname);

				tempValidationInput = checkValidStringInput(sMname);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\Middle Name : ";
					getline(cin, sMname);

					tempValidationInput = checkValidStringInput(sMname);
				}
			}
			strcpy_s(edit_donor.MiddleName, sMname.c_str());
			// --------------------------------------------------------------------------------------------


			// Last name ----------------------------------------------------------------------------------
			cout << "\nLast Name : ";
			getline(cin, sLname);
			tempValidationInput = checkValidStringInput(sLname);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\Last Name : ";
				getline(cin, sLname);

				tempValidationInput = checkValidStringInput(sLname);
			}

			while (sLname.length() > Size)
			{
				cout << "\nPlease enter a Last name less than " << Size << " characters : ";
				getline(cin, sLname);

				tempValidationInput = checkValidStringInput(sLname);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\Last Name : ";
					getline(cin, sLname);

					tempValidationInput = checkValidStringInput(sLname);
				}
			}
			strcpy_s(edit_donor.LastName, sLname.c_str());
			// --------------------------------------------------------------------------------------------


			// Date of Birth ------------------------------------------------------------------------------
			cout << "\nDate of birth:";
			getline(cin, sDob);
			while (sDob.length() > Size)
			{
				cout << "\nPlease enter a DOB less than " << Size << " characters: ";
				getline(cin, sDob);
			}
			strcpy_s(edit_donor.DOB, sDob.c_str());
			// --------------------------------------------------------------------------------------------


			// Gender -------------------------------------------------------------------------------------
			// Updated to check if validated
			cout << "Gender (M/F/X - Other): ";
			cin >> temp5;

			while (temp5 != 'M' && temp5 != 'F' && temp5 != 'X' && temp5 != 'm' && temp5 != 'f' && temp5 != 'x')
			{
				cin.ignore(100, '\n');
				//system("CLS"); // clear screen

				cout << "\nPlease try again" << endl;
				cout << "Gender (M/F/X - Other): ";
				cin >> temp5;
			}
			edit_donor.Gender = temp5;
			cin.ignore();
			// --------------------------------------------------------------------------------------------


			// Nationality --------------------------------------------------------------------------------
			cout << "\nNationality : ";
			getline(cin, sNationality);
			tempValidationInput = checkValidStringInput(sNationality);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\Nationality : ";
				getline(cin, sNationality);

				tempValidationInput = checkValidStringInput(sNationality);
			}

			while (sNationality.length() > Size)
			{
				cout << "\nPlease enter a nationality less than " << Size << " characters : ";
				getline(cin, sNationality);

				tempValidationInput = checkValidStringInput(sNationality);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\Nationality : ";
					getline(cin, sNationality);

					tempValidationInput = checkValidStringInput(sNationality);
				}
			}
			strcpy_s(edit_donor.Nationalty, sNationality.c_str());
			// --------------------------------------------------------------------------------------------


			// Ethnicity ----------------------------------------------------------------------------------
			cout << "\nEthnicity : ";
			getline(cin, sEthnicity);
			tempValidationInput = checkValidStringInput(sEthnicity);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\Ethnicity : ";
				getline(cin, sEthnicity);

				tempValidationInput = checkValidStringInput(sEthnicity);
			}

			while (sEthnicity.length() > Size)
			{
				cout << "\nPlease enter a ethnicity less than " << Size << " characters : ";
				getline(cin, sEthnicity);

				tempValidationInput = checkValidStringInput(sEthnicity);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\Ethnicity : ";
					getline(cin, sEthnicity);

					tempValidationInput = checkValidStringInput(sEthnicity);
				}
			}
			strcpy_s(edit_donor.Ethnicity, sEthnicity.c_str());
			// --------------------------------------------------------------------------------------------


			// City ---------------------------------------------------------------------------------------
			cout << "\nCity : ";
			getline(cin, sCity);
			tempValidationInput = checkValidStringInput(sCity);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\City : ";
				getline(cin, sCity);

				tempValidationInput = checkValidStringInput(sCity);
			}

			while (sCity.length() > Size)
			{
				cout << "\nPlease enter a city less than " << Size << " characters : ";
				getline(cin, sCity);

				tempValidationInput = checkValidStringInput(sCity);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\City : ";
					getline(cin, sCity);

					tempValidationInput = checkValidStringInput(sCity);
				}
			}
			strcpy_s(edit_donor.City, sCity.c_str());
			// --------------------------------------------------------------------------------------------


			// Address ------------------------------------------------------------------------------------
			cout << "\nAddress:";
			getline(cin, sAddress);
			while (sEthnicity.length() > Size)
			{
				cout << "\nPlease enter an address less than " << Size << " characters: ";
				getline(cin, sAddress);
			}
			strcpy_s(edit_donor.Address, sAddress.c_str());
			// --------------------------------------------------------------------------------------------


			// Contact Number -----------------------------------------------------------------------------
			cout << "\nContact Number : ";
			getline(cin, sContactNumber);
			tempValidationInput = checkValidStringNumberInput(sContactNumber);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using numbers." << endl;
				cout << "\Contact Number : ";
				getline(cin, sContactNumber);

				tempValidationInput = checkValidStringNumberInput(sContactNumber);
			}

			while (sContactNumber.length() > Size)
			{
				cout << "\nPlease enter a contact number less than " << Size << " characters : ";
				getline(cin, sContactNumber);

				tempValidationInput = checkValidStringNumberInput(sContactNumber);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using numbers." << endl;
					cout << "\Contact Number : ";
					getline(cin, sContactNumber);

					tempValidationInput = checkValidStringNumberInput(sContactNumber);
				}
			}
			strcpy_s(edit_donor.ContactNumber, sContactNumber.c_str());
			// --------------------------------------------------------------------------------------------


			// Email --------------------------------------------------------------------------------------
			cout << "\nEmail:";
			getline(cin, sEmail);
			while (sEmail.length() > Size)
			{
				cout << "\nPlease enter an Email address less than " << Size << " characters: ";
				getline(cin, sEmail);
			}
			strcpy_s(edit_donor.Email, sEmail.c_str());
			// --------------------------------------------------------------------------------------------


			// Conditions ---------------------------------------------------------------------------------
			cout << "\nHealth Conditions : ";
			getline(cin, sConditions);
			tempValidationInput = checkValidStringInput(sConditions);
			while (tempValidationInput != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\Health Conditions : ";
				getline(cin, sConditions);

				tempValidationInput = checkValidStringInput(sConditions);
			}

			while (sConditions.length() > Size)
			{
				cout << "\nPlease enter health conditions less than " << Size << " characters : ";
				getline(cin, sConditions);

				tempValidationInput = checkValidStringInput(sConditions);
				while (tempValidationInput != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\Health Conditions : ";
					getline(cin, sConditions);

					tempValidationInput = checkValidStringInput(sConditions);
				}
			}
			strcpy_s(edit_donor.Conditions, sConditions.c_str());
			// --------------------------------------------------------------------------------------------


			DonorFile.seekp(current_donor_position * sizeof(edit_donor), ios::beg);
			DonorFile.write(reinterpret_cast<char*>(&edit_donor), sizeof(edit_donor));
			DonorFile.close();
			if (strcmp(edit_donor.hasBooking, tab3) == 0)
			{
				//If no booking is existing for donor 
				createBooking();
			}

			break;
		case 2:
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

//Admin Functions.
void adminScreen()
{
	bool flag = true;
	int choice;

	while (flag != false)
	{
		cout << "1. View Recipient Information" << endl;
		cout << "2. View Donor Information" << endl;
		cout << "3. Weekly Report (Donor and Recipient)" << endl;
		cout << "4. Report by Blood Group" << endl;
		cout << "5. Report by Location" << endl;
		cout << "6. Update Specific Donor Record" << endl;
		cout << "7. back\n" << endl;

		cout << "Please enter option : ";
		cin >> choice;
		while (cin.fail())
		{
			cout << "\nPlease enter a valid option.." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << endl;
			// --------------------------------
			// Menu Here....
			cout << "1. View Recipient Information" << endl;
			cout << "2. View Donor Information" << endl;
			cout << "3. Weekly Report (Donor and Recipient)" << endl;
			cout << "4. Report by Blood Group" << endl;
			cout << "5. Report by Location" << endl;
			cout << "6. Update Specific Donor Record" << endl;
			cout << "7. back\n" << endl;
			// --------------------------------

			cout << "Please enter option : ";
			cin >> choice;
		}
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			// View Recipient Information
			displayRecipientForAdmin();
			break;
		}
		case 2:
		{
			// View Donor Information
			displayDonorForAdmin();
			break;
		}
		case 3:
		{
			// Donor Report
			displayDonorReport();
			// Recipient Report
			displayRecipientReport();
			break;
		}
		case 4:
		{
			//Donor Report by Blood Group
			// Report by Blood Group
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
			searchDonorBloodGroupReport(inputBlood);
			searchRecipientBloodGroupReport(inputBlood);



			//Recipient Report by Blood Group
			break;
		}
		case 5:
		{
			//Donor Report by Location
			//Recipient Report by Location
			string sLocation;
			char inputHospital[100];
			bool tempAlphabetValid;

			cout << "\nInput Hospital name : ";
			cin.ignore();
			getline(cin, sLocation);

			tempAlphabetValid = checkValidStringInput(sLocation);
			while (tempAlphabetValid != true)
			{
				cout << "\nPlease try again with using alphabet characters." << endl;
				cout << "\nInput Hospital name : ";
				getline(cin, sLocation);
				tempAlphabetValid = checkValidStringInput(sLocation);
			}

			while (sLocation.length() > 100)
			{
				cout << "\nPlease enter a Hospital name less than 100 characters." << endl;
				cout << "\nInput Hospital name : ";
				getline(cin, sLocation);
				tempAlphabetValid = checkValidStringInput(sLocation);

				while (tempAlphabetValid != true)
				{
					cout << "\nPlease try again with using alphabet characters." << endl;
					cout << "\nInput Hospital name : ";
					getline(cin, sLocation);
					tempAlphabetValid = checkValidStringInput(sLocation);
				}
			}
			strcpy_s(inputHospital, sLocation.c_str());

			searchDonorLocationReport(inputHospital);
			searchRecipientLocationReport(inputHospital);
			break;
		}
		case 6:
			char inputUserName[20];
			cout << "\nInput the user name of the donor's record / booking you wish to edit: ";
			cin.ignore();
			cin.getline(inputUserName, 20);
			updateDonorReport(inputUserName);
			break;
		case 7:
		{
			// Go back
			return;
			flag = false;
		}
		default:
			cout << "\nPlease enter a valid option.." << endl;
			break;
		}
	}
}
void displayRecipientForAdmin()
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	int count_Record = 1;
	char input = ' ';

	RecipientFile.open("recipient.dat", ios::in | ios::binary);

	if (!RecipientFile)
	{
		cout << "File not found" << endl;
	}
	else
	{
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));

		while (!RecipientFile.eof())
		{
			cout << "  RECIPIENT RECORD " << count_Record << endl;
			cout << "----------------------" << endl << endl;
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
			count_Record++;

			cout << "Do you want to continue to see another record? (y/n) : ";
			cin >> input;

			while (input != 'y' && input != 'n')
			{
				cout << "Your input (y/n) : ";
				cin >> input;
			}

			if (input == 'n')
			{
				break;
			}
			cout << endl;

			RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		}

		if (RecipientFile.eof() && input == 'y')
		{
			cout << "End of the File\n" << endl;
		}
	}
	RecipientFile.close();
}
void displayDonorForAdmin()
{
	fstream DonorFile;
	Registration_Donor donor;
	int count_Record = 1;
	char input = ' ';

	DonorFile.open("donor.dat", ios::in | ios::binary);

	if (!DonorFile)
	{
		cout << "File not found" << endl;
	}
	else
	{
		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));

		while (!DonorFile.eof() && input != 'n')
		{
			cout << "  DONOR RECORD " << count_Record << endl;
			cout << "------------------" << endl << endl;
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
			cout << endl;
			count_Record++;

			cout << "Do you want to continue to see another record? (y/n) : ";
			cin >> input;

			while (input != 'y' && input != 'n')
			{
				cout << "Your input (y/n) : ";
				cin >> input;
			}

			if (input == 'n')
			{
				break;
			}
			cout << endl;

			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}

		if (DonorFile.eof() && input == 'y')
		{
			cout << "End of the File\n" << endl;
		}
	}
	DonorFile.close();
}
void displayRecipientReport()
{
	fstream RecipientFile;
	Registration_Recipient recipient;
	int i = 1;

	RecipientFile.open("recipient.dat", ios::in | ios::binary);

	if (!RecipientFile)
	{
		cout << "\nFile not found!\n" << endl;
	}
	else
	{
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		cout << "\n***************************\n";
		cout << "* Weekly Recipient Report *";
		cout << "\n***************************\n";



		while (!RecipientFile.eof())
		{
			cout << "\n\n\t" << recipient.FirstName << " " << recipient.MiddleName << " " << recipient.LastName << endl;
			printline(40, '*');
			cout << "Contact Details\n";
			printline(40, '*');
			cout << "Date Of Birth : " << recipient.DOB << endl;
			cout << "Nationalty : " << recipient.Nationalty << endl;
			cout << "Ethnicity : " << recipient.Ethnicity << endl;
			cout << "Gender : " << recipient.Gender << endl;
			cout << "City : " << recipient.City << endl;
			cout << "Contact Number : " << recipient.ContactNumber << endl;
			cout << "Email : " << recipient.Email << endl;
			cout << "Address : " << recipient.Address << endl;
			printline(40, '*');
			cout << "Health Details\n";
			printline(40, '*');
			cout << "Conditions : " << recipient.Conditions << endl;
			cout << "Blood Group : " << recipient.BloodGroup << endl;
			cout << "Hospital : " << recipient.Hospital_Name << endl;
			printline(40, '*');
			cout << "Account Details\n";
			printline(40, '*');
			cout << "Username : " << recipient.Username << endl;
			cout << "Password : " << recipient.Password << endl;
			printline(40, '*');
			RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		}

	}

	RecipientFile.close();
	cout << endl << endl;
}
void displayDonorReport() {
	//Donor Report for Admin Menu.
	fstream DonorFile;
	Registration_Donor donor;
	DonorFile.open("donor.dat", ios::in | ios::binary);

	if (!DonorFile)
	{
		cout << "File not found";
		return;
	}

	DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));

	cout << "\n***********************\n";
	cout << "* Weekly Donor Report *";
	cout << "\n***********************\n";


	while (!DonorFile.eof())
	{
		cout << "\n\n\t" << donor.FirstName << " " << donor.MiddleName << " " << donor.LastName << endl;
		printline(40, '*');
		cout << "Contact Details\n";
		printline(40, '*');
		cout << "Date Of Birth : " << donor.DOB << endl;
		cout << "Nationalty : " << donor.Nationalty << endl;
		cout << "Ethnicity : " << donor.Ethnicity << endl;
		cout << "Gender : " << donor.Gender << endl;
		cout << "City : " << donor.City << endl;
		cout << "Contact Number : " << donor.ContactNumber << endl;
		cout << "Email : " << donor.Email << endl;
		cout << "Address : " << donor.Address << endl;
		printline(40, '*');
		cout << "Health Details\n";
		printline(40, '*');
		cout << "Conditions : " << donor.Conditions << endl;
		cout << "Blood Group : " << donor.BloodGroup << endl;
		cout << "Hospital : " << donor.Hospital_Name << endl;
		printline(40, '*');
		cout << "Account Details\n";
		printline(40, '*');
		cout << "Username : " << donor.Username << endl;
		cout << "Password : " << donor.Password << endl;
		printline(40, '*');
		cout << "Booking Details\n";
		printline(40, '*');
		displayBooking(donor.Username);

		DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
	}
	cout << endl << endl;
	DonorFile.close();
}
void searchDonorBloodGroupReport(char blood[]) {
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

		cout << "\n********************************\n";
		cout << "* Donor Report's via blood type*";
		cout << "\n********************************\n";

		while (!DonorFile.eof())
		{
			if (strcmp(blood, donor.BloodGroup) == 0)
			{
				cout << "\n\n\t" << donor.FirstName << " " << donor.MiddleName << " " << donor.LastName << endl;
				printline(40, '*');
				cout << "Contact Details\n";
				printline(40, '*');
				cout << "Date Of Birth : " << donor.DOB << endl;
				cout << "Nationalty : " << donor.Nationalty << endl;
				cout << "Ethnicity : " << donor.Ethnicity << endl;
				cout << "Gender : " << donor.Gender << endl;
				cout << "City : " << donor.City << endl;
				cout << "Contact Number : " << donor.ContactNumber << endl;
				cout << "Email : " << donor.Email << endl;
				cout << "Address : " << donor.Address << endl;
				printline(40, '*');
				cout << "Health Details\n";
				printline(40, '*');
				cout << "Conditions : " << donor.Conditions << endl;
				cout << "Blood Group : " << donor.BloodGroup << endl;
				cout << "Hospital : " << donor.Hospital_Name << endl;
				printline(40, '*');
				cout << "Account Details\n";
				printline(40, '*');
				cout << "Username : " << donor.Username << endl;
				cout << "Password : " << donor.Password << endl;
				printline(40, '*');
				cout << "Booking Details\n";
				printline(40, '*');
				displayBooking(donor.Username);
			}

			i++;
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}
	}
	cout << endl << endl;
	DonorFile.close();
}
void searchRecipientBloodGroupReport(char blood[]) {
	fstream RecipientFile;
	Registration_Recipient recipient;
	int i = 1;

	RecipientFile.open("recipient.dat", ios::in | ios::binary);

	if (!RecipientFile)
	{
		cout << "\nFile not found!\n" << endl;
	}
	else
	{
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		cout << "\n*************************************\n";
		cout << "* Recipient Report's via blood type *";
		cout << "\n*************************************\n";

		while (!RecipientFile.eof())
		{
			if (strcmp(blood, recipient.BloodGroup) == 0)
			{
				cout << "\n\n\t" << recipient.FirstName << " " << recipient.MiddleName << " " << recipient.LastName << endl;
				printline(40, '*');
				cout << "Contact Details\n";
				printline(40, '*');
				cout << "Date Of Birth : " << recipient.DOB << endl;
				cout << "Nationalty : " << recipient.Nationalty << endl;
				cout << "Ethnicity : " << recipient.Ethnicity << endl;
				cout << "Gender : " << recipient.Gender << endl;
				cout << "City : " << recipient.City << endl;
				cout << "Contact Number : " << recipient.ContactNumber << endl;
				cout << "Email : " << recipient.Email << endl;
				cout << "Address : " << recipient.Address << endl;
				printline(40, '*');
				cout << "Health Details\n";
				printline(40, '*');
				cout << "Conditions : " << recipient.Conditions << endl;
				cout << "Blood Group : " << recipient.BloodGroup << endl;
				cout << "Hospital : " << recipient.Hospital_Name << endl;
				printline(40, '*');
				cout << "Account Details\n";
				printline(40, '*');
				cout << "Username : " << recipient.Username << endl;
				cout << "Password : " << recipient.Password << endl;
				printline(40, '*');
				RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
			}
		}
	}

	RecipientFile.close();
	cout << endl << endl;
}
void searchDonorLocationReport(char search[]) {
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

		cout << "\n************************************\n";
		cout << "* Donor Report's via Hospital Name *";
		cout << "\n************************************\n";

		while (!DonorFile.eof())
		{
			if (strcmp(search, donor.Hospital_Name) == 0)
			{
				cout << "\n\n\t" << donor.FirstName << " " << donor.MiddleName << " " << donor.LastName << endl;
				printline(40, '*');
				cout << "Contact Details\n";
				printline(40, '*');
				cout << "Date Of Birth : " << donor.DOB << endl;
				cout << "Nationalty : " << donor.Nationalty << endl;
				cout << "Ethnicity : " << donor.Ethnicity << endl;
				cout << "Gender : " << donor.Gender << endl;
				cout << "City : " << donor.City << endl;
				cout << "Contact Number : " << donor.ContactNumber << endl;
				cout << "Email : " << donor.Email << endl;
				cout << "Address : " << donor.Address << endl;
				printline(40, '*');
				cout << "Health Details\n";
				printline(40, '*');
				cout << "Conditions : " << donor.Conditions << endl;
				cout << "Blood Group : " << donor.BloodGroup << endl;
				cout << "Hospital : " << donor.Hospital_Name << endl;
				printline(40, '*');
				cout << "Account Details\n";
				printline(40, '*');
				cout << "Username : " << donor.Username << endl;
				cout << "Password : " << donor.Password << endl;
				printline(40, '*');
				cout << "Booking Details\n";
				printline(40, '*');
				displayBooking(donor.Username);
			}

			i++;
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}
	}
	cout << endl << endl;
	DonorFile.close();
}
void searchRecipientLocationReport(char search[]) {
	fstream RecipientFile;
	Registration_Recipient recipient;
	int i = 1;

	RecipientFile.open("recipient.dat", ios::in | ios::binary);

	if (!RecipientFile)
	{
		cout << "\nFile not found!\n" << endl;
	}
	else
	{
		RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		cout << "\n*****************************************\n";
		cout << "* Recipients Report's via Hospital Name *";
		cout << "\n*****************************************\n";

		while (!RecipientFile.eof())
		{
			if (strcmp(search, recipient.Hospital_Name) == 0)
			{
				cout << "\n\n\t" << recipient.FirstName << " " << recipient.MiddleName << " " << recipient.LastName << endl;
				printline(40, '*');
				cout << "Contact Details\n";
				printline(40, '*');
				cout << "Date Of Birth : " << recipient.DOB << endl;
				cout << "Nationalty : " << recipient.Nationalty << endl;
				cout << "Ethnicity : " << recipient.Ethnicity << endl;
				cout << "Gender : " << recipient.Gender << endl;
				cout << "City : " << recipient.City << endl;
				cout << "Contact Number : " << recipient.ContactNumber << endl;
				cout << "Email : " << recipient.Email << endl;
				cout << "Address : " << recipient.Address << endl;
				printline(40, '*');
				cout << "Health Details\n";
				printline(40, '*');
				cout << "Conditions : " << recipient.Conditions << endl;
				cout << "Blood Group : " << recipient.BloodGroup << endl;
				cout << "Hospital : " << recipient.Hospital_Name << endl;
				printline(40, '*');
				cout << "Account Details\n";
				printline(40, '*');
				cout << "Username : " << recipient.Username << endl;
				cout << "Password : " << recipient.Password << endl;
				printline(40, '*');

			}
			i++;
			RecipientFile.read(reinterpret_cast<char*>(&recipient), sizeof(recipient));
		}
	}
	cout << endl << endl;
	RecipientFile.close();
}
void updateDonorReport(char uname[]) {
	//Update the current donor variable for positioning based off of the inputted username.
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
			if (strcmp(uname, donor.Username) == 0)
			{
				current_donor_position = DonorFile.tellg() / sizeof(donor) - 1;
			}

			i++;
			DonorFile.read(reinterpret_cast<char*>(&donor), sizeof(donor));
		}
	}
	DonorFile.close();

	//Run the update update_donor_information
	updateDonorInformation();
}

//      Validation Functions
//-----------------------------------
//Check array Size isnt above array limit.
bool checkValidArraySize(char arr[], int setSize)
{
	int arrSize;
	for (arrSize = 0; arr[arrSize] != '\0'; arrSize++)
	{
		// counting the array size with a for loop, it will stop when it hits the null character.
	}

	if (arrSize < setSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Check array if only Alphabet letters are inside.
bool checkValidInput(char arr[])
{
	int arrSize;
	for (arrSize = 0; arr[arrSize] != '\0'; arrSize++)
	{
		if (!isalpha(arr[arrSize]))
		{
			return false;
		}
	}
	return true;

}

//Check array if only Numbers are inside.
bool checkValidNumbers(char arr[])
{
	int arrSize;
	for (arrSize = 0; arr[arrSize] != '\0'; arrSize++)
	{
		if (!isdigit(arr[arrSize]))
		{
			return false;
		}
	}
	return true;
}

// Check string if only Alphabet letters are inside
bool checkValidStringInput(string str)
{
	char tempStringArray[300];

	strcpy_s(tempStringArray, str.c_str());

	for (int i = 0; tempStringArray[i] != '\0'; i++)
	{
		if (!isalpha(tempStringArray[i]))
		{
			return false;
		}
	}

	return true;

}

// Check string if only Numbers are inside
bool checkValidStringNumberInput(string str)
{
	char tempStringArray[300];

	strcpy_s(tempStringArray, str.c_str());

	for (int i = 0; tempStringArray[i] != '\0'; i++)
	{
		if (!isdigit(tempStringArray[i]))
		{
			return false;
		}
	}

	return true;

}
//-----------------------------------

//Misc
void inline printline(int size, char symbol) {
	//Print a line based on the size and symbol as arguments.
	for (int i = 0; i < size; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

