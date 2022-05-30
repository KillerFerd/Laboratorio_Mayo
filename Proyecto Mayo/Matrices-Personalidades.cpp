//***Matriz de Compatibilidad de las 16 Personalidades (Usando Memoria Dinamica)
//***Desarrollador: KillerFerd
//***Curso: Programación III
//En esta ocación se necesita incorporar y manipular la memoria dinamica con la incorporacion de
//la matriz a un arbol binario
#include<iostream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
}

struct id_personalidades{
	char text;
	int id_color;
	int id_decimal;
	string hexadecimal;
	int p1=0, p2=0;
};

struct Nodo{
	int id_decimal;
	int id_color;
	string hexadecimal;
	Nodo *der;
	Nodo *izq;
};

Nodo *crearNodo(int,int,string);
void insertarNodo(Nodo *&,int,int,string);
Nodo *arbol = NULL;
void mostrarArbol(Nodo *,int);
string calcularHex(int);

Nodo *crearNodo(int n1, int n2, string s1){
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->id_decimal = n1;
	nuevo_nodo->id_color = n2;
	nuevo_nodo->hexadecimal = s1;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol,int n1, int n2, string s1){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n1,n2,s1);
		arbol = nuevo_nodo;
	}

	else{
		int valorRaiz = arbol->id_decimal;
		if(n1 < valorRaiz){
			insertarNodo(arbol->izq,n1,n2,s1);
		}
		else{
			insertarNodo(arbol->der,n1,n2,s1);
		}
	}
}

//Para mostrar estructura en forma de arbol binario 
//***No se aprecia correctamente por ser una gran cantidad de datos***
/*void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->id_decimal<<","<<arbol->id_color<<","<<arbol->hexadecimal<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}*/

