"# SoalShift_modul2_A06" 

1. Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang
klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki
ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan
Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu
program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori
/home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.
Langkah-Langkah :
1. Membuat Daemon terlebih dahulu sebab dalam penyelesaiannya tidak boleh
menggunakan crontab.
2. membuat fungsi agar dapat membuka direktori dan mengambil/mengelist file
yang hanya berekstensi “.png”, dengan cara :
 membuat struct untuk membuka direktori
 menggunakan strrchr mendapatkan karakter dot(.) pada nama file.
 Menggunakan strcmp agar mengecek file yang di dapat hanya berekstensi
“.png”.
&lt;code&gt;
/* when return 1, scandir will put this dirent to the list*/
static int parse_ext(const struct dirent *dir)
{
if(!dir)
return 0;
if(dir-&gt;d_type == DT_REG) { /* only deal with regular file */
const char *ext = strrchr(dir-&gt;d_name,&#39;.&#39;);
if((!ext) || (ext == dir-&gt;d_name))
return 0;
else {
if(strcmp(ext, &quot;.png&quot;) == 0)
return 1;
}
}
return 0;
}
&lt;code&gt;

3. Setelah itu di dalam fungsi main program di daemon buatlah variabel agar
menyimpan semua list file berekstensi “.png”.
&lt;code&gt;
struct dirent **namelist;
int n;

n = scandir(&quot;.&quot;, &amp;namelist, parse_ext, alphasort);
if (n &lt; 0) {
perror(&quot;scandir&quot;);
return 1;
}
else {
while (n--) {
char *old_name = namelist[n]-&gt;d_name;
&lt;code&gt;

4. Kemudian hilangkan karakter “.png” agar hanya menyimpan nama file.
Cat : buatlah array dengan string kosong agar tidak terjadi looping saat
rename file.
&lt;code&gt;
char sementara[100]=&quot;&quot;;
strncpy(sementara, old_name, (strlen(old_name)-4));
&lt;code&gt;

5. Tambahkan karakter “_grey.png” ke nama file yang telah di dapat.

&lt;code&gt;
strcat(sementara, &quot;_grey.png&quot;);
&lt;code&gt;

6. Pindahkan file tersebut ke direktori /home/[user]/modul2/gambar.

Cat : buatlah array dengan string kosong agar tidak terjadi looping saat
rename file.
&lt;code&gt;
char new_name[100]=&quot;&quot;;
strcpy(new_name, &quot;/home/hafidzasqalany28/modul2/gambar/&quot;);
strcat(new_name, sementara);
&lt;code&gt;

7. Setelah itu tinggal gunakan fungsi rename untuk mengubah nama file dan
jangan lupa kosongkan lagi isi list nama file
&lt;code&gt;
rename(old_name, new_name);
free(namelist[n]);
&lt;code&gt;

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
Langkah-Langkah :
1.
