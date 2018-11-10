#include "ciudades.h"
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include <utility>
#include <set>
#define PI 3.14159265
#define RADIO_TIERRA 6378 //radio ecuatorial


/**
 * @brief Convierte grados a radianes
 * @param d: valor en grados
 * @return el valor en radianes
 */
float ToRadianes(float d){
    return PI/180*d;
}
/**
 * @brief Dadas dos posiciones obtiene la distancia en Kms
 * @param posOrigen: Posicion de un punto geografico
 * @param posDestino: Posicion de un punto geografico
 * @return la distancia en kms entre dos posiciones
 */
float DistanciaKm(Posicion posOrigen, Posicion posDestino)
{
  float difLatitud = ToRadianes(posDestino.GetLat()-posOrigen.GetLat());
  float difLongitud =ToRadianes(posDestino.GetLon()-posOrigen.GetLon());
  float a = pow(sin(difLatitud/2),2)+
          cos(ToRadianes(posOrigen.GetLat()))*
          cos(ToRadianes(posDestino.GetLat()))*
          pow(sin(difLongitud/2),2);
   float c = 2 *atan2(sqrt(a), sqrt(1 -a));

   return RADIO_TIERRA*c;
}

/**
 * @brief Obtiene la poblacion total de un conjunto de ciudades
 * @param v: Conjunto de ciudades
 * @return la suma de las poblaciones en dichas ciudades
*/
unsigned int ObtenerPoblacion(const Ciudades & v){
  unsigned int n=v.size();
  unsigned int t_pob=0;
  for (unsigned int i=0;i<n;i++)
    t_pob+=v[i].GetPoblacion();
  return t_pob;
}
/**
 * @brief mensaje en pantalla indicando los parametros del programa
 */
void Mensaje(){
  cout<<"Los parametros son:"<<endl;
  cout<<"1.- Fichero con la informacion de las ciudades "<<endl;
  cout<<"2. Ciudad.  "<<endl;
  cout<<"3. Pais. "<<endl;
  cout<<"4. Número de ciudades a mostrar." << endl;
  return;
}

Ciudad obtenerCiudad(Ciudades misciudades,char* nombre, char* pais){
    Ciudad parametro;
    for(unsigned int i=0;i<misciudades.size();i++){
        if(misciudades[i].GetNombre()==nombre && misciudades[i].GetPais()==pais ){
            parametro=misciudades[i];
            return parametro;
        }
    }
    return parametro;

}
VD<pair<Ciudad, float>> obtenerDistanciaCiudad(Ciudades misciudades, Ciudad parametro){
        pair<Ciudad,float>auxpair;
        float aux=0;
        VD<pair<Ciudad, float>>cercanas;
        for(int i=0;i<misciudades.size();i++){
            aux=DistanciaKm(parametro.GetPosicion(),misciudades[i].GetPosicion());
            auxpair.first=misciudades[i];
            auxpair.second=aux;
            cercanas.insertar(auxpair,i);
        }
        return cercanas;
}
set<float>ordenarDecreciente(VD<pair<Ciudad, float>>cercanas){
    set<float>orden_decreciente;
    for(int i=0;i<cercanas.size();i++){
        orden_decreciente.insert(cercanas[i].second);
    }
    return orden_decreciente;
}
int main(int argc, char *argv[]){
    VD<pair<Ciudad, float>>cercanas;
    Ciudades misciudades;
    set<float>orden_decreciente;
    set<float>::iterator it;

    if (argc!=5){
        Mensaje();
        return 0;
    }
    ifstream f(argv[1]);
    if (!f){
       cerr<<" No puedo abrir el fichero "<<argv[1]<<endl;
       return 0;
    }
    //Leer ciudades pasadar por un ficchero, se almacena en misciudades de tipo Ciudades
    f>>misciudades;
    cout<< "Numero de ciudades "<<misciudades.size()<< endl <<"Pulse intro para continuar...";
    cin.get();


    //Se obtiene la ciudad pasada por parámetro.
    Ciudad parametro=obtenerCiudad(misciudades,argv[2],argv[3]);
    if(parametro.GetNombre()==""){
        cout << "No se encuentra la ciudad pasada en mi lsita." << endl;
    }else{
        cercanas = obtenerDistanciaCiudad(misciudades,parametro);
        orden_decreciente=ordenarDecreciente(cercanas);
        //Se inicializa it al princio del contendor
        it=orden_decreciente.begin();
        //Se avanzan las posiciones pasadas por parámetro en la ejecución del programa.
        advance(it,atoi(argv[4]));
        //Eliminar todas las ciudades que no interesan.
        orden_decreciente.erase(it,orden_decreciente.end());

        //Muestra las ciudades de manera ordenada, por distancia.
        for(it=orden_decreciente.begin();it!=orden_decreciente.end();++it){
            for(int i=0;i<cercanas.size();i++){
                if(*it==cercanas[i].second){
                    cout << cercanas[i].first.GetNombre()<<" " <<cercanas[i].first.GetPais()  << " " << cercanas[i].second <<endl;
                }
            }
        }
    }

}
