file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(lr-vk10 ${SOURCE_FILES})
target_include_directories(lr-vk10 PUBLIC
    ${CMAKE_SOURCE_DIR}/third_party/vulkan-sdk/include
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(lr-vk10 PUBLIC
    ${CMAKE_SOURCE_DIR}/third_party/vulkan-sdk/bin/vulkan-1.dll
)