#include "Map.h"
#include "Map_Set.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

Map<string, Pair<double, double>> CityLocations;

double HaversineDistance(double Latitude1, double Longitude1, double Latitude2, double Longitude2)
{
	double R = 6371; // Radius of Earth in km
	double Lat1 = Latitude1 * M_PI / 180;
	double Lat2 = Latitude2 * M_PI / 180;
	double dLat = (Latitude2 - Latitude1) * M_PI / 180;
	double dLon = (Longitude2 - Longitude1) * M_PI / 180;
	double a = sin(dLat / 2) * sin(dLat / 2) + cos(Lat1) * cos(Lat2) * sin(dLon / 2) * sin(dLon / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	return R * c;
};

void Menu()
{
	cout << "Chose 2 cities to find the distance between them" << endl;
	for (string CityName : CityLocations.keys())
	{
		cout << CityName << " ... ";
	}
	cout << endl;
	cout << "Enter the first city: " << endl;
	string City1;
	cin >> City1;
	cout << "Enter the second city: " << endl;
	string City2;
	cin >> City2;
	Pair<double, double> City1Location = CityLocations[City1];
	Pair<double, double> City2Location = CityLocations[City2];
	double Distance = HaversineDistance(City1Location.first, City1Location.second, City2Location.first, City2Location.second);
	cout << "The distance between " << City1 << " and " << City2 << " is " << Distance << " km" << endl;
}

int main()
{
	//Set Up Map of City Locations
	ifstream CitiesFile("hw5_input.txt");
	string Line;
	while (getline(CitiesFile, Line))
	{
		int WhitespaceIndex = Line.find(" ");
		string CityName = Line.substr(0, WhitespaceIndex);
		string RestOfLine = Line.substr(WhitespaceIndex + 1);
		double Latitude, Longitude;
		WhitespaceIndex = RestOfLine.find(" ");
		Latitude = stod(RestOfLine.substr(0, WhitespaceIndex));
		Longitude = stod(RestOfLine.substr(WhitespaceIndex + 1));
		CityLocations[CityName] = Pair<double, double>(Latitude, Longitude);
	};

	CitiesFile.close();

	//Run Menu
	while (true)
	{
		Menu();
		cout << "Would you like to find the distance between two more cities? (y/n)" << endl;
		string Continue;
		cin >> Continue;
		if (Continue == "n")
		{
			break;
		}
	}
}