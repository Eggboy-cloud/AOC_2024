#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define LENGTH 140
#define PART_1 1
#define PART_2 1

/* for(int j = 0; i < str_length; i++) {
            if(list[j][i] == 'X') {
                val++;
                //cout << list[i+1][j] << endl;
                if(checkRight(j,i,list)||checkDown(j,i,list)||checkDiagonal(j,i,list))
                    sum ++; */

bool checkRight(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(x+i >= str_length)
            return 0;
        if(list[y][x+i] == word[i])
            continue;
        else
            return 0;
    }
    return 1;
}

bool checkDown(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(y+i >= LENGTH)
            return 0;
        if(list[y+i][x] == word[i])
            continue;
        else
            return 0;
    }
    return 1;
}

bool checkDiagonal(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(x+i >= str_length || y+i >= LENGTH)
            return 0;
        if(list[y+i][x+i] == word[i])
            continue;
        else
            return 0;
    }
    return 1;

}

bool checkDiagonal_2(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(x-i < 0 || y+i >= LENGTH)
            return 0;
        if(list[y+i][x-i] == word[i])
            continue;
        else
            return 0;
    }
    return 1;
}

bool checkDiagonal_3(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(x+i >= str_length || y-i < 0)
            return 0;
        if(list[y-i][x+i] == word[i])
            continue;
        else
            return 0;
    }
    return 1;
}

bool checkDiagonal_4(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(x-i < 0 || y-i < 0)
            return 0;
        if(list[y-i][x-i] == word[i])
            continue;
        else
            return 0;
    }
    return 1;
}

bool checkLeft(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(x-i < 0)
            return 0;
        if(list[y][x-i] == word[i])
            continue;
        else
            return 0;
    }
    return 1;
}

bool checkUp(int y, int x, string list[]) {
    int str_length = list[0].length();
    string word = "XMAS";
    for(int i = 1; i < 4; i++) {
        if(y-i < 0)
            return 0;
        if(list[y-i][x] == word[i])
            continue;
        else
            return 0;
    }
    return 1;
}

bool isX(int y, int x, string list[]) {
    int cross = 0;
    int str_length = list[0].length();
    if(x-1 < 0 || y-1 < 0 || x+1 >= str_length || y+1 >= LENGTH)
        return 0;
    if(list[y-1][x-1] == 'M' && list[y+1][x+1] == 'S')
        cross ++;
    else if(list[y-1][x-1] == 'S' && list[y+1][x+1] == 'M')
        cross ++;
    if(list[y-1][x+1] == 'M' && list[y+1][x-1] == 'S')
        cross ++;
    else if(list[y-1][x+1] == 'S' && list[y+1][x-1] == 'M')
        cross ++;
    return cross == 2;
}

int getAmount(string list[]) {
    int str_length = list[0].length();
    int sum = 0;
    int val = 0;
    for(int i = 0; i < LENGTH; i++) {
        for(int j = 0; j < str_length; j++){
            if(list[i][j] == 'X') {
                if(checkRight(i,j,list)) sum ++;
                if(checkLeft(i,j,list))sum ++;
                if(checkDown(i,j,list))sum ++;
                if(checkUp(i,j,list))sum ++;
                if(checkDiagonal(i,j,list))sum ++;
                if(checkDiagonal_2(i,j,list))sum ++;
                if(checkDiagonal_3(i,j,list))sum ++;
                if(checkDiagonal_4(i,j,list))sum ++;
            }
        }
    }
    return sum;
}

int getNewAmount(string list[]) {
    int str_length = list[0].length();
    int sum = 0;
    int val = 0;
    for(int i = 0; i < LENGTH; i++) {
        for(int j = 0; j < str_length; j++){
            if(list[i][j] == 'A' && isX(i,j,list)) sum++;
        }
    }
    return sum;
}



int main(int argc, char * argv[]) {
    // Create an input file stream object named 'file' and
    ifstream file("../input/day_4");
    // String to store each line of the file.
    string line;
    int index = 0;
    string list[LENGTH];
    // Read each line from the file and store it in the
    // 'line' variable.
    while (getline(file, line)) {   
        list[index] = line;
        index++; 
    }
    // Close the file stream once all lines have been
    // read.
    file.close();
    if(PART_1||PART_2)printf("Results");
    if(PART_1)printf("\nXMAS: %d",getAmount(list));
    if(PART_2)printf("\nX-MAS: %d",getNewAmount(list));

    return 0;
}
