find_package(Doxygen)
if (DOXYGEN_FOUND)
	set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR}/include/BadLinAlg)
	set(DOXYGEN_BAD_README ${PROJECT_SOURCE_DIR}/README.md)

	set(DOXYGEN_IN ${CMAKE_CURRENT_LIST_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
