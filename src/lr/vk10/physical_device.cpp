#include <stdexcept>
#include <lr/vk10/physical_device.hpp>

namespace Diamond::lr::vk10
{
    void Vk10PhysicalDevice::_get_device_type()
    {
        switch (m_properties.deviceType)
        {
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            m_device_type = Type::Integrated;
            break;

        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            m_device_type = Type::Discrete;
            break;

        default:
            m_device_type = Type::Unknown;
            break;
        }
    }

    Vk10PhysicalDevice::Vk10PhysicalDevice(VkPhysicalDevice handle)
        : m_handle(handle)
    {
        if (!handle)
            throw std::runtime_error("Invalid VkPhysicalDevice handle");

        vkGetPhysicalDeviceProperties(handle, &m_properties);
        _get_device_type();
        m_device_name = m_properties.deviceName;
    }

    void *Vk10PhysicalDevice::get_native_handle() const { return m_handle; }
    IPhysicalDevice::Type Vk10PhysicalDevice::get_device_type() const { return m_device_type; }
    const std::string &Vk10PhysicalDevice::get_device_name() const { return m_device_name; }

} // namespace Diamond::lr::vk10
