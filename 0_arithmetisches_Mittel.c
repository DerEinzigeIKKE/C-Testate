#include <stdio.h>

int main() {
    //Variablen festlegen
    int a = 0;
    int b = 0;
    int mittel = 0;
    //Input
    scanf("%d%d", &a, &b);
    //Mittelwert berechnen
    mittel = (a + b) / 2;
    //Ausgabe
    printf("%d", mittel);
    return 0;
}