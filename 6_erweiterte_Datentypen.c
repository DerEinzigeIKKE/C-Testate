#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
//Gegeben ist eine Datenstruktur für eine Parabel (bzw. Polynom zweiten Grades, a*x^2 + b*x + c) s.Header-Datei.
#include "testat-6.h" // diese Zeile nicht abändern! Die Datei testat-6.h nicht verändern und nicht umbenennen!

// Vorgegeben
void print_polynome(polynom p[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%5.2lf x^2 + %5.2lf x + %5.2lf\n", p[i].a, p[i].b, p[i].c);
}

int main() {
  polynom p1[] = {
    {1,2,3},
    {2,5,-19},
    {2,6,-19},
    {0,0,0},
    {0,5,0},
    {0,7,0},
    {-1,0,0}
  };
  int n = sizeof(p1) / sizeof(polynom);
  polynom* p2 = (polynom*) malloc(n * sizeof(polynom));
  memcpy(p2, p1, sizeof(p1));
//Ausgabe der Ursprungsfolge
  printf("Vor Sortierung:\n");
  print_polynome(p1, n);
//Ausgabe nach Quicksort
  qsort(p1, n, sizeof(polynom), cmp_polynom);
  printf("Nach Quicksort:\n");
  print_polynome(p1, n);
//Ausgabe nach Bubblesort
  bsort(p2, n, sizeof(polynom), cmp_polynom);
  printf("Nach Bubblesort:\n");
  print_polynome(p2, n);

  free(p2);
  return 0;
}

/*
a) Entwickeln Sie die Funktion cmp_polynom für Polynomvergleiche derart dass

bei verschiedenen a dieses a signifikant ist
bei gleichen a aber verschiedenen b dieses b signifikant ist
bei gleichen a, b das c signifikant ist.

Rückgaben:

-1 falls das erste übergebene Polynom das kleinere ist
0 falls die zwei übergebenen Polynome identisch sind
+1 falls das zweite übergebene Polynom das kleinere ist

Testen Sie Ihre Funktion cmp_polynom, indem Sie den Quicksort-Algorithmus aus der Standardbibliothek stdlib.h  mit dieser Vergleichsfunktion aufrufen (siehe https://linux.die.net/man/3/qsort . 
*/
int cmp_polynom(const void* pp1, const void* pp2) {
    const polynom* p1 = (const polynom*) pp1;
    const polynom* p2 = (const polynom*) pp2;
    //Vergleiche A
    if (p1->a > p2->a)
        return 1;
    if (p1->a < p2->a)
        return -1;
    //Vergleiche B
    if (p1->b > p2->b)
        return 1;
    if (p1->b < p2->b)
        return -1;
    //Vergleiche C
    if (p1->c > p2->c)
        return 1;
    if (p1->c < p2->c)
        return -1;
    return 0;
}
/*b) Entwickeln Sie einen generischen (datentypunabhängigen) Bubblesort (bsort) mit der gleichen Schnittstelle wie der Quicksort aus der Bibliothek stdlib.h. 
Diese Funktion muss komplett frei von polynomspezifischem Code sein. 
Das heißt, dass die Funktion auch mit anderen Datentypen oder Datenstrukturen aufgerufen werden können soll.
*/
void bsort(void *base, size_t nel, size_t width, int (*compar)(const void*, const void*)) {
  // ToDo
}

/*
Kommentare:

Die gesamte Kommunikation der Funktionen muss über die genannten Schnittstellen erfolgen, diese dürfen nicht verändert werden.
Innerhalb der Funktion sind keine Ein- und Ausgaben erlaubt.
Es sind keine globalen Variablen erlaubt.
Die Header-Datei ist Basis der Abgabe und darf nicht verändert werden, auch nicht der Name der Datei (testat-6.h), da dieser sonst nicht gefunden wird!
Die main-Funktion ist nicht Bestandteil des Testats, sie darf im abgegebenen Programm vorkommen, wird aber nicht bewertet. 
Es wird empfohlen, noch weitere / andere Tests in das Hauptprogramm einzubauen.
*/