#include <iostream>
#include <fstream>
#include "optim/ssdf.hpp"

ssdf::ssdf (std::string& datafile_name)
{
    std::ifstream datafile;
    datafile.open(datafile_name);
    
    for (unsigned int i=0; i<5; ++i)
        for (unsigned j=0; j<5;++j)
        {
            datafile >> returns(i,j);
        }
    datafile.close();
}
