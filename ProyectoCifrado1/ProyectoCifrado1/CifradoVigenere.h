#pragma once

#include <string>
#include <cctype>

class CifradoVigenere {
private:
    std::string clave;

public:
    CifradoVigenere(const std::string& k) : clave(k) {}

    std::string cifrar(const std::string& texto) {
        std::string resultado = "";
        int j = 0;

        for (char c : texto) {
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                char claveChar = std::tolower(clave[j % clave.length()]);
                int desplazamiento = claveChar - 'a';
                resultado += ((c - base + desplazamiento) % 26) + base;
                j++;
            }
            else {
                resultado += c;
            }
        }

        return resultado;
    }

    std::string descifrar(const std::string& texto) {
        std::string resultado = "";
        int j = 0;

        for (char c : texto) {
            if (std::isalpha(c)) {
                char base = std::isupper(c) ? 'A' : 'a';
                char claveChar = std::tolower(clave[j % clave.length()]);
                int desplazamiento = claveChar - 'a';
                resultado += ((c - base - desplazamiento + 26) % 26) + base;
                j++;
            }
            else {
                resultado += c;
            }
        }

        return resultado;
    }
};
