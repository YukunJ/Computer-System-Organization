cmake_minimum_required(VERSION 3.0)
project(cso-hw04)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Og -Werror -std=c11")

execute_process (
  COMMAND bash -c "uname -s"
  OUTPUT_VARIABLE UNAME_S
)

if(UNAME_S EQUAL "Darwin" OR UNAME_S MATCHES "Darwin")
  set(OBJS objs-mac)
else()
  set(OBJS objs)
endif()

set(SOURCE_FILES ${OBJS}/tester.o src/ex1.c src/ex2.c src/ex3.c src/ex4.c src/ex5.c)
set(SOURCE_FILES_SOL ${OBJS}/tester.o ${OBJS}/ex1_sol.o ${OBJS}/ex2_sol.o ${OBJS}/ex3_sol.o ${OBJS}/ex4_sol.o ${OBJS}/ex5_sol.o)
add_executable(tester ${SOURCE_FILES})
add_executable(tester-sol ${SOURCE_FILES_SOL})
set_target_properties(tester-sol PROPERTIES LINKER_LANGUAGE C)