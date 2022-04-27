add_executable(main main.cpp)
# target_link_libraries(main PUBLIC easy medium hard)
target_include_directories(main PUBLIC ${EASY_PATH} ${MEDIUM_PATH} ${HARD_PATH})