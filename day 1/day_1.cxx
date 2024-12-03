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

int partition(vector<int> &vec, int low, int high) {

    // Selecting last element as the pivot
    int pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec, low, high);

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}


int fstNum(string line) {
    string newNum = "";
    for (int i = 0; i < line.length(); i++) {
        if(line[i] == ' ')
            break;
        newNum += line[i];
    }
    return stoi(newNum);
}

int sndNum(string line) {
    string newNum = "";
    for (int i = 8; i < line.length(); i++) {
        if(line[i] == '\0')
            break;
        newNum += line[i];
    }
    return stoi(newNum);
}

int main(int argc, char * argv[]) {
    // Create an input file stream object named 'file' and
    ifstream file("../input/day_1");

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
            //cout << returnSndNum(line) << endl;
            if(index < LENGTH) {
                vec_1.push_back(fstNum(line));
                vec_2.push_back(sndNum(line));
                index++;
            }   
        }
         // Close the file stream once all lines have been
        // read.
        file.close();
        if(PART_1) {
            quickSort(vec_1,0, LENGTH-1);
            quickSort(vec_2,0,LENGTH-1);
            for(int i = 0; i < LENGTH; i++) {
                sum += abs(vec_1.at(i) - vec_2.at(i));
            }
            printf("Sum: %d \n",sum);
        }
        if(PART_2) {
           for(int i = 0; i < LENGTH; i++) {
                for(int j = 0; j < LENGTH; j++) {
                    if(vec_1.at(i) == vec_2.at(j))
                        similar += vec_1.at(i);
                }
            }
            printf("Similarity score: %d \n",similar); 
        }

    return 0;
}