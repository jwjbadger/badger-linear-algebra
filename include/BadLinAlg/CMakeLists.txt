add_library(BadLinAlg INTERFACE)

target_include_directories(BadLinAlg
	INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

if(INSTALL_BAD_LIBRARY)
	install(TARGETS BadLinAlg 
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

	include(CMakePackageConfigHelpers)
	write_basic_package_version_file("${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    	VERSION ${PROJECT_VERSION}
		COMPATIBILITY SameMajorVersion)

	configure_package_config_file(
  		"${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  		"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  		INSTALL_DESTINATION
  		${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

	install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

	install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
	
	include(GNUInstallDirs)
	install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/BadLinAlg 
		DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()
