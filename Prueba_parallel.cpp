#include <string>
#include <iostream>
//lectura de archivos
#include <fstream>
//para usar los aceentos.
#include <locale.h>



using namespace std;

int main() {
	//para poder usar los acentos.
  setlocale(LC_ALL, "");
  
  ifstream in("quijote.txt");
  string s, line;
  int cont = 0; 
  char caracter[] = {'a','á','A','Á','b','B','c','C','d','D','e','é','E','É','f','F','g','G','h','H','i','í','I','Í','j','J','k','K','l','L','m','M','n','N','ñ','Ñ','o','ó','O','Ó','p','P','q','Q','r','R','s','S','T','t','u','ú','v','V','w','W','x','X','y','Y','z','Z',',',';','.',':','-','_','"','´','!'};
  while(getline(in, line))
    s += line;
    
	
    int num = sizeof caracter;
   	
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

