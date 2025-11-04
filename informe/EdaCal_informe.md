# Informe de Proyecto – Ed

## 1. Resumen
EdaCal es una calculadora estructurada en C++11 que evalúa expresiones aritméticas infijas utilizando ADTs del curso (Lista Enlazada, Pila y Árbol Binario). El sistema soporta `+ - * / ^ sqrt()`, variables y la variable especial `ans`, genera notación postfija/prefija e imprime el árbol de expresión.

## 2. Introducción
El proyecto integra estructuras de datos del libro *Estructuras de Datos y Algoritmos (Saavedra & Chang, 2025)*, aplicando pilas para conversión infijo–postfijo, listas enlazadas para representar la expresión de entrada y un árbol binario para modelar la jerarquía de operaciones.

## 3. Desarrollo
- **Estructuras:** `LinkedList`, `Stack`, `ASTNode`.
- **Librerías estándar:** `iostream`, `string`, `sstream`, `cmath`, `cctype`, `vector`, `map`, `algorithm`, `stdexcept` (todas mencionadas en el apunte).
- **Parser:** Shunting-Yard con precedencias (sqrt > ^ > * / > + -) y asociatividad derecha para `^`.
- **Árbol:** Construcción desde postfija con pila de nodos.
- **Evaluación:** Recursiva en postorden; variables almacenadas en `std::map<std::string,double>`.

## 4. Resultados y Discusión
Pruebas interactivas confirman la corrección de la conversión y evaluación, y la impresión de `tree`, `postfix`, `prefix`. La complejidad de conversión, construcción y evaluación es O(n) en número de tokens.

## 5. Conclusiones
El proyecto demuestra cómo los ADTs vistos en el curso permiten construir un evaluador de expresiones modular y eficiente, manteniendo la implementación alineada con el material del apunte.
