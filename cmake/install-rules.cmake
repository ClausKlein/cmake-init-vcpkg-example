install(
    TARGETS vcpkg-example_exe
    RUNTIME COMPONENT vcpkg-example_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  set(CPACK_GENERATOR TGZ)
  include(CPack)
endif()
