#pragma once
#pragma once
#include <string>
#include <cctype>

class CifradoCesar {
private:
    int desplazamiento;

public:
    // Constructor para definir el desplazamiento
    CifradoCesar(int d) : desplazamiento(d) {}

    // Método para cifrar texto
    std::string cifrar(const std::string& texto) {
        std::string resultado = "";
        for (char c : texto) {
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                resultado += ((c - base + desplazamiento) % 26) + base;
            }
            else {
                resultado += c;
            }
        }
        return resultado;
    }

    // Método para descifrar texto
    std::string descifrar(const std::string& texto) {
        std::string resultado = "";
        for (char c : texto) {
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                resultado += ((c - base - desplazamiento + 26) % 26) + base;
            }
            else {
                resultado += c;
            }
        }
        return resultado;
    }
};
