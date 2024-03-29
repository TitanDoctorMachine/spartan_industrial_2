UI = LibUI
FULL = 1
NORMAL = 0

require_relative "sub_classes/button.rb"
require_relative "sub_classes/sector.rb"
require_relative "sub_classes/table.rb"
require_relative "sub_classes/input.rb"
require_relative "sub_classes/checkbox.rb"
require_relative "sub_classes/select.rb"
require_relative "sub_classes/label.rb"


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

  def window
    @window_box
  end

  def new_notification(message)
    UI.msg_box(@absolute_main_window, "Message!", message)
  end

  def new_sector(*args)
    return SpartanUIGenSector.new(args[0])
  end

  def new_button(*args)
    return SpartanUIGenButton.new(args[0])
  end

  def new_table(*args)
    return SpartanUIGenTable.new(args[0], args[1])
  end

  def new_input(*args)
    return SpartanUIGenInput.new()
  end

  def new_select_box(*args)
    return SpartanUIGenSelect.new(args[0])
  end

  def new_checkbox(*args)
    return SpartanUIGenCheckBox.new(args[0])
  end

  def new_label(*args)
    return SpartanUIGenLabel.new(args[0])
  end

end