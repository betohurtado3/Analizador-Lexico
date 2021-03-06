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

bool Archivo :: buscar(string buscando)
{
    bool bandera=false;
    int i,campo;
	string auxiliar;
	string total;
	ifstream Lectura("Diccionario.txt");
	bool respuesta;
	if(!Lectura.good())
	{
		cout<<"\nFile Doesn't exit ";
	}
	else
    {
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
                respuesta = true;
                break;
            }
        }
        if(bandera==false)
            respuesta = false;;
    }
    Lectura.close();
    return respuesta;
}

void Archivo:: mostrar()
{
    cout<<"----------------------------------------------------"<<endl;
    cout<<entrada<<": "<<definicion<<endl;
    cout<<"----------------------------------------------------"<<endl;
}
