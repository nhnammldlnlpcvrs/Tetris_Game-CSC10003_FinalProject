#pragma once
#include "raylib.h"

/**
 * @file guide.h
 * @brief Khai báo hàm vẽ hướng dẫn cho người chơi.
 *
 * Module này phụ trách hiển thị các hướng dẫn hoặc chú thích trên giao diện trò chơi Tetris.
 */

/**
 * @brief Vẽ khung hướng dẫn chơi game lên màn hình.
 *
 * Hàm này vẽ một hộp bán trong suốt chứa các dòng hướng dẫn điều khiển.
 *
 * @param font   Font chữ để hiển thị văn bản.
 * @param x      Tọa độ X của khung hướng dẫn.
 * @param y      Tọa độ Y của khung hướng dẫn.
 * @param width  Chiều rộng của khung hướng dẫn.
 */
void DrawGuide(const Font& font, float x, float y, float width);
