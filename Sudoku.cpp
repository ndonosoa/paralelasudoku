#include <iostream>

using namespace std;

struct Celda{
	int CoordenadaX;
	int CoordenadaY;
	int Valor;
	int Bloque;
	int BloqueDisp[9];
	int Disp[9];
};

void MostrarMatriz(Celda Matriz[][9]){
	cout<<"Matriz de Valores"<<endl;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<Matriz[i][j].Valor<<" ";
		}
		cout<<endl;
	}
	//for(int k=0;k<9;k++){
		cout<<"Matriz de Disponibilidad del número "<<endl;
	//cout<<endl;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<Matriz[i][j].Disp[1]<<" ";
			}
			cout<<endl;
		}
		//cout<<endl;
	//}*/
	
}

void MarcarBloque(int SubMatriz,Celda Matriz[][9],int NumeroBuscado){
	int fila=0,columna=0, cont=0;
	//int valores[9] = {1,2,3,4,5,6,7,8,9};
	switch(SubMatriz){
		case 1: fila=0; columna=0;
				break;
		case 2: fila=0; columna=3;
				break;
		case 3: fila=0; columna=6;
				break;
		case 4: fila=3; columna=0;
				break;
		case 5: fila=3; columna=3;
				break;
		case 6: fila=3; columna=6;
				break;
		case 7: fila=6; columna=0;
				break;
		case 8: fila=6; columna=3;
				break;
		case 9: fila=6; columna=6;
				break;
	}
	for(int i=fila;i<fila+3;i++){
		for(int j=columna;j<columna+3;j++){
			Matriz[i][j].Disp[NumeroBuscado-1] = 0;
			Matriz[i][j].BloqueDisp[NumeroBuscado-1] = 0;
		}
	}
}

bool RevisarCriterio2(int coordenada,int tipo,Celda Matriz[][9],int SubMatriz,int NumeroBuscado){
	int cont=0;
	if(tipo == 1){
		for(int i=0;i<9;i++){
		  if(Matriz[i][coordenada].Disp[NumeroBuscado-1] != 0 && Matriz[i][coordenada].Bloque != SubMatriz){//¿Hay algun disponible en los otros bloques?
		  	cont++;
		  }
		}
	}else{
		for(int i=0;i<9;i++){
		  if(Matriz[coordenada][i].Disp[NumeroBuscado-1] != 0 && Matriz[coordenada][i].Bloque != SubMatriz){//¿Hay algun disponible en los otros bloques?
		  	cont++;
		  }
		}
	}
	if(cont > 0){
		return true;
	}else{
		return false;
	}
}

