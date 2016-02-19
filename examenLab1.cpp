#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void eliminarMatriz(int**);
int** crearMatriz();
bool Ganador(int**);
void Impresion(int**);
bool Validacion(int**, int, int,int, int);


int main(int argc, char* argv []){
	int menu=1;
	int turno = 1;
	int primera = 0;
	while(menu==1){
		int** matriz = crearMatriz();
		cout << "Ingresar la po";
		while(Ganador(matriz) == false){
			int v1, v2;
			int p11, p12;
			int p21, p22;
			cout<< "Ingrese posicion de la fila: ";
			cin >> v1;
			cout << "Ingrese posicion de la columna: ";
			cin >> v2;
			if(primera == 0){
				p11 = v1;
				p12 = v2;
			}
			if(primera == 1){
				p21 = v1;
				p22 = v2;
			}
			while((Validacion(matriz, p11, p12, v1, v2)) || (Validacion(matriz, p21, p22, v1, v2))){

			}
			if(turno%2 == 0){
				turno = 1;
				
			}else{
				turno = 2;
			}
			primera++;
		}
		eliminarMatriz(matriz);
		cout<< "Ingresar opicon del menu"<<endl<<"1. Seguir jugando" << endl << "2. Salir";
		cin>> menu;
	}
}

bool Validacion(int** matriz, int p1, int p2, int v1, int v2){
	bool vali=false;
	if(matriz [v1][v2] == 0){
		for(int i=1; i<3; i++){
			if((v1 == p1-i)&&(v2 == p2-i)){
				vali = true;
			}
			if((v1 == p1+i)&&(v2 == p2+i)){
				vali = true;
			}
			if((v1 == p1-i)&&(v2 == p2+i)){
				vali = true;
			}
			if((v1 == p1+i)&&(v2 == p2-i)){
				vali = true;
			}
			if((v1 == p1+i)&&(v2 == p2)){
				vali = true;
			}
			if((v1 == p1-i)&&(v2 == p2)){
				vali = true;
			}
			if((v1 == p1)&&(v2 == p2+i)){
				vali = true;
			}
			if((v1 == p1)&&(v2 == p2-i)){
				vali = true;
			}

		}
	}
	return vali;
}

void Impresion(int** matriz){
	for(int i=0; i<7; i++){
		cout<< i << "\t";
	}
	cout << endl;
	for(int i=0; i<7; i++){
		cout << i<< "\t";
        for(int j=0; j<7; j++){
            cout<< matriz[i][j] << "\t";
        }
        cout<< endl;
    }
    return;
}

bool Ganador(int** matriz){
	bool ganador = true;
	for(int i=0; i<7; i++){
                for(int j=0; j<7; j++){
                        if(matriz[i][j] == 0){
                                ganador = false;
                        }
            }
    }
	return ganador;		
}

int** crearMatriz(){
	int** matriz = new int*[7];
	for(int i=0;i<7;i++){
		matriz[i]= new int[7];		
	}
	for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                matriz[i][j]= 0;
        }
    }
	return matriz;
}

void eliminarMatriz(int** matriz){
	for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                delete[] matriz[i];
        }
    }
	delete[] matriz;
	return;
} 

