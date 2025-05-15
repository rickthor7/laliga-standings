3. Struktur Data Binary Search Tree (BST)

Pada bagian ini, struktur BST didefinisikan menggunakan BSTNode:

struct BSTNode {
    Club data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Club club) : data(club), left(nullptr), right(nullptr) {}
};

data: Menyimpan data klub (objek Club).

left: Pointer ke node kiri (klub dengan nilai lebih kecil).

right: Pointer ke node kanan (klub dengan nilai lebih besar).


Konstruktor:

BSTNode(Club club) : data(club), left(nullptr), right(nullptr) {}

Menginisialisasi node baru dengan data club.

left dan right di-set ke nullptr (belum ada anak node).


BST ini akan digunakan untuk menyimpan dan mengurutkan klub berdasarkan kriteria tertentu, misalnya nama atau poin.

4. Struktur Data Graph

Struktur data Graph didefinisikan menggunakan GraphNode:

struct GraphNode {
    string clubName;
    GraphNode* neighbors[MAX_NEIGHBORS];
    int neighborCount;

    GraphNode(string name) : clubName(name), neighborCount(0) {}
};

clubName: Nama klub sebagai identitas node.

neighbors: Array pointer yang menyimpan tetangga dari node tersebut.

neighborCount: Jumlah tetangga saat ini (maksimum MAX_NEIGHBORS).


Konstruktor:

GraphNode(string name) : clubName(name), neighborCount(0) {}

Inisialisasi nama klub.

neighborCount diatur ke 0.

Array neighbors belum diisi (masih nullptr).


Graph ini digunakan untuk merepresentasikan hubungan antar klub, misalnya pertandingan atau pertemuan.

Selanjutnya, saya akan lanjutkan ke implementasi BST, termasuk operasi insert, search, dan traversal.

5. Implementasi BST - Insert, Search, dan Traversal

a. Insert Node dalam BST

Fungsi untuk menambahkan node baru dalam BST kemungkinan besar berbentuk seperti ini:

BSTNode* insertBST(BSTNode* root, Club club) {
    if (root == nullptr) {
        return new BSTNode(club);
    }

    if (club.nama < root->data.nama) {
        root->left = insertBST(root->left, club);
    } else {
        root->right = insertBST(root->right, club);
    }

    return root;
}

Jika root adalah nullptr, node baru dibuat.

Jika club.nama lebih kecil dari root->data.nama, node akan ditempatkan di subtree kiri.

Jika lebih besar, node ditempatkan di subtree kanan.



---

b. Search Node dalam BST

Untuk mencari klub berdasarkan nama:

BSTNode* searchBST(BSTNode* root, string nama) {
    if (root == nullptr || root->data.nama == nama) {
        return root;
    }

    if (nama < root->data.nama) {
        return searchBST(root->left, nama);
    } else {
        return searchBST(root->right, nama);
    }
}

Jika root adalah nullptr, maka klub tidak ditemukan.

Jika nama sama dengan root->data.nama, node ditemukan.

Jika nama lebih kecil, pencarian dilanjutkan ke subtree kiri, sebaliknya ke kanan.



---

c. Inorder Traversal BST

Traversal inorder (kiri, akar, kanan) untuk mencetak data dalam urutan terurut:

void inorderTraversal(BSTNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << "Nama Klub: " << root->data.nama << ", Poin: " << root->data.poin << ", Selisih Gol: " << root->data.selisihGol << endl;
        inorderTraversal(root->right);
    }
}

Traversal inorder berguna untuk mencetak data dalam urutan abjad (jika BST diurutkan berdasarkan nama).


Selanjutnya, saya akan lanjutkan ke implementasi Graph, termasuk penambahan tetangga dan pencarian jalur.

6. Implementasi Graph - Penambahan Tetangga dan Pencarian Jalur

a. Menambahkan Tetangga dalam Graph

Untuk menambahkan tetangga (node terhubung) pada sebuah node:

void addNeighbor(GraphNode* node, GraphNode* neighbor) {
    if (node->neighborCount < MAX_NEIGHBORS) {
        node->neighbors[node->neighborCount++] = neighbor;
    } else {
        cout << "Jumlah tetangga maksimum tercapai untuk " << node->clubName << endl;
    }
}

