# Program Klasemen Liga Sepak Bola (La Liga)

Program C++ untuk mengelola klasemen liga sepak bola dengan fitur **Sorting**, **Searching**, **BST**, dan **Graph**.

## Fitur Utama

1. **Manajemen Data Klub**
   - Input data klub (nama, poin, selisih gol)
   - Tampilkan klasemen (terurut/tidak terurut)

2. **Algoritma Sorting & Searching**
   - **Quick Sort**: Mengurutkan klub berdasarkan poin dan selisih gol
   - **Binary Search**: Mencari klub berdasarkan nama

3. **Struktur Data**
   - **Binary Search Tree (BST)**: Menyimpan data klub secara terurut
   - **Graph**: Simulasi hubungan pertandingan antar klub

## Cara Menggunakan

1. **Kompilasi Program**:
   ```bash
   g++ main.cpp -o klasemen
   ```

2. **Jalankan Program**:
   ```bash
   ./klasemen
   ```

3. **Menu Interaktif**:
   ```
   Menu Klasemen La Liga:
   1. Input Data Klub
   2. Tampilkan Klasemen (Belum Sorting)
   3. Urutkan Klasemen (Quick Sort)
   4. Cari Klub (Binary Search)
   5. Buat BST dari Klasemen
   6. Tampilkan BST (Inorder)
   7. Buat Graph Pertandingan
   8. Tampilkan Graph (BFS)
   9. Keluar
   ```

## Contoh Penggunaan

### 1. Input Data Klub
```
Masukkan jumlah klub (maksimal 20): 3

Klub 1
Nama Club: Barcelona
Poin: 85
Selisih Gol: 30

Klub 2
Nama Club: Real Madrid
Poin: 82
Selisih Gol: 28

Klub 3
Nama Club: Atletico
Poin: 78
Selisih Gol: 25
```

### 2. Tampilkan Klasemen Terurut
```
--------------------------------------------------
| No. | Nama Club       | Poin | Selisih Gol    |
--------------------------------------------------
| 1   | Barcelona       | 85   | 30            |
| 2   | Real Madrid     | 82   | 28            |
| 3   | Atletico        | 78   | 25            |
--------------------------------------------------
```

### 3. Binary Search
```
Masukkan nama klub yang dicari: Real Madrid
Klub ditemukan: Real Madrid (Poin: 82, Selisih Gol: 28)
```

### 4. BST Traversal
```
Inorder Traversal BST:
----------------------
| Nama Club     | Poin | Selisih Gol |
----------------------
| Barcelona     | 85   | 30          |
| Real Madrid   | 82   | 28          |
| Atletico      | 78   | 25          |
----------------------
```

### 5. Graph BFS
```
Traversal BFS Graph Pertandingan:
Barcelona -> Real Madrid -> Atletico -> END
```

## Struktur Kode
```
- Input Data: inputData()
- Sorting: quickSort(), partition()
- Searching: binarySearch()
- BST: insertBST(), inorderBST()
- Graph: addEdge(), BFS()
```

## Batasan
- Maksimal **20 klub** (ubah `MAX_CLUBS` untuk menyesuaikan)
- Maksimal **10 tetangga** per node graph (`MAX_NEIGHBORS`)

## Catatan
Program ini menggunakan **pure C++** tanpa library tambahan (hanya `<iostream>` dan `<string>`).

```

File ini bisa disimpan sebagai `README.md` di folder project Anda. Format ini mencakup:
- Deskripsi program
- Instruksi kompilasi
- Contoh penggunaan
- Penjelasan fitur
- Struktur kode penting
- Batasan program


SEKIAN TERIMAGAJIEH

Anda bisa menyesuaikan contoh data sesuai kebutuhan.
