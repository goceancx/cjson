#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"globe.h"
#include"stack.h"
#include"json.h"
using namespace std;


char * parseKey(char* s,char** addr){
	char* key = new char[100];
	char* p=key;
	s++;
	for(; *(s-1)!='\\' && *s!='\"' ;*p++=*s++);
	*(++p)='\0';
	
	*addr = s;
	printf("key:%s\t",key);

	return key;
}
void* parseInt(char* val,char** addr){
	char*pint = new char[100];
	char * p = pint;
	while( (*val-'0') >= 0 && (*val-'0')<=9){
		*p++=*val++;
	}
	*(p)='\0';
	--val;
	*addr =val;
	printf("val:%s\n",pint);
	return (void*)pint;
}
void* parseNoString(char* val){
	void* v;
	return v;
}


void* parseJsonArray(char* jsonarray){
	JSON* pjson[10];
	for(int i=0;i<10;i++)
	{
	  JSON* pj= new JSON();
	  	pjson[i]=pj;
	}
	//JSON** ppjson = ;
	JSON** ppjson ;
	ppjson =  pjson;
	return (void*)ppjson;
}

void * parseString(char* s,char** addr){
	
	char* pval= new char[100];
	char* p = pval;
	*p++='\"';
	s++;
	for(; *(s-1)!='\\' && *s!='\"' ;*p++=*s++);
	*p='\"';
	*(++p)='\0';
	//echo(key);
	*addr = s;
	printf("val:%s\n",pval);
	return (void*) pval;
}
void* parseJson(char* json,char** addr){
	/*
		对JSON进行解析
	*/
	JSON* node =new JSON();
	node->index=0;
	
	bool firstReadBrace=true;
	bool firstReadBracket=true;
		bool bParseKey = false;
	for(char* pjson =json ; *pjson!='\0'; pjson++){
		char c= *pjson;
		int idx = node->index;
		switch(c){
			case '{':
			{
				if(!firstReadBrace){
					node->types[idx] = T_JSON;
					node->vals[idx]=parseJson(pjson,&pjson);
					
					node->index++;
					bParseKey = false;
				}
				firstReadBrace=false;
				break;
			}
			case '}':
			{
				*addr=pjson;
				return (void*)node;
				break;
			}
			case '[':
			{
				if(!firstReadBracket){
					node->types[idx]=T_JSON_ARRAY;
					node->vals[idx]=parseJsonArray(pjson);
					node->index++;
					bParseKey= false;
				}
				firstReadBracket=false;
			}
			break;
			case '\"':
			{	
				if(!bParseKey){
					// 对key进行parse
					node->keys[idx]=parseKey(pjson,&pjson);
					bParseKey = true;	
				}else{
					node->types[idx] = T_STR;
					node->vals[idx] = parseString(pjson,&pjson);
					node->index++;
					bParseKey = false;
				}
				break;
			}
			case ':':
			{
			//	printf("addr:%d :\n",pjson  );
				bParseKey = true;
				break;
			}
			case ',':
			{
				bParseKey = false;
				break;
			}
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
			//	echo("readInt");
				node->types[idx]= T_INT;
				node->vals[idx] = parseInt(pjson,&pjson);
				node->index++;
				bParseKey = false;
				break;
			}
			default:
			{
				//其他类型的val 存储成字符串
				node->types[idx]= T_EXCEPTION;
				node->vals[idx] = parseNoString(pjson);
				node->index++;
				bParseKey= false;
				break;
			}
		}
	
	}
	return (void*)node;
	
}




int main(){
	char c;
	int index=0;
	while((c= getchar())!=EOF){
		jsonstr[index++] = c;
	}
	jsonstr[index]='\0';
	char* pjson=jsonstr;
	index=0;

	
	int metQts= 0;

	for(;*pjson!='\0';pjson++){
		char c= *pjson;
		if( c=='\"' && *(pjson-1) !='\\' ){
			metQts++;
		}
		
		if(metQts%2==0 && is_white(c)){
			
			pjson=skip_white(pjson);
			pjson--;
			continue;	
		}
		
			jsonstr[index++]=*pjson;

	//	putchar(*pjson);
	}
	jsonstr[index]='\0';
	int top_jsonstr= index;
	int bottom_jsonstr=0;

	echo(jsonstr);
	// trim Json  完毕
	/*
	对JSON串进行解析 输入key val对
	利用栈 先逐个字符读入,然后匹配
	*/
	Stack s;
	pjson = jsonstr;

	JSON* root;
	char ** addr= &pjson;	
	root=(JSON*) parseJson(jsonstr,addr);
	root->print(0);
		
	
	return 0;
}

