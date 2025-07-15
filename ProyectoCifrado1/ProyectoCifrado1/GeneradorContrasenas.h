#pragma once
#pragma once
#include <string>
#include <random>

class GeneradorContrasenas {
public:
    static std::string generar(int longitud) {
        const std::string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
        std::random_device rd;
        std::mt19937 generador(rd());
        std::uniform_int_distribution<> distrib(0, caracteres.size() - 1);

        std::string contrasena;
        for (int i = 0; i < longitud; ++i) {
            contrasena += caracteres[distrib(generador)];
        }
        return contrasena;
    }
};
