#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    system("cls");
    int data[100];
    int cari = 20;
    int counter = 0;
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        data[i] = rand() % 100;
        cout << data[i] << " ";
    }
  cout << "\ndone. \n";
    printf("\ndone. \n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
        }
    }
   cout << "Data yang ditemukan sebanyak: " << counter << "\n";
    printf("Data yang ditemukan sebanyak: %d\n", counter);
    if (counter == 0) {
       cout << "Data tidak ditemukan";
        printf("Data tidak ditemukan");
    }
}
