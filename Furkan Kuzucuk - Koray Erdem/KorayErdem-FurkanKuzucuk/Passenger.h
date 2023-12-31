#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <list>
#include <vector>
using namespace std;


class Passenger {
private:
	string PassengerName, PassengerSurname;
	string PhoneNumber;
	string password;
	static int totalPassengers;
public:
	Passenger(string _name, string _surname, string _PhoneNumber, string _password);

	//Passenger Fonksiyonlarý 
	static void Passsenger();
	void SignUp();
	void showPassengers();
	bool readPassenger();
	void bookticket();
	void updatePassword();
	void userProfile();
	void cancelticket();
	void myTickets();

	//-------OPERATOR OVERLOADING-----------
	bool operator==(const Passenger& otherPassenger) const {
		return this->PhoneNumber == otherPassenger.PhoneNumber;
	}

	//Set Fonksiyonlarý 
	void setName(string _name);
	void setSurname(string _surname);
	void setPhoneNumber(string _PhoneNumber);
	void setPassword(string _password);

	//Get Fonksiyonlarý 
	string getName();
	string getSurname();
	string getPhoneNumber();
	string getPassword();

};
#endif

