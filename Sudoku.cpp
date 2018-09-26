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
	/*for(int k=0;k<9;k++){
		cout<<"Matriz de Disponibilidad del número "<<k+1<<endl;
	cout<<endl;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<Matriz[i][j].Disp[k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}*/
	
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
			if(Matriz[i][j].Valor == NumeroBuscado){
				
				for(int k=0;k<9;k++){
						if(Matriz[k][j].Disp[NumeroBuscado-1] != 0){
							Matriz[k][j].Disp[NumeroBuscado-1] = 0;
							cont++;
						}	
						if(Matriz[i][k].Disp[NumeroBuscado-1] = 0){
							Matriz[i][k].Disp[NumeroBuscado-1] = 0;
							cont++;	
						}			
						
				}
				MarcarBloque(Matriz[i][j].Bloque,Matriz,NumeroBuscado); //crear funcion que marque todo el bloque como no disponible
				 //contador que sirve para verificar si hay nuevos valores que agregar, si es 0, significa que no hay más valores a agregar
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
bool MarcarBloque2(Celda Auxiliar[],Celda Matriz[][9],int NumeroBuscado,int tipo,int revisar){
	int fila=0,columna=0, cont=0;
	//int valores[9] = {1,2,3,4,5,6,7,8,9};
	int SubMatriz = Auxiliar[0].Bloque;
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
			if(tipo == 2){
				if(i != Auxiliar[0].CoordenadaX){
					if(revisar == 0){
						Matriz[i][j].Disp[NumeroBuscado-1] = 0;	
					}else{
						if(Matriz[i][j].Disp[NumeroBuscado-1] == 0){
							cont++;
						}			
					}	
				}
			}else{
				if(j != Auxiliar[0].CoordenadaY){
					if(revisar == 0){
						Matriz[i][j].Disp[NumeroBuscado-1] = 0;	

					}else{
						if(Matriz[i][j].Disp[NumeroBuscado-1] == 0){
							cont++;
						}
					}
				}
			}			
		}
	}
	if(cont==6){
		return false;
	}
	return true;
}
int LlenarFila(int coordi, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, jaux=0,bloqueaux=0,cont2=0,cont3 = 0,retorno=0,auxBloque=0;
	Celda Auxiliar[10];
	for(int j=0;j<9;j++){
		if(Matriz[coordi][j].Disp[NumeroBuscado-1] == 0){
			cont++;
		}
	}
	if(cont<8 && cont>5){
		for(int j=0;j<9;j++){
			if(Matriz[coordi][j].Disp[NumeroBuscado-1] != 0){
				if(cont3 == 0){
					auxBloque = Matriz[coordi][j].Bloque;
				}

				if(auxBloque == Matriz[coordi][j].Bloque){
					Auxiliar[cont3].Bloque = Matriz[coordi][j].Bloque;
					Auxiliar[cont3].CoordenadaX = coordi;
					Auxiliar[cont3].CoordenadaY = j;
					cont3++;	

				}else{
					cont3=10;
					j=9;

				}	
			}
		}
	}
	
	if((cont3 == 2 || cont3 == 3) && MarcarBloque2(Auxiliar,Matriz,NumeroBuscado,2,1)){
		if(Auxiliar[0].Bloque == Auxiliar[1].Bloque){
			MarcarBloque2(Auxiliar,Matriz,NumeroBuscado,2,0);
			retorno++;
		}
	}
	return retorno;
}
int LlenarColumna(int coordj, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, jaux=0,bloqueaux=0,cont2=0,cont3 = 0,retorno=0,auxBloque=0;
	Celda Auxiliar[10];
	for(int j=0;j<9;j++){
		if(Matriz[j][coordj].Disp[NumeroBuscado-1] == 0){
			cont++;
		}
	}
	if(cont<8 && cont>5){
		for(int i=0;i<9;i++){
			if(Matriz[i][coordj].Disp[NumeroBuscado-1] != 0){
				if(cont3 == 0){
					auxBloque = Matriz[i][coordj].Bloque;
				}

				if(auxBloque == Matriz[i][coordj].Bloque){
					Auxiliar[cont3].Bloque = Matriz[i][coordj].Bloque;
					Auxiliar[cont3].CoordenadaX = i;
					Auxiliar[cont3].CoordenadaY = coordj;
					cont3++;
				}else{
					cont3=10;
					i=9;
				}
			}
		}
	}
	
	if((cont3 == 2 || cont3 == 3) && MarcarBloque2(Auxiliar,Matriz,NumeroBuscado,3,1)){
		if(Auxiliar[0].Bloque == Auxiliar[1].Bloque){

			MarcarBloque2(Auxiliar,Matriz,NumeroBuscado,3,0);
			retorno++;
		}
	}
	return retorno;
}
int RevisionFila(int coordi, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, jaux=0,bloqueaux=0,cont2=0,cont3 = 0,retorno=0,auxBloque=0;
	Celda Auxiliar[10];
	for(int j=0;j<9;j++){
		if(Matriz[coordi][j].Valor != NumeroBuscado && Matriz[coordi][j].Disp[NumeroBuscado-1] == 0){ //se salta su propia celda y busca entre los no disponibles
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
		retorno = 0;
	}
	if(cont == 8){

		Matriz[coordi][jaux].Valor = NumeroBuscado;
		Matriz[coordi][jaux].Bloque = bloqueaux;
		
		for(int r=0;r<9;r++){
		  Matriz[coordi][jaux].Disp[r] = 0;
		}
		retorno = 1; //Ya se terminó con este bloque, agregó un valor, por lo tanto debe seguir
		
	}
	return retorno;
}
int RevisionColumna(int coordj, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, iaux=0,bloqueaux=0,cont2=0,cont3=0,retorno=0,auxBloque=0;
	Celda Auxiliar[10];
	for(int i=0;i<9;i++){
		if(Matriz[i][coordj].Valor != NumeroBuscado && Matriz[i][coordj].Disp[NumeroBuscado-1] == 0){ //se salta su propia celda y busca entre los no disponibles
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
		retorno = 0;
	}

	if(cont == 8){
		Matriz[iaux][coordj].Valor = NumeroBuscado;
		Matriz[iaux][coordj].Bloque = bloqueaux;
		for(int r=0;r<9;r++){
		  Matriz[iaux][coordj].Disp[r] = 0;										
		}

		retorno = 1; //Ya se terminó con este bloque, agregó un valor, por lo tanto debe seguir
		
	}
	return retorno;
}

int RevisionBloque(int SubMatriz,int NumeroBuscado,Celda Matriz[][9]){
	int fila=0,columna=0, cont=0, jaux,iaux,bloqueaux,cont2=0,retorno=0;
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
	if(cont==9){
		retorno = 0;
	}
	if(cont == 8){
		Matriz[iaux][jaux].Valor = NumeroBuscado;
		Matriz[iaux][jaux].Bloque = SubMatriz;
			
		for(int r=0;r<9;r++){
		  Matriz[iaux][jaux].Disp[r] = 0;											
		}

		retorno =1; //Ya se terminó con este bloque, agregó un valor, por lo tanto debe seguir
	}
	return retorno;
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

bool MarcarBloque3(int coord1,int coord2,int coord,int SubMatriz,int Numero1,int Numero2,Celda Matriz[][9],int filacolumna,int revisar){
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
			if(filacolumna == 1){
				if((i != coord || j != coord1) && (i!=coord || j != coord2)){
					if(revisar == 0){
						Matriz[i][j].Disp[Numero1-1] = 0;
						Matriz[i][j].Disp[Numero2-1] = 0;	
					}else{
						if(Matriz[i][j].Disp[Numero1-1] == 0 && Matriz[i][j].Disp[Numero2-1] == 0){
							cont++;
						}			
					}	
				}
			}else{
				if((i != coord1 || j != coord) && (i!=coord2 || j != coord)){
					if(revisar == 0){
						Matriz[i][j].Disp[Numero1-1] = 0;
						Matriz[i][j].Disp[Numero2-1] = 0;	
					}else{
						if(Matriz[i][j].Disp[Numero1-1] == 0 && Matriz[i][j].Disp[Numero2-1] == 0){
							cont++;
						}	
					}
				}
			}			
		}
	}
	if(cont==6){
		return false;
	}
	return true;
}

int NakedSubset(int tipo,int coord, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, jaux=0,cont2=0,cont3 = 0,retorno=0;
	int auxValor[20][20],auxCoord[10], auxBloque[10];
	for(int i=0;i<9;i++){
		cont=0;
		if(tipo == 0){
			for(int k=0;k<9;k++){
				if(Matriz[coord][i].Disp[k] != 0){
					auxValor[cont2][cont] = k+1;
					cont++;
				}
			}
			if(cont==2){
				auxCoord[cont2] = i;
				auxBloque[cont2] = Matriz[coord][i].Bloque;	
				cont2++;	
			}
			if(cont2==2 && auxBloque[0] == Matriz[coord][i].Bloque){
				
				if(auxValor[0][0] == auxValor[1][0] && auxValor[0][1] == auxValor[1][1] && MarcarBloque3(auxCoord[0],auxCoord[1],coord,auxBloque[0],auxValor[0][0],auxValor[1][0],Matriz,1,1)){
					MarcarBloque3(auxCoord[0],auxCoord[1],coord,auxBloque[0],auxValor[0][0],auxValor[0][1],Matriz,1,0);
					retorno++;
				}
			}			
		}else{
			for(int k=0;k<9;k++){
				if(Matriz[i][coord].Disp[k] != 0){
					auxValor[cont2][cont] = k+1;
					cont++;
				}
			}
			if(cont==2){
				auxCoord[cont2] = i;
				auxBloque[cont2] = Matriz[i][coord].Bloque;

				cont2++;
				//cout<<"hello otterfucker "<<auxValor[0][0]<<" "<<auxValor[1][0]<<endl;	
			}
			if(cont2==2 && auxBloque[0] == Matriz[i][coord].Bloque){	
				if(auxValor[0][0] == auxValor[1][0] && auxValor[0][1] == auxValor[1][1] && MarcarBloque3(auxCoord[0],auxCoord[1],coord,auxBloque[0],auxValor[0][0],auxValor[0][1],Matriz,2,1)){
					//cout<<" "<<auxValor[0][0]<<" "<<auxValor[0][1]<<" bloque "<<auxBloque<<" coord"<<endl;
					MarcarBloque3(auxCoord[0],auxCoord[1],coord,auxBloque[0],auxValor[0][0],auxValor[0][1],Matriz,2,0);
					retorno++;
				}
			}	
		}
	}

	return retorno;
	
}

bool Cant(int NumeroBuscado,int coord,Celda Matriz[][9],int tipo){
	int cont=0;
	for(int i=0;i<9;i++){
		if(tipo == 1){
			if(Matriz[coord][i].Disp[NumeroBuscado-1] == 0){
				cont++;
			}
		}else{
			if(Matriz[i][coord].Disp[NumeroBuscado-1] == 0){
				cont++;
			}
		}
	}
	if(cont == 7){
		return true;
	}else{
		return false;
	}
}

int HiddenSubsetF(int coordi, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, jaux=0,bloqueaux=0,cont2=0,cont3 = 0,retorno=0,auxBloque=0,contDisp=0, auxi=0;
	Celda Auxiliar[10];
	for(int j=0;j<9;j++){
		if(Matriz[coordi][j].Disp[NumeroBuscado-1] == 0){
			cont++;
		}
	}
	if(cont==7){
		for(int j=0;j<9;j++){
			if(Matriz[coordi][j].Disp[NumeroBuscado-1] != 0){
				if(cont3 == 0){
					auxBloque = Matriz[coordi][j].Bloque;
				}

				if(auxBloque == Matriz[coordi][j].Bloque){
					Auxiliar[cont3].Bloque = Matriz[coordi][j].Bloque;
					Auxiliar[cont3].CoordenadaX = coordi;
					Auxiliar[cont3].CoordenadaY = j;
					for(int k=0;k<9;k++){
						Auxiliar[cont3].Disp[k] = Matriz[coordi][j].Disp[k];
					}
					cont3++;	

				}else{
					cont3=10;
					j=9;

				}	
			}
		}
	}
	
	if(cont3 == 2){
		if(Auxiliar[0].Bloque == Auxiliar[1].Bloque){
			for(int i=0;i<9;i++){
				if(Cant(i+1,coordi,Matriz,1)){
					if(Auxiliar[0].Disp[i] == Auxiliar[1].Disp[i] && i != NumeroBuscado-1  && Auxiliar[0].Disp[i] == 1){
						contDisp++;
						auxi = i+1;
					}	
				}
					
			}
			if(contDisp == 1){
				for(int i=0;i<9;i++){
					if(i != NumeroBuscado-1 && i != auxi-1){
						if(Matriz[Auxiliar[0].CoordenadaX][Auxiliar[0].CoordenadaY].Disp[i] != 0){
							Matriz[Auxiliar[0].CoordenadaX][Auxiliar[0].CoordenadaY].Disp[i] = 0;
							retorno++;
						}
						if(Matriz[Auxiliar[1].CoordenadaX][Auxiliar[1].CoordenadaY].Disp[i] != 0){
							Matriz[Auxiliar[1].CoordenadaX][Auxiliar[1].CoordenadaY].Disp[i] = 0;	
							retorno++;
						}
					}			  	
				}	

			}						
			
		}
	}
	return retorno;
}

int HiddenSubsetC(int coordj, int NumeroBuscado,Celda Matriz[][9]){
	int cont=0, jaux=0,bloqueaux=0,cont2=0,cont3 = 0,retorno=0,auxBloque=0,contDisp =0, auxi=0;
	Celda Auxiliar[10];
	for(int j=0;j<9;j++){
		if(Matriz[j][coordj].Disp[NumeroBuscado-1] == 0){
			cont++;
		}
	}
	if(cont==7){
		for(int j=0;j<9;j++){
			if(Matriz[j][coordj].Disp[NumeroBuscado-1] != 0){
				if(cont3 == 0){
					auxBloque = Matriz[j][coordj].Bloque;
				}

				if(auxBloque == Matriz[j][coordj].Bloque){
					Auxiliar[cont3].Bloque = Matriz[j][coordj].Bloque;
					Auxiliar[cont3].CoordenadaX = j;
					Auxiliar[cont3].CoordenadaY = coordj;
					for(int k=0;k<9;k++){
						Auxiliar[cont3].Disp[k] = Matriz[j][coordj].Disp[k];
					}
					cont3++;	

				}else{
					cont3=10;
					j=9;

				}	
			}
		}
	}	
	if(cont3 == 2){
		for(int i=0;i<9;i++){
			if(Cant(i+1,coordj,Matriz,2)){
				if(Auxiliar[0].Disp[i] == Auxiliar[1].Disp[i] && i != NumeroBuscado-1 && Auxiliar[0].Disp[i] == 1 ){
					contDisp++;
					auxi = i+1;
				}		
			}
			
		}
		if(contDisp == 1){

			for(int i=0;i<9;i++){
				if(i != NumeroBuscado-1 && i != auxi-1){		  	 
					if(Matriz[Auxiliar[0].CoordenadaX][Auxiliar[0].CoordenadaY].Disp[i] != 0){
						Matriz[Auxiliar[0].CoordenadaX][Auxiliar[0].CoordenadaY].Disp[i] = 0;
						retorno++;
					}
					if(Matriz[Auxiliar[1].CoordenadaX][Auxiliar[1].CoordenadaY].Disp[i] != 0){
						Matriz[Auxiliar[1].CoordenadaX][Auxiliar[1].CoordenadaY].Disp[i] = 0;
						retorno++;	
					}
				}			  	
			}	

		}						

	}
	return retorno;
}

void Revisar(Celda Matriz[][9], int NumeroBuscado){
	bool var = true;
	while(var){
	int b=0;

		for(int l=0;l<9;l++){
			b = LlenarBloque(l+1,NumeroBuscado,Matriz);
			if(b==1){
				b = 1;
			}
		}
		for(int j=0;j<2;j++){
			for(int i=0;i<9;i++){
				b = NakedSubset(j,i,NumeroBuscado,Matriz);	
				if(b==1){
					b = 1;
				}	
			}
		}
		for(int i=0;i<9;i++){
			b = LlenarFila(i,NumeroBuscado,Matriz);	

			if(b==1){
				b = 1;
			}	
			//cout<<"b fila"<<endl;
		}	

		for(int i=0;i<9;i++){
			b = LlenarColumna(i,NumeroBuscado,Matriz);
			if(b==1){
				b = 1;
			}	
			//cout<<"b columna"<<endl;

		}
		
		for(int i=0;i<9;i++){
			b = HiddenSubsetC(i,NumeroBuscado,Matriz);
			if(b==1){
				b = 1;
			}

		}
		for(int i=0;i<9;i++){
			b = HiddenSubsetF(i,NumeroBuscado,Matriz);	
			if(b==1){
				b = 1;
			}	
		}
		
		for(int i=0;i<9;i++){
			b = RevisionBloque(i+1,NumeroBuscado,Matriz);

			if(b==1){
				b = 1;
			}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				b = RevisarCelda(i,j,NumeroBuscado,Matriz);

				if(b == 1){
					b=1;
				}
			}
		}
	
		for(int i=0;i<9;i++){
			b = RevisionFila(i,NumeroBuscado,Matriz);	

			if(b==1){
				b = 1;
			}	
		}
		for(int i=0;i<9;i++){
			b = RevisionColumna(i,NumeroBuscado,Matriz);
			if(b==1){
				b = 1;
			}	
		}	
		for(int m=0;m<9;m++){
			b = LlenarBloque(m+1,NumeroBuscado,Matriz);
			if(b==1){
				b = 1;
			}
		}
		for(int i=0;i<9;i++){
			b = LlenarFila(i,NumeroBuscado,Matriz);	

			if(b==1){
				b = 1;
			}	
		}	

		for(int i=0;i<9;i++){
			b = LlenarColumna(i,NumeroBuscado,Matriz);
			if(b==1){
				b = 1;
			}	

		}
		for(int j=0;j<2;j++){
			for(int i=0;i<9;i++){
			//	b = NakedSubset(j,i,NumeroBuscado,Matriz);	
				if(b==1){
					b = 1;
				}	
			}
		}
		for(int i=0;i<9;i++){
			b = HiddenSubsetC(i,NumeroBuscado,Matriz);
			if(b==1){
				b = 1;
			}

		}
		for(int i=0;i<9;i++){
			b = HiddenSubsetF(i,NumeroBuscado,Matriz);	
			if(b==1){
				b = 1;
			}	
		}
		//While itera hasta que no haya habido cambio en ninguna de las funciones, eso significa que debe esperar
		//a que la matriz se actualice con los datos de los otros números
		
		if(b == 0){
			var = false;
		}
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

}