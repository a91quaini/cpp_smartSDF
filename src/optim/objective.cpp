#include <cmath>
#include "external/eigen/Eigen/Dense"
#include "optim/objective.hpp"

/*void
div
(
    const Eigen::VectorXd& weights,
    const Eigen::MatrixXd& returns,
    double& div_holder,
    Eigen::VectorXd* grad_holder
)
{
    div_holder = weights.sum(); 
    hj_div(weights, returns, div_holder, grad_holder);
}*/

void 
hj_div 
(
    const Eigen::VectorXd& weights, // portfolio weights 
    const Eigen::MatrixXd& returns, // matrix of returns
    double& div_holder, // hj-divergence holder computed by the function
    Eigen::VectorXd* grad_holder /* gradient holder computed by the function 
                                 (if it is not set to nullptr) */
)
{

    Eigen::VectorXd data(returns.rows());
    data = returns * weights;
    for (unsigned int n=0; n<weights.size(); ++n)
        data(n) = fmax( data(n), 0.0 );
    div_holder = weights.sum() + data.dot(data)*2/returns.rows();

    if (grad_holder)
    {
        for (unsigned t=0; t<returns.rows(); ++t)
        {
            *grad_holder = Eigen::VectorXd::Ones(returns.cols()) +  
                returns.transpose() * data * 2.0/returns.rows();
        }
    }    
}

/*void penalty 
(
    const Eigen::VectorXd weights,
    const double pen_param,
    double& div_holder,
    Eigen::VectorXd* grad_holder
)
{
}*/
