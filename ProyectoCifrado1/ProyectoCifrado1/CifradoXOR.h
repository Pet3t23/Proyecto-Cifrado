#pragma once
#include <string>

// Clase para cifrado XOR con clave car�cter
class CifradoXOR {
private:
    char clave;

public:
    CifradoXOR(char k) : clave(k) {}

    // Cifrar o descifrar con operaci�n XOR (id�ntica para ambos)
    std::string cifrar(const std::string& texto) {
        std::string resultado = texto;
        for (char& c : resultado) {
            c = c ^ clave;
        }
        return resultado;
    }

    std::string descifrar(const std::string& texto) {
        // XOR es sim�trico
        return cifrar(texto);
    }
};
