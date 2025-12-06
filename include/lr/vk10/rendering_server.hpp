#pragma once

#include <vulkan/vulkan.h>
#include <lr/common/rendering_server.hpp>
#include <lr/vk10/rendering_device.hpp>

namespace Diamond::lr::vk10
{
    class Vk10RenderingServer : public IRenderingServer
    {
    public:
        static constexpr inline VkApplicationInfo APPLICATION_INFO = {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pNext = nullptr,
            .pApplicationName = "Lite Render",
            .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
            .pEngineName = "Lite Render - Vulkan 1.0",
            .engineVersion = VK_MAKE_VERSION(1, 0, 0),
            .apiVersion = VK_API_VERSION_1_0,
        };

    private:
        VkInstance m_instance = VK_NULL_HANDLE;
        std::unique_ptr<Vk10RenderingDevice> m_default_device = {};
        std::vector<std::shared_ptr<IPhysicalDevice>> m_physical_devices = {};

    private:
        void _initialize_instance();
        void _initialize_device();

    public:
        Vk10RenderingServer();
        ~Vk10RenderingServer();

    public:
        const std::vector<std::shared_ptr<IPhysicalDevice>> &get_physical_devices() const override;
        IRenderingDevice *get_default_device() const override;
        IRenderingDevice *create_device(const std::shared_ptr<IPhysicalDevice> &physical_device) override;
    };

} // namespace Diamond::lr::vk10
