#include <stdio.h>

int main()
{
    float num1, num2, suma, resta;

    // Solicita al usuario dos números de punto flotante
    printf("Introduce el primer número de punto flotante: ");
    scanf("%f", &num1);
    printf("Introduce el segundo número de punto flotante: ");
    scanf("%f", &num2);

    // Realiza la suma y la resta
    suma = num1 + num2;
    resta = num1 - num2;

    // Muestra los resultados
    printf("Suma: %f\n", suma);
    printf("Resta: %f\n", resta);

    return 0;
}
/*Para realizar operaciones directamente sobre la representación binaria de números 
de punto flotante sería necesario un conocimiento profundo del estándar IEEE 754, 
incluyendo cómo se codifican el signo, el exponente y la mantisa, y cómo se normalizan 
y denormalizan los valores para realizar operaciones aritméticas. Esto va más allá de 
lo que un simple programa de ejemplo puede ilustrar.*/
