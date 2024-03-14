class SpartanUIGenSelect

  def initialize(options)
    @element = UI.new_combobox
    @options = options
    options.each do |option|
      UI.combobox_append(@element, option)
    end
  end

  def ui_element
    @element
  end

  def get_value
    return @options[UI.combobox_selected(@element)]
  end


  def perform_action_on_select
    UI.combobox_on_selected(@element) do
      yield(@element) if block_given?
    end
  end

end