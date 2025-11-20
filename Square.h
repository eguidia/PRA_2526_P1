#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"
#include "Shape.h"

class Square : public Rectangle {
	public:
		static bool check(Point2D* vertices);
		Square();
		Square(std::string color, Point2D* vertices);
		void set_vertices(Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);
			
		//metodos heredados de la clase Rectangle
	
		void print();
		bool isSquare() const override { 
			return true; 
		}
    		void move(double dx, double dy) override {
        		for (int i = 0; i < N_VERTICES; i++) {
            			vs[i].x += dx;
            			vs[i].y += dy;
        }
    }
};

#endif
