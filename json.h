/**
 *	json 自定义文件
 * 
*/

typedef struct KVNode_TYPE
{
	char* key;
	void* val;
	int type;
	struct KVNode_TYPE* next;
}KVNode;

typedef struct StrNode_TYPE
{
	char* s;
	int type;
	int len;
	struct StrNode_TYPE* next;
	struct StrNode_TYPE* prev;
}StrNode;

// class JSONParser
// {
// private:
// 		void trim(char *s){
// 			char*p = s;
// 			for(char *t=s;*t!='\0';t++){
// 				if(!isspace(*t)){
// 					*s++=*t;		
// 				}
// 			}
// 			*s='\0';
// 			s=p;
// 			printf("%s\n", p);
// 		}

// 		bool isspace(char c){
// 			if(c==' '||c=='\t'||c=='\n')return true;
// 			else return false;
// 		}
	

// 	int cauculateKvcnt(char *s){
// 		int kvcnt=0;
// 		int stack[100],top=0;
// 		for(int i = 0 ;i< strlen(s);i++){
// 			char c= s[i];
// 			if(c=='{'){
// 				stack[top++]=i;
// 			}else if(c=='}'){
// 				int pre_i = stack[--top];
// 				for(int j = pre_i;j<=i;j++){
// 					/**
// 					*/

// 				}
// 				kvcnt++;
// 			}
// 		}
// 	}



// 	JSON* parseJson(char* s,int l,int r){
// 		JSON* json = new JSON();	//存储这个要被解析的JSON字符串
// 		KVList list=new KVList();
// 		while(isEndParse(s,l,r)){
// 			char* key = parseKey(s,l,r);
// 			int type = parseValueType(s,l,r);
// 			void* val = parseVal(s,l,r);
// 			list->addKVNode(key,val,type);
// 			kvcnt++;
// 		}
		
// 	}

// 	JSON* parseJsonArray(){

// 	}
// public:
// 	JSONParser(char *s){
// 		trim(s);
// 		if(c=='{')
// 			pJson=parseJson(s);
// 		else 
// 			pJson=parseJsonArray(s);
// 	};
// 	~JSONParser();
// 	void* pJson;
	
// };



class JSON {
	private:
		
	public:
		char *str;
		int kvcnt;		// 此Json包含的键值对
		//char** keys;	// Json中包含的键集合
		//void** vals;	// Json中包含的值集合
		//int* types;		// 当前val种类,包括 str,json,jsonarray,int,bool(回头加)
		KVNode *kvlist;

		JSON* next;
		JSON(){
	
		}
		~JSON(){


		}

		void addKeyVal(char *key,void *val,int type){
			KVNode* node =new KVNode();
			node->key =key;
			node->val = val;
			node->type = type;
			if(kvlist==NULL){
				kvlist=node;
				kvlist->next=NULL;
			}else{
				node->next=kvlist;
				kvlist=node;
			}
			kvcnt++;
		}

		void print(int dep){

			// bool first=true;
			// putchar('{');
			// putchar('\n');
			
			// for(int i=0;i<index;i++){
			// 	if(keys[i]!=NULL){
			// 		echo_t(dep);
			// 				printf("\"%s\":", keys[i]);
			// 	}
			// 	switch(types[i]){
			// 		case T_JSON:{
			// 			JSON* json = (JSON*)vals[i];		
			// 			json->print(dep+1);
			// 		}
			// 			break;
			// 		case T_JSON_ARRAY:{
			// 			JSON** pAry = (JSON **)vals[i];
						
			// 			bool first=true;
			// 			putchar('[');
			// 			while(*pAry!=NULL){
			// 				if(first){
			// 					(*(pAry++))->print(dep+1);
			// 					first=false;
			// 				}else{
			// 					putchar(',');
			// 					(*(pAry++))->print(dep+1);
			// 				}

			// 			}
			// 			putchar(']');
			// 		}
			// 			break;
			// 		case T_INT:{
						
			// 			echo((char*)vals[i]);
			// 		}
			// 			break;
			// 		case T_STR:{
						
			// 			echo((char*)vals[i]);
			// 		}
			// 			break;
			// 		case T_EXCEPTION:{
			// 			printf("T_EXCEPTION: \"%s\":", keys[i]);
			// 		}
			// 			break;
			// 	}
			// 	if(i== index-1){
			// 		putchar('\n');
			// 	}else{
			// 		putchar(',');
			// 		putchar('\n');
			// 	}
			// }
			// 	echo_t(dep-1);
			// 	putchar('}');
		}
		void echo_t(int dep){
			for(int i=0;i<dep;i++){putchar(' ');putchar(' ');}
		}
		void echo(char * s){ 
			printf("%s", s);
		}
		void echo_key(char *key){
			if(key!=NULL){
				// if(*key!=NULL && *key!='\0'){
				// printf("\"%s\": ",key );
				// }
			}
		}

};




