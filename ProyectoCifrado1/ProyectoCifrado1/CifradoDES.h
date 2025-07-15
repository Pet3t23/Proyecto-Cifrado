#pragma once
#include <string>
#include <algorithm>

class CifradoDES {
private:
    std::string clave;

    // Función simple para "mezclar" texto con clave (XOR + rotación)
    std::string transformarBloque(const std::string& bloque, bool cifrar) {
        std::string resultado = bloque;
        for (size_t i = 0; i < bloque.size(); ++i) {
            // XOR con carácter de la clave (modular)
            char c = bloque[i] ^ clave[i % clave.size()];
            // Si cifrar: rotar bits a la izquierda 1, si descifrar rotar a la derecha 1
            if (cifrar)
                c = (c << 1) | ((c & 0x80) ? 1 : 0);
            else
                c = (c >> 1) | ((c & 0x01) ? 0x80 : 0);
            resultado[i] = c;
        }
        return resultado;
    }

public:
    CifradoDES(const std::string& k) : clave(k) {}

    std::string cifrar(const std::string& texto) {
        std::string resultado = texto;
        // Procesar bloques de 8 caracteres
        for (size_t i = 0; i < resultado.size(); i += 8) {
            std::string bloque = resultado.substr(i, 8);
            // Si bloque < 8, rellenar con espacios
            if (bloque.size() < 8)
                bloque.append(8 - bloque.size(), ' ');
            std::string bloqueCifrado = transformarBloque(bloque, true);
            resultado.replace(i, 8, bloqueCifrado);
        }
        return resultado;
    }

    std::string descifrar(const std::string& texto) {
        std::string resultado = texto;
        for (size_t i = 0; i < resultado.size(); i += 8) {
            std::string bloque = resultado.substr(i, 8);
            std::string bloqueDescifrado = transformarBloque(bloque, false);
            resultado.replace(i, 8, bloqueDescifrado);
        }
        return resultado;
    }
};
