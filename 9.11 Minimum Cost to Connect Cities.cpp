#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

bool notInVisited(int curV, std::vector<int> & result){
    bool inVisited = true;

    for(int i = 0; i < result.size(); i++)
    {
        if ( curV == result[i])
        {
            inVisited = false;
            break;
        }
    }

    return inVisited;
}

int minimumCost( std::vector<std::vector<int>> & graph ){


    std::vector<int> visited;
    int startingV = 0;
    visited.push_back(startingV);
    int totalCost = 0;

    while(visited.size() < graph.size()) {
        int leastEdge = std::numeric_limits<int>::max();

        //find smallest edge in graph
        int curV = -1;
        int i = -1;
        for (int k = 0; k < graph.size(); k++)
        {
            if(notInVisited(k, visited))
            {
                continue;
            }

            for (int j = 0; j <= graph[k].size() - 1; j++) {
                if (graph[k][j] < leastEdge && graph[k][j] != 0) {
                    leastEdge = graph[k][j];
                    i = j;
                    curV = k;
                }
            }

        }
        if(notInVisited(curV, visited) || notInVisited(i, visited))
        {
            totalCost += graph[curV][i];
        }

        //Add non visited verticies
        if(notInVisited(curV, visited))
        {
            visited.push_back(curV);
        }
        if(notInVisited(i, visited))
        {
            visited.push_back(i);
        }

        //Max out edge
        graph[curV][i] = std::numeric_limits<int>::max();
    }

    return totalCost;
}

int main() {
    // Nothing needs to be in main
    std::vector<std::vector<int>> graph {{0, 1, 1, 100, 0, 0},
                                         {1, 0, 1, 0, 0, 0},
                                         {1, 1, 0, 0, 0, 0},
                                         {100, 0, 0, 0, 2, 2},
                                         {0, 0, 0, 2, 0, 2},
                                         {0, 0, 0, 2, 2, 0}};

    std::cout << minimumCost(graph);

    return 0;
}
