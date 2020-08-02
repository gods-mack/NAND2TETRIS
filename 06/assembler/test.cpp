
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include "code.h"
#include "symbolTable.h"

using namespace std;


string decimalToBinary(int n) 
{ 
    //finding the binary form of the number and  
    //coneverting it to string.  
    string s = bitset<64> (n).to_string(); 
      
    //Finding the first occurance of "1" 
    //to strip off the leading zeroes. 
    const auto loc1 = s.find('1'); 
      
    if(loc1 != string::npos) 
        return s.substr(loc1); 
      
    return "0"; 
} 

int string2int(string s){

	int num = 0;

	for(int i = 0; i < (int)s.length(); i++){
		num = num*10 + (s[i] - '0');
	}
	return num;
}

string make16bit(string ins) {

	if(ins.length() < 16) {
		string rem = "";
		for(int j = 0; j < 16-ins.length(); j++){
			rem += "0";
		}
		ins = rem + ins;
	}

	return ins;

}

string Ainstruction(string line) {

	int number = 0;
	string num = "";
	string ans = "";
	for(int i = 0; i < line.length(); i++ ) {
		if(i == 0) {
			continue;
		}
		else{
			num += line[i];
		}
	}
	if(sym_table.find(num)!=sym_table.end()){
		string tmp = sym_table[num];
		ans = decimalToBinary(string2int(tmp));
	
	}
	else{
		if((int)line[0]>=48 and (int)line[0]<=57){
			number = string2int(num);
			ans = decimalToBinary(number);

		}
		

	}

	// num = num*10 + (line[i] - '0');
	
	ans = make16bit(ans);
	return ans;
}

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
	p = line.find("=");
	p++;

	while(1) {

		comp += line[p];
		p++;
		if(line[p] == ';') {
			break;
		}
	} 
	p++;

	while(p < n) {
		jum += line[p];
		p++;
	}

	string ans =  "111"+opcode[comp]+dests[des]+jumps[jum];

	ans = make16bit(ans);
	return ans;

		
}

void LableInstruction(string line,int line_pointer){

	string label = 0;


	for(int i = 0; i < (int)line.length(); i++) {
		if(line[i] == '(' or line[i] ==')'){
			continue;
		}
		else{
			label += line[i];
		}
	}


	string ans = decimalToBinary(line_pointer+1);	
	ans = make16bit(ans);

	sym_table[label] = ans;
	

}

int main() {

	ifstream fin;
	ofstream fout;

	string line;
	vector<string> prog;

	fin.open("add.asm");
	fout.open("add.hack");

	int m = 0;
	int line_pointer = 0;

	while(fin) {

		getline(fin,line);
		if(line[0] == '/' or line.length()==0 or line[0] == '\n' or (int)line[0] == 13){
			//cout<<"ww\n";
			continue;
		}
		/*cout<<m<<" ";
		if(m == 0) {
			cout<<"len "<<line.length()<<"\n";
			cout<<"asc "<<(int)line[0];
			
		}*/
	//	prog += line;
		cout<<line<<endl;
		if(line.find("@") != -1) {
			string ains = Ainstruction(line);
			fout<<ains<<endl;
			line_pointer++;
		}
		else if(line.find("(") != -1) {
			
			line_pointer++;
			LableInstruction(line,line_pointer);
		

		}
		else  {
			line_pointer++;
			string cins = Cinstruction(line);
			fout<<cins<<endl;


		}
		prog.push_back(line);
		m++;
		
	}

	fin.close();
	fout.close();

	cout<<"###"<<endl;
	for(int i = 0; i < prog.size(); i++) {
		cout<<prog[i]<<endl;
	}

}