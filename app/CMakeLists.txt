ADD_EXECUTABLE(SchooGLExe SchooGLExe)
TARGET_LINK_LIBRARIES(SchooGLExe SchooGLSrc)

INSTALL(TARGETS SchooGLExe RUNTIME DESTINATION .)
FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/../data/character/*.bmp")
INSTALL(FILES ${files} DESTINATION data/character)
FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/../data/monster/*.bmp")
INSTALL(FILES ${files} DESTINATION data/monster)
