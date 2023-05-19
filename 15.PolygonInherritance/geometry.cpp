#include "geometry.h"
#include <iostream>
#include <cmath>

// Pair definitions
template < typename T1, typename T2 >
Pair< T1, T2 > Pair<T1, T2>::operator-(Pair <T1, T2> secound_pair) {
    return Pair<T1, T2> ( this->first - secound_pair.first, this->secound - secound_pair.secound );
}

template < typename T1, typename T2 >
double Pair<T1, T2>::operator*(Pair <> secound_pair) {
    return ( this->first * secound_pair.secound - this->secound * secound_pair.first );
}


/* ................. Regular Polygon ................. */

double RegularPolygon::area() {
    return ( (edge_num / 4.0) * pow( side_length, 2) * (1.0 / tan( M_PI / edge_num ) ) );
}

double RegularPolygon::perimeter() {
    return ( edge_num * side_length );
}

/* ................. Trapezoid ................... */

Trapezoid::Trapezoid( Pair <> first_point, Pair <> secound_point, Pair <> third_point, Pair <> base_point ) 
: first_point( first_point ), secound_point( secound_point ), 
third_point( third_point ), base_point( base_point ), Polygon(4) {
    Pair<> first_side_vector = first_point - base_point;
    Pair<> greater_width_vector = third_point - base_point;
    Pair<> secound_side_vector = secound_point - third_point;
    Pair<> small_width_vector = secound_point - first_point;

    graeter_width_length = magnitude_of_vector( greater_width_vector );
    smaller_width_length = magnitude_of_vector( greater_width_vector );
    first_side_length = magnitude_of_vector( first_side_vector );
    secound_side_length = magnitude_of_vector( secound_side_vector );
    if ( graeter_width_length < smaller_width_length ) {
        std::swap( graeter_width_length, smaller_width_length );
    }
    height_length = std::abs( (greater_width_vector * first_side_vector) / graeter_width_length );
}
double Trapezoid::magnitude_of_vector( Pair <> vector) {
    return sqrt( pow( vector.first, 2 ) + pow( vector.secound, 2 ) );
}
double Trapezoid::area() {
    return ( graeter_width_length + smaller_width_length ) * height_length / 2;
}
double Trapezoid::perimeter() {
    return ( graeter_width_length + smaller_width_length + first_side_length + secound_side_length );
}

/* ................. Parallelogram ................... */

Parallelogram::Parallelogram( Pair <> first_point, Pair <> secound_point, Pair <> base_point ) 
: Trapezoid( first_point, Pair<>(first_point.first + secound_point.first, first_point.secound), secound_point, base_point) {
    width_length = graeter_width_length;
    height_length = Trapezoid::height_length;
    secound_length = secound_side_length;
}
double Parallelogram::area() {
    return width_length * height_length;
}
double Parallelogram::perimeter() {
    return 2 * ( width_length + secound_length );
}

/* .................... Rhombus ...................... */

Rhombus::Rhombus( Pair <> first_point, Pair <> secound_point, Pair <> base_point ) 
: Parallelogram( first_point, secound_point, base_point ) {
    if ( width_length != secound_length ) {
        std::cout << "***The points declared does not form a Rhombus!" << std::endl;
        width_length = 0;
        secound_length = 0;
        height_length = 0;
    }
}

/* .................... Triangle ...................... */

Triangle::Triangle( Pair <> first_point, Pair <> secound_point, Pair <> base_point ) 
: Parallelogram( first_point, secound_point, base_point ) {}
double Triangle::area() {
    return width_length * height_length / 2;
}
double Triangle::perimeter() {
    return  ( width_length + secound_length + magnitude_of_vector( secound_point - first_point ) );
}
/* .................... Rectangle .................... */

Rectangle::Rectangle( double width_length, double height_length) : Parallelogram() {
    Parallelogram::width_length = width_length;
    Parallelogram::height_length = height_length;
}
double Rectangle::perimeter() {
    return 2 * ( width_length + height_length );
}
double Rectangle::get_width_length() {
    return width_length;
}
void Rectangle::set_width_length( double length ) { 
    width_length = length;
}
double Rectangle::get_height_length() {
    return width_length;
}
void Rectangle::set_height_length( double length ) { 
    width_length = length;
}


/* .................... SQAURE ....................... */

double Square::get_length() {
    get_width_length();
}
void Square::set_length( double length ) { 
    set_width_length ( length );
    set_height_length( length );
}