#include "../shape.h"

namespace renderer {
class Rectangle : public Shape {
  public:
    Rectangle(double x, double y, double w, double h) : Shape(x, y), width_(w), height_(h) {}

    void draw() override;

    double width() const { return width_; }
    double height() const { return height_; }

  private:
    double width_;
    double height_;
};

/*
  Исходя из принципа "favor composition over inheritance", я решил сделать класс Square 
  производным класса Shape, а не Rectangle, несмотря на то, что математически квадрат -
  это частный случай прямоугольника. Если оставить наследование с Rectangle, то при
  добавлении сеттеров возникнет проблема с квадратом: он перестанет быть квадратом.
  Это приведёт к нарушению инварианта (в данном случае, равенства сторон квадрата).
  Проблема Квадрата-Прямоугольника...
*/

class Square final : public Shape {
  public:
    Square(double x, double y, double side) : Shape(x, y), side_(side) {}

    void draw() override final;

    double side() const { return side_; }

  private:
    double side_;
};
}
