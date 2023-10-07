#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"TT.h"

int main(){
	changeSystemConsole();
	srand(time(NULL));
	gotoxy(33,2);
	blueChange();
	printf("TYPE TEST");
	defaultChange();
	gotoxy(28,3);
	printf("Press space to start");
	//testCase while
	char control;
	control = getch();	
	while(control == 32){	
		//open source file to read the data
		FILE* source;
		source = fopen("source.txt", "r");
		if(source == NULL){
			printf("\nLoi tao hoac mo file");
			exit(0);
		}
		char sourceString[1000000];
		fgets(sourceString, sizeof(sourceString), source);
		//puts(sourceString);
		
		//convert string to matrix
		char sourceMatrix[10000][20];
		int wordCount = convertFromStringToMatrix(sourceString, sourceMatrix);
		//use while and sleep to count time
		int timeEnd = 6000;
		char currentWord[20]; strcpy(currentWord, "");
		char rightWord[20]; strcpy(rightWord, "hello");
		int ready = 1;
		int currentChar = 0;
		int wrongCount = 0, rightCount = 0;

		//setup background
		int i;
		gotoxy(0,3);
		for(i=0;i<80;i++){
			printf("=");
		}
		gotoxy(0,15);
		for(i=0;i<80;i++){
			printf("=");
		}
		gotoxy(0,7);
		for(i=0;i<80;i++){
			printf("=");
		}
		gotoxy(20,13);
		for(i=0;i<50;i++){
			printf(" ");
		}
		gotoxy(20,14);
		for(i=0;i<50;i++){
			printf(" ");
		}
		while(timeEnd){
			Sleep(1);
			timeEnd--;
			
			if(timeEnd%100 == 0){
				gotoxy(0,0);
				for(i=0;i<50;i++){
					printf(" ");
				}
				gotoxy(0,0);	
				defaultChange();
				printf("TIME LEFT: %d", timeEnd/100);
			} 
			
			if(ready == 1){
				ready = 0;
				//reset the console and ready to display the word
				defaultChange();
				gotoxy(35,5);
				int i;	
				for(i=0;i<40;i++){
					printf(" ");
				}
				gotoxy(35,5);
				puts(rightWord);
				gotoxy(35,8);
				for(i=0;i<40;i++){
					printf(" ");
				}
				currentChar = 0;
				gotoxy(35,8);
				
				
				//count the wrong and right words
				
			}
			//if keyboard hit
			if(kbhit()){
				//let player enter word till "\n"
				char c = getch();
				//if the char is enter
				if(c == 32){
					ready = 1;
					//check the word
					if(checkString(rightWord, currentWord, currentChar) == 0){
						rightCount++;
					}else{
						wrongCount++;
					}
					//random a word for new round
					int random = rand()%wordCount;
					strcpy(currentWord, "");
					strcpy(rightWord, sourceMatrix[random]);
					
				}else if(c == 8){
					if(currentChar > 0){
						deleteLast(currentWord);
						gotoxy(--currentChar+35,8);
						printf(" ");
						gotoxy(currentChar+35,8);
					}	
				}else{
					addLast(currentWord, c);
					gotoxy(35+currentChar++,8);
					checkString(rightWord, currentWord, currentChar);
					printf("%c", c);	
				}
				
				
			}
		}
			
		//display the result
		gotoxy(25,13);
		defaultChange();
		printf("wrong: %d, right: %d, WPM: %d\n", wrongCount, rightCount, rightCount);
		
		
		
		//eclose the file
		close(source);
		gotoxy(25,14);
		printf("Want to try again?(y/n): ");
		fflush(stdin);
		scanf("%c",&control);
		if(control == 'y') control = 32;
	}
	gotoxy(26,15);
	return 0;
} 
