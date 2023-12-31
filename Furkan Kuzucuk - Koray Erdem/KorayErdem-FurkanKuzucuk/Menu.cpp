#include <iostream>
#include "Menu.h"
#include "Train.h";
#include "Passenger.h"
#include <ctime>
#include <windows.h>
using namespace std;

void Menu::showTime() {
	time_t rawtime;
	time(&rawtime);
	cout << "\t\t    " << ctime(&rawtime);
}

void Menu::loginMenu() {
label_login:
	system("cls");
	string Username;
	int pword;
	string _name;
	string _surname;
	string _PhoneNumber;
	string _password;
	Passenger passenger(_name, _surname, _PhoneNumber, _password);
	string  adminUserName = "Admin";
	int password = 1234;
	int choice;
	showTime();
	cout << "\t\t===============================" << endl;
	cout << "\t\t=                             =" << endl;
	cout << "\t\t=   TRAIN MANAGEMENT SYSTEM   =" << endl;
	cout << "\t\t=                             =" << endl;
	cout << "\t\t===============================" << endl;
	cout << "\t" << endl;
	cout << "\t\t[1] Admin Login" << endl;
	cout << "\t\t[2] Passenger Login" << endl;
	cout << "\t\t[3] Sign Up " << endl;
	cout << "\t\t[4] Forgot Password " << endl;
	cout << "\t\t[0] Exit " << endl;
	cout << "\t\tEnter Your Choice : ";
	cin >> choice;
	switch (choice) {
	case 1:
	label_adminlogin:
		system("cls");
		cout << "\t\t===============================" << endl;
		cout << "\t\t=         Admin Login         =" << endl;
		cout << "\t\t===============================" << endl;
		cout << "\t\tAdmin UserName : ";
		cin >> Username;
		cout << "\t\tPassword : ";
		cin >> pword;
		if (Username == adminUserName && pword == password) {
			cout << "\n\t\tLogin successful" << endl;
			Sleep(1000);
			AdminMenu();
		}
		else {
			goto label_adminlogin;
		}
		break;
	case 2:
	label_passengerlogin:
		system("cls");
		cout << "\t\t===============================" << endl;
		cout << "\t\t=      Passenger Login        =" << endl;
		cout << "\t\t===============================" << endl;
		if (passenger.readPassenger()) {
			passengerMenu();
		}
		break;
	case 3:
		system("cls");
		cout << "\t\t===============================" << endl;
		cout << "\t\t=           Sign Up           =" << endl;
		cout << "\t\t===============================" << endl;
		passenger.SignUp();
		goto label_passengerlogin;
		break;
	case 4:
		system("cls");
		cout << "\t\t===============================" << endl;
		cout << "\t\t=       Forgot Password       =" << endl;
		cout << "\t\t===============================" << endl;
		passenger.updatePassword();
		Sleep(1500);
		goto label_passengerlogin;
	case 0:
		break;
	default:
		cout << "\n\n\t\tWrong Choice!!! " << endl;
		Sleep(1000);
		cout << "\t\tYou are directed to the main menu" << endl;
		Sleep(1000);
		goto label_login;
		break;
	}
}

