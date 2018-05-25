#pragma once
#include <vector>

namespace soft_renderer
{
  struct SVertex
  {
    int vertex_idx;
    int texture_idx;
  };

  class CFace
  {
    enum
    {
      None,
      Triangle,
      Rectangle
    } type = None;

    std::vector<SVertex> vertices;
  public:
    CFace(const std::vector<SVertex>& a_vertices) 
      : vertices(a_vertices) 
    {
      switch (vertices.size())
      {
      case 3: type = Triangle; break;
      case 4: type = Rectangle; break;
      default: type = None;
      }
    }

    CFace(
      SVertex v1,
      SVertex v2,
      SVertex v3
    )
      : type(Triangle)
    {
      vertices.push_back(v1);
      vertices.push_back(v2);
      vertices.push_back(v3);
    }

    CFace(
      SVertex v1,
      SVertex v2,
      SVertex v3,
      SVertex v4
    )
      : type(Rectangle)
    {
      vertices.push_back(v1);
      vertices.push_back(v2);
      vertices.push_back(v3);
      vertices.push_back(v4);
    }
  };
}