#ifndef List_
#define List_

#include "AtDataCollect.h"
#include "FriendsDataCollect.h"
struct Member
{
	string value;
	int key;
	Member(){	
		key = 0;
	}
};
class PeopleList{
public:
	AtDataCollector atCollector;
	FriendsDataCollector friCollector;
	PeopleList(){
		length = 0;
		friCollector.FriCollect("newfriends.txt");
		atCollector.AtCollect("at.txt");
		list = new Member[1000];
		for(int i =0;i< friCollector.friData.length;i++){
			int Index = Hash(friCollector.friData.matrix[i]);
			//cout<<Hash(friCollector.friData.matrix[i])<<endl;
			Member *p = new Member;
			while (list[Index].key>0)
			{
				Index ++;
				//cout<<"index:"<<Index<<endl;
			}
			p->key = Index;
			p->value = friCollector.friData.matrix[i];
			list[Index] = *p;
			length++;
		}
		cout<<"The total num of people -> "<<length<<endl;
	}
	inline int Hash(string key){
		int hash = 0;
		for(int i =0;i<key.length();i++){
			hash += (hash << 5) + int(key[i])-1;  
		}
		return (hash & 0x2FF);
	}
	inline int FindIndex(string key){
		int Index = Hash(key);
		while(list[Index].value!=key){
			if(Index>=850)return -1;
			Index++;
		}
		return Index;
	}
    Member* list;
	int length;
};
#endif