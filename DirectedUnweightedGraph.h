#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Edge
{
	int source;
	int destination;
	int weight;
};

class UndirectedweightedGraph
{
private:
	int numberOfVertices;
	vector<vector<pair<int, int>>> adjacencyList;
	//void DFSRec(int vertex, vector<bool>& visited);
public:
	UndirectedweightedGraph(int size);

	void addEdge(const Edge& edge);
	void printGraph() const;
};