#include <iostream>
#include "LibMatrix.h"

using namespace std;

int main()
{
    LibMatrix mat;
      int A[12][12];
    int B[12][12];


for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
                if(y==x+1){
				A[y][x]=1;
                }
                else{
                A[y][x]=3;
                }
            }
        }

for(int y=0;y<12;y++){
            for(int x=0;x<12;x++){
                if(y==x-6){
				B[y][x]=1;
                }
                else{
                B[y][x]=0;
                }
            }
        }

/******Decommenter les codes ci-dessous pour visualiser leurs effets******/

//LibMatrix::identity(A);
//LibMatrix::axialSymmetryIdentity(A);
   // LibMatrix::matrixProduct(matLevel,A,B);
    //LibMatrix::transpose(matLevel);
//LibMatrix::matrixCopy(A,B);
//LibMatrix::matrixRot90(B);
//LibMatrix::matrixRot180(B);
LibMatrix::readMatrix(B);

    return 0;
}
