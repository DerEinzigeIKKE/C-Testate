#include <stdio.h>
#include <string.h>
void skytale(char * in, int n, char * out);
void skytale(char * in, int n, char * out) {
    int l = strlen(in); //Länge des zu verschlüsselnden Textes
    int rows = (l + n - 1) / n; // rows berechnen mit Überlauf, falls l%n != 0
    char temp[rows][n]; //Erszeugt temporäres 2D-Array mit Dimensionen rows * Schlüssellänge

    for(int i = 0; i < l; i++){ //Beschreiben des temporären Arrays
        int row = i / n;        // Zeile = Index i / Schlüssellänge
        int col = i % n;        // Spalte = Index i modulo Schlüssellänge
        temp[row][col] = in[i];
    }

    for(int i = 0; i < l; i++){ //Auslesen des temporären Arrays in neuer Reihenfolge
        int col = i / rows;     // Spalte = Index i / Anzahl der Zeilen
        int row = i % rows;     // Zeile = Index i modulo Anzahl der Zeilen
        out[i] = temp[row][col];
    }
    out[l] = '\0';
}

int main() {
  char s1[1000] = "DIESERKLARTEXTISTJETZTZUVERSCHLUESSELN12",
  s2[1000]="***bereits*verwendete*zeichenkette*mit*inhalt***", // Verschlüsseln hier hinein
  s3[1000]; // Entschlüsseln in diese Variable
  int n = 5; // Schlüssellänge
  int l = strlen(s1); // Textlänge
  printf("%s\n", s1); //gibt unverschlüsselten Text aus
  printf("Laenge: %d\n", l); //gibt Länge des Text aus

  skytale(s1, n, s2); // Chiffriere s1 zu s2 mit n Buchstaben pro Umdrehung
  printf("%s\n", s2); //gibt verschlüsselten Text aus

  if (l % n == 0) { //falls Länge vielfaches von Schlüssel ist, kann entschlüsselt werden
    skytale(s2, l / n , s3); // Chiffriere zurueck
    printf("%s\n", s3); //gibt entschlüsselten Text aus
    if (!strcmp(s1, s3)) {
      printf("In diesem Fall OK\n");
    }
    else {
      printf("Problem!\n");
    }
  }
  return 0;
}

/*Programmiertechnisch ist es einfacher, die "'Zeilen"' und "'Spalten"' der Skytale zu tauschen!

Zur Verschlüsselung wird der Text in Blöcke der Länge n eingeteilt, die zeilenweise geschrieben werden

Der String wird auch nicht in Großbuchstaben transformiert oder Leerzeichen entfernt (wie im Beispiel der TU Freiberg durchgeführt)!
Getestet wird aber wieder nur die Funktion, d.h. alle Funktionalität muss innerhalb der Funktion passieren. 

Die gesamte Kommunikation der Funktion muss über die Schnittstelle erfolgen.
Innerhalb der Funktion sind keine Ein- und Ausgaben erlaubt.
Es sind keine globalen Variablen erlaubt.
Ein Prototyp der Funktion ist Pflicht.
Gehen Sie davon aus, dass der übergebene Parameter n immer größer als 0 ist (n>0, da ein Stift nicht weniger als die Dicke von 1 Zeichen haben darf).
Es werden keine Leerzeichen eingefügt, auch nicht wenn die Länge des Eingabetextes nicht durch n teilbar ist!
Verändern Sie den zu chiffrierenden Text nicht!!!!!!
Der chiffrierte Text muss die gleiche Länge haben wie der zu chiffrierende Text!!
Auch wenn es in dem obigen Beispiel danach aussieht, es werden keine zweidimensionalen Felder benötigt!
Tip: Der eigentliche Chiffrier-Teil Ihres Programms ist in drei bis fünf Zeilen codierbar.
Anmerkung: Wenn n die Schlüssellänge ist und l die Länge des Strings und l ein ganzzahliges Vielfaches von n ist, so kann mit einem Dechiffrierungs-Schlüssel mit demselben Algorithmus dechiffriert werden. 
Dies kann zum Testen des Programms genutzt werden.
*/