#define JSON_STR_LENGTH  1000


struct Stack{
	char stack[JSON_STR_LENGTH];
	int top;
	
	public:
	void push(char c){
		stack[top++]=c;
	}
	 char pop(){
		return stack[top--];
	}
	 void clear(){
		top=0;
	}
	void print(){
		for(int i=0;i<top;i++){
			putchar(stack[i]);
		}
		putchar('\n');
	}
};

