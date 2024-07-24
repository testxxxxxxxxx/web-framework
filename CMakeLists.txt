cmake_minimum_required(VERSION 2.8.12)

project(app)

file(GLOB MAIN_APP_SRC

    "./include/*.hpp"
    "./src/*.cpp"

)

include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)

link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})

set(CURLIBRARY "-lcurl")
find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})

add_executable(app ${MAIN_APP_SRC})

target_include_directories(app PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(app PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})
target_link_libraries(app PRIVATE ${CURL_LIBRARIES})

install(TARGETS app DESTINATION bin)
install(FILES ${MAIN_APP_SRC} DESTINATION src)