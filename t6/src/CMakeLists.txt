#CMAKE_POLICY(SET CMP0016 NEW)
FIND_PACKAGE(HELLO REQUIRED)
IF (HELLO_FOUND)
    INCLUDE_DIRECTORIES(${HELLO_INCLUDE_DIR})
    ADD_EXECUTABLE(hello main.c)
    TARGET_LINK_LIBRARIES(hello ${HELLO_LIBRARY})
ENDIF(HELLO_FOUND)
