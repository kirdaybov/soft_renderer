#include "renderer/renderer.h"

/**
  * Usage: soft_renderer -m path_to_model -t path_to_texture
  */
int main(int argc, char** argv)
{
  soft_renderer::CRenderer r;
  r.parse_arguments(argc, argv);
  r.print();
}