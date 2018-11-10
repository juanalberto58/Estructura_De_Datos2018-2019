#include "ciudades.h"
#include <fstream>
#include <cmath>
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
  return;
}




int main(int argc, char *argv[]){

  if (argc!=2){
    Mensaje();
    return 0;
  }

  ifstream f(argv[1]);
  if (!f){
     cerr<<" No puedo abrir el fichero "<<argv[1]<<endl;
     return 0;
  }

  // _______________________________________________________________

  //Seccion 1: Comprobar declaracion, lectura y diferentes formas
  // de impresion de las ciudades. A través de la lectura (operator >>) se debe comprobar
  // que funciona bien el proceso de Insertar
  Ciudades misciudades;

  f>>misciudades;
  cout<< "Numero de ciudades "<<misciudades.size();
  cin.get();

  cout<<"Ciudades Ordenadas por pais y ciudad ..."<<endl;

  cout<<misciudades;
  cout<<"Pulsa una tecla para continuar...."<<endl;
  cin.get();

  cout<< "Listado de las ciudades en orden alfabético..."<<endl;
  for (unsigned int i=0;i<misciudades.size();i++){
     Ciudad a = misciudades.GetCiudad_Ciudad(i);
    cout<<"pos= "<<i<< " ciudad " <<a<<endl;

  }


  //_______________________________________________________________

  //Sección 2: Obtener ciudades que tienen un nombre (puede haber mas de una).
  //Se debe comprobar que los métodos para obtener información funcionan bien.
  //Medir la distancia en kms de dos ciudades
  cout<<"Vamos a obtener distancia en kms entre dos ciudades "<<endl;

  cout<<" Dime dos ciudades:"<<endl;
  string name1, name2;
  cin>>name1>>name2;
  cout<<"________________________DISTANCIAS________________"<<endl;
  Ciudades cds1=misciudades.GetCiudad_Ciudad_PorNombre(name1);
  Ciudades cds2=misciudades.GetCiudad_Ciudad_PorNombre(name2);
  for (int i=0;i<cds1.size();i++)
    for (int j=0;j<cds2.size();j++)
      cout<<"La distancia entre "<<cds1[i].GetCiudad()<<","<<cds1[i].GetPais()<<" -y- " <<cds2[j].GetCiudad()<<","<<cds2[j].GetPais()<<" es:"<<DistanciaKm(cds1[i].GetPosicion(),cds2[j].GetPosicion())<<" Kms"<<endl;


  //_______________________________________________________________

  //Sección 3: Obtener todas las ciudades de un pais
  cout<<endl<<"Dime el nombre de un pais "<<endl;
  string name_pais;
  cin >>name_pais;
  cout<<"________________CIUDADES EN UN PAIS______________"<<endl;
  cout<<"Las ciudades del pais  "<<name_pais<<" son:"<<endl;
  Ciudades cds_pais=misciudades.GetAllCiudadesPais(name_pais);
  for (int i=0;i<cds_pais.size();i++)
    cout<<cds_pais.GetCiudad_Ciudad(i)<<endl;
  cout<<endl<<"La población total del pais es "<<ObtenerPoblacion(cds_pais)<<endl;



  //_______________________________________________________________

  //Sección 4: Comprobar que el proceso de borrado funciona bien
  //Borramos las ciudades encontradas
  for (int i=0;i<cds_pais.size();i++)
      misciudades.BorrarCiudad(cds_pais[i]);

  cout<<endl<<"Despues de borrar el numero de ciudades es:"<<misciudades.size();

}
