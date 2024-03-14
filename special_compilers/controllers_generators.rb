class ControllersGenerators
  
  def initialize(input, method_select_box, type_select_box, checkbox)
    @name_controller = input
    @method = method_select_box
    @type_render = type_select_box
    @gen_view = !checkbox
    
    raise InvalidParams if ["", nil].include? input or input.empty?
  end

  def run()

buffer_to_layout =
%{
  
- route: /#{@name_controller}
  verb: #{@method}
  render_method: #{@type_render}
  file_controller: #{@method}_#{@name_controller}_controller.cpp
  layout: #{@gen_view ? "application.html" : "null"} }

    File.write('../jobs/routes.yml', buffer_to_layout, mode: 'a')
    File.write("../jobs/controllers/#{@method}_#{@name_controller}_controller.cpp", default_message_controller) if !File.exist? ("../jobs/controllers/#{@method}_#{@name_controller}_controller.cpp")
    File.write("../jobs/views/#{@method}_#{@name_controller}.#{@type_render}", default_message_view) if @gen_view and !File.exist? ("../jobs/views/#{@method}_#{@name_controller}.#{@type_render}")

    return true
  end

  def default_message_controller
    %{


    }
  end

  def default_message_view
    %{


    }
  end

end

class InvalidParams < StandardError; end