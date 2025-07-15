#include <iostream>
#include <fstream>
#include <string>
#include "CifradoCesar.h"
#include "CifradoXOR.h"
#include "CifradoVigenere.h"
#include "GeneradorContrasenas.h"
#include "CifradoDES.h"

// Función para comparar dos archivos línea por línea
bool archivosSonIguales(const std::string& ruta1, const std::string& ruta2) {
    std::ifstream archivo1(ruta1);
    std::ifstream archivo2(ruta2);

    if (!archivo1.is_open() || !archivo2.is_open()) {
        return false;
    }

    std::string linea1, linea2;
    while (true) {
        bool finArchivo1 = !std::getline(archivo1, linea1);
        bool finArchivo2 = !std::getline(archivo2, linea2);

        if (finArchivo1 && finArchivo2) {
            return true; // Ambos terminaron juntos
        }
        if (finArchivo1 != finArchivo2) {
            return false; // Uno terminó antes que otro
        }
        if (linea1 != linea2) {
            return false; // Líneas diferentes
        }
    }
}

void mostrarMenu() {
    std::cout << "=== PROYECTO CIFRADO DE ARCHIVOS ===\n";
    std::cout << "Selecciona una opción:\n";
    std::cout << "1. Cifrado Cesar\n";
    std::cout << "2. Cifrado XOR\n";
    std::cout << "3. Cifrado Vigenere\n";
    std::cout << "4. Generador de contraseñas seguras\n";
    std::cout << "5. Cifrado DES simulado\n";
    std::cout << "0. Salir\n";
    std::cout << "Opción: ";
}

