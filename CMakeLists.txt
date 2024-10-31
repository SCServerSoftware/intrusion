cmake_minimum_required(VERSION 3.10)
project(Intrusion)

# Add SoLoud
add_subdirectory(lib/soloud)

# Maybe Intrusion needs a strict include directory definition
target_include_directories(intrusion PRIVATE include)

# Add your source files
add_executable(intrusion
    main.cpp
)

# Link SoLoud with your project
target_link_libraries(intrusion PUBLIC soloud)

# Target the appropriate SoLoud backends per OS
if(WIN32)
    target_compile_definitions(intrusion PRIVATE WITH_WASAPI=1 WITH_WINMM=1)
elseif(APPLE)
    target_compile_definitions(intrusion PRIVATE WITH_COREAUDIO=1)
elseif(UNIX)
    target_compile_definitions(intrusion PRIVATE WITH_ALSA=1 WITH_PULSEAUDIO=1)
endif()

# Set C++ version
set_target_properties(intrusion PROPERTIES
    CXX_STANDARD 20 # I need the modules badly
    CXX_STANDARD_REQUIRED ON
)