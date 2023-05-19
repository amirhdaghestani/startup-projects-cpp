#include <iostream>
#include "geometry.h"



int main( int argc, char* args[] ) {
   Rectangle rect( 5, 4);
   Square square(2);
   Parallelogram parallelogram( Pair<>(3,4), Pair<>(6,0) );
   Rhombus rhombus( Pair<>(3,4), Pair<>(5,0) );
   Triangle triangle( Pair<>(1,1), Pair<>(1,0));
   Trapezoid trapezoid( Pair<>(0,1), Pair<>(1,1), Pair<>(1,0) );
   RegularPolygon regularPolygon( 6, 1 );
   
   std::cout << "Rectangle Area: " << rect.area() << " Perimeter: " << rect.perimeter() << std::endl;
   std::cout << "Square Area: " << square.Rectangle::area() << " Perimeter: " << square.Rectangle::perimeter() << std::endl;
   std::cout << "Parallelogram Area: " << parallelogram.area() << " Perimeter: " << parallelogram.perimeter() << std::endl;
   std::cout << "Rhombus Area: " << rhombus.area() << " Perimeter: " << rhombus.perimeter() << std::endl;
   std::cout << "Triangle Area: " << triangle.area() << " Perimeter: " << triangle.perimeter() << std::endl;
   std::cout << "Trapezoid Area: " << trapezoid.area() << " Perimeter: " << trapezoid.perimeter() << std::endl;
   std::cout << "Regular Polygon Area: " << regularPolygon.area() << " Perimeter: " << regularPolygon.perimeter() << std::endl;
   
   return 0;
}