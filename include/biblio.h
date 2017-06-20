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
    extern "C++" template<typename T>
    bool buscaTerRe(T V[], int ini, int fim, int x){
        int esq= ini + (fim - ini) * 1 / 3;
        int dir= ini + (fim - ini) * 2 / 3;
        if(fim<ini){
            return false;
        }
        if(V[esq]==x){
            return true;
        }
        if(V[dir]==x){
            return true;
        }
        if(V[esq]>x){
            return buscaTerRe(V, ini, esq-1, x);
        }
        if(V[esq]<x && V[dir]>x){
            return buscaTerRe(V, esq+1, dir-1, x);
        }
        if(V[dir]<x){
            return buscaTerRe(V, dir+1, fim, x);
        }
        return false;
    }
    extern "C++" template<typename T>
    bool buscaTerIt(T V[], int ini, int fim, int x){
        int mid1, mid2;
        int esq=ini;
        int dir= fim;
        do{
            mid1= ((dir-esq)/3) + esq;
            mid2= (( (dir-esq) /3) *2) + esq;
            if(V[mid1]==x){
                return true;
            }
            if(V[mid2]==x){
                return true;
            }
            if(V[mid1]> x){
                dir= mid1 -1;
            }
            if(V[mid1]< x && V[mid2]>x){
                dir=mid2 -1;
                esq=mid1 +1;
            }
            else if(V[mid2] <x){
                esq=mid2 +1;
            }

        }while(esq<=dir);
        return false;
    }

}


#endif