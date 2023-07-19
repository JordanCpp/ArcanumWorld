add_executable(ArchiveReader "ArchiveReader.cpp")
target_link_libraries(ArchiveReader ArcanumLib)

add_executable(DatList "DatList.cpp")
target_link_libraries(DatList ArcanumLib)

add_executable(DatItem "DatItem.cpp")
target_link_libraries(DatItem ArcanumLib)