#include <iostream>
#include <math.h>
void delete_Massive (float **mas, int m);
void PrintMatr(float **mas, int n);
void Help_Matr(float **mas, float **p, int i, int j, int m);
float Deter(float **mas, int m);

int main() {
    int i, j, n, k, d;
    float **A; //?????? ?
    std::cout<<"Enter the dimension of the matrix: ";
    std::cin>>n; 
    A=new float*[n]; 
    for (i=0;i<n;i++){ 
        A[i]=new float[n];
        for(j=0;j<n;j++)
            std::cin>>A[i][j];
    }
    float **B; //?????? B ???? ? ?????
    B=new float*[n]; 
    for (i=0;i<n;i++){ 
        B[i]=new float[n];
        for(j=0;j<n;j++) {
            if ((i == j) || (i+j) == (n - 1)){ //??????????? ?????????????? ??????????
                if ((i+j) == (n - 1)) //???????? ?????????
                    B[i][j] = A[i][j] * 4 / 3;
                if (i == j) //??????? ?????????
                    B[i][j] = A[i][j] / 3;
            }
            else // ???????? ??? ??????????
               B[i][j] = pow(A[i][j], 2);
        }
    }
    std::cout<<"Massiv B: \n";
    PrintMatr(B, n);
    float **C;         //?????? ?
    C = new float*[n];
     for (i=0;i<n;i++) { 
        C[i]=new float[n];
        for(j=0;j<n;j++) {
            C[i][j]=0;
            for(k=0; k < n; k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
    }
    std::cout<<"Determinant: ";
    std::cout<<Deter(C, n);
    delete_Massive (A, n);
    delete_Massive (B, n);
    delete_Massive (C, n);
    return 0;
}
void delete_Massive (float **mas, int m){
    for (int i = 0; i < m; i++){
        delete [] mas[i];
    }
    delete [] mas;
}
void PrintMatr(float **mas, int n) {
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
            std::cout<<mas[i][j]<<" ";
        std::cout<<std::endl;
    }
}
void Help_Matr(float **mas, float **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < (m - 1); ki++) { // ???????? ??????? ??????
        if (ki == i) di = 1;
            dj = 0;
        for (kj = 0; kj < (m - 1); kj++) { // ???????? ??????? ???????
            if (kj == j) dj = 1;
                p[ki][kj] = mas[ki + di][kj + dj];
        }
    }   
}
float Deter(float **mas, int m) {
    int i, j = 0, d = 0, k = 1, n;
    float **p;
    p = new float*[m];
    for (i = 0; i<m; i++)
        p[i] = new float[m];
    j = 0; d = 0; k = 1; n = m - 1; 
    if (m<1) std::cout << "Determinant doesn't exist";
    if (m == 1) {
        d = mas[0][0];
        delete_Massive (p, m);
        return(d);
    }
    if (m == 2) {
        d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
        delete_Massive (p, m);
        return(d);
    }
    if (m>2) {
        for (i = 0; i<m; i++) {
            Help_Matr(mas, p, i, 0, m);
            d = d + k * mas[i][0] * Deter(p, n - 1);
            k = -k;
        }
    }
    delete_Massive (p, m);
    return(d);
}
