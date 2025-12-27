#include <stdio.h>

int main() {
//Variablen setzen
    double bruttogehalt;
    double steuersatz;
    double steuerlast;
    double rabatt;
    int verheiratet, kinder;

//Input
    scanf("%lf%d%d", &bruttogehalt, &verheiratet, &kinder);
//Input überprüfen
    if(bruttogehalt <= 0 || verheiratet < 0 || verheiratet >= 2 || kinder < 0)
    printf("Eingabefehler\n");
    
//Rabatt berechnen
    if (verheiratet == 1) {
        rabatt = 0.2;
    }
    if (kinder != 0){
        rabatt += kinder * 0.1;
    }
    if (rabatt > 1.0){
        rabatt = 1.0;
    }
//Steuersatz berechnen
    if (bruttogehalt > 30000)
        steuersatz = 0.25;
    if (bruttogehalt > 20000 && bruttogehalt <= 30000)
        steuersatz = 0.2;
    if (bruttogehalt > 12000 && bruttogehalt <= 20000)
        steuersatz = 0.15;
    if (bruttogehalt < 12000)
        steuersatz = 0.12;
//Steuerberechnung
    steuerlast = bruttogehalt * (steuersatz * (1 - rabatt));
//Output Nomal
    printf("%.2lf\n", steuerlast);
    return 0;
}
/*
Gehalt in Euro	Steuersatz
bis einschl. 12.000	12 %
über 12.000 bis einschl. 20.000	15 %
über 20.000 bis einschl. 30.000	20 %
über 30.000	25 %

Verheirateten Steuerpflichtigen werden 20% ihrer Steuer erlassen
pro Kind werden 10% der Steuer erlassen.

Alle Steuernachlässe werden addiert, d.h. sie beziehen sich auf das Bruttogehalt. 
Negative Steuersätze gibt es nicht, in diesem Fall wird die Steuerlast auf 0 gesetzt.


Die Steuersätze sind in Konstanten vom Typ double zu halten.
Alle drei eingegebenen Werte sind auf Fehler zu überprüfen, es gibt aber keine max. Kinderzahl.

Das Programm gibt im Normalfall die abzuführende Steuer mit zwei Nachkommastellen aus:

Das Programm gibt im Fehlerfall den Text "`Eingabefehler"' (mit Zeilenumbruch) aus:

Der oben stehende Code ist verpflichtend, die Ein- und Ausgabe muss so erfolgen!
Lediglich die dabei verwendeten Variablen sind frei!
Weitere Ein- und Ausgaben dürfen nicht erfolgen!
Das Programm darf keine Schleifen und Funktionen enthalten!*/