set(MAIN_FILES
        DataType_LongLong.cpp
        DataType_Char.cpp
        Test_Namespace.cpp
        Test_auto.cpp
        Test_typeid.cpp
        Test_decltype.cpp
        )

foreach (file ${MAIN_FILES})
    get_filename_component(fn ${file} NAME_WE)
    add_executable(${fn} ${file})
endforeach ()