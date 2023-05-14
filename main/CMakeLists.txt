
file(GLOB_RECURSE ICONS
    icons/*.c
)

idf_component_register(SRCS "lvgl_base.cpp" ${ICONS}
                    INCLUDE_DIRS ".")
