#ifndef klasa_h
#define klasa_h

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <random>



using namespace std;



	//zwraca temperature w danym punkcie, uwzglednia brzegi obszaru 
	double temperatura(int i, int j);
	double & siatkaTemperatura(int i, int j);
	bool czyWnetrzeSiatki(int i, int j);
	int losujKierunek();
	int losujPunkt();
	void liczTemperature(int i, int j);
	void sumujTemperaturyRekursywnie(int i, int j, int & n, double & sumaTemperaturSasiadow);
	

	


#endif





