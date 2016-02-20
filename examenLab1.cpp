#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void eliminarMatriz(int**);
int** crearMatriz();
bool Ganador(int**);
void Impresion(int**);
bool Validacion(int**, int, int,int, int);
int** Validacion2(int**, int, int, int);

int main(int argc, char* argv []){
	int menu=1;
	int turno = 1;
	int primera = 0;
	while(menu==1){
		int** matriz = crearMatriz();
		cout << "Ingresar la po";
		int v1=1, v2=1;
		int p11=5, p12=5;
		int p21=5, p22=5;
		while((Ganador(matriz) == false) || ((Validacion(matriz, p11, p12, v1, v2)) || (Validacion(matriz, p21, p22, v1, v2)) )  ){
			Impresion(matriz);
			cout<< "Jugador "<< turno;
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
			while(!(Validacion(matriz, p11, p12, v1, v2)) || (Validacion(matriz, p21, p22, v1, v2))){
				cout << "Error en las posiciones ingresadas";
				cout<< "Ingrese posicion de la fila: ";
				cin >> v1;
				cout << "Ingrese posicion de la columna: ";
				cin >> v2;
			}
			matriz[v1][v2] = turno;
			matriz = Validacion2 (matriz, v1, v2, turno);
			if(turno%2 == 0){
				turno = 1;
				p11 = v1;
				p12 = v2;
			}else{
				turno = 2;
				p21 = v1;
				p22 = v2;
			}
			primera++;
		}
		eliminarMatriz(matriz);
		cout<< "Ingresar opicon del menu"<<endl<<"1. Seguir jugando" << endl << "2. Salir";
		cin>> menu;
	}
}

bool Validacion(int** matriz, int p1, int p2, int v1, int v2){// p = posicion
	bool vali=false;// v = posicion nueva
	if(matriz [v1][v2] == 0){
		for(int i=1; i<3; i++){
			if(!(i==1) && ((p1 == 0) || (p2 == 0)) ){
				if(!(i==2) && ((p1 == 1) || (p2 == 1))) {
					if((v1 == p1-i)&&(v2 == p2-i)){
						vali = true;
					}
				}
			}

			if(!(i==1) && ((p1 == 6) || (p2 == 6) )){
				if(!(i==2) && ((p1 == 1) || (p2 == 1))) {
					if((v1 == p1+i)&&(v2 == p2+i)){
						vali = true;
					}
				}
			}

			if(!(i==1) && ((p1 == 0) || (p2 == 6) )) {
				if(!(i==2) && ( (p1 == 1) || (p2 == 5) )) {
					if((v1 == p1-i)&&(v2 == p2+i)){
						vali = true;
					}
				}
			}

			if(!(i==1) && ((p1 == 6) || (p2 == 0) )){
				if(!(i==2) && ((p1 == 5) || (p2 == 1))) {
					if((v1 == p1+i)&&(v2 == p2-i)){
						vali = true;
					}
				}
			}


			if(!(i==1) && ((p1 == 6) )){
				if(!(i==2) && ((p1 == 5))){
					if((v1 == p1+i)&&(v2 == p2)){
						vali = true;
					}
				}
			}

			if(!(i==1) && ((p1 == 0) )){
				if(!(i==2) && ( (p1 == 1))) {
					if((v1 == p1-i)&&(v2 == p2)){
						vali = true;
					}
				}
			}	

			if(!(i==1) && ( (p2 == 6) )){
				if(!(i==2) && ((p2 == 5))) {
					if((v1 == p1)&&(v2 == p2+i)) {
						vali = true;
					}
				}
			}

			if(!(i==1) && ((p2 == 0) )) {
				if(!(i==2) && ((p2 == 1))) {
					if((v1 == p1)&&(v2 == p2-i)) {
						vali = true;
					}
				}
			}
		}
		if((p1 == v1) && (p2==v2)){
			vali = true;
		}
	}
	if(!((v1 > 0) && (v1 < 7))){
		vali = false;
	}
	return vali;
}



int** Validacion2(int**matriz, int p1, int p2, int turno){
	int i=1;	// contrario es el numero del equipo contrario
	int contrario;
	if(contrario%2 == 0){
		turno = 1;
	}else{
		turno = 2;
	}
	if(matriz[p1-i][p2-i] == contrario){
		matriz[p1-i][p2-i] = turno;
	}
	if(matriz[p1+i][p2+i] == contrario){
		matriz[p1+i][p2+i] = turno;
	}
	if(matriz[p1-i][p2+i] == contrario){
		matriz[p1-i][p2+i] = turno;
	}
	if(matriz[p1+i][p2-i] == contrario){
		matriz[p1+i][p2-i] = turno;
	}
	if(matriz[p1+i][p2] == contrario){
		matriz[p1+i][p2] = turno;
	}
	if(matriz[p1-i][p2] == contrario){
		matriz[p1-i][p2] = turno;
	}
	if(matriz[p1][p2+i] == contrario){
		matriz[p1][p2+i] = turno;
	}
	if(matriz[p1][p2-i] == contrario){
		matriz[p1][p2-i] = turno;
	}
	return matriz;
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

