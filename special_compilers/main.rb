# require_relative "LibUI/lib/libui.rb"
require "libui"
require "pry"
require "yaml"
require_relative "interface.rb"
require_relative "generator.rb"
require_relative "controllers_generators.rb"

class Main

  def initialize
    @files_and_folders = []
    @files_layouts = []
    @files_partials = []
    @main_interface = Interface.new
    @main_interface.load_close_instance_behaviour()
    load_graphical_interface()
    load_window()
  end

  def load_graphical_interface

    load_sectors() 
    load_buttons_and_actions()
    load_routes()
    insert_plain_files_routes()
    load_layouts()
    load_partials()
    load_async_jobs()
    load_routes_table()
    load_layouts_table()
    load_partials_table()
    load_generator_sector()
    load_async_jobs_table()
    load_button_cancel()

  end

  def load_sectors()
    @sector_horz = @main_interface.new_sector(HORZ)
    @sector_horz.fully_bind_to_father_element(@main_interface.window)

    @sector_left = @main_interface.new_sector(VERT)
    @sector_left.fully_bind_to_father_element(@sector_horz)

    @sector_right = @main_interface.new_sector(VERT)
    @sector_right.fully_bind_to_father_element(@sector_horz)

    @sector_top = @main_interface.new_sector(VERT)
    @sector_middle = @main_interface.new_sector(VERT)
    @sector_bottom = @main_interface.new_sector(VERT)

    @sector_top.fully_bind_to_father_element(@sector_right)
    @sector_middle.fully_bind_to_father_element(@sector_left)
    @sector_bottom.fully_bind_to_father_element(@sector_right)
  end

  def load_buttons_and_actions

    sub_sector_compile = @main_interface.new_sector(VERT)
    sub_sector_compile.dinamically_bind_to_father_element(@sector_top)
    
    button1 = @main_interface.new_button("Compile")
    sub_sector_compile.dinamically_add_children_element(button1)

    button1.perform_action_clicked do 
      generator = SpartanGenerator.new(@data_yaml_routes, @files_layouts, @files_partials)
      content = generator.generate
      views_generators = generator.return_views_generators
      views_layouts = generator.return_layouts
      views_partials = generator.return_partials
      File.write('../spartan_main/generators_controllers/routes.cpp', content)
      File.write('../spartan_main/generators_controllers/buffer_renders.h', views_generators)
      File.write('../spartan_main/generators_controllers/buffer_layouts.h', views_layouts)
      File.write('../spartan_main/generators_controllers/buffer_partials.h', views_partials)

      @main_interface.new_notification("SUCCESS! Compiled Files!")

    end

  end

  def load_generator_sector

    sector_gen = @main_interface.new_sector(VERT)
    sector_gen.fully_bind_to_father_element(@sector_top)

    label = @main_interface.new_label("\n CONTROLLERS GENERATOR")
    sector_gen.fully_add_children_element(label)

    sub_sector_gen = @main_interface.new_sector(HORZ)
    sub_sector_gen.dinamically_bind_to_father_element(sector_gen)
    
    method_select_box = @main_interface.new_select_box(["GET", "POST"])
    sub_sector_gen.fully_add_children_element(method_select_box)

    type_select_box = @main_interface.new_select_box(["html", "js"])
    sub_sector_gen.fully_add_children_element(type_select_box)

    checkbox = @main_interface.new_checkbox("DO NOT GEN VIEW?")
    sub_sector_gen.fully_add_children_element(checkbox)

    input = @main_interface.new_input
    sector_gen.fully_add_children_element(input)

    button = @main_interface.new_button("Generate")
    sector_gen.dinamically_add_children_element(button)

    button.perform_action_clicked do 

      begin
        @main_interface.new_notification("SUCCESS! Generated Controller!") if
        ControllersGenerators.new(      
          input.get_value(),
          method_select_box.get_value(),
          type_select_box.get_value(),
          checkbox.get_value()
        )
        .run()
      rescue InvalidParams
        @main_interface.new_notification("ERROR! Invalid Params!")
      end
    end
  end

  def load_button_cancel
    sub_sector_cancel = @main_interface.new_sector(VERT)
    sub_sector_cancel.dinamically_bind_to_father_element(@sector_bottom)

    button2 = @main_interface.new_button("Cancel")
    sub_sector_cancel.dinamically_add_children_element(button2)

    button2.perform_action_clicked do 
      raise SystemExit
    end
  end

  def load_routes
    @data_yaml_routes = YAML.load(File.read('../jobs/routes.yml'))
  end

  def insert_plain_files_routes
    @files_and_folders = []
    get_files_and_folders_in_folder("../jobs/public_assets").each do |file|
      @data_yaml_routes.append({
        "route"=> file.gsub("../jobs/public_assets", ""),
        "verb"=>"GET",
        "render_method"=>file.split(".").last,
        "file_controller"=> nil,
        "file_view_self_generated" => file.gsub("../jobs/public_assets", ""),
        "layout" => nil
      })
    end
  end

  def load_layouts
    @files_and_folders = []
    @files_layouts = get_files_and_folders_in_folder("../jobs/views/layouts/").map{|value| value if !value.split("/").last.start_with?("_")}
    @files_layouts = @files_layouts.compact!
    @files_layouts = [] if @files_layouts.nil?
  end

  def load_partials
    @files_and_folders = []
    @files_partials = get_files_and_folders_in_folder("../jobs/views/").map{|value| value if value.split("/").last.start_with?("_")}
    @files_partials = @files_partials.compact!
    @files_partials = [] if @files_partials.nil?
  end

  def load_async_jobs
    @files_and_folders = []
    @files_async_jobs = get_files_and_folders_in_folder("../async_jobs/")
    @files_async_jobs = [] if @files_async_jobs.nil?
  end

  def load_routes_table
    headers = ["HTTP VERB", "FILE_CONTROLLER", "FILE_VIEW", "ROUTE"]
    data = []

    @data_yaml_routes.each do |route_line|
      out_route = []
      out_route.append route_line["verb"]
      out_route.append route_line["file_controller"].to_s
      out_route.append route_line["file_controller"].nil? ? "/public_assets" + route_line["file_view_self_generated"] : "/views/" + route_line["file_controller"].gsub("_controller.cpp", "") + ".#{route_line["render_method"]}"
      out_route.append route_line["route"]
      data.append(out_route)
    end

    @routes_table = @main_interface.new_table(data, headers)
    @sector_middle.fully_add_children_element(@routes_table)
  end

  def load_layouts_table
    headers = ["FILE LAYOUTS"]
    data = []

    @files_layouts.each do |route_line|
      out_route = []
      out_route.append route_line
      data.append(out_route)
    end

    @layouts_table = @main_interface.new_table(data, headers)
    @sector_bottom.dinamically_add_children_element(@layouts_table)
  end

  def load_partials_table
    headers = ["FILE PARTIALS"]
    data = []

    @files_partials.each do |route_line|
      out_route = []
      out_route.append route_line
      data.append(out_route)
    end

    @partials_table = @main_interface.new_table(data, headers)
    @sector_bottom.dinamically_add_children_element(@partials_table)
  end

  def load_async_jobs_table
    headers = ["FILE ASYNC JOBS"]
    data = []

    @files_async_jobs.each do |route_line|
      out_route = []
      out_route.append route_line
      data.append(out_route)
    end

    @async_jobs_table = @main_interface.new_table(data, headers)
    @sector_top.fully_add_children_element(@async_jobs_table)
  end

  def load_window
    @main_interface.draw_window()
  end

  private

  def get_files_and_folders_in_folder(folder_path)
    if Dir.exist?(folder_path)
      items = Dir.glob(File.join(folder_path, '*'))
      files = items.select { |item| File.file?(item) }

      folders = items.select { |item| File.directory?(item) }
      
      @files_and_folders.concat(files)

      folders.each do |folder|
        get_files_and_folders_in_folder(folder)
      end

      return @files_and_folders
    else
      return {}
    end
  end

  def preload
  end


end

Main.new