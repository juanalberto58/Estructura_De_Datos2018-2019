/**
* @file Ciudad.h
* @brief Contiene la descripción de la clase y sus funciones miembro
* @author Juan Antonio Martín Quirós, Juan Alberto Rivera Peña
* @date 30/10/2018
* @version 1.0
*/
#ifndef _CIUDAD_H_
#define _CIUDAD_H_
#include<iostream>
#include<string.h>
#include<Posicion.h>
using namespace std;
/**
* @brief T.D.A. Ciudad
*
* Esta clase Ciudades representa la interpretación
* de una ciudad.
*  Para definir el objeto de dicha clase se llamara Ciudad objeto.
* Este objeto tendrá todos los atributos de la clase privada de esta clase.
*/
class Ciudad{
    friend ostream & operator << (ostream &o, const Ciudad &pos);
    friend istream & operator >> (istream &in, Ciudad &pos);
    private:
        string nombre;/**<Nombre de la ciudad.>*/
        string pais;/**<País al que pertenece la ciudad.>*/
        Posicion posicion;/**<Posición en la que se encuentra, definida por latitud y longitud>*/
        int poblacion;/**<Número de habitantes de la ciudad>*/
    public:
        /**
        * @brief Constructor por defecto, crea una Ciudad con sus valores a null.
        * @param No necesita parámetros
        */
        Ciudad();
        /**
        * @brief Constructor para valores de una Ciudad.
        * @param nombre String para el nombre de la ciudad.
        * @param pais String para el nombre del país de la ciudad.
        * @param posicion Posicion en la que se encuentra la ciudad.
        * @param poblacion Entero que indica el número de habitantes de la ciudad.
        */
        Ciudad(string nombre, string pais, Posicion posicion, int poblacion);
        /**
        * @brief Asigna un nombre al objeto.
        * @param nombre String que indica el nombre.
        */
        void setNombre(string nombre);
        /**
        * @brief Asigna un pais al objeto.
        * @param pias String que indica el pais.
        */
        void setPais(string pais);
        /**
        * @brief Asigna una posicion al objeto.
        * @param posicion Posicion que indica la latitud y longitud.
        */
        void setPosicion(Posicion posicion);
        /**
        * @brief Asigna una poblacion al objeto.
        * @param poblacion Entero que indica el nombre.
        */
        void setPoblacion(int poblacion);
        /**
       * @brief Devuelve un comentario con el nombre de la ciudad.
       * @retval String con el nombre.
       */
        string GetNombre()const; /**
        * @brief Devuelve un comentario con el nombre del pais de la ciudad.
        * @retval String con el nombre del pais..
        */
        string GetPais()const; /**
        * @brief Devuelve un comentario con la posicion del objeto.
        * @retval Posicion con la posicion del objeto.
        */
        Posicion GetPosicion()const;
        /**
       * @brief Devuelve un comentario con la población del objeto.
       * @retval int con la cantidad de personas que viven la ciudad.
       */
        int GetPoblacion()const;

        Ciudad& operator=(const Ciudad&original);

        string GetCiudad()const;

};
#endif
