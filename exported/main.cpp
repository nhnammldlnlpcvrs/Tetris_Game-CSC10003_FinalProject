/**
 * @file main.cpp
 * @brief Điểm khởi đầu của chương trình – chỉ gọi App::Run().
 */

#include "../resource/App/App.h"

int main() {
    App app;
    app.Run();
    return 0;
}
/*

g++ -std=c++17 -I./ \
  ./main.cpp \
  $(find . -name "*.cpp" ! -name "main.cpp") \
  -o tetris \
  -lraylib \
  -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

  
*/