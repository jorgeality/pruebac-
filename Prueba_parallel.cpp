#include <string>
#include <iostream>
//lectura de archivos
#include <fstream>
//para usar los aceentos.
#include <locale.h>
//funciona para paralelizar.
#include <omp.h>
using namespace std;



int main() {
  //Usamos el setlocale, para poder usar los acentos.
  setlocale(LC_ALL, "");
 /*En esta parte usamos el ifstream para leer el archivo*/
  ifstream in("quijotet.txt");
 /*Declaracion de variables y arrays a usar*/
  string s, line;
  int cont = 0;
  char caracter[] = {'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','T','t','u','v','V','w','W','x','X','y','Y','z','Z',',',';','.',':','-','_','"','!',' '};
 /*En esta parte lo que hacemos es leer el documento linea por linea.
    Lo almacenamos todo en un sola variable de tipo string llamada
   's'. Posteriormente cerramos el documento que se ha abierto para ser leido.*/
  while(getline(in, line))
    s += line;
  in.close();
     //Usamos el tamaño del  array caracter para su iteración en el ciclo for 
     // en donde se ejecutara el proceso a realizar.
    int num = sizeof caracter;
    //Configuración de la cantidad de threads para la ejecución del programa.
    omp_set_num_threads(4);

     /*En esta parte podermos ver  claramente un bottleneck, y justo aqui 
	es donde paralelizamos un for doble.
	Justo en esta parte podemos ver claramente como cada caracter del 
	array est siendo comparada con cada uno de los caracteres del archivo.
	*/
	#pragma omp for schedule(static)
	for(int i = 0; i < num;i++)
    	{

  			for(int j = 0; j < s.size();j++)
			{
				//Comparaciones mencionadas.
		   		if(caracter[i] == s[j])
		   		{
					//Contador de caracteres.
		   			cont++;
		   		}
			}
			/*En esta condicional solo decimos que si el contador que acaba de salir es mayor a cero 
			 entonces me imprima el caracter comparado, y el numero de veces que se repite.
			*/
			if(cont > 0)
			{
				cout<<caracter[i]<<" = "<<cont<<endl;
			}
			//Hacemos cero nuevamete el contador.
			cont = 0;
    	}

 return 0;
}

