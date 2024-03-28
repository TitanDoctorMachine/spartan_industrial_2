class SpartanUIGenInput

  def initialize()
    @element = UI.new_entry
  end

  def ui_element
    @element
  end

  def get_value
    return UI.entry_text(@element).to_s
  end



end