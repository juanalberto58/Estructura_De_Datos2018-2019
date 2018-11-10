#include<VD.h>
#include<iostream>
using namespace std;

int main(){
    VD<int> vdint;
    VD<char> vdchar;
    vdint.insertar(25,0);
    vdint.insertar(28,1);
    vdchar.insertar('c',0);
    vdchar.insertar('d',1);
    vdchar.insertar('e',2);
    cout << vdint[0] << endl;
    cout << vdint[1] << endl;
    cout << vdint.size();
    cout << "Borrar";
    vdint.borrar(0);
    vdint.borrar(1);
    cout << vdint.size() << endl;
    cout << endl << vdint[0];
}
