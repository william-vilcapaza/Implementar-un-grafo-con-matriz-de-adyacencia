#include <iostream>
#include <cstdlib>


using namespace std;


struct nodo
{
    int dato;
    struct nodo *liga_vertice;
    struct nodo *liga_arista;
};


typedef struct nodo *registro;
registro sig_ver, ant_ver, cab_ver, sig_ari, ant_ari, dir1, dir2;

//registro de nuevo vertice

registro nuevo_vertice(int dat)
{
    registro reg_ver=new(struct nodo);
    reg_ver->dato=dat;
    reg_ver->liga_vertice=NULL;
    reg_ver->liga_arista=NULL;
    return reg_ver;
}

//funcion insertar vertice
void insertarVertice(int dat)
{
    int sw=0;
    ant_ver=cab_ver;
    sig_ver=cab_ver;

    while(sig_ver!=NULL && sw==0)
    {
        if(sig_ver->dato==dat)
        {
            sw=1;
        }
        else
        {
            ant_ver=sig_ver;
            sig_ver=sig_ver->liga_vertice;
        }
    }

    if(sw==1)
    {
        cout<<"\n Vertice ya existente no se adiciona\n";
    }
    else
    {
        if(cab_ver==NULL)
        {
            cab_ver=nuevo_vertice(dat);
        }
        else
        {
            ant_ver->liga_vertice=nuevo_vertice(dat);
        }
        cout<<"Vertice adicionado\n";
    }
}




//Registro recorrer vertice

registro recorrer_vertice(int dat)
{
    registro dir;
    dir=NULL;
    sig_ver=cab_ver;

    while(sig_ver!=NULL)
    {
        if(sig_ver->dato==dat)
        {
            dir=sig_ver;
        }
        sig_ver=sig_ver->liga_vertice;
    }
    return dir;
}


//Registro nueva arista
registro nueva_arista(int pes)
{
    registro reg_ari=new(struct nodo);
    reg_ari->dato=pes;
    reg_ari->liga_arista=NULL;
    reg_ari->liga_vertice=dir2;
    return reg_ari;
}


//Funcion insertar arista
void insertarArista(int dato_destino)
{
    int pes, sw2=0;
    ant_ari=dir1;
    sig_ari=dir1;

    while(sig_ari!=NULL && sw2==0)
    {
        if(sig_ari->dato==dato_destino)
        {
            sw2=1;
        }
        else
        {
            ant_ari=sig_ari;
            sig_ari=sig_ari->liga_arista;
        }
    }

    if(sw2==1)
    {
        cout<<"Arista ya existente no se adiciona\n\n";
    }
    else
    {
        cout<<"Digite el peso de la arista: ";
        cin>>pes;
        ant_ari->liga_arista=nueva_arista(pes);
    }
}


//Funcion del grafo
void verLista()
{
    cout<<"\n\nVer lista de vertices y sus aristas";
    sig_ver=cab_ver;

    while(sig_ver!=NULL)
    {
        cout<<"\n El nodo";
        cout<<(sig_ver->dato);
        cout<<"Tiene aristas a los siguientes vertices";
        sig_ari=sig_ver->liga_arista;
        while(sig_ari!=NULL)
        {
            cout<<" ";
            dir1=sig_ari->liga_vertice;
            cout<<dir1->dato;
            sig_ari=sig_ari->liga_arista;
        }
        sig_ver=sig_ver->liga_vertice;
    }
}



//Funcion principal
int main()
{
    cab_ver=NULL;
    int dato_origen, dato_destino;
    int sw, opcion;

    do
    {
        cout<<"\n\tMenu\n"<<endl;
        cout<<"1.- Crear vertices"<<endl;
        cout<<"2.- Creacion de aristas"<<endl;
        cout<<"3.- Mostrar grafo"<<endl;
        cout<<"4.- Salir"<<endl;
        cout<<"\nOpcion"<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1: cout<<"Digite un numero para el vertice: ";
                    cin>>dato_origen;
                    insertarVertice(dato_origen);
                    system("pause");
                    break;
            case 2: cout<<"Digite el nodo de origen: ";
                    cin>>dato_origen;
                    cout<<"Digite el nodo destino: ";
                    cin>>dato_destino;
                    dir1=recorrer_vertice(dato_origen);
                    dir2=recorrer_vertice(dato_destino);
                    if(dir1==NULL || dir2==NULL)
                    {
                        cout<<"\n\tNodo origen o nodo destino no existen";
                    }
                    else
                    {
                        insertarArista(dato_destino);
                    }
                    system("pause");
                    break;
            case 3: verLista();
                    cout<<endl<<endl;
                    system("pause");
                    break;
        }
        system("cls");
    }while(opcion!=4);

    return 0;
}
