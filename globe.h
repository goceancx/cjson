#define JSON_STR_LENGTH  1000
#define T_JSON 1
#define T_JSON_ARRAY 2
#define T_INT 3
#define T_STR 4
#define T_EXCEPTION 5

char jsonstr[JSON_STR_LENGTH];
void echo(char* str);
const char COLON=':';
const char BRACE_LEFT='{';
const char BRACE_RIGHT='}';
const char BRACKET_LEFT='[';
const char BRACKET_RIGHT=']';
const char COMMA =',';
const char D_QUOTES='"';

void echo_c(char c){
	printf("%c\n",c);
}

bool is_white(char c){
	if(c==' '|| c=='\n' || c=='\t'){
		return true;
	}
	return false;
}
char* skip_white(char *s ){
	char*p = s;
	while(p!=NULL){

		char c= *p;
		if(is_white(c)){
			p++;
		}else{
			break;
		}

	}
	return p;
}

void echo(char*   str){
	printf("%s\n",str);
}

