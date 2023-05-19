#ifndef GEOMETRY
#define GEOMETRY

// Pair type struct which gets tuple of points ( Not using STL default Pair struct, for more basic approach )
template < typename T1 = double, 
           typename T2 = double >
struct Pair {
  T1 first;
  T2 secound;
  Pair( T1 first, T2 secound ) : first ( first ), secound ( secound ) {}
  Pair() {}
  Pair< T1, T2 > operator-( Pair <T1, T2> secound_pair );
  double operator*( Pair<> secound_pair );
};

class Polygon {
 protected:
  int edge_num;
 public:
  Polygon( int edge_num ) : edge_num( edge_num ) {}
  virtual double perimeter( ) = 0;
  virtual double area( ) = 0;
};

class RegularPolygon : public Polygon {
 protected:
  double side_length;
 public:
  RegularPolygon( int edge_num, double side_length ) : Polygon( edge_num ), side_length( side_length ) {}
  double perimeter();
  double area();
};

class Trapezoid : public Polygon {
 protected:
  double graeter_width_length;
  double smaller_width_length;  
  double first_side_length;
  double secound_side_length;
  double height_length;
  Pair<> first_point;
  Pair<> secound_point;
  Pair<> third_point;
  Pair<> base_point;
  double magnitude_of_vector( Pair <> vector);
 public:
  Trapezoid( Pair <> first_point = Pair<>(0,0), Pair <> secound_point = Pair<>(0,0), Pair <> third_point = Pair<>(0,0), Pair <> base_point = Pair<>(0,0) );
  virtual double perimeter();
  virtual double area();
};

class Parallelogram : public Trapezoid {
 protected:
  double width_length;
  double secound_length;
  double height_length;
 public:
  Parallelogram( Pair <> first_point = Pair<>(0,0), Pair <> secound_point = Pair<>(0,0), Pair <> base_point = Pair<>(0,0) );
  virtual double perimeter();
  virtual double area();
};

class Rhombus : public Parallelogram {
 public:
  Rhombus( Pair <> first_point = Pair<>(0,0) , Pair <> secound_point = Pair<>(0,0), Pair <> base_point = Pair<>(0,0) );
};

class Triangle : public Parallelogram {
 public:
  Triangle( Pair <> first_point = Pair<>(0,0) , Pair <> secound_point = Pair<>(0,0), Pair <> base_point = Pair<>(0,0) );
  double perimeter();
  double area();
};

class Rectangle : public Parallelogram {
 protected:
 public:
  Rectangle( double width_length = 0, double height_length = 0 );
  virtual double perimeter();
  virtual double get_width_length();
  virtual void set_width_length( double length );
  virtual double get_height_length();
  virtual void set_height_length( double length );
};

class Square : public Rectangle, public Rhombus {
 public:
  Square( double length ) : Rectangle( length, length ) {}
  double get_length();
  void set_length( double length ); 
};





#endif