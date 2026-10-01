
// function.cpp
#include "function.h"   // Include the header file to link the declaration with the definition
#include <string>
#include<bits/stdc++.h>
using namespace std;
ofstream outFile("output.txt");

//function for checking variable size
int var_size(string &s){ 
	if (s == "int") {
        return sizeof(int);
    }
    else if (s == "float") {
        return sizeof(float);
    }
    else if (s == "char") {
        return sizeof(char);
    }
    else if (s == "double") {
        return sizeof(double);
    }
    else if (s == "signed char") {
        return sizeof(signed char);
    }
    else if (s == "unsigned char") {
        return sizeof(unsigned char);
    }
    else if (s == "signed short") {
        return sizeof(signed short);
    }
    else if (s == "unsigned short") {
        return sizeof(unsigned short);
    }
    else if (s == "unsigned int") {
        return sizeof(unsigned int);
    }
    else if (s == "signed int") {
        return sizeof(signed int);
    }
    else if (s == "signed short int") {
        return sizeof(signed short int);
    }
    else if (s == "unsigned short int") {
        return sizeof(unsigned short int);
    }
    else if (s == "signed long int") {
        return sizeof(signed long int);
    }
    else if (s == "unsigned long int") {
        return sizeof(unsigned long int);
    }
    else if (s == "long double") {
        return sizeof(long double);
    }
    else if (s == "short") {
        return sizeof(short);
    }
    else if (s == "short int") {
        return sizeof(short int);
    }
    else if (s == "long int") {
        return sizeof(long int);
    }
    else return 0;
}

// for loop checker function 
bool for_checker(string s){
	int res = s.find("for");
    if (res != string::npos)
         return true;
      else
          return false;
}

//removes the space between characters
void space_remover(string &s) {
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            s[j++] = s[i];  // Move non-space characters to the front
        }
    }
    s.resize(j);  // Resize the string to remove the excess characters
}
//check whether there is any function or not
bool function_checker(string &s){
	string func_name[5]={"int","float","char","void","bool"}; //array of return types 
	for(auto func:func_name){
		if(s.find(func)!=string::npos  &&  (s.find("(")!=string::npos  &&  s.find(")") != string::npos) || s.find("{") != string::npos){ //checking return types and brackets
			return true;
		}
	}
	return false;

}
// counts the number of commas
int comma_counter(string &s){
	 int count=0,comma=0;
    	while(count<s.size()){
        	if(s[count]==',') {
        	    comma = comma + 1; //Counts to commaa counter
        	}
        	count = count + 1;
    	}	
    return comma;
}

//for dynamic memory allocation checker function
bool alloc_checker( string line) {
    const string alloc[12] = {"=malloc", "=calloc", ")malloc", ")calloc","=new","= malloc", "= calloc", ") malloc", ") calloc","= new",")realloc",") realloc"};
    
    for (int i = 0; i < 12; i++) {
        if (line.find(alloc[i]) != string::npos && line.find("(") != string::npos 
            && line.find(")") != string::npos && line.find(";") != string::npos) {
            
            return true; // Returns true if it contains all of the if conditions
        }
        if(line.find(alloc[i]) != string::npos && line.find("[") != string::npos 
            && line.find("]") != string::npos && line.find(";") != string::npos){
            	return true;
            }
    }
    
    return false;
}

// function for variable checker 
bool var_checker(string s){
	string datatypes[18]={"signed char","unsigned char","signed short","unsigned short","signed int","unsigned int","signed short int","unsigned short int","signed long int","unsigned long int","float","double","long double","char","short","int","short int","long int"};	
	for(int i=0;i<18;i++){
		if(s.find(datatypes[i]) != string::npos && s.find("=") != string::npos && s.find(";") != string::npos && for_checker(s)==false){
			return true;
		}
	}
	return false;
}

// Gives the function name
string func_name(string s){
	int i=0;
	while(s[i]!=' ') i++;
	string func="";
	while(s[i]!='('){
		func+=s[i];
		i++;
	}
	return func;
}

string gives_dtype(string s){
	string datatypes[18]={"signed char","unsigned char","signed short","unsigned short","signed int","unsigned int","signed short int","unsigned short int","signed long int","unsigned long int","float","double","long double","char","short","int","short int","long int"};	
	for(int i=0;i<18;i++){
		if(s.find(datatypes[i])!=string::npos) return datatypes[i];
	}
	return "";
}

// Gives the variable name
string var_name(string &s){
	int i=0;
	while(s[i]!=' ') i++;
	string var="";
	while((s[i]!='=') && i<s.size()){
		var+=s[i];
		i++;
	}
	return var;
}

//function for text section
void printing_text_sextion(string &file_name){
	 if (outFile.is_open()) {
	 	string fname="###### Data Section ######";
	 	outFile << fname << endl;
	 	outFile<<endl;
	 	string s="    ";
	 	s+=file_name;
	 	outFile << s << endl;
	 	outFile<<endl;
	 	 
	 }
	cout<<"###### Data Section ######"<<endl;
	cout<<endl;
	cout<<"    "<<file_name<<endl;
	cout<<endl;
}