int LlenarBloque(int SubMatriz,int NumeroBuscado,Celda Matriz[][9]){
	int fila=0,columna=0, cont=0,contCriterio2=0;
	bool Criterio2 = false,Criterio3 = false,var=true;
	Celda Auxiliar[20];
	//int valores[9] = {1,2,3,4,5,6,7,8,9};
	switch(SubMatriz){
		case 1: fila=0; columna=0;
				break;
		case 2: fila=0; columna=3;
				break;
		case 3: fila=0; columna=6;
				break;
		case 4: fila=3; columna=0;
				break;
		case 5: fila=3; columna=3;
				break;
		case 6: fila=3; columna=6;
				break;
		case 7: fila=6; columna=0;
				break;
		case 8: fila=6; columna=3;
				break;
		case 9: fila=6; columna=6;
				break;
	}


	for(int i=fila;i<fila+3;i++){
		for(int j=columna;j<columna+3;j++){
			//Criterio Básico
			if(Matriz[i][j].Valor == NumeroBuscado && Matriz[i][j].BloqueDisp[NumeroBuscado-1] != 0){
				
				for(int k=0;k<9;k++){					
						Matriz[k][j].Disp[NumeroBuscado-1] = 0;
						Matriz[i][k].Disp[NumeroBuscado-1] = 0;
				}
				MarcarBloque(Matriz[i][j].Bloque,Matriz,NumeroBuscado); //crear funcion que marque todo el bloque como no disp[NumeroBuscado-1]onible
				cont++; //contador que sirve para verificar si hay nuevos valores que agregar, si es 0, significa que no hay más valores a agregar
			}
		}
	}
	for(int i=fila;i<fila+3;i++){
		for(int j=columna;j<columna+3;j++){
			//Segundo Criterio
			if(Matriz[i][j].Disp[NumeroBuscado-1] != 0){

				Auxiliar[contCriterio2].CoordenadaX = i;
				Auxiliar[contCriterio2].CoordenadaY = j;
				
				contCriterio2++;
			}

		}
	}
			

	//Aplicación del segundo criterio para 2 elementos
	if(contCriterio2==2){

		if(Auxiliar[0].CoordenadaX == Auxiliar[1].CoordenadaX && RevisarCriterio2(Auxiliar[0].CoordenadaX,0,Matriz,SubMatriz,NumeroBuscado)){

			for(int i=0;i<9;i++){
			  if(Matriz[Auxiliar[0].CoordenadaX][i].Disp[NumeroBuscado-1] != 0 && Matriz[Auxiliar[0].CoordenadaX][i].Bloque != SubMatriz){
			  	Matriz[Auxiliar[0].CoordenadaX][i].Disp[NumeroBuscado-1] = 0;
			  }			  	
			}
			cont++;
		}

		if(Auxiliar[0].CoordenadaY == Auxiliar[1].CoordenadaY && RevisarCriterio2(Auxiliar[0].CoordenadaY,1,Matriz,SubMatriz,NumeroBuscado)){
				
			for(int i=0;i<9;i++){
			 if(Matriz[i][Auxiliar[0].CoordenadaY].Disp[NumeroBuscado-1] != 0 && Matriz[i][Auxiliar[0].CoordenadaY].Bloque != SubMatriz){
			  	Matriz[i][Auxiliar[0].CoordenadaY].Disp[NumeroBuscado-1] = 0;
			  }	
			}
			cont++;
		}
	}

	//
	//Aplicación del segundo criterio para 3 elementos
	if(contCriterio2==3){
	  if(Auxiliar[0].CoordenadaX == Auxiliar[1].CoordenadaX && Auxiliar[1].CoordenadaX == Auxiliar[2].CoordenadaX && RevisarCriterio2(Auxiliar[0].CoordenadaX,0,Matriz,SubMatriz,NumeroBuscado)){
			for(int i=0;i<9;i++){
			  if(Matriz[Auxiliar[0].CoordenadaX][i].Disp[NumeroBuscado-1] != 0 && Matriz[Auxiliar[0].CoordenadaX][i].Bloque != SubMatriz){
			  	Matriz[Auxiliar[0].CoordenadaX][i].Disp[NumeroBuscado-1] = 0;
			  }			  	
			}
			cont++;
		}
		if(Auxiliar[0].CoordenadaY == Auxiliar[1].CoordenadaY && Auxiliar[1].CoordenadaY == Auxiliar[2].CoordenadaY && RevisarCriterio2(Auxiliar[0].CoordenadaY,1,Matriz,SubMatriz,NumeroBuscado)){
			for(int i=0;i<9;i++){
			 if(Matriz[i][Auxiliar[0].CoordenadaY].Disp[NumeroBuscado-1] != 0 && Matriz[i][Auxiliar[0].CoordenadaY].Bloque != SubMatriz){
			  	Matriz[i][Auxiliar[0].CoordenadaY].Disp[NumeroBuscado-1] = 0;
			  }	
			}
			cont++;
		}
	}

	if(cont==0){
		return 0;
	}else{

		return 1;
	}
}


int RevisionFila(int coordi, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, jaux=0,bloqueaux=0,cont2=0;
	for(int j=0;j<9;j++){
		if(Matriz[coordi][j].Valor != NumeroBuscado && Matriz[coordi][j].Disp[NumeroBuscado-1] == 0 && Matriz[coordi][j].Valor >0){ //se salta su propia celda y busca entre los no disponibles
			cont++;
		}else{
			jaux = j;
			bloqueaux = Matriz[coordi][j].Bloque;
		}
		if(Matriz[coordi][j].Disp[NumeroBuscado-1] == 0){//Si las 9 celdas están ocupadas, sale sin agregar valores
			cont2++;
		}
	}
	if(cont2 == 9){
		return 0;
	}
	if(cont == 8){

		Matriz[coordi][jaux].Valor = NumeroBuscado;
		Matriz[coordi][jaux].Bloque = bloqueaux;
		for(int r=0;r<9;r++){
		  Matriz[coordi][jaux].Disp[r] = 0;
		}

		return 1; //Ya se terminó con este bloque, agregó un valor, por lo tanto debe seguir
		
	}else{

		return 0; //No agregó valores, si los demás están también en 0 en una vuelta completa, se termina.
	}
}
int RevisionColumna(int coordj, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, iaux=0,bloqueaux=0,cont2=0;
	for(int i=0;i<9;i++){
		if(Matriz[i][coordj].Valor != NumeroBuscado && Matriz[i][coordj].Disp[NumeroBuscado-1] == 0 && Matriz[i][coordj].Valor >0){ //se salta su propia celda y busca entre los no disponibles
			cont++;
		}else{
			iaux = i;
			bloqueaux = Matriz[i][coordj].Bloque;
		}
		if(Matriz[i][coordj].Disp[NumeroBuscado-1] == 0){ //Si las 9 celdas están ocupadas, sale sin agregar valores
			cont2++;
		}
	}
	if(cont2 == 9){
		return 0;
	}

	if(cont == 8){
		Matriz[iaux][coordj].Valor = NumeroBuscado;
		Matriz[iaux][coordj].Bloque = bloqueaux;
		for(int r=0;r<9;r++){
		  Matriz[iaux][coordj].Disp[r] = 0;										
		}

		return 1; //Ya se terminó con este bloque, agregó un valor, por lo tanto debe seguir
		
	}else{		
		return 0; //No agregó valores, si los demás están también en 0 en una vuelta completa, se termina.
	}
}

