#include <stdio.h>

// Función para invertir los bits de un número
unsigned int invertirBits(unsigned int num)
{
    // Variable para el número de bits de 'num'
    unsigned int numBits = sizeof(num) * 8;
    unsigned int inverso = 0;
    for (unsigned int i = 0; i < numBits; i++)
    {
        // Si el bit actual está encendido, lo enciende en 'inverso'
        if (num & (1 << i))
        {
            inverso &= ~(1 << i);
        }
        else
        {
            inverso |= (1 << i);
        }
    }
    return inverso;
}

// Función para convertir un número binario a su complemento a dos
unsigned int complementoADos(unsigned int num)
{
    // Primero invierte los bits del número
    unsigned int inverso = invertirBits(num);
    // Luego, suma 1 al resultado para obtener el complemento a dos
    return inverso + 1;
}

int main()
{
    unsigned int num;
    printf("Introduce un número binario (como entero): ");
    scanf("%u", &num);

    // Convierte el número al complemento a dos y lo imprime
    unsigned int resultado = complementoADos(num);
    printf("El complemento a dos del número introducido es: %u\n", resultado);

    return 0;
}
