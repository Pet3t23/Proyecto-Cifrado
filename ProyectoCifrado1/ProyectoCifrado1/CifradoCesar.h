#pragma once
#include <string>

// Clase para cifrado César con desplazamiento fijo
class CifradoCesar {
private:
    int desplazamiento;

public:
    CifradoCesar(int d) : desplazamiento(d) {}

    // Cifrar texto desplazando caracteres ASCII
    std::string cifrar(const std::string& texto) {
        std::string resultado = texto;
        for (char& c : resultado) {
            c = c + desplazamiento;
        }
        return resultado;
    }

    // Descifrar texto desplazando en sentido contrario
    std::string descifrar(const std::string& texto) {
        std::string resultado = texto;
        for (char& c : resultado) {
            c = c - desplazamiento;
        }
        return resultado;
    }
};
