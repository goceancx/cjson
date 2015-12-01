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

};



