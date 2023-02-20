add_library(BadLinAlg INTERFACE)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)
target_include_directories(BadLinAlg
	INTERFACE
	${CMAKE_CURRENT_LIST_DIR}
)	
set(CMAKE_CXX_FLAGS, "-m64")
