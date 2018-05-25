#include "model.h"
#include <fstream>
#include <string>
#include <iterator>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace soft_renderer
{
  class CObjModelParser
  {
  public:
    CObjModelParser(CModel& Model, const char* model_name)
    {
      std::ifstream model_file;
      model_file.open(model_name, std::ios::in);
      if (model_file.is_open())
      {
        for (std::string line; std::getline(model_file, line); )
        {
          if (line[0] == '#')
            continue;

          std::stringstream ss(line);
          std::string token;
          if (std::getline(ss, token, ' '))
          {
            if (generic_parse<&CObjModelParser::parse_v >(token, "v" , ss)) continue; else
            if (generic_parse<&CObjModelParser::parse_vt>(token, "vt", ss)) continue; else
            if (generic_parse<&CObjModelParser::parse_vn>(token, "vn", ss)) continue; else
            if (generic_parse<&CObjModelParser::parse_vp>(token, "vp", ss)) continue; else
            if (generic_parse<&CObjModelParser::parse_f >(token, "f" , ss)) continue; else
            if (generic_parse<&CObjModelParser::parse_g >(token, "g" , ss)) continue; else
            if (generic_parse<&CObjModelParser::parse_o >(token, "o" , ss)) continue; else
              std::cout << "Couldn't parse string: " << line;
          }
        }
        model_file.close();
      }
      else
        std::cout << "Couldn't open model: " << model_name;

      print();
    }

    void print() const
    {
      std::cout << std::endl << "vertices count: " << vertices.size();
      std::cout << std::endl << "texture idx count: " << texture_coords.size();
      std::cout << std::endl << "faces count: " << faces.size();
    }

  private:
    typedef void(CObjModelParser::*TParseFunc)(std::stringstream& token);
    template<TParseFunc func>
    bool generic_parse(const std::string& token, const char* code, std::stringstream& ss)
    { 
      if (token.compare(code) == 0)
      {
        (this->*func)(ss);
        return true;
      }
      else
        return false;
    }

    void parse_v (std::stringstream& ss);
    void parse_vt(std::stringstream& ss);
    void parse_vn(std::stringstream& ss) {}
    void parse_vp(std::stringstream& ss) {}
    void parse_f (std::stringstream& ss);
    void parse_g (std::stringstream& ss) {}
    void parse_o (std::stringstream& ss) {}

    std::vector<CPoint> vertices;
    std::vector<CPoint2D> texture_coords;
    std::vector<CFace> faces;
  };

  void CObjModelParser::parse_v(std::stringstream& ss)
  {
    float x, y, z;
    ss >> x >> y >> z;
    vertices.push_back(CPoint(x, y, z));
  }

  void CObjModelParser::parse_vt(std::stringstream& ss)
  {
    float u, v;
    ss >> u >> v;
    texture_coords.push_back(CPoint2D(u, v));
  }

  void CObjModelParser::parse_f(std::stringstream& ss)
  {
    std::vector<SVertex> face_vertices;
    std::string vertex_string;
    while (std::getline(ss, vertex_string, ' '))
    {
      int vertex_idx, texture_idx;
      std::stringstream ss_vertex_string(vertex_string);
      char skip;
      ss_vertex_string >> vertex_idx >> skip >> texture_idx;
      face_vertices.push_back({ vertex_idx, texture_idx });
    }
    faces.push_back(CFace(face_vertices));
  }

  CModel::CModel(const char* model_name, const char* texture_name)
  {
    load_obj(model_name, texture_name);
  }

  void CModel::load_obj(const char* model_name, const char* texture_name)
  {
    CObjModelParser(*this, model_name);
  }
}