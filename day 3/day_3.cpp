#include <sys/time.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <print>
#include <cstdio>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define LENGTH 1000
#define PART_1 1
#define PART_2 1

int getSum(string input){
    ifstream file(input);
    char s;
    string func_1 = "mul(";
    int arg_1 = 0;
    string s_arg = ""; 
    int index = 0;
    int sum = 0;
    while (file >> noskipws >> s) {
        if(s == func_1[index]) {    
            index ++;
        }
        else if(index == func_1.length() && s == ',') {
            arg_1 = stoi(s_arg); 
            index ++; 
            s_arg =""; 
        }
        else if(index == func_1.length() && (s - '0') <= 9 && (s - '0') >= 0) {
            s_arg += s;
        }
        else if(s == ')' && index == func_1.length()+1){ 
        sum += arg_1 * stoi(s_arg);
        index = 0;
        s_arg = "";
        }
        else if(index == func_1.length()+1 && (s - '0') <= 9 && (s - '0') >= 0) {
            s_arg += s;
        }
        else{
            index = 0;
            s_arg = "";
        } 
    }
    file.close();
    return sum;
}

int getNewSum(string input) {
        ifstream file(input);
    char s;
    string func_1 = "mul(";
    int arg_1 = 0;
    string s_arg = ""; 
    int index = 0;
    int sum = 0;
    string active_func = "do()";
    int index_2 = 0;
    string unActive_func = "don't()";
    int index_3 = 0;
    bool active = true;
    int count = 0;
    while (file >> noskipws >> s) {
        if(s == active_func[index_2]) {
            index_2++;
            if(index_2 == active_func.length()) {
                active = true;
                index_2 = 0;
            }
        }
        else
            index_2 = 0;
        if(s == unActive_func[index_3]){
            index_3++;
            if(index_3 == unActive_func.length()) {
                active = false;
                index_3 = 0;
            }
        }
        else
            index_3 = 0;
        if(s == func_1[index] && index < func_1.length()) {    
            index ++;
        }
        else if(index == func_1.length() && s == ',') {
            arg_1 = stoi(s_arg); 
            index ++; 
            s_arg =""; 
        }
        else if(index == func_1.length() && (s - '0') <= 9 && (s - '0') >= 0) {
            s_arg += s;
        }
        else if(s == ')' && index == func_1.length()+1){ 
            if(!active) {
                index = 0;
                s_arg = "";
                arg_1 = 0;
                continue;
            }
            sum += arg_1 * stoi(s_arg);
            index = 0;
            s_arg = "";
        }
        else if(index == func_1.length()+1 && (s - '0') <= 9 && (s - '0') >= 0) {
            s_arg += s;
        }
        else{
            index = 0;
            s_arg = "";
        } 
    }
    file.close();
    return sum;

}


int main(int argc, char * argv[]) {
    // Create an input file stream object named 'file' and
    string input = "../input/day_3";
    if(PART_1 || PART_2) printf("Sum: ");
    if(PART_1) printf("\nOnly mul(): %d",getSum(input));
    if(PART_2) printf("\nWith do(), don't(): %d",getNewSum(input));
    
    // Close the file stream once all lines have been
    // read.

    return 0;
}