# Google Test
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings 
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

macro(add_bad_test testname)
	add_executable(
		${testname}_test	
		${testname}.cpp
	)
	target_link_libraries(
		${testname}_test
		PRIVATE
		GTest::gtest_main
		BadLinAlg	
	)

	gtest_discover_tests(${testname}_test)
endmacro()

# Add tests
add_bad_test(vector)
