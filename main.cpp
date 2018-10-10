#include <iostream>
#include <iomanip>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
};

// Al2ready implemented
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int [row * col];
  for (int i = 0; i < row * col; i++){
        mat.data[i]=num[i];
}
cout<<endl;
};
matrix operator+= (matrix& mat1, matrix mat2){     // mat1 changes + return new	 // matrix with addition
     cout<<"addition of the two matrices"<<endl;
     for(int i=0; i<(mat1.row*mat1.col) ; i++){
        cout<<mat2.data[i]+mat1.data[i]<<" ";
     }
     cout<<endl;
};
matrix operator-= (matrix& mat1, matrix mat2){    // mat1 changes + return new	 // matrix with difference
     cout<<"difference between the two matrices"<<endl;
     for(int i=0; i<(mat1.row*mat1.col) ; i++){
            cout<<mat2.data[i]-mat1.data[i]<<" ";
    }
     cout<<endl;
};

matrix operator+= (matrix& mat, int scalar){    // change mat & return new matrix
    cout<<"add number to the array"<<endl;
    for(int i=0; i<(mat.row*mat.col) ; i++){
    cout<<scalar+mat.data[i]<<" ";
    }
    cout<<endl;
};

matrix operator-= (matrix& mat, int scalar){    // change mat & return new matrix
    cout<<"subtract a number from the array"<<endl;
    for(int i=0; i<(mat.row*mat.col) ; i++){
    cout<<mat.data[i]-scalar<<" ";
    }
    cout<<endl;
    };

void   operator++ (matrix& mat){       // Add 1 to each element ++mat
    cout<<"add 1 to each element in the array"<<endl;
    int mat4[mat.row*mat.col];
    for(int i=0; i<(mat.row*mat.col) ; i++){
       mat4[i]= mat.data[i]+1;
        cout<<mat4[i]<<" ";
    }
    cout<<endl;
};

void   operator-- (matrix& mat){      // Sub 1 from each element --mat
     cout<<"subtract 1 from each element in the array"<<endl;
     int mat4[mat.row*mat.col];
     for(int i=0; i<(mat.col*mat.row) ; i++){
       mat4[i]= mat.data[i]-1;
        cout<<mat4[i]<<" ";
    }
    cout<<endl;
};

  istream & operator >> (istream &in, matrix &mat) {
        in >> mat.row;
        in >> mat.col;
            cout << " values (top row, second row... last row - left to right)" << endl;
            mat.data=new int[mat.row*mat.col];
            // Copy values into new array
            for(int i=0;i<(mat.row*mat.col);i++) {
            in >> mat.data[i];
    }
    return in;
}
int main()
{
  matrix mat1, mat2, mat3;
  int number=0;
  cout<<"enter number which will be added to the array ";
  cin>>number;
  int row,col;
  cout<<"enter number of rows ";
  cin>>row;
  cout<<"enter number of columns ";
  cin>>col;
  int data1[row][col];
  int data2[row][col];

  cout<<"enter elements of array1"<<endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
        cin>>data1[i][j];
  }
  }
  cout<<"enter elements of array2"<<endl;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
        cin>>data2[i][j];
  }
  }
  int dataa[6];
  int dataaa[6];
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
        dataa[col*i+j]=data1[i][j];
        dataaa[col*i+j]=data2[i][j];
  }
  }
  cout<<endl;
  createMatrix (row ,col , dataa, mat1);
  createMatrix (row ,col , dataaa, mat2);
  mat3=operator+= (mat1,mat2);
  mat3=operator-= (mat1,mat2);
  operator++ (mat1);
  operator-- (mat1);
  mat3=operator+= (mat1, number);
  mat3=operator-= (mat1, number);
  return 0;
}
