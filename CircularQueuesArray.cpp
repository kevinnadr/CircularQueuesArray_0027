#include <iostream>                // Library untuk input dan output
using namespace std;

class queues {
    int FRONT, REAR, max = 5;      // Variabel penanda depan dan belakang queue serta ukuran maksimal
    int queue_array[5];           // Array untuk menyimpan elemen queue

public:
    queues() {                    // Konstruktor: inisialisasi queue kosong
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "enter a number: ";
        cin >> num;
        cout << endl;

        // Cek apakah queue penuh (circular condition)
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nqueue overflow\n";
            return;
        }

        // Cek apakah queue kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }