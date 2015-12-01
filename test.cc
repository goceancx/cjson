#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	char* c= new char(10);
	*c ='t';
	c[1]='d';
	c[2]='\0';

	for(int i=0;i<2;i++){
		printf("%d",&c[i]);
	}
	printf("%d",c);
	char** cc;
	void ** ccv;
	cc=&c;
	ccv=(void **)  cc;
	printf("\n%s", *((char **)ccv));

	return 0;
}
