#pragma once

#include "point.h"
#include "point2d.h"
#include "face.h"
#include <vector>

namespace soft_renderer
{
  class CModel
  { 
    std::vector<CPoint> vertices;
    std::vector<CPoint2D> texture_coords;
    std::vector<CFace> faces;

    void load_obj(const char* model_name, const char* texture_name);

  public:
    CModel(const char* model_name, const char* texture_name);
  };
}