void Menu::AdminMenu() {
label_admin:
	system("cls");
	showTime();
	int choice2;
	string _TrainName;
	int _capacity = 0;
	string _departurePoint;
	string _destinationPoint;
	Train train(_TrainName, _capacity, _departurePoint, _destinationPoint);
	string _name;
	string _surname;
	string _PhoneNumber;
	string _password;
	Passenger passenger(_name, _surname, _PhoneNumber, _password);
	cout << "\t\t===============================" << endl;
	cout << "\t\t=          Admin Menu         =" << endl;
	cout << "\t\t===============================" << endl;
	cout << "\n" << endl;
	cout << "\t\t[1] Add Train " << endl;
	cout << "\t\t[2] Delete Train " << endl;
	cout << "\t\t[3] Update Train " << endl;
	cout << "\t\t[4] Show Trains " << endl;
	cout << "\t\t[5] Show Passengers " << endl;
	cout << "\t\t[6] Main Menu " << endl;
	cout << "\t\t[0] Exit " << endl;
	cout << "\t\tEnter Your Choice : ";
	cin >> choice2;
	switch (choice2) {
	case 1:
	label_addtrain:
		system("cls");
		cout << "\t\t===============================" << endl;
		cout << "\t\t=          Add Train          =" << endl;
		cout << "\t\t===============================" << endl;
		train.addTrain();
		int choice4;
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t[1] Add one more " << endl;
		cout << "\t\t[2] Admin Menu" << endl;
		cout << "\t\t[0] Exit " << endl;
		cout << "\t\t";
		cin >> choice4;
		switch (choice4) {
		case 1:
			system("cls");
			goto label_addtrain;
			break;
		case 2:
			system("cls");
			AdminMenu();
			break;
		case 0:
			break;
		default:
			cout << "\n\n\t\tWrong Choice!!! " << endl;
			Sleep(1000);
			cout << "\t\tYou are directed to the admin menu" << endl;
			Sleep(1000);
			goto label_admin;
			break;
		}
		break;
	case 2:
		system("cls");
	label_deleteTrain:
		int choice6;
		cout << "\t\t===============================" << endl;
		cout << "\t\t=        Delete Train         =" << endl;
		cout << "\t\t===============================" << endl;
		train.showTrains();
		train.deleteTrain();
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t[1] Delete one more " << endl;
		cout << "\t\t[2] Admin Menu " << endl;
		cout << "\t\t[0] Exit " << endl;
		cout << "\t\t";
		cin >> choice6;
		switch (choice6) {
		case 1:
			goto label_deleteTrain;
			break;
		case 2:
			goto label_admin;
			break;
		case 0:
			break;
		default:
			cout << "\n\n\t\tWrong Choice!!! " << endl;
			Sleep(1000);
			cout << "\t\tYou are directed to the admin menu" << endl;
			Sleep(1000);
			goto label_admin;
			break;
		}
	case 3:
		system("cls");
		cout << "\t\t===============================" << endl;
		cout << "\t\t=        Update Train         =" << endl;
		cout << "\t\t===============================" << endl;
		train.showTrains();
		cout << "\t\t-------------------------------" << endl;
		train.updateTrain();
		goto label_admin;
		Sleep(1000);
		break;
	case 4:
		system("cls");
		int choice5;
		cout << "\t\t===============================" << endl;
		cout << "\t\t=           Trains            =" << endl;
		cout << "\t\t===============================" << endl;
		train.showTrains();
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t[1] Admin Menu " << endl;
		cout << "\t\t[0] Exit" << endl;
		cout << "\t\t";
		cin >> choice5;
		switch (choice5) {
		case 1:
			AdminMenu();
			break;
		case 0:
			break;
		default:
			cout << "\n\n\t\tWrong Choice!!! " << endl;
			Sleep(1000);
			cout << "\t\tYou are directed to the admin menu" << endl;
			Sleep(1000);
			goto label_admin;
			break;
		}
		break;
	case 5:
		system("cls");
		int choice11;
		cout << "\t\t===============================" << endl;
		cout << "\t\t=         Passengers          =" << endl;
		cout << "\t\t===============================" << endl;
		passenger.showPassengers();
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t[1] Admin Menu " << endl;
		cout << "\t\t[0] Exit" << endl;
		cout << "\t\t";
		cin >> choice11;
		switch (choice11) {
		case 1:
			AdminMenu();
			break;
		case 0:
			system("cls");
			break;
		default:
			cout << "\n\n\t\tWrong Choice!!! " << endl;
			Sleep(1000);
			cout << "\t\tYou are directed to the admin menu" << endl;
			Sleep(1000);
			goto label_admin;
			break;
		}
		break;
	case 6:
		system("cls");
		loginMenu();
		break;
	case 0:
		break;
	default:
		cout << "\n\n\t\tWrong Choice!!! " << endl;
		Sleep(1000);
		cout << "\t\tYou are directed to the admin menu" << endl;
		Sleep(1000);
		goto label_admin;
	}

}

