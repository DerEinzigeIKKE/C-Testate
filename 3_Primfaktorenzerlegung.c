#include <stdio.h>

void faktorzerlegung (int zahl_in);
int ist_prim (int zahl_in);

int main() {
//Variablen festlegen
    int zahl = 0;
//Input
    scanf("%d", &zahl);
//Input zahl < 2 abfangen
    if (zahl < 2) {
        printf("%d kann nicht zerlegt werden.\n", zahl);
        return 0;
    }
//Primzahlen abfangen
    if (ist_prim(zahl) == 1) {
        printf("%d ist prim.\n", zahl);
        return 0;
    }
//Berechnung
    faktorzerlegung(zahl);
    return 0;
}

void faktorzerlegung(int zahl_in){
    for (int teiler = 2; teiler <= zahl_in; teiler++) {
        while (zahl_in % teiler == 0) {
            zahl_in = zahl_in / teiler;
            printf("%d\n", teiler);
        }
    }
}
int ist_prim (int zahl_in){
    if (zahl_in <= 1) return 0;
    for (int teiler = 2; teiler * teiler <= zahl_in; teiler++) {
        if (zahl_in % teiler == 0) {
            return 0;
        }
    }
    return 1;
}

/*Entwickeln oder recherchieren Sie einen Algorithmus zur Primfaktorzerlegung und codieren Sie Ihren Algorithmus in C. 
So ist bspw. die Primfaktorzerlegung von 6936 das Produkt 2*2*2*3*17*17

Weitere Ein- und Ausgaben dürfen nicht erfolgen.
Das Programm darf keine Felder enthalten. Funktionen sind erlaubt, Prototypen sind dann aber Pflicht.
Testen Sie Ihr Programm bitte auch mit großen (Prim-) Zahlen als Eingabe!!!
*/