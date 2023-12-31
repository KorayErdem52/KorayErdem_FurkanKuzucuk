#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>
using namespace std;

class Train {
private:
	string TrainName;
	int capacity;
	string departurePoint;
	string destinationPoint;
public:
	Train(string _TrainName, int _capacity, string _departurePoint, string _destinationPoint);
	Train();

	//-------Set Fonksiyonlarý------- 
	void setName(string _name);
	void setCapacity(int _capacity);
	void setDeparture(string _departurePoint);
	void setDestination(string _destination);

	//-------Get Fonksiyonlarý------- 
	string getName();
	int getCapacity();
	string getDeparture();
	string getDestination();

	//-------Diðer Fonsksiyonlar-------
	void TrainInfo();
	void addTrain();
	void addTrain(string _TrainName, int _capacity, string _departurePoint, string _destinationPoint);
	friend void addTrainHelper(Train& trainObj);
	void showTrains();
	void deleteTrain();
	void updateTrain();
	int CalculatePrice(string Destination);
};
#endif