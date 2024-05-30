#include <iostream>
using namespace std;

class queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public:
   queues() {
      FRONT = -1;
      REAR = -1;
   }

   void insert() {
      int num;
      cout << "enter a number: ";
      cin >> num;
      cout << endl;

      //cek apakah antrian penuh
      if ((FRONT == 0 && REAR == max -1) || (FRONT == REAR + 1)) {
        cout << "n\queue overlow\n";
      }

      //cek apakah antrian kosong
      if (FRONT == -1) {
          FRONT = 0;
          REAR = 0;
      }
      else {
        // jika REAR berada di posisi terakhir array, kembali ke awal array
        if (REAR == max -1)
            REAR = 0;
      }
      queue_array[REAR] = num;
   }

   void remove() {
      // cek apakah antrian kosong
      if (FRONT == -1) {
        cout << "queue underflow\n";
        return;
        
      }
      cout << "\nthe element deleted from the queue is : " << queue_array[FRONT] << "\n";

      //cek jika antrian hanya memiliki satu element
      if(FRONT == max -1) {
         FRONT = -1;
         REAR = -1;
      }
      else {
        //jika element yang di hapus berada di posisi terakhir array, kembali ke awal array
        if (FRONT == max -1)
            FRONT = 0;
        else
           FRONT = FRONT +1;
      }
    }

    void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        //cek apakah antrian kosong 
        if (FRONT == -1) {
            cout << "queue is empty\n";
            return;
        }

        cout << "\nelements in the queue are...\n";

        //jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while(FRONT_position <= max -1) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main() {
    queues q;
    char ch;

    while (true) {
        try {
            cout << "menu" << endl;
            cout << "1. implement insert operation" << endl;
            cout << "2. implement insert operation" << endl;
            cout << "3. display values" << endl;
            cout << "4. exit" << endl;
            cout << "enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1':{

                q.insert();
                break;
                
            }
            case '2': {
                q.remove();
                break;
            }
            case '3': {
                q.display();
                break;
            }
            case '4': {
                return 0;
            }
            case '5': {
                cout << "invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << "chechk for the values entered." << endl;
        }
    }
    
    return 0;
}