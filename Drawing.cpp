#ifndef DRAWING_H
#define DRAWING_H

#include "ListArray.h"
#include "List.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"

class Drawing {
private:
    List<Shape*>* shapes;

public:
    // Constructor
    Drawing() {
        shapes = new ListArray<Shape*>();
    }

    // Destructor
    ~Drawing() {
        // Borrar cada Shape*
        for (int i = 0; i < shapes->size(); i++) {
            delete shapes->get(i);
        }
        // Borrar la lista
        delete shapes;
    }

    // Agregar figura al inicio
    void add_front(Shape* shape) {
        shapes->prepend(shape);
    }

    // Agregar figura al final
    void add_back(Shape* shape) {
        shapes->append(shape);
    }

    // Imprimir todas las figuras
    void print_all() {
        for (int i = 0; i < shapes->size(); i++) {
            Shape* figura = shapes->get(i);
            figura->print();  // Polimorfismo: Square, Rectangle, Circle
        }
    }

    // Calcular área de todos los círculos
    double get_area_all_circles() {
        double area = 0;
        for (int i = 0; i < shapes->size(); i++) {
            Shape* figura = shapes->get(i);
            // Usamos polimorfismo: isCircle()
            if (figura->isCircle()) {
                area += figura->area();
            }
        }
        return area;
    }

    // Mover todos los cuadrados
    void move_squares(double incX, double incY) {
        for (int i = 0; i < shapes->size(); i++) {
            Shape* figura = shapes->get(i);
            if (figura->isSquare()) {
                figura->move(incX, incY);  // Polimórfico: mueve vértices
            }
        }
    }
};

#endif
