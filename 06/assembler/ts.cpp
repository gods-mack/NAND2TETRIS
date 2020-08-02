
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include "code.h"

using namespace std;

string Cinstruction(string line) {

	string des = "";
	string comp = "";
	string jum = "";

	int n = line.length();
	int p = 0; // string pointer

	while(1) {
		des += line[p];
		p++;
		if(line[p] == '=') {
			break;
		}
	}
	//p = line.find("=");
	p++;

	while(1) {

		comp += line[p];
		p++;
		if(line[p] == ';' or p < n) {
			break;
		}
	} 
	cout<<"cmpOnlu "<<comp<<endl;
	p++;

	while(p < n) {
		jum += line[p];
		p++;
	}
	cout<<"jump "<<jumps[jum]<<endl;
	cout<<"dest "<<dests[des]<<endl;
	cout<<"comp "<<opcode[comp]<<endl;
	string ans =  "111"+opcode[comp]+dests[des]+jumps[jum];


	return ans;

		
}


int main() {
	string s;
	cin>>s;

	cout<<Cinstruction(s)<<endl;
}