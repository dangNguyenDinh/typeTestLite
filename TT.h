#ifndef HEADER_FILE
#define HEADER_FILE

#include<stdio.h>
#include<string.h>
#include<windows.h>


void deleteLast(char word[]);
int convertFromStringToMatrix(char src[], char srcMtx[][20]);
void gotoxy(int x, int y);
void addLast(char word[], char c);
void redChange();
void greenChange();
void blueChange();
void defaultChange();
int checkString(char right[], char current[], int n);
void changeSystemConsole();


int convertFromStringToMatrix(char src[], char srcMtx[][20]){
	int i,j = 0,count = 0;
	for(i = 0; src[i] != '\0'; i++){ // Chuyen thanh mang cac string
		if(src[i]==' '||src[i]=='\0'){
			srcMtx[count++][j] = '\0';
			j = 0;
		}
		else{
			srcMtx[count][j]=src[i];
            j++;
		}
	}
	return ++count;
}

void gotoxy(int x, int y){
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void deleteLast(char word[]){
	int len = strlen(word)-1;
	word[len] = '\0';
}

void addLast(char word[], char c){
	int len = strlen(word);
	word[len] = c;
	word[len+1] = '\0';
}

void redChange(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); 
}
void greenChange(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); 
}
void blueChange(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); 
}

void defaultChange(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
int checkString(char right[], char current[], int n){
	if(strncmp(right, current, n)){
		redChange();
		return 1;
	}else{
		greenChange();
		return 0;
	}
}
void changeSystemConsole(){
	SMALL_RECT windowSize = {0, 0, 79, 19}; 
    COORD bufferSize = {80, 20};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize); 
    SetConsoleScreenBufferSize(hConsole, bufferSize);
}


#endif
