class SpartanGenerator

  def initialize(hash_params)
    @hash_params = hash_params
    @global_output = ""
  end

  def generate
    
    add_routes_header()


    @hash_params.each do |param|
      add_mapped_route(param)
    end

    return @global_output
  end

  private

  def add_routes_header
    @global_output += %{
/*
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
    file_pre_render_view = param["file_pre_render_view"]

    content = File.read("#{Dir.pwd}/../jobs/views/#{file_pre_render_view}").gsub("\n", "")

    @global_output += %{
  //*%..IDENTIFIER $#{verb.upcase} #{route}$
  if (uri == "#{route}" && http_verb == "#{verb.upcase}"){
    pre_render(R"=====(#{content})=====");
    #include "../controllers/#{file_controller}"
  } else

    }
  end


end