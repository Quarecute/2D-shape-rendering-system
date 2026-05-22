#pragma once

#include "../shape.h"
#include <memory>
#include <optional>

namespace renderer {
class Triangle : public Shape {
  public:
    std::unique_ptr<Shape> clone() const override {
      if (auto opt = Triangle::create(x(), y(), first_side_, second_side_, third_side_))
        return std::make_unique<Triangle>(std::move(*opt));
      return nullptr;
      // return std::make_unique<Triangle>(*this);
    }
    void draw() override;

    double first_side()  const { return first_side_;  }
    double second_side() const { return second_side_; }
    double third_side()  const { return third_side_;  }

    static std::optional<Triangle> create(double x, double y, double AB, double BC, double AC) noexcept;
    static std::optional<Triangle> make_isosceles(double x, double y, double side, double foundation) noexcept;
    static std::optional<Triangle> make_equilateral(double x, double y, double side) noexcept;

  private:
    Triangle(double x, double y, double first_side, double second_side, double third_side)
      : Shape(x, y)
      , first_side_(first_side)
      , second_side_(second_side)
      , third_side_(third_side) {}

    double first_side_;
    double second_side_;
    double third_side_;
};
}
