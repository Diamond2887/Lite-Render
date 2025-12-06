#pragma once

namespace Diamond::lr
{
    class IRenderingDevice
    {
        IRenderingDevice(const IRenderingDevice &) = delete;
        IRenderingDevice &operator=(const IRenderingDevice &) = delete;

    public:
        IRenderingDevice() = default;
        virtual ~IRenderingDevice() = default;

    public:
        virtual void destroy() = 0;
    };

} // namespace Diamond::lr