int RevisionBloque(int SubMatriz,int NumeroBuscado,Celda Matriz[][9]){
	int fila=0,columna=0, cont=0, jaux,iaux,bloqueaux;
	//int valores[9] = {1,2,3,4,5,6,7,8,9};
	switch(SubMatriz){
		case 1: fila=0; columna=0;
				break;
		case 2: fila=0; columna=3;
				break;
		case 3: fila=0; columna=6;
				break;
		case 4: fila=3; columna=0;
				break;
		case 5: fila=3; columna=3;
				break;
		case 6: fila=3; columna=6;
				break;
		case 7: fila=6; columna=0;
				break;
		case 8: fila=6; columna=3;
				break;
		case 9: fila=6; columna=6;
				break;
	}
	for(int i=fila;i<fila+3;i++){
		for(int j=columna;j<columna+3;j++){
			if(Matriz[i][j].Disp[NumeroBuscado-1] == 0){
				cont++;		//Revisa cuantas celdas faltan por llenar, si son 8, llena automáticamente con el número que falta
			}else{ //Guarda las coordenadas de la celda que falta llenar
				iaux = i;
				jaux = j;
			}	
			
		}
	}
	if(cont == 8){
		Matriz[iaux][jaux].Valor = NumeroBuscado;
		Matriz[iaux][jaux].Bloque = SubMatriz;	
		for(int r=0;r<9;r++){
		  Matriz[iaux][jaux].Disp[r] = 0;											
		}

		return 1; //Ya se terminó con este bloque, agregó un valor, por lo tanto debe seguir
	}else{
		return 0; //No agregó valores, si los demás están también en 0 en una vuelta completa, se termina.
	}
}

int RevisarCelda(int coordi,int coordj,int NumeroBuscado,Celda Matriz[][9]){
	int cont=0,aux=0;
	for(int i=0;i<9;i++){
		if(Matriz[coordi][coordj].Disp[i] == 0){
			cont++;
		}else{
			aux = i;
		}
	}
	if(cont==8 && aux == NumeroBuscado-1){
	  Matriz[coordi][coordj].Valor = NumeroBuscado;
	  for(int j=0;j<9;j++){
	  	Matriz[coordi][coordj].Disp[j] = 0;
	  }
	  return 1;
	}else{
		return 0;
	}
}
void Revisar(Celda Matriz[][9], int NumeroBuscado){
	bool var = true;
	while(var){
	int b=0,f=0,c=0,lb=0,n=0,b2=0,f2=0,c2=0,lb2=0,cont=0,celda=0,celda2=0;

		for(int l=0;l<9;l++){
			lb = LlenarBloque(l+1,NumeroBuscado,Matriz);
			if(lb==1){
				lb2 = 1;
			}
		}
		for(int i=0;i<9;i++){
			b = RevisionBloque(i+1,NumeroBuscado,Matriz);		
			if(b==1){
				b2 = 1;
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				celda = RevisarCelda(i,j,NumeroBuscado,Matriz);
				if(celda == 1){
					celda2=1;
				}
			}
		}
		for(int i=0;i<9;i++){
			f = RevisionFila(i,NumeroBuscado,Matriz);	
			if(f==1){
				f2 = 1;
			}	
		}
		for(int i=0;i<9;i++){
			c = RevisionColumna(i,NumeroBuscado,Matriz);	
			if(c==1){
				c2 = 1;
			}	
		}
		for(int m=0;m<9;m++){
			lb = LlenarBloque(m+1,NumeroBuscado,Matriz);
			if(lb==1){
				lb2 = 1;
			}
		}

		//While itera hasta que no haya habido cambio en ninguna de las funciones, eso significa que debe esperar
		//a que la matriz se actualice con los datos de los otros números
		
		if(b2 == 0 && f2 == 0 && c2 == 0 && lb2 == 0 && celda2==0){
			var = false;
		}
		n++;
	}
	
	
}



