#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define INF 100000000
using namespace std;

int V, E;
int v1, v2;
vector<pair<int, int>> vertex[801]; // {weight, destination}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist_v1[801], dist_v2[801], result[2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	int s, d, w;

	for (int i = 0; i < E; i++) {
		cin >> s >> d >> w;
		// undirected graph
		vertex[s].push_back({ w,d });
		vertex[d].push_back({ w,s });
	}
	cin >> v1 >> v2;
	// Initiate distances to INF
	for (int i = 1; i <= V; i++) {
		dist_v1[i] = INF;
		dist_v2[i] = INF;
	}
	// v1에서의 dijkstra
	dist_v1[v1] = 0;
	pq.push({ 0, v1 });
	while (!pq.empty()) {
		w = pq.top().first;
		s = pq.top().second;
		pq.pop();

		if (dist_v1[s] < w) continue;

		for (int i = 0; i < vertex[s].size(); i++) {
			d = vertex[s][i].second;
			if (dist_v1[d] > w + vertex[s][i].first) {
				dist_v1[d] = w + vertex[s][i].first;
				pq.push({ dist_v1[d], d });
			}
		}
	}
	// v2에서의 dijkstra
	dist_v2[v2] = 0;
	pq.push({ 0, v2 });
	while (!pq.empty()) {
		w = pq.top().first;
		s = pq.top().second;
		pq.pop();

		if (dist_v2[s] < w) continue;

		for (int i = 0; i < vertex[s].size(); i++) {
			d = vertex[s][i].second;
			if (dist_v2[d] > w + vertex[s][i].first) {
				dist_v2[d] = w + vertex[s][i].first;
				pq.push({ dist_v2[d], d });
			}
		}
	}
	result[0] = result[1] = INF; 
	// result[0]: 1->v1->v2->N, result[1]: 1->v2->v1->N
	// If the path(v1 -> v2 || v2 -> v1) isn't exist, then print -1.
	if (dist_v1[v2] == INF) {
		cout << "-1\n";
	}
	else {
		// result[0] check.
		if (dist_v1[1] != INF && dist_v2[V] != INF) {
			result[0] = dist_v1[1] + dist_v1[v2] + dist_v2[V];
		}
		// result[1] check.
		if (dist_v2[1] != INF && dist_v1[V] != INF) {
			result[1] = dist_v2[1] + dist_v1[v2] + dist_v1[V];
		}

		// if the path is not exist,
		if (result[0] == INF && result[1] == INF) {
			cout << "-1\n";
		}
		else {
			cout << min(result[0], result[1]) << "\n";
		}
	}
	return 0;
}