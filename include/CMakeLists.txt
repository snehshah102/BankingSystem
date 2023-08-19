add_library(BankingLib Account.cpp Transaction.cpp User.cpp FileIO.cpp)
target_include_directories(BankingLib PUBLIC ${CMAKE_SOURCE_DIR}/src)
