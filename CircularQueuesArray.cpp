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
        else {
            // Jika REAR di akhir array, kembali ke indeks 0 (circular)
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;  // Geser REAR ke kanan
        }
        queue_array[REAR] = num;  // Masukkan elemen ke REAR
    }

    void remove() {
        // Cek apakah queue kosong
        if (FRONT == -1) {
            cout << "queue underflow\n";
            return;
        }

        cout << "\nthe element deleted from the queue is : " << queue_array[FRONT] << "\n";

        // Cek jika hanya ada satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            // Jika FRONT di akhir array, kembali ke 0
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1; // Geser FRONT ke kanan
        }
    }

    void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // Cek apakah queue kosong
        if (FRONT == -1) {
            cout << "queue is empty\n";
            return;
        }

        cout << "\nelements in the queue are...\n";
