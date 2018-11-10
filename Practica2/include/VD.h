#ifndef _VD_H_
#define _VD_H_
template <class T>
    class VD{
        private:
            T *datos;
            int n;
            void resize(int n_tam);
            int reservados;
        public:
            VD(int tam=10);
            VD(const VD<T>&original);
            VD<T>&operator=(const VD<T>&original);
            ~VD();
            int size()const;
            T&operator[](int i);
            const T&operator[](int i)const;
            void insertar(const T&dato, int pos);
            void borrar(int pos);
};
#include <VD.cpp>
#endif
