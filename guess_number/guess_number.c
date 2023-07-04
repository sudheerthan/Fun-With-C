#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int max,min,randomNum,temp,num,attempt=0;
	srand(time(NULL));
	printf("\n******** GUESS THE NUMBER GAME *********\n");
	printf("enter the number range\n");
	printf("enter the max value\n");
	scanf("%d",&max);
	printf("enter the min value\n");
	scanf("%d",&min);
	if(min>max){
	temp = max;
	max = min; 
	min = temp;}
	printf("max = %d min =%d\n",max,min);	
	randomNum = rand() % (max-min+1)+min;
	do{
	again:
		printf("guess a number\n");
		scanf("%d",&num);
		if(num < min || num > max){
			printf("please enter the number between the range\n");
			goto again;
		}
		if(num > randomNum){
			printf("\n TOO HIGH !!!!!! try again \n");	
			attempt ++;	
		}
		else if(num < randomNum){
			printf("\n TOO LOW !!!!!! try again \n");		
			attempt ++;
		}
		else{
			printf("\n!!!!!!! YOU WIN !!!!!!\n");;
			printf("attempts %d\n",attempt);}
	}while(num!=randomNum);
}
