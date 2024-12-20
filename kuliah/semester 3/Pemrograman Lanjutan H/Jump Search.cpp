#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Student {
    string npm;
    string nama;
    string prodi;
    float gpa;
};

bool compareByNPM(const Student& a, const Student& b) {
    return a.npm < b.npm;
}

void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "NPM: " << student.npm << ", Nama: " << student.nama
             << ", Prodi: " << student.prodi << ", IPK: " << student.gpa << endl;
    }
}

int jumpSearch(const vector<Student>& students, const string& npm) {
    int n = students.size();
    int step = sqrt(n);
    int prev = 0;

    while (students[min(step, n) - 1].npm < npm) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if (students[i].npm == npm) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "Menu:\n"
             << "1. Tambah Mahasiswa\n"
             << "2. Tampilkan Mahasiswa\n"
             << "3. Urutkan Mahasiswa\n"
             << "4. Cari Mahasiswa (NPM)\n"
             << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                cout << "Masukkan NPM: ";
                cin >> student.npm;
                cout << "Masukkan Nama: ";
                cin.ignore(); // Clear input buffer
                getline(cin, student.nama);
                cout << "Masukkan Prodi: ";
                getline(cin, student.prodi);
                cout << "Masukkan IPK: ";
                cin >> student.gpa;
                students.push_back(student);
                break;
            }
            case 2:
                displayStudents(students);
                break;
            case 3: {
                int sortChoice;
                cout << "Urutkan berdasarkan:\n"
                     << "1. NPM\n"
                     << "2. Nama\n"
                     << "3. IPK\nPilih: ";
                cin >> sortChoice;

                switch (sortChoice) {
                    case 1:
                        sort(students.begin(), students.end(), compareByNPM);
                        break;
                    case 2:
                        sort(students.begin(), students.end(), compareByNama);
                        break;
                    case 3:
                        sort(students.begin(), students.end(), compareByGPA);
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            case 4: {
                if (students.empty()) {
                    cout << "Belum ada mahasiswa yang ditambahkan.\n";
                    break;
                }

                string npm;
                cout << "Masukkan NPM untuk mencari: ";
                cin >> npm;

                sort(students.begin(), students.end(), compareByNPM); // Pastikan daftar diurutkan berdasarkan NPM untuk jump search
                int index = jumpSearch(students, npm);

                if (index != -1) {
                    cout << "Mahasiswa ditemukan:\n";
                    cout << "NPM: " << students[index].npm << ", Nama: " << students[index].nama
                         << ", Prodi: " << students[index].prodi << ", IPK: " << students[index].gpa << endl;
                } else {
                    cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan.\n";
                }
                break;
            }
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 5);

    return 0;
}
