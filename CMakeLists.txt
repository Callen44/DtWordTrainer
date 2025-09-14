cmake_minimum_required(VERSION 3.10)
project(DtWordTrainer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(SOURCES
	main.cpp # main.cpp is not in a zone

	# RootZone
	RootZone/DtWordTrainer.cpp

	# DataZone
	DataZone/Noun.cpp
	DataZone/Verb.cpp
	DataZone/Word.cpp
	DataZone/Wordset.cpp
	DataZone/Algorithm.cpp
)

set(HEADERS
	# RootZone
	RootZone/DtWordTrainer.h

	# DataZone
	DataZone/Noun.h
	DataZone/Verb.h
	DataZone/Word.h
	DataZone/Wordset.h
	DataZone/Algorithm.h
)

set(UIS
	RootZone/DtWordTrainer.ui
)

set(QRCS
	RootZone/DtWordTrainer.qrc
)

add_executable(${PROJECT_NAME}
	${SOURCES}
	${HEADERS}
	${UIS}
	${QRCS}
)

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
