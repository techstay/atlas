#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iomanip>
#include <iostream>
#include <limits>

using boost::multiprecision::cpp_dec_float_100;
using std::cout;
using std::endl;

int main()
{
    cout << std::setprecision(std::numeric_limits<cpp_dec_float_100>::digits10)
         << boost::math::constants::pi<cpp_dec_float_100>() << endl;
}