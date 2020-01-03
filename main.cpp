/*!
*
* @author spades
* @date 1/3/20
*
*/

#include "load_matrix_file.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(){

    cout << Eigen::LoadMatrixFile::load_from_file<int,5,5>(std::string("matrix_test.m")) << endl;

}

