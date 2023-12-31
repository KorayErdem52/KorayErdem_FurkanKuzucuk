#include <iostream>
#include <vector>
#include "Passenger.h"
#include <fstream>
#include <string>
#include <Windows.h>
vector<Passenger>PassengerList;
using namespace std;

Passenger::Passenger(string _name, string _surname, string _PhoneNumber, string _password) {
	this->PassengerName = _name;
	this->PassengerSurname = _surname;
	this->PhoneNumber = _PhoneNumber;
}

void Passenger::bookticket() {
label_bookticket:
	string bookTrainName;
	string _name;
	string _surname;
	string _PhoneNumber;
	string _password;
	string phoneNum;
	cout << "\t\tTrain Name : ";
	cin >> bookTrainName;
	cout << "\t\tPhone Number : ";
	cin >> phoneNum;
	string currentTrainName;
	int capacity;
	int price;
	string departurePoint;
	string destinationPoint;
	ifstream inFile("trains.txt");
	while (inFile >> currentTrainName >> capacity >> departurePoint >> destinationPoint >> price) {
		if (currentTrainName == bookTrainName) {
			ifstream userFile("Users.txt");
			while (userFile >> _name >> _surname >> _password >> _PhoneNumber) {
				if (phoneNum == _PhoneNumber) {
					ofstream Tickets("tickets.txt", ios::app);
					if (Tickets.is_open()) {
						Tickets << currentTrainName << " " << capacity << " " << departurePoint << " " << destinationPoint << " " << price << endl;
						Tickets << _name << " " << _surname << " " << phoneNum << endl;
						cout << "\t\tTicket booked successfully!\n";
						Tickets.close();
						return;
					}
				}
			}
		}
	}
	cout << "\t\tError: Invalid train name or phone number. Please try again.\n";
}

void Passenger::userProfile() {
	string _name;
	string _surname;
	string _password;
	string _PhoneNumber;

	cout << "\t\tEnter your password: ";
	string password;
	cin >> password;

	ifstream userFile("Users.txt");
	bool found = false;

	while (userFile >> _name >> _surname >> _password >> _PhoneNumber) {
		if (password == _password) {
			found = true;
			cout << "\n\t\tUser Profile:\n";
			cout << "\t\tName: " << _name << "\n";
			cout << "\t\tSurname: " << _surname << "\n";
			cout << "\t\tPhone Number: " << _PhoneNumber << "\n";
			break;
		}
	}

	if (!found) {
		cout << "\t\tError: User not found. Please check your phone number.\n";
	}
}

void Passenger::Passsenger() {}
void Passenger::SignUp() {
	string _name;
	string _surname;
	string _PhoneNumber;
	string _password;
	string name, surname, password, phonenumber;
	cout << "\t\tName : ";
	cin >> _name;
	cout << "\t\tSurname : ";
	cin >> _surname;
	label_phone:
	cout << "\t\tPhone Number : ";
	cin >> _PhoneNumber;
	ifstream checkPhone("Users.txt");
	while (checkPhone >> name >> surname >> password >> phonenumber) {
		if (_PhoneNumber == phonenumber) {
			cout << "\t\tThis Phone Number is Already Exists" << endl;
			Sleep(1000);
			cout << "\t\tYou must enter a different phone number " << endl;
			Sleep(1000);
			goto label_phone;
		}
	}
	cout << "\t\tPassword : ";
	cin >> _password;
	Passenger passenger(_name, _surname, _PhoneNumber, _password);
	ofstream User("Users.txt", ios::app);
	if (User.is_open()) {
		User << _name << "  " << _surname << "  " << _password << "  " << _PhoneNumber << endl;
		User.close();
	}
}

void Passenger::updatePassword() {
	string upName;
	string upSurname;
	cout << "\t\tName : ";
	cin >> upName;
	cout << "\t\tSurname : ";
	cin >> upSurname;
	ifstream inPass("Users.txt");
	ofstream outPass("tempPass.txt");

	if (!inPass.is_open() || !outPass.is_open()) {
		cerr << "\t\tEror: Unable to open the file\n";
		return;
	}

	string name, surname, password, phonenum;
	bool found = false;

	while (inPass >> name >> surname >> password >> phonenum) {
		if (name == upName) {
			found = true;

			cout << "\t\tEnter new password : ";
			cin >> password;
			cout << "\t\tReenter password : ";
			cin >> password;
			outPass << name << "  " << surname << "  " << password << "  " << phonenum << endl;
		}
		else {
			outPass << name << "  " << surname << "  " << password << "  " << phonenum << endl;
		}
	}
	inPass.close();
	outPass.close();

	if (found) {
		remove("Users.txt");
		Sleep(1500);
		rename("tempPass.txt", "Users.txt");
		cout << "\t\tPassword updated" << endl;
	}
	else {
		cout << "\t\tUser Not Found!!" << endl;
		remove("tempPass.txt");
	}
}

