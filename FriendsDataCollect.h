#ifndef FRI_DATE
#define FRI_DATE

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct  friendspair
{
	string str1;
	string str2;
};

struct buffefFriend
{
	friendspair *pairs;
	int length;
	void Append(string s1,string s2){
		pairs[length].str1 = s1;
		pairs[length].str2 = s2;
		length++;
	}
	/*bool exist(string s1,string s2){
		for (int i = 0; i < length; i++){
			if (pairs[i].str1==s1&&pairs[i].str2==s2){
				return true;
			}
		}
		return false;
	}*/
	buffefFriend(){
		pairs = new friendspair[30000];
	}
};
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
	bool exist(string s){
		for (int i = 0;i<length;i++){
			if (matrix[i]==s){
				return true;
			}
		}
		return false;
	}
};


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

/*
int main(){
		Select("newfriends.txt");
		system("pause");
}
*/
#endif
