#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

typedef pair<int, int> pii;

class graph {
	int n;
    vector<vector<pii>> adj;

public:
    int count = 0;
	graph(int n) {
        this->n = n;
        vector<vector<pii>> t(n);
        adj = t;
        
    }

    void addVertex(const string &s1, const string &s2, unordered_map<int, pair<string, string>> &indices, unordered_map<string, int> &ind) {
        indices[count] = make_pair(s1, s2);
        ind[s1] = count;
        count++;
    }

	void addEdge(const string &u, const string &v, int w, unordered_map<string, int> &ind) {
	    adj[ind[u]].push_back(make_pair(ind[v], w));
	    adj[ind[v]].push_back(make_pair(ind[u], w));
    }

	vector<int> shortestPath(int source, int target) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push(make_pair(0, source));
        vector<int> dist(n, INF);

        dist[source] = 0;
        vector<int> parent(n, -1);

        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i : adj[u]) {
                int v = i.first;
                int weight = i.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return parent;
    }
};

int main()
{
	int n = 20;
	graph g(n);
    unordered_map<int, pair<string, string>> indices;
    unordered_map<string, int> ind;
    

	g.addVertex("Noida Sector 62~B", "red", indices, ind);
    g.addVertex("Botanical Garden~B", "red", indices, ind);
    g.addVertex("Yamuna Bank~B", "red", indices, ind);
    g.addVertex("Rajiv Chowk~BY", "blue", indices, ind);
    g.addVertex("Vaishali~B", "red", indices, ind);
    g.addVertex("Moti Nagar~B", "blue", indices, ind);
    g.addVertex("Janak Puri West~BO", "blue", indices, ind);
    g.addVertex("Dwarka Sector 21~B", "blue", indices, ind);
    g.addVertex("Huda City Center~Y", "yellow", indices, ind);
    g.addVertex("Saket~Y", "yellow", indices, ind);
    g.addVertex("Vishwavidyalaya~Y", "blue", indices, ind);
    g.addVertex("Chandni Chowk~Y", "blue", indices, ind);
    g.addVertex("New Delhi~YO", "blue", indices, ind);
    g.addVertex("AIIMS~Y", "yellow", indices, ind);
    g.addVertex("Shivaji Stadium~O", "red", indices, ind);
    g.addVertex("DDS Campus~O", "red", indices, ind);
    g.addVertex("IGI Airport~O", "red", indices, ind);
    g.addVertex("Rajouri Garden~BP", "yellow", indices, ind);
    g.addVertex("Netaji Subhash Place~PR", "yellow", indices, ind);
    g.addVertex("Punjabi Bagh West~P", "yellow", indices, ind);

    g.addEdge("Noida Sector 62~B", "Botanical Garden~B", 8, ind);
    g.addEdge("Botanical Garden~B", "Yamuna Bank~B", 10, ind);
    g.addEdge("Yamuna Bank~B", "Vaishali~B", 8, ind);
    g.addEdge("Yamuna Bank~B", "Rajiv Chowk~BY", 6, ind);
    g.addEdge("Rajiv Chowk~BY", "Moti Nagar~B", 9, ind);
    g.addEdge("Moti Nagar~B", "Janak Puri West~BO", 7, ind);
    g.addEdge("Janak Puri West~BO", "Dwarka Sector 21~B", 6, ind);
    g.addEdge("Huda City Center~Y", "Saket~Y", 15, ind);
    g.addEdge("Saket~Y", "AIIMS~Y", 6, ind);
    g.addEdge("AIIMS~Y", "Rajiv Chowk~BY", 7, ind);
    g.addEdge("Rajiv Chowk~BY", "New Delhi~YO", 1, ind);
    g.addEdge("New Delhi~YO", "Chandni Chowk~Y", 2, ind);
    g.addEdge("Chandni Chowk~Y", "Vishwavidyalaya~Y", 5, ind);
    g.addEdge("New Delhi~YO", "Shivaji Stadium~O", 2, ind);
    g.addEdge("Shivaji Stadium~O", "DDS Campus~O", 7, ind);
    g.addEdge("DDS Campus~O", "IGI Airport~O", 8, ind);
    g.addEdge("Moti Nagar~B", "Rajouri Garden~BP", 2, ind);
    g.addEdge("Punjabi Bagh West~P", "Rajouri Garden~BP", 2, ind);
    g.addEdge("Punjabi Bagh West~P", "Netaji Subhash Place~PR", 3, ind);

    cout << "Enter pickup: ";
    string source, target;
    //cin >> source >> target;
    getline(cin, source);
    cout << "Enter destination: ";
    getline(cin, target);
    cout << endl;
    int src = ind[source];
    int tar = ind[target];
	vector<int> parent = g.shortestPath(src, tar);
    string temp = indices[tar].second;
    while(parent[tar] != -1) {
        if(temp == indices[tar].second) {
            cout << indices[tar].first << "<-";
        }
        else {
            cout << "\n\nChange metro line from " << indices[tar].second << " to " << temp << endl << endl;
            cout << indices[tar].first << "<-";
        }
        temp = indices[tar].second;
        
        
        tar = parent[tar];
    }
    cout << source << endl;

	return 0;
}
