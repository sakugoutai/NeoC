option(NEOC_BUILD_SHARED_LIBS "build NeoC as a shared library" OFF)

if (NEOC_BUILD_SHARED_LIBS)
    add_library(NeoC SHARED)
else()
    add_library(NeoC STATIC)
endif()

target_sources(NeoC
    PRIVATE

    Base/Object.c
    Base/Error.c
    Base/Memory.c
    Base/Exception/Signal.c
    Base/Exception/Exception.c
    Base/Defer.c
    Base/Environment.c

    SPEC/CC.c
    SPEC/CSI.c
    SPEC/SGR.c

    Type/String.c
    Type/Bit.c
    Type/Bool.c
    Type/Int32.c
    Type/UInt32.c

    Console.c
    System.c
    Socket.c

    Collection/Collection.c
    Collection/Tuple.c
    Collection/List.c
    Collection/Stack.c
    Collection/Queue.c
    Collection/Map.c

    #File/Directory.c
    #File/File.c
)

target_include_directories(NeoC
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

include(GNUInstallDirs)
install(TARGETS NeoC
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)
