# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Magazyn_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Magazyn_autogen.dir\\ParseCache.txt"
  "Magazyn_autogen"
  )
endif()
