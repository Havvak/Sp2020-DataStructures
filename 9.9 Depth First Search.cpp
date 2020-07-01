#include <iostream>
#include <vector>
#include <stack>

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

void iterativeDFS( std::vector<std::vector<int>> & adjList, int startNode, std::vector<int> & result ){
    /* Your code goes here */
    std::stack<int> stack;
    stack.push(startNode);

    while(!stack.empty())
    {
        int curV = stack.top();
        stack.pop();

        if(notInVisited(curV, result))
        {
            result.push_back(curV);
            for(int i = 0; i < adjList[curV].size(); i++)
            {
                stack.push(adjList[curV][i]);
            }

        }
    }
}

void recursiveDFS( std::vector<std::vector<int>> & adjList, int currNode, std::vector<bool> & visited, std::vector<int> & result ){
    /* Your code goes here */
    if(notInVisited(currNode, result)){
        result.push_back(currNode);
        for(int i = 0; i < adjList[currNode].size(); i++)
        {
            recursiveDFS(adjList, adjList[currNode][i], visited, result);
        }
    }
}


int main() {
    // Nothing is needed in main
    std::vector<std::vector<int>> adj { {1, 2}, {2}, {0, 3}, {3}};
    std::vector<int> result;
    std::vector<bool> visited;

    recursiveDFS(adj, 2, visited, result);

    return 0;
}
