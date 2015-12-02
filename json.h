/**
 *	json 自定义文件
 * 
*/

typedef char* String;
typedef char** StringArray;
typedef void* Object;
typedef void** ObjectArray;


class JSON {
	public :
		int index;
//		StringArray key;
		int types[10];
//		Object val;
		char* keys[LESS];
		void* vals[LESS];		



		void printJsonArray(JSON **pJsonAry){

		}
		void print(int dep){

			bool first=true;
			putchar('{');
			putchar('\n');
			echo_t(dep);
			for(int i=0;i<index;i++){
				if(keys[i]!=NULL){
							printf("\"%s\":", keys[i]);
				}
				switch(types[i]){
					case T_JSON:{
						JSON* json = (JSON*)vals[i];		
						json->print(dep+1);
					}
						break;
					case T_JSON_ARRAY:{
						JSON** pAry = (JSON **)vals[i];
						
						//printJsonArray(pAry);
						bool first=true;
						putchar('[');
						while(*pAry!=NULL){
							if(first){
								(*(pAry++))->print(dep+1);
								first=false;
							}else{
								putchar(',');
								(*(pAry++))->print(dep+1);
							}

						}
						putchar(']');
					}
						break;
					case T_INT:{
						
						echo((char*)vals[i]);
					}
						break;
					case T_STR:{
						
						echo((char*)vals[i]);
					}
						break;
					case T_EXCEPTION:{
						printf("T_EXCEPTION: \"%s\":", keys[i]);
					}
						break;
				}
				if(i== index-1){
					putchar('\n');
				}else{
					putchar(',');
					putchar('\n');
				}
			}
				echo_t(dep-1);
				putchar('}');
		}
		void echo_t(int dep){
			for(int i=0;i<dep;i++){putchar(' ');putchar(' ');}
		}
		void echo(char * s){ 
			printf("%s", s);
		}
		void echo_key(char *key){
			if(key!=NULL){
				if(*key!=NULL && *key!='\0'){
				
				printf("\"%s\": ",key );

			}
			}
			
		}

};



