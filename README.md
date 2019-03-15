# SoalShift_modul2_A06

1. Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang
klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki
ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan
Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu
program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori
/home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

```
Langkah-Langkah :

1. Membuat Daemon terlebih dahulu sebab dalam penyelesaiannya tidak boleh
menggunakan crontab.

2. membuat fungsi agar dapat membuka direktori dan mengambil/mengelist file
yang hanya berekstensi “.png”, dengan cara :

 membuat struct untuk membuka direktori
 menggunakan strrchr mendapatkan karakter dot(.) pada nama file.
 Menggunakan strcmp agar mengecek file yang di dapat hanya berekstensi
“.png”.

3. Setelah itu di dalam fungsi main program di daemon buatlah variabel agar
menyimpan semua list file berekstensi “.png”.

4. Kemudian hilangkan karakter “.png” agar hanya menyimpan nama file.

5. Tambahkan karakter “_grey.png” ke nama file yang telah di dapat.

6. Pindahkan file tersebut ke direktori /home/[user]/modul2/gambar.

Cat : buatlah array dengan string kosong agar tidak terjadi looping saat
rename file.

7. Setelah itu tinggal gunakan fungsi rename untuk mengubah nama file dan
jangan lupa kosongkan lagi isi list nama file
```
