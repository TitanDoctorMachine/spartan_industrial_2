class SpartanGenerator

  def initialize(hash_params)
    @hash_params = hash_params
    @global_output = ""
    @global_output_renders =  ""
  end

  def generate
    
    add_routes_header()


    @hash_params.each do |param|
      add_mapped_route(param)
    end

    add_routes_footer()

    return @global_output
  end

  def return_views_generators
    return @global_output_renders
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

  def add_mapped_route(param)

    route = param["route"]
    verb = param["verb"]
    file_controller = param["file_controller"]
    render_mode = param["render_method"]

    if !param["file_controller"].nil?
      file_pre_render_view = param["file_controller"].gsub("_controller.cpp", "") + ".#{render_mode}"
    else
      file_pre_render_view = param["file_view_self_generated"]
    end

    begin
      content = File.read("#{Dir.pwd}/../jobs/views/#{file_pre_render_view}").gsub("\n", "")

      render_public_name = "#{Dir.pwd}/../jobs/views/#{file_pre_render_view}".gsub(" ", "_").gsub("/", "_").gsub(".", "_")
      @global_output_renders += %{const char var#{render_public_name}[] PROGMEM = R"=====(#{content})====="; }
    rescue => e
      puts e.to_s
      content = false
    end

    if file_controller.nil? and content == false
      begin
        content = File.read("#{Dir.pwd}/../jobs/public_assets/#{file_pre_render_view}").gsub("\n", "")
      
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
  #{content ? %{pre_render(var#{render_public_name});} : ""}
  #{ file_controller.nil? ? "" : %{#include "../../jobs/controllers/#{file_controller}"} }
  post_render();
} else
    }
  end


end

class NoFoundCompiledFile < StandardError; end