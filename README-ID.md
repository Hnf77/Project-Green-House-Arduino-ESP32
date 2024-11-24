# Otomasi dan Pemantauan Rumah Kaca

## Ringkasan
Proyek ini bertujuan untuk membuat sistem rumah kaca pintar menggunakan **Arduino Uno** dan **ESP32**, yang dirancang untuk perawatan tanaman otomatis dan pemantauan secara real-time. Sistem ini memanfaatkan kombinasi sensor dan sistem otomatis untuk memastikan kondisi tumbuh yang optimal.

## Terjemahan
- <a href="https://github.com/Hnf77/Project-Green-House-Arduino-ESP32/blob/main/README.md">Inggris</a>

## Fitur
- **Pemantauan Suhu**: Melacak suhu secara real-time di dalam rumah kaca.
- **Kontrol Kelembapan**: Memantau kelembapan udara untuk menjaga kondisi yang sesuai.
- **Deteksi Kelembapan Tanah**: Sistem penyiraman otomatis yang diaktifkan saat kelembapan tanah berada di bawah level tertentu.
- **Pengukuran Intensitas Cahaya**: Mendeteksi tingkat sinar matahari untuk pertumbuhan tanaman yang optimal.
- **Penyiraman Otomatis**: Sistem penyiraman akan menyala secara otomatis berdasarkan pembacaan sensor kelembapan tanah.
- **Pemantauan melalui Ponsel**: Data sensor dikirim ke aplikasi **Blynk**, memungkinkan pengguna untuk memantau dan mengontrol rumah kaca dari jarak jauh.

## Kebutuhan Perangkat Keras
- Arduino Uno
- ESP32
- DHT11 atau DHT22 (Sensor Suhu & Kelembapan), tetapi proyek ini menggunakan DHT11
- Sensor Kelembapan Tanah
- Sensor Intensitas Cahaya (LDR atau serupa)
- Modul Relay (untuk mengontrol pompa air)
- Pompa Air
- Kabel Jumper
- Breadboard

## Kebutuhan Perangkat Lunak
- Arduino IDE
- Aplikasi Blynk (untuk pemantauan melalui ponsel)
- Library: Blynk, DHT, WiFi, dll.

## Instalasi
1. Clone repositori ini ke komputer lokal Anda.
2. Pasang perangkat keras sesuai diagram koneksi proyek.
3. Buka Arduino IDE dan instal library yang diperlukan.
4. Upload kode ke Arduino dan ESP32.
5. Atur aplikasi Blynk untuk memantau data secara jarak jauh.

## Cara Kerja
1. **Sensor** secara terus-menerus memantau suhu, kelembapan, kelembapan tanah, dan intensitas cahaya.
2. Ketika kelembapan tanah turun di bawah ambang batas yang ditentukan, **sistem penyiraman otomatis** akan diaktifkan.
3. Semua data sensor dikirimkan ke aplikasi **Blynk**, memungkinkan pengguna untuk memantau dan mengontrol sistem dari jarak jauh.

## Penghargaan
Proyek ini terinspirasi oleh kebutuhan untuk mengotomatisasi dan mengoptimalkan perawatan tanaman di rumah kaca, sehingga memudahkan pengguna untuk memantau dan mengontrol tanaman mereka dari jarak jauh menggunakan teknologi IoT modern.

## Dukung Saya

 <a href="https://paypal.me/hanif1230?country.x=ID&locale.x=id_ID" target="_blank" >
    <img src="https://user-images.githubusercontent.com/42001064/196043185-ebd61195-44ee-480f-9b76-f5eb7cfcaf55.png" alt="Paypal" width="180"/>
 </a>
 &nbsp;
 &nbsp;
 &nbsp;
 &nbsp;
 &nbsp;
 <a href="https://www.buymeacoffee.com/hnf77" target="_blank">
    <img src="https://cdn.buymeacoffee.com/buttons/v2/arial-yellow.png" alt="Paypal" width="180"/>
 </a>

