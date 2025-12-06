#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>
#include <lr/common/wsi.hpp>

namespace Diamond::lr::vk10
{
    class Vk10WSI : public IWSI
    {
    private:
        VkSurfaceKHR m_surface = VK_NULL_HANDLE;
        VkSwapchainKHR m_swapchain = VK_NULL_HANDLE;
    };

} // namespace Diamond::lr::vk10
