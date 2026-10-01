
// function.h
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string> 
#include<bits/stdc++.h>
using namespace std;
// Function declaration
void space_remover(string &s);
bool function_checker(string &s);
int comma_counter(string &s);
bool alloc_checker(string st);
bool var_checker(string s);
string func_name(string s);
bool for_checker(string s);
void printing_data_section(vector<string>&data);
void printing_stack_section(vector<string>&stack_storage);
void printing_heap_section(vector<string>&heap);
void printing_text_sextion(string &file_name);
void overall_analysis(int n_line,vector<string>data,vector<string>heap,vector<string>stack_storage,vector<string>functions);
#endif

