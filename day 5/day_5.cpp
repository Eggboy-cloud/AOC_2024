#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>
#include <utility>

using namespace std;
#define LENGTH 1176
#define PART_1 1
#define PART_2 1

string getFst(string line){
    int index = 0;
    string num = "";
    while(line[index] != '|'){
        num += line[index];
        index++;
    }
    return num;
}

string getSnd(string line){
    int index = 3;
    string num = "";
    while(line[index] != '\0'){
        num += line[index];
        index++;
    }
    return num;
}

vector <string> makeVec(string line){
    vector <string> vec;
    string num = "";
    for(int i = 0; i < line.length(); i++){
        if(line[i] == ',') {
            vec.push_back(num);
            num = "";
            continue;
        }
        num += line[i];
    }
    vec.push_back(num);
    return vec;
}

int* testLine(string rules[], string line, int in[]) {
    vector <string> vec = makeVec(line);
    bool ruleBreaker = false;
    for(int i = 0; i < vec.size(); i++) {
        for(int k = i + 1; k < vec.size(); k++) {
            for(int j = 0; j < LENGTH; j++) {
                if(getFst(rules[j]) == vec.at(k) && getSnd(rules[j]) == vec.at(i)) {
                    swap(vec.at(k),vec.at(i));
                    ruleBreaker = true;
                    break;
                }
                    
            }
        }
    }
    in[ruleBreaker] += stoi(vec.at((vec.size()/2)));
    return in;
}

int main(int argc, char * argv[]) {
    // Create an input file stream object named 'file' and
    ifstream file("../input/day_5");
    // String to store each line of the file.
    string line;
    int index = 0;
    // Read each line from the file and store it in the
    // 'line' variable.
    string rules [LENGTH];
    int values [2] = {0,0};
    while (getline(file, line)) {   
        if(index >= LENGTH)
            break;
        rules[index] = line;
        index ++;
    }
    index = 0;
    int val_2 = 0;
    int val = 0;
    int index_2 = 0;
    while (getline(file, line)) {
        testLine(rules,line, values);
    }
    if(PART_1||PART_2) printf("Updates:");
    if(PART_1)printf("\nCorrectly-ordered updates, %d",values[0]);
    if(PART_2)printf("\nIncorrectly-ordered updates, %d",values[1]);
    // Close the file stream once all lines have been
    // read.
    file.close();

    return 0;
}