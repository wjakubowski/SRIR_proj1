#include "srir1.h"


int losujKierunek()
{
	extern default_random_engine generator;
	static uniform_int_distribution<int> los_zero_jeden(0,1);
	return los_zero_jeden(generator)*2-1;
}

int losujPunkt()
{
	extern int rozmiarSiatki;
	extern default_random_engine generator;
	static uniform_int_distribution<int> los_punkt(0,rozmiarSiatki-1);
	return los_punkt(generator);
}

double temperatura(int i, int j)
{
	extern vector < vector <double> > siatka;
	extern const int rozmiarSiatki;
	extern const double temperaturaBrzegu3;
	extern const double temperaturaBrzegu1;
	
	if(i<0 || j<0 || i>=rozmiarSiatki)
		return temperaturaBrzegu3;
	else if(j>=rozmiarSiatki)
		return temperaturaBrzegu1;
	else
		return siatka[i][j];
}

double & siatkaTemperatura(int i, int j)
{
	extern vector < vector <double> > siatka;
	return siatka.at(i).at(j);
}

bool czyWnetrzeSiatki(int i, int j)
{
	extern const int rozmiarSiatki;
	return i>=0 && j>=0 && i<rozmiarSiatki && j<rozmiarSiatki;
}

void liczTemperature(int i, int j)
{
	double sumaTemperaturSasiadow = 0.0;
	//ilosc zsumowanych sasiadow
	int n = 0;
	if(losujKierunek()==1)
		sumujTemperaturyRekursywnie(i+losujKierunek(), j, n, sumaTemperaturSasiadow);
	else
		sumujTemperaturyRekursywnie(i, j+losujKierunek(), n, sumaTemperaturSasiadow);
	siatkaTemperatura(i,j) = sumaTemperaturSasiadow/n;
	//cout << "n: " << n << "\tsum: " << sumaTemperaturSasiadow << "\tsred: " << sumaTemperaturSasiadow/n << endl;
	
}

void sumujTemperaturyRekursywnie(int i, int j, int & n, double & sumaTemperaturSasiadow)
{
	extern const int maxGlebokoscRekursji;
	if(czyWnetrzeSiatki(i,j) && n<maxGlebokoscRekursji)
	{
		//cout << "i: "<< i << "\tj: " << j  << endl;
		if(losujKierunek()==1)
			sumujTemperaturyRekursywnie(i+losujKierunek(), j, n, sumaTemperaturSasiadow);
		else
			sumujTemperaturyRekursywnie(i, j+losujKierunek(), n, sumaTemperaturSasiadow);
		//cout << "n: " << n << "\tsum: " << sumaTemperaturSasiadow << "\tsred: " << sumaTemperaturSasiadow/n << endl;
		
		double tmp = sumaTemperaturSasiadow/n;
		sumaTemperaturSasiadow += temperatura(i,j);
		++n;
		
		siatkaTemperatura(i,j) = tmp;
	}
	else
	{
		//cout << "Napodkano brzeg:\ti: " << i << "\tj: " << j << endl;
		//cout << "n: " << n << "\tsum: " << sumaTemperaturSasiadow << "\tsred: " << sumaTemperaturSasiadow/n << endl;
		sumaTemperaturSasiadow += temperatura(i,j);
		++n;
	}
}