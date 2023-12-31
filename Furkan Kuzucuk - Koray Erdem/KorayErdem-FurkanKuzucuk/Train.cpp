#include <iostream>
#include "Train.h"
#include <windows.h>
#include <vector>
#include <fstream>
vector<Train>TrainList;
using namespace std;


Train::Train(string _TrainName, int _capacity, string _departurePoint, string _destinationPoint) {
	this->TrainName = _TrainName;
	this->capacity = _capacity;
	this->departurePoint = _departurePoint;
	this->destinationPoint = _destinationPoint;
}
Train::Train() {   }

void Train::TrainInfo() {
	cout << "    " << TrainName << "         " << capacity << "         " << departurePoint << "             " << destinationPoint << endl;
}
void Train::addTrain() {
	int price;
	string _TrainName;
	int _capacity;
	string _departurePoint;
	string _destinationPoint;
	cout << "\t\tTrain Name : ";
	cin >> _TrainName;
	cout << "\t\tDeparture Point : ";
	cin >> _departurePoint;
	cout << "\t\tDestination Point : ";
	cin >> _destinationPoint;
	cout << "\t\tCapacity : ";
	cin >> _capacity;
	price = CalculatePrice(_destinationPoint);
	Train train(_TrainName, _capacity, _departurePoint, _destinationPoint);
	TrainList.push_back(train);
	ofstream FileTrain("trains.txt", ios::app);
	if (FileTrain.is_open()) {
		for (const auto& train : TrainList) {
			FileTrain << _TrainName << "  " << _capacity << "  " << _departurePoint << "  " << _destinationPoint << "  " << price << endl;;
		}
		FileTrain.close();
	}
}

//--------FRÝEND FUNCTÝON-------------
void addTrainHelper(Train& trainObj) {
	trainObj.addTrain();
}
//------------------------------------

//--------FUNCÝTON OVERLOADÝNG--------
void Train::addTrain(string _TrainName, int _capacity, string _departurePoint, string _destinationPoint) {
	Train train(_TrainName, _capacity, _departurePoint, _destinationPoint);
	TrainList.push_back(train);
}
//------------------------------------


void Train::showTrains() {
	ifstream FileTrain("trains.txt");
	if (FileTrain.is_open()) {
		cout << "\t\t-------------------------------" << endl;
		string trainName;
		int capacity;
		string departurePoint;
		string destinationPoint;
		int price;
		while (FileTrain >> trainName >> capacity >> departurePoint >> destinationPoint >> price) {
			cout << "\t\tTrain Name : " << trainName << "\n";
			cout << "\t\tCapacity : " << capacity << "\n";
			cout << "\t\tDeparture Point : " << departurePoint << "\n";
			cout << "\t\tDestination Point : " << destinationPoint << "\n";
			cout << "\t\tTicket Price : " << price << endl;
			cout << "\t\t-------------------------------" << endl;
		}
		FileTrain.close();
	}
	else {
		cerr << "\t\tError: Unable to open the file.\n";
	}
}

void Train::deleteTrain() {
	string userTrainName;
	cout << "\t\tEnter a train name to remove: ";
	cin >> userTrainName;

	ifstream inFile("trains.txt");
	ofstream outFile("temp.txt");

	if (!inFile.is_open() || !outFile.is_open()) {
		cerr << "\t\tError: Unable to open the file(s).\n";
		return;
	}

	string currentTrainName;
	int capacity;
	string departurePoint;
	string destinationPoint;
	int price;
	bool found = false;

	while (inFile >> currentTrainName >> capacity >> departurePoint >> destinationPoint >> price) {
		if (currentTrainName == userTrainName) {
			found = true;
		}
		else {
			outFile << currentTrainName << "  " << capacity << "  "
				<< departurePoint << "  " << destinationPoint << "  " << price << "\n";
		}
	}

	inFile.close();
	outFile.close();

	if (found) {
		remove("trains.txt");
		rename("temp.txt", "trains.txt");
		cout << "\t\tTrain with name " << userTrainName << " removed successfully.\n";
	}
	else {
		cout << "\t\tTrain with name " << userTrainName << " not found.\n";
		remove("temp.txt");
	}
}

void Train::updateTrain() {
	string userTrainName;
	cout << "\t\tEnter a train name to update: ";
	cin >> userTrainName;

	ifstream inFile("trains.txt");
	ofstream outFile("temp.txt");

	if (!inFile.is_open() || !outFile.is_open()) {
		cerr << "\t\tError: Unable to open the file\n";
		return;
	}

	string currentTrainName;
	int capacity;
	string departurePoint;
	string destinationPoint;
	int price;

	bool found = false;

	while (inFile >> currentTrainName >> capacity >> departurePoint >> destinationPoint >> price) {
		if (currentTrainName == userTrainName) {
			found = true;
			cout << "\t\tEnter new capacity: ";
			cin >> capacity;
			cout << "\t\tEnter new departure point: ";
			cin >> departurePoint;
			cout << "\t\tEnter new destination point: ";
			cin >> destinationPoint;
			price = CalculatePrice(destinationPoint);
			outFile << currentTrainName << "  " << capacity << "  "
				<< departurePoint << "  " << destinationPoint << "  " << price << "\n";
		}
		else {
			outFile << currentTrainName << "  " << capacity << "  "
				<< departurePoint << "  " << destinationPoint << "\n";
		}
	}

	inFile.close();
	outFile.close();

	if (found) {
		remove("trains.txt");
		rename("temp.txt", "trains.txt");
		cout << "\t\tTrain with name " << userTrainName << "updated successfully.\n";
	}
	else {
		cout << "\t\tTrain with name " << userTrainName << " not found.\n";
		remove("temp.txt");
	}
}

int Train::CalculatePrice(string Destination) {
	int distance = 0;
	int price = 0;
	ifstream Distance("Distance.txt");
	string destination;
	while (Distance >> destination >> distance) {
		if (Destination == destination) {
			price = distance / 5;
		}
	}
	cout << "\t\tPrice : " << price << endl;
	return price;
}

void Train::setName(string _Name) {
	TrainName = _Name;
}
void Train::setCapacity(int _capacity) {
	capacity = _capacity;
}
void Train::setDeparture(string _departure) {
	departurePoint = _departure;
}
void Train::setDestination(string _destination) {
	destinationPoint = _destination;
}
string Train::getName() {
	return TrainName;
}
int Train::getCapacity() {
	return capacity;
}
string Train::getDeparture() {
	return departurePoint;
}
string Train::getDestination() {
	return destinationPoint;
}