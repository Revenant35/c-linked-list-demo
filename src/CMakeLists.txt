# Create a static library for the linked list implementations
add_library(linked_list STATIC
    singly-linked-list.c
    doubly-linked-list.c
)

# Make the include directory available to targets that link this library
target_include_directories(linked_list PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

# Create the main executable
add_executable(c_linked_list_demo main.c)

# Link the executable against the library
target_link_libraries(c_linked_list_demo PRIVATE linked_list)