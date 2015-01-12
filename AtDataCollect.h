#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// At关系的存储结构
struct atpair
{
	string str1;
	string str2;
};

// 将AT关系存入内存
struct bufferAt{
	atpair *pairs;
	int length;
	bufferAt(){
		pairs = new atpair[2500];
	}
	void Append(string s1,string s2){
		pairs[length].str1 = s1;
		pairs[length].str2 = s2;
		length++;
	}
};
// 存储出现过的人的列表
struct AtDatas
{
	string *data;
	int length;
	void Append(string s){
		if (exist(s)){
			return;
		}
		data[length] = s;
		length ++;
	}
	// 排重处理
	bool exist(string s){
		for (int i = 0; i < length; i++)
		{
			if (data[i]==s){
				return true;
			}
		}
		return false;
	}
};

// At的成员与关系的收集 缓冲与内存之中
class AtDataCollector{
public:
	AtDatas atDatas;
	bufferAt atPairs;
	AtDataCollector(){
		atPairs.pairs = new atpair[2500];
		atPairs.length = 0;
		atDatas.length = 0;
		atDatas.data = new string[700];
	}
	void AtCollect(string text){
		ifstream fin(text.c_str());
		string s;
		if(!fin){
			cout<<text<<" Read ERROR"<<endl;
		}
		cout<<"Please wait,the ATs date is collecting ... "<<endl;
		while (fin>>s){
			for (unsigned int i = 0; i<s.length(); i++){
				if(s[i]=='@'){
					string temps1,temps2;
					for (int j = 0; j < i; j++)
					{
						temps1+=s[j];	
					}
					for (unsigned int k = i+1; k<s.length(); k++)	{
						temps2+=s[k];
					}
					atDatas.Append(temps1);
					atDatas.Append(temps2);
					atPairs.Append(temps1,temps2);
				}
			}
		}
		cout<<"The num of people is "<<atDatas.length<<endl;
		cout<<"The num of the at action is "<<atPairs.length<<endl;
	}
};
