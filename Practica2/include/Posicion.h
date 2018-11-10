/**
* @file Posicion.h
* @brief Contiene la descripción de la clase y sus funciones miembro
* @author Juan Antonio Martín Quirós, Juan Alberto Rivera Peña
* @date 30/10/2018
* @version 1.0
*/
#ifndef _POSICION_H_
#define _POSICION_H_
#include<iostream>
using namespace std;
/**
* @brief T.D.A. Posicion
*
* Esta clase Posición representa la interpretación
* de una posición.
*  Para definir el objeto de dicha clase se llamara Posicion objeto.
* Este objeto tendrá todos los atributos de la clase privada de esta clase.
*/
class Posicion{
    friend ostream & operator << (ostream &o, const Posicion &pos);
    friend istream & operator >> (istream &in, Posicion &pos);
    private:
        float latitud;/** <Latitud del objeto >*/
        float longitud;/** <Longitud del objeto >*/
    public:
        /**
        * @brief Constructor por defecto, crea una Posicion con sus valores a 0.0.
        * @param No necesita parámetros
        */
        Posicion();
        /**
        * @brief Constructor para valores de una Posicion.
        * @param lat float para la latitud de la posición.
        * @param longi float para la longitud de la posición.

        */
        Posicion(float lat, float longi);
        /**
        * @brief Asigna una latitud al objeto.
        * @param lat float que indica la latitud..
        */
        void setLatitud(float lat);/**
        * @brief Asigna un longitud al objeto.
        * @param longi float que indica la longitud.
        */
        void setLongitud(float longi);/**
       * @brief Devuelve la latitud del objeto.
       * @retval float con la latitud.
       */
        float GetLat()const;/**
       * @brief Devuelve la longitud del objeto.
       * @retval float con la longitud..
       */
        float GetLon()const;

};
#endif
