#include <iostream>
#include <vector>

class Node {
private:
	std::string name;
	int num_of_node;
public:
	Node( int num_of_node_new );
	void set_name( std::string name_new );
	std::string get_name();
};

Node::Node( int num_of_node_new ) {
	name = "";
	num_of_node = num_of_node_new;
}

void Node::set_name( std::string name_new ) {
	name = name_new;
}

std::string Node::get_name() {
	return name;
}

class Edge {
private:
	int weight, node_a, node_b;
public:
	Edge( int node_a, int node_b, int weight = 1 );
};

Edge::Edge( int node_a_new, int node_b_new, int weight_new ) {
	node_a = node_a_new;
	node_b = node_b_new;
	weight = weight_new;
}

class Graph {
 private:
   int vertices_num, pointer;
   int** adj;
   Node** node;
   void init_adj();
   void init_node();
   void free_adj();
   void free_node();
   int get_index_of_node( std::string city_name );
 public:
   Graph( int v = 0 );
   ~Graph();
   void free();
   void set_graph( int v );
   void set_node( int i, std::string city_name );
   void add_edge( std::string city_a, std::string city_b);
   void BFS( std::string city_a, std::string city_b );
   void show_adj();
   int get_vertices_num();
};

Graph::Graph( int v ) {
	vertices_num = v;
	pointer = 0;
	init_adj();
	init_node();
}

Graph::~Graph() {
	free();
}

void Graph::free() {
	free_adj();
	free_node();
}

void Graph::free_adj() {
	for( int i = 0; i < vertices_num; i++ ) {
		delete[] adj[ i ];
		adj[ i ] = NULL;
	}
	delete[] adj;
	adj = NULL;
}

void Graph::free_node() {
	for( int i = 0; i < vertices_num; i++ ) {
		delete node[ i ];
		node[ i ] = NULL;
	}
	delete[] node;
	node = NULL;
}

void Graph::init_adj() {
	adj = new int*[ vertices_num ];
	for( int i = 0; i < vertices_num; i++ ) {
		adj[i] = new int[ vertices_num ];
		for( int j = 0; j < vertices_num; j++ )
			adj[i][j]  = 0;
	}
}

void Graph::init_node() {
	node = new Node*[ vertices_num ];
	for( int i = 0; i < vertices_num; i++ )
		node[ i ] = new Node(i);
}

void Graph::set_node(int i, std::string city_name) {
	if ( city_name.compare(":number") == 0 ) {
		for ( int k = i; k < vertices_num; k++ )
			node[k]->set_name( std::to_string( k + 1 ) );
	}
	else 
		node[i]->set_name( city_name );
}

void Graph::set_graph( int v ) {
	vertices_num = v;
	init_adj();
	init_node();
}

void Graph::add_edge( std::string city_a, std::string city_b ) {
	int node_a = 0, node_b = 0;
	node_a = get_index_of_node(city_a);
	node_b = get_index_of_node(city_b);
	adj[ node_a ][ node_b ] = 1;
	adj[ node_b ][ node_a ] = 1;
}

void Graph::show_adj() {
	for( int i = 0; i < vertices_num; i++ ) {
		for( int j = 0; j < vertices_num; j++ )
			std::cout << adj[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Graph::get_vertices_num() {
	return vertices_num;
}

int Graph::get_index_of_node( std::string city_name ) {
	for( int i = 0; i < vertices_num; i++ )
		if ( node[i]->get_name().compare(city_name) == 0 )
			return i;
	return -1;
}

void Graph::BFS( std::string city_a, std::string city_b ) {
	int node_a = 0, node_b = 0, temp;
	bool* visited = new bool[ vertices_num ]; // remember to delete this
	for( int i = 0; i < vertices_num; i++ )
		visited[i] = false;
	
	std::vector<int> queue;

	node_a = get_index_of_node( city_a );
	node_b = get_index_of_node( city_b );
	
	visited[ node_a ] = true;
	queue.push_back( node_a );

	while( !queue.empty() ) {
		
		node_a = queue.back();
		std::cout << node[ node_a ]->get_name() << " - ";
		queue.pop_back();

		if ( node_a == node_b )
			break;
			
		for( int j = 0; j < vertices_num; j++ ) {
			if( adj[ node_a ][ j ] == 1) {
				if( !visited[ j ] ) {
					visited[ j ] = true;
					queue.push_back( j );
				}
			}
		}
	}

	std::cout << "end" << std::endl;

	delete[] visited;
}

int main() {
	Graph graph;
	int vertices_num = 0;
	std::string str_a, str_b;

	std::cout << "Enter the number of cities> ";
	std::cin >> vertices_num;
	graph.set_graph( vertices_num );
	
	std::cout << "Enter the name of the cities> (If you'd rather to have numbers instead of name, e.g. city '1', type ':number')" << std::endl;
	for( int i = 0; i < vertices_num; i++ ) {
		std::cin >> str_a;
		graph.set_node( i, str_a );
		if ( str_a.compare(":number") == 0 )
			break;
	}
	
	std::cout << "Which two cities are connected? (type 'E' if your entery was over)" << std::endl;
	while( 1 ) {
		std::cin >> str_a;
		if ( str_a == "e" || str_a == "E" )
			break;
		std::cin >> str_b;
		graph.add_edge( str_a, str_b );
		
	}
	
	std::cout << "Which two cities, you want to find the shortest path?" << std::endl;
	std::cin >> str_a;
	std::cin >> str_b;
	
	std::cout << "The shortest path is: ";
	graph.BFS( str_a, str_b );
	

	return 0;
}
