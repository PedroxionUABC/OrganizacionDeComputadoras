#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones para operaciones binarias
int sumaBinaria(int, int);
int restaBinaria(int, int);
int multiplicarBinaria(int, int);
int dividirBinaria(int, int);

// Función principal
int main()
{
    int a, b;
    printf("Introduce el primer numero binario: ");
    scanf("%d", &a);
    printf("Introduce el segundo numero binario: ");
    scanf("%d", &b);

    // Realiza y muestra los resultados de las operaciones
    printf("Suma: %d\n", sumaBinaria(a, b));
    printf("Resta: %d\n", restaBinaria(a, b));
    printf("Multiplicacion: %d\n", multiplicarBinaria(a, b));
    printf("Division: %d\n", dividirBinaria(a, b));

    return 0;
}

// Realiza la suma binaria
int sumaBinaria(int a, int b)
{
    int acarreo; // Almacena el acarreo en la suma
    while (b != 0)
    {
        // 'acarreo' almacena los bits comunes de 'a' y 'b'
        acarreo = (a & b) << 1;
        // Suma de bits de 'a' y 'b' donde al menos uno de los bits no es 1
        a = a ^ b;
        // Transfiere el acarreo
        b = acarreo;
    }
    return a;
}

// Realiza la resta binaria
int restaBinaria(int a, int b)
{
    // Utiliza complemento a dos para la resta
    b = sumaBinaria(~b, 1);   // Invierte los bits de 'b' y suma 1
    return sumaBinaria(a, b); // Suma 'a' y el complemento a dos de 'b'
}

// Realiza la multiplicación binaria
int multiplicarBinaria(int a, int b)
{
    int resultado = 0; // Almacena el resultado de la multiplicación
    while (b != 0)
    { // Itera hasta que 'b' sea 0
        // Si el bit más bajo de 'b' es 1, añade 'a' al resultado
        if (b & 1)
            resultado = sumaBinaria(resultado, a);
        // Desplaza 'a' un bit a la izquierda
        a <<= 1;
        // Desplaza 'b' un bit a la derecha
        b >>= 1;
    }
    return resultado;
}

// Realiza la división binaria
int dividirBinaria(int a, int b)
{
    int cociente = 0; // Almacena el cociente de la división
    while (a >= b)
    {                 // Mientras el dividendo sea mayor o igual al divisor
        int temp = b; // Temporal para el divisor
        int i = 1;    // Inicializa el contador de desplazamiento
        while (a >= (temp << 1))
        {               // Mientras el dividendo sea mayor que el doble del divisor
            temp <<= 1; // Duplica el valor del divisor
            i <<= 1;    // Duplica la posición del bit de resultado
        }
        a = restaBinaria(a, temp); // Resta el valor temporal del dividendo
        cociente |= i;             // Añade el valor de 'i' al cociente
    }
    return cociente; // Retorna el cociente de la división
}
