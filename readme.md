简单的解析JSON对象

测试:

	g++ cjson.cc;./a.out<test.txt


结果:

	{"mode":2,"rec":[{"id":"v200014","miojiTag":"推荐","rec":"Hello PHP"},{"id":"v200014","miojiTag":"推荐","rec":"Hello PHP"},{"id":"v200014","miojiTag":"推荐","rec":"Hello PHP"}],"img":"http://mioji.attr.kssws.ks-cdn.com/v200014_1.jpg","tag":"教堂|广场","score":"9.65","name":"威尼斯圣马可大教堂"}
	key:mode	val:2
	key:rec	key:id	val:"v200014"
	key:miojiTag	val:"推荐"
	key:rec	val:"Hello PHP"
	---节点返回----
	key:id	val:"v200014"
	key:miojiTag	val:"推荐"
	key:rec	val:"Hello PHP"
	---节点返回----
	key:id	val:"v200014"
	key:miojiTag	val:"推荐"
	key:rec	val:"Hello PHP"
	---节点返回----
	key:img	val:"http://mioji.attr.kssws.ks-cdn.com/v200014_1.jpg"
	key:tag	val:"教堂|广场"
	key:score	val:"9.65"
	key:name	val:"威尼斯圣马可大教堂"
	---节点返回----
	{
	  "mode":2,
	"rec":[{
	    "id":"v200014",
	"miojiTag":"推荐",
	"rec":"Hello PHP"
	  },{
	    "id":"v200014",
	"miojiTag":"推荐",
	"rec":"Hello PHP"
	  },{
	    "id":"v200014",
	"miojiTag":"推荐",
	"rec":"Hello PHP"
	  }],
	"img":"http://mioji.attr.kssws.ks-cdn.com/v200014_1.jpg",
	"tag":"教堂|广场",
	"score":"9.65",
	"name":"威尼斯圣马可大教堂"
	}
