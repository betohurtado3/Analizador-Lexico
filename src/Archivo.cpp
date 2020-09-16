#include "Archivo.h"
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

Archivo::Archivo()
{
    //ctor
}

Archivo::~Archivo()
{
    //dtor
}
void Archivo::Aregar()
{
    ofstream archivo("Diccionario.txt", ios::app);
    cout<<"Type your input: "<<endl;
    getline(cin,entrada);

    cout<<"Define the input: "<<endl;
    getline(cin,definicion);



    archivo<<entrada<<"|"<<definicion<<"|"<<endl;
    archivo.close();
}

void Archivo :: buscar()
{
    bool bandera=false;
    int i,campo;
	string auxiliar;
	string total;
	ifstream Lectura("Diccionario.txt");
	if(!Lectura.good())
	{
		cout<<"\nFile Doesn't exit ";
	}
	else
    {
        string buscando;
        cout<<"Type Something: "<<endl;
        getline(cin, buscando);
        while(getline(Lectura,auxiliar))
        {
            campo = 0;
            for(i = 0; i< auxiliar.length();i++)
            {
              if(auxiliar[i] != '|')
                    total += auxiliar[i];
              else
              {
                  campo++;
                  switch(campo)
                  {
                  case 1:
                        entrada = total;
                        break;
                    case 2:
                        definicion = total;
                        break;
                  }
                total = "";
              }
            }
            if(buscando == entrada)
            {
                bandera=true;
                cout<<"----------------------------------------------------"<<endl;
                cout<<entrada<<": "<<definicion<<endl;
                cout<<"----------------------------------------------------"<<endl;
            }
        }
        if(bandera==false)
            cout<<"\ninput not recognized \n "<<endl;
    }
    Lectura.close();
}
