#ifndef property_h
#define property_h

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>

/*
urzytkowanie:
-wystarczy dodac ten plik do folderu ze swoim kodem i w pliku .cpp zainkludowac:
#include "PropertyFileConfiguration.h"

-utworzyc plik z parametrami do symulacji, np o tresci:

nm_L = 20
nm_dx = 0.1

-w programie sczytuje wartosci z tego pliku w taki sposob:

PropertyFileConfiguration readProperties("nazwa_pliku.txt");
double L = readProperties.getDouble("nm_L");
double dx = readProperties.getDouble("nm_dx");

-sa jeszcze funkcjie getString() i getInt()
-plik txt nie zwraca uwagi na spacje i tabulatory ale kazda wartosc powinna byc w osobnej lini

-to oczywiście nie jest jakies cudo i wywali program jak popelni sie blad typu:
L=7.55555.4


*/

using namespace std;

class PropertyFileConfiguration
{
	private:
	void split(const string &s, char delim, vector<string> &elems);
	vector<string> split(const string &s, char delim);
	map<string,string> prop_map;
	string file_name;
	public:
	PropertyFileConfiguration(string file_name);
	string getString(string kay);
	int getInt(string kay);
	double getDouble(string kay);
	void printProperties();
	void changeProperty(string key,string val);
};


#endif
