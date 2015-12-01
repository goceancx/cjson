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
		int types[20];
//		Object val;
		char* keys[20];
		void* vals[20];		

		void print(int dep){
			putchar('{');
			putchar('\n');
			bool first=true;
			for(int i=0;i<index;i++){
				echo_t(dep);
				echo_key(keys[i]);
				putchar(':');

				switch(types[i]){
					case T_JSON:{
						JSON* json = (JSON*)vals[i];
						dep++;
						json->print(dep);
					}
						break;
					case T_JSON_ARRAY:{

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
				
				putchar('}');
		}
		void echo_t(int dep){
			for(int i=0;i<dep;i++)putchar('\t');

		}
		void echo(char * s){ 
			
			printf("%s", s);
			
		}
		void echo_key(char *key){
			printf("\"%s\"",key );
		}

};



