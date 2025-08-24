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

std::unique_ptr<Block> RandomBlockGenerator::Generate(int gridColumns) {
    static bool initialized = false;
    if (!initialized) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        initialized = true;
    }

    int type = std::rand() % 7;
    std::unique_ptr<Block> block;

    switch (type) {
        case 0: block = std::make_unique<IBlock>(); break;
        case 1: block = std::make_unique<JBlock>(); break;
        case 2: block = std::make_unique<LBlock>(); break;
        case 3: block = std::make_unique<OBlock>(); break;
        case 4: block = std::make_unique<SBlock>(); break;
        case 5: block = std::make_unique<TBlock>(); break;
        case 6: block = std::make_unique<ZBlock>(); break;
    }

    int center_column = gridColumns / 2;
    block->Move(0, center_column);

    return block;
}
