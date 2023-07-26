#pragma once

#include <cstddef>
#include <cstdint>

namespace booba
{
    enum class EventType
    {
        NoEvent            = 0, // Stub. Should be ignored.
        MouseMoved         = 1, // Mouse moved over image.  Data structure: MotionEventData
        MousePressed       = 2, // Mouse pressed on image.  Data structure: MouseButtonEventData
        MouseReleased      = 3, // Mouse released on image. Data structure: MouseButtonEventData
        MouseWheelScrolled = 4,
        TextEvent          = 5, // Text changed event. Data structure - TextEventData.
    };

    enum class MouseButton
    {
        Left,
        Right
    };

    struct MotionEventData
    {
        size_t x, y;
        /**
         * @brief Relative to previous mouse position.
         */
        int64_t rel_x, rel_y;
    };

    struct MouseButtonEventData
    {
        size_t x, y;
        MouseButton button;
        /**
         * @brief If corresponding keys was pressed.
         */
        bool shift, alt, ctrl;
    };

    struct TextEventData
    {
        char letter;
    };


    /**
     * @brief booba::Event is used to transmit event inside plugin.
     */
    class Event
    {
    public:
        EventType type;
        union
        {
            MotionEventData motion;
            MouseButtonEventData mpedata;
            TextEventData tedata;
        } Oleg; //Object loading event group.
    };
}