void LlenarMatriz(char* inputC,Celda Matriz[][9]){
	bool var=true,var2=true;
	string input = inputC;
	string token,token2,auxiliar;
	int largo = input.length(), pos,n=0,pos2,aux,cont3=1,bloque,asd=0;
	int numero[2];
	char delimitador = ']',delimitador2= ';';
	while(n<largo){
		pos = input.find(delimitador);
		if(pos != -1 && var == true){
			if(pos == -1){
				var = false;
			}
			token = input.substr(1,pos-1);
			auxiliar = token;
			cont3=1;
			for(int i=0;i<3;i++){
				if(i!=2){
					pos2= auxiliar.find(delimitador2);
					token2 = auxiliar.substr(0,pos2);
					aux = stoi(token2);
					numero[i+cont3] = aux;
					cont3=-1;
					auxiliar.erase(0,pos2+1);
				}else{
					aux = stoi(auxiliar);
					if(numero[0] >= 0 && numero[0] <= 9 && numero[1] >= 0 && numero[1] <= 9 && aux >=1 && aux <=9){
						Matriz[numero[1]][numero[0]].Valor = aux;
						Matriz[numero[1]][numero[0]].CoordenadaX = numero[1];	
						Matriz[numero[1]][numero[0]].CoordenadaY = numero[0];
						bloque = Matriz[numero[1]][numero[0]].Bloque;
						for(int r=0;r<9;r++){
							Matriz[numero[1]][numero[0]].Disp[r] = 0;							
						}
						asd++;
					}else{
						n=largo;
						var2=false;
					}				
				}	
			}
			input.erase(0,pos+1);
			n++;
		}else{
			n=largo;

		}
	}
	if(var2== true){
	 //MostrarMatriz(Matriz);	
	}	

}
void InicializarMatriz(Celda Matriz[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			Matriz[i][j].Valor = 0;
			for(int k=0;k<9;k++){
				Matriz[i][j].Disp[k] = 1;
				Matriz[i][j].BloqueDisp[k] = 1;	
			}			
			Matriz[i][j].Bloque = 0;		
			if(i < 3 && j < 3){
				Matriz[i][j].Bloque = 1;	
			}
			if(i < 3 && j >= 3 && j < 6){
				Matriz[i][j].Bloque = 2;	
			}
			if(i < 3 && j >= 6 && j < 9){
				Matriz[i][j].Bloque = 3;	
			}
			if(i >= 3 && i < 6 && j < 3){
				Matriz[i][j].Bloque = 4;	
			}
			if(i >= 3 && j < 6 && j >= 3 && j < 6){
				Matriz[i][j].Bloque = 5;	
			}
			if(i >= 3 && i < 6 && j >= 6 && j < 9){
				Matriz[i][j].Bloque = 6;	
			}
			if(i >= 6 && j < 3){
				Matriz[i][j].Bloque = 7;	
			}
			if(i >= 6 && j >= 3 && j < 6){
				Matriz[i][j].Bloque = 8;	
			}	
			if(i >= 6 && j >= 6 && j < 9){
				Matriz[i][j].Bloque = 9;	
			}							

		}
	}
}
void ContarFaltantes(Celda Matriz[][9]){
	int cont=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(Matriz[i][j].Disp[0] == 0){
				cont++;
			}
		}
	}
	cout<<"La cantidad de celdas ocupadas es: "<<cont<<endl;
}

int main(int argc, char* argv[]){
	Celda Matriz[9][9];
	int n=0;
	InicializarMatriz(Matriz);
	LlenarMatriz(argv[1],Matriz);
	MostrarMatriz(Matriz);
	while(n<1000){
	 for(int i=1;i<10;i++){
	 Revisar(Matriz,i);	
	}
	n++;	
	}
	MostrarMatriz(Matriz);
	ContarFaltantes(Matriz);
}