#ifndef BUSCA_H
#define BUSCA_H

namespace edb1{
    extern "C++" template<typename T>
    bool buscaSeqIt(T V[], int size, T elemento){
        for(int i=0; i<size; i++){
            if(V[i]==elemento){
                cout<<"posicao do elemento= "<<i+1<<endl;
                return 1;
            }
        }
        cout<<"elemento nao encontrado!"<<endl;
        return 0;
    }

    extern "C++" template<typename T>
    bool buscaSeqRe(T V[], int size, T elemento){
        if(size<=0){
            return 0;
        }
        if(V[0]==elemento){
            return 1;
        }
        return buscaSeqRe(V+1, size-1, elemento);
    }

    extern "C++" template<typename T>
    bool buscaBiRe(T V[], int size, T elemento){
        if(size<=0){
            return 0;
        }
        int mid=size/2;
        if(V[mid]==elemento){
            return 1;
        }
        if(V[mid]>elemento){
            return buscaBiRe(V, mid, elemento);
        }
        else{
            return buscaBiRe(V+mid+1, size-mid, elemento);

        }
    }

    extern "C++" template<typename T>
    bool buscaBiIt(T V[], int size, T elemento){
        int mid;
        while(size>=0){
            mid=size/2;
            if(V[mid]==elemento){
                return 1;
            }
            if(V[mid]>elemento){
                size=mid;
            }
            else{
                V=V+mid+1;
                size=size-mid-1;
            }
        }
        return 0;
    }

}


#endif