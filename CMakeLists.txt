cmake_minimum_required(VERSION 3.27)
project(mockCliv3)

set(CMAKE_CXX_STANDARD 17)

add_executable(mockCliv3 main.cpp
        include/InputHandler.h
        src/inputHandler.cpp
        include/Parser.h
        src/parser.cpp
        include/ICommand.h
        include/ErrorHandler.h
        src/errorhandler.cpp
        include/Commands/Echo.h
        src/commands/echo.cpp
        src/fileManipulation.cpp
        src/functions.cpp
        include/Functions.h
        include/Commands/Touch.h
        src/commands/touch.cpp
        src/commands/time.cpp
        src/commands/wc.cpp
        include/Commands/Date.h
        src/commands/date.cpp
        src/commands/head.cpp
        src/commands/prompt.cpp
        src/commands/rm.cpp
        src/commands/truncate.cpp
        src/commands/batch.cpp
        include/Commands/Tr.h
        src/commands/tr.cpp
        include/CmdExecutor.h
        src/cmdexecutor.cpp
        include/AllCommands.h
        include/ErrorTypes.h)
