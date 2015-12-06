/*
 * Set4_R1_Q1.c
 *
 *  Created on: 28-Aug-2015
 *      Author: vikas
 *
 *  Given a 2D array containing only 0/1’s and each row is in sorted order.
 *  Find the row which contains maximum number of 0s.
 */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>

void print_array(int **a, int l, int b);
void create_array(int **a, int l, int b);
int binary_search(int *a, int start, int end);

int main(){
	int l=40,b=40,i,index,temp,row;
	int **a=(int **)malloc(sizeof(int *) * l);
	create_array(a,l,b);
	print_array(a,l,b);
	index=binary_search(a[0], 0,b);
	printf("Index: %d, a[%d]:%d\n",index,index,a[0][index]);
	for(i=1;i<l;i++){
		temp=binary_search(a[i],0,index);
		printf("Index: %d\n",temp);
//		sleep(1);
		if(temp<index){
			index=temp;
			row=i;
		}
	}
	printf("Row: %d",row);
	return 0;
}

int binary_search(int *a, int start, int end){
	while((start+1)<end){
		if(a[(start+end)/2]==0){
			start=(start+end)/2;
		}else{
			end=(start+end)/2;
		}
//		sleep(1);
//		printf("Start: %d, End:%d\n",stasrt,end);
	}
	if((start+1==end) && (a[start+1]==1)){
//		printf("1\n");
		return start+1;
	}
	else {
//		printf("2\n");
		return start;
	}
}

void create_array(int **a, int l, int b){
	int i,j,r;
	srand(clock());
	for(i=0;i<l;i++){
		a[i]=malloc(sizeof(int)*b);
		r=(int)rand();
		r=r%b;
		for(j=0;j<r;j++){
			a[i][j]=0;
		}
		for(;j<b;j++){
			a[i][j]=1;
		}
	}
}

void print_array(int **a, int l, int b){
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<b;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
