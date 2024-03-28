class SpartanUIGenButton

  def initialize(name)
    @element = UI.new_button(name)
  end

  def ui_element
    @element
  end

  def perform_action_clicked
    UI.button_on_clicked(@element) do
      yield(@element) if block_given?
    end
  end



end