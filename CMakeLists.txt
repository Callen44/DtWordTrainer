cmake_minimum_required(VERSION 3.10)
project(DtWordTrainer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
	main.cpp # main.cpp is not in a zone

	# RootZone
	RootZone/DtWordTrainer.cpp
	RootZone/MainScreen.cpp

	# QuestionZone
	QuestionZone/Logic/MCFDLogic.cpp
	QuestionZone/Logic/TPDTWLogic.cpp
	QuestionZone/Logic/Question.cpp

	QuestionZone/GUI/GuiTemplate.h
	QuestionZone/GUI/MCFDGui.cpp
	QuestionZone/GUI/TPDTWGui.cpp
	QuestionZone/GUI/QuestionOverseer.cpp

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
	RootZone/MainScreen.h

	# QuestionZone
	QuestionZone/Logic/MCFDLogic.h
	QuestionZone/Logic/TPDTWLogic.h
	QuestionZone/Logic/Question.h

	QuestionZone/GUI/GuiTemplate.h
	QuestionZone/GUI/MCFDGui.h
	QuestionZone/GUI/TPDTWGui.h
	QuestionZone/GUI/QuestionOverseer.h

	# DataZone
	DataZone/Noun.h
	DataZone/Verb.h
	DataZone/Word.h
	DataZone/Wordset.h
	DataZone/Algorithm.h
)

set(UIS
	RootZone/MainScreen.ui
	QuestionZone/GUI/MCFDGui.ui
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
