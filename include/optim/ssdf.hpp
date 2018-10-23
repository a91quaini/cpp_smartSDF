#pragma once

#include <string>
#include "external/eigen/Eigen/Dense"

class ssdf {
    private:
        unsigned int N;
        unsigned int T;
        Eigen::MatrixXd returns;
    public:
        ssdf (std::string& datafile);
};
