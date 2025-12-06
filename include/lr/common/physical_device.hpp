#pragma once

#include <cstdint>
#include <string>

namespace Diamond::lr
{
    class IPhysicalDevice
    {
        IPhysicalDevice(const IPhysicalDevice &) = delete;
        IPhysicalDevice &operator=(const IPhysicalDevice &) = delete;

    public:
        enum class Type : std::uint32_t
        {
            Unknown,
            Integrated,
            Discrete,
        };

    public:
        IPhysicalDevice() = default;
        virtual ~IPhysicalDevice() = default;

    public:
        virtual void *get_native_handle() const = 0;
        virtual Type get_device_type() const = 0;
        virtual const std::string &get_device_name() const = 0;
    };

} // namespace Diamond::lr
