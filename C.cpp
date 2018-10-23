#include <stdio.h>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
char* str;
int state;
int table[2][6]={{3,4,5,0,1,2},   //++++++++++++++++++++++++++++++++++++++++++++++//
				 {1,2,1,4,5,4}};  //ДКА для определния строки с четным количеством// 
void step(int &state, char ptr){  //нулей и нечетным количеством единиц			  //
	if(ptr=='0')				  //++++++++++++++++++++++++++++++++++++++++++++++//
		state=table[0][state];
	else if(ptr=='1')
		state=table[1][state];
}
void main(){
	state=0;
	int n=0;
	fin>>n;
	for(int i=0;i<n;i++){
		char temp;
		fin>>temp;
		step(state,temp);
	}
	if(state==1) cout<<"Congrats. Your string does match the pattern\n";
	else cout<<"Unfortunately your string doesn't match the pattern\n";
}