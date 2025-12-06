#pragma once

#include <vulkan/vulkan.h>
#include <lr/common/physical_device.hpp>

namespace Diamond::lr::vk10
{
    class Vk10PhysicalDevice : public IPhysicalDevice
    {
    private:
        VkPhysicalDevice m_handle = VK_NULL_HANDLE;
        VkPhysicalDeviceProperties m_properties = {};
        Type m_device_type = Type::Unknown;
        std::string m_device_name = {};

    public:
        void _get_device_type();

    public:
        Vk10PhysicalDevice(VkPhysicalDevice handle);

    public:
        void *get_native_handle() const override;
        Type get_device_type() const override;
        const std::string &get_device_name() const override;
    };

} // namespace Diamond::lr::vk10
