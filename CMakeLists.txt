cmake_minimum_required(VERSION 3.9)
project(curves)
add_library(curves SHARED
            point.cpp
            vect.cpp
            curve.cpp
            ellipse.cpp
            circle.cpp
            helix.cpp)
include_directories(include)
add_executable(main
  main.cpp
  point.cpp
  vect.cpp
  curve.cpp
  ellipse.cpp
  circle.cpp
  helix.cpp
  point.h
  vect.h
  curve.h
  ellipse.h
  circle.h
  helix.h
  exception.h
)
