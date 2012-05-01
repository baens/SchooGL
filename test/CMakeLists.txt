ADD_EXECUTABLE(UserManagerTest UserManagerTest.cpp)
TARGET_LINK_LIBRARIES(UserManagerTest SchooGLSrc)
ADD_TEST(UserManagerTest ${EXECUTABLE_OUTPUT_PATH}/UserManagerTest)

ADD_EXECUTABLE(ProfileTest ProfileTest.cpp)
TARGET_LINK_LIBRARIES(ProfileTest SchooGLSrc)
ADD_TEST(ProfileTest ${EXECUTABLE_OUTPUT_PATH}/ProfileTest)

ADD_EXECUTABLE(LoginManagerTest LoginManagerTest.cpp)
TARGET_LINK_LIBRARIES(LoginManagerTest SchooGLSrc)
ADD_TEST(LoginMangerTest ${EXECUTABLE_OUTPUT_PATH}/LoginManagerTest)

ADD_EXECUTABLE(ColorTest ColorTest.cpp)
TARGET_LINK_LIBRARIES(ColorTest SchooGLSrc)
ADD_TEST(ColorTest ${EXECUTABLE_OUTPUT_PATH}/ColorTest)

ADD_EXECUTABLE(PointTest PointTest.cpp)
TARGET_LINK_LIBRARIES(PointTest SchooGLSrc)
ADD_TEST(PointTest ${EXECUTABLE_OUTPUT_PATH}/PointTest)