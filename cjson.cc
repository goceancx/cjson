#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include"globe.h"
#include"stack.h"
#include"json.h"
using namespace std;


void parseJson(char* json , JSON* node){
	/*
		对JSON进行解析
	*/

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
	for(;*pjson!='\0';pjson++){
		char c= *pjson;
		if(is_white(c)){
			pjson=skip_white(pjson);
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
		
	parseJson(jsonstr,root);
	// for(;*pjson!='\0';pjson++){
	// 	char c=*pjson;
	// 	switch( c){
	// 	case ':':
	// 		break;
	// 	case '{':
	// 		break;
	// 	case '}':
	// 		break;
	// 	case '[':
	// 		break;
	// 	case ']':
	// 		break;
	// 	case ',':
	// 		break;
	// 	case '\"':
	// 		break;
	// 	}
	// }
		
	
	return 0;
}

