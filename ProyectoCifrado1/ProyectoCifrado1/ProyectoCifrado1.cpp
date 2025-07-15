#include <iostream>
#include <fstream>
#include <string>
#include "CifradoCesar.h"
#include "CifradoXOR.h"
#include "CifradoVigenere.h"

int main() {
    std::string rutaOriginal = "Datos/crudo/datos.txt";
    std::string rutaCifrado = "Datos/cifrados/datos_cifrado.txt";

    std::cout << "=== PROYECTO CIFRADO DE ARCHIVOS ===\n";
    std::cout << "Selecciona el tipo de cifrado:\n";
    std::cout << "1. Cifrado César\n";
    std::cout << "2. Cifrado XOR\n";
    std::cout << "3. Cifrado Vigenère\n";
    std::cout << "Opción: ";

    int opcion;
    std::cin >> opcion;

    // Abrir archivo original para leer
    std::ifstream archivoOriginal(rutaOriginal);
    if (!archivoOriginal.is_open()) {
        std::cerr << "❌ Error al abrir el archivo original: " << rutaOriginal << std::endl;
        return 1;
    }

    // Abrir archivo de salida para guardar el cifrado
    std::ofstream archivoCifrado(rutaCifrado);
    if (!archivoCifrado.is_open()) {
        std::cerr << "❌ Error al crear el archivo cifrado: " << rutaCifrado << std::endl;
        return 1;
    }

    std::string linea;

    if (opcion == 1) {
        // César
        CifradoCesar cesar(3); // desplazamiento de 3
        while (std::getline(archivoOriginal, linea)) {
            archivoCifrado << cesar.cifrar(linea) << std::endl;
        }
        archivoOriginal.close();
        archivoCifrado.close();

        std::ifstream archivoCifradoLeer(rutaCifrado);
        std::cout << "\n🟢 Contenido DESCIFRADO (César):\n";
        while (std::getline(archivoCifradoLeer, linea)) {
            std::cout << cesar.descifrar(linea) << std::endl;
        }
        archivoCifradoLeer.close();

    }
    else if (opcion == 2) {
        // XOR
        CifradoXOR xorCifrado('K'); // clave XOR = 'K'
        while (std::getline(archivoOriginal, linea)) {
            archivoCifrado << xorCifrado.cifrar(linea) << std::endl;
        }
        archivoOriginal.close();
        archivoCifrado.close();

        std::ifstream archivoCifradoLeer(rutaCifrado);
        std::cout << "\n🟢 Contenido DESCIFRADO (XOR):\n";
        while (std::getline(archivoCifradoLeer, linea)) {
            std::cout << xorCifrado.descifrar(linea) << std::endl;
        }
        archivoCifradoLeer.close();

    }
    else if (opcion == 3) {
        // Vigenère
        CifradoVigenere vigenere("clave"); // clave = "clave"
        while (std::getline(archivoOriginal, linea)) {
            archivoCifrado << vigenere.cifrar(linea) << std::endl;
        }
        archivoOriginal.close();
        archivoCifrado.close();

        std::ifstream archivoCifradoLeer(rutaCifrado);
        std::cout << "\n🟢 Contenido DESCIFRADO (Vigenère):\n";
        while (std::getline(archivoCifradoLeer, linea)) {
            std::cout << vigenere.descifrar(linea) << std::endl;
        }
        archivoCifradoLeer.close();

    }
    else {
        std::cout << "❌ Opción inválida. Intenta nuevamente.\n";
    }

    return 0;
}
