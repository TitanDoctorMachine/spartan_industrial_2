class SpartanGenerator

  def initialize(hash_params, files_layouts)
    @hash_params = hash_params
    @files_layouts = files_layouts
    @global_output = ""
    @global_output_renders =  ""
    @global_output_layouts =  ""
  end

  def generate
    
    add_routes_header()

    @hash_params.each do |param|
      add_mapped_route(param)
    end

    add_mapped_layout()

    add_routes_footer()

    return @global_output
  end

  def return_views_generators
    return @global_output_renders
  end

  def return_layouts
    return @global_output_layouts
  end

  private

  def add_routes_header
    @global_output += %{/*
    THIS PART IS COMPLETED SELF_GENERATED, DO NOT MANUALLY CHANGE
*/
}
  end

  def add_routes_footer
    @global_output += %{
//{++ AUTO GENERATED PART, DO NOT CHANGE! ++}

{
  render_plain("WELCOME TO SPARTA!");
}
}
  end

  def add_mapped_layout()
    array_layouts = []

    @files_layouts.each do |file_layout|

      content = File.read("#{Dir.pwd}/#{file_layout}").gsub("\n", "").gsub("  ", "")
      render_public_name = "#{Dir.pwd}/#{file_layout}".gsub(" ", "_").gsub("/", "_").gsub(".", "_")
      @global_output_renders += %{const char var#{render_public_name}[] PROGMEM = R"=====(#{content})====="; }

      array_layouts.append({"file_key" => file_layout.split("/").last(), "content" => ("var" + render_public_name)})
    end

    array_layouts.each do |hash|
      @global_output_layouts += %{
  if (layout == "#{hash["file_key"]}"){
    response_compiled = "";
    response_compiled += String(#{hash["content"]});
  } else}
    end
    
    @global_output_layouts += %{
  {response_compiled = "<S&= render_absolute_view />";}}
  end 


  def add_mapped_route(param)

    route = param["route"]
    verb = param["verb"]
    file_controller = param["file_controller"]
    render_mode = param["render_method"]
    layout = param["layout"]

    if !param["file_controller"].nil?
      file_pre_render_view = param["file_controller"].gsub("_controller.cpp", "") + ".#{render_mode}"
    else
      file_pre_render_view = param["file_view_self_generated"]
    end

    begin
      content = File.read("#{Dir.pwd}/../jobs/views/#{file_pre_render_view}").gsub("\n", "").gsub("  ", "")

      render_public_name = "#{Dir.pwd}/../jobs/views/#{file_pre_render_view}".gsub(" ", "_").gsub("/", "_").gsub(".", "_")
      @global_output_renders += %{const char var#{render_public_name}[] PROGMEM = R"=====(#{content})====="; }
    rescue => e
      puts e.to_s
      content = false
    end

    if file_controller.nil? and content == false
      begin
        content = File.read("#{Dir.pwd}/../jobs/public_assets/#{file_pre_render_view}").gsub("\n", "").gsub("  ", "")
      
        render_public_name = "#{Dir.pwd}/../jobs/public_assets/#{file_pre_render_view}".gsub(" ", "_").gsub("/", "_").gsub(".", "_")
        @global_output_renders += %{const char var#{render_public_name}[] PROGMEM = R"=====(#{content})====="; }
      rescue => e
        puts e.to_s
        content = false
      end
    end

    @global_output += %{
//*%..IDENTIFIER $#{verb.upcase} #{route}$
if (uri == "#{route}" && http_verb == "#{verb.upcase}"){
  #{content ? %{pre_render_layout("#{layout.to_s}");} : ""}
  run_application();
  #{content ? %{pre_render(var#{render_public_name});} : ""}
  #{ file_controller.nil? ? "" : %{#include "../../jobs/controllers/#{file_controller}"} }
  post_render();
} else
    }
  end


end

class NoFoundCompiledFile < StandardError; end