int main() {
    std::string rutaOriginal = "Datos/crudo/datos.txt";
    std::string rutaCifrado = "Datos/cifrados/datos_cifrado.txt";
    std::string rutaDescifradoTemporal = "Datos/cifrados/descifrado_temporal.txt";

    int opcion = -1;

    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar buffer después de leer opción

        if (opcion >= 1 && opcion <= 3) {
            std::ifstream archivoOriginal(rutaOriginal);
            if (!archivoOriginal.is_open()) {
                std::cerr << "❌ Error al abrir el archivo original: " << rutaOriginal << std::endl;
                continue;
            }

            std::ofstream archivoCifrado(rutaCifrado);
            if (!archivoCifrado.is_open()) {
                std::cerr << "❌ Error al crear el archivo cifrado: " << rutaCifrado << std::endl;
                continue;
            }

            std::string linea;

            if (opcion == 1) {
                CifradoCesar cesar(3);
                while (std::getline(archivoOriginal, linea)) {
                    archivoCifrado << cesar.cifrar(linea) << std::endl;
                }
                archivoOriginal.close();
                archivoCifrado.close();

                // Descifrar y guardar en archivo temporal
                std::ifstream archivoCifradoLeer(rutaCifrado);
                std::ofstream archivoDescifrado(rutaDescifradoTemporal);
                std::cout << "\n🟢 Contenido DESCIFRADO (Cesar):\n";
                while (std::getline(archivoCifradoLeer, linea)) {
                    std::string desc = cesar.descifrar(linea);
                    std::cout << desc << std::endl;
                    archivoDescifrado << desc << std::endl;
                }
                archivoCifradoLeer.close();
                archivoDescifrado.close();

                // Verificación
                if (archivosSonIguales(rutaOriginal, rutaDescifradoTemporal)) {
                    std::cout << "\n✅ Verificación exitosa: El archivo descifrado es idéntico al original.\n";
                }
                else {
                    std::cout << "\n❌ Verificación fallida: El archivo descifrado NO coincide con el original.\n";
                }
            }
            else if (opcion == 2) {
                CifradoXOR xorCifrado('K');
                while (std::getline(archivoOriginal, linea)) {
                    archivoCifrado << xorCifrado.cifrar(linea) << std::endl;
                }
                archivoOriginal.close();
                archivoCifrado.close();

                std::ifstream archivoCifradoLeer(rutaCifrado);
                std::ofstream archivoDescifrado(rutaDescifradoTemporal);
                std::cout << "\n🟢 Contenido DESCIFRADO (XOR):\n";
                while (std::getline(archivoCifradoLeer, linea)) {
                    std::string desc = xorCifrado.descifrar(linea);
                    std::cout << desc << std::endl;
                    archivoDescifrado << desc << std::endl;
                }
                archivoCifradoLeer.close();
                archivoDescifrado.close();

                if (archivosSonIguales(rutaOriginal, rutaDescifradoTemporal)) {
                    std::cout << "\n✅ Verificación exitosa: El archivo descifrado es idéntico al original.\n";
                }
                else {
                    std::cout << "\n❌ Verificación fallida: El archivo descifrado NO coincide con el original.\n";
                }
            }
            else if (opcion == 3) {
                CifradoVigenere vigenere("clave");
                while (std::getline(archivoOriginal, linea)) {
                    archivoCifrado << vigenere.cifrar(linea) << std::endl;
                }
                archivoOriginal.close();
                archivoCifrado.close();

                std::ifstream archivoCifradoLeer(rutaCifrado);
                std::ofstream archivoDescifrado(rutaDescifradoTemporal);
                std::cout << "\n🟢 Contenido DESCIFRADO (Vigenere):\n";
                while (std::getline(archivoCifradoLeer, linea)) {
                    std::string desc = vigenere.descifrar(linea);
                    std::cout << desc << std::endl;
                    archivoDescifrado << desc << std::endl;
                }
                archivoCifradoLeer.close();
                archivoDescifrado.close();

                if (archivosSonIguales(rutaOriginal, rutaDescifradoTemporal)) {
                    std::cout << "\n✅ Verificación exitosa: El archivo descifrado es idéntico al original.\n";
                }
                else {
                    std::cout << "\n❌ Verificación fallida: El archivo descifrado NO coincide con el original.\n";
                }
            }
        }
        else if (opcion == 4) {
            int longitud;
            std::cout << "Ingresa la longitud de la contraseña: ";
            std::cin >> longitud;
            std::cin.ignore();
            std::string contrasena = GeneradorContrasenas::generar(longitud);
            std::cout << "🔐 Contraseña generada: " << contrasena << "\n";
        }
        else if (opcion == 5) {
            CifradoDES des("MiClaveSecreta");

            std::ifstream archivoOriginal(rutaOriginal);
            if (!archivoOriginal.is_open()) {
                std::cerr << "❌ Error al abrir el archivo original: " << rutaOriginal << std::endl;
                continue;
            }

            std::ofstream archivoCifrado(rutaCifrado);
            if (!archivoCifrado.is_open()) {
                std::cerr << "❌ Error al crear el archivo cifrado: " << rutaCifrado << std::endl;
                continue;
            }

            std::string linea;
            while (std::getline(archivoOriginal, linea)) {
                archivoCifrado << des.cifrar(linea) << std::endl;
            }
            archivoOriginal.close();
            archivoCifrado.close();

            std::ifstream archivoCifradoLeer(rutaCifrado);
            std::ofstream archivoDescifrado(rutaDescifradoTemporal);
            std::cout << "\n🟢 Contenido DESCIFRADO (DES simulado):\n";
            while (std::getline(archivoCifradoLeer, linea)) {
                std::string desc = des.descifrar(linea);
                std::cout << desc << std::endl;
                archivoDescifrado << desc << std::endl;
            }
            archivoCifradoLeer.close();
            archivoDescifrado.close();

            if (archivosSonIguales(rutaOriginal, rutaDescifradoTemporal)) {
                std::cout << "\n✅ Verificación exitosa: El archivo descifrado es idéntico al original.\n";
            }
            else {
                std::cout << "\n❌ Verificación fallida: El archivo descifrado NO coincide con el original.\n";
            }
        }
        else if (opcion == 0) {
            std::cout << "👋 Saliendo del programa. ¡Gracias!\n";
        }
        else {
            std::cout << "❌ Opción inválida. Intenta nuevamente.\n";
        }

        std::cout << "\n--------------------------------------\n";

    } while (opcion != 0);

    return 0;
}
