| Rule                                                | Mô tả                                                                                    |
| --------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| **P.1 – Express intent**                            | Tên hàm, biến, class phải rõ nghĩa. Không viết tắt gây khó hiểu.                         |
| **NL.1 – Use a consistent naming style**            | Dùng camelCase cho biến/hàm, PascalCase cho class, viết thường\_snake\_case cho file.    |
| **F.21 – Use `return` to return values**            | Không dùng tham chiếu output (`void GetX(int& x)`), hãy dùng `int GetX()`.               |
| **R.3 – Use RAII**                                  | Quản lý bộ nhớ bằng `std::vector`, `std::unique_ptr`, không dùng `new/delete` trực tiếp. |
| **ES.20 – Always initialize**                       | Luôn khởi tạo giá trị ban đầu cho biến.                                                  |
| **E.2 – Avoid magic constants**                     | Đặt tên cho các số hằng (`constexpr int TileSize = 32;`).                                |
| **F.42 – Prefer `nullptr`**                         | Dùng `nullptr` thay cho `0` hoặc `NULL`.                                                 |
| **C.129 – Avoid macros**                            | Không dùng `#define`, hãy dùng `constexpr` hoặc `enum class`.                            |
| **C.2 – Use `class` for logic, `struct` for data**  | Nếu có hàm và ràng buộc, dùng `class`; nếu chỉ chứa dữ liệu, dùng `struct`.              |
| **I.1 – Make interfaces explicit**                  | Nếu là interface (lớp trừu tượng), chỉ nên khai báo thuần ảo.                            |
| **C.35 – Base class needs virtual destructor**      | Nếu class có kế thừa, cần `virtual ~Base() = default;`.                                  |
| **I.11 – Never transfer ownership via raw pointer** | Không dùng `Block*`; dùng `std::unique_ptr<Block>`.                                      |


source/
├── app/        # Controller: luồng chính, điều khiển game
├── core/       # Model: logic game, xử lý khối, va chạm, điểm
├── data/       # View: vẽ block, màn hình, font, màu sắc
├── test/       # Unit tests với Catch2
