#include<Posicion.h>
#include<Ciudad.h>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    Posicion x;
    Posicion y(8.3,9.7);
    Ciudad ciudad("jj","españa",y,200);

    cout << ciudad <<endl <<endl;
    cout << "Valor asignada usando el la sobrecarga del operador << "<<endl << y << endl<<endl;
    cout << "Introduce dos valores separados por ; para probar la sobrecarga del operado >>  " << endl ;
    cin >> x ;


    cout << x;
    return 0;
}
