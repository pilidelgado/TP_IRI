TEMPLATE = lib
DEFINES += LIBRERIA_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abrirArchivos.cpp \
    asistencias_copy.cpp \
    gimnasio.cpp \

HEADERS += \
    abrirArchivos.h \
    asistencias_copy.h \
    gimnasio.h \
    libreria.h \
    libreria_global.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
