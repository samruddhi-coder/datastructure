#include <iostream>
#include <list>
     
    using namespace std;
     
    class Graph
    {
        int V;
        list<int> *adjLists;
        bool* visited;
    public:
        Graph(int V);  
        void addEdge(int src, int dest); 
        void BFS(int startVertex);
    };
     
    Graph::Graph(int  V)
    {
         this->V = V; 
        adjLists = new list<int>[V];
    }
     
    void Graph::addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        //[dest].push_back(src);
    }
     
    void Graph::BFS(int startVertex)
    {
        visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;
     
        list<int> queue;
     
        visited[startVertex] = true;
        queue.push_back(startVertex);
     
        list<int>::iterator i;
     
        while(!queue.empty())
        {
            startVertex = queue.front();
            cout << "Visited " << startVertex << " ";
            queue.pop_front();
     
            for(i = adjLists[startVertex].begin(); i != adjLists[startVertex].end(); ++i)
            {
                int adjVertex = *i;
                if(!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
        }
    }
     
    int main()
    {
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        g.BFS(2);
     
        return 0;
    }

