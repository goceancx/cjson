class JSONAry
{
public:
	JSONAry(){

	}
	~JSONAry(){
		
	}
	JSON* jsons;
	int jcnt;
	void addJson(JSON* json){
		if(json == NULL)return;
		if(jsons==NULL){
			jsons=json;
			jsons->next=NULL;
		}
		else {
			json->next = jsons;
			jsons=json; 
		}
		jcnt++;
	}
	
};
