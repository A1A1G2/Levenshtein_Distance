#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define numEl = 5;

void printMx(int **mx,int n,int m);
int getMinNeigh(int** mx,int m,int n);
int** createMx(int n,int m);
int main(){
	char* str1 = "_honda",*str2 = "_hyundai";
	int** mx = createMx(strlen(str1),strlen(str2)); 
	int i,j,k,tmp;
	for(i=0;i<strlen(str1);i++){
		for(j=0;j<strlen(str2);j++){
			if(str1[i] == str2[j]){
				mx[i][j] = getMinNeigh(mx,i,j);
			}else{
				mx[i][j] = getMinNeigh(mx,i,j)+1;
			}
		}
	}
	printMx(mx,strlen(str1),strlen(str2));
}
void printMx(int **mx,int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",mx[i][j]);
		}
		printf("\n");
	}
}

int** createMx(int n,int m){
	int i;
	int **hlpr = (int**) malloc(sizeof(int*)*n);
	for(i = 0;i<n;i++){
		hlpr[i] = (int*) malloc(sizeof(int)*m); 
	}
	return hlpr;
}
int getMinNeigh(int** mx,int m,int n){
	int a=INT_MAX,b=INT_MAX,c=INT_MAX;
	if(n>0){
		c = mx[m][n-1];
		if(m>0){
			a = mx[m-1][n-1];
			b = mx[m-1][n];
		}
	}else if(m>0){
		b = mx[m-1][n];
	}else{
		return 0;
	}
	return (a<=b&&a<=c)?a:(b<=a&&b<=c)?b:c;
}
