#pragma once

#include <vector>
#include <memory>
#include <lr/common/wsi.hpp>
#include <lr/common/physical_device.hpp>
#include <lr/common/rendering_device.hpp>

namespace Diamond::lr
{
    class IRenderingServer
    {
        IRenderingServer(const IRenderingServer &) = delete;
        IRenderingServer &operator=(const IRenderingServer &) = delete;

    public:
        IRenderingServer() = default;
        virtual ~IRenderingServer() = default;

    public:
        virtual const std::vector<std::shared_ptr<IPhysicalDevice>> &get_physical_devices() const = 0;
        virtual IRenderingDevice *get_default_device() const = 0;
        virtual IRenderingDevice *create_device(const std::shared_ptr<IPhysicalDevice> &physical_device) = 0;
    };

} // namespace Diamond::lr
