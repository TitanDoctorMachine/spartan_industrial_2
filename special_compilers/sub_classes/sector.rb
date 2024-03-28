VERT = 0
HORZ = 1

class SpartanUIGenSector

  def initialize(orientation)
    if orientation == VERT
      @element = UI.new_vertical_box
    elsif orientation == HORZ
      @element = UI.new_horizontal_box
    end
  end

  def ui_element
    @element
  end

  def fully_bind_to_father_element(father_element_to_bind)
    return UI.box_append(father_element_to_bind, @element, 1) if fiddle_class? father_element_to_bind
    UI.box_append(father_element_to_bind.ui_element, @element, 1)
  end

  def fully_add_children_element(sub_element_to_bind)
    return UI.box_append(@element, sub_element_to_bind, 1) if fiddle_class? sub_element_to_bind
    UI.box_append(@element, sub_element_to_bind.ui_element, 1)
  end

  def dinamically_bind_to_father_element(father_element_to_bind)
    return UI.box_append(father_element_to_bind, @element, 0) if fiddle_class? father_element_to_bind
    UI.box_append(father_element_to_bind.ui_element, @element, 0)
  end

  def dinamically_add_children_element(sub_element_to_bind)
    return UI.box_append(@element, sub_element_to_bind, 0) if fiddle_class? sub_element_to_bind
    UI.box_append(@element, sub_element_to_bind.ui_element, 0)
  end

  private

  def fiddle_class?(test_element)
    test_element.class == Fiddle::Pointer
  end

end