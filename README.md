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

Bu proje C dilinde yazılmıştır ve herhangi bir standart C derleyicisi (GCC, Clang vb.) ile derlenebilir.

1.  Proje dosyasını klonlayın:
    ```bash
    git clone [GitHub Repo Linkiniz Buraya Gelecek]
    ```
2.  Kodu derleyin (Örnek GCC kullanımı):
    ```bash
    gcc main.c -o oyun
    ```
3.  Uygulamayı çalıştırın:
    ```bash
    oyun
    ```