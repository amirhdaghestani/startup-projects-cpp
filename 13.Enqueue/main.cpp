#include <iostream>
template <class T>
class Queue {
private:
   int rear;
   int front;
   T *queue;
   int size;
   void extend_size();
   bool in_range( T input, T minimum, T maximum );
public:
   Queue();
   ~Queue();
   void push_back( T input );
   T pop_back();
   T pop_front();
   T get_front();
   bool swap( int i, int j );
   bool is_empty();
   T& operator[]( int index ) {
	return queue[ index + rear ];	
   }
};

template<class T>
Queue<T>::Queue() {
	rear = 0;
	front = 0;
	queue = new T[ 8 ];
	size = 8;
}

template<class T>
Queue<T>::~Queue() {
	delete[] queue;
}

template<class T>
void Queue<T>::push_back( T input ) {
	if ( front >= size)
		extend_size();
	queue[ front ] = input;
	front++;
}

template<class T>
T Queue<T>::pop_back() {
	if ( front > (rear) )
		return queue[ ++rear ];
}

template<class T>
T Queue<T>::pop_front() {
	if ( front > (rear) )
		return queue[ --front ];
}

template<class T>
T Queue<T>::get_front() {
	if ( front > (rear) )
		return queue[ front - 1 ];
}

template<class T>
bool Queue<T>::swap( int i, int j ) {
	if ( in_range( i, rear, front - 1 ) && in_range( j, rear, front - 1 ) ) {
		T temp = queue[ i ];
		queue[ i ] = queue[ j ];
		queue[ j ] = temp;
	}
}

template<class T>
void Queue<T>::extend_size() {
	T *temp = new T[ 2*size ];
	for( int i = rear; i < size; i++ )
		temp[ i - rear ] = queue[ i ];
	size *= 2;
	delete[] queue;
	queue = temp;
	front -= rear;
	rear = 0;
}

template<class T>
bool Queue<T>::in_range( T input, T minimum, T maximum ) {
	if ( input <= maximum && input >= minimum )
		return true;
	return false;
}

template<class T>
bool Queue<T>::is_empty() {
	return ( front == (rear) )?true:false;
}

int main( int args, char* argc[]) {
	Queue<int> queue;
	for( int i = 0; i < 8; i++ )
		queue.push_back( i );
	
	std::cout << queue[ 0 ] << std::endl;
	queue.pop_back();
	std::cout << queue[ 0 ] << std::endl;
	queue.pop_back();
	std::cout << queue[ 0 ] << std::endl;
	
	for( int i = 8; i < 16; i++ )
		queue.push_back( i );
	
	std::cout << queue[ 0 ] << std::endl;
	queue.pop_back();
	std::cout << queue[ 0 ] << std::endl;

	std::cout << queue.get_front() << std::endl;
	queue.pop_front();
	std::cout << queue.get_front() << std::endl;

	std::cout << queue.is_empty() << std::endl;
	for( int i = 0; i < 12; i++)
		queue.pop_back();

	std::cout << queue.is_empty() << std::endl;
}
