#include<ciudades.h>
#include<Ciudad.h>
#include<iostream>
using namespace std;

Ciudades::Ciudades(){

}

VD<Ciudad> Ciudades::getDatos()const{
    return datos;
}
VD<int> Ciudades::getIndice(){
    return indice;
}

comprueba Ciudades::Esta_en_Datos(const Ciudad& ciu){
  int n = datos.size();
  int inicio = 0, fin = n;
  bool encontrado = false;
  comprueba c={inicio,false};
  if(datos.size()==0){
    //  cout << "entra la primera vez" << endl;
      c={inicio,false};
      return c;
  }
  while ((inicio < fin) && !encontrado) {

    int mitad =(inicio + fin)/2;
      //if(ciu.getNombre().compare(datos[mitad].getNombre())==0){
     if(ciu.GetNombre()==datos[mitad].GetNombre() && ciu.GetPais()==datos[mitad].GetPais()){
         encontrado=true;
         c={mitad,true};
         return c;
     }else {
         if(ciu.GetPais()==datos[mitad].GetPais()){
            if(ciu.GetNombre()>datos[mitad].GetNombre()){
                inicio=mitad+1;
                c ={inicio,false};
            }else{
                fin=mitad;
                c ={fin,false};
            }
        }else if (ciu.GetPais()>datos[mitad].GetPais()){
            inicio=mitad+1;
            c ={inicio,false};
        }else{
            fin=mitad;
            c ={fin,false};
        }
    }

  }

  return c;
}
int Ciudades::Esta_en_Indice(const Ciudad& ciu){
    int n = indice.size();
    int inicio = 0, fin = n;
    bool encontrado = false;
    int c=inicio;
    if(indice.size()==0){
        c=inicio;
        return c;
    }
    while (inicio < fin)  {
      int mitad =(inicio + fin)/2;
      if(ciu.GetNombre()>datos[indice[mitad]].GetNombre()){
          inicio=mitad+1;
          c =inicio;
      }else if(ciu.GetNombre()<datos[indice[mitad]].GetNombre()){
          fin=mitad;
          c =fin;
      }else{
          if(ciu.GetPais()>datos[indice[mitad]].GetPais()){
              inicio=mitad+1;
              c =inicio;
          }else{
              fin=mitad;
              c =fin;
          }

      }
    }

    return c;
}

void Ciudades::insertar(const Ciudad& nueva){

    comprueba c= Esta_en_Datos(nueva);
    int d= Esta_en_Indice(nueva);

    if(!c.esta){
        datos.insertar(nueva, c.pos);
    }
    for(int i=0;i<indice.size();i++){
        if(indice[i]>=c.pos){
            indice[i]=indice[i] + 1;
        }
    }
    indice.insertar(c.pos,d);
}
int Ciudades::getPosicionCiudad(const Ciudad&ciu){
    for(int i=0;i<datos.size();i++){
        if(ciu.GetNombre()==datos[i].GetNombre()){
            return i;
        }
    }
    return -1;
}
void Ciudades::BorrarCiudad(const Ciudad &nombre){
    int i=getPosicionCiudad(nombre);
    if(i==-1){
        cout<<"No existe la ciudad";
    }else{
        datos.borrar(i);
    }

}
Ciudades& Ciudades::operator=(const Ciudades&original){
    datos=original.datos;
    indice=original.indice;
}
Ciudades Ciudades::GetAllCiudadesPais(string pais){
    Ciudades aux;
    int cont=0;
    for(int i=0;i<datos.size();i++){
        if(datos[i].GetPais()==pais){

            aux.insertar(datos[i]);
            cont++;
        }
    }
    return aux;
}


const Ciudad& Ciudades::operator[](int i)const{
    return datos[i];
}
Ciudad& Ciudades::operator[](int i){
    return datos[i];
}

VD<string> Ciudades::getCiudades(string pais){
    VD<string>aux;
    int cont=0;
    for(int i=0;i<datos.size();i++){
        if(datos[i].GetPais()==pais){
            cout << datos[i].GetNombre();
            aux.insertar(datos[i].GetNombre(),cont);
            cont++;
        }

    }
    return aux;
}

Ciudades Ciudades::GetCiudad_Ciudad_PorNombre(string name){
    Ciudades aux;
    for(int i=0;i<datos.size();i++){
        if(datos[i].GetNombre()==name){
            aux.insertar(datos[i]);
        }
    }
    return aux;
}


Ciudad Ciudades::GetCiudad_Ciudad(int pos){
    return datos[indice[pos]];
}

istream & operator >> (istream &f,  Ciudades &pos){
    Ciudad x;
    string c;
    getline(f,c);
    while(f >> x){
        //cout << pos.datos.size() << endl;
        pos.insertar(x);
    }
    return f;
}


ostream & operator <<(ostream &os, const Ciudades &pos){
    for(int i=0;i<pos.size();i++){
            os << pos[i]<<endl;
    }

}

int Ciudades::size()const{
    return datos.size();
}
