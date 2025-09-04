cmake_minimum_required(VERSION 3.10)
project(DtWordTrainer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(SOURCES
	main.cpp
	DtWordTrainer.cpp
	Noun.cpp
	Verb.cpp
	Word.cpp
	Wordset.cpp
)

set(HEADERS
	DtWordTrainer.h
	Noun.h
	Verb.h
	Word.h
)

set(UIS
	DtWordTrainer.ui
	Widget.ui
)

set(QRCS
	DtWordTrainer.qrc
)

add_executable(${PROJECT_NAME}
	${SOURCES}
	${HEADERS}
	${UIS}
	${QRCS}
)

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
