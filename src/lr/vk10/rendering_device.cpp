#include <lr/vk10/rendering_device.hpp>

namespace Diamond::lr::vk10
{
    Vk10RenderingDevice::~Vk10RenderingDevice() { destroy(); }

    void Vk10RenderingDevice::destroy()
    {
        if (m_device)
            vkDestroyDevice(m_device, nullptr);
    }

} // namespace Diamond::lr::vk10
