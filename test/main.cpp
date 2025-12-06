#include <iostream>
#include <fmt/core.h>
#include <lr/vk10/rendering_server.hpp>
using namespace Diamond;

int main()
{
    fmt::println("Hello World!");
    std::unique_ptr<lr::IRenderingServer> server = std::make_unique<lr::vk10::Vk10RenderingServer>();
    return 0;
}
