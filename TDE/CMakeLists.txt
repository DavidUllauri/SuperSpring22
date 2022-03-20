add_library(TDE SHARED TDE.h TDE TDEUtil.h TDEApp.cpp)

add_definitions(-DTDE_LIB)
add_definitions(-DTDE_DEBUG)

target_precompile_headers(TDE PRIVATE pch.h)