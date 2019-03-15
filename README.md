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

2. Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh
orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada
direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma
adalah membantunya untuk menghapus semua kenangan tentang Elen dengan
membuat program C yang bisa mendeteksi owner dan group dan menghapus file
“elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”.

Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah
permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma
bisa move on.
Catatan: Tidak boleh menggunakan crontab

```
Langkah-Langkah :

1. Membuat daemon yg berjalan setiap 3 detik

2. Cek apakah file elen.ku ada di dalam folder hatiku

3. Setelah di cek dan ada, ubah permission file menggunakan chmod

4. Cek dan dapatkan data dari owner dan group dengan getpwuid dan getgrgid

5. Data dari owner dan group akan disimpan untuk diubah

6. Setelah itu baru kita bisa mengakses owner dan group

7. Cek apakah owner dari file adalah www-data

8. Jika iya maka file akan dihapus
```

3. Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :
i)  mengekstrak file zip tersebut.
ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 
Catatan:  
Gunakan fork dan exec.
Gunakan minimal 3 proses yang diakhiri dengan exec.
Gunakan pipe
Pastikan file daftar.txt dapat diakses dari text editor

```
Langkah-Langkah :

1. gunakan fork untuk membuat child 1

2. buatlah fungsi exec untuk meng-unzip file campur2.zip

3. gunakan fork untuk membuat child 2

4. buatlah fungsi exec untuk menjalankan fungsi touch untuk membuat file kosong bernama daftar.txt

5. gunakan fork untuk membuat child 3

6. buatlah pipe untuk menyimpan output data dari fungsi di child 3

7. buatlah fungsi exec untuk menjalankan fungsi ls untuk membuat list file di folder campur2

8. buatlah pipe untuk membaca output yang disimpan dalam pipe sebelumnya

9. buatlah fungsi untuk membuat file sementara untuk membaca output dari pipe

10. buatlah fungsi untuk membuka file daftar.txt untuk kemudian di write

11. buatlah fungsi untuk mendapatkan data dari file sementara tsb yang nanti nya akan diprint di daftar.txt

12. buatlah fungsi print untuk mengeprint data list ke daftar.txt

13. tutup file daftar, dan selesai
```

4. Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh: 
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
dilarang menggunakan crontab
Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst

```
Langkah-Langkah :

```

5. Kerjakan poin a dan b di bawah:
Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1
Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.

```
Langkah-Langkah :

1. buatlah daemon agar proses bisa terus berjalan di background

2. 
```
