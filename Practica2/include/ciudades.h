#ifndef _CIUDADES_H_
#define _CIUDADES_H_
#include<Posicion.h>
#include<Ciudad.h>
#include<VD.h>
#include<iostream>
#include<string.h>
#include<string>

struct comprueba {
 int pos;
 bool esta;
};

class Ciudades{
    friend ostream & operator << (ostream &os, const Ciudades &pos);
    friend istream & operator >> (istream &f, Ciudades &pos);
    private:
        VD<Ciudad>datos;
        VD<int>indice;
    public:
        Ciudades();
        //Ciudades(const VD<Ciudades> &original);
        VD<Ciudad> getDatos()const;
        VD<int> getIndice();
        Ciudades GetAllCiudadesPais(string pais);
        Ciudades GetCiudad_Ciudad_PorNombre(string name);
        int getPosicionCiudad(const Ciudad&ciu);
        comprueba Esta_en_Datos(const Ciudad& ciu);
        int Esta_en_Indice(const Ciudad& ciu);
        void insertar(const Ciudad& nueva);
        void BorrarCiudad(const Ciudad &nombre);
        Ciudad GetCiudad_Ciudad(int pos);
        Ciudad getNombre(string nombre);
        VD<string> getCiudades(string pais);
        Ciudad& operator[](int i);
        const Ciudad& operator[](int i)const;
        Ciudades&operator=(const Ciudades&original);
        int size()const;

        //void setCiudades(int i, int j, String ciudades)
};

#endif