//function for data section 
void printing_data_section(vector<string>&data){
	/*
	cout<<"###### Data Section ######"<<endl;
	cout<<endl;
	for(int i=0;i<data.size();i++){
		string var=var_name(data[i]);
		space_remover(var);
		string dtype=gives_dtype(data[i]);
		cout<<"    "<<var<<" ("<<dtype<<") ("<<var_size(dtype)<<" bytes)"<<endl;
	}
	cout<<endl;
	*/
	if (outFile.is_open()) {
	 	string name="###### data Section ######";
	 	cout<<name<<endl;
	 	outFile << name << endl;
	 	outFile<<endl;
	 	cout<<endl;
		for(int i=0;i<data.size();i++){
			string s="";
			string var=var_name(data[i]);
			string dtype=gives_dtype(data[i]);
			s+=data[i];
			s+=" ";
			s+=var;
			s+=" is a reference variable of these (";
			s+=to_string(var_size(dtype));
			s+=" bytes)";
			outFile << s << endl;
	 		//outFile<<endl;
	 		cout<<s<<endl;
			//cout<<heap[i]<<" "<<var<<" is a reference variable of these ("<<var_size(dtype)<<" bytes)"<<endl;
		}
		cout<<endl;
		outFile<<endl;
	 	 
	 }
}

// function for stack section
void printing_stack_section(vector<string>&stack_storage){
	/*
	cout<<"###### Stack Section ######"<<endl;
	cout<<endl;
	for(int i=0;i<stack_storage.size();i++){
		string var=var_name(stack_storage[i]);
		string dtype=gives_dtype(stack_storage[i]);
		cout<<var<<" ("<<dtype<<") ("<<var_size(dtype)<<" bytes)"<<endl;
	}
	cout<<endl;
	*/
	if (outFile.is_open()) {
	 	string name="###### Stack Section ######";
	 	cout<<name<<endl;
	 	outFile << name << endl;
	 	outFile<<endl;
	 	cout<<endl;
		for(int i=0;i<stack_storage.size();i++){
			string s="";
			string var=var_name(stack_storage[i]);
			string dtype=gives_dtype(stack_storage[i]);
			s+=stack_storage[i];
			s+=" ";
			s+=var;
			s+=" is a reference variable of these (";
			s+=to_string(var_size(dtype));
			s+=" bytes)";
			outFile << s << endl;
	 		//outFile<<endl;
	 		cout<<s<<endl;
			//cout<<heap[i]<<" "<<var<<" is a reference variable of these ("<<var_size(dtype)<<" bytes)"<<endl;
		}
		cout<<endl;
		outFile<<endl;
	 	 
	 }
}

//function for heap section
void printing_heap_section(vector<string>&heap){
	if (outFile.is_open()) {
	 	string name="###### Heap Section ######";
	 	cout<<name<<endl;
	 	outFile << name << endl;
	 	outFile<<endl;
	 	cout<<endl;
		for(int i=0;i<heap.size();i++){
			string s="";
			string var=var_name(heap[i]);
			string dtype=gives_dtype(heap[i]);
			s+=heap[i];
			s+=" ";
			s+=var;
			s+=" is a reference variable of these (";
			s+=to_string(var_size(dtype));
			s+=" bytes)";
			outFile << s << endl;
	 		//outFile<<endl;
	 		cout<<s<<endl;
			//cout<<heap[i]<<" "<<var<<" is a reference variable of these ("<<var_size(dtype)<<" bytes)"<<endl;
		}
		cout<<endl;
	 	 
	 }
	
}

//function for overall analysis
void overall_analysis(int n_line,vector<string>data,vector<string>heap,vector<string>stack_storage,vector<string>functions){
	if (outFile.is_open()) {
	string a,b,c,d;
	 	string overall_analysis="Overall analysis";
	 	outFile << overall_analysis << endl;
	 	outFile<<endl;
	 	string s="    Total number of lines = ";
	 	s+=to_string(n_line);
	 	outFile << s << endl;
	 	a="    Total number of functions = ";
	 	a+=to_string(functions.size());
	 	outFile << a << endl;
	 	b="    Total local variables = ";
	 	b+=to_string(stack_storage.size());
	 	outFile << b << endl;
	 	c="    Total dynamic variables = ";
	 	c+=to_string(heap.size());
	 	outFile << c << endl;
	 	d="    Total global variables = ";
	 	d+=to_string(data.size());
	 	outFile << d << endl;
	 	outFile<<endl;
	 	 
	 }
	cout<<"Overall analysis"<<endl;
	cout<<endl;
	cout<<"Total number of lines = "<<n_line<<endl;
	cout<<"Total number of functions = "<<functions.size()<<endl;
	cout<<"Total local variables = "<<stack_storage.size()<<endl;
	cout<<"Total dynamic variables = "<<heap.size()<<endl;
	cout<<"Total global variables = "<<data.size()<<endl;
	cout<<endl;
	
}


