target_sources(${TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/interrupts.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logic.cpp
)

target_include_directories(${TARGET} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(dologic)
