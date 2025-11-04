# Implementacja algorytmu Marching Squares w języku C

Projekt stanowi implementację algorytmu Marching Squares w języku C.  
Algorytm służy do generowania konturów w dwuwymiarowej siatce punktów na podstawie wartości skalarnych.  
Został zrealizowany w formie programu konsolowego. Wykorzystującego wyłącznie standardowe funkcje wejścia/wyjścia języka C.

---

## Opis działania

Algorytm Marching Squares analizuje kolejne kwadraty złożone z czterech sąsiednich punktów w siatce.  
Każdy z tych punktów posiada wartość binarną.  
Na podstawie kombinacji tych wartości określa się, przez które krawędzie danego kwadratu przebiega linia konturu.

W implementacji:
1. Generowana jest siatka punktów o losowych wartościach 0 i 1.  
2. Każdy zestaw czterech sąsiadujących punktów tworzy strukturę `Square`.  
3. Dla każdego kwadratu obliczany jest jego stan (`all`) na podstawie sumy i rozmieszczenia wartości narożników.  
4. Funkcja `segmentSquare()` tworzy tablicę odwzorowania (lookup table), określającą sposób interpolacji dla każdej konfiguracji.  
5. Na tej podstawie budowany jest wynikowy „ekran” (`screen`), który przedstawia przebieg konturów w postaci znaków ASCII.

Program wypisuje na konsolę:
- siatkę punktów wejściowych,
- wynikową mapę konturów (w postaci znaków `#` i spacji).
