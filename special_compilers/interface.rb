UI = LibUI

FULL = 1
NORMAL = 0

class Interface

  def initialize
    UI.init
    @absolute_main_window = UI.new_window('Spartan Industrial 2 Compiler', 700, 500, 1)
    @window_box = UI.new_vertical_box
    UI.box_set_padded(@window_box, 0)
    UI.window_set_child(@absolute_main_window, @window_box)
  end

  def draw_window
    UI.control_show(@absolute_main_window)
    UI.main
    UI.quit
  end

  def load_close_instance_behaviour
    UI.window_on_closing(@absolute_main_window) do
      UI.control_destroy(@absolute_main_window)
      UI.quit
      0
    end
  end

  def load_sectors
    @window_sector1 = UI.new_vertical_box
    @window_sector2 = UI.new_vertical_box
    @window_sector3 = UI.new_vertical_box

    UI.box_append(@window_box, @window_sector1, 1)
    UI.box_append(@window_box, @window_sector2, 1)
    UI.box_append(@window_box, @window_sector3, 1)
  end

  def new_button(name, sector, mode)
    button = UI.new_button(name)
    case sector
    when 1
      UI.box_append(@window_sector1, button, mode)
    when 2
      UI.box_append(@window_sector1, button, mode)
    else 3
      UI.box_append(@window_sector1, button, mode)
    end
  end


  def new_table(hash_data, headers, sector)

    @block_callers = []

    model_handler = UI::FFI::TableModelHandler.malloc
    model_handler.to_ptr.free = Fiddle::RUBY_FREE
    model_handler.NumColumns   = rbcallback(4) { headers.count }
    model_handler.ColumnType   = rbcallback(4) { 0 }
    model_handler.NumRows      = rbcallback(4) { hash_data.count }
    model_handler.CellValue    = rbcallback(1, [1, 1, 4, 4]) do |_, _, row, column|
      UI.new_table_value_string(hash_data[row][column])  
    end
    model_handler.SetCellValue = rbcallback(0, [0]) {}
    
    model = UI.new_table_model(model_handler)
    
    table_params = UI::FFI::TableParams.malloc
    table_params.to_ptr.free = Fiddle::RUBY_FREE
    table_params.Model = model
    table_params.RowBackgroundColorModelColumn = -1
    
    table = UI.new_table(table_params)
   
    headers.each_with_index do |header, index|
      UI.table_append_text_column(table, header, index, -1)
    end
    
    UI.table_append_button_column(table, "", 3, 1)
    UI.table_append_button_column(table, "", 4, 1)
    
    UI.table_append_progress_bar_column(table, "", 5)
    

    case sector
    when 1
      UI.box_append(@window_sector1, table, 1)
    when 2
      UI.box_append(@window_sector2, table, 1)
    else 3
      UI.box_append(@window_sector3, table, 1)
    end

  end







  def load_graphical_elements

    # button1 = UI.new_button('Button 1')
    # button2 = UI.new_button('Button 2')
    # button3 = UI.new_button('Button 3')

    # UI.box_append(@window_sector1, button1, 1)
    # UI.box_append(@window_sector2, button2, 1)
    # UI.box_append(@window_sector3, button3, 1)

        
    # UI.button_on_clicked(button1) do
    #   UI.msg_box(@absolute_main_window, 'Information', 'You clicked the button1')
    # end


    # UI.button_on_clicked(button2) do
    #   UI.msg_box(@absolute_main_window, 'Information', 'You clicked the button2')
    # end

  
  end

  def rbcallback(*args, &block)
    args << [0] if args.size == 1 # Argument types are ommited
    block_caller = Fiddle::Closure::BlockCaller.new(*args, &block)
    @block_callers << block_caller
    block_caller
  end







  # hbox = UI.new_horizontal_box
  # UI.window_set_child(main_window, hbox)
  
  # data = [
  #   %w[cat meow],
  #   %w[dog woof],
  #   %w[chicken cock-a-doodle-doo],
  #   %w[horse neigh],
  #   %w[cow moo]
  # ]
  
  # # Protects BlockCaller objects from garbage collection.
  # @block_callers = []
  # def rbcallback(*args, &block)
  #   args << [0] if args.size == 1 # Argument types are ommited
  #   block_caller = Fiddle::Closure::BlockCaller.new(*args, &block)
  #   @block_callers << block_caller
  #   block_caller
  # end
  
  # model_handler = UI::FFI::TableModelHandler.malloc
  # model_handler.to_ptr.free = Fiddle::RUBY_FREE
  # model_handler.NumColumns   = rbcallback(4) { 2 }
  # model_handler.ColumnType   = rbcallback(4) { 0 }
  # model_handler.NumRows      = rbcallback(4) { 5 }
  # model_handler.CellValue    = rbcallback(1, [1, 1, 4, 4]) do |_, _, row, column|
  #   UI.new_table_value_string(data[row][column])
  # end
  # model_handler.SetCellValue = rbcallback(0, [0]) {}
  
  # model = UI.new_table_model(model_handler)
  
  # table_params = UI::FFI::TableParams.malloc
  # table_params.to_ptr.free = Fiddle::RUBY_FREE
  # table_params.Model = model
  # table_params.RowBackgroundColorModelColumn = -1
  
  # table = UI.new_table(table_params)
  # UI.table_append_text_column(table, 'Animal', 0, -1)
  # UI.table_append_text_column(table, 'Description', 1, -1)
  
  # UI.box_append(hbox, table, 1)
  # UI.control_show(main_window)





















end