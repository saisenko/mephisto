# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\mephisto_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\mephisto_autogen.dir\\ParseCache.txt"
  "mephisto_autogen"
  )
endif()
