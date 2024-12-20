#include <iostream>
#include <vector>
#include <algorithm>

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

bool compareByNama(const Student& a, const Student& b) {
    return a.nama < b.nama;
}

bool compareByGPA(const Student& a, const Student& b) {
    return a.gpa > b.gpa; 
}

void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "NPM: " << student.npm << ", Nama: " << student.nama
             << ", Prodi: " << student.prodi << ", IPK: " << student.gpa << endl;
    }
}

void insertStudent(vector<Student>& students, const Student& student, int position) {
    if (position >= 0 && position <= students.size()) {
        students.insert(students.begin() + position, student);
    } else {
        cout << "Posisi tidak valid.\n";
    }
}

void selectStudentsByGPA(const vector<Student>& students, float gpaThreshold) {
    vector<Student> selectedStudents;
    for (const auto& student : students) {
        if (student.gpa >= gpaThreshold) {
            selectedStudents.push_back(student);
        }
    }
    
    if (selectedStudents.empty()) {
        cout << "Tidak ada mahasiswa dengan IPK di atas " << gpaThreshold << ".\n";
    } else {
        cout << "Mahasiswa dengan IPK di atas " << gpaThreshold << ":\n";
        displayStudents(selectedStudents);
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "Menu:\n"
             << "1. Tambah Mahasiswa\n"
             << "2. Tampilkan Mahasiswa\n"
             << "3. Urutkan Mahasiswa\n"
             << "4. Sisipkan Mahasiswa\n"
             << "5. Seleksi Mahasiswa berdasarkan IPK\n"
             << "6. Keluar\n";
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
                Student student;
                int position;
                cout << "Masukkan NPM: ";
                cin >> student.npm;
                cout << "Masukkan Nama: ";
                cin.ignore(); // Clear input buffer
                getline(cin, student.nama);
                cout << "Masukkan Prodi: ";
                getline(cin, student.prodi);
                cout << "Masukkan IPK: ";
                cin >> student.gpa;
                cout << "Masukkan posisi: ";
                cin >> position;
                insertStudent(students, student, position);
                break;
            }
            case 5: {
                float gpaThreshold;
                cout << "Masukkan IPK minimum untuk seleksi: ";
                cin >> gpaThreshold;
                selectStudentsByGPA(students, gpaThreshold);
                break;
            }
            case 6:
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 6);

    return 0;
}