Jika jumlah tetangga belum mencapai MAX_NEIGHBORS, tetangga baru ditambahkan ke array neighbors.

Jika sudah penuh, pesan peringatan akan ditampilkan.



---

b. Pencarian Jalur dalam Graph (Depth-First Search - DFS)

Implementasi pencarian jalur menggunakan DFS:

void dfs(GraphNode* node, string target, bool visited[], bool& found) {
    if (node->clubName == target) {
        found = true;
        return;
    }

    for (int i = 0; i < node->neighborCount; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(node->neighbors[i], target, visited, found);
        }
    }
}

Fungsi ini melakukan pencarian jalur dari node saat ini hingga menemukan node dengan clubName yang sesuai target.

visited[] digunakan untuk mencegah loop.

found menjadi true jika node target ditemukan.



---

c. Inisialisasi dan Penggunaan Graph

Misalnya, untuk membuat node dan menambahkan tetangga:

GraphNode* nodeA = new GraphNode("Klub A");
GraphNode* nodeB = new GraphNode("Klub B");

addNeighbor(nodeA, nodeB);

Graph ini dapat digunakan untuk merepresentasikan jaringan klub yang memiliki hubungan tertentu (misalnya pertandingan yang pernah dilakukan).

Selanjutnya, saya akan lanjutkan ke fungsi utama dan interaksi pengguna.

7. Fungsi Utama dan Interaksi Pengguna

Pada bagian ini, fungsi utama (main) akan menggabungkan semua struktur data dan fungsi yang telah dijelaskan.

a. Inisialisasi BST dan Graph

Di dalam fungsi main(), kita dapat menginisialisasi BST dan Graph seperti ini:

int main() {
    BSTNode* bstRoot = nullptr;

    GraphNode* graph[MAX_CLUBS];
    int graphSize = 0;

    // Contoh data klub
    Club club1 = {"Klub A", 30, 10};
    Club club2 = {"Klub B", 25, 5};

    // Insert ke BST
    bstRoot = insertBST(bstRoot, club1);
    bstRoot = insertBST(bstRoot, club2);

    // Inisialisasi Graph
    graph[graphSize++] = new GraphNode("Klub A");
    graph[graphSize++] = new GraphNode("Klub B");

    addNeighbor(graph[0], graph[1]);  // Menambahkan hubungan antar klub

    // Traversal BST
    cout << "Data Klub (Inorder BST):" << endl;
    inorderTraversal(bstRoot);

    return 0;
}


---

b. Interaksi Pengguna: Input Data Klub

Untuk memungkinkan pengguna menambahkan klub secara dinamis:

void inputClubData(BSTNode*& bstRoot, GraphNode* graph[], int& graphSize) {
    string nama;
    int poin, selisihGol;

    cout << "Masukkan nama klub: ";
    cin >> nama;
    cout << "Masukkan poin klub: ";
    cin >> poin;
    cout << "Masukkan selisih gol: ";
    cin >> selisihGol;

    Club newClub = {nama, poin, selisihGol};

    // Tambahkan ke BST
    bstRoot = insertBST(bstRoot, newClub);

    // Tambahkan ke Graph
    graph[graphSize++] = new GraphNode(nama);
}

Fungsi ini menerima input klub baru dari pengguna.

Data klub tersebut dimasukkan ke dalam BST dan Graph.



---

c. Pencarian Klub Berdasarkan Nama

Untuk mencari klub berdasarkan nama dalam BST:

void searchClub(BSTNode* bstRoot) {
    string nama;
    cout << "Masukkan nama klub yang dicari: ";
    cin >> nama;

    BSTNode* result = searchBST(bstRoot, nama);
    if (result) {
        cout << "Nama: " << result->data.nama << ", Poin: " << result->data.poin << ", Selisih Gol: " << result->data.selisihGol << endl;
    } else {
        cout << "Klub tidak ditemukan." << endl;
    }
}


---

Pada tahap ini, pengguna dapat menambahkan klub baru, melihat data klub secara terurut, serta mencari klub berdasarkan nama.

Selanjutnya, saya akan lanjutkan ke bagian terakhir yaitu kesimpulan dan analisis kompleksitas.

