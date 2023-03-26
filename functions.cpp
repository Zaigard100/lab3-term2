#include <iostream>

int *mark(int *a,unsigned m){
  for(unsigned i = 0; i < m; i++){
    if(a[i] > 0){
      a[i] = 1;
    }else{
      a[i] = 0;
    }
  }
  return a;
}

int **matrix_task(int** matrix,int* a,unsigned m){
  for (unsigned i = 0; i < m; i++) {
    for (unsigned j = 0; j < m; j++) {
      if(a[i]==1){
        if(matrix[i][j]>0){
          matrix[i][j] = 1;
        }else if(matrix[i][j]<0){
          matrix[i][j] = -1;
        }
      }
    }
  }
  return matrix;
}

int matrix_negativ(int** matrix,int* a,unsigned m){
  int negativ = 0;
  for (unsigned i = 0; i < m; i++) {
    for (unsigned j = 0; j < m; j++) {
      if(a[i]==1){
        if(matrix[i][j]<0){
          negativ++;
        }
      }
    }
  }
  return negativ;
}
