#include "Clamp.h"

using namespace SOAR;
using namespace Math;

void Clamp::Int(int& val, int min, int max)
{
    if (val < min)
        val = min;
    else if (val > max)
        val = max;
}
