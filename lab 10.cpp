#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "DirectedUnweightedGraph.h"

using namespace std;

/*A   B  C  D  E  F  G  H  I  J
A -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
B -1 00 -1 01 02 03 04 05 06 -1
C -1 07 -1 -1 -1 08 09 10 11 -1
D -1 12 13 14 -1 15 -1 16 17 -1
E -1 18 19 -1 -1 -1 -1 20 21 -1
F -1 22 -1 -1 23 24 25 26 27 -1
G -1 28 29 -1 30 -1 -1 -1 31 -1
H -1 32 33 -1 -1 -1 34 -1 35 -1
I -1 36 37 38 39 40 41 42 43 -1
J -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/

UndirectedweightedGraph::UndirectedweightedGraph(int size)
    : numberOfVertices(size), adjacencyList(size, vector<string>(30, "")) {}

void UndirectedweightedGraph::addEdge(const Edge& edge) {
    adjacencyList[edge.source][edge.destination] = edge.weight;
   // adjacencyList[edge.destination][edge.source] = edge.weight;
}

void UndirectedweightedGraph::printGraph() const {
    cout << "Adjacency Matrix:" << endl;

    for (int i = 0; i < adjacencyList.size(); i++){
        for (int j = 0; j <= 29; j = j+3) {
            cout << adjacencyList[i][j]<<' ';
        }
        cout << endl;
    }

}

string getSubStr(const vector<string>& str, int &i, int &k) {

    int counter = 0;
    string sub{};

    if (i == 30) {
        k++;
        i = 0;
    }
    else {
        while (counter < 3 && i <= 30) {
            
            if (str[k][i] == ' ') {
                counter++;
                i++;
            }
            else {
                sub += str[k][i];
                counter++;
                i++;
            }
                
        }

    }


    return sub;
}

int main() {
    ifstream file("C:/Users/Fawzy/source/repos/lab 10/lab 10/graph.txt.txt");


    vector<string> text;
    string line;


    while (getline(file, line)) {
        text.push_back(line);
    }

    file.close();

    int size = text.size();
    int k = 0;
    int l = 0;
    UndirectedweightedGraph graph(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= 29; j+=3) {
                Edge edge;
                edge.source = i;
                edge.destination = j;
                edge.weight = getSubStr(text, k, l);
                graph.addEdge(edge);
        }
    }

    graph.printGraph();

    return 0;
}
