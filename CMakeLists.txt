cmake_minimum_required(VERSION 3.10)
project(DtWordTrainer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
	main.cpp # main.cpp is not in a zone

	# RootZone
	RootZone/DtWordTrainer.cpp
	RootZone/MainScreen.cpp

	# QuestionZone
	QuestionZone/Logic/Question.cpp
	QuestionZone/Logic/MCFDLogic.cpp
	QuestionZone/Logic/TPDTWLogic.cpp
	QuestionZone/Logic/CHGNDLogic.cpp

	QuestionZone/GUI/QuestionOverseer.cpp
	QuestionZone/GUI/MCFDGui.cpp
	QuestionZone/GUI/TPDTWGui.cpp
	QuestionZone/GUI/CHGNDGui.cpp

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
	QuestionZone/Logic/Question.h
	QuestionZone/Logic/MCFDLogic.h
	QuestionZone/Logic/TPDTWLogic.h
	QuestionZone/Logic/CHGNDLogic.h

	QuestionZone/GUI/QuestionOverseer.h
	QuestionZone/GUI/MCFDGui.h
	QuestionZone/GUI/TPDTWGui.h
	QuestionZone/GUI/CHGNDGui.h

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
	QuestionZone/GUI/TPDTWGui.ui
	QuestionZone/GUI/CHGNDGui.ui
)

set(QRCS
	RootZone/DtWordTrainer.qrc
)

qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION
	${SOURCES}
	${HEADERS}
	${UIS}
	${QRCS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    QT_ANDROID_PACKAGE_NAME "com.caleb.DtWordTrainer"
    QT_ANDROID_TARGET_SDK_VERSION 34
    QT_ANDROID_VERSION_CODE 10
    QT_ANDROID_VERSION_NAME "1.0"
)

qt_finalize_executable(${PROJECT_NAME})
