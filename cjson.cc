#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include"globe.h"
// #include"stack.h"
#include"json.h"
#include"jsonArray.h"
using namespace std;

/**
重新写解析Json
1. 先把Json读一遍 确定分配空间
2. 再读一遍,进行parse
*/


char* parseKey(char *s,char** addr){
	int len=0; 	
	if(*s=='\"'){
		s++;
	}
	for(char*p=s;*(p-1)!='\\'&& *p!='\"';p++)len++;

	if(len == 0)return NULL;

	char* key = new char(len+1);
	char* p = s;
	for(int i=0;i<len;i++){
		key[i]=*(p+i);
	}
	key[len]='\0';
	// s=s+len+1;		//offset s to ':'
	*addr=(*addr+len+3);
	printf("len : %d key:%s\n", len ,key);
	return key;
}

char* parseInt(char*s,char **addr){
//	printf("s:%d add:%d\n", s,addr);
	int len=0; 	
	char*p=s;
	for(;*p>='0'&&*p<='9';p++){len++;}
	
	if(len == 0)return NULL;
	char* key = new char(len+1);
	p = s;
	for(int i=0;i<len;i++){
		key[i]=*(p+i);
	}
	key[len]='\0';
	s=s+len;	//offset s to ',' || '}'
	*addr=(*addr+len+1);
	//printf("int:%s len:%d\n", key,len);
	return key;
}

JSON* parseJson(char * s,char** addr);

JSONAry* parseJsonArray(char *s,char **addr){
	char *p = s;
	p++;
	JSONAry* jsonArray=new JSONAry();
	do
	{
		JSON* json = parseJson(p,addr);
		p=*addr;
		jsonArray->addJson(json);
		if(*p==',')p++;
		if(*p==']'){
			p++;
			*addr=(*addr+(p-s));
			break;
		}
	} while (*s!='\0');
	return jsonArray;
}

void* parseVal(char *s, char **addr,int *type){
	char*p = s;
	p++; //skip :
	char c = *p;
	void* val=NULL;
	if(c>='0' && c <='9'){
		*type=T_INT;
		val =(void*) parseInt(p,addr);
		p=*addr;
	}
	else if(c=='\"'){
		*type=T_STR;
		val = (void*)parseKey(p,addr);
		p=*addr;
	}
	else if(c=='{'){
		*type= T_JSON;
		val = (void*)parseJson(p,addr);
		p=*addr;
	}
	else if(c=='['){
		*type= T_JSON_ARRAY;
		val = (void*)parseJsonArray(p,addr);	
		p=*addr;
	}
	else {
		*type =-1;
		val=NULL;
	}
	
	return type;
}



JSON* parseJson(char *s,char** addr){
	char*p=s;
	p++; //skip '{'
	JSON* json = new JSON();
	do
	{
		char *key = parseKey(p,addr);
		p=*addr;
		//printf("p:%d &p:%d\n", p,addr);
		if(key == NULL)break;
		int type=-1;
		void* val = parseVal(p,addr,&type);
		p=*addr;
		if(type==-1){
			printf("type解析出错!\n");
			return NULL;
		}
		json->addKeyVal(key,val,type);
		if(*p==','){
			p++;
		}
		if(*p=='}'){
			p++;
			*addr=(*addr+(p-s));
			break;
		}
	} while (*s!='\0');
	return json;
}


bool isspace(char c){
	if(c==' '||c=='\t'||c=='\n')return true;
	else return false;
}


void trim(char *s){
	char*p = s;
	for(char *t=s;*t!='\0';t++){
		if(!isspace(*t)){
			*s++=*t;		
		}
	}
	*s='\0';
	s=p;
	printf("%s\n", p);
}


int main(){
	char c;
	int index=0;
	
	while((c= getchar())!=EOF){
		jsonstr[index++] = c;
	}
	jsonstr[index]='\0';
	trim(jsonstr);
	char *s=jsonstr;
	parseJson(s,&s);
	
	
	return 0;
}