//Para mostrar estrucutra en forma de lista en recorrido inorden
void mostrarArbol(Nodo *arbol,int cont){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		SetConsoleTextAttribute(hConsole, arbol->id_color);
		cout<<arbol->id_decimal<<","<<arbol->id_color<<","<<arbol->hexadecimal<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

string calcularHex(int id_decimal){
	int digitohex[20];
	char cad[30];
	string salida;
	int residuo, resultado, i=0,contador=0;

	do
	{
		residuo = id_decimal % 16;
		resultado = id_decimal / 16;
		digitohex[i] = residuo;
		id_decimal=resultado;
		i++;

	} while(resultado>15);
	digitohex[i] = 	resultado;
	for(int j=i;j>=0;j--){
		if(digitohex[j]==10){
			cad[contador]='A';
			contador++;
		}
		else if(digitohex[j]==11){
			cad[contador]='B';
			contador++;
		}
		else if(digitohex[j]==12){
			cad[contador]='C';
			contador++;
		}
		else if(digitohex[j]==13){
			cad[contador]='D';
			contador++;
		}
		else if(digitohex[j]==14){
			cad[contador]='E';
			contador++;
		}
		else if(digitohex[j]==15){
			cad[contador]='F';
			contador++;
		}
		else
		{
			cad[contador]=digitohex[j]+'0';
			contador++;
		}
	}
	for(int j=0;j<contador;j++){
		salida=salida+cad[j];
	}
	return salida;
}


int main()
{
	
 	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	system("cls");
	int bcount=0, azcount=0, vcount=0, amcount=0, ncount=0; 
	
	int flag1=0;
	int id_decimal=0,id_color,contador=0;
	string hexadecimal; 
	int matriz2[16][16]=
	{
	7,11,11,2,11,14,2,14,14,4,4,4,11,14,4,2,
	11,7,14,11,2,11,4,2,11,14,4,14,4,4,4,4,
	11,2,7,11,2,4,11,14,4,4,4,14,14,4,14,11,
	2,11,2,7,14,2,14,11,14,4,14,11,4,4,4,14,
	11,14,2,14,7,11,11,2,4,14,4,4,14,2,14,14,
	14,2,4,2,11,7,14,11,2,2,14,4,4,14,4,4,
	2,14,11,2,11,2,7,11,4,4,14,4,14,14,2,14,
	14,2,2,11,2,11,2,7,4,14,2,14,4,4,14,4,
	14,11,14,14,4,14,4,4,7,11,2,11,2,2,14,14,
	4,14,4,4,4,2,4,14,11,7,11,2,2,11,2,4,
	4,14,4,14,14,2,2,2,2,11,7,11,14,2,11,2,
	4,2,14,2,4,14,14,2,11,2,11,7,2,14,2,2,
	2,4,2,4,14,4,14,4,2,2,14,2,7,11,2,11,
	14,4,4,4,2,14,4,4,2,11,2,14,11,7,11,2,
	4,4,14,4,4,4,11,14,14,2,11,2,2,11,7,11,
	2,4,11,14,14,4,2,4,14,14,2,2,11,2,11,7
	};
	
	/*
	per[0].arq=">ISFJ";  per[1].arq=">ISTJ";  per[2].arq=">ESTJ";  per[3].arq=">ESFJ"; per[4].arq=">ISTP";  per[5].arq=">ISFP";
	per[6].arq=">ESTP";  per[7].arq=">ESFP";  per[8].arq=">INFJ";  per[9].arq=">INFP"; per[10].arq=">ENFP"; per[11].arq=">ENFJ";
	per[12].arq=">INTJ"; per[13].arq=">INTP"; per[14].arq=">ENTP"; per[15].arq=">ENTJ";
	*/
		
	system("cls");
	
    int azsize=1;
	id_personalidades *azul = new id_personalidades[azsize];
	int vsize=1;
	id_personalidades *verde = new id_personalidades[vsize];
	int amsize=1;
	id_personalidades *amarillo = new id_personalidades[amsize];
	int nsize=1;
	id_personalidades *naranja = new id_personalidades[nsize];
	int bsize=1;
	id_personalidades *blanco = new id_personalidades[bsize];	

	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		{

			if (matriz2[i][j]==11){
				azul[azcount].p1=i;
				azul[azcount].p2=j;
				id_decimal++;
				azul[azcount].id_decimal=id_decimal;
				azul[azcount].hexadecimal=calcularHex(id_decimal);
				azul[azcount].id_color=11;
				azul[azcount].text='B';
				azcount++;

				azsize=azsize+5;
				id_personalidades *aux = new id_personalidades[azsize];
				for(int z=0;z<azsize-5;z++){
					aux[z] = azul[z];
				}
				delete[] azul;
				azul = aux;
			}

			else if (matriz2[i][j]==2){
				verde[vcount].p1=i;
				verde[vcount].p2=j;
				id_decimal++;
				verde[vcount].id_decimal=id_decimal;
				verde[vcount].hexadecimal=calcularHex(id_decimal);
				verde[vcount].id_color=2;
				verde[vcount].text='G';
				vcount++;
				vsize=vsize+5;
				id_personalidades *aux = new id_personalidades[vsize];
				for(int z=0;z<vsize-5;z++){
					aux[z] = verde[z];
				}
				delete[] verde;
				verde = aux;				
			}

			else if (matriz2[i][j]==14){
				amarillo[amcount].p1=i;
				amarillo[amcount].p2=j;
				id_decimal++;
				amarillo[amcount].id_decimal=id_decimal;
				amarillo[amcount].hexadecimal=calcularHex(id_decimal);
				amarillo[amcount].id_color=14;
				amarillo[amcount].text='Y';
				amcount++;
				amsize=amsize+5;
				id_personalidades *aux = new id_personalidades[amsize];
				for(int z=0;z<amsize-5;z++){
					aux[z] = amarillo[z];
				}
				delete[] amarillo;
				amarillo = aux;				
			}
			
			else if (matriz2[i][j]==4){
				naranja[ncount].p1=i;
				naranja[ncount].p2=j;
				id_decimal++;
				naranja[ncount].id_decimal=id_decimal;
				naranja[ncount].hexadecimal=calcularHex(id_decimal);
				naranja[ncount].id_color=4;
				naranja[ncount].text='O';
				ncount++;
				nsize=nsize+5;
				id_personalidades *aux = new id_personalidades[nsize];
				for(int z=0;z<nsize-5;z++){
					aux[z] = naranja[z];
				}
				delete[] naranja;
				naranja = aux;					
			}	

			else{
				blanco[bcount].p1=i;
				blanco[bcount].p2=j;
				id_decimal++;
				blanco[bcount].id_decimal=id_decimal;
				blanco[bcount].hexadecimal=calcularHex(id_decimal);
				blanco[bcount].id_color=7;
				blanco[bcount].text='W';
				bcount++;
				bsize=bsize+5;
				id_personalidades *aux = new id_personalidades[bsize];
				for(int z=0;z<bsize-5;z++){
					aux[z] = blanco[z];
				}
				delete[] blanco;
				blanco = aux;				
			}						
		}	 
	}	
	
	cout<<	"     "	<<">ISFJ "<<">ISTJ "<<">ESTJ "<<">ESFJ "<<">ISTP "<<">ISFP "<<">ESTP "<<">ESFP "
					<<">INFJ "<<">INFP "<<">ENFP "<<">ENFJ "<<">INTJ "<<">INTP "<<">ENTP "<<">ENTJ ";
	cout<<endl		<<">ISFJ "<<endl<<">ISTJ "<<endl<<">ESTJ "<<endl<<">ESFJ "<<endl<<">ISTP "<<endl
					<<">ISFP "<<endl<<">ESTP "<<endl<<">ESFP "<<endl<<">INFJ "<<endl<<">INFP "<<endl
					<<">ENFP "<<endl<<">ENFJ "<<endl<<">INTJ "<<endl<<">INTP "<<endl<<">ENTP "<<endl
					<<">ENTJ ";
	
	for(int i=0, p1=5;i<16,p1<100;i++,p1=p1+6)
	{
		for(int j=0;j<16;j++)
		{
			flag1=0;

				if (i==j){
						SetConsoleTextAttribute(hConsole, blanco[1].id_color);
						gotoxy(p1+2,j+1);
						cout<<blanco[i].text;
				}
				else{
						for(int z=0;z<100;z++){
							if(i==azul[z].p1 && j==azul[z].p2 && flag1==0){
								SetConsoleTextAttribute(hConsole, azul[z].id_color);
								gotoxy(p1+2,j+1);
								cout<<azul[z].text;
								flag1=1;								
							}
							if(i==verde[z].p1 && j==verde[z].p2 && flag1==0){
								SetConsoleTextAttribute(hConsole, verde[z].id_color);
								gotoxy(p1+2,j+1);
								cout<<verde[z].text;
								flag1=1;								
							}
							if(i==amarillo[z].p1 && j==amarillo[z].p2 && flag1==0){
								SetConsoleTextAttribute(hConsole, amarillo[z].id_color);
								gotoxy(p1+2,j+1);
								cout<<amarillo[z].text;
								flag1=1;								
							}
							if(i==naranja[z].p1 && j==naranja[z].p2 && flag1==0){
								SetConsoleTextAttribute(hConsole, naranja[z].id_color);
								gotoxy(p1+2,j+1);
								cout<<naranja[z].text;
								flag1=1;								
							}																					
						}				
				}
		}	 
	}	
	
	int op;
	int flag_firts=0;
	string cadena;

	do{
		if(flag_firts==0){
			gotoxy(0,20);
		}
			cout<<".:MENU DE OPCIONES:."<<endl;
			cout<<"Op1. Insertar Matriz en Arbol Binario"<<endl;
			cout<<"Op2. Mostrar Registros guardados en el arbol"<<endl;
			cout<<"Op3. Salir"<<endl;
			cout<<"Digite una Opcion [1-3]: ";
			cin>>op;
			switch(op){
				case 1:
					bcount=0; azcount=0; vcount=0; amcount=0; ncount=0; 			
					for(int i=0;i<16;i++){
						for(int j=0;j<16;j++){
							if (matriz2[i][j]==11){
								insertarNodo(	
								arbol,
								azul[azcount].id_decimal,
								azul[azcount].id_color,
								azul[azcount].hexadecimal	);
								azcount++;
							}
							else if (matriz2[i][j]==2){
								insertarNodo(
								arbol,
								verde[vcount].id_decimal,
								verde[vcount].id_color,	
								verde[vcount].hexadecimal	);
								vcount++;
							}
							else if (matriz2[i][j]==14){
								insertarNodo(
								arbol,
								amarillo[amcount].id_decimal,
								amarillo[amcount].id_color,
								amarillo[amcount].hexadecimal	);
								amcount++;		
								}
							else if (matriz2[i][j]==4){
								insertarNodo(
								arbol,
								naranja[ncount].id_decimal,
								naranja[ncount].id_color,
								naranja[ncount].hexadecimal	);
								ncount++;				
							}	
							else{
								insertarNodo(
								arbol,
								blanco[bcount].id_decimal,
								blanco[bcount].id_color,
								blanco[bcount].hexadecimal	);
								bcount++;
							}						
						}	 
					}					
					break; 
				
				case 2: 
					cout<<endl<<"Mostrando el arbol: \n\n";
					mostrarArbol(arbol,contador);
					getch();
					break; 

				case 3: 
					break; 

				default:
					cout<<endl<<"Digite un valor valido";
					getch();
					break;
			}
		flag_firts=1;
		system("cls"); system("cls");
	}while(op!=3);

	getch();
	return 0;
}