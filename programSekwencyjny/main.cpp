#include <iostream>
// #include <string>
//#include <algorithm>
//#include <cmath>
//#include <vector>
#include <cstdlib>
#include <random>
#include <chrono>


#include "srir1.h"
#include "PropertyFileConfiguration.h"

using namespace std;

vector < vector <double> > siatka;
int rozmiarSiatki = 20;
extern const double temperaturaBrzegu3 = 0.0;
extern const double temperaturaBrzegu1 = 100.0;
const double temperaturaPoczatkowa = 50.0;
int maxGlebokoscRekursji = 1000;

//random_device rd;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator (seed);




int main()
{
	//mamy plik z parametrami które mozna zmieniac bez potrzeby kompilowania
	PropertyFileConfiguration readProperties("properties.txt");
	double iteracje = readProperties.getDouble("iteracje");
	rozmiarSiatki = readProperties.getInt("rozmiarSiatki");
	maxGlebokoscRekursji = readProperties.getInt("maxGlebokoscRekursji");
	//cout << "N:\t" << N << "\talpha:\t" << alpha << endl;
	
	//inicjalizacja siatki punktow
	siatka = vector < vector <double> > (rozmiarSiatki);
	for(auto & v:siatka)
	{
		v.resize(rozmiarSiatki);
		for(auto & p:v)
			p = temperaturaPoczatkowa;
	}
	
	for(int t=0; t<iteracje; ++t)
		liczTemperature(losujPunkt(),losujPunkt());
	
	ofstream plikWynikowy;
	plikWynikowy.open("rozklad.txt", ofstream::trunc);
	
	for(int i=-1; i<=rozmiarSiatki; ++i)
	{
		for(int j=-1; j<=rozmiarSiatki; ++j)
			plikWynikowy << temperatura(i,j) << '\t';
		plikWynikowy << endl;
	}
	
	plikWynikowy.close();
	
	system("python ./rysuj.py");
	
	
	
	
	
	
	
	
	
	
	
	

};

