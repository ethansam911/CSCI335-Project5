/*
 File:      CreateGraphAndTest.cpp
 Author:    Ethan Sam
 Purpose:    This file performs matrix multiplications based on 
			the optimal amount of multiplications needed (AKA the 
			least)

			
 Date:      5/7/2019
 */
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <limits>
using namespace std;

//Pass an array and its size
int MatrixChainOrder(int p[], int size) 
{ 
 
    /* one extra row and one 
    extra column are allocated in m[][].  
	0th row and 0th 
    column of m[][] are not used 
	*/
    int m[size][size]; 
  
    int i, j, k, L, q; 
  
    /* m[i,j] = Minimum number of scalar multiplications needed 
       to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where 
       dimension of A[i] is p[i-1] x p[i] */
  
    // cost is zero when multiplying one matrix. 
	//Therefore initilialize all spaces to be 0;
    for (i=1; i<size; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L=2; L<size; L++) 
    { 
        for (i=1; i<size-L+1; i++) 
        { 
            j = i+L-1; 
            m[i][j] = INT_MAX; 
            for (k=i; k<=j-1; k++) 
            { 
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n-1]; 
} 

void ReadFromMatrixInput( const string& matrixFile)
{
    std::ifstream input_from_file;
    input_from_file.open(matrixFile);
    if(input_from_file.fail())
	{
        std::cout << "Failed to open " << matrixFile << std::endl;
        exit(1);
    }
	
	int dimensionValue;
	int size = 0;
	//initialize a given array of size 50
	int arr[50];
    std::string line;
    while(std::getline(input_from_file, line))
	{
        if(!line.empty())
		{
            std::stringstream ss(line);
            while(ss >> dimensionValue)
			{
			 arr[size] = dimensionValue;	 
			 size++;	
			}
		}
	}
	std::cout<<"The minimum amount of multiplications is: " << MatrixChainOrder(arr, size) << endl; 
	
    input_from_file.close();
 }


 int main(int argc, char **argv)
 {
 	if(argc != 2)
	{
 		std::cout << "Usage: " << argv[0] << " <matrixInputFileName> " << std::endl;
        return 0;
    }
    const string dimensions_filename(argv[1]);
	ReadFromMatrixInput(dimensions_filename);
	

    return 0;
 }