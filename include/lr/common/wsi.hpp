#pragma once

namespace Diamond::lr
{
    class IWSI
    {
        IWSI(const IWSI &) = delete;
        IWSI &operator=(const IWSI &) = delete;

    public:
        IWSI() = default;
        virtual ~IWSI() = default;

    public:
        virtual void *get_window_handle() const = 0;
        virtual void destroy() = 0;
        virtual void present() = 0;
    };

} // namespace Diamond::lr
