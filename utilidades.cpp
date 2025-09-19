#include "utilidades.h"

#include <iostream>
#include <string>

std::string aMinuscula(std::string ingreso)
{
    for (size_t i = 0; i < ingreso.length(); i++)
    {
        if (ingreso[i] >= 'A' && ingreso[i] <= 'Z')
        {
            ingreso[i] = ingreso[i] + 32;  /// convierte a minúscula usando ASCII
        }
    }
    return ingreso;
}
