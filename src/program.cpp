#include <iostream>
#include "optim/objective.hpp"
#include "external/eigen/Eigen/Dense"

int main (void)
{
    const unsigned N = 2;
    const unsigned T = 3;
    Eigen::VectorXd eigen_weights(N);
    Eigen::MatrixXd eigen_returns(T,N);
    double eigen_div=0.0;
    Eigen::VectorXd* eigen_grad = new Eigen::VectorXd(N);

    for (unsigned t=0; t<T; ++t)
        for (unsigned n=0; n<N; ++n)
        {
             eigen_weights(n)=double(n+1)/7.0;
             //(*eigen_grad)(n)=0.0;
             eigen_returns(t,n)=double((n+1)*(t+1))/7.0;
        }

    std::cout << eigen_weights << std::endl;
    std::cout << eigen_returns << std::endl;
    hj_div(eigen_weights, eigen_returns, eigen_div, eigen_grad);
    std::cout << eigen_div << std::endl;
    std::cout << *eigen_grad << std::endl;
}
