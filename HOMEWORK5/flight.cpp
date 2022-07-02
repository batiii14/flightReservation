#include <iostream>
#include <string>
#include "FlightRes.h"
using namespace std;

void main()
{		
	
		FlightRes resauto;
		FlightRes resptr1, * ptr1;
		ptr1 = &resptr1;
		FlightRes *resptr2 = new FlightRes; 
		FlightRes* resArr = new FlightRes[10]; 

		cout << "\n\nNUMBER OF RESERVATIONS IN THIS FLIGHT IS: " << FlightRes::totRes << endl;//here the number of reservation2
		cout << "\n\n" << endl;
		resauto.setpName("Maria Bruno");
		showFlight(resauto);
		showFlight(resptr1);
		showFlight(*resptr2);
		for (int i = 0; i < 10; i++) {
			showFlight(resArr[i]);
		}


		delete resptr2;
		delete[] resArr;

	




}