#include<iostream>
using std::cout;
using std::endl;
#include "include/biblio.h"
#include "include/lista.h"
#include "include/pilha.h"


using namespace edb1;

int main(){
    ///Teste Busca///
    int vetor[100];
    for(int i = 0; i < 50; i++){
        vetor[i] = i + 1;
    }
    cout<< buscaSeqIt(vetor, 50, 30) << endl;
    cout<< buscaSeqRe(vetor, 50, 15)<<endl;
    cout<<buscaBiRe(vetor, 50, 10)<<endl;
    cout<<buscaBiIt(vetor, 50, 37)<<endl;
    cout<<buscaTerRe(vetor, 0, 50, 7)<<endl;
    cout<<buscaTerRe(vetor, 0, 50, 50)<<endl;

    ///Teste lista///
    Lista<int> lista;
    lista.Inserir(33);
    lista.Inserir(99);
    lista.Inserir(15);
    lista.Exibe();

    ///Teste Pilha///
    Pilha<int> pilha(30);
    pilha.push(55);
    pilha.push(40);
    pilha.push(9);

    cout<<pilha.pop()<<endl;
    cout<<pilha.pop()<<endl;

    return 0;
}