#include <iostream>
using namespace std;

int main() {
    int data[8] = {8, 10, 6, -2, 11, 7, 1, 100};
    int cari;
    bool flag = false;
    
    cout << "Masukkan data yang ingin dicari = ";
    cin >> cari;
    
    for (int i = 0; i < 8; i++) {
        if (data[i] == cari)
            flag = true;
    }
    
    if (flag)
        cout << "Data ditemukan" << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    return 0;
}
