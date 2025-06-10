#include <iostream>                // Library untuk input dan output
using namespace std;

class queues {
    int FRONT, REAR, max = 5;      // Variabel penanda depan dan belakang queue serta ukuran maksimal
    int queue_array[5];           // Array untuk menyimpan elemen queue
