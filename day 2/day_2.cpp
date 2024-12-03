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
#define PART_1 0
#define PART_2 1

vector<int> inVector(string line){
    int new_num;
    string temp_num = "";
    vector<int> vec;
    for (int i = 0; i < line.length(); i++) {
        if(line[i] == ' ') {
            new_num =stoi(temp_num);
            vec.push_back(new_num);
            temp_num = "";
            continue;
        }   
        temp_num += line[i];
    }
    new_num =stoi(temp_num);
    vec.push_back(new_num);
    return vec;
}

bool isValid(string line) {
    vector <int> vec = inVector(line);
    int test_val = vec.at(0) - vec.at(1);
    int fst_val = vec.at(1);
    int val = 0;
    int check;
    if(abs(test_val) > 3 || test_val == 0)
        return 0;
    else if(test_val < 0)
        check = -1;
    else
        check = 1;
    for(int i = 2; i < vec.size(); i++){
        val = vec.at(i);
        int diff = fst_val - val;
        if(abs(diff) >3 || diff == 0 || !(abs(diff)/diff == check)){
            return 0;
        }
            
        fst_val = val;
    }  
    return 1;
}

bool isNewValid(string line) {
    vector <int> vec = inVector(line);
    int test_val = vec.at(0) - vec.at(1);
    int fst_val = vec.at(1);
    int val = 0;
    int pos = 0;
    int neg = 0;
    int tooHigh = 0;
    vector <int> diffs;
    for(int i = 1; i < vec.size(); i++){
        val = vec.at(i);
        int diff = fst_val - val;
        diffs.push_back(diff);
        fst_val = val;
    }
    for(int elm : diffs){
        printf("%d \n",elm);
        if(abs(elm) >3 || elm == 0)
            tooHigh++;     
        if(elm < 0)
            neg++;
        if(elm >0)
            pos++;
    }
    printf("%d, %d, %d \n",tooHigh,neg,pos);
    if(tooHigh > 1 || (pos >1 && neg > 1)) {
       
        return 0;
    }
        
    neg = 0;
    pos = 0;
    tooHigh = 0;
    for(int elm : diffs){
        if(abs(elm) >3 || elm == 0) {
            tooHigh++;
            continue;
        }     
        if(elm < 0)
            neg++;
        if(elm >0)
            pos++;
    }
    printf("%d, %d, %d \n",tooHigh,neg,pos);
    if(tooHigh >= 1 && (pos >=1 && neg >= 1))
        return 0;
    return 1;
}



int main(int argc, char * argv[]) {
    // Create an input file stream object named 'file' and
    ifstream file("../input/day_2");

    // String to store each line of the file.
    string line;
    vector <int>vec_1;
    vector <int>vec_2;
    int index = 0;
    int sum = 0;
    int similar = 0;

        // Read each line from the file and store it in the
        // 'line' variable.
        while (getline(file, line)) {
            cout << line << endl;
            
            if(isNewValid(line)){
                printf("is valid \n");
                index++;
            }
            //if(line == "48 48 50 53 54 56 59")
                //break;
        }
        printf("Safe lines: %d",index);
         // Close the file stream once all lines have been
        // read.
        file.close();

    return 0;
}