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

## 🚀 Kurulum ve Çalıştırma

Bu projeyi kendi bilgisayarınızda çalıştırmak için bir C derleyicisine (GCC gibi) ihtiyacınız vardır.

1. Projeyi klonlayın veya `main.c` dosyasını indirin.
2. Terminali açın ve dosyanın olduğu dizine gidin.
3. Aşağıdaki komutla derleyin:
   ```bash
   gcc main.c -o oyun
4. Oyunu başlatın:

Windows için: oyun.exe

Mac/Linux için: ./oyun