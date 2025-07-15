# Proyecto Cifrado de Archivos en C++

## Introducción

Este proyecto en C++ permite proteger información sensible almacenada en archivos de texto mediante algoritmos de cifrado simétrico.  
Incluye métodos de cifrado César, XOR, Vigenère y un cifrado DES simulado, además de un generador de contraseñas seguras.

## Funcionalidad

- Leer un archivo de texto con datos simulados (usuarios, contraseñas).
- Cifrar y guardar el contenido en un archivo seguro.
- Descifrar el archivo cifrado y recuperar el contenido original.
- Verificación automática para asegurar que el descifrado coincide con el archivo original.
- Generador de contraseñas con longitud configurable.

## Cómo usar

1. Compila el proyecto en Visual Studio 2022.
2. Ejecuta el programa y elige el cifrado deseado desde el menú.
3. El programa cifrará el archivo original (`Datos/crudo/datos.txt`) y guardará el resultado en (`Datos/cifrados/datos_cifrado.txt`).
4. Se mostrará el contenido descifrado y se verificará automáticamente la integridad del archivo.
5. También puedes generar contraseñas seguras desde el menú.
