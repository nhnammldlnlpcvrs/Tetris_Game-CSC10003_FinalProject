<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile doxygen_version="1.14.0">
  <compound kind="file">
    <name>App.cpp</name>
    <path>App/</path>
    <filename>_app_8cpp.html</filename>
    <includes id="_app_8h" name="App.h" local="yes" import="no" module="no" objc="no">App.h</includes>
    <includes id="_game_controller_8h" name="GameController.h" local="yes" import="no" module="no" objc="no">Controller/Game/GameController.h</includes>
    <includes id="_guide_8h" name="Guide.h" local="yes" import="no" module="no" objc="no">View/Guide/Guide.h</includes>
    <member kind="variable">
      <type>const int</type>
      <name>screenWidth</name>
      <anchorfile>_app_8cpp.html</anchorfile>
      <anchor>a7242fea9327c0747b47801c13f4e05c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const int</type>
      <name>screenHeight</name>
      <anchorfile>_app_8cpp.html</anchorfile>
      <anchor>a8897ff6127a397a8ee4ea76976f8534d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const int</type>
      <name>targetFPS</name>
      <anchorfile>_app_8cpp.html</anchorfile>
      <anchor>ae6bea5d630f02caf8697b377b87416f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const float</type>
      <name>panelX</name>
      <anchorfile>_app_8cpp.html</anchorfile>
      <anchor>a025a03ca7150bb7aa1abba3fd99d5012</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const float</type>
      <name>panelWidth</name>
      <anchorfile>_app_8cpp.html</anchorfile>
      <anchor>a7bfed013731d120e1ba1371f4dfc44f7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>App.h</name>
    <path>App/</path>
    <filename>_app_8h.html</filename>
    <class kind="class">App</class>
  </compound>
  <compound kind="file">
    <name>BlockController.cpp</name>
    <path>Controller/Block/</path>
    <filename>_block_controller_8cpp.html</filename>
    <includes id="_block_controller_8h" name="BlockController.h" local="yes" import="no" module="no" objc="no">BlockController.h</includes>
  </compound>
  <compound kind="file">
    <name>BlockController.h</name>
    <path>Controller/Block/</path>
    <filename>_block_controller_8h.html</filename>
    <includes id="_block_view_8h" name="BlockView.h" local="yes" import="no" module="no" objc="no">View/Block/BlockView.h</includes>
    <includes id="_block_history_8h" name="BlockHistory.h" local="yes" import="no" module="no" objc="no">Model/BlockService/BlockHistory.h</includes>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">BlockController</class>
  </compound>
  <compound kind="file">
    <name>GameController.cpp</name>
    <path>Controller/Game/</path>
    <filename>_game_controller_8cpp.html</filename>
    <includes id="_game_controller_8h" name="GameController.h" local="yes" import="no" module="no" objc="no">GameController.h</includes>
  </compound>
  <compound kind="file">
    <name>GameController.h</name>
    <path>Controller/Game/</path>
    <filename>_game_controller_8h.html</filename>
    <includes id="_game_logic_service_8h" name="GameLogicService.h" local="yes" import="no" module="no" objc="no">Model/Game/GameLogicService.h</includes>
    <includes id="_score_service_8h" name="ScoreService.h" local="yes" import="no" module="no" objc="no">Model/Game/ScoreService.h</includes>
    <includes id="_audio_service_8h" name="AudioService.h" local="yes" import="no" module="no" objc="no">Infrastructure/Audio/AudioService.h</includes>
    <includes id="_grid_render_8h" name="GridRender.h" local="yes" import="no" module="no" objc="no">View/Grid/GridRender.h</includes>
    <includes id="_grid_8h" name="Grid.h" local="yes" import="no" module="no" objc="no">Core/Grid/Grid.h</includes>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <includes id="_random_block_generator_8h" name="RandomBlockGenerator.h" local="yes" import="no" module="no" objc="no">Model/BlockService/RandomBlockGenerator.h</includes>
    <class kind="class">GameController</class>
  </compound>
  <compound kind="file">
    <name>Color.cpp</name>
    <path>Core/Graphics/</path>
    <filename>_color_8cpp.html</filename>
    <includes id="_color_8h" name="Color.h" local="yes" import="no" module="no" objc="no">Color.h</includes>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColors</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>aea7f3865c94b7c651b6d3bd95b938009</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Color</type>
      <name>GetBlockColor</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>a8e668021c25aa96a3bded869f704c0c7</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>darkGrey</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>ac745ea02ee7c667d37dbb70af4c9014f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>cyan</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>ad60c49a5c154c88304b546e16e47ed4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>blue</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>a7e78bfe284185633543a17557b9f02e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>orange</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>a326249a02ed814a93a9accf6eaeb1ae0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>yellow</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>af40f471a29b9372da120fc1cfe4919a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>green</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>ad0ef3ed7b6e40bc293b3becaed19e328</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>purple</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>a2e57d4080e7963600dea70c0f94f4dad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>red</name>
      <anchorfile>_color_8cpp.html</anchorfile>
      <anchor>a0c72d046084f830d973084d2596cd1a4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Color.h</name>
    <path>Core/Graphics/</path>
    <filename>_color_8h.html</filename>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColors</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>aea7f3865c94b7c651b6d3bd95b938009</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Color</type>
      <name>GetBlockColor</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>a8e668021c25aa96a3bded869f704c0c7</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>darkGrey</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>ac745ea02ee7c667d37dbb70af4c9014f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>green</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>ad0ef3ed7b6e40bc293b3becaed19e328</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>red</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>a0c72d046084f830d973084d2596cd1a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>orange</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>a326249a02ed814a93a9accf6eaeb1ae0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>yellow</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>af40f471a29b9372da120fc1cfe4919a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>purple</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>a2e57d4080e7963600dea70c0f94f4dad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>cyan</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>ad60c49a5c154c88304b546e16e47ed4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>blue</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>a7e78bfe284185633543a17557b9f02e2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>lightBlue</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>abba647316dfb72c08441ace89886a4df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Color</type>
      <name>darkBlue</name>
      <anchorfile>_color_8h.html</anchorfile>
      <anchor>a475c619b2aa4c3377a3a62ce406ad53f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Grid.cpp</name>
    <path>Core/Grid/</path>
    <filename>_grid_8cpp.html</filename>
    <includes id="_grid_8h" name="Grid.h" local="yes" import="no" module="no" objc="no">Grid.h</includes>
  </compound>
  <compound kind="file">
    <name>Grid.h</name>
    <path>Core/Grid/</path>
    <filename>_grid_8h.html</filename>
    <includes id="_color_8h" name="Color.h" local="yes" import="no" module="no" objc="no">Core/Graphics/Color.h</includes>
    <includes id="_position_8h" name="Position.h" local="yes" import="no" module="no" objc="no">Core/Position/Position.h</includes>
    <class kind="class">Grid</class>
  </compound>
  <compound kind="file">
    <name>Position.cpp</name>
    <path>Core/Position/</path>
    <filename>_position_8cpp.html</filename>
    <includes id="_position_8h" name="Position.h" local="yes" import="no" module="no" objc="no">Position.h</includes>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>_position_8cpp.html</anchorfile>
      <anchor>ab7ab267bcecdb85160da8e5a7069a98e</anchor>
      <arglist>(std::ostream &amp;os, const Position &amp;pos)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Position.h</name>
    <path>Core/Position/</path>
    <filename>_position_8h.html</filename>
    <class kind="struct">Position</class>
  </compound>
  <compound kind="file">
    <name>AudioService.cpp</name>
    <path>Infrastructure/Audio/</path>
    <filename>_audio_service_8cpp.html</filename>
    <includes id="_audio_service_8h" name="AudioService.h" local="yes" import="no" module="no" objc="no">AudioService.h</includes>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>ROTATE_SOUND_PATH</name>
      <anchorfile>_audio_service_8cpp.html</anchorfile>
      <anchor>aca95064d2374c6a58daff28c5b93115f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>CLEAR_SOUND_PATH</name>
      <anchorfile>_audio_service_8cpp.html</anchorfile>
      <anchor>a8de609d278857e08fba0ee04727b5c84</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>constexpr const char *</type>
      <name>MUSIC_PATH</name>
      <anchorfile>_audio_service_8cpp.html</anchorfile>
      <anchor>a8b8bb0e14f2c4092841330a050b20733</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AudioService.h</name>
    <path>Infrastructure/Audio/</path>
    <filename>_audio_service_8h.html</filename>
    <class kind="class">AudioService</class>
  </compound>
  <compound kind="file">
    <name>main.cpp</name>
    <path></path>
    <filename>main_8cpp.html</filename>
    <includes id="_app_8h" name="App.h" local="yes" import="no" module="no" objc="no">../resource/App/App.h</includes>
    <member kind="function">
      <type>int</type>
      <name>main</name>
      <anchorfile>main_8cpp.html</anchorfile>
      <anchor>ae66f6b31b5ad750f1fe042a706a4e3d4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Block.cpp</name>
    <path>Model/Block/</path>
    <filename>_block_8cpp.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Block.h</includes>
  </compound>
  <compound kind="file">
    <name>Block.h</name>
    <path>Model/Block/</path>
    <filename>_block_8h.html</filename>
    <includes id="_position_8h" name="Position.h" local="yes" import="no" module="no" objc="no">Core/Position/Position.h</includes>
    <includes id="_color_8h" name="Color.h" local="yes" import="no" module="no" objc="no">Core/Graphics/Color.h</includes>
    <includes id="_block_memento_8h" name="BlockMemento.h" local="yes" import="no" module="no" objc="no">BlockMemento.h</includes>
    <class kind="class">Block</class>
  </compound>
  <compound kind="file">
    <name>BlockMemento.cpp</name>
    <path>Model/Block/</path>
    <filename>_block_memento_8cpp.html</filename>
    <includes id="_block_memento_8h" name="BlockMemento.h" local="yes" import="no" module="no" objc="no">BlockMemento.h</includes>
  </compound>
  <compound kind="file">
    <name>BlockMemento.h</name>
    <path>Model/Block/</path>
    <filename>_block_memento_8h.html</filename>
    <includes id="_i_memento_8h" name="IMemento.h" local="yes" import="no" module="no" objc="no">Model/Block/IMemento.h</includes>
    <class kind="class">BlockMemento</class>
  </compound>
  <compound kind="file">
    <name>IBlock.cpp</name>
    <path>Model/Block/</path>
    <filename>_i_block_8cpp.html</filename>
    <includes id="_i_block_8h" name="IBlock.h" local="yes" import="no" module="no" objc="no">IBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>IBlock.h</name>
    <path>Model/Block/</path>
    <filename>_i_block_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">IBlock</class>
  </compound>
  <compound kind="file">
    <name>IMemento.h</name>
    <path>Model/Block/</path>
    <filename>_i_memento_8h.html</filename>
    <class kind="class">IMemento</class>
  </compound>
  <compound kind="file">
    <name>JBlock.cpp</name>
    <path>Model/Block/</path>
    <filename>_j_block_8cpp.html</filename>
    <includes id="_j_block_8h" name="JBlock.h" local="yes" import="no" module="no" objc="no">JBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>JBlock.h</name>
    <path>Model/Block/</path>
    <filename>_j_block_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">JBlock</class>
  </compound>
  <compound kind="file">
    <name>LBlock.cpp</name>
    <path>Model/Block/</path>
    <filename>_l_block_8cpp.html</filename>
    <includes id="_l_block_8h" name="LBlock.h" local="yes" import="no" module="no" objc="no">LBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>LBlock.h</name>
    <path>Model/Block/</path>
    <filename>_l_block_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">LBlock</class>
  </compound>
  <compound kind="file">
    <name>OBlock.cpp</name>
    <path>Model/Block/</path>
    <filename>_o_block_8cpp.html</filename>
    <includes id="_o_block_8h" name="OBlock.h" local="yes" import="no" module="no" objc="no">OBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>OBlock.h</name>
    <path>Model/Block/</path>
    <filename>_o_block_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">OBlock</class>
  </compound>
  <compound kind="file">
    <name>SBlock.cpp</name>
    <path>Model/Block/</path>
    <filename>_s_block_8cpp.html</filename>
    <includes id="_s_block_8h" name="SBlock.h" local="yes" import="no" module="no" objc="no">SBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>SBlock.h</name>
    <path>Model/Block/</path>
    <filename>_s_block_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">SBlock</class>
  </compound>
  <compound kind="file">
    <name>TBlock.cpp</name>
    <path>Model/Block/</path>
    <filename>_t_block_8cpp.html</filename>
    <includes id="_t_block_8h" name="TBlock.h" local="yes" import="no" module="no" objc="no">TBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>TBlock.h</name>
    <path>Model/Block/</path>
    <filename>_t_block_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">TBlock</class>
  </compound>
  <compound kind="file">
    <name>ZBlock.cpp</name>
    <path>Model/Block/</path>
    <filename>_z_block_8cpp.html</filename>
    <includes id="_z_block_8h" name="ZBlock.h" local="yes" import="no" module="no" objc="no">ZBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>ZBlock.h</name>
    <path>Model/Block/</path>
    <filename>_z_block_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">ZBlock</class>
  </compound>
  <compound kind="file">
    <name>BlockFactory.cpp</name>
    <path>Model/BlockService/</path>
    <filename>_block_factory_8cpp.html</filename>
    <includes id="_block_factory_8h" name="BlockFactory.h" local="yes" import="no" module="no" objc="no">BlockFactory.h</includes>
  </compound>
  <compound kind="file">
    <name>BlockFactory.h</name>
    <path>Model/BlockService/</path>
    <filename>_block_factory_8h.html</filename>
    <includes id="_i_block_8h" name="IBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/IBlock.h</includes>
    <includes id="_j_block_8h" name="JBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/JBlock.h</includes>
    <includes id="_l_block_8h" name="LBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/LBlock.h</includes>
    <includes id="_o_block_8h" name="OBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/OBlock.h</includes>
    <includes id="_s_block_8h" name="SBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/SBlock.h</includes>
    <includes id="_t_block_8h" name="TBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/TBlock.h</includes>
    <includes id="_z_block_8h" name="ZBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/ZBlock.h</includes>
    <class kind="class">BlockFactory</class>
  </compound>
  <compound kind="file">
    <name>BlockHistory.cpp</name>
    <path>Model/BlockService/</path>
    <filename>_block_history_8cpp.html</filename>
    <includes id="_block_history_8h" name="BlockHistory.h" local="yes" import="no" module="no" objc="no">BlockHistory.h</includes>
  </compound>
  <compound kind="file">
    <name>BlockHistory.h</name>
    <path>Model/BlockService/</path>
    <filename>_block_history_8h.html</filename>
    <includes id="_block_memento_8h" name="BlockMemento.h" local="yes" import="no" module="no" objc="no">Model/Block/BlockMemento.h</includes>
    <class kind="class">BlockHistory</class>
  </compound>
  <compound kind="file">
    <name>RandomBlockGenerator.cpp</name>
    <path>Model/BlockService/</path>
    <filename>_random_block_generator_8cpp.html</filename>
    <includes id="_random_block_generator_8h" name="RandomBlockGenerator.h" local="yes" import="no" module="no" objc="no">RandomBlockGenerator.h</includes>
    <includes id="_i_block_8h" name="IBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/IBlock.h</includes>
    <includes id="_j_block_8h" name="JBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/JBlock.h</includes>
    <includes id="_l_block_8h" name="LBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/LBlock.h</includes>
    <includes id="_o_block_8h" name="OBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/OBlock.h</includes>
    <includes id="_s_block_8h" name="SBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/SBlock.h</includes>
    <includes id="_t_block_8h" name="TBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/TBlock.h</includes>
    <includes id="_z_block_8h" name="ZBlock.h" local="yes" import="no" module="no" objc="no">Model/Block/ZBlock.h</includes>
  </compound>
  <compound kind="file">
    <name>RandomBlockGenerator.h</name>
    <path>Model/BlockService/</path>
    <filename>_random_block_generator_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">RandomBlockGenerator</class>
  </compound>
  <compound kind="file">
    <name>GameLogicService.cpp</name>
    <path>Model/Game/</path>
    <filename>_game_logic_service_8cpp.html</filename>
    <includes id="_game_logic_service_8h" name="GameLogicService.h" local="yes" import="no" module="no" objc="no">GameLogicService.h</includes>
  </compound>
  <compound kind="file">
    <name>GameLogicService.h</name>
    <path>Model/Game/</path>
    <filename>_game_logic_service_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <includes id="_grid_8h" name="Grid.h" local="yes" import="no" module="no" objc="no">Core/Grid/Grid.h</includes>
    <includes id="_color_8h" name="Color.h" local="yes" import="no" module="no" objc="no">Core/Graphics/Color.h</includes>
    <class kind="class">GameLogicService</class>
  </compound>
  <compound kind="file">
    <name>ScoreService.cpp</name>
    <path>Model/Game/</path>
    <filename>_score_service_8cpp.html</filename>
    <includes id="_score_service_8h" name="ScoreService.h" local="yes" import="no" module="no" objc="no">ScoreService.h</includes>
  </compound>
  <compound kind="file">
    <name>ScoreService.h</name>
    <path>Model/Game/</path>
    <filename>_score_service_8h.html</filename>
    <class kind="class">ScoreService</class>
  </compound>
  <compound kind="file">
    <name>BlockView.cpp</name>
    <path>View/Block/</path>
    <filename>_block_view_8cpp.html</filename>
    <includes id="_block_view_8h" name="BlockView.h" local="yes" import="no" module="no" objc="no">BlockView.h</includes>
  </compound>
  <compound kind="file">
    <name>BlockView.h</name>
    <path>View/Block/</path>
    <filename>_block_view_8h.html</filename>
    <includes id="_block_8h" name="Block.h" local="yes" import="no" module="no" objc="no">Model/Block/Block.h</includes>
    <class kind="class">BlockView</class>
  </compound>
  <compound kind="file">
    <name>GridRender.cpp</name>
    <path>View/Grid/</path>
    <filename>_grid_render_8cpp.html</filename>
    <includes id="_grid_render_8h" name="GridRender.h" local="yes" import="no" module="no" objc="no">GridRender.h</includes>
  </compound>
  <compound kind="file">
    <name>GridRender.h</name>
    <path>View/Grid/</path>
    <filename>_grid_render_8h.html</filename>
    <includes id="_grid_8h" name="Grid.h" local="yes" import="no" module="no" objc="no">Core/Grid/Grid.h</includes>
    <includes id="_color_8h" name="Color.h" local="yes" import="no" module="no" objc="no">Core/Graphics/Color.h</includes>
    <class kind="class">GridRenderer</class>
  </compound>
  <compound kind="file">
    <name>Guide.cpp</name>
    <path>View/Guide/</path>
    <filename>_guide_8cpp.html</filename>
    <includes id="_guide_8h" name="Guide.h" local="yes" import="no" module="no" objc="no">Guide.h</includes>
    <member kind="function">
      <type>void</type>
      <name>DrawGuide</name>
      <anchorfile>_guide_8cpp.html</anchorfile>
      <anchor>a072740cc83de0c007f577e3b0bf5ba6c</anchor>
      <arglist>(const Font &amp;font, float x, float y, float width)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Guide.h</name>
    <path>View/Guide/</path>
    <filename>_guide_8h.html</filename>
    <member kind="function">
      <type>void</type>
      <name>DrawGuide</name>
      <anchorfile>_guide_8h.html</anchorfile>
      <anchor>a072740cc83de0c007f577e3b0bf5ba6c</anchor>
      <arglist>(const Font &amp;font, float x, float y, float width)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>App</name>
    <filename>class_app.html</filename>
    <member kind="function">
      <type>void</type>
      <name>Run</name>
      <anchorfile>class_app.html</anchorfile>
      <anchor>a78d24016da98422fabb55b10dbfe3d72</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AudioService</name>
    <filename>class_audio_service.html</filename>
    <member kind="function">
      <type></type>
      <name>AudioService</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>ae802d9f4de7199ed2300c96f2740169e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~AudioService</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a1532bf691f7e70c8e0a34bf2d05cae16</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Init</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a48f4419250668d2f3e9ed6693d850a22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>PlayRotateEffect</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a93199082518f814ef98782708cfa666a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>PlayClearEffect</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>ad97739a121918062514f0fb4a798541a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>PlayBackgroundMusic</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>aeb46906945f4914497cdb30685b836a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Music &amp;</type>
      <name>GetBackgroundMusic</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a6fffef3150c9d05e7ed0a0cd1184412f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Sound</type>
      <name>rotate_sound_</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a5243983ea2d640b7259238ca0141e642</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Sound</type>
      <name>clear_sound_</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a2e6777e6569e4d4b419b0326c20e06bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Music</type>
      <name>background_music_</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a520dd8d72694f4f2c99d1ba63b2f649c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>is_initialized_</name>
      <anchorfile>class_audio_service.html</anchorfile>
      <anchor>a8a2ef6d002bf1b045b63d38b374f1c8f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Block</name>
    <filename>class_block.html</filename>
    <member kind="function">
      <type></type>
      <name>Block</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a37658a946bf5067ad01d68d9ff086adc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; BlockMemento &gt;</type>
      <name>SaveState</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a1730a2e08f5e03e2d8f475f858c708b7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>RestoreState</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a4f90c211eb2c191746e6e37b510ada1e</anchor>
      <arglist>(const std::shared_ptr&lt; BlockMemento &gt; &amp;memento)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Draw</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a7df884ba33f04fb233a290cfc70905f8</anchor>
      <arglist>(int offset_x, int offset_y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>DrawPreview</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a695ec89ef86b9d565514a0c992fa611c</anchor>
      <arglist>(int offset_x, int offset_y)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Move</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a8d3c1b1b61b9a5671281508e42034010</anchor>
      <arglist>(int rows, int columns)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MoveLeft</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a086ba9ec7589bba279aec285a1ff61df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MoveRight</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>ad867388e27d27f27cbcc80d03c426a8b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MoveDown</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>ac540e89656281c04dc3d3eb0f016a878</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MoveUp</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a49bbf9a0b53ffad2d8b2ead886c3c895</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Rotate</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a1ced2170a2dad5b9110cb3c2171be6e4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>RotateBack</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a6490efd5854a5236ba7a132870e8fb31</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Position &gt;</type>
      <name>GetCellPositions</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a1fb01ff1f82c82806024787f382071e0</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>std::pair&lt; int, int &gt;</type>
      <name>GetSize</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>af0c7f1220a3e906962ccea4d83fd6838</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetId</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a3336669e14498db0791297edd0fd2ddb</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>afbec0b36440b11cd6aa16990ea760e98</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a38d890966dfeaa3ec332899f9428555f</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~Block</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>aece461956ee55f531533348cab5487bf</anchor>
      <arglist>()=default</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>_id</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>aa3e22cbcc4cc469f33569b1b9c431855</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>_rotationState</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a9d62c757df555397bbcf7d2caed740fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>_rowOffset</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a1fe022f0690155ab3e4b77013a5bea34</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>_columnOffset</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a31032d0702bcf331d52c8fab33078a71</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::map&lt; int, std::vector&lt; Position &gt; &gt;</type>
      <name>_cells</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>aa05cf617218d661ea9f1ff8572328f61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>std::vector&lt; Color &gt;</type>
      <name>_colors</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>ac698c3f6c0d260133890071f02ec8ad3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static constexpr int</type>
      <name>cellSize</name>
      <anchorfile>class_block.html</anchorfile>
      <anchor>a38fd7bd64af431ccd6fe2d22cb122443</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BlockController</name>
    <filename>class_block_controller.html</filename>
    <member kind="function">
      <type></type>
      <name>BlockController</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>a1141b019d24dd4cef9607fccebb9d820</anchor>
      <arglist>(std::shared_ptr&lt; Block &gt; block)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Move</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>aaf0130109976cc1de077c8249625c54a</anchor>
      <arglist>(int delta_row, int delta_col)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Rotate</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>ab37152f194a530f551c60d494afc677f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; Block &gt;</type>
      <name>GetBlock</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>a8008f5c80582b91f03eb372231987213</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SaveState</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>a2d70f4a7f12862c3bf47cb87c1d91ac6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Undo</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>a4d733b25b5288ee7d0bee647e327e255</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Redo</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>aac0b017f87191c08865cd87c3b65d2e2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::shared_ptr&lt; Block &gt;</type>
      <name>block_</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>a0c7ef39d87108dbf0356cd0011824848</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>BlockHistory</type>
      <name>_history</name>
      <anchorfile>class_block_controller.html</anchorfile>
      <anchor>a27af39249b41b6c8193224cd0c4e3f2f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BlockFactory</name>
    <filename>class_block_factory.html</filename>
    <member kind="function">
      <type></type>
      <name>BlockFactory</name>
      <anchorfile>class_block_factory.html</anchorfile>
      <anchor>a344e662841f70635a678f1d25c6cd80a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>CreateBlock</name>
      <anchorfile>class_block_factory.html</anchorfile>
      <anchor>a762086ec7b4b74f8b6c29e6922cd183f</anchor>
      <arglist>(int id) const</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>CreateRandomBlock</name>
      <anchorfile>class_block_factory.html</anchorfile>
      <anchor>a7d7e410223727635f067b6c8550e3f00</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="private">
      <type>int</type>
      <name>GenerateRandomId</name>
      <anchorfile>class_block_factory.html</anchorfile>
      <anchor>ab691f19ab432e1eba233b46d368c41c4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::array&lt; std::unique_ptr&lt; Block &gt;, 7 &gt;</type>
      <name>_prototypes</name>
      <anchorfile>class_block_factory.html</anchorfile>
      <anchor>a03fde2a7ea0ab9d5d095c10cf062fec3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BlockHistory</name>
    <filename>class_block_history.html</filename>
    <member kind="function">
      <type>void</type>
      <name>Save</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>a1afb2398996f52c97e742766d9dad558</anchor>
      <arglist>(const std::shared_ptr&lt; BlockMemento &gt; &amp;memento)</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; BlockMemento &gt;</type>
      <name>Undo</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>a1a7948071d008a99a643b1ff5bf07964</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::shared_ptr&lt; BlockMemento &gt;</type>
      <name>Redo</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>ad6ce15c33235be9b32102076755115a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>CanUndo</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>a921bc75656ce816fd93a278d99d87f43</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>CanRedo</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>a15022c3bd1d0184bb1ac833742baba9c</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Clear</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>afff10347b277a319bcf63fdc5732e771</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::stack&lt; std::shared_ptr&lt; BlockMemento &gt; &gt;</type>
      <name>_undo_stack</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>a95ee2710bcd28bc2bb89417c3cd1471e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::stack&lt; std::shared_ptr&lt; BlockMemento &gt; &gt;</type>
      <name>_redo_stack</name>
      <anchorfile>class_block_history.html</anchorfile>
      <anchor>ac20c06c776b5f2b629475c585dfd52f7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BlockMemento</name>
    <filename>class_block_memento.html</filename>
    <base>IMemento</base>
    <member kind="function">
      <type></type>
      <name>BlockMemento</name>
      <anchorfile>class_block_memento.html</anchorfile>
      <anchor>ab4ddc24e67cc7a4c5b6fbc3facce2f6f</anchor>
      <arglist>(int rotationState, int rowOffset, int columnOffset)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetRotationState</name>
      <anchorfile>class_block_memento.html</anchorfile>
      <anchor>a6eb1ea98bfcfbaa9851f4f8c61ab0e4d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetRowOffset</name>
      <anchorfile>class_block_memento.html</anchorfile>
      <anchor>a7ec00b64c341ac0f6f66d160c8a79eb3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetColumnOffset</name>
      <anchorfile>class_block_memento.html</anchorfile>
      <anchor>a85d7437f5d42355b180a9c1b0e7d3d6e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>m_rotationState</name>
      <anchorfile>class_block_memento.html</anchorfile>
      <anchor>a0bc44303d384afd1b943a80ef3bf8277</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>m_rowOffset</name>
      <anchorfile>class_block_memento.html</anchorfile>
      <anchor>abd4c001d75abb8e96d89db474700932b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>m_columnOffset</name>
      <anchorfile>class_block_memento.html</anchorfile>
      <anchor>a4518f05bb27eaa0778c5ec8bcafed571</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>BlockView</name>
    <filename>class_block_view.html</filename>
    <member kind="function">
      <type>void</type>
      <name>Render</name>
      <anchorfile>class_block_view.html</anchorfile>
      <anchor>a4292993a2ef06e16047df2f6d4a28063</anchor>
      <arglist>(Block &amp;block, int offset_x, int offset_y) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>GameController</name>
    <filename>class_game_controller.html</filename>
    <member kind="function">
      <type></type>
      <name>GameController</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>abc996a5d7a9c9abb6f73e29977cd4291</anchor>
      <arglist>(int rows, int cols, int cellSize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Init</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>abe2325a1ff410fbbe6d94a7d1f63320a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Update</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>ac673d7d0e9dd7a57390ac204e43f0cbe</anchor>
      <arglist>(float deltaTime)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Draw</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a817309716548ec96b574eb59b5ec1212</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>DrawNextBlock</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>ac30b6f7445883988df81ccd6bfc4151d</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Reset</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a3e555e037b0ad8dd0c94e5166070b7a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetScore</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>ad194663264cdcc05769e94fda8d35616</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetBestScore</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a19a0c52ac3a09bd5c9bb655d21b9bc2e</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsGameOver</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>ac02eedfe4afbe4f4fc69e711a358f270</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" protection="private">
      <type>void</type>
      <name>SpawnNewBlock</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>ae1d064295f8daec44164f534dc488c95</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>Grid</type>
      <name>grid_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a76c6f5d2649feebdb31c70604cdd6ae3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>current_block_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a633f68f7d23df149d896f0b86f5f35ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>next_block_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>af6db251b98c8d184f02aecb06ad6f16f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>GridRenderer</type>
      <name>renderer_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>adf38a44f30e200f15d640f1ed93d87a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>GameLogicService</type>
      <name>logic_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a6bbb00ccddd5167679f65a40f988e3d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>ScoreService</type>
      <name>score_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a546b6d44cf9aacecdd8aa53b2281cc16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>AudioService</type>
      <name>audio_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a7e3dd189b1507c4cdd42079a1d69164b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>drop_timer_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>ac8075367bfae76b751afc9720b3b19e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>float</type>
      <name>drop_interval_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a7aa76805eb521d5222fe4267be649cfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>bool</type>
      <name>is_game_over_</name>
      <anchorfile>class_game_controller.html</anchorfile>
      <anchor>a1401dd0146207e1adea2d3d46911ed7d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>GameLogicService</name>
    <filename>class_game_logic_service.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>MoveLeft</name>
      <anchorfile>class_game_logic_service.html</anchorfile>
      <anchor>a665ec1f545ec841bacab8e7bc695925f</anchor>
      <arglist>(Block &amp;block, const Grid &amp;grid) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>MoveRight</name>
      <anchorfile>class_game_logic_service.html</anchorfile>
      <anchor>aec8318804d8d89e8fa65b14b7589ddb2</anchor>
      <arglist>(Block &amp;block, const Grid &amp;grid) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>MoveDown</name>
      <anchorfile>class_game_logic_service.html</anchorfile>
      <anchor>acea467d66dae6a02d412fcb7116db7fd</anchor>
      <arglist>(Block &amp;block, const Grid &amp;grid) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>Rotate</name>
      <anchorfile>class_game_logic_service.html</anchorfile>
      <anchor>a980bbff0cf19f735f10c3b7daaf2b91a</anchor>
      <arglist>(Block &amp;block, const Grid &amp;grid) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>LockBlock</name>
      <anchorfile>class_game_logic_service.html</anchorfile>
      <anchor>a66080fbc0a0a1f6215bbc22a84b6f168</anchor>
      <arglist>(Grid &amp;grid, const Block &amp;block) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>ClearLines</name>
      <anchorfile>class_game_logic_service.html</anchorfile>
      <anchor>a02349c36655df8040a1574f706255034</anchor>
      <arglist>(Grid &amp;grid) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsGameOver</name>
      <anchorfile>class_game_logic_service.html</anchorfile>
      <anchor>a9be813a633fe2172a3a0379a2511a98c</anchor>
      <arglist>(const Grid &amp;grid) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Grid</name>
    <filename>class_grid.html</filename>
    <member kind="function">
      <type></type>
      <name>Grid</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>a3e2592c777f412b65e0d4e7396b7f602</anchor>
      <arglist>(int rows, int columns)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsCellOccupied</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>a6d6ea351a0c88b3c0f79df0277f3a108</anchor>
      <arglist>(int row, int column) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SetCell</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>a60a9f60f3c95281243fcc49dae4ef8e3</anchor>
      <arglist>(int row, int column, const Color &amp;color)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ClearCell</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>aab7fc6e8a0b8a922c7035f4423cf2458</anchor>
      <arglist>(int row, int column)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>ClearFullLines</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>a29d83e071468b70943613aa758f9476d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetRows</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>ad6166ccc007bb8e5148134f09b1b27ae</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetColumns</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>a14b9ed254fa998e69d61cc536d22b873</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>const std::vector&lt; std::vector&lt; Color &gt; &gt; &amp;</type>
      <name>GetCells</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>aeaedeee050268bcee9aff5b92d70f3b3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsValidPosition</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>ad5a0606a61f181e3a3e5f6b20a865032</anchor>
      <arglist>(const std::vector&lt; Position &gt; &amp;positions) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>HasBlockAtTop</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>ae1316dfd669dc06b92f270657df172b3</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_rows</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>a1ffc6dd8bbe395e54bd7132c3c3fcfc4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_columns</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>adadaed5e80bd86e3b4061478cfd159bc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>std::vector&lt; std::vector&lt; Color &gt; &gt;</type>
      <name>_cells</name>
      <anchorfile>class_grid.html</anchorfile>
      <anchor>a6b8f8960d5d62cadcde83f6fefa95e90</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>GridRenderer</name>
    <filename>class_grid_renderer.html</filename>
    <member kind="function">
      <type></type>
      <name>GridRenderer</name>
      <anchorfile>class_grid_renderer.html</anchorfile>
      <anchor>ab7aa402bc829752922e62e4231262072</anchor>
      <arglist>(int cellSize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Draw</name>
      <anchorfile>class_grid_renderer.html</anchorfile>
      <anchor>a1fdd8f49ef23e045d643c08088b187a5</anchor>
      <arglist>(const Grid &amp;grid, int offset_x, int offset_y) const</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>_cellSize</name>
      <anchorfile>class_grid_renderer.html</anchorfile>
      <anchor>a670253e64bf2218ded0bf7a8c3ad0293</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IBlock</name>
    <filename>class_i_block.html</filename>
    <base>Block</base>
    <member kind="function">
      <type></type>
      <name>IBlock</name>
      <anchorfile>class_i_block.html</anchorfile>
      <anchor>af26a7f3b50449bce99a7d1b1fd2cd3df</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_i_block.html</anchorfile>
      <anchor>a2ae59c18a11f8ac6dd67df8704e0f277</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_i_block.html</anchorfile>
      <anchor>a39c6445ab3b91e120cbdd098e2867814</anchor>
      <arglist>() const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IMemento</name>
    <filename>class_i_memento.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~IMemento</name>
      <anchorfile>class_i_memento.html</anchorfile>
      <anchor>a3e1c418d35b028a749f8cd8f40732c02</anchor>
      <arglist>()=default</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>JBlock</name>
    <filename>class_j_block.html</filename>
    <base>Block</base>
    <member kind="function">
      <type></type>
      <name>JBlock</name>
      <anchorfile>class_j_block.html</anchorfile>
      <anchor>aba4a5ffffa85bd6281b9348e6e693964</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_j_block.html</anchorfile>
      <anchor>a3a208d023d3ad9308aab1879621caf9d</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_j_block.html</anchorfile>
      <anchor>ad851644da3b1ce43e99d19447670ad57</anchor>
      <arglist>() const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>LBlock</name>
    <filename>class_l_block.html</filename>
    <base>Block</base>
    <member kind="function">
      <type></type>
      <name>LBlock</name>
      <anchorfile>class_l_block.html</anchorfile>
      <anchor>a1b3d85ab4771dd322c8cb7080016248a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_l_block.html</anchorfile>
      <anchor>a0040537b9e5b6072c7234d16f06b4646</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_l_block.html</anchorfile>
      <anchor>aa6a0bade55865e762a3291a11a4ba6d3</anchor>
      <arglist>() const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>OBlock</name>
    <filename>class_o_block.html</filename>
    <base>Block</base>
    <member kind="function">
      <type></type>
      <name>OBlock</name>
      <anchorfile>class_o_block.html</anchorfile>
      <anchor>a6f2a8d88e083cb78378a325c2a53be1b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_o_block.html</anchorfile>
      <anchor>a56aba00624ec5971f50a66a08937e11b</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_o_block.html</anchorfile>
      <anchor>a219c400a479a68171f73ed76a462fcb0</anchor>
      <arglist>() const override</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Position</name>
    <filename>struct_position.html</filename>
    <member kind="function">
      <type></type>
      <name>Position</name>
      <anchorfile>struct_position.html</anchorfile>
      <anchor>a71430182b83d7a8815349c2feec2701d</anchor>
      <arglist>(int row=0, int column=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>struct_position.html</anchorfile>
      <anchor>acf13e7e45c7c07a67c2adf2f7e1dcc5f</anchor>
      <arglist>(const Position &amp;other) const</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>struct_position.html</anchorfile>
      <anchor>ae4d491be71bc11896f864835187e860d</anchor>
      <arglist>(const Position &amp;other) const</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>row</name>
      <anchorfile>struct_position.html</anchorfile>
      <anchor>a224d714110152e1fca26b2437253f56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>column</name>
      <anchorfile>struct_position.html</anchorfile>
      <anchor>a7bf46f67257b7fd5d6ced23095d15846</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>struct_position.html</anchorfile>
      <anchor>ab7ab267bcecdb85160da8e5a7069a98e</anchor>
      <arglist>(std::ostream &amp;os, const Position &amp;pos)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RandomBlockGenerator</name>
    <filename>class_random_block_generator.html</filename>
    <member kind="function" static="yes">
      <type>static std::unique_ptr&lt; Block &gt;</type>
      <name>Generate</name>
      <anchorfile>class_random_block_generator.html</anchorfile>
      <anchor>a8388aead1bc6f82e48d32b4adfc5be67</anchor>
      <arglist>(int gridColumns)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>SBlock</name>
    <filename>class_s_block.html</filename>
    <base>Block</base>
    <member kind="function">
      <type></type>
      <name>SBlock</name>
      <anchorfile>class_s_block.html</anchorfile>
      <anchor>aadbe7658255bcd6c2efe585ad9782962</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_s_block.html</anchorfile>
      <anchor>aca0aef137a4731514a3a93c0e47b34c4</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_s_block.html</anchorfile>
      <anchor>a23543416110b3da286545a34860ad4c6</anchor>
      <arglist>() const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ScoreService</name>
    <filename>class_score_service.html</filename>
    <member kind="function">
      <type></type>
      <name>ScoreService</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>af7e62887b7c4b51100e2370791f8e21c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Reset</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>ac8b683f02fc2875586473a2e913b59a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>AddScore</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>a37d1b35ef3dae1bb6ef5037d33cab679</anchor>
      <arglist>(int linesCleared, int dropPoints)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetScore</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>a95874e149f780643d498140f76ce660a</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>GetBestScore</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>aa7f56f54daa2ef3ce97a56cff0891be6</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>LoadBestScore</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>a83cdc41ffc2210c264aff724b3e13c5a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SaveBestScore</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>a2ae4ce64f6aa4c51501f5b02d3a38fbb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>score</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>a9c6aaf0b273b07dac69b85960e7ac259</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="private">
      <type>int</type>
      <name>bestScore</name>
      <anchorfile>class_score_service.html</anchorfile>
      <anchor>a509cbe7b2bec958aa761262e610aa194</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TBlock</name>
    <filename>class_t_block.html</filename>
    <base>Block</base>
    <member kind="function">
      <type></type>
      <name>TBlock</name>
      <anchorfile>class_t_block.html</anchorfile>
      <anchor>a3ff40864c7de7545539f6676e9cdc4be</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_t_block.html</anchorfile>
      <anchor>a93407d91628f1b1a45d6b23df9e031d1</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_t_block.html</anchorfile>
      <anchor>a9aa05effb8abe032b96a9c4f765f07a8</anchor>
      <arglist>() const override</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ZBlock</name>
    <filename>class_z_block.html</filename>
    <base>Block</base>
    <member kind="function">
      <type></type>
      <name>ZBlock</name>
      <anchorfile>class_z_block.html</anchorfile>
      <anchor>a0cec86fba303e36df08b23d5e5e5932f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::vector&lt; Color &gt;</type>
      <name>GetCellColor</name>
      <anchorfile>class_z_block.html</anchorfile>
      <anchor>a450642e53bc6b13a443fcbb130a4a4fb</anchor>
      <arglist>() const override</arglist>
    </member>
    <member kind="function">
      <type>std::unique_ptr&lt; Block &gt;</type>
      <name>Clone</name>
      <anchorfile>class_z_block.html</anchorfile>
      <anchor>afd5dc0689963eb16ea9f5e248786b2de</anchor>
      <arglist>() const override</arglist>
    </member>
  </compound>
</tagfile>
