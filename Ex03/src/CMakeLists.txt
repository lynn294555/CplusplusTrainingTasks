#include_directories(${PROJECT_SOURCE_DIR}/lib})#连接目录
#set(library_output_path ${project_source_dir}/lib})
#link_directories(${PROJECT_SOURCE_DIR}/lib})
#add_library(libex01 ex_01.cpp)
add_executable(test test.cpp )
target_link_libraries(test libex01)

