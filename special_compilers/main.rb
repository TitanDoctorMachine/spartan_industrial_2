# require_relative "LibUI/lib/libui.rb"
require "libui"
require "pry"
require "yaml"
require_relative "interface.rb"
require_relative "generator.rb"

class Main

  def initialize
    @files_and_folders = []
    @files_layouts = []
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
    load_routes_table()

  end

  def load_sectors()
    @sector_top = @main_interface.new_sector(VERT)
    @sector_middle = @main_interface.new_sector(VERT)
    @sector_bottom = @main_interface.new_sector(VERT)

    @sector_top.fully_bind_to_father_element(@main_interface.window)
    @sector_middle.fully_bind_to_father_element(@main_interface.window)
    @sector_bottom.fully_bind_to_father_element(@main_interface.window)
  end

  def load_buttons_and_actions

    sub_sector_compile = @main_interface.new_sector(VERT)
    sub_sector_compile.fully_bind_to_father_element(@sector_top)
    
    button1 = @main_interface.new_button("Compile")
    sub_sector_compile.dinamically_add_children_element(button1)

    sub_sector_spacer = @main_interface.new_sector(HORZ)
    sub_sector_cancel = @main_interface.new_sector(VERT)
    sub_sector_spacer.fully_bind_to_father_element(@sector_bottom)
    sub_sector_cancel.fully_bind_to_father_element(@sector_bottom)

    button2 = @main_interface.new_button("Cancel")
    sub_sector_cancel.fully_add_children_element(button2)

    button1.perform_action_clicked do 
      generator = SpartanGenerator.new(@data_yaml_routes, @files_layouts)
      content = generator.generate
      views_generators = generator.return_views_generators
      views_layouts = generator.return_layouts
      File.write('../spartan_main/generators_controllers/routes.cpp', content)
      File.write('../spartan_main/generators_controllers/buffer_renders.h', views_generators)
      File.write('../spartan_main/generators_controllers/buffer_layouts.h', views_layouts)
    end

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
    @files_layouts = get_files_and_folders_in_folder("../jobs/views/layouts/")
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