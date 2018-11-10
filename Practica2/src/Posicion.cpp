#include "Posicion.h"
using namespace std;

Posicion::Posicion(){
    latitud=0;
    longitud=0;
}
Posicion::Posicion(float lat, float longi){
    latitud=lat;
    longitud=longi;
}
void Posicion::setLatitud(float lat){
    latitud=lat;
}
void Posicion::setLongitud(float longi){
    longitud=longi;
}
float Posicion::GetLat()const{
    return latitud;
}
float Posicion::GetLon()const{
        return longitud;
}
ostream & operator << (ostream &o, const Posicion &pos){
    o  << pos.latitud << ";"<< pos.longitud << ";" ;
    return o;
}

istream & operator >> (istream &in, Posicion &pos){
    in >> pos.latitud;
    in.ignore(1);
    in >> pos.longitud;
    in.ignore(1);
    return in;
}
