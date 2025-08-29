#pragma once
#include <memory>
#include <array>
#include <random>

#include "Model/Block/IBlock.h"
#include "Model/Block/JBlock.h"
#include "Model/Block/LBlock.h"
#include "Model/Block/OBlock.h"
#include "Model/Block/SBlock.h"
#include "Model/Block/TBlock.h"
#include "Model/Block/ZBlock.h"

/**
 * @class BlockFactory
 * @brief Factory pattern để tạo các khối (Block) trong game Tetris.
 *
 * Lớp này lưu trữ các prototype (I, J, L, O, S, T, Z) và cung cấp
 * phương thức để tạo ra block theo ID hoặc ngẫu nhiên.
 */
class BlockFactory {
public:
    /**
     * @brief Khởi tạo BlockFactory và nạp các prototype block.
     */
    BlockFactory();

    /**
     * @brief Tạo block dựa theo ID.
     *
     * @param id Giá trị từ 0–6 (0: I, 1: J, 2: L, 3: O, 4: S, 5: T, 6: Z).
     * @return std::unique_ptr<Block> Con trỏ thông minh quản lý block mới tạo.
     * @throws std::out_of_range nếu ID không hợp lệ.
     * @throws std::runtime_error nếu việc clone thất bại.
     */
    std::unique_ptr<Block> CreateBlock(int id) const;

    /**
     * @brief Tạo block ngẫu nhiên (0–6).
     *
     * @return std::unique_ptr<Block> Con trỏ thông minh quản lý block ngẫu nhiên.
     */
    std::unique_ptr<Block> CreateRandomBlock() const;

private:
    /// Danh sách prototype cho 7 loại block
    std::array<std::unique_ptr<Block>, 7> _prototypes;

    /**
     * @brief Sinh ngẫu nhiên ID block từ 0–6.
     * @return int ID block.
     */
    int GenerateRandomId() const;
};
