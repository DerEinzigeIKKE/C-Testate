#ifndef testat_6
#define testat_6 1

typedef struct { // Datenstruktur fuer Polynome zweiten Grades
  double a;
  double b;
  double c;
} polynom;

void bsort ( // Bubblesort
  void *base,
  size_t nel,	// Anzahl Elemente
  size_t width, // Groesse eines Elements
  int (*compar)(const void*, const void*) // Funktion zum Vergleichen zweier Elemente
);
int cmp_polynom(const void* p1, const void* p2); // Funktion zum Vergleichen zweier Polynome
void print_polynome(polynom p[], int n); // Funktion zum Anzeigen eines Arrays von Polynomen

#endif

//Gehört zu Testat 6 "Erweiterte Datentypen"