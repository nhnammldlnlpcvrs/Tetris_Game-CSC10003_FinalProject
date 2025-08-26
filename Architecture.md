# 📊 Report: MVC Architecture in Tetris Project

## 1. Model (Quản lý dữ liệu & logic game)
**Các lớp liên quan:**
- `Block` (abstract) và các Tetromino con: `IBlock`, `JBlock`, `TBlock`, `ZBlock`, `OBlock`, `LBlock`, `SBlock`
- `Grid` (lưới game)
- `BlockMemento`, `BlockHistory` (Undo/Redo)
- `GameLogicService` (quy tắc di chuyển, xóa line, kiểm tra game over)
- `ScoreService` (quản lý điểm & best score)
- `AudioService` (âm thanh, nhạc nền)

👉 Đây là phần **“trái tim”** của game, chứa toàn bộ trạng thái và luật chơi, **không phụ thuộc vào giao diện**.

---

## 2. View (Hiển thị dữ liệu cho người chơi)
**Các lớp liên quan:**
- `BlockView` (render khối)
- `GridRenderer` (vẽ lưới)
- `Guide` (hướng dẫn chơi)
- `Color`, `Position` (dữ liệu hỗ trợ vẽ)

👉 View chỉ biết **“vẽ”** theo trạng thái Model, **không xử lý logic game**.

---

## 3. Controller (Điều khiển, xử lý input & kết nối Model ↔ View)
**Các lớp liên quan:**
- `App` (khởi động game, vòng lặp chính)
- `GameController` (điều khiển toàn bộ trò chơi: spawn block, update, draw, reset)
- `BlockController` (điều khiển khối hiện tại: move, rotate, undo/redo)

👉 Controller nhận **input từ người chơi (bàn phím)**, gọi logic từ **Model** (`GameLogicService`, `Block`, `Grid`) rồi yêu cầu **View** (`BlockView`, `GridRenderer`) hiển thị.

---

## 🔗 Cách các lớp phối hợp trong MVC
1. Người chơi **nhấn phím** → `BlockController` hoặc `GameController` xử lý input.  
2. Controller gọi **Model** (`Block`, `Grid`, `GameLogicService`, …) để cập nhật trạng thái.  
3. Controller gọi **View** (`BlockView`, `GridRenderer`) để **vẽ lại màn hình**.  

---

## ✨ Ưu điểm khi áp dụng MVC
- **Tách biệt rõ ràng** giữa logic, hiển thị, và điều khiển → dễ bảo trì, mở rộng.  
- **Dễ kiểm thử (unit test)** vì Model không phụ thuộc vào View.  
- **Dễ mở rộng** (ví dụ thêm hiệu ứng đồ họa mới chỉ cần thay View, không đụng đến logic).  
- **Kết hợp tốt với design patterns**: Prototype, Factory, Memento, … đều được nhúng vào Model/Controller mà không phá vỡ kiến trúc.  
