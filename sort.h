#ifndef SORT_H
#define SORT_H
#include <stdio.h>

struct KeyToValue
{
	int key;
	int value;
};


void quickSort(KeyToValue *sort,int left,int right);

void sort(KeyToValue *sort,int n){
	quickSort(sort,0,n);
}

void quickSort(KeyToValue *sort,int left,int right){

	int i = left,j = right;
	KeyToValue pivot = sort[(left+right)/2];

	while(i<=j) {
	    while(sort[i].value < pivot.value) {
	  		i++;
	    }
	    while(sort[j].value > pivot.value) {
	    	j--;
		}
	 	if(i <= j){
	 		int temp  = 0;
	 		temp = sort[i].value;
	 		sort[i].value = sort[j].value;
	 		sort[j].value = temp;
	 		temp = sort[i].key;
	 		sort[i].key = sort[j].key;
	 		sort[j].key = temp;
	 		i++;
	 		j--;
	    }
	}

	    if(i < right)
	    	quickSort(sort,i,right);	
	    if(left < j)
	    	quickSort(sort,left,j);
}

#endif // SORT_H
