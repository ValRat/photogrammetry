# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)


# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             native-lib.cpp
             )


# Set MVE library paths
#set(mve-libs "/home/valerian/Programming/Photogrammetry/mve/libs")
#add_library(mve-sfm STATIC IMPORTED)
#set_target_properties(mve-sfm PROPERTIES IMPORTED_LOCATION "${mve-libs}/sfm/libmve_sfm.a")
# message(STATUS "Linking from: ${mve-libs}/sfm/libmve_sfm.a")



# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )


# JPEG
set(jpeg_lib_src_DIR libjpeg)
add_subdirectory(${jpeg_lib_src_DIR})

# PNG library
#include(${CMAKE_CURRENT_SOURCE_DIR}/mve/CMakeLists.txt)
#include(${CMAKE_CURRENT_SOURCE_DIR}/libpng/CMakeLists.txt)
set(png_lib_src_DIR libpng)
#[[set(png_lib_build_DIR ./libpng/outputs)
file(MAKE_DIRECTORY ${png_lib_build_DIR})]]
add_subdirectory(${png_lib_src_DIR})
                 #${png_lib_build_DIR})

#add_library(png-lib STATIC IMPORTED)
#set_target_properties(png-lib PROPERTIES IMPORTED_LOCATION)
#message(STATUS "Imported pnglib from: ${png_lib_build_DIR}/${CMAKE_ANDROID_ARCH_ABI}/libpng.a")


# TIFF

# Seems like the TIFF library depends on JPEG and PNG libraries...
# how about that for dependency cycles

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       )
