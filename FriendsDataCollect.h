#ifndef FRI_DATE
#define FRI_DATE

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 朋友关系对的结构
struct  friendspair
{
	string str1;
	string str2;
};

// 关系对的缓冲存储结构
struct buffefFriend
{
	friendspair *pairs;
	int length;
	void Append(string s1,string s2){
		pairs[length].str1 = s1;
		pairs[length].str2 = s2;
		length++;
	}
	
	buffefFriend(){
		pairs = new friendspair[30000];
	}
};

// 所涉及成员的列表结构
struct FriDatas{
	string *matrix;
	int length;
	void Append(string s){
		if (exist(s)){
			return ;
		}else{
		matrix[length] = s;
		length ++;
		}
	}
	// 对重复出现的人进行去重
	bool exist(string s){
		for (int i = 0;i<length;i++){
			if (matrix[i]==s){
				return true;
			}
		}
		return false;
	}
};


// 朋友关系对 与 相关人员的收集与缓存
class FriendsDataCollector{
public:
	FriDatas friData;
	buffefFriend friPairs;
	FriendsDataCollector(){
		friData.length = 0;
		friData.matrix = new string[1000];
		friPairs.length = 0;
		friPairs.pairs = new friendspair[30000];
	}
	void FriCollect(string text){
		ifstream fin(text.c_str());
		string s;
		if(!fin){
			cout<<text<<" Read ERROR"<<endl;
		}
		cout<<"Please wait,the Friends date is collecting ... "<<endl;
		string s1,s2;
		int count = 0;
		while (fin>>s)
		{
			friData.Append(s);
			if(count%2==0){
				s1 = s;
			}
			else{
				s2 = s;
				friPairs.Append(s1,s2);
			}
			count ++;
			if (count%10000==0)
			{
				cout<<"Collecting "<<count<<" dates"<<endl;
			}
		}
		cout<<"The num of the people is "<<friData.length<<endl;
		cout<<"The num of the pairs is "<<friPairs.length<<endl;
	}
};

#endif
