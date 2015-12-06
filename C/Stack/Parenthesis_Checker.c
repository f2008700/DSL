/* Parenthesis checker.
 */


#include<stdio.h>

int main(){
	FILE *fp=fopen("Set2_IR1_Q2.c","r");
	char c;
	int count=0;
	while((c=getc(fp))!=EOF){
		if(c=='{'){
			count++;
		}else if(c=='}'){
			count--;
		}
		if(count<0){
			printf("Extra '}' encountered\n");
			break;
		}
	}
	if(count>0)
		printf("Extra '{' encountered\n");
	else if(count==0){
		printf("Code is perfect\n");
	}
	return 0;
}
