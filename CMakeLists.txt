cmake_minimum_required(VERSION 2.6)
project(wxexperimental)

add_subdirectory(frames)

set(SOURCE
    ${SOURCE}
    myapp.cpp
  )
  
add_executable(wxexperimental ${SOURCE} ${HEADERS})

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})
# and for each of your dependent executable/library targets:
target_link_libraries(wxexperimental ${wxWidgets_LIBRARIES})

install(TARGETS wxexperimental RUNTIME DESTINATION bin)