// TODO:
// 1. Семантика перемещения move(double dx, double dy) для перемещения фигур

namespace renderer {
class Shape {
  public:
    Shape(double x, double y) : x_(x), y_(y) {}
    virtual void draw() = 0;
    virtual ~Shape() = default;

    double x() const { return x_; }
    double y() const { return y_; }

  private:
    double x_;
    double y_;
};
}
