#pragma once

namespace soft_renderer
{
  class CRenderer
  {
    char* model_name = "";
    char* texture_name = "";

  public:
    void parse_arguments(int argc, char** argv);
    void print();
    void load();
  };
}