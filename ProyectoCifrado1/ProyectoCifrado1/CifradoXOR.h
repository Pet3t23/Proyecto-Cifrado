#pragma once
#pragma once
#include <string>

class CifradoXOR {
private:
    char clave; // clave para XOR

public:
    CifradoXOR(char k) : clave(k) {}

    std::string cifrar(const std::string& texto) {
        std::string resultado = texto;
        for (size_t i = 0; i < resultado.size(); i++) {
            resultado[i] = resultado[i] ^ clave;
        }
        return resultado;
    }

    // El descifrado es igual que cifrado en XOR
    std::string descifrar(const std::string& texto) {
        return cifrar(texto);
    }
};
