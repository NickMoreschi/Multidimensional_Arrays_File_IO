#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (int argc, char ** argv) {

    ifstream file;
    file.open(argv[1]);
    string fileName;
    int col;
    int row;
    int maxGray;
    file >> fileName;
    file >> col;
    file >> row;
    file >> maxGray;

    if (argc < 4) {
        cout << "Usage: ./image <input image> <neg image> <rotate image>" << endl;
        return 0;
    } else if (argc > 4) {
        cout << "Usage: ./image <input image> <neg image> <rotate image>" << endl;
        return 0;
    }
    if (!file.good()) {
        cout << "Can not open file" << endl;
        return 0;
    }

    //create original image 2d array
    int** oImg = new int*[row];
    for (int i = 0; i < row; i++) {
        oImg[i] = new int[col];
    }
    //put image data into  array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            file >> oImg[i][j];
        }
    }
    file.close();

    //create negative image 2d array
    int ** nImg = new int*[row];
    for (int i = 0; i < row; i++) {
        nImg[i] = new int[col];
    }
    //subtract original image max gray value from each value in the array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            nImg[i][j] = (maxGray - oImg[i][j]);
        }
    }

    //output negative image to file
    ofstream outputN (argv[2]);
    outputN << fileName << endl << col << "  " << row << endl << maxGray << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            outputN << nImg[i][j] << " ";
        }
        outputN << endl;
    }
    outputN.close();

    //create rotated image 2d array
    int** rImg = new int*[col];
    for (int i = 0; i < col; i++) {
        rImg[i] = new int[row];
    }
    //rotating original image 2d array clockwise into rotated image 2d array
    for (int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            rImg[i][j] = oImg[row - 1 - j][i];
        }
    }

    //output roated image to file
    ofstream outputR (argv[3]);
    outputR << fileName << endl << col << "  " << row << endl << maxGray << endl;
    for (int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            outputR << rImg[i][j] << " ";
        }
        outputR << endl;
    }
    outputR.close();

    for (int i = 0; i < row; i++) {
        delete[] nImg[i];
        delete[] oImg[i];
    }
    delete[] nImg;
    delete[] oImg;

    for (int i = 0; i < col; i++) {
        delete[] rImg[i];
    }
    delete[] rImg;

    return 0;
}