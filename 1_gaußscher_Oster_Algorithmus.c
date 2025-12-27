#include <stdio.h>

int main(){
    //Variablen
    int jahreszahl = 0;
    int tag = 0 , monat = 0, ostertag = 0;
    int a = 0, b = 0, c = 0, k = 0, p = 0, q = 0, M = 0, d = 0, N = 0, e = 0;
    //Input Jahreszahl
    scanf("%d", &jahreszahl);
    //Berechnung
    a = jahreszahl % 19;
    b = jahreszahl % 4;
    c = jahreszahl % 7;
    k = jahreszahl / 100;
    p = (8 * k + 13) / 25;
    q = k / 4;
    M = (15 + k - p - q) % 30;
    d = (19 * a + M) % 30;
    N = (4 + k - q) % 7;
    e = (2 * b + 4 * c + 6 * d + N) % 7;
    tag = 22 + d + e;
    monat = 3 + ((tag -1) / 31);
    ostertag = (tag - 1) % 31 + 1;

    //Ausgabe Oster-Termin
    printf("%02d.%02d.%04d\n", ostertag, monat, jahreszahl);
    return 0;
}
/*
a = Jahr mod 19
b = Jahr mod 4
c = Jahr mod 7
k = Jahr div 100
p = (8k + 13) div 25
q = k div 4
M = (15 + k - p - q) mod 30
d = (19a + M) mod 30
N = (4 + k - q) mod 7
e = (2b + 4c + 6d + N) mod 7
Ostern = (22 + d + e)ter März (Der 32. März ist der 1. April usw.)

Die Umrechnung der Variable Ostern aus der Osterformel in ein korrektes Datum darf nur mit Ausdrücken erfolgen!
Verzweigungen (if, if-else, switch-case, ternärer Operator) oder gar Schleifen sind nicht erlaubt, da diese erst in späteren Kapiteln behandelt werden!
Der bei Wikipedia beschriebene Sonderfall, der nach dieser Berechnung zu einem falschen Ergebnis führt, ist nicht zu berücksichtigen bzw. zu implementieren. 
Es ist die obige Berechnung umzusetzen.

Für dieses Testat müssen 50% unserer Tests richtig sein, um das Testat zu bestehen.

*/