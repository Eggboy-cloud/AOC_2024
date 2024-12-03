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

vector<int> inSmallVector(int index, string line){
    int new_num;
    string temp_num = "";
    vector<int> vec;
    int size = 0;
    for (int i = 0; i < line.length(); i++) {
        if(line[i] == ' ') {
            if (size == index) {
                temp_num = "";
                size ++;
                continue;
                }
            new_num =stoi(temp_num);
            vec.push_back(new_num);
            temp_num = "";
            size ++;
            continue;
        }   
        temp_num += line[i];
    }
    if (index != size) {
        new_num =stoi(temp_num);
        vec.push_back(new_num);
    }
    return vec;
}

bool vecValid(vector <int> vec) {
    int test_val = vec.at(0) - vec.at(1);
    int fst_val = vec.at(1);
    int check;
    int val = 0;
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
    if(isValid(line))
        return 1;
    for(int i = 0; i < vec.size(); i++){
        vector <int> temp_vec = inSmallVector(i,line);
        if(vecValid(temp_vec))
            return 1;
    }
    return 0;
}


int main(int argc, char * argv[]) {
    // Create an input file stream object named 'file' and
    ifstream file("../input/day_2");
    // String to store each line of the file.
    string line;
    int val = 0;
    int val_2 = 0;
    // Read each line from the file and store it in the
    // 'line' variable.
    while (getline(file, line)) {   
        if (PART_1 && isValid(line)) val++;        
        if (PART_2 && isNewValid(line)) val_2++; }
    printf("Safe reports: ");
    if (PART_1) printf("\nwithout exceptions: %d", val);
    if (PART_2) printf("\nwith one exception: %d",val_2);
        // Close the file stream once all lines have been
    // read.
    file.close();

    return 0;
}