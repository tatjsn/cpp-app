project(cool-cpp CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(/usr/local/Cellar/protobuf/3.11.3/include)
link_directories(/usr/local/Cellar/protobuf/3.11.3/lib)

add_executable(cool-cpp cool-cpp.cxx
  sensor.pb.cc sensor.pb.h
  foo.pb.cc foo.pb.h
  out/httplib.cc out/httplib.h)
target_link_libraries(cool-cpp ${CONAN_LIBS} protobuf)
set_target_properties(cool-cpp PROPERTIES CXX_STANDARD 17)