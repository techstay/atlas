add_rules("mode.debug", "mode.release")
add_requires("boost")
add_requires("spdlog")

-- Iterate over all .cpp files under src/ and its subdirectories
-- Target names use full relative path segments: e.g. boost_core_01_smart_ptr
for _, filepath in ipairs(os.files("src/**/*.cpp")) do
    local rel = path.relative(filepath, "src")
    local target_name = rel:gsub("[/\\]", "_"):gsub("%.cpp$", ""):gsub("%.", "_")

    -- Dynamically create a target for each .cpp file
    target(target_name)
        set_kind("binary")
        if is_plat("windows") then
            set_toolchains("msvc")
            set_languages("c++latest")
            add_cxflags("/EHsc")
        elseif is_plat("linux") then
            set_toolchains("clang")
            set_languages("c++26")
        end
        add_files(filepath)
        add_packages("boost", "spdlog")
    end
