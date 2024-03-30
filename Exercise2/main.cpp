# include <iostream>
#include "Eigen/Eigen"
#include<iomanip>
using namespace std;
using namespace Eigen;

void sol(Matrix2f& A, Vector2f& b){
    VectorXf x1=A.fullPivLu().solve(b);
    VectorXf x_1=A.householderQr().solve(b);
    cout<<scientific<<"Risultato con la fattorizzazione PALU "<<setprecision(16)<<x1<<endl;
    cout<<scientific<<"Risultato con la fattorizzazione QR "<<setprecision(16)<<x_1<<endl;
    float errRelPALU=0.0;
    float errRelQR=0.0;
    Vector2f exactSolution={-1.0e+00, -1.0e+00};
    errRelPALU = (exactSolution - x1).norm() / exactSolution.norm();
    errRelQR = (exactSolution - x_1).norm() / exactSolution.norm();
    cout<<scientific<<"Errore relativo con la fattorizzazione PALU "<<setprecision(16)<<errRelPALU<<endl;
    cout<<scientific<<"Errore relativo con la fattorizzazione QR "<<setprecision(16)<<errRelQR<<endl;
}
int main(){
    Matrix2f A;
    A<< 5.547001962252291e-01,-3.770900990025203e-02, 8.320502943378437e-01,-9.992887623566787e-01;
    Vector2f b ={-5.169911863249772e-01, 1.672384680188350e-01};
    sol(A,b);
    A(0,1)=-5.540607316466765e-01;
    A(1,1)=-8.324762492991313e-01;
    b[0]=-6.394645785530173e-04;
    b[1]=4.259549612877223e-04;
    sol(A,b);
    A(0,1)=-5.547001955851905e-01;
    A(1,1)=-8.320502947645361e-01;
    b[0]=-6.400391328043042e-10;
    b[1]=4.266924591433963e-10;
    sol(A,b);
    return 0;
}
