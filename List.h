#ifndef List_
#define List_

#include "AtDataCollect.h"
#include "FriendsDataCollect.h"
// Hash存储结构的结点
struct Member
{
	string value;
	int key;
	Member(){	
		key = 0;
	}
};

// 所有信息的存储类
class PeopleList{
public:
	AtDataCollector atCollector;
	FriendsDataCollector friCollector;
	Member* list;
	int length;
	
	PeopleList(){
		length = 0;
		friCollector.FriCollect("newfriends.txt");
		atCollector.AtCollect("at.txt");
		
		list = new Member[1000];
		// 数据的收集
		for(int i =0;i< friCollector.friData.length;i++){
			int Index = Hash(friCollector.friData.matrix[i]);
			Member *p = new Member;
			while (list[Index].key>0)
			{
				Index ++;
			}
			p->key = Index;
			p->value = friCollector.friData.matrix[i];
			list[Index] = *p;
			length++;
		}

		cout<<"The total num of people -> "<<length<<endl;
	}
	// Hash函数
	inline int Hash(string key){
		int hash = 0;
		for(int i =0;i<key.length();i++){
			hash += (hash << 5) + int(key[i])-1;  
		}
		return (hash & 0x2FF);
	}
	// 根据ID找到对应的index
	inline int FindIndex(string key){
		int Index = Hash(key);
		while(list[Index].value!=key){
			if(Index>=850)return -1;
			Index++;
		}
		return Index;
	}
};
#endif