// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYYj7xj6TVsDFARc&categoryId=AYzyEMha298DFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

unordered_map<int, int> um;
vector<vector<pair<int, int>>> graph, r_graph;

int compress(int node) // 1,000,000,000인 수들 600개를 600이내의 수로 압축
{
    if (um.count(node)) // != 0 : 이미 um 에 존재
        return um[node];
    else // == 0 : 존재 하지 않아서 새로 추가
        return um[node] = (int)um.size();
}

int init(int N, int sCity[], int eCity[], int mCost[])
{

    um.clear();
    graph.clear();
    r_graph.clear();

    for (int i = 0; i < N; ++i)
        compress(sCity[i]);

    int s = um.size();
    graph.resize(s);
    r_graph.resize(s); // 1->5->1 를 (1->5) : graph 부분과 (5->1) : r_graph 부분으로 쪼개서 계산하기

    for (int i = 0; i < N; ++i)
    {
        graph[um[sCity[i]]].push_back({um[eCity[i]], mCost[i]});
        r_graph[um[eCity[i]]].push_back({um[sCity[i]], mCost[i]});
    }

    return s;
}

void add(int sCity, int eCity, int mCost)
{

    graph[um[sCity]].push_back({um[eCity], mCost});   // 정방향
    r_graph[um[eCity]].push_back({um[sCity], mCost}); // 역방향

    return;
}

int dijkstra(int start, vector<vector<pair<int, int>>> &graph)
{
    vector<int> D(um.size(), INT_MAX);                                                  // 최솟값을 찾아야 하므로 INT MAX 로 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오름차순 pq

    D[start] = 0;
    pq.push({0, start}); // weight - node

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (D[node] != weight) // 해당 노드의 최단 거리가 이미 갱신되었다면 처리하지 않고, 넘어감
            continue;

        for (pair<int, int> e : graph[node])
        {
            if (D[e.first] > weight + e.second)
            {
                D[e.first] = weight + e.second;
                pq.push({D[e.first], e.first}); // weight - node
            }
        }
    }

    int sum = 0;
    for (int weight : D)
        sum += weight;

    return sum;
}

int cost(int mHub)
{
    int city = um[mHub];

    int go = dijkstra(city, graph);
    int come = dijkstra(city, r_graph);

    return go + come;
}
