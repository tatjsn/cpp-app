project(app CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
include_directories(/usr/local/Cellar/protobuf/3.11.3/include)
link_directories(/usr/local/Cellar/protobuf/3.11.3/lib)

add_executable(app
  app.cc
  db-impl.cc
  out/foo.pb.cc
  out/foo-dto.pb.cc
  out/httplib.cc)
target_link_libraries(app ${CONAN_LIBS} protobuf)
set_target_properties(app PROPERTIES CXX_STANDARD 17)