# require_relative "LibUI/lib/libui.rb"
require "libui"
require "pry"
require_relative "interface.rb"

class Main

  def initialize
    @main_interface = Interface.new
    @main_interface.load_close_instance_behaviour()
    load_graphical_interface()
    load_window()
  end

  def load_graphical_interface
    @main_interface.load_sectors()
    
    
    button1 = @main_interface.new_button("Test", 1, FULL)
    button2 = @main_interface.new_button("Test", 2, NORMAL)
    button3 = @main_interface.new_button("Test", 3, FULL)


    headers = ["Route","HTTP VERB","CONTROLLER"]
    data = [
      ["/system", "GET", "ola", "Erase", "Edit", "50", ""],
      ["/system1", "GET", "ola", "Erase", "Edit", "60", ""],
      ["/system2", "GET", "ola", "Erase", "Edit", "70", ""]
    ]
    @main_interface.new_table(data, headers, 2)


    @main_interface.load_graphical_elements()

  end

  def load_window
    @main_interface.draw_window()
  end

  private

  def preload
  end


end

Main.new