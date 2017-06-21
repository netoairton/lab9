#ifndef FILA_H
#define FILA_H

#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;
namespace edb1{
    template <typename T>
    class Fila{
    private:
    int maximo;
    int tamanho;
    T *fila;

    public:
    Fila(int tamanho);
    int push(T el);
    T pop();
};

template <typename T>
Fila<T>::Fila(int t){
    fila= new T[t];
    maximo=t;
    tamanho=0;
}

template <typename T>
int Fila<T>::push(T el){
    if(tamanho==maximo){
        return tamanho;
    }
    fila[tamanho]=el;
    return ++tamanho;
}

template <typename T>
T Fila<T>::pop(){
    if(tamanho==0){
        return tamanho;
    }
    --tamanho;
    T retirado= fila[0];
    for(int ii=0; ii<tamanho; ii++){
        fila[ii]=fila[ii+1];
    }
    return retirado;
}
}

#endif