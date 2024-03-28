class SpartanUIGenCheckBox

  def initialize(name)
    @element = UI.new_checkbox(name)
  end

  def ui_element
    @element
  end

  def get_value
    return UI.checkbox_checked(@element) == 1
  end

  def perform_action_on_change
    UI.checkbox_on_toggled(@element) do
      yield(@element) if block_given?
    end
  end

end