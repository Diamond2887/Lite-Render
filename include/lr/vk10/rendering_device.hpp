#pragma once

#include <vulkan/vulkan.h>
#include <lr/common/rendering_device.hpp>

namespace Diamond::lr::vk10
{
    class Vk10RenderingDevice : public IRenderingDevice
    {
    private:
        VkDevice m_device = VK_NULL_HANDLE;

    public:
        ~Vk10RenderingDevice();

    public:
        void destroy() override;
    };

} // namespace Diamond::lr::vk10
