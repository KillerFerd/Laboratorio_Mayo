//***Matriz de Compatibilidad de las 16 Personalidades
//***Desarrollador: KillerFerd
//***Curso: Programación III
// Una matriz de 16*16
// Una visualizacion de 5 colores blanco(7) celeste(11) verde(2) amarillo(14) naranja(4)
// Personalidades: ISTJ ISFJ ESTJ ESFJ ISTP ISFP ESTP ESFP INFJ INFP ENFP ENFJ INTJ INTP ENTP ENTJ
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

struct personalidades{
	string arq;
}per[15];

int main()
{
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	system("cls");
	char matriz[16][16], flag1=0;
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

	per[0].arq=">ISFJ";  per[1].arq=">ISTJ";  per[2].arq=">ESTJ";  per[3].arq=">ESFJ"; per[4].arq=">ISTP";  per[5].arq=">ISFP";
	per[6].arq=">ESTP";  per[7].arq=">ESFP";  per[8].arq=">INFJ";  per[9].arq=">INFP"; per[10].arq=">ENFP"; per[11].arq=">ENFJ";
	per[12].arq=">INTJ"; per[13].arq=">INTP"; per[14].arq=">ENTP"; per[15].arq=">ENTJ";
		
	system("cls");
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		{
			matriz[i][j]='x';
		}
	}

	for(int i=0, p1=5;i<16,p1<100;i++,p1=p1+6)
	{
		for(int j=0;j<16;j++)
		{
			flag1=0;
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(p1,0);
			cout<<per[i].arq;	
			SetConsoleTextAttribute(hConsole, 7);
			gotoxy(0,i+1);
			cout<<per[i].arq;	

				SetConsoleTextAttribute(hConsole, matriz2[i][j]);
				gotoxy(p1+2,j+1);	
				cout<<matriz[i][j]; 	

		}	 
	}	

	getch();
	return 0;
}
