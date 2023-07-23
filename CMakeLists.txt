if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

#Install LDL
set(LDL_STATIC_LIBRARY true)
add_definitions(-DLDL_STATIC_LIBRARY)
add_subdirectory(dependencies/LDL)
include_directories(dependencies/LDL/include)
link_directories (${CMAKE_CURRENT_BINARY_DIR}/dependencies/LDL)

#Install zlib
add_subdirectory(dependencies/zlib)
include_directories(dependencies/zlib)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/dependencies/zlib)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/dependencies/zlib)

include_directories("include")

file(GLOB_RECURSE SOURCE_FILES "source/Shared/*.cpp")

add_library(ArcanumLib STATIC ${SOURCE_FILES})

target_link_libraries(ArcanumLib LDL zlibstatic)

add_executable(ArcanumWorld "source/ArcanumWorld.cpp")
target_link_libraries(ArcanumWorld ArcanumLib)

add_executable(GenMap "source/GenMap.cpp")
target_link_libraries(GenMap ArcanumLib)

add_subdirectory("test")