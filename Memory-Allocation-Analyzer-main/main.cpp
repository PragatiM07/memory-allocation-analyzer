#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <bits/stdc++.h>
#include "function.h"  // Include the header file 

using namespace std;

vector<string>functions; // for storing the name of functions 
vector<string>heap; // for storing the name of heap sections variable
vector<string>stack_storage; // for storing the name of stack sections variable
vector<string>data; // for storing the name of data sections variable

int func_count=0;

int main() {

    string file_name="input.txt"; 
    ifstream f("input.txt"); //opening a text file
    
    if (!f.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    
    string s;
    int n_line=0;
    
    while (getline(f, s)) {
        string st=s;
        streampos position;
        
    	if(for_checker(s)==false && function_checker(st) && alloc_checker(s)==false){ //condition for function checking
    		stack<char>bracket;
    		functions.push_back(func_name(st));
    		if(s.find("{") != string::npos) bracket.push('{');
    		while(getline(f,s)){
    			n_line++;
    			if(var_checker(s)==true) stack_storage.push_back(s);
    			if(alloc_checker(s)==true) heap.push_back(s);
    			if(s.find("{") != string::npos) bracket.push('{');
    			else if(s.find("}") != string::npos) bracket.pop();
    			if(bracket.empty()==true) break;
    		}
    	}
    	
    	if(alloc_checker(st)){ // condition  for checking dynamic allocation
    		n_line++;
    		heap.push_back(st);
    	}
    	
    	if(var_checker(s)){ // condition  for checking local variable
    		n_line++;
    		data.push_back(s);
    	}
    	
    	else n_line++;
    	
    }
    
    	//calling functions for output
    	overall_analysis(n_line,data,heap,stack_storage,functions);
	printing_text_sextion(file_name);
	printing_data_section(data);
	printing_stack_section(stack_storage);
	printing_heap_section(heap);
	
    f.close();
    
    return 0;
    
}

