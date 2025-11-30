# 🌲 C ile Hayatta Kalma Simülatörü (Survival Game)

Bu proje, C programlama dili kullanılarak geliştirilmiş, metin tabanlı bir hayatta kalma oyunudur. Oyuncu, sınırlı kaynakları (enerji, sağlık) yöneterek hayatta kalmaya çalışır ve güvenli bir sığınak bulmayı hedefler.

## 🎮 Oyun Özellikleri

- **Dinamik Durum Yönetimi:** Sağlık, Enerji, Yemek ve İlerleme Puanı takibi.
- **Komut Sistemi:** Klavye üzerinden karakter komutları ile kontrol.
- **Risk Analizi:** Sağlık ve enerjiniz düşükse avlanma ihtimaliniz düşer (`&&` ve `||` mantıksal operatörleri ile hesaplanır).

## 🕹️ Komut Listesi

| Tuş | İşlev | Açıklama |
| :---: | --- | --- |
| **A** | Avlan | Enerji harcar, yemek kazandırabilir veya hasar verir. |
| **S** | Sığınak Ara | İlerleme puanı kazandırır. |
| **R** | Dinlen | Enerji ve sağlık yeniler (yemek varsa). |
| **E** | Envanter | Mevcut durumu gösterir. |
| **F** | Tehlike Simülasyonu | 3 turluk tehlike serisi (yüksek risk/ödül). |
| **P** | Şifreli İlerleme | Matematik sorusunu çözerek ilerleme puanı kazan. |
| **X** | Çıkış | Oyunu sonlandır. |

## Kullanılan C Yapıları ve Mantığı
Projenin temelinde şu yapılar kullanılmıştır.
### 1 Komut Sistemi (Switch-Case)
Oyunun ana kontrol mekanizmasıdır. Oyuncudan alınan ‘A’, ‘S’, ‘E’, ‘R’, ‘F’, ‘P’ ve ‘X’ komutları switch-case ile kontrol edilmiştir.
- **Neden kullanıldı?** Tek bir değişkenin farklı değerlerle eşleşip eşleşmediği kontrol edilmesi gerekilen durumlarda if-else yapısı yerine switch-case yapısı öne çıkar. Ayrıca büyük küçük harf duyarlılığını ortadan kaldırmak için (örn: `case ‘A’: case ‘a’:` ) yığın yapısı kullanılmıştır.
### 2 Mantıksal Operatörler ve Karar Yapıları (If-Else)
Oyunun belirsizlik ve şans faktörleri bu yapılarla sağlanmıştır.
- **Örnek (Avlanma):** Avlanma sırasında oyuncunun başarısı, sadece rastgele değil, mevcut sağlık ve enerji durumuna göre belirlenir. Örneğin; `if (saglik < 30 && enerji < 30)` koşulu ile oyuncunun durumu kötüyse avlanma başarısız sayılmış ve daha fazla hasar alması sağlanmıştır. Böylece her avlanmada alınacak hasar ve enerji kaybı oyuncunun durumuna göre dinamik şekilde değişerek oyunun ilerlemesindeki öngörülebilirliği azaltmıştır. Burada `&&` (VE) operatörü iki koşulun aynı anda sağlanmasını kontrol etmiştir.
### 3 Döngüler
- **DO-WHILE (Ana Oyun Döngüsü):** Oyunun en az bir kez çalışması ve oyuncu ‘X’ komutunu verene veya ölene veya sığınağı bulana kadar devam etmesi gerektiği için do-while tercih edilmiştir. Koşul olarak `saglik > 0`, `!siginak_bulundu_mu` ve `(komut != ‘X’ && komut != ‘x’)` kontrol edilir.
- **For (Tehlike Simülasyonu – F Komutu):** 3 tur süren bir tehlike dalgası için for döngüsü kullanılmıştır. Her döngü adımında hasar miktarı artırılarak (`(i+1)/10.0` formülü ile) tehlikenin giderek büyüdüğü simüle edilmiştir.
- **DO-WHILE (Şifreli İlerleme – P Komutu):** Oyuncuya bir matematik sorusu sorulur. Oyuncu doğru cevabı verene kadar bu döngüden çıkamaz.
### 4 Aritmetik İşlemler ve Durum Yönetimi
Oyun içindeki değişkenler (sağlık, enerji) sürekli güncellenir.
- **Şifre Algoritması:** Statik bir şifre yerine, o anki duruma göre değişen dinamik bir şifre oluşturulmuştur: `int sifre = ((int)saglik) * (int)enerji;`. Bu sayede her oyun deneyimi farklılaşmaktadır.

## 🚀 Kurulum ve Çalıştırma

Bu proje C dilinde yazılmıştır ve herhangi bir standart C derleyicisi (GCC, Clang vb.) ile derlenebilir.

1.  Proje dosyasını klonlayın:
    ```bash
    git clone https://github.com/b-demir/Algoritma-ve-Programlama-Odev-2
    ```
2.  Kodu derleyin (Örnek GCC kullanımı):
    ```bash
    gcc main.c -o oyun
    ```
3.  Uygulamayı çalıştırın:
    ```bash
    oyun
    ```