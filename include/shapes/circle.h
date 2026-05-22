#pragma once

#include "../shape.h"
#include <memory>

namespace renderer {
class Circle : public Shape {
  public:
    Circle(double x, double y, double r) : Shape(x, y), radius_(r) {}

    std::unique_ptr<Shape> clone() const override {
      return std::make_unique<Circle>(x(), y(), radius_);
    }
    void draw() override;

    double radius() const { return radius_; }

  private:
    double radius_;
};
}
