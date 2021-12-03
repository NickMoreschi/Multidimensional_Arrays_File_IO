#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main (int argc, char ** argv) {

    int*** oImg = new int**[argc-2];
    string fileName;
    int col;
    int row;
    int maxGray;
    vector<int> sortNums;

    for (int i = 0; i < argc-2; i++) {
        ifstream iFile;
        iFile.open(argv[i+1]);
        iFile >> fileName;
        iFile >> col;
        iFile >> row;
        iFile >> maxGray;
        
        oImg[i] = new int*[row];
        for (int x = 0; x < row; x++) {
            oImg[i][x] = new int[col];
        }

        for (int x = 0; x < row; x++) {
            for (int y = 0; y < col; y++) {
                iFile >> oImg[i][x][y];
            }
        }
        iFile.close();

    }

    int** fImg = new int*[row];
    for (int i = 0; i < row; i++) {
        fImg[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < argc-2; k++) {
                sortNums.push_back(oImg[k][i][j]);
            }
            sort(sortNums.begin(), sortNums.end());
            int mid = sortNums.size();
            mid = mid / 2;
            fImg[i][j] = sortNums[mid];
            sortNums.clear();
        }
    }

    ofstream oFile (argv[argc-1]);
    oFile << fileName << endl << col << "  " << row << endl << maxGray << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            oFile << fImg[i][j] << " ";
        }
        oFile << endl;
    }
    oFile.close();

    sortNums.clear();
    for (int i = 0; i < argc-2; i++) {
        for (int j = 0; j < row; j++) {
            delete[] oImg[i][j];
        }
        delete[] oImg[i];
    }
    delete[] oImg;

    for (int i = 0; i < row; i++) {
        delete[] fImg[i];
    }
    delete[] fImg;

    return 0;
}