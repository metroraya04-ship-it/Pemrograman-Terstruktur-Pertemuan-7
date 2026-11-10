
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main() {

    cout << fixed << setprecision(2);

    int jumlah_mahasiswa = 0;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;

    while (cin.fail() || jumlah_mahasiswa < 1) {

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Itu bukan angka. ";
        } else {
            cin.ignore(1000, '\n');
            cout << "Jumlah mahasiswa harus lebih dari 0. ";
        }

        cout << "Coba lagi: ";
        cin >> jumlah_mahasiswa;
    }

    cin.ignore(1000, '\n');

    double total_nilai = 0.0;

    int jumlah_A = 0;
    int jumlah_B = 0;
    int jumlah_C = 0;
    int jumlah_D = 0;
    int jumlah_E = 0;

    double nilai_tertinggi = -1.0;
    string nama_tertinggi = "";

    int lulus = 0;
    int belum_lulus = 0;

    cout << "          Program SiNilai v0.6\n";

    for (int i = 1; i <= jumlah_mahasiswa; i++) {

        string nama;

        double kehadiran = 0.0;
        double mingguan = 0.0;
        double uts = 0.0;
        double uas = 0.0;

        double nilai_akhir = 0.0;

        string huruf_mutu;
        string status;

        cout << "\n--- Mahasiswa ke-" << i
             << " dari " << jumlah_mahasiswa << " ---\n";

        bool sah = false;

        do {

            cout << "Nama      : ";
            getline(cin, nama);

            int panjang = nama.length();

            bool ada_huruf = false;
            bool ada_angka = false;

            for (int k = 0; k < panjang; k++) {

                if (nama[k] != ' ') {
                    ada_huruf = true;
                }

                if (isdigit(static_cast<unsigned char>(nama[k]))) {
                    ada_angka = true;
                }
            }

            if (!ada_huruf) {
                cout << "Nama tidak boleh kosong.\n";
            }
            else if (ada_angka) {
                cout << "Nama tidak boleh mengandung angka.\n";
            }
            else {
                sah = true;
            }

        } while (!sah);

        int panjang = nama.length();

        bool awal_kata = true;

        for (int k = 0; k < panjang; k++) {

            if (nama[k] == ' ') {
                awal_kata = true;
            }
            else if (awal_kata) {

                nama[k] = static_cast<char>(
                    toupper(static_cast<unsigned char>(nama[k]))
                );

                awal_kata = false;
            }
            else {

                nama[k] = static_cast<char>(
                    tolower(static_cast<unsigned char>(nama[k]))
                );
            }
        }

        cout << "Kehadiran (0-100): ";
        cin >> kehadiran;

        while (cin.fail() || kehadiran < 0 || kehadiran > 100) {

            if (cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Itu bukan angka. ";
            }
            else {

                cin.ignore(1000, '\n');

                cout << "Harus angka 0 sampai 100. ";
            }

            cout << "Coba lagi: ";
            cin >> kehadiran;
        }

        cin.ignore(1000, '\n');

        cout << "Mingguan (0-100): ";
        cin >> mingguan;

        while (cin.fail() || mingguan < 0 || mingguan > 100) {

            if (cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Itu bukan angka. ";
            }
            else {

                cin.ignore(1000, '\n');

                cout << "Harus angka 0 sampai 100. ";
            }

            cout << "Coba lagi: ";
            cin >> mingguan;
        }

        cin.ignore(1000, '\n');

        cout << "UTS (0-100): ";
        cin >> uts;

        while (cin.fail() || uts < 0 || uts > 100) {

            if (cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Itu bukan angka. ";
            }
            else {

                cin.ignore(1000, '\n');

                cout << "Harus angka 0 sampai 100. ";
            }

            cout << "Coba lagi: ";
            cin >> uts;
        }

        cin.ignore(1000, '\n');

        cout << "UAS (0-100): ";
        cin >> uas;

        while (cin.fail() || uas < 0 || uas > 100) {

            if (cin.fail()) {

                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Itu bukan angka. ";
            }
            else {

                cin.ignore(1000, '\n');

                cout << "Harus angka 0 sampai 100. ";
            }

            cout << "Coba lagi: ";
            cin >> uas;
        }

        cin.ignore(1000, '\n');

        nilai_akhir = (
            kehadiran + mingguan + uts + uas
        ) / 4.0;

        if (nilai_akhir >= 85.0) {
            huruf_mutu = "A";
        }
        else if (nilai_akhir >= 80.0) {
            huruf_mutu = "B+";
        }
        else if (nilai_akhir >= 70.0) {
            huruf_mutu = "B";
        }
        else if (nilai_akhir >= 60.0) {
            huruf_mutu = "C";
        }
        else if (nilai_akhir >= 50.0) {
            huruf_mutu = "D";
        }
        else {
            huruf_mutu = "E";
        }

        if (nilai_akhir >= 60.0) {
            status = "Lulus";
        }
        else {
            status = "Belum lulus";
        }

        cout << "\nHasil Mahasiswa:\n";

        cout << left << setw(20) << "Nama"
             << ": " << nama << '\n';

        cout << left << setw(20) << "Kehadiran"
             << ": " << kehadiran << '\n';

        cout << left << setw(20) << "Mingguan"
             << ": " << mingguan << '\n';

        cout << left << setw(20) << "UTS"
             << ": " << uts << '\n';

        cout << left << setw(20) << "UAS"
             << ": " << uas << '\n';

        cout << left << setw(20) << "Nilai Akhir"
             << ": " << nilai_akhir << '\n';

        cout << left << setw(20) << "Huruf Mutu"
             << ": " << huruf_mutu << '\n';

        cout << left << setw(20) << "Status"
             << ": " << status << '\n';

        total_nilai += nilai_akhir;

        switch (huruf_mutu[0]) {

            case 'A':
                jumlah_A++;
                break;

            case 'B':
                jumlah_B++;
                break;

            case 'C':
                jumlah_C++;
                break;

            case 'D':
                jumlah_D++;
                break;

            case 'E':
                jumlah_E++;
                break;

            default:
                break;
        }

        if (nilai_akhir >= 60.0) {
            lulus++;
        }
        else {
            belum_lulus++;
        }

        if (nilai_akhir > nilai_tertinggi) {

            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    double rata_rata = total_nilai / jumlah_mahasiswa;

    cout << "Laporan Kelas\n";

    cout << "Jumlah mahasiswa : "
         << jumlah_mahasiswa << '\n';

    cout << "Lulus            : "
         << lulus << '\n';

    cout << "Belum lulus      : "
         << belum_lulus << '\n';

    cout << "Rata-rata kelas  : "
         << rata_rata << '\n';

    cout << "Tertinggi        : "
         << nama_tertinggi
         << " (" << nilai_tertinggi << ")\n";

    cout << "\nNilai huruf mutu:\n";

    for (char huruf = 'A'; huruf <= 'E'; huruf++) {

        int jumlah_huruf = 0;

        if (huruf == 'A') {
            jumlah_huruf = jumlah_A;
        }
        else if (huruf == 'B') {
            jumlah_huruf = jumlah_B;
        }
        else if (huruf == 'C') {
            jumlah_huruf = jumlah_C;
        }
        else if (huruf == 'D') {
            jumlah_huruf = jumlah_D;
        }
        else if (huruf == 'E') {
            jumlah_huruf = jumlah_E;
        }

        cout << huruf << " | ";

        for (int j = 0; j < jumlah_huruf; j++) {
            cout << '#';
        }

        cout << ' ' << jumlah_huruf << '\n';
    }

    cout << "Program Selesai\n";

    return 0;
}