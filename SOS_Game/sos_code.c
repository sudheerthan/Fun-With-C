#include <stdio.h>
#include <stdlib.h>
volatile char a[10];
int b,s_var,count,win;
int p1=0,p2=0;
int v[10],mrr[20];
static int i=0;

void arr_func(){
printf("\n");
	printf(" %c | %c | %c\n",a[1],a[2],a[3]);
	printf("- -|- -|- -\n");
	printf(" %c | %c | %c \n",a[4],a[5],a[6]);
	printf("- -|- -|- -\n");
	printf(" %c | %c | %c\n",a[7],a[8],a[9]);
	printf("\n");
}
void arr_sel_p1(int s){
	p1 == 1 ? (a[s] = 'X') : (a[s] = 'O');
	arr_func();	
}
int repeat_check(int l){
	mrr[i]=l;
	for(int h=0;h<i;h++){
          if(mrr[h]==mrr[i])
          return 1;
	}i++;
	return 0;
}
void arr_sel_p2(int s){
	p2 == 2 ? (a[s] = 'O') : (a[s] = 'X');
	arr_func();	
}
void p1_call(){
	printf("\n player 1 enter a num\n");
	scanf("%d",&s_var);
	int k = repeat_check(s_var);
	if(k==1){printf("number is already taken ,sorry!!! \n");
	p1_call();}
	if(s_var < 10 && s_var > 0)
		arr_sel_p1(s_var);
	else{
		printf("enter a number b/w 0 - 9\n");
		p1_call();
	}
}
void p2_call(){
	printf("\n player 2 enter a num\n");
	scanf("%d",&s_var);
	int j = repeat_check(s_var);
	if(j==1){printf("number is already taken ,sorry!!! \n");
	p2_call();}
	if(s_var < 10 && s_var > 0)
		arr_sel_p2(s_var);
	else{
		printf("enter a number b/w 0 - 9\n");
		p2_call();
	}
}
void comp_val(){
	v[1]=a[1]|a[2]|a[3];
	v[2]=a[4]|a[5]|a[6];
	v[3]=a[7]|a[8]|a[9];
	v[4]=a[1]|a[4]|a[7];
	v[5]=a[2]|a[5]|a[8];
	v[6]=a[3]|a[6]|a[9];
	v[7]=a[1]|a[5]|a[9];
	v[8]=a[3]|a[5]|a[7];
	if (p1 == 1) {
    	for (int i = 1; i <= 8; i++) {
        	if (v[i] == 88) {
        	    win = 1;
        	    break;}}
    	for (int i = 1; i <= 8; i++) {
        	if (v[i] == 79) {
        	    win = 2;
        	    break;}}}
	if (p1 == 2) {
    	for (int i = 1; i <= 8; i++) {
        	if (v[i] == 88) {
        	    win = 3;
        	    break;}}
    	for (int i = 1; i <= 8; i++) {
        	if (v[i] == 79) {
        	    win = 4;
        	    break;}}}      
    switch(win){
    	case 1: printf("player 1 -X- WIN !!!");
    	exit(1);
    break;
        case 2: printf("player 2 -O- WIN !!!");
        exit(1);
    break;
        case 3: printf("player 2 -X- WIN !!!");
        exit(1);
    break;
        case 4: printf("player 1 -O- WIN !!!");
        exit(1);
    break;
    }
}

int main(){
	for(int i = 1 ; i< 10; i++)
	a[i]=i+'0';
	arr_func();
	printf("for player 1 select a num\n");
	printf("  1. X ");
	printf("  2. O \n");
	scanf("%d",&b);
	if(b == 1){
		printf(" player 1 : X \t");
		p1 = 1;
		printf(" player 2 : O \n");
		p2 = 2;
	}
	if(b == 2){
		printf(" player 1 : O \t");
		p1 = 2;
		printf(" player 2 : X \n");
		p2 = 1;
	}
	printf("\n");
	arr_func();
	p1_call();
	p2_call();
	p1_call();
	p2_call();	
	comp_val();
	p1_call();
	comp_val();
	p2_call();
	comp_val();
	p1_call();
	comp_val();
	p2_call();
	comp_val();
	/*p1_call();
	comp_val();
	p2_call();
	comp_val();*/
    	printf("better luck next time !!!");
	arr_func();
	
}
