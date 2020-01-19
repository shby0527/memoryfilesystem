# check if already in cache, be silent
IF (PTHREAD_INCLUDE_DIR)
    SET (PTHREAD_FIND_QUIETLY TRUE)
ENDIF (PTHREAD_INCLUDE_DIR)

# find includes
FIND_PATH (PTHREAD_INCLUDE_DIR pthread.h
        /usr/local/include
        /usr/include
        )

# find lib
if (APPLE)
    SET(PTHREAD_NAMES libosxpthread.dylib pthread)
else (APPLE)
    SET(PTHREAD_NAMES pthread)
endif (APPLE)
FIND_LIBRARY(PTHREAD_LIBRARIES
        NAMES ${PTHREAD_NAMES}
        PATHS /lib64 /lib /usr/lib64 /usr/lib /usr/local/lib64 /usr/local/lib /usr/lib/x86_64-linux-gnu
        )

include ("FindPackageHandleStandardArgs")
find_package_handle_standard_args ("PTHREAD" DEFAULT_MSG
        PTHREAD_INCLUDE_DIR PTHREAD_LIBRARIES)

mark_as_advanced (PTHREAD_INCLUDE_DIR PTHREAD_LIBRARIES)