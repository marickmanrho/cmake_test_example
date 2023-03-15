# specify the C++ standard
add_library(NISE_compiler_flags INTERFACE)
target_compile_features(NISE_compiler_flags INTERFACE cxx_std_11)

# Create helper variables to determine which compiler we are using:
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# Add warning flag compile options to the interface library
target_compile_options(NISE_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-W3>"
)

# build-tree
target_compile_options(NISE_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# should we use our own math functions
option(USE_MYMATH "Use NISE provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/NISEConfig.h.in"
  "${PROJECT_BINARY_DIR}/NISEConfig.h"
  )

# add the MathFunctions library
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

# add the executable
add_executable(NISE NISE.cxx)
target_link_libraries(NISE PUBLIC ${EXTRA_LIBS} NISE_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find NISEConfig.h
target_include_directories(NISE PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
