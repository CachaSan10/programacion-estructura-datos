#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	char dato;
	pnodo sig;
};

typedef struct tlista{
	pnodo lista;
	int contadorLetra;
	int contadorDigitos;
	int contadorSimbolos;
};

void  iniciar_lista(tlista &listaNodos);
void crear_nodo(pnodo &nuevo);
void agregar_inicio_nodo(tlista &listaNodos, pnodo nuevo);
void quitar_final_nodo(tlista &listaNodos);
void mostrar_lista(tlista listaNodos);

void aumentar_contador_lista(tlista &listaNodos,char valor);
void disminuir_contador_lista(tlista &listaNodos, char valor);

bool esLetra(char valor);
bool esDigito(char valor);

int main(int argc, char *argv[]) {
	tlista lista;
	pnodo nuevo;
	int opcion;
	iniciar_lista(lista);
	do {
		cout<<"Menu"<<endl;
		cout<<"1- Agregar nodo"<<endl;
		cout<<"2- Eliminar Nodo"<<endl;
		cout<<"3- Mostrar lista"<<endl;
		cout<<"4- Salir"<<endl;
		cout<<"Seleccionar opcion: ";
		cin>>opcion;
		switch(opcion){
		case 1:
			crear_nodo(nuevo);
			agregar_inicio_nodo(lista,nuevo);
			break;
		case 2:
			quitar_final_nodo(lista);
			break;
		case 3:
			mostrar_lista(lista);
			break;
		case 4:
			cout<<"Fin del Programa"<<endl;
			break;
		default:
			cout<<"Opcion Incorrecta"<<endl;
			break;
		}
	} while (opcion!=4);
	return 0;
}

void iniciar_lista(tlista &listaNodos){
	listaNodos.lista=NULL;
	listaNodos.contadorLetra=0;
	listaNodos.contadorDigitos=0;
	listaNodos.contadorSimbolos=0;
}
	
void crear_nodo(pnodo &nuevo){
		nuevo = new tnodo;
		if(nuevo!=NULL){
			cout<<"Ingrese dato: ";
			cin>> nuevo->dato;
			nuevo->sig=NULL;
		}else
		   cout<<"Memoria Insuficiente"<<endl;
}
		
void agregar_inicio_nodo(tlista &listaNodos,pnodo nuevo){
	if(listaNodos.lista==NULL)
		listaNodos.lista=nuevo;
	else{
		nuevo->sig=listaNodos.lista;
		listaNodos.lista=nuevo;
	}
	
	aumentar_contador_lista(listaNodos,listaNodos.lista->dato);
		
		
}
	
void aumentar_contador_lista(tlista &listaNodos,char valor){
	if(esLetra(valor))
		listaNodos.contadorLetra++;
	else{
		if(esDigito(valor))
			listaNodos.contadorDigitos++;
		else
			listaNodos.contadorSimbolos++;
	}
		
	
}

bool esLetra(char valor){
	bool letra=false;
	if((valor>='a' && valor<='z') || (valor>='A' && valor<='Z'))
		letra=true;
	
	return letra;
}

bool esDigito(char valor){
	bool digito = false;
	if(valor>='0' && valor<='9')
		digito=true;
	
	return digito;
}
	
void quitar_final_nodo(tlista &listaNodos){
	pnodo i, borrado;
	if(listaNodos.lista==NULL)
		borrado=NULL;
	else{
		if(listaNodos.lista->sig==NULL){
			borrado=listaNodos.lista;
			listaNodos.lista=NULL;
		}else{
			for(i=listaNodos.lista;(i->sig)->sig!=NULL;i=i->sig);
			borrado=i->sig;
			i->sig=NULL;
		}
	}
	
	if(borrado!=NULL)
		disminuir_contador_lista(listaNodos, borrado->dato);
	
	delete(borrado);
	
}

void disminuir_contador_lista(tlista &listaNodos,char valor){
	if(esLetra(valor))
		listaNodos.contadorLetra--;
	else
		if(esDigito(valor))
			listaNodos.contadorDigitos--;
		else
			listaNodos.contadorSimbolos--;
}

void mostrar_lista(tlista listaNodos){
	pnodo i;
	if(listaNodos.lista!=NULL){
		for(i=listaNodos.lista;i!=NULL;i=i->sig){
			cout<<"Nodo: "<<i->dato<<" ";
		}
	cout<<"Cantidad de letras: "<<listaNodos.contadorLetra<<endl;
	cout<<"Cantidad de digitos: "<<listaNodos.contadorDigitos<<endl;
	cout<<"Cantidad de simbolos: "<<listaNodos.contadorSimbolos<<endl;
	}else
	   cout<<"Lista Vacia"<<endl;
}
