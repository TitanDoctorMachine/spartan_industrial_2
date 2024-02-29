class SpartanUIGenTable

  def initialize(hash_data, headers)
    @block_callers = []

    model_handler = UI::FFI::TableModelHandler.malloc
    model_handler.to_ptr.free = Fiddle::RUBY_FREE
    model_handler.NumColumns   = rbcallback(4) { headers.count }
    model_handler.ColumnType   = rbcallback(4) { 0 }
    model_handler.NumRows      = rbcallback(4) { hash_data.count }
    model_handler.CellValue    = rbcallback(1, [1, 1, 4, 4]) do |_, _, row, column|
      UI.new_table_value_string(hash_data[row][column])  
    end

    model_handler.SetCellValue = rbcallback(0, [1,1]) do |test1, test2|
    end
    
    model = UI.new_table_model(model_handler)
    
    table_params = UI::FFI::TableParams.malloc
    table_params.to_ptr.free = Fiddle::RUBY_FREE
    table_params.Model = model
    table_params.RowBackgroundColorModelColumn = -1
    
    @element = UI.new_table(table_params)

    headers.each_with_index do |header, index|
      UI.table_append_text_column(@element, header, index, -1)
    end
    
  end

  def ui_element
    @element
  end

  private

  def rbcallback(*args, &block)
    args << [0] if args.size == 1 # Argument types are ommited
    block_caller = Fiddle::Closure::BlockCaller.new(*args, &block)
    @block_callers << block_caller
    block_caller
  end
  
end