bool Passenger::readPassenger() {
	string _name;
	string _surname;
	string _password;
	cout << "\n\t\tPassenger Name : ";
	cin >> _name;
	cout << "\t\tPassenger Surname : ";
	cin >> _surname;
	cout << "\t\tPassword : ";
	cin >> _password;
	ifstream User("Users.txt");
	if (User.is_open()) {
		cout << "\t\t-------------------\n";
		string name;
		string surname;
		string password;
		string phonenum;
		while (User >> name >> surname >> password >> phonenum) {
			if (_name == name && _surname == surname && _password == password) {
				Sleep(1000);
				cout << "\t\tLogin successful";
				cout << "\t\t";
				Sleep(1000);
				User.close();
				return true;
			}
		}
		User.close();
	}
	cout << "\t\tLogin Failed";
	return false;
}

void Passenger::showPassengers() {
	string trainName, trainDepa, trainDest;
	int capacity = 0;
	string name;
	string surname;
	string password;
	string phonenum;
	int count = 0;
	ifstream user("tickets.txt");
	cout << "\t\tName" << "  " << "Surname" << "  " << "Phone" << "  " << "Train" << endl;
	cout << "\t\t-------------------------------" << endl;
	while (user >> trainName >> capacity >> trainDepa >> trainDest >> name >> surname >> phonenum) {
		cout << "\t\t" << name << "   " << surname << "   " << phonenum << "   " << trainName << endl;
		cout << "\t\t-------------------------------" << endl;
		count++;
	}
	cout << "\t\tTotal Passengers : " << count << endl;
}

void Passenger::myTickets() {
	cout << "\t\tEnter your phone number to display your tickets: ";
	string phoneNum;
	cin >> phoneNum;
	ifstream ticketFile("tickets.txt");
	system("cls");
	string currentTrainName;
	int capacity;
	string departurePoint;
	string destinationPoint;
	string userName;
	string userSurname;
	string userPhoneNum;
	int price;
	bool ticketFound = false;
	cout << "\t\t===============================" << endl;
	cout << "\t\t=         My Tickets          =" << endl;
	cout << "\t\t===============================" << endl;
	cout << "\t\tYour Tickets:\n";
	cout << "\t\t---------------\n";

	while (ticketFile >> currentTrainName >> capacity >> departurePoint >> destinationPoint >> price >> userName >> userSurname >> userPhoneNum) {
		if (userPhoneNum == phoneNum) {
			ticketFound = true;
			cout << "\t\tTrain Name: " << currentTrainName << "\n";
			cout << "\t\tCapacity: " << capacity << "\n";
			cout << "\t\tDeparture Point: " << departurePoint << "\n";
			cout << "\t\tDestination Point: " << destinationPoint << "\n";
			cout << "\t\tTicket Price : " << price << endl;
			cout << "\t\t---------------\n";
		}
	}
	ticketFile.close();
	if (!ticketFound) {
		cout << "\t\tYou have no tickets.\n";
	}
}

void Passenger::cancelticket() {
	myTickets();

	cout << "\t\tEnter the train name of the ticket you want to cancel: ";
	string trainName;
	cin >> trainName;

	cout << "\t\tEnter your phone number to confirm the cancellation: ";
	string phoneNum;
	cin >> phoneNum;

	ifstream ticketFile("tickets.txt");
	ofstream tempFile("temp.txt");

	string currentTrainName;
	int capacity;
	string departurePoint;
	string destinationPoint;
	string userName;
	string userSurname;
	string userPhoneNum;
	int price;
	bool ticketFound = false;

	while (ticketFile >> currentTrainName >> capacity >> departurePoint >> destinationPoint >> price >> userName >> userSurname >> userPhoneNum) {
		if (trainName == currentTrainName && phoneNum == userPhoneNum) {
			ticketFound = true;
			cout << "\t\tTicket canceled successfully!\n";
		}
		else {
			tempFile << currentTrainName << " " << capacity << " " << departurePoint << " " << destinationPoint << " "
				<< userName << " " << userSurname << " " << userPhoneNum << endl;
		}
	}

	ticketFile.close();
	tempFile.close();

	if (ticketFound) {
		remove("tickets.txt");
		rename("temp.txt", "tickets.txt");
	}
	else {
		cout << "\t\tError: Ticket not found. Please check your train name and phone number.\n";
		remove("temp.txt");
	}
}

//GET SET FONKSÝYONLARI 
void Passenger::setName(string _name) {
	PassengerSurname = _name;
}
void Passenger::setSurname(string _surname) {
	PassengerSurname = _surname;
}
void Passenger::setPhoneNumber(string _PhoneNumber) {
	PhoneNumber = _PhoneNumber;
}
void Passenger::setPassword(string _password) {
	password = _password;
}
string Passenger::getName() {
	return PassengerName;
}
string Passenger::getSurname() {
	return PassengerSurname;
}
string Passenger::getPhoneNumber() {
	return PhoneNumber;
}
string Passenger::getPassword() {
	return password;
}
