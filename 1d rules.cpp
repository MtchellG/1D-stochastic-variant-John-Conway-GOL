#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
const unsigned SIZE = 200;
const unsigned ones = 15;

int* initializeCells() {                                       //filling initial array with random 1s and 0s
    int* c = new int[SIZE];
    for (unsigned i = 0, m = ones; i < SIZE; ++i) {
        if (rand() % (SIZE - i) < m) {
            c[i] = 1;
            --m;
        }
        else {
            c[i] = 0;
        }
    }
    return c;
}

int _1_0_1_(){                                                 // next step if lattice point (i) has neighbors in the form: 101
int randomNum = rand() %100;
if (randomNum <= 75){
    return 1;
}
else {
    return 0;
}
}
int _0_1_0_ (){                                                // next step if lattice has neighbors in the form: 010
int randomNum = rand() % 100;
if (randomNum <= 50) {
    return 1;
}
else{
    return 0;
}
}
int _1_1_0_ (){                                                // next step if lattice has neighbors in the form: 110
int randomNum = rand() % 100;
if (randomNum <= 75) {
        return 1;
}
else {
    return 0;
}
}
int _0_1_1_ (){                                                 // next step if lattice has neighbors in the form: 011
int randomNum = rand() % 100;
if (randomNum <= 75) {
        return 1;
}
else {
    return 0;
}
}
int _1_0_0 (){                                                  // next step if lattice has neighbors in the form: 100
int randomNum = rand() % 100;
if (randomNum <=25) {
    return 1;
}
else {
    return 0;
}
}
int _0_0_1 (){                                                  //next step if lattice has neighbors in the form: 001
int randomNum = rand() % 100;
if (randomNum <=25) {
    return 1;
}
else {
    return 0;
}

}
int _1_1_1_ () {
int randomNum = rand() % 100;
if (randomNum <=100) {
    return 1;
}
else {
    return 0;
}

}
int _0_0_0_ () {
int randomNum = rand() % 100;
if (randomNum <=100) {
    return 0;
}
else {
    return 1;
}

}



void updatecells(int* c, int* new_c) {
    for (int i = 0; i < SIZE; i++) {
        int iP = (i == 0) ? SIZE - 1 : i - 1;  // i-1 at boundary
        int iN = (i == SIZE - 1) ? 0 : i + 1;  // i+1 at boundary

        if (c[iP] == 1 && c[i] == 1 && c[iN] == 1) {
            new_c[i] = 1;
        }
        else if (c[iP] == 1 && c[i] == 1 && c[iN] == 0) {
            new_c[i] = _1_1_0_();
        }
        else if (c[iP] == 1 && c[i] == 0 && c[iN] == 1) {
            new_c[i] = _1_0_1_();
        }
        else if (c[iP] == 0 && c[i] == 1 && c[iN] == 1) {
            new_c[i] = _0_1_1_();
        }
        else if (c[iP] == 0 && c[i] == 0 && c[iN] == 1) {
            new_c[i] = _0_0_1_();
        }
        else if (c[iP] == 1 && c[i] == 0 && c[iN] == 0) {
            new_c[i] = _1_0_0_();
        }
        else if (c[iP] == 0 && c[i] == 1 && c[iN] == 0) {
            new_c[i] = _0_1_0_();
        }
        else if (c[iP] == 0 && c[i] == 0 && c[iN] == 0) {
            new_c[i] = _0_0_0_();
        }
        else {
            new_c[i] = c[i]; // If none of the conditions are met, keep the current value
        }
    }

    for (int i = 0; i < SIZE; i++) {
        c[i] = new_c[i];
    }
}


void initializeRandom() {
srand(time(NULL));
    }


int main() {
    initializeRandom();

    ofstream CFile("C.txt");

    int* c_array = initializeCells();
    int* new_c_array = new int[SIZE];

    for (int t = 0; t < 100; t++) {
        updatecells(c_array, new_c_array);

        for (int j = 0; j < SIZE; j++) {
            CFile << c_array[j] << " ";
        }
        CFile << endl;
    }

    CFile.close();
    delete[] c_array;
    delete[] new_c_array;
    return 0;
}
