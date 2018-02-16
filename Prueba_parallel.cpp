#include <string>
#include <iostream>
//lectura de archivos
#include <fstream>
//para usar los aceentos.
#include <locale.h>
//funciona para paralelizar.
#include <omp.h>
using namespace std;

int hid, cont, nh;


int main() {
	//para poder usar los acentos.
  setlocale(LC_ALL, "");

  ifstream in("../quijote.txt");
  string s, line;
  cont = 0;
  char caracter[] = {'a','�','A','�','b','B','c','C','d','D','e','�','E','�','f','F','g','G','h','H','i','�','I','�','j','J','k','K','l','L','m','M','n','N','�','�','o','�','O','�','p','P','q','Q','r','R','s','S','T','t','u','�','v','V','w','W','x','X','y','Y','z','Z',',',';','.',':','-','_','"','�','!'};
  while(getline(in, line))
    s += line;


  in.close();

    int num = sizeof caracter;
 //omp_set_num_threads(numero de hilos)


    #pragma omp parallel for schedule(static)


	for(int i = 0; i < num;i++)
    	{

  			for(int j = 0; j < s.size();j++)
			{
		   		if(caracter[i] == s[j])
		   		{
		   			cont++;
		   		}
			}
			if(cont > 0)
			{
				cout<<caracter[i]<<" = "<<cont<<endl;
			}

			cont = 0;
    	}




}