void Menu::passengerMenu() {
label_passenger:
	system("cls");
	showTime();
	string _TrainName;
	int _capacity = 0;
	string _departurePoint;
	string _destinationPoint;
	Train train(_TrainName, _capacity, _departurePoint, _destinationPoint);
	string _name;
	string _surname;
	string _PhoneNumber;
	string _password;
	Passenger passenger(_name, _surname, _PhoneNumber, _password);
	int choice3;
	cout << "\t\t===============================" << endl;
	cout << "\t\t=       Passenger Menu        =" << endl;
	cout << "\t\t===============================" << endl;
	cout << "\n";
	cout << "\t\t[1] Book Ticket" << endl;
	cout << "\t\t[2] Show Trains" << endl;
	cout << "\t\t[3] Cancel Ticket" << endl;
	cout << "\t\t[4] Main Menu " << endl;
	cout << "\t\t[5] My Tickets" << endl;
	cout << "\t\t[0] Exit " << endl;
	cout << "\t\tEnter Your Choice : ";
	cin >> choice3;
	switch (choice3) {
	case 1:
	label_booktic:
		system("cls");
		char choiceTic;
		cout << "\t\t===============================" << endl;
		cout << "\t\t=         Book Ticket         =" << endl;
		cout << "\t\t===============================" << endl;
		cout << "\t\t-------------------------------" << endl;
		train.showTrains();
		cout << "\t\t-------------------------------" << endl;
		passenger.bookticket();
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t[1] Book one more " << endl;
		cout << "\t\t[2] Passenger Menu " << endl;
		cout << "\t\t[0] Exit " << endl;
		cin >> choiceTic;
		switch (choiceTic) {
		case '1':
			goto label_booktic;
			break;
		case '2':
			passengerMenu();
			break;
		case '0':
			break;
		default:
			cout << "\n\n\t\tWrong Choice!!! " << endl;
			Sleep(1000);
			cout << "\t\tYou are directed to the passenger menu" << endl;
			Sleep(1000);
			goto label_passenger;
			break;
		}
		break;
	case 2:
		system("cls");
		char choice10;
		cout << "\t\t===============================" << endl;
		cout << "\t\t=           Trains            =" << endl;
		cout << "\t\t===============================" << endl;
		train.showTrains();
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t[1] Book A Ticket" << endl;
		cout << "\t\t[2] Passenger Menu " << endl;
		cout << "\t\t[0] Exit " << endl;
		cout << "\t\t";
		cin >> choice10;
		switch (choice10) {
		case '1':
			goto label_booktic;
			break;
		case '2':
			goto label_passenger;
			break;
		case '0':
			break;
		default:
			cout << "\n\n\t\tWrong Choice!!! " << endl;
			Sleep(1000);
			cout << "\t\tYou are directed to the passenger menu" << endl;
			Sleep(1000);
			goto label_passenger;
			break;
		}
		break;
	case 3:
		passenger.cancelticket();
		goto label_passenger;
		break;
	case 4:
		system("cls");
		loginMenu();
	case 5:
		system("cls");
		char choice13;
		cout << "\t\t===============================" << endl;
		cout << "\t\t=         My Tickets          =" << endl;
		cout << "\t\t===============================" << endl;
		passenger.myTickets();
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t[1] Passenger Menu " << endl;
		cout << "\t\t[2] Exit ";
		cin >> choice13;
		switch (choice13) {
		case '1':
			goto label_passenger;
			Sleep(1000);
			break;
		case '2':
			break;
		default:
			cout << "\n\n\t\tWrong Choice!!!" << endl;
			Sleep(1000);
			cout << "\t\tYou are directed to the passenger menu" << endl;
			Sleep(1000);
			goto label_passenger;
		}
	case 0:
		break;
	default:
		cout << "\n\n\t\tWrong Choice!!! " << endl;
		Sleep(1000);
		cout << "\t\tYou are directed to the passenger menu" << endl;
		Sleep(1000);
		goto label_passenger;
	}
}