include_directories(${CMAKE_SOURCE_DIR}/src)
link_directories(${CMAKE_SOURCE_DIR}/src)

add_library(transport Bus.hpp Bus.cpp BusLine.hpp BusLine.cpp BusStop.hpp Cell.hpp Iterator.hpp Kernel.cpp Kernel.hpp Node.hpp Transport.hpp Transport.cpp
        SubwayLine.cpp SubwayLine.hpp List.hpp main.cpp State.cpp State.hpp Station.hpp Train.cpp Train.hpp Way.hpp)

target_link_libraries(transport)

add_executable(main main.cpp)

target_link_libraries(main transport)

