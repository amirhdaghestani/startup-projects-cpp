#include <iostream>

template < typename Key,
	   typename T >
class Map {
 private:
   Key *key;
   T *value;
   int rear, front, size;
   int search_key( Key key_new );
   void extend_size( int size_new, int neglect_index = -1 );
 public:
   Map();
   ~Map();
   void insert(Key key_new, T value_new);
   void erase( Key key_new );
   void show();
   T& operator[]( Key key_new );
};

template < typename Key,
	   typename T >
Map<Key, T>::Map() {
	size = 8;
	key = new Key[ size ];
	value = new T[ size ];
	rear = 0;
	front = 0;
}

template < typename Key,
	   typename T >
Map<Key, T>::~Map() {
	delete[] key;
	delete[] value;
}

template < typename Key,
	   typename T >
void Map<Key, T>::insert( Key key_new, T value_new ) {
	if ( front >= size )
		extend_size( 2*size );
	key[ front ] = key_new;
	value[ front ] = value_new;
	front++;
	size++;
}

template < typename Key,
	   typename T >
void Map<Key, T>::erase( Key key_new ) {
	int index = search_key( key_new );
	extend_size( size, index );
	front--;
}

template < typename Key,
	   typename T >
void Map<Key, T>::show() {
	std::cout << "\tKey" << "\tValue" << std::endl;
	for( int i = 0; i < front - 1; i++ )
		std::cout << "\t" << key[i] << "\t" << value[i] << std::endl;
}

template < typename Key,
	   typename T >
T& Map<Key, T>::operator[]( Key key_new ) {
	return ( value[ search_key( key_new ) ] );
}

template < typename Key,
	   typename T >
void Map<Key, T>::extend_size( int size_new, int neglect_index ) {
	Key *key_arr_new = new Key[ size_new ];
	T *value_arr_new = new T[ size_new ];
	for( int i = 0, index_erased = 0; i < front - 1; i++ ) {
		if ( i != neglect_index ) {
			key_arr_new[ index_erased ] = key[ i ];
			value_arr_new[ index_erased ] = value[ i ];
			index_erased++;
		}
		
	}
	delete[] key;
	key = key_arr_new;
	delete[] value;
	value = value_arr_new;
}

template < typename Key,
	   typename T >
int Map<Key, T>::search_key( Key key_new ) {
	for( int i = 0; i < size; i++ )
		if ( key[ i ] == key_new )
			return i;
	return -1;
}

int main() {
	Map < char, int > map;
	map.insert( 'a', 1 );
	map.insert( 'b', 2 );
	map.insert( 'c', 3 );
	map.insert( 'd', 4 );
	map.insert( 'e', 5 );
	map.insert( 'f', 6 );
	map.insert( 'g', 7 );
	map.insert( 'h', 8 );
	map.insert( 'i', 9 );
	map.insert( 'j', 10 );

	map.show();

	map.erase( 'h' );
	map.show();
	
	std::cout << map[ 'i' ] << std::endl;	
	
	return 0;
}
