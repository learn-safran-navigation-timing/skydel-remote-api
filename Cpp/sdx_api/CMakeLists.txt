file(GLOB_RECURSE SDX_API_SRC ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_library(sdx_api ${SDX_API_SRC})

target_include_directories(sdx_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(sdx_api PRIVATE pch.h)

if(WIN32)
  target_compile_definitions(sdx_api PRIVATE GUID_WINDOWS=1)
  target_link_libraries(sdx_api PUBLIC Ole32 ws2_32)
  target_compile_options(sdx_api PRIVATE /wd4244 /wd4838 /wd4701)
else()
  target_compile_definitions(sdx_api PRIVATE GUID_LIBUUID=1)
  target_link_libraries(sdx_api PUBLIC uuid)
endif()
