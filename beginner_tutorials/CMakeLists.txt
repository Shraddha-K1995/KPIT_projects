cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


## Generate messages in the 'msg' folder
add_message_files(DIRECTORY msg FILES Num.msg)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(

CATKIN_DEPENDS message_runtime

)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
#add_library(${PROJECT_NAME}
#src/${PROJECT_NAME}/beginner_tutorials.cpp
#)


## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

###########ADD DEPENDENCIES ################
add_executable(EvenNumberGenerator src/Publisher1.cpp)
target_link_libraries(EvenNumberGenerator ${catkin_LIBRARIES})
add_dependencies(EvenNumberGenerator beginner_tutorials_generate_messages_cpp)

add_executable(OddNumberGenerator src/Publisher2.cpp)
target_link_libraries(OddNumberGenerator ${catkin_LIBRARIES})
add_dependencies(OddNumberGenerator beginner_tutorials_generate_messages_cpp)

add_executable(DisplayAddition src/Subscriber.cpp)
target_link_libraries(DisplayAddition ${catkin_LIBRARIES})
add_dependencies(DisplayAddition beginner_tutorials_generate_messages_cpp)
