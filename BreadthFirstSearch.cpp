#include <iostream>
#include <vector>
#include <stack>
#include <queue>

/*
   If you want to make your own functions so you can modifiy parameters
   ensure you are using the result vector to store your answers
*/
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

void iterativeBFS( std::vector<std::vector<int>> & adjList, int startNode, std::vector<int> & result ){
    // Your code goes here
    std::queue<int> frontier;
    frontier.push(startNode);
    result.push_back(startNode);

    while(!frontier.empty())
    {
        int curV = frontier.front();
        frontier.pop();

        for(int i = 0; i < adjList[curV].size(); i++)
        {
            if(notInVisited(adjList[curV][i], result))
            {
                frontier.push(adjList[curV][i]);
                result.push_back(adjList[curV][i]);
            }
        }
    }
}


int main() {
   // Nothing is needed in main
    std::vector<std::vector<int>> adj { {1, 2}, {2}, {0, 3}, {3}};
    std::vector<int> result;

    iterativeBFS(adj, 2, result);

    return 0;
}
