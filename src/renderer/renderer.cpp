#include "renderer.h"
#include "model.h"
#include <iostream>

using namespace std;

namespace soft_renderer
{
  void CRenderer::parse_arguments(int argc, char** argv)
  {
    for (int i = 0; i < argc; i++)
    {
      if (strcmp(argv[i], "-m") == 0)
      {
        if (i + 1 < argc)
          model_name = argv[i + 1];
      }
      else if (strcmp(argv[i], "-t") == 0)
      {
        if (i + 1 < argc)
          texture_name = argv[i + 1];
      }
    }
  }

  void CRenderer::print()
  {
    cout << "model: " << model_name << endl;
    cout << "texture: " << texture_name << endl;
  }

  void CRenderer::load()
  {
    CModel(model_name, texture_name);
  }
}