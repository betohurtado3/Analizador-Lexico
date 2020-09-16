#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include "Archivo.h"

using namespace std;

template <class T>
bool TryParse(string input, T & var)
{
    static const string ws(" \t\f\v\n\r");
    size_t pos = input.find_last_not_of(ws);
    if (pos != string::npos)
        input.erase(pos + 1);
    else input.clear();
    stringstream buffer(input);
    return buffer >> var && buffer.eof();
}
int main()
{
    Archivo file;
    string buscando;
    int n; // variable auxiliar para saber si entrada es numerica
    cout<<"Type Something: ";
    getline(cin, buscando);

    if(file.buscar(buscando)){
        file.mostrar();
    }
    else if(TryParse(buscando, n)){
        cout<<"----------------------------------------------------"<<endl;
        cout<<buscando<<": "<<"Es un dato numerico"<<endl;
        cout<<"----------------------------------------------------"<<endl;
    }
    else if(((buscando[0] >= 'A' && buscando[0] <= 'Z') || (buscando[0] >= 'a' && buscando[0] <= 'z') || (buscando[0] == '_' && buscando.length() > 1)) && (buscando.find(" ") == std::string::npos)){
        cout<<"----------------------------------------------------"<<endl;
        cout<<buscando<<": "<<"Es un identificador de variable o constante"<<endl;
        cout<<"----------------------------------------------------"<<endl;
    }
    else if (buscando == "+" || buscando == "-" || buscando == "/" || buscando == "*"){
        cout<<"----------------------------------------------------"<<endl;
        cout<<buscando<<": "<<"Es un operador aritmetico"<<endl;
        cout<<"----------------------------------------------------"<<endl;
    }

    else if (buscando == "<" || buscando == ">" || buscando == "<=" || buscando == ">=" || buscando == "&&" || buscando == "||" || buscando == "==" || buscando == "!="){
        cout<<"----------------------------------------------------"<<endl;
        cout<<buscando<<": "<<"Es un operador logico"<<endl;
        cout<<"----------------------------------------------------"<<endl;
    }

    if (buscando == "="){
        cout<<"----------------------------------------------------"<<endl;
        cout<<buscando<<": "<<"Es un operador de asignacion"<<endl;
        cout<<"----------------------------------------------------"<<endl;     }
    else{
        cout<<"----------------------------------------------------"<<endl;
        cout<<buscando<<": "<<"Es dato no identificado"<<endl;
        cout<<"----------------------------------------------------"<<endl;
    }


}


