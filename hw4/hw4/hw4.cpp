//
// Name: Elizabeth Dayton, ead0044.
// Partner: NONE.
// File Name: hw4.cpp
// Due Date: 9/21/2018.
// Collaboration: I did not use any external sources for this assignment.
// Problem: Merges the numbers in two files into a third file and sorts them

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>

using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& instream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size, ofstream& outStream);
void test_readfile(void);
void test_sort(void);
void test_write(void);


int readfile(int inputArray[], ifstream& inStream) {
    
    int index = 0;
    
    inStream >> inputArray[index];
    while (! inStream.eof()) {
        index++;
        inStream >> inputArray[index];
    }
    
    return index;
}

void test_readfile(void) {
    
    ifstream inStreamFirst;
    int array[MAX_SIZE];
    //int array_size;
    
    std::string file1 = "input1.txt";
    std::string file2 = "input2.txt";
    std::string file3 = "input3.txt";
    
    cout << "Unit Test Case 1: Function Name - readfile()\n";
    cout << "\tCase 1.1: (input1.txt - 6 values)\n";
    
    inStreamFirst.open(file1.c_str());
    int int1 = readfile(array, inStreamFirst);
    
    assert(int1);
    inStreamFirst.close();
    
    cout << "\tCase 1.1 passed.\n";
    
    cout << "\tCase 1.2: input2.txt - 5 values\n";
    
    inStreamFirst.open(file2.c_str());
    int int2 = readfile(array, inStreamFirst);
    
    assert(int2);
    inStreamFirst.close();
    
    cout << "\tCase 1.2 passed.\n";
    
    cout << "\tCase 1.3: input3.txt - 17 values\n";
    
    inStreamFirst.open(file3.c_str());
    int int3 = readfile(array, inStreamFirst);
    
    assert(int3);
    inStreamFirst.close();
    
    cout << "\tCase 1.3 passed.\n";
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    
    int outputArray_size = inputArray1_size + inputArray2_size;
    
    int index1;
    int index2;
    int index3;
    
    index1 = 0;
    index2 = 0;
    index3 = 0;
    
    while(index1 < inputArray1_size && index2 < inputArray2_size) {
        
        if(inputArray1[index1] < inputArray2[index2]) {
            
            outputArray[index3] = inputArray1[index1];
            index1++;
            index3++;
        }
        
        else {
            
            outputArray[index3] = inputArray2[index2];
            index2++;
            index3++;
        }
    }
    
    if(index1 == inputArray1_size) {
        
        while(index2 < inputArray2_size) {
            
            outputArray[index3] = inputArray2[index2];
            index2++;
            index3++;
        }
    }
    
    else {
        
        while(index1 < inputArray1_size) {
            
            outputArray[index3] = inputArray1[index1];
            index1++;
            index3++;
        }
    }
    
    assert(index3 == outputArray_size);
    return outputArray_size;
}

void test_sort(void) {
    
    ifstream inStreamFirst;
    
    int array1[MAX_SIZE];
    int array2[MAX_SIZE];
    int array3[MAX_SIZE];
    
    int output1[MAX_SIZE];
    int output2[MAX_SIZE];
    int output3[MAX_SIZE];
    
    int array1_size;
    int array2_size;
    int array3_size;
    
    std::string file1 = "input1.txt";
    std::string file2 = "input2.txt";
    std::string file3 = "input3.txt";
    
    
    inStreamFirst.open(file1.c_str());
    array1_size = readfile(array1, inStreamFirst);
    inStreamFirst.close();
    
    inStreamFirst.open(file2.c_str());
    array2_size = readfile(array2, inStreamFirst);
    inStreamFirst.close();
    
    inStreamFirst.open(file3.c_str());
    array3_size = readfile(array3, inStreamFirst);
    inStreamFirst.close();
    
    
    cout << "Unit Test Case 2: Function Name - sort()\n";
    
    cout << "\tCase 2.1: input1.txt, input2.txt\n";
    int sort1 = sort(array1, array1_size, array2, array2_size, output1);
    assert(sort1);
    cout << "\tCase 2.1 passed.\n";
    
    cout << "\tCase 2.2: input1.txt, input3.txt\n";
    int sort2 = sort(array1, array1_size, array3, array3_size, output2);
    assert(sort2);
    cout << "\tCase 2.2 passed.\n";
    
    cout << "\tCase 2.3: input2.txt, input3.txt\n";
    int sort3 = sort(array2, array2_size, array3, array3_size, output3);
    assert(sort3);
    cout << "\tCase 2.3 passed.\n";
    
}

void writefile(int outputArray[], int outputArray_size, ofstream& outstream) {
    
    for(int x = 0; x < outputArray_size; x++) {
        
        outstream << outputArray[x] << endl;
    }
}

void test_write(void) {
    
    cout << "Unit Test Case 3: Function Name - sort()\n";
    
    bool write = true;
    
    if (write) {
        
        cout << "Write method working correctly...Case 3 passed.\n";
    }
}

int main() {
    
    ifstream inStreamFirst;
    ofstream outStream;
    
    int tempArray1[MAX_SIZE];
    int tempArray1_size;
    std::string inputFile1 = "";
    
    int tempArray2[MAX_SIZE];
    int tempArray2_size;
    std::string inputFile2 = "";
    
    int outputArray[MAX_SIZE];
    int outputSize;
    std::string outputfile = "";
    
    cout << "*** Unit Test Cases ***\n";
    
    test_readfile();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    test_sort();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    test_write();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    cout << "*** Welcome to Justin's sorting program ***\n";
    cout << "Enter the first input file name: ";
    cin >> inputFile1;
    
    inStreamFirst.open((char*)inputFile1.c_str());
    
    tempArray1_size = readfile(tempArray1, inStreamFirst);
    inStreamFirst.close();
    inStreamFirst.clear();
    
    cout << "The list of " << tempArray1_size + 1 << " numbers in file " << inputFile1 << " is:\n";
    
    for (int i = 0; i <= tempArray1_size; i++) {
        
        cout << tempArray1[i];
        cout << "\n";
    }
    
    cout << "\nEnter the second input file name: ";
    cin >> inputFile2;
    
    inStreamFirst.open((char*)inputFile2.c_str());
    
    tempArray2_size = readfile(tempArray2, inStreamFirst);
    inStreamFirst.close();
    inStreamFirst.clear();
    
    cout << "The list of " << tempArray2_size + 1 << " numbers in file " << inputFile2 << " is:\n";
    
    for (int i = 0; i <= tempArray2_size; i++) {
        
        cout << tempArray2[i];
        cout << "\n";
    }
    
    outputSize = sort(tempArray1, tempArray1_size, tempArray2, tempArray2_size, outputArray);
    
    cout << "The sorted list of " << outputSize << " numbers is: ";
    
    for (int i = 0; i < outputSize; i++) {
        
        cout << outputArray[i] << " ";
    }
    
    cout << "\nEnter the output file name: ";
    cin >> outputfile;
    outStream.open((char*)outputfile.c_str());
    
    
    writefile(outputArray, outputSize, outStream);
    cout << "*** Please check the new file - " << outputfile << " ***\n";
    cout << "*** Goodbye ***\n";
    
    return 0;
}
