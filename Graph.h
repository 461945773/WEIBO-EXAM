#ifndef GRAPH_H
#define GRAPH_H
#include "list.h"
#include "sort.h"
#include <stdio.h>

/*struct KeyToValue
{
	int key;
	int value;
};
*/
class Graph{
	
public:
	Graph(){
		matrix = new int *[Default_Size];
		for (int i=0; i<Default_Size; i++){
			matrix[i] = new int[Default_Size];
		}
		for (int i=0; i<Default_Size; i++)
		for (int j=0; j<Default_Size; j++){
			matrix[i][j] =0;
		}
		for (int i=0;i<peoList.friCollector.friPairs.length;i++){
			matrix[peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str1)][peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str2)] = 1;
			matrix[peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str2)][peoList.FindIndex(peoList.friCollector.friPairs.pairs[i].str1)] = 1;
		}
		for (int i=0;i<peoList.atCollector.atPairs.length;i++){
			if(matrix[peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str1)][peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str2)]<1)
				matrix[peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str1)][peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str2)]=0;
				matrix[peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str1)][peoList.FindIndex(peoList.atCollector.atPairs.pairs[i].str2)] += 2;
 		}
 		createNumFriends();
	}
	void TheFriendsNumList(int n){
		KeyToValue sorted[Default_Size];
		for (int i = 0; i < Default_Size; ++i){
			sorted[i].key = i;
			sorted[i].value = numFriends[i];
		}
		sort(sorted,Default_Size);
		cout<<"Here is the FriendsNum List"<<endl;
		cout<<"Show as { Id : Num of friends }"<<endl;
		cout<<"{"<<endl;

		for (int i = Default_Size-1; i >= 0; --i){
			if(sorted[i].value > 0){
			cout<<"		"<<peoList.list[sorted[i].key].value<<" : "<<sorted[i].value<<endl; 
			n--;
			if(n==0)goto out;
		  }
		}
		out:
		cout<<"}"<<endl;
	}
	
	void WhoHaveTheMostAts(){
		int max = 0;
		int temp = 0;
		int maxi = 0;
		for (int i = 0;i<Default_Size;i++){
			temp = 0;
			for (int j = 0; j < Default_Size; j++)
			{   
				if(matrix[j][i]>0){
						temp += matrix[j][i]/2;
				}
			}
			if(temp>max){
				max = temp;
				maxi = i;
			}
		}
		cout<<"The Man/WoMan Who Hava The Most @ is "<<peoList.list[maxi].value<<endl;
		cout<<"He/She has "<<max<<" @ "<<endl;
	}

	void WhoSendMostAts(){
		int max = 0;
		int temp = 0;
		int maxi = 0;
		for (int i = 0;i<Default_Size;i++){
			temp = 0;
			for (int j = 0; j < Default_Size; j++)
			{   
				if(matrix[i][j]>0){
						temp += matrix[i][j]/2;;
				}
			}
			if(temp>max){
				max = temp;
				maxi = i;
			}
		}
		cout<<"The Man/WoMan Who send The Most @ is "<<peoList.list[maxi].value<<endl;
		cout<<"He/She has sent "<<max<<" @ "<<endl;
	}
	void TheAverageAts(){

	}
	void TheAverageFriends(){
		int iFriends = 0;
		int iCount = 0;
		for (int i = 0; i < Default_Size; ++i)
		{
			for (int j = 0; j < Default_Size; ++j)
			{
				if(matrix[i][j]%2!=0)
					iFriends++;
			}
		}
		cout<<"The Average of Friends is "<<iFriends/(2*648)<<endl;
	}
private:
	void createNumFriends(){
		int temp = 0;
		for (int i = 0;i<Default_Size;i++){
			temp = 0;
			for (int j = 0; j < Default_Size; j++)
			{   
				if(matrix[i][j]>0){
					if(matrix[i][j]%2!=0){
						temp ++;
					}
				}
			}
			numFriends[i] = temp;
		}
	}
	int numAtsIn[850];
	int numAtsOut[850];
	int numFriends[850];
	PeopleList peoList;
	int **matrix;
	static const int Default_Size = 850;
};

#endif