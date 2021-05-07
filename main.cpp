#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <string>
#include <stdlib.h>

using std:: cout;
using std:: cin;
using std:: endl;

/*07/05/2021*/

void ejercicio2(char**& , int, int, int);
void inicializar_matriz(char**& , int, int);
void instanciar_matriz(char**& , int, int);
void liberar_matriz(char**& , int);
void imprimir(char**& , int , int );


//Metodo de menu
int menu(){
	int p = 0; 
	while (p != 4){
	cout<<"+--------[MENU]------+"<<endl;
	cout<<"Ejercicio---------[1]"<<endl;
	cout<<"Ejercicio---------[2]"<<endl;
	cout<<"Ejercicio---------[3]"<<endl;
	cout<<"Salir-------------[4]"<<endl;	
	cout<<"+--------------------+"<<endl;
	cin>> p; 
		if (p == 4){
			cout << "Saliendo... " <<endl; 
		}else if (p > 0 && p < 4){
			break; 
		}
	}
	return p; 
}


int main(int argc, char** argv) {
	int p = menu();

	while(p != 4){
		switch(p){
			case 1:{	
			cout<<"Ejercicio 1"<<endl;
			
			
			
			
				break;
			}//fin case 1
				
			case 2:{
				
			cout<<"Ejercicio 2"<<endl;
			int filas=0;
			int columnas=0;
			int obstaculos=0;
			
			while (filas<1){
				cout <<"Ingrese numero de filas: ";
				cin >> filas;
			}//fin while
			
			while (columnas<1){
				cout <<"Ingrese numero de columnas: ";
				cin >> columnas;
			}//fin while
			
			//while (obstaculos<=filas*columnas){
				cout <<"Ingrese numero de obstaculos: ";
				cin >> obstaculos;
		//	}//fin while
			
			char** matriz = 0;
    		inicializar_matriz(matriz, filas, columnas);
   			cout << "Original" << endl;
    		imprimir(matriz, filas, columnas);
    		ejercicio2(matriz, obstaculos, filas, columnas);
  			cout << "Obstaculos" << endl;
  			imprimir(matriz, filas, columnas);

				break;
			}//fin case 2
			
			case 3:{
				
			
				break;
			}//fin case 3
			
			case 4:{
				cout<< "Saliendo..."<<endl;
				break;
			}//fin case 4
			
			
			default: {
				cout<< "Entrada No valida ingrese numero del 1-4"<<endl;
				break;
			}
		}
		p = menu();
				
		
	}//fin del while
	
	return 0;
}


void ejercicio2(char**& matriz, int obstaculos, int filas, int columnas) {
    while (obstaculos > 0) {
        srand(time(NULL));
        int fila_random = 0 + rand() % filas, columna_random = 0 + rand() % columnas;
        while (matriz[fila_random][columna_random] != '-') {
            fila_random = 0 + rand() % filas, columna_random = 0 + rand() % columnas;
        }//fin while*/
        matriz[fila_random][columna_random] = '#';
        obstaculos--;
    }//fin while
}//fin función

void inicializar_matriz(char**& matriz, int filas, int columnas) {
    if (matriz != NULL) {
        // liberar_matriz(matriz, filas);
    } else {
        instanciar_matriz(matriz, filas, columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz[i][j] = '-';
            }//fin for
        }//fin for
    }//fin else
}

void instanciar_matriz(char**& matriz, int filas, int columnas) {
    matriz = new char*[filas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i] = new char[columnas];
        }//fin for
    }//fin for
}

void liberar_matriz(char**& matriz, int filas) {
    if (matriz != NULL) {
        for (int i = 0; i < filas; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
        matriz = NULL;
    }//fin if
}//fin método

void imprimir(char**& matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }//fin for
        cout << endl;
    }//fin for
    cout << endl;
}//fin metodo