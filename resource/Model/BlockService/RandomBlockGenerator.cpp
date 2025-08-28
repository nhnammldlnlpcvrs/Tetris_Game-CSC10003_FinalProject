#include "RandomBlockGenerator.h"
#include "Model/Block/IBlock.h"
#include "Model/Block/JBlock.h"
#include "Model/Block/LBlock.h"
#include "Model/Block/OBlock.h"
#include "Model/Block/SBlock.h"
#include "Model/Block/TBlock.h"
#include "Model/Block/ZBlock.h"

#include <cstdlib>
#include <ctime>

/**
 * @brief Sinh ngẫu nhiên một khối (Block) trong trò chơi Tetris.
 *
 * Hàm này sẽ chọn một khối trong số 7 loại khối Tetris (I, J, L, O, S, T, Z) 
 * dựa trên giá trị ngẫu nhiên. Khối sau khi được tạo sẽ được dịch chuyển 
 * sang vị trí giữa bảng (theo số cột).
 *
 * @param gridColumns Số cột của lưới (grid) trong game. Dùng để xác định vị trí ban đầu của block.
 * @return std::unique_ptr<Block> Con trỏ thông minh trỏ đến khối vừa được sinh ra.
 */
std::unique_ptr<Block> RandomBlockGenerator::Generate(int gridColumns) {
    static bool initialized = false; ///< Đảm bảo srand chỉ khởi tạo 1 lần duy nhất
    if (!initialized) {
        std::srand(static_cast<unsigned>(std::time(nullptr))); ///< Khởi tạo seed cho random
        initialized = true;
    }

    int type = std::rand() % 7; ///< Chọn ngẫu nhiên loại block (0-6)
    std::unique_ptr<Block> block;

    /// Tạo block tương ứng với type
    switch (type) {
        case 0: block = std::make_unique<IBlock>(); break; ///< Khối thẳng (I)
        case 1: block = std::make_unique<JBlock>(); break; ///< Khối chữ J
        case 2: block = std::make_unique<LBlock>(); break; ///< Khối chữ L
        case 3: block = std::make_unique<OBlock>(); break; ///< Khối vuông (O)
        case 4: block = std::make_unique<SBlock>(); break; ///< Khối chữ S
        case 5: block = std::make_unique<TBlock>(); break; ///< Khối chữ T
        case 6: block = std::make_unique<ZBlock>(); break; ///< Khối chữ Z
    }

    int center_column = gridColumns / 2; ///< Tính cột trung tâm
    block->Move(0, center_column);       ///< Đặt block vào vị trí giữa lưới

    return block; ///< Trả về block vừa tạo
}
