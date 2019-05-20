
# 这里生成的动态库和静态库名字是不同的
add_library(dm06_library_a library.c)
add_library(dm06_library_so SHARED library.c)

# 因此 target_link_libraries(dm06_library_so_main dm06_library_so) 链接动态库是没有问题的
add_executable(dm06_library_so_main main.c)
target_link_libraries(dm06_library_so_main dm06_library_so)

# target_link_libraries(dm06_library_a_main dm06_library_a) 链接静态库也是没有问题的
add_executable(dm06_library_a_main main.c)
target_link_libraries(dm06_library_a_main dm06_library_a)

# 但是如果动态库和静态库的名字相同呢
