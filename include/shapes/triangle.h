#include "../shape.h"
#include <optional>
// #include <stdexcept>

namespace renderer {
class Triangle : public Shape {
  public:
    // Triangle(double x, double y, double first_side, double second_side, double third_side)
    //   : Shape(x, y)
    //   , first_side_(first_side)
    //   , second_side_(second_side)
    //   , third_side_(third_side)
    //   {
    //     if (!(first_side < second_side + third_side
    //           && second_side < first_side + third_side
    //           && third_side < first_side + second_side))
    //       throw std::invalid_argument("Несоблюдение неравенства треугольника");
    //   }

    void draw() override;

    double first_side()  const { return first_side_;  }
    double second_side() const { return second_side_; }
    double third_side()  const { return third_side_;  }

    static std::optional<Triangle> create(double x, double y, double AB, double BC, double AC);
    static std::optional<Triangle> make_isosceles(double x, double y, double side, double foundation);
    static std::optional<Triangle> make_equilateral(double x, double y, double side);

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
