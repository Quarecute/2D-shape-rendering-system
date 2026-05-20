#include "../shape.h"

namespace renderer {
class Circle : public Shape {
  public:
    Circle(double x, double y, double r) : Shape(x, y), radius_(r) {}

    void draw() override {};
    double radius() const { return radius_; }

  private:
    double radius_;
};
}
