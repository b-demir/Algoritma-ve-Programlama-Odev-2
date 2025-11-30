#include <stdio.h>
#include <math.h>

int main()
{
    float saglik = 100, enerji = 100;
    int siginak_bulundu_mu = 0, yemek_miktari = 0, ilerleme = 0;
    char komut;

    printf("Hayatta Kalma Oyununa Hoşgeldiniz!\n");
    printf("Saglik: %.2f\n", saglik);
    printf("Enerji: %.2f\n", enerji);
    printf("Yemek Miktari: %d\n", yemek_miktari);
    printf("İlerleme: %d\n", ilerleme);
    printf("Oyunu tamamlayabilmek icin siginak bulmalisiniz!\n");
    printf("Siginak bulmak icin ilerleme puaninizin 10 veya daha fazla olmasi gerekiyor.\n");
    printf("Iyi sanslar!\n");

    do
    {
        printf("Komut giriniz :\n");
        printf("A: Avlan\n");
        printf("S: Siginak ara\n");
        printf("E: Envanteri Goruntule\n");
        printf("R: Dinlen\n");
        printf("F: Bolgedeki tehlike serisini simule et\n");
        printf("P: Sifreli ilerleme\n");
        printf("X: Cikis\n");

        scanf(" %c", &komut);

        switch (komut)
        {
        case 'A':
        case 'a':
            if (enerji > 0)
            {
                printf("Avlaniyor...\n");

                float saglik_kaybi;
                int av_basarili_mi;

                if (saglik < 30 && enerji < 30)
                {
                    printf("Av basarisiz oldu!\n");
                    av_basarili_mi = 0;
                    saglik_kaybi = saglik * 0.5;
                }
                else if (saglik < 30 && enerji >= 30 && enerji < 50)
                {
                    printf("Av basarisiz oldu!\n");
                    av_basarili_mi = 0;
                    saglik_kaybi = saglik * 0.4;
                }
                else if (saglik < 30 && enerji >= 50)
                {
                    printf("Av basarili oldu!\n");
                    av_basarili_mi = 1;
                    saglik_kaybi = saglik * 0.02;
                }
                else if (saglik < 50 && enerji < 20)
                {
                    printf("Av basarisiz oldu!\n");
                    av_basarili_mi = 0;
                    saglik_kaybi = saglik * 0.3;
                }
                else if (saglik < 50 && enerji >= 20 && enerji < 40)
                {
                    printf("Av basarisiz oldu!\n");
                    av_basarili_mi = 0;
                    saglik_kaybi = saglik * 0.2;
                }
                else if (saglik < 50 && enerji >= 40)
                {
                    printf("Av basarili oldu!\n");
                    av_basarili_mi = 1;
                    saglik_kaybi = saglik * 0.02;
                }
                else if (saglik >= 50 && enerji < 20)
                {
                    printf("Av basarili oldu!\n");
                    av_basarili_mi = 1;
                    saglik_kaybi = saglik * 0.1;
                }
                else if (saglik >= 50 && enerji < 80)
                {
                    printf("Av basarili oldu!\n");
                    av_basarili_mi = 1;
                    saglik_kaybi = saglik * 0.05;
                }
                else
                {
                    printf("Av basarili oldu!\n");
                    av_basarili_mi = 1;
                    saglik_kaybi = saglik * 0.02;
                }

                saglik -= saglik_kaybi;
                if (saglik <= 0)
                {
                    saglik = 0;
                    printf("Malesef sagliginiz tukenmistir. Oyun bitti!\n");
                    break;
                }

                enerji -= 10;
                if (enerji < 0)
                {
                    enerji = 0;
                }

                printf("Saglik kaybi: %.2f\n", saglik_kaybi);
                printf("Saglik: %.2f\n", saglik);

                if (av_basarili_mi)
                {
                    yemek_miktari += 1; // Yiyecek ekle
                }
            }
            else
            {
                printf("Yeterli enerjiniz yok, dinlenmeniz gerekiyor!\n");
            }

            printf("Enerji: %.2f\n", enerji);

            break;
        case 'S':
        case 's':
            if (enerji > 0)
            {
                printf("Sığınak aranıyor...\n");

                if (!((saglik < 20 && enerji < 50) || (saglik < 50 && enerji < 40) || (saglik < 80 && enerji < 20)))
                {
                    printf("1 ilerleme puani kazandiniz!\n");
                    ilerleme += 1;
                }
                else
                {
                    printf("Siginak arama basarisiz oldu!\n");
                }

                printf("Ilerleme puaniniz: %d\n", ilerleme);

                enerji -= 15;
                if (enerji < 0)
                {
                    enerji = 0;
                }
            }
            else
            {
                printf("Yeterli enerjiniz yok, dinlenmeniz gerekiyor!\n");
            }

            printf("Enerji: %.2f\n", enerji);

            break;
        case 'E':
        case 'e':
            printf("Envanter goruntuleniyor...\n");
            printf("Yemek Miktari: %d\n", yemek_miktari);
            break;
        case 'R':
        case 'r':
            printf("Dinleniyor...\n");

            if (enerji < 100)
            {
                printf("Enerji artirildi.\n");
            }

            if (yemek_miktari > 0 && saglik <= 90)
            {
                yemek_miktari -= 1;
                printf("Yemek tuketildi ve saglik artirildi, yemek miktari: %d\n", yemek_miktari);
                saglik += 10;
                enerji += 15;
            }
            else
            {
                enerji += 10;
            }

            if (enerji > 100)
            {
                enerji = 100;
            }

            printf("Enerji: %.2f\n", enerji);
            printf("Saglik: %.2f\n", saglik);
            break;
        case 'F':
        case 'f':
            if (enerji > 0)
            {
                printf("Bolgedeki tehlike serisi simule ediliyor...\n");

                int i;
                float tehlike_saglik_kaybi;
                float enerji_kaybi;
                for (i = 0; i < 3; i++)
                {
                    tehlike_saglik_kaybi = saglik * ((i + 1) / 10.0);

                    if (tehlike_saglik_kaybi < 10)
                    {
                        tehlike_saglik_kaybi = 10;
                    }

                    if (enerji == 0)
                    {
                        tehlike_saglik_kaybi *= 2;
                        saglik -= tehlike_saglik_kaybi;
                        printf("Tehlike %d: Saglik kaybi: %.2f, Kalan saglik: %.2f, Enerji kaybi: %.2f, Kalan enerji: %.2f\n", i + 1, tehlike_saglik_kaybi, saglik < 0 ? 0 : saglik, enerji_kaybi, enerji);

                        if (saglik <= 0)
                        {
                            printf("Malesef sagliginiz tukenmistir. Oyun bitti!\n");
                            saglik = 0;
                            break;
                        }
                    }
                    else
                    {
                        saglik -= tehlike_saglik_kaybi;

                        enerji_kaybi = enerji * ((i + 1) / 10.0);
                        enerji -= enerji_kaybi;

                        if (enerji < 0)
                        {
                            enerji = 0;
                        }

                        printf("Tehlike %d: Saglik kaybi: %.2f, Kalan saglik: %.2f, Enerji kaybi: %.2f, Kalan enerji: %.2f\n", i + 1, tehlike_saglik_kaybi, saglik < 0 ? 0 : saglik, enerji_kaybi, enerji);

                        if (saglik <= 0)
                        {
                            printf("Malesef sagliginiz tukenmistir. Oyun bitti!\n");
                            saglik = 0;
                            break;
                        }
                    }
                }
                
                if (saglik != 0)
                {
                    printf("Simulasyon tamamlandi.\n");
                    printf("Ilerleme puaniniz 3 artirildi.\n");
                    ilerleme += 3;
                    printf("Ilerleme puaniniz: %d\n", ilerleme);
                }
            }
            else
            {
                printf("Yeterli enerjiniz yok, dinlenmeniz gerekiyor!\n");
                printf("Enerji: %.2f\n", enerji);
            }

            break;
        case 'P':
        case 'p':
            if (enerji > 0)
            {
                printf("Sifreli ilerleme yapiliyor...\n");

                int sifre = ((int)saglik) * (int)enerji;

                printf("Sifreyi cozunuz: %d x %d = ? (Sadece tam sayi giriniz)\n", (int)saglik, (int)enerji);

                int cevap;

                do
                {
                    scanf("%d", &cevap);
                    if (cevap == sifre)
                    {
                        printf("Dogru cevap! 2 ilerleme puani kazandiniz!\n");
                        ilerleme += 2;
                        printf("Ilerleme puaniniz: %d\n", ilerleme);
                    }
                    else
                    {
                        printf("Yanlis cevap! Tekrar deneyiniz:\n");
                    }
                } while (cevap != sifre);

                enerji -= 20;

                if (enerji < 0)
                {
                    enerji = 0;
                }
            }
            else
            {
                printf("Yeterli enerjiniz yok, dinlenmeniz gerekiyor!\n");
            }

            printf("Enerji: %.2f\n", enerji);

            break;
        case 'X':
        case 'x':
            printf("Cikis yapiliyor...\n");
            break;
        default:
            printf("Gecersiz komut!\n");
            break;
        }

        if (ilerleme > 9)
        {
            printf("Tebrikler siginak bulundu!\n");
            siginak_bulundu_mu = 1;
        }
    } while (saglik > 0 && !siginak_bulundu_mu && (komut != 'X' && komut != 'x'));

    return 0;
}