load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

cmake(
    name = "glfw",
    lib_source = "@glfw//:all_srcs",
    out_static_libs = ["libglfw3.a"],
    cache_entries = {
        "GLFW_BUILD_EXAMPLES": "OFF",
        "GLFW_BUILD_TESTS": "OFF",
        "GLFW_BUILD_DOCS": "OFF",
        "CMAKE_BUILD_TYPE": "Release",
    },
    visibility = ["//visibility:public"],
)

# Adiciona um filegroup no repositório externo
filegroup(
    name = "all_srcs",
    srcs = glob(["**/*"]),
    visibility = ["//visibility:public"],
)