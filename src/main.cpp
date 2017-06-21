#include<iostream>
using std::cout;
using std::endl;
#include<cstdlib>
#include<ctime>
#include<string>
using std::string;
#include "include/biblio.h"
#include "include/lista.h"
#include "include/pilha.h"
#include "include/fila.h"


using namespace edb1;

int main(){
    ///Teste Busca///
    int vetor[100];
    for(int i = 0; i < 50; i++){
        vetor[i] = i + 1;
    }
    cout<<"Resultado das buscas:"<<endl;
    cout<< buscaSeqIt(vetor, 50, 30) <<" ";
    cout<< buscaSeqRe(vetor, 50, 15)<<" ";
    cout<<buscaBiRe(vetor, 50, 10)<<" ";
    cout<<buscaBiIt(vetor, 50, 37)<<" ";
    cout<<buscaTerRe(vetor, 0, 50, 7)<<" ";
    cout<<buscaTerRe(vetor, 0, 50, 50)<<endl;

    ///Teste lista///
    Lista<int> lista;
    lista.Inserir(33);
    lista.Inserir(99);
    lista.Inserir(15);
    cout<<"Impressao dos itens da lista:"<<endl;
    lista.Exibe();

    ///Teste Pilha///
    Pilha<int> pilha(10);
    pilha.push(55);
    pilha.push(40);
    pilha.push(9);
    cout<<"Impressao dos itens da pilha:"<<endl;
    cout<<pilha.pop()<<endl;
    cout<<pilha.pop()<<endl;
    cout<<pilha.pop()<<endl;

    ///Teste Fila///
    Fila<float> fila1(5);
    fila1.push(55);
    fila1.push(40);
    fila1.push(9);
    cout<<"Impressao dos itens da fila:"<<endl;
    cout<<fila1.pop()<<endl;
    cout<<fila1.pop()<<endl;
    cout<<fila1.pop()<<endl;

    ///Teste Ordenação///
    srand(time(NULL));
    int *VET= new int[15];
    ///Insertion///
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    InsertionSort(VET, 15);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    cout<<endl;
    ///Selection
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<endl
        <<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    SelectionSort(VET, 15);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    cout<<endl;
    ///Bubble
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<endl
        <<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    BubbleSort(VET, 15);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    cout<<endl;

    //Quick
    cout<<endl;
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    QuickSort(VET, 0, 14);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }

    delete [] VET;
    return 0;
}