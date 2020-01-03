/*!
*
* @author spades
* @date 1/3/20
*
*/

#ifndef LOAD_MATRIX_FILE_INCLUDE_LOAD_MATRIX_FILE_CPP_
#define LOAD_MATRIX_FILE_INCLUDE_LOAD_MATRIX_FILE_CPP_

#include <Eigen/Dense>
#include <fstream>

using namespace std;
using namespace Eigen;

namespace Eigen {

/*!
 * @brief This class exists for the sole purpose of  loading matrices stored in files to Eigen matrices. The original
 * idea was to load matrices generated in matlab.
 */
class LoadMatrixFile {

 public:


    /*!
     * @brief This functions does all the work and load a matrix stored in a file to an eigen matrix
     *
     * @param [in] matrix_file_name the path the the matrix file (in general, absolute path)
     *
     * @return The matrix loaded
     *
     */
    template<typename T, int _Rows, int _Cols>
    static Matrix<T, _Rows, _Cols> load_from_file(const std::string &matrix_file_name){

        Matrix<T, _Rows, _Cols> new_matrix = Matrix<T, _Rows, _Cols>::Constant(0);

        std::fstream matrix_file_stream(matrix_file_name, std::ios_base::in);

        T a;

        if(matrix_file_stream.is_open()) {

            for (int i = 0; i < _Rows; ++i) {

                for (int j = 0; j < _Cols && (matrix_file_stream >> a); ++j) {

                    new_matrix(i, j) = a;

                }

            }

        }

        return new_matrix;

    }

};

}

#endif //LOAD_MATRIX_FILE_INCLUDE_LOAD_MATRIX_FILE_CPP_
