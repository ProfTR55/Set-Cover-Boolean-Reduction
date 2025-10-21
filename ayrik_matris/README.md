# Ayrık Matris Sadeleştirme Algoritması

Bu proje, rastgele oluşturulan 0/1 matris üzerinde sadeleştirme (reduction) algoritması uygular.
Matris, mutlak satır tespiti ve sezgisel silme adımlarıyla küçültülür.

## Derleme

```bash
mkdir build
cd build
cmake ..
make
```

## Çalıştırma

```bash
./ayrik_matris
```

## Dosya Yapısı

- `main.cpp`: Ana algoritma döngüsü  
- `create_matrix.cpp`: Rastgele matris oluşturur  
- `print_matrix.cpp`: Matrisi ekrana yazdırır  
- `sadeles.cpp`: Sadeleştirme ve işlem fonksiyonları  
