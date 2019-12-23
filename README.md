# KOCAELİ ÜNİVERSİTESİ PROGRAMLAMA LAB I PROJE - MATEMATİK ÇARKI
 Matematik ve Lineer Cebir derslerinde görülen teorik bilgilerin uygulamada kullanılmasıdır

# 

Çark döndürme işleminde rastgele sayı üretimi ile kontrol edilecek ve 0 ile +241 arasında rastgele sayılar üretilmesi istenmekte. Ardından çarkı durdurma işlemi gerçekleşmekte bu da şöyle: kullanıcıdan kaç tane sayı üretilecek bilgisi çarkı durduracaktır. Kullanıcıdan alınan sayı kadar çark dönecek ve duracaktır.Bu işlemin ardından hangi işlemin yapılacağını belirleme (1-Öz değer bul 2-Schur Teoremi 3-Öz vektör bul 4-Nilpotent matris) işlemi şöyle gerçekleşmekte: Çark durduğunda en son üretilen sayı çarktaki hangi işlemin yapılacağını belirleyecektir. Örn. çark durduğunda en son 213 sayısı üretilmiş olabilir. 

Çark döndürme işleminin ardından hangi işlem geldiyse  ona göre fonksiyon çalıştırılmakta.

- Eğer çark döndürüldüğünde Öz Değer bul işlemi geldiyse:

nxn boyutunda kare matris için n sayısı ve bu matrisin elemanları kullanıcıdan alınacak ve matrisin öz değerleri ozdegerbul() fonksiyonu ile hesaplanacaktır.Ardından 
girilen kare matris, ozdegerbul() fonksiyonunda yapılan işlemler sonucunda elde elde edilen ara matrisler ve son olarak öz değerler ozdeger.txt dosyasına yazdırılacaktır.

- Eğer çark döndürüldüğünde Schur Teoremi geliyse:

nxn boyutunda kare matris için n sayısı ve bu matrisin elemanları kullanıcıdan alınacak ve matrisin öz değerleri ozdegerbul() fonksiyonu ile bulunup bu fonksiyondan geriye dönen öz değerler schur() fonksiyonuna parametre olarak gönderilecektir. schur() fonksiyonunda öz değerler için Schur eşitsizliği kullanılarak sınır değeri bulunacaktır. (Schur Teoremi sizin araştırıp bulmanız gerekmektedir.) Ardından girilen kare matris, schur() fonksiyonunda yapılan hesaplamalar schur.txt dosyasına yazdırılacaktır. 

- Eğer çark döndürüldüğünde Öz Vektör bul işlemi geldiyse:


nxn boyutunda kare matris için n sayısı ve bu matrisin elemanları kullanıcıdan alınacak ve matrisin öz değerleri ozdegerbul() fonksiyonu ile bulunup bu fonksiyondan geriye dönen öz değerler ozvektorbul() fonksiyonuna parametre olarak gönderilecektir. Fonksiyondan geriye girilen kare matrisin öz vektörleri dönecektir.Ardından 
girilen kare matris, ozdegerbul() fonksiyonunda yapılan işlemler sonucunda elde elde edilen ara matrisler, öz değerler ve ozdegerbul() fonksiyonunda her bir öz değer için hesaplanan öz vektörler ozvektor.txt dosyasına yazdırılacaktır. 


- Eğer çark döndürüldüğünde Nilpotent matris işlemi geldiyse:


nxn boyutunda kare matris için n sayısı kullanıcıdan alınacaktır. Ancak matrisin elemanları (-15 ile + 15) arasında rastgele tam sayı olarak üretilecektir. Bu matrisin nilpotent matris olup olmadığı nilpotent() fonksiyonu ile kontrol edilecek fonksiyonda matrisin nilpotent olup olmadığı bilgisi ekrana yazdırılacaktır.Ardından  üretilen kare matris, nilpotent() fonksiyonunda kontrol işlemleri için kıyaslanan matrisler nilpotent.txt dosyasına yazdırılacaktır. 


# 
