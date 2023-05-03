#include <stdlib.h> // rand(), srand()
#include <stdio.h> // printf()
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

void SimpleRandDemo(int n) {
    // Cetak n angka acak.
    for (int i = 0; i < n; i++) {
        printf("  %6d\n", rand());
    }
}

void RangedRandDemo(int range_min, int range_max, int n) {
    // Generate random numbers in the interval [range_min, range_max], inclusive.

    for (int i = 0; i < n; i++) {
        // Catatan: Metode menghasilkan angka acak dalam rentang ini tidak cocok untuk
        // aplikasi yang membutuhkan angka acak berkualitas tinggi.
        // rand() memiliki rentang keluaran kecil [0,32767], membuatnya tidak cocok untuk
        // menghasilkan angka acak dalam rentang besar menggunakan metode di bawah ini.
        // Pendekatan di bawah ini juga dapat menghasilkan distribusi yang tidak seragam.
        // Fungsi nomor acak yang lebih kuat tersedia di header C++ <random>.
        // Lihat https://learn.microsoft.com/cpp/standard-library/random
        int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        printf("  %6d\n", r);
    }
}

int main() {
    // Benih generator bilangan acak dengan benih tetap sehingga
    // angkanya akan sama setiap kali kita berlari.
    srand(1792);

    printf("Simple random number demo ====\n\n");
    SimpleRandDemo(10);
    printf("\nRandom number in a range demo ====\n\n");
    RangedRandDemo(-100, 100, 100000);
    
    _getch();
    return 0;
}