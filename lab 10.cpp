#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "DirectedUnweightedGraph.h"

using namespace std;



UndirectedweightedGraph::UndirectedweightedGraph(int size)
    : numberOfVertices(size), adjacencyList(size, vector<pair<int, int>>(size)) {}

void UndirectedweightedGraph::addEdge(const Edge& edge) {
    adjacencyList[edge.source][edge.destination] = make_pair(edge.weight, edge.destination);
    adjacencyList[edge.destination][edge.source] = make_pair(edge.weight, edge.source);
}

void UndirectedweightedGraph::printGraph() const {
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : adjacencyList) {
        for (const auto& pair : row) {
            cout << pair.first << " ";
        }
        cout << endl;
    }
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
    UndirectedweightedGraph graph(size);

    for (int i = 0; i < size; ++i) {
        string temp = text[i];
        for (int j = 0; j < size; ++j) {
            if (temp[j * 3] != '-') {
                Edge edge;
                edge.source = i;
                edge.destination = j;
                edge.weight = stoi(temp.substr(j * 3 + 1, 2));
                graph.addEdge(edge);
            }
        }
    }

    graph.printGraph();

    return 0;
}