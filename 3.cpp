#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight;
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }

    // ----- BAGIAN DFS -----
    void dfsUtil(int u, vector<bool>& visited, const vector<char>& vertexChar) {
        visited[u] = true;
        cout << vertexChar[u];

        for (int v = numVertices - 1; v >= 0; v--) {
            if (adjMatrix[u][v] > 0 && !visited[v]) {
                cout << " -> ";
                dfsUtil(v, visited, vertexChar);
            }
        }
    }

    void dfs(int startVertex, const vector<char>& vertexChar) {
        vector<bool> visited(numVertices, false);
        cout << "PENJELAJAHAN PARUL (DFS dari A):" << endl;
        dfsUtil(startVertex, visited, vertexChar);
        cout << endl << endl;
    }

    // ----- BAGIAN BFS -----
    void bfs(int startVertex, const vector<char>& vertexChar, const vector<string>& vertexNames) {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        vector<int> parent(numVertices, -1);
        vector<int> edgeCount(numVertices, 0);

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "JALUR TERCEPAT PARUL (BFS):" << endl;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = numVertices - 1; v >= 0; v--) {
                if (adjMatrix[u][v] > 0 && !visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    edgeCount[v] = edgeCount[u] + 1;
                    q.push(v);
                }
            }
        }

        // Jalur dari A ke E (index 4)
        vector<int> path;
        int curr = 4;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }

        // Balik urutan jalur
        int left = 0, right = path.size() - 1;
        while (left < right) {
            swap(path[left], path[right]);
            left++;
            right--;
        }

        // Cetak hasil BFS
        int totalJarak = 0;
        vector<char> pathString;

        for (int i = 0; i < path.size(); ++i) {
            int nodeIndex = path[i];
            cout << vertexNames[nodeIndex] << " (" << vertexChar[nodeIndex] << ")" << endl;
            pathString.push_back(vertexChar[nodeIndex]);

            if (i < path.size() - 1) {
                int u = path[i];
                int v = path[i + 1];
                int jarak = adjMatrix[u][v];
                totalJarak += jarak;
                cout << jarak << "m" << endl;
            }
        }

        cout << "\nJalur terpendek: ";
        for (int i = 0; i < pathString.size(); ++i) {
            cout << pathString[i];
            if (i < pathString.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Total langkah: " << (path.size() - 1) << " edge" << endl;
        cout << "Total jarak: " << totalJarak << " meter" << endl;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    vector<char> vertexChar = {'A', 'B', 'C', 'D', 'E'};
    vector<string> vertexNames = {
        "Ikan Bakar Pak Harry",
        "Gudang Kaleng Bekas",
        "Sushi Kucing Alya",
        "Kedai IKLC",
        "Pasar Ikan Tengah Malam"
    };

    g.addEdge(0, 1, 5); // A-B
    g.addEdge(0, 2, 2); // A-C
    g.addEdge(1, 3, 4); // B-D
    g.addEdge(2, 3, 1); // C-D
    g.addEdge(3, 4, 3); // D-E

    g.dfs(0, vertexChar);
    cout << endl;
    g.bfs(0, vertexChar, vertexNames);

    return 0;
}