#include <stdexcept>
#include <fmt/core.h>
#include <vulkan/vk_enum_string_helper.h>
#include <lr/vk10/rendering_server.hpp>

namespace Diamond::lr::vk10
{
    void Vk10RenderingServer::_initialize_instance()
    {
        constexpr VkInstanceCreateInfo create_info = {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = nullptr,
            .flags = 0,
            .pApplicationInfo = &APPLICATION_INFO,
            .enabledLayerCount = 0,
            .ppEnabledLayerNames = nullptr,
            .enabledExtensionCount = 0,
            .ppEnabledExtensionNames = nullptr,
        };
        VkResult result = vkCreateInstance(&create_info, nullptr, &m_instance);
        if (result != VK_SUCCESS)
            throw std::runtime_error(fmt::format("Failed to create instance, reason: {}", string_VkResult(result)));
    }

    void Vk10RenderingServer::_initialize_device()
    {
    }

    Vk10RenderingServer::Vk10RenderingServer()
    {
        _initialize_instance();
        _initialize_device();
    }

    Vk10RenderingServer::~Vk10RenderingServer()
    {
        if (m_instance)
            vkDestroyInstance(m_instance, nullptr);
    }

    const std::vector<std::shared_ptr<IPhysicalDevice>> &Vk10RenderingServer::get_physical_devices() const
    {
        return m_physical_devices;
    }

    IRenderingDevice *Vk10RenderingServer::get_default_device() const
    {
        return m_default_device.get();
    }

    IRenderingDevice *Vk10RenderingServer::create_device(const std::shared_ptr<IPhysicalDevice> &physical_device)
    {
        return nullptr;
    }

} // namespace Diamond::lr::vk10
