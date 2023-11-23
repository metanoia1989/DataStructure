add_rules("mode.debug", "mode.release")

target('bst')
    set_kind("binary")
    set_languages("c++11")
    add_includedirs(".")
    add_files( "BinarySearchTree.cpp", "BinarySearchTreeTest.cpp")