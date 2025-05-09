#include <iostream>
#include <string>
using namespace std;

const int MAX_CLUBS = 20;
const int MAX_NEIGHBORS = 10; // ini Batas tetangga per node di Graph ya rweks

struct Club {
    string nama;
    int poin;
    int selisihGol;
};

// --- BST Node ---
struct BSTNode {
    Club data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Club club) : data(club), left(nullptr), right(nullptr) {}
};

// --- Graph Node ---
struct GraphNode {
    string clubName;
    GraphNode* neighbors[MAX_NEIGHBORS];
    int neighborCount;
    bool visited;
    GraphNode(string name) : clubName(name), neighborCount(0), visited(false) {}
};

// --- Fungsi Utama ---
int inputData(Club liga[]) {
    int jumlah;
    cout << "Masukkan jumlah klub (maksimal " << MAX_CLUBS << "): ";
    cin >> jumlah;
    cin.ignore();

    if (jumlah > MAX_CLUBS) {
        cout << "Jumlah klub melebihi batas! Diubah menjadi " << MAX_CLUBS << endl;
        jumlah = MAX_CLUBS;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nKlub " << i + 1 << endl;
        cout << "Nama Club: ";
        getline(cin, liga[i].nama);
        cout << "Poin: ";
        cin >> liga[i].poin;
        cout << "Selisih Gol: ";
        cin >> liga[i].selisihGol;
        cin.ignore(); 
    }
    return jumlah; 
}

// --- Quick Sort ---
int partition(Club liga[], int low, int high) {
    Club pivot = liga[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (liga[j].poin > pivot.poin || 
           (liga[j].poin == pivot.poin && liga[j].selisihGol > pivot.selisihGol)) {
            i++;
            swap(liga[i], liga[j]);
        }
    }
    swap(liga[i + 1], liga[high]);
    return (i + 1);
}

void quickSort(Club liga[], int low, int high) {
    if (low < high) {
        int pi = partition(liga, low, high);
        quickSort(liga, low, pi - 1);  
        quickSort(liga, pi + 1, high); 
    }
}

// --- Binary Search ---
int binarySearch(Club liga[], int low, int high, string target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (liga[mid].nama == target) return mid;
        if (liga[mid].nama < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// --- BST Operations ---
BSTNode* insertBST(BSTNode* root, Club club) {
    if (!root) return new BSTNode(club);
    if (club.poin > root->data.poin || 
       (club.poin == root->data.poin && club.selisihGol > root->data.selisihGol)) {
        root->left = insertBST(root->left, club);
    } else {
        root->right = insertBST(root->right, club);
    }
    return root;
}

void inorderBST(BSTNode* root) {
    if (root) {
        inorderBST(root->left);
        cout << "| " << root->data.nama << "\t| " << root->data.poin << "\t| " 
             << root->data.selisihGol << "\t|" << endl;
        inorderBST(root->right);
    }
}

// --- Graph Operations ---
void addEdge(GraphNode* a, GraphNode* b) {
    if (a->neighborCount < MAX_NEIGHBORS && b->neighborCount < MAX_NEIGHBORS) {
        a->neighbors[a->neighborCount++] = b;
        b->neighbors[b->neighborCount++] = a;
    }
}

// iki BFS rekursif gawe array untuk simulasi queue
void BFS(GraphNode* nodes[], int size) {
    GraphNode* queue[MAX_CLUBS];
    int front = 0, rear = 0;

    // Reset visited status
    for (int i = 0; i < size; i++) {
        nodes[i]->visited = false;
    }

    // Mulai dari node pertamA
    queue[rear++] = nodes[0];
    nodes[0]->visited = true;

    while (front < rear) {
        GraphNode* current = queue[front++];
        cout << current->clubName << " -> ";

        for (int i = 0; i < current->neighborCount; i++) {
            GraphNode* neighbor = current->neighbors[i];
            if (!neighbor->visited) {
                neighbor->visited = true;
                queue[rear++] = neighbor;
            }
        }
    }
    cout << "END" << endl;
}

void printKlasemen(Club liga[], int jumlah) {
    cout << "\n--------------------------------------------------" << endl;
    cout << "| No. | Nama Club       | Poin | Selisih Gol    |" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "| " << i + 1 << "   | " << liga[i].nama;
        if (liga[i].nama.length() < 10) cout << "\t";
        cout << "\t| " << liga[i].poin << "   | " << liga[i].selisihGol << "\t\t|" << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

int main() {
    Club liga[MAX_CLUBS]; 
    int jumlahKlub = 0;
    int pilihan;
    BSTNode* bstRoot = nullptr;
    GraphNode* graphClubs[MAX_CLUBS];
    int graphSize = 0;

    do {
        cout << "\nMenu Klasemen La Liga:" << endl;
        cout << "1. Input Data Klub" << endl;
        cout << "2. Tampilkan Klasemen (Belum Sorting)" << endl;
        cout << "3. Urutkan Klasemen (Quick Sort)" << endl;
        cout << "4. Cari Klub (Binary Search)" << endl;
        cout << "5. Buat BST dari Klasemen" << endl;
        cout << "6. Tampilkan BST (Inorder)" << endl;
        cout << "7. Buat Graph Pertandingan" << endl;
        cout << "8. Tampilkan Graph (BFS)" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                jumlahKlub = inputData(liga);
                break;
            case 2:
                if (jumlahKlub == 0) {
                    cout << "Data klub kosong!" << endl;
                } else {
                    printKlasemen(liga, jumlahKlub);
                }
                break;
            case 3:
                if (jumlahKlub == 0) {
                    cout << "Data klub kosong!" << endl;
                } else {
                    quickSort(liga, 0, jumlahKlub - 1);
                    cout << "Klasemen setelah diurutkan:" << endl;
                    printKlasemen(liga, jumlahKlub);
                }
                break;
            case 4: {
                if (jumlahKlub == 0) {
                    cout << "Data klub kosong!" << endl;
                } else {
                    quickSort(liga, 0, jumlahKlub - 1); // Pastikan terurut untuk binary search
                    string target;
                    cout << "Masukkan nama klub yang dicari: ";
                    getline(cin, target);
                    int result = binarySearch(liga, 0, jumlahKlub - 1, target);
                    if (result != -1) {
                        cout << "Klub ditemukan: " << liga[result].nama 
                             << " (Poin: " << liga[result].poin 
                             << ", Selisih Gol: " << liga[result].selisihGol << ")" << endl;
                    } else {
                        cout << "Klub tidak ditemukan!" << endl;
                    }
                }
                break;
            }
            case 5:
                if (jumlahKlub == 0) {
                    cout << "Data klub kosong!" << endl;
                } else {
                    for (int i = 0; i < jumlahKlub; i++) {
                        bstRoot = insertBST(bstRoot, liga[i]);
                    }
                    cout << "BST berhasil dibuat!" << endl;
                }
                break;
            case 6:
                if (!bstRoot) {
                    cout << "BST kosong!" << endl;
                } else {
                    cout << "\nInorder Traversal BST:" << endl;
                    cout << "----------------------" << endl;
                    cout << "| Nama Club\t| Poin\t| Selisih Gol\t|" << endl;
                    cout << "----------------------" << endl;
                    inorderBST(bstRoot);
                    cout << "----------------------" << endl;
                }
                break;
            case 7:
                if (jumlahKlub < 2) {
                    cout << "Minimal 2 klub untuk membuat graph!" << endl;
                } else {
                    // Reset graph
                    for (int i = 0; i < graphSize; i++) {
                        delete graphClubs[i];
                    }
                    graphSize = 0;
                    
                    // Buat node graph untuk setiap klub
                    for (int i = 0; i < jumlahKlub; i++) {
                        graphClubs[graphSize++] = new GraphNode(liga[i].nama);
                    }
                    
                    // Contoh: Hubungkan klub secara berurutan
                    for (int i = 0; i < graphSize - 1; i++) {
                        addEdge(graphClubs[i], graphClubs[i + 1]);
                    }
                    cout << "Graph pertandingan berhasil dibuat!" << endl;
                }
                break;
            case 8:
                if (graphSize == 0) {
                    cout << "Graph kosong!" << endl;
                } else {
                    cout << "Traversal BFS Graph Pertandingan:" << endl;
                    BFS(graphClubs, graphSize);
                }
                break;
            case 9:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 9);

    // Cleanup memory
    for (int i = 0; i < graphSize; i++) {
        delete graphClubs[i];
    }
    
    return 0;
}
