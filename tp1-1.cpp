#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo
{
    int dato;
    pnodo sig;
};

void iniciar_lista(pnodo &lista);
void crear_nodo(pnodo &nuevo);

void menu_agregar_nodo(pnodo &lista);
pnodo menu_extraer_nodo(pnodo &lista);

void agregar_inicio_nodo(pnodo &lista, pnodo nuevo);
void agregar_final_nodo(pnodo &lista, pnodo nuevo);
void agregar_ordenado_nodo(pnodo &lista, pnodo nuevo);

pnodo extraer_nodo_inicio(pnodo &lista);
pnodo extraer_nodo_final(pnodo &lista);
pnodo extraer_nodo_especifico(pnodo &lista, int buscado);

void mostrar_lista(pnodo lista);

bool buscar_nodo(pnodo lista,int buscado);

int main()
{
  int opcion, buscado;
  pnodo lista, extraido;
  iniciar_lista(lista);
  do
  {
    cout<<"Menu"<<endl;
    cout<<"1-Agregar nodo a la lista"<<endl;
    cout<<"2- Extraer nodo de la lista"<<endl;
    cout<<"3- Buscar nodo de la lista"<<endl;
    cout<<"4- Mostrar lista"<<endl;
    cout<<"5- Finalizar Programa"<<endl;
    cout<<endl;
    cout<<"Seleccione Opcion: ";
    cin>>opcion;
    switch (opcion)
    {
    case 1:
       
		menu_agregar_nodo(lista);
        break;
    case 2:
		extraido=menu_extraer_nodo(lista);
		delete(extraido);
        break;
    case 3:
			cout<<"Ingrese Valor que desea buscar en la lista: ";
			cin>>buscado;
			if(buscar_nodo(lista,buscado))
				cout<<"Valor encontrado"<<endl;
			else
				cout<<"Valor inexistente"<<endl;
        break;
    case 4:
				mostrar_lista(lista);
        break;
    case 5:
        cout<<"Fin del Programa"<<endl;
		break;
    default:
        cout<<"Opcion Incorrecta"<<endl;
        break;
    }
    
  } while (opcion!=5);
  

    return 0;
}

void iniciar_lista(pnodo &lista){
	lista=NULL;
}
	
void crear_nodo(pnodo &nuevo){
	nuevo = new tnodo;
	if(nuevo!=NULL){
		cout<<"Ingrese Valor: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}else
	   cout<<"No hay espacio de memoria"<<endl;
}

	
void agregar_inicio_nodo(pnodo &lista, pnodo nuevo){
	if(lista==NULL)
		lista=nuevo;
	else{
		nuevo->sig=lista;
		lista=nuevo;
	}
}
	
void agregar_final_nodo(pnodo &lista,pnodo nuevo){
	pnodo i;
	if(lista==NULL)
		lista=nuevo;
	else{
		for (i=lista;i->sig!=NULL;i=i->sig);
		i->sig=nuevo;
	}
}
	
void agregar_ordenado_nodo(pnodo &lista,pnodo nuevo){
	pnodo i;
	if(lista==NULL)
		lista=nuevo;
	else{
		if(lista->dato > nuevo->dato){
			nuevo->sig=lista;
			lista=nuevo;
		}else{
			for (i=lista;i!=NULL && (nuevo->dato > (i->sig)->dato);i=i->sig);
			nuevo->sig=i->sig;
			i->sig=nuevo;
		}
	}
}
	
void menu_agregar_nodo(pnodo &lista){
	int opcion;
	pnodo nuevo;
	do{
	cout<<"Menu de Agregar nodo"<<endl;
	cout<<"1- Agregar al inicio"<<endl;
	cout<<"2- Agregar al final"<<endl;
	cout<<"3- Agregar Ordenado"<<endl;
	cout<<"4- Salir"<<endl;
	cout<<"Elija Opcion: ";
	cin>>opcion;
	switch(opcion){
	case 1:
		crear_nodo(nuevo);
		agregar_inicio_nodo(lista,nuevo);
		break;
	case 2:
		crear_nodo(nuevo);
		agregar_final_nodo(lista,nuevo);
		break;
	case 3:
		crear_nodo(nuevo);
		agregar_ordenado_nodo(lista,nuevo);
		break;
	case 4:
		cout<<"Fin de menu de operacion de agregar"<<endl;
	default:
		cout<<"Opcion Incorrecta"<<endl;
		break;
		
	}
	}while(opcion!=4);
}
	
	
	
	

pnodo extraer_nodo_inicio(pnodo &lista){
	pnodo borrado;
	if(lista==NULL)
		borrado=NULL;
	else{
		borrado=lista;
		lista=lista->sig;
		borrado->sig=NULL;
	}
	return borrado;
}
	
pnodo extraer_nodo_final(pnodo &lista){
	pnodo borrado,i;
	if(lista==NULL)
		borrado=NULL;
	else{
		if(lista->sig==NULL){
			borrado=lista;
			lista=NULL;
		}else{
			for(i=lista;(i->sig)->sig!=NULL;i=i->sig); 
				borrado=i->sig;
				i->sig=NULL;
			
		}
		
	}
	return borrado;
}
	
pnodo extraer_nodo_especifico(pnodo &lista,int buscado){
	pnodo borrado,i;
	if(lista==NULL)
		borrado=NULL;
	else{
		if(lista->dato==buscado){
			borrado=lista;
			lista=lista->sig;
			borrado->sig=NULL;
		} else {
			for(i=lista;i->sig!=NULL && ((i->sig)->dato!=buscado) ;i=i->sig);
			if(i->sig!=NULL){
				borrado=i->sig;
				i->sig=borrado->sig;
				borrado->sig=NULL;
			}else{
				borrado=NULL;
			}
		}
	}
	return borrado;
}
	
pnodo menu_extraer_nodo(pnodo &lista){
	pnodo extraido;
	int opcion,buscado;
	do{
		cout<<"Menu de extraer nodo"<<endl;
		cout<<"1- Extraer nodo de inicio"<<endl;
		cout<<"2- Extraer nodo de final"<<endl;
		cout<<"3- Extraer nodo especificado"<<endl;
		cout<<"4- Salir"<<endl;
		cout<<"Elija Opcion: ";
		cin>>opcion;
		switch(opcion){
		case 1:
		   extraido = extraer_nodo_inicio(lista);
			break;
		case 2:
			extraido = extraer_nodo_final(lista);
			break;
		case 3:
			cout<<"Ingrese valor que desea encontrar: ";
			cin>>buscado;
			extraido = extraer_nodo_especifico(lista,buscado);
			break;
		case 4:
			cout<<"Fin del operaciones en menu eliminar"<<endl;
		default:
			cout<<"Opcion Incorrecta"<<endl;
			break;
			
		}
	}while(opcion!=4);
	return extraido;
}
	
bool buscar_nodo(pnodo lista, int buscado){
	pnodo i;
	bool encontrado=false;
	if(lista!=NULL){
		for(i=lista;i!=NULL && encontrado==false;i=i->sig){
			if(i->dato==buscado)
				encontrado=true;
		}
	}
	
	return encontrado;
}

void mostrar_lista(pnodo lista){
	pnodo i;
	if(lista!=NULL){
		cout<<"Lista de nodos"<<endl;
		for(i=lista;i!=NULL;i=i->sig){
			cout<<i->dato<<" ";
		}
	}else{
		cout<<"Lista vacia"<<endl;
	}
	cout<<endl;
}
