#pragma once

namespace soft_renderer
{
  class CPoint2D
  {
    float x = 0;
    float y = 0;

  public:
    CPoint2D(
      float a_x = 0, 
      float a_y = 0
    )
      : x(a_x)
      , y(a_y)
    {}

    inline float get_x() const { return x; }
    inline float get_y() const { return y; }
  };
}