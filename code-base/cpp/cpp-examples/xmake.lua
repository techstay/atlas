-- xmake.lua
add_rules("mode.debug", "mode.release")

-- Shared moduleonly target: compiles std module BMI exactly once.
-- _std_trig.mpp is the trigger — its `import std;` tells xmake's
-- build.c++.modules.std auto-injection to compile the std module here.
-- {public = true} propagates the compiled modules to dependents.
target("std_modules")
    set_kind("moduleonly")
    set_policy("build.c++.modules", true)
    add_files("src/_std_trig.mpp", {public = true})
    if is_plat("windows") then
        set_toolchains("msvc")
        set_languages("c++latest")
        add_cxflags("/EHsc")
    elseif is_plat("linux") then
        set_toolchains("clang")
        set_languages("c++26")
    end

-- Iterate over all .cpp files under src/ and its subdirectories
for _, filepath in ipairs(os.files("src/**/*.cpp")) do
    -- Combine subdirectory name and file basename as the target name
    local subdir = path.directory(filepath):match("([^/\\]+)$")
    local name = path.basename(filepath)
    local target_name = subdir .. "_" .. name

    -- Dynamically create a target for each .cpp file
    target(target_name)
        set_kind("binary")
        -- Inherit std BMI from std_modules; do NOT compile our own copy
        add_deps("std_modules")
        set_policy("build.c++.modules", true)
        if is_plat("windows") then
            set_toolchains("msvc")
            set_languages("c++latest")
            add_cxflags("/EHsc")
        elseif is_plat("linux") then
            set_toolchains("clang")
            set_languages("c++26")
        end
        add_files(filepath)
    end
