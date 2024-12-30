cmake_minimum_required(VERSION 3.16)

project(mephisto VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui

        include/risc/InstructionFactory.h

        include/risc/memory/Registers.h
        src/risc/memory/Registers.cpp
        include/risc/memory/Memory.h
        src/risc/memory/Memory.cpp

        include/risc/instructions/Instruction.h
        include/risc/instructions/RTypeInstruction.h
        include/risc/instructions/ITypeInstruction.h

        include/risc/instructions/r_type/Add.h
        include/risc/instructions/r_type/Slt.h
        include/risc/instructions/r_type/Sub.h
        include/risc/instructions/r_type/And.h
        include/risc/instructions/r_type/Or.h
        include/risc/instructions/r_type/Xor.h
        include/risc/instructions/r_type/Sll.h
        include/risc/instructions/r_type/Srl.h

        include/risc/instructions/i_type/Addi.h
        include/risc/instructions/i_type/Slti.h
        include/risc/instructions/i_type/Andi.h
        include/risc/instructions/i_type/Ori.h
        include/risc/instructions/i_type/Xori.h
        include/risc/instructions/i_type/Slli.h
        include/risc/instructions/i_type/Srli.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(mephisto
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET mephisto APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(mephisto SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(mephisto
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(mephisto PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.mephisto)
endif()
set_target_properties(mephisto PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS mephisto
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(mephisto)
endif()
