# EdaCal – Calculadora Estructurada (C++11)

## Requisitos
- g++ (C++11) y CMake ≥ 3.16 (opcional)

## Compilación con CMake
```bash
mkdir build
cd build
cmake ..
make
./EdaCal
```

## Compilación directa con g++
```bash
g++ -std=c++11 -O2 src/main.cpp -o EdaCal
./EdaCal
```

## Uso
- Ingrese expresiones usando `+ - * / ^ sqrt( )` y paréntesis.
- Asignación: `<id> = <expresion>`
- Variables: `ans` guarda el último resultado.
- Comandos:
  - `tree`     → imprime el árbol de la última expresión
  - `postfix`  → imprime notación postfija del último árbol
  - `prefix`   → imprime notación prefija del último árbol
  - `show x`   → muestra el valor de la variable `x`
  - `exit`     → salir
