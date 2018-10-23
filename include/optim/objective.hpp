#pragma once

#include "external/eigen/Eigen/Dense"

void
div
(
    const Eigen::VectorXd& weights, 
    const Eigen::MatrixXd& returns, 
    double& div_holder,  
    Eigen::VectorXd* grad_holder
);

void 
hj_div 
(
    const Eigen::VectorXd& weights, 
    const Eigen::MatrixXd& returns, 
    double& div_holder, 
    Eigen::VectorXd* grad_holder
);

/*void penalty
 (
     const Eigen::VectorXd weights,
     const double pen_param,
     double& div_holder,
     Eigen::VectorXd* grad_holder
 );*/
