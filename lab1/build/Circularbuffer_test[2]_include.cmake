if(EXISTS "/Users/trisha/Desktop/nsu/oop/oop_git/lab1/build/Circularbuffer_test[2]_tests.cmake")
  include("/Users/trisha/Desktop/nsu/oop/oop_git/lab1/build/Circularbuffer_test[2]_tests.cmake")
else()
  add_test(Circularbuffer_test_NOT_BUILT Circularbuffer_test_NOT_BUILT)
endif()
