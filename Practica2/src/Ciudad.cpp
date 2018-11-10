#include "Ciudad.h"

using namespace std;

Ciudad::Ciudad(){
     nombre="";
     pais="";
     posicion=Posicion();
     poblacion=0;
}
Ciudad::Ciudad(string nombre, string pais, Posicion posicion, int poblacion){
    this->nombre=nombre;
    this->pais=pais;
    this->posicion=posicion;
    this->poblacion=poblacion;
}
void Ciudad::setNombre(string nombre){
    this->nombre=nombre;
}
void Ciudad::setPais(string pais){
    this->pais=pais;
}
void Ciudad::setPosicion(Posicion posicion){
    this->posicion=posicion;
}
void Ciudad::setPoblacion(int poblacion){
    this->poblacion=poblacion;
}
string Ciudad::GetNombre()const{
    return nombre;
}
string Ciudad::GetPais()const{
    return pais;
}
Posicion Ciudad::GetPosicion()const{
    return posicion;
}
int Ciudad::GetPoblacion()const{
    return poblacion;
}

string Ciudad::GetCiudad()const{
    return nombre;
}
Ciudad& Ciudad::operator=(const Ciudad&original){
    nombre=original.nombre;
    pais=original.pais;
    posicion=original.posicion;
    poblacion=original.poblacion;
}
ostream & operator << (ostream &o, const Ciudad &ciu){
    o  << ciu.nombre << ";"<< ciu.pais << ";" << ciu.posicion << ciu.poblacion  ;
    return o;
}

istream & operator >> (istream &in, Ciudad &ciu){
    getline(in, ciu.nombre, ';')  ;
    getline(in, ciu.pais, ';')  ;
    in >>  ciu.posicion ;
    in >>ciu.poblacion ;
    in.ignore(1);
    return in;
}
