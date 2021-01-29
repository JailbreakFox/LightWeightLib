PROJECT(GSettings)

INSTALL(FILES com.deepin.test.gschema.xml
        DESTINATION /usr/share/glib-2.0/schemas/)

ADD_EXECUTABLE(GSettings main.cpp)
TARGET_LINK_LIBRARIES(GSettings ${GTK3_LIBRARIES})

