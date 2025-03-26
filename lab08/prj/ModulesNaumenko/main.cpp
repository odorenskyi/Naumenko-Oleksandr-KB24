#include "libModulesNaumenko.h"
#include <cmath>
#include <stdexcept>

namespace Naumenko {
    double calculateS(double x, double y, double z) {
        if (cos(z + y) + x * x < 0) {
            throw std::domain_error("Недопустиме значення під коренем");
        }
        
        double numerator = pow(2 * z + 1, 2) - sqrt(std::abs(y - 0.5 * z));
        double denominator = sqrt(cos(z + y) + x * x);

        return z + M_PI * (numerator / denominator);
    }
}
