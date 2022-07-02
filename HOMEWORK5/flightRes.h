#include <iostream>
#include <string>

using namespace std;

class FlightRes {
private:
	string pName;
	int seatNo;
	int poption;
	double fcost;
	string fdate;
	string destination;
	string origin;

	void calculateCost() {
		if (this->poption == 1) {
			this->fcost = 250 - (250 * 10) / 100;
			cout << "The flight cost is:" << this->fcost << endl;
		}
		else if (this->poption == 2) {
			this->fcost = 250 - (250 * 15) / 100;
			cout << "The flight cost is:" << this->fcost << endl;
		}
		else if (this->poption == 3) {
			this->fcost = 250;
			cout << "The flight cost is:" << this->fcost << endl;
		}
		else {
			cout << "You have entered invalid value" << endl;

		}
	}


public:
	int checkSeat;
	static int num;
	static int totRes;
	static string nameOfPassenger[50];
	static int seatTaken[50];
	static int start;
	static int count;

	FlightRes()
	{
		cout << "Please enter your name" << endl;
		cin >> this->pName;
		cout << "Enter seat number" << endl;
		cin >> checkSeat;
		checkSeatValidity(checkSeat);
		cout << "Please enter your flight date(DD-MON-YYYY)" << endl;
		cin >> this->fdate;
		cout << "Please enter origin city" << endl;
		cin >> this->origin;
		cout << "Please enter destination city" << endl;
		cin >> this->destination;
		cout << "Payment Options--Base cost is 250 tl for every flight--\n1-EMU students(%10 discount)\n2-EMU-IT-MIS students (%15 discount)\n3-Standard Passenger (no discount)\nenter your choice (1,2 or 3):" << endl;
		cin >> this->poption;
		calculateCost();





		totRes++;



	}

	static int gettotRes()
	{
		return totRes;

	}
	void setpName(string name)
	{
		this->pName = name;

	}
	void setDestination(string destination)
	{
		this->destination = destination;
	}

	void setOrigin(string origin)
	{
		this->origin = origin;

	}
	void checkSeatValidity(int seatNo)
	{

		if (seatNo < 1 || seatNo>50) {
			cout << "Seat number must be between 1 and 50.\nPlease enter your try another seat number: " << endl;
			cin >> checkSeat;
			checkSeatValidity(checkSeat);
		}
		else {
			if (start == 0)
			{
				for (int i = 0; i < 50; i++) {
					seatTaken[i] = 0;
				}
				start = 1;
				seatTaken[count] = seatNo;
				this->seatNo = seatNo;
				nameOfPassenger[count] = this->pName;



			}
			else {
				bool isItequal = false;
				for (int i = 0; i < 50; i++) {
					if (seatNo == seatTaken[i]) {
						isItequal = true;
						num = i;

					}


				}
				if (isItequal) {
					cout << "Sorry that seat has been taken by " << nameOfPassenger[num] << " please try another seat: " << endl;
					cin >> checkSeat;
					checkSeatValidity(checkSeat);
				}
				else {
					this->seatNo = seatNo;
					seatTaken[count] = seatNo;
					nameOfPassenger[count] = this->pName;
					count++;
				}

			}

		}



	}

	~FlightRes()
	{
		cout << "The passenger " << this->pName << " with the seat number of " << this->seatNo << " has been deleted" << endl;
		totRes--;
	}
	friend void showFlight(FlightRes obj);
};
string FlightRes::nameOfPassenger[50];
int FlightRes::seatTaken[50];
int FlightRes::totRes = 0;
int FlightRes::start = 0;
int FlightRes::count = 0;
int FlightRes::num = 0;



void showFlight(FlightRes obj)
{
	cout << "\nPassanger Name: " << obj.pName
		<< "\nSeat number: " << obj.seatNo
		<< "\nOrigin City: " << obj.origin
		<< "\nDestination: " << obj.destination
		<< "\nFlight Date: " << obj.fdate
		<< "\nFlight Cost: " << obj.fcost << endl;

}