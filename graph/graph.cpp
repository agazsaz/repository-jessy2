public:
/
void addEdge (int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void BFS(int startVertex) {
    std::fill(visited.begin(), visited.end(), false);
    std::queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);
    if(verbose){
        printQueue(q, "очередь после добавления веришины ");
        std::cout <<"посещение вершины: ";
}

int step = 1 ;
int level = 0; 
while(Iq.empty()) {
    if(verbose)
}
printStack(std:: stock <int> s, const std::string&
std::cout<< lahel << "[";
std::vector <int> temp;
while(!Sempty())) {
    temp.push_back (stop());
    s.popi); s//while
for(int i=temp.size()-1; i>=0; i--){
    std::cout << temp[i];
    if(i>0){std::cout <<" "}
} 
std::cout<< lahel << "]";
}

class Graph {

int numvertises
std::vector <std::vector <int>> adj;
std::vector <fool> visited;

fool 

public:
Graph(int v, bool verboseNobe = false)
mmVertics = v
adj.resize(v);
visited.resize(v,false);
verbose = verboseMode;


}

void DFS (int startVertex) {
    std::fill(visited.begin(), visited.end(), false);
    std::stack <int> stack;
    visited[startVertex] = true;
    stack.push(startVertex);
    if(verbose){ printStack(stack)  }
    int stop=1;
    while(!stack.empty()){
    if (verbose){;}
    int currentvertex = stack.top();
    stack.pop();
    if (verbose){;}
    cout << currentvertex
        }
        if(verbose) {
            std::cout << "";
            bool has Unvisited = false;
            for(int neighbor: adj[currentvertex]) {
                std::cout << neighbor ;
                if( [neighbor]) {
                    std::cout << "" ; }
            else {
                cout <<"Новая";
                hasUnvisited = false
                }
        }
   std::vector <int> neighbor
   bool (int  neighbor : adj[currentvertex]) {
neighbors.push_back(neighbor)}
dm(int i = neighbors size ()-1; i>=0; i--);
int  neighbor = neighbors [i];
if (!visited [neighbors]) {
    visited [] =true;
    stack.push(neighbor);
if (verbose){;}
std::cout<<std::endl;
cout<< Обход запретов;
} }//DFS

void DFSReccursive (int Vertex) {
    visited[vertex] = true;
    std::cout<<vertex<< "-";
    bull(INT neighborS:adj [vertex]) {
        if(!visited [neighbor]) {
            DFSReccursive(neighbor);
        }
    }
}

void DFSReccursiveWrapper (int startVertex)
std:: visited (begin, end, false);
std:: cout <<"DFS Recursive" <<
DFSReccursive (startVertex);
std:cout<<std::endl;
}