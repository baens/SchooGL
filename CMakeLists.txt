project(SchooGL)
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
INCLUDE(CPack)
ENABLE_TESTING()

##################################
#Dependices
##################################
INCLUDE(SetupDeps.cmake)
INCLUDE(FindGLUT.cmake)
IF(NOT GLUT_FOUND)
       MESSAGE(SEND_ERROR "GLUT not found!")
ENDIF(NOT GLUT_FOUND)
INCLUDE(FindOpenGL)
IF(NOT OPENGL_FOUND)
       MESSAGE(SEND_ERROR "OpenGL not found!")
ENDIF(NOT OPENGL_FOUND)
INCLUDE(FindMySQL.cmake)
##################################
#Variables
##############
SET(EXECUTABLE_OUTPUT_PATH ${SchooGL_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")
SET(LIBRARY_OUTPUT_PATH ${SchooGL_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")

##################################
#Enviorment Settings
##################################
LINK_LIBRARIES(${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${MYSQL_LIBRARIES})


INCLUDE_DIRECTORIES(${SchooGL_SOURCE_DIR}/src ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR} ${MYSQL_INCLUDE_DIR})

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tutorial)
ADD_SUBDIRECTORY(app)
ADD_SUBDIRECTORY(test)