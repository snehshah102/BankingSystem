add_subdirectory(include)
add_executable(BankingSystem main.cpp Account.cpp Transaction.cpp User.cpp FileIO.cpp)
target_include_directories(BankingSystem PRIVATE ${CMAKE_SOURCE_DIR}/src)
