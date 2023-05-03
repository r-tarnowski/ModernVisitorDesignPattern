#include <iostream>
#include <string>
#include <algorithm>
#include <variant>

using std::cout;
using std::endl;

class Circle {
public:
   explicit Circle( double rad )
         : radius{ rad }
         //... Remaining data members
   {}

   double getRadius() const noexcept {
      return radius;
   }

// ... getCenter(), getRotation(), ...
private:
   double radius;
// ... Remaining data members
};

class Square
{
public:
   explicit Square( double s )
         : side{ s }
         // ... Remaining data members
   {}

   double getSide() const noexcept {
      return side;
   }
// ... getCenter(), getRotation(), ...
private:
   double side;
// ... Remaining data members
};

using Shape = std::variant<Circle,Square>;

class Draw {
public:
   void operator()( const Circle & circle ) const {
      std::cout << "class Draw for Circle with radius: "
                << circle.getRadius() << " called."<< std::endl;
   }

   void operator()( const Square & square) const {
      std::cout << "class Draw for Square with side: "
                << square.getSide() << " called." << std::endl;
   }
};

void drawAllShapes( const std::vector<Shape> & shapes ) {
   for( auto const & s : shapes ) {
      std::visit( Draw{}, s );
   }
}



void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "         Modern Visitor Design Pattern          " << endl;
   cout << "             an example taken from              "  << endl;
   cout << "        the lecture by Klaus Iglberger          " << endl;
   cout << "      Breaking Dependencies - Type Erasure      " << endl;
   cout << "                 CppCon 2022                    " << endl;
   cout << "================================================" << endl;
   cout << endl;
}



int main(int argc, char *argv[]) {
   printHeader();

   using Shapes = std::vector<Shape>;
// Creating some shapes
   Shapes shapes;
   shapes.emplace_back( Circle{ 2.0 } );
   shapes.emplace_back( Square{ 1.5 } );
   shapes.emplace_back( Circle{ 4.2 } );
// Drawing all shapes
   drawAllShapes( shapes );


   cout << endl << "main() completed" << endl << endl;
   return 0;
}
