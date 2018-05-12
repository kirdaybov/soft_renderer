#pragma once

namespace soft_renderer
{
  class CPoint
  {
    float x = 0;
    float y = 0;
    float z = 0;

  public:
    CPoint(
      float a_x = 0, 
      float a_y = 0, 
      float a_z = 0
    )
      : x(a_x)
      , y(a_y)
      , z(a_z)
    {}

    inline float get_x() const { return x; }
    inline float get_y() const { return y; }
    inline float get_z() const { return z; }
